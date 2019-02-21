// from https://stackoverflow.com/a/26948383/827927

#include <iostream>
#include <csignal>
#include <csetjmp>
#include <stdexcept>
#include <thread>
#include <chrono>
using namespace std;

jmp_buf gBuffer;        // A buffer to hold info on where to jump to

void catch_signal(int signalNumber) {
    //signal(SIGINT, SIG_DFL);          // Switch to default handling
    signal(SIGINT, catch_signal);       // Reactivate this handler.
    longjmp (           // Jump back into the normal flow of the program
        gBuffer,        // using this context to say where to jump to
        signalNumber    // and passing back the value of the signal.
    );
}


int test_signal() {
    try {
        int sig;
        if ((sig = setjmp(gBuffer)) == 0) {
            cout << "before raise\n";
						this_thread::sleep_for(chrono::seconds(3));
            raise(SIGINT);
            cout << "after raise\n";
        } else {
            // This path implies that a signal was thrown, and
            // that the setjmp function returned the signal
            // which puts us at this point.
            // Now that we are out of the signal handler it is
            // normally safe to throw what ever sort of exception we want.
            throw(runtime_error("Signal "+to_string(sig)+" was raised!"));
        }
    } catch (const exception& ex) {
        cerr << "Caught exception inside test_signal: " << ex.what() << endl;
    }

    return 0;
}

int main() {
		signal(SIGINT, catch_signal);
		signal(SIGTERM, catch_signal);
		try {
		    test_signal();
		} catch (const exception& ex) {
		    cerr << "Caught exception inside main: " << ex.what() << endl;
		}
		return 0;
}

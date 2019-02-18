/**
 * A demo of inline functions.
 * Compile with --assemble.
 */

inline int square(int x) {
    return x*x;
}

int main() {
    return square(1234);
}

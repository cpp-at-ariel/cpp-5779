/**
 * A demo of inline functions.
 * Compile with --assemble.
 */

#define sqr(x) x*x

inline int square(int x) {
    return x*x;
}

int main() {
    int r=sqr(5+5);
    return square(5+5);
}

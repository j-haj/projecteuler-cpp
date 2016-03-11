#include "projecteuler/pe3.h"

unsigned long largestPrimeFactor(unsigned long n, unsigned long x) {
    if (n == x) {
        return n;
    }
    if (n%x == 0) {
        return largestPrimeFactor(n/x, x);
    } else {
        if (x == 2) {
            return largestPrimeFactor(n, x+1);
        } else {
            return largestPrimeFactor(n, x+2);
        }
    }
}

unsigned long pe3() {
    return largestPrimeFactor(600851475143, 2);
}

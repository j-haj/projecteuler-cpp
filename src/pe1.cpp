#include "projecteuler/pe1.h"

int sumLessThanN(int n) {
    int sum = 0;
    for (i = 3; i < n; ++i) {
        if ((i%3 == 0) || (i%== 0)) {
            sum += i;
        }
    }
    return sum;
}

int pe1() {
    return sumLessThanN(1000);
}

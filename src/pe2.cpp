#include "projecteuler/pe2.h"
#include <vector>

// Fibonacci number cache used to store fibonacci calculations
static std::vector<int> fibonacciNums = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89};

// Cacluates the fibonacci number using a cache to store prior results
int fibonacci(int n) {
    if (n <= fibonacciNums.size()) {
        return fibonacciNums[n-1];
    } else {
        int result = fibonacci(n-1) + fibonacci(n-2);
        fibonacciNums.push_back(result);
        return result;
    }
}

int pe2() {
    auto fibIndex = 2;
    auto currentTerm = fibonacci(2);
    auto sum = 0;
    while (currentTerm < 4000000) {
        if (currentTerm % 2 == 0) {
            sum += currentTerm;
        }
        ++fibIndex;
        currentTerm = fibonacci(fibIndex);
    }
    return sum;
}

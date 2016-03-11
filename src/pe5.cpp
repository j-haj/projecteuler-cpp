#include "projecteuler/pe5.h"

#include <vector>
#include <map>
#include <cmath>

static std::vector<int> Primes = {2, 3, 5, 7, 11, 13, 17, 23, 29};

long multiplicity(int n, int p) {
    long multiplicity = 0;
    while (n%p == 0) {
        n /= p;
        ++multiplicity;
    }
    return multiplicity;
}

// Returns a map where the keys are the prime factors of `n` and the
// corresponding values are the multiplicity values
std::map<int, int> prime_multiplicity_map(int n) {
    std::map<int, int> primeMap;
    for (const auto& p : Primes) {
        if (n%p == 0) {
            primeMap[p] = multiplicity(n, p);
        }
    }
    return primeMap;
}

std::map<int, int> max_prime_map(std::vector<std::map<int, int>> maps) {
    std::map<int, int> maxMap;
    for (std::map<int, int>& x : maps) {
        for(std::map<int, int>::iterator it=x.begin(); it != x.end(); ++it) {
            if (maxMap.find(it->first) != maxMap.end()) {
                if (it->second > maxMap[it->first]) {
                    maxMap[it->first] = it->second;
                }
            } else {
                maxMap[it->first] = it->second;
            }
        }
    }
    return maxMap;
}

long pe5() {

    std::vector<std::map<int, int>> primeMaps;
    for (int i = 1; i < 30; ++i) {
        primeMaps.push_back(prime_multiplicity_map(i));
    }
    std::map<int, int> maxPrimeMap = max_prime_map(primeMaps);
    int composite = 1;
    for (std::map<int, int>::iterator it=maxPrimeMap.begin(); it!=maxPrimeMap.end(); ++it) {
        composite *= pow(it->first, it->second);
    }
    return composite;
}

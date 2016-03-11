#include "projecteuler/pe4.h"

#include <string>
#include <sstream>

bool isPalindrome(int n) {
    std::stringstream ss;
    ss << n;
    std::string num = ss.str();
    std::string fwdNum = ss.str();
    std::reverse(num.begin(), num.end());
    if (num.compare(fwdNum) == 0) {
        return true;
    }
    return false;
}

int largestPalindrome() {
    int largestVal = 0;
    for (int i = 999; i >= 100; --i) {
        for (int j = 999; j >= i; --j) {
            int tmp = i*j;
            if (tmp > largestVal && isPalindrome(tmp)) {
                largestVal = tmp;
            }
        }
    }
    return largestVal;
}

int pe4() {
    return largestPalindrome();
}

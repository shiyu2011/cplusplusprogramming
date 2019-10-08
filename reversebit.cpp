#include <iostream>
#include <algorithm>
#include <string>
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t x=0;
        for(auto i = 31; i>=0; i--) {
            x |= (n & 1) << i;
            n >>= 1;
        }
        return x;
    }
};

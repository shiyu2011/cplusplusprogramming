#include <iostream>
#include <vector>
#include <stdlib.h>
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
            int tmp = 0;
            for(auto it=digits.end()-1; it>=digits.begin(); it--){
                    if(it==digits.end()-1){
                            *it+=1; 
                            if(*it>=10){
                                    *it-=10;
                                    tmp=1;
                            }
                            continue;
                    }
                    *it+=tmp;
                    if(*it>=10){
                            tmp = 1;
                            *it-=10;
                    }       
                    else
                            tmp = 0;
            }       
            if(tmp ==1){
                    digits.insert(digits.begin(), tmp, 1);
            }
            return digits;
    }
};

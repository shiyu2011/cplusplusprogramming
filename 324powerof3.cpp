class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)
            return true;
        int div = n/3;
        int rem = n%3;
        while(1){
            if(div == 1&& rem ==0)
                return true;
            else if(rem!=0)
                return false;
            else if(div == 0)
                return false;
            rem = div%3;
            div = div/3;
        }
    }
};

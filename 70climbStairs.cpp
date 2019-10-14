class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)
            return 1;
        if(n==2)
            return 2;
        //return climbStairs(n-1) + climbStairs(n-2);//recursive repeat computing o(2^n) time complexity
	//better to use dynamic programming o(n)
        std::vector<int> rec(n);
        for(auto it = rec.begin(); it!=rec.end(); it++){
            if(it==rec.begin()){
                *it = 1;
                continue;
            }
            if(it==rec.begin()+1){
                *it = 2;
                continue;
            }
            *it = *(it-1)+*(it-2);
        }
        return rec.back();
    }
};

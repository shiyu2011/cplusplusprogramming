#include<algorithm>
#include<vector>
#include<iostream>

class Solution{
        public:
                int rob(vector<int>& nums) {
                        if(nums.size()==NULL)
                                return 0;
                        if(nums.size()==1)
                                return nums.front();
                        std::vector<int> maxVal;
                        maxVal.reserve(nums.size());
                        maxVal.push_back(nums.front());
                        maxVal.push_back(std::max(maxVal.front(),*(nums.begin()+1)));
                        //std::vector<int>::iterator dist;
                        for(auto it=nums.begin()+2; it!=nums.end(); it++){
                                auto dist = it-nums.begin();
                                maxVal.push_back(std::max(*(maxVal.begin()+dist-2)+*it, *(maxVal.begin()+dist-1)));
				//dp(i) is after rob reach out the house i, the maximum value ;
				//dp(i) = max(dp(i-2)+hval(i), dp(i-1));
				//dp(i-1) = max(dp(i-3)+hval(i-1), dp(i-2));
				//dp(i) = max(dp(i-2)+hval(i), max(dp(i-3)+hval(i-1), dp(i-2)));
				//if second part is dp(i-2), then dp(i-2)_hval(i) is the most;
				//if second part is dp(i-3)+hval(i-1) which means robbing house i-1 which implys cannot rob house i
				//then compare dp(i-2)+hval(i) and dp(i-3)+hval(i-1) which means robbing i or i-1 is a question
                        }
                        return maxVal.back();
                }
};

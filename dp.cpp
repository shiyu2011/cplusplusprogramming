#include<algorithm>
#include<vector>
#include<iostream>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
	    if(nums.size()==0)
		    return 0;
	    if(nums.size()==1)
		    return nums.back();
	    std::vector<int> maxRec;
	    maxRec.reserve(nums.size());
	    maxRec.push_back(*nums.begin());
	    for(auto it=nums.begin()+1;it!=nums.end(); it++){
		    auto dis = it-nums.begin();
		    maxRec.push_back(std::max((*(maxRec.begin()+dis-1) + *it), *it));
	    }
	    std::cout<<"\n";	
	    int val=maxRec.front();
	    for(auto it=maxRec.begin()+1;it!=maxRec.end(); it++){
		    if(val<*it)
			    val = *it;
	    }
	    return val;
    }
};

int main(){
	int tmp[9]={-2,1,-3,4,-1,2,1,-5,4};
	//int tmp[2]={-2,-1};
	std::vector<int> nums(tmp, tmp+9);
	for(auto it=nums.begin(); it!=nums.end(); it++)
		std::cout<<*it<<" ";
	std::cout<<"\n";	
	Solution s;
	int val = s.maxSubArray(nums);
	std::cout<<val<<std::endl;
	return 1;
}

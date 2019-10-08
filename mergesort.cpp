#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
	    if (nums1.size()==0){
		    nums1 = nums2;
		    return;
	    }
	    if (nums2.size()==0){
		    return;
	    }
	    std::vector<int> tmp(nums1.begin(), nums1.begin()+m);
	    nums1.resize(0);
	    nums1.reserve(m+n);
	    auto it1 = tmp.begin();
	    auto it2 = nums2.begin();
	    auto it3 = nums1.begin();
	    while(1){
		    if (*it1<=*it2){
			    nums1.push_back(*it1);
			    it3++;
			    it1++;
			    if(it1==tmp.end()){
				    std::copy(it2, nums2.end(), back_inserter(nums1));
				    break;
			    }
		    }
		    else if(*it1>*it2){
			    nums1.push_back(*it2);
			    it3++;
			    it2++;
			    if(it2==nums2.end()){
				    std::copy(it1, tmp.end(), back_inserter(nums1));
				    break;
			    }
		    }
	    }
    }
};

int main(){
	int tmp[5] = {1,2,3,0,0};
	std::vector<int> a(tmp, tmp+5);
	int tmp1[3] = {2,5,6};
	std::vector<int> b(tmp1, tmp1+3);
	Solution s;
	s.merge(a,3,b,3);
	for(auto it=a.begin(); it!=a.end(); it++)
		std::cout<<*it;
	return 1;

}

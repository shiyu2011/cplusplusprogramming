#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        for (int i=0 ; i<k%nums.size(); i++){
            nums.insert(nums.begin(), nums.back());
	    nums.pop_back();
        }
    }
};

int main(){
	int b[10]={1,2,3,4,5,6,7,8,9,10};	
	vector<int> a(b, b+10);
	for (vector<int>::const_iterator i=a.begin(); i!=a.end(); i++)
		cout <<*i<<" ";
	cout<<"\n";
	Solution s;
	s.rotate(a,11);
	for (vector<int>::const_iterator i=a.begin(); i!=a.end(); i++)
		cout <<*i<<" ";
	cout<<"\n";
	return 1;
}

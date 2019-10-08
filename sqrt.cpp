#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    int mySqrt(int x) {
        for(long int i=0; i<=x+1;i++){
            if(i*i>x)
                return i-1;
        }
	return -1;
    }
    int search(int left, int right, int x){
	    int tmp = (left+right)/2;
	    if(left + 1== right){
		    if(tmp*tmp == x)
			    return tmp;
		    else if(tmp*tmp>x){
			    left = left;
			    right = tmp;
		    }
		    else{
			    left = tmp;
			    right = right;
		    }
		    tmp = search(left, right, x);
	    }
	    return tmp;
    }
    int mySqrtb(int x) {
	    int left = 0;
	    int right = x;
	    if(x == 1)
		    return 1;
	    return search(left, right, x);
    }
};

int main(){
	Solution s;
	std::cout<<"input value: ";
	int a;
	std::cin>>a;
	std::cout<<"result: ";
	std::cout<<s.mySqrtb(a)<<std::endl;
	return 1;
}

#include<iostream>
#include<algorithm>
#include<vector>

bool comp(int i, int j){
	return (i>j);
}

int main(){
	int a[10]={1, 20, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> v(a, a+10);
	std::sort(v.begin(), v.end(), &comp);
	for(std::vector<int>::const_iterator i=v.begin(); i!=v.end(); i++){
		std::cout<<*i<<" ";
	}
	std::cout<<"\n ";
	return 1;	
}

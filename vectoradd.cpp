#include <iostream>
#include <vector>
#include <stdlib.h>

class vec{
	private:
		int array[100];
		int len;
	public:
		vec(int *a, int tlen){
			memcpy(array, a, tlen*(sizeof(int)));
			len = tlen;
		}
		vec(){}
		void operator + (int const &a){
			vec tmp;
			for (auto it=0; it<len; it++){
				array[it] = array[it] + a;
			}
			len = len;
		}
		void printv(){
			std::cout << "len = "<<len<<"\n";
			for (auto it=0; it<len; it++){
				std::cout<<array[it]<<" ";
			}
		std::cout<<"\n";
	}

};

int main(){
	int a[5] = {1, 2, 3, 4, 5};
	vec v(a, 5);
	v.printv();
	vec t;
	v+1;
	v.printv();
}

#include <iostream>
#include <stdlib.h>

class increase{
	//prims * (k-1); k=1...N
	public:
	int getk(int prim, int k){
		return prim*k;	
	}

};

int main(){
	increase s;
	std::cout<<s.getk(3*5*7, 1);
}

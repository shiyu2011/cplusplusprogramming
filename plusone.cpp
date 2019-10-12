#include <iostream>
#include <vector>
#include <stdlib.h>
#define MAXSIZE 100
class plusone{
	private:
		int array[MAXSIZE];
		int len;
	public:
		plusone(int *a, int tlen){
			memcpy(array, a, tlen*sizeof(int));
			len = tlen;
		}
		plusone(){}
		
		void fplusone(){
			int tmp = 0;
			array[len-1] = array[len-1]+1;
			if (array[len-1]>=10){
				tmp = 1;
				array[len-1]-=10;
			}
			for (int k=len-2; k>=1; k--){
				array[k]+=tmp;
				if(array[k]>=10){
					tmp = 1;
					array[k]-=10;
				}
				else 
					tmp = 0;
			}
			if(array[0] == 9 && tmp == 1){
				for(int j = len-1; j>=1; j--){
					array[j+1]= array[j];
				}
				array[0] = tmp;
				array[1] = 0;
				len++;
			}
			else if(tmp==1)
				array[0]+=tmp;
		}
		void printa(){
			for(int k =0; k<len; k++)
				std::cout << array[k] <<" ";
			std::cout<<"\n";
		}
};

int main(){
	int a[100] = {8,9,9,9};
	plusone b(a, 4);
	b.printa();
	b.fplusone();
	b.printa();
}


#include <iostream>
#include <stdlib.h>

#define MAXSIZE 100
class matrix{
	private:
		float mat[MAXSIZE][MAXSIZE];
		int len;
	public:
		matrix(float & *a, int tlen){
			len = tlen;
			for (int i = 0; i<len; i++){
				for (int j=0; j<len; j++){
					mat[i][j] = a[i][j];
				}
			}
		}	
		matrix(){}
		void multi(matrix a, matrix b){
			len=a.len;
			for (int i=0; i<len; i++){
				for (int j =0; j<len;j++){
					mat[i][j] = 0;
					for(int k = 0; k<len; k++)
						mat[i][j]+=a.mat[i][k]*b.mat[k][j];
				}
			}
		}
		void printm(){
			for (int i=0; i<len; i++){
				for (int j=0; j<len; j++)
					std::cout<<mat[i][j]<<" ";
				std::cout<<"\n";
			}
		}	
};


int main(){
	float a[2][2] = {{1,0},{0,1}};
	matrix m1(a, int(2));
	m1.printm();
	matrix m2(a, int(2));
	m2.printm();
	matrix m3;
	m3.multi(m1,m2);
	m3.printm();
	return 1;
}

#include <iostream>
#include <vector>


class X
{
public:
    X():val_(0){}
    X(int val):val_(val){}
    int get(){return val_;}
    void set(int val){val_=val;}
private:
    int val_;
};
//....
//
int main(){
/**	std::vector<X> ax;         // create an empty vector containing
	// objects of type class X
	// version 1:
	ax.resize(10);             // resize the controlled sequence
	for(int i=0; i<10; ++i){
		ax[i].set(i);          // set each element's value
	}
	//...
	// version 2:
	ax.reserve(10);            // make room for 10 elements
	for(int i=0; i<10; ++i){
		ax.push_back(X(i));    // insert elements using the second ctor
	}***/
	std::vector<int> array;
	array.reserve(10);
	array.push_back(10);
	array.push_back(9);
	array.push_back(8);
//	array.resize(20);
	for(std::vector<int>::const_iterator i=array.begin(); i!=array.end(); i++){
		std::cout<<*i<<" ";
	}
	std::cout<<"\n ";

	std::vector<int>::iterator j;
	j = array.begin()+1;
	array.insert(j, 100);
	for(std::vector<int>::iterator i=array.begin(); i!=array.end(); i++){
		*i*=2;
		std::cout<<*i<<" ";
	}
	std::cout<<"\n ";
	return 1;
}

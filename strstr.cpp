#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool search_next(std::string::iterator it0, std::string::iterator it1, std::string::iterator hayend, std::string::iterator needleend){
	    if(it1 == needleend)
		    return true;
	    if(it0==hayend)
		    return false;
	    bool tmp= false;
	    if(*it1 == *it0){
		    tmp = search_next(it0+1, it1+1, hayend, needleend);
	    } 
	    return tmp;
    }
    int strStr(std::string &haystack, std::string &needle) {
	if(needle.length()==0)
		return 0;
	if(needle.length()>haystack.length())
		return -1;
	if(!haystack.compare(needle))
		return 0;
	bool tmp = false;
	for(std::string::iterator it=haystack.begin(); it!=haystack.end(); it++){
		if(*it==needle.front()){
			bool tmp = search_next(it+1, needle.begin()+1, haystack.end(), needle.end());
			if(tmp==true)
				return it-haystack.begin();
		}

	}
	return -1;	
    }
};


int main(){
	Solution s;
	std::string haystack("mississippi");
	std::cout<< "haystack:" <<haystack <<std::endl;
	std::string needle("issip");
	std::cout<< "needle:" <<needle <<std::endl;
	std::cout<<s.strStr(haystack, needle)<<std::endl;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
/***
typedef struct bst{
	char element;
	struct bst *lchild, *rchild;
}s_bst;
 ***/
class Solution{
	private:
		int strcompare(std::string &str1, std::string &str2){
			int n = (str1.length()<str2.length())? str1.length():str2.length();
			for (int i = 0; i<n; i++){
				if(str1[i]!=str2[i])
					return i;
			}
			return n;
		}
	public:
		std::string longestCommonPrefix(std::vector<std::string>& strs){
			int count = 0;
			if(strs.size()==0)
				return("");
			if(strs.size()==1)
				return(strs.at(0));
			std::string tmp = strs[0];
			for (std::vector<std::string>::iterator it = strs.begin(); it!=strs.end()-1; it++){
				count = strcompare(tmp, *(it+1));
				if (count == 0)
					return("");
				tmp = (*it).substr(0, count);
			}
			return(tmp);
		}
};



int main(){
	//const char* tmp[] = {"flower","flow","flight"};
	//const char* tmp[] = {""};
	const char* tmp[] = {"acc","aaa","aaba"};
	std::vector<std::string> strs(tmp, std::end(tmp));
	Solution s;
	std::cout<<s.longestCommonPrefix(strs)<<std::endl;
	return 1;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Solution {
	public:
		static bool isNotAlpha(char c){
			return !(std::isalpha(c)||std::isdigit(c));
		}
		static bool compareChar(char & c1, char & c2)
		{
			if (c1 == c2)
				return true;
			else if (std::toupper(c1) == std::toupper(c2))
				return true;
			return false;
		}
		bool isPalindrome(std::string s) {
			//std::remove_if(s.begin(), s.end(), isNotAlpha);
			s.erase(remove_if(s.begin(), s.end(), isNotAlpha ), s.end());
			std::string rs(s.begin(), s.end());
			std::cout<<s<<"\n";
			std::reverse(rs.begin(), rs.end());
			std::cout<<rs<<"\n";
			return std::equal(s.begin(), s.end(), rs.begin(), compareChar);
		}
};

int main(){
	//std::string st("race a car");
//	std::string st("ada");
	std::string st("0F");
	Solution s;
	std::cout<<s.isPalindrome(st);
	return 1;
}	

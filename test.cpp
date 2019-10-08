#include <algorithm>
#include <string>
#include <iostream>
#include <cctype>

bool isNotAlpha(char c){
	return !std::isalpha(c);
}

int main()
{
    std::string str1 = "Text with some   spaces";
    str1.erase(std::remove_if(str1.begin(), str1.end(), (isNotAlpha)), str1.end());
    std::cout << str1 << '\n';
 
    /**std::string str2 = "Text\n with\tsome \t  whitespaces\n\n";
    str2.erase(std::remove_if(str2.begin(), 
                              str2.end(),
                              [](unsigned char x){return std::isspace(x);}),
               str2.end());
    std::cout << str2 << '\n';**/
}

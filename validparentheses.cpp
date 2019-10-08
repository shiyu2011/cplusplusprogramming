#include<algorithm>
#include<vector>
#include<iostream>

class Solution {
public:
    bool isValid(std::string s) {
	    if (s.size()==0)
		    return true;
	    std::vector<std::string> tmp;
	    tmp.reserve(s.size());
	    for(auto it = s.begin(); it!=s.end(); it++){
		    if(tmp.size()==0)
			    tmp.push_back(*it);
		    else if(tmp.back()=="("&&*it==")"){
			    tmp.pop_back();
		    }
		    else if(tmp.back()=="["&&*it=="]"){
			    tmp.pop_back();
		    }
		    else if(tmp.back()=="{"&&*it=="}"){
			    tmp.pop_back();
		    }
		    else
			    tmp.push_back(*it);
	    }
	    if(tmp.size()==0)
		    return true;
	    return false;
    }
};

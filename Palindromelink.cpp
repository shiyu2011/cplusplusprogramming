#include<vector>
#include<algorithm>
#include<iostream>

typedef struct ListNode {
     int val;
     ListNode *next;
} s_ListNode;

/**
class Solution {
public:
    bool isPalindrome(s_ListNode* head) {
            s_ListNode *p = head;
            std::vector<int> tmp;
            tmp.reserve(100);
            bool flag = false;
            if (p==NULL||p->next==NULL)
                return true;
            while(p!=NULL){
                    if(tmp.size()==0){
                            tmp.push_back(p->val);
                    }
		    else if(p->val==tmp.back()){
                            tmp.pop_back();
                            if(tmp.size()==0)
                                return true;
                    }
                    else{
                            tmp.push_back(p->val);
                    }
                    p=p->next;
            }
            return false;
    }
};

**/

class Solution{
	public:
		bool isPalindrome(s_ListNode* head){
			std::vector<int> tmp;
			tmp.reserve(100);
			s_ListNode *p = head;
			if(p==NULL)
				return true;
			while(p!=NULL){
				tmp.push_back(p->val);
				p=p->next;
			}
			p = head;
			while(p!=NULL){
				if(p->val!=tmp.back())
					return false;
				else{
					tmp.pop_back();
				}
				p=p->next;
			}
			return true;
		}
};

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

typedef struct ListNode{
      int val;
      ListNode *next;
  }s_ListNode;


class Solution {
	public:
		ListNode *getIntersectionNode(s_ListNode *headA, s_ListNode *headB) {
			s_ListNode *pA=headA;
			s_ListNode *pB=headB;
			int32_t key = 0;
			std::unordered_map<s_ListNode *, int32_t> umap;
			while(pA !=NULL){
				umap[pA] = key;
				pA = pA->next;
				key++;
			}
			while(pB !=NULL){
				if(umap.find(pB)!=umap.end())
					return pB;
				pB = pB->next;
			}
			return NULL;
		}
};

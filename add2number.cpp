/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *currentL1 = l1;
        ListNode *currentL2 = l2;
        int advanceVal = 0;
        int tmpVal = 0;
        ListNode *resultL3 = NULL;
        ListNode *currentL3 = NULL;
        bool isL1End = false;
        bool isL2End = false;
        tmpVal = currentL1->val + currentL2->val;
        if(tmpVal >= 10){
            advanceVal = 1;
            resultL3 = new ListNode(tmpVal - 10);
        }
        else{
            advanceVal = 0;
            resultL3 = new ListNode(tmpVal);
        }
        currentL3 = resultL3;
        while(1){
            if(currentL1->next==NULL && currentL2->next==NULL){
                if(advanceVal > 0){
                    currentL3->next = new ListNode(advanceVal);
                }
                return resultL3;
            }
            if(currentL1->next!=NULL){
                currentL1 = currentL1->next;
            }
            else{
                isL1End = true;
            }
            if(currentL2->next!=NULL){
                currentL2 = currentL2->next;
            }
            else{
                isL2End = true;
            }
            if(isL1End){
                tmpVal = currentL2->val + advanceVal;
                advanceVal = 0;
            }
            else if(isL2End){
                tmpVal = currentL1->val + advanceVal;
                advanceVal = 0;
            }
            else{
                tmpVal = currentL1->val + currentL2->val + advanceVal;
                advanceVal = 0;
            }
            if(tmpVal>=10){
                advanceVal = 1;
                currentL3->next = new ListNode(tmpVal - 10);
                currentL3 = currentL3->next;
            }
            else{
                advanceVal = 0;
                currentL3->next = new ListNode(tmpVal);
                currentL3 = currentL3->next;
            }
        }
    }
};

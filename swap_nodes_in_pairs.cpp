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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *f = head;
        ListNode *s = NULL;
        ListNode *temp=NULL;
        head = head->next;
        while(f!=NULL && f->next!=NULL){
            s=f->next->next;
            f->next->next=f;
            if(temp!=NULL){
                temp->next= f->next;
            }
            temp = f;
            f=s;
        }
        if(f!=NULL){
            temp->next=f;
        }
        else{
            temp->next=NULL;
        }
        return head;
    }
};

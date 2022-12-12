/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL||head->next==NULL)
            return NULL;
        int flag=0;
        ListNode* f=head->next;
        ListNode* s=head->next->next;
        while(s!=NULL &&s->next!=NULL){
            f = f->next;
            s = s->next->next;
            if(f==s){
                flag=1;
                break;
            }
        }
        if(flag==0){
            return NULL;
        }
        else{
            f = head;
            while(s!=f){
                f = f->next;
                s = s->next;
            }
        }
        return f;
    }
};

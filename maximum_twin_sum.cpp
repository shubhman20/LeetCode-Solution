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
    int Size(ListNode *head){
        ListNode * temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }

    int pairSum(ListNode* head) {
        int n = Size(head);
        vector<int> add(n/2,0);
        ListNode *temp = head;
        int val=0;
        int ans=0;
        while(temp!=NULL){
            if(val<n/2){
                add[val]+=temp->val;
                ans= max(ans,add[val]);
            }
            else{
                add[n-val-1]+=temp->val;
                ans= max(ans,add[n-val-1]);
            }
            val++;
            temp=temp->next;
        }
        return ans;
    }

};

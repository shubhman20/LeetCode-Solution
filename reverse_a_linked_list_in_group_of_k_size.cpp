/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    
    struct node *reverse (struct node *head, int k)
    { 
        //base case for recursion
        if(head==NULL) return NULL;
        struct node* next=NULL;
        struct node* curr = head;
        struct node* prev = NULL;
        
        //reverse k LL
        int cnt=0;
        while(curr!=NULL && cnt<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        
        //calling recursion to solve other cases
        if(next!=NULL){
            head->next=reverse(next,k);
        }
        
        //return head of LL
        return prev;
        
    }
};

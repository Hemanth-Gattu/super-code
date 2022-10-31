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
    
   
    
    ListNode *addboth(ListNode* first,ListNode *second){
        int carry=0;
        ListNode *head=NULL;
        ListNode *ptr=NULL;
        while(first || second){
            int sum=carry;
            if(first){
                sum+=first->val;
                first=first->next;
                
            }
            if(second){
                sum+=second->val;
                second=second->next;
            }
            carry=sum/10;
            sum=sum%10;
            ListNode *temp=new ListNode(sum);
            if(head==NULL){
                head=temp;
            }
            else{
                ptr->next=temp;
            }
            ptr=temp;
            
        }
        if(carry!=0){
            ListNode *temp=new ListNode(carry);
            ptr->next=temp;
        }
        return head;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
     
        ListNode *result=addboth(l1,l2);
        // result=reverse(result);
        return result;
        
    }
};

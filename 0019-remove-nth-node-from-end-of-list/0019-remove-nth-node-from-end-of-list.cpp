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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return nullptr;
        int total =0;
        ListNode* temp = head;
        while(temp != nullptr){
            total++;
            temp = temp->next;
        }
        int l = total+1-n;
        if(l==1){
            ListNode* del = head; 
            head = head->next;
            delete del;
            return head;
        } 
        temp = head;

        int cnt =l-1;
        while(cnt>1){
            temp = temp->next;
            cnt--;
        }
        
        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;
        return head;        
    }
};
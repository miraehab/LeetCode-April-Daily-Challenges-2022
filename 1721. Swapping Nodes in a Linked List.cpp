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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* tmp = head;
        ListNode* first = new ListNode;
        ListNode* second = new ListNode;
        ListNode* answer = new ListNode;
        ListNode* Head_answer = answer;
        int i = 1, size = 0;
        while(tmp != NULL){
            if(i == k) first->val = tmp->val; 
            ++i;
            ++size;
            tmp = tmp->next;
        }
        tmp = head;
        for(int j = 1; j<=size-k+1; ++j){
            if(j == size-k+1) second->val = tmp->val;
            if(tmp == NULL) break;
            tmp = tmp->next;
        }
        tmp = head;
        for(int j = 1; j <= size; ++j){
            if(tmp == NULL) break;
            if(j == k) answer->next = second;
            else if(j == size-k+1) answer->next = first;
            else answer->next = tmp;
            tmp = tmp->next;
            answer = answer->next;
        }
        return Head_answer->next;
    }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef pair<int, pair<int, ListNode*>> ppi;

//O(N*logk) N- number of all elements, k nr of arrays
class Solution {
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* pHead = NULL; //we need pHead to move because we would loose the pointer 
        ListNode* head = NULL; //head of the new list
        
        priority_queue<ppi, vector<ppi>,greater<ppi>> pq;
        for(int i = 0; i <lists.size() ; ++i)
            if(lists[i]) //if not null
                pq.push({lists[i]->val, {i, lists[i]->next}});
        
        if(!pq.empty()) //the first time to set head can move it inside the while loop for less code
        {
            ppi top = pq.top();
            pq.pop();
            head = pHead = new ListNode(top.first);
            ListNode* node = top.second.second; //next node to be inserted in pq, can be null if we are at the last el of list
            if(node) pq.push({node->val, {top.first,node->next}}); //push if not null
        }
           
        while(!pq.empty())
        {
            ppi top = pq.top();
            pq.pop();
            pHead->next = new ListNode(top.first);
            pHead = pHead->next;
            ListNode* node = top.second.second; //if this is null 
            if(node) pq.push({node->val, {top.first,node->next}});    
        }
        
        return head;      
     }
};


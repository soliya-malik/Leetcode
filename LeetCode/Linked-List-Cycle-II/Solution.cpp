1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode(int x) : val(x), next(NULL) {}
7 * };
8 */
9class Solution {
10public:
11    ListNode *detectCycle(ListNode *head) {
12        ListNode* slow = head;
13        ListNode* fast = head;
14
15        while(fast != NULL && fast->next != NULL){
16            slow = slow->next;
17            fast = fast->next->next;
18
19           if(slow==fast){
20            slow = head;
21           
22           while(slow!=fast){
23            slow=slow->next;
24            fast= fast->next;
25           }
26           return slow;
27        
28        }
29        
30    }
31    return NULL;
32    }
33};
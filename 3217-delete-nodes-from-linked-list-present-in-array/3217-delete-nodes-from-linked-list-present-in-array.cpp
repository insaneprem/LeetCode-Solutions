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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        
        set<int> st(begin(nums), end(nums));

        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* temp = dummy;

        while (temp) {
            
            while(temp->next && st.count(temp->next->val)){
                temp->next = temp->next->next;
            }

            temp = temp->next;
        }

        return dummy->next;
    }
};
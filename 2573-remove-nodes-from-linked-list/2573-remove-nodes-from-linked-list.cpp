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
    ListNode* removeNodes(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;

        while (temp != nullptr) {
            int val = temp->val;

            while (!st.empty() && st.top() < val) st.pop();
            st.push(val);

            temp = temp->next;
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        ListNode* root = new ListNode(ans[0]);
        ListNode* t = root;
        for (int i = 1; i < ans.size(); i++) {
            t->next = new ListNode(ans[i]);
            t = t->next;
        }

        return root;
    }
};
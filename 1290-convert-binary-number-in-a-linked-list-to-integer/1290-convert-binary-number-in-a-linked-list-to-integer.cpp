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
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        string str = "";
        while (temp != nullptr) {
            str += to_string(temp->val);
            temp = temp->next;
        }

        int decimalval = 0, n = str.size();

        for (int i = 0; i < n; i++) {
            if (str[i] == '1')
                decimalval += (1 << (n - 1 - i));
        }

        return decimalval;
    }
};
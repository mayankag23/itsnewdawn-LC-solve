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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        if (head == nullptr ||
            head->next == nullptr ||
            head->next->next == nullptr) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;

        int first = -1;
        int last = -1;

        int mini = INT_MAX;

        while (curr->next != nullptr) {

            ListNode* next = curr->next;

            bool critical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);

            if (critical) {

                // First critical point
                if (first == -1) {
                    first = pos;
                }
                else {
                    // Distance from previous critical point
                    mini = min(mini, pos - last);
                }

                // Update last critical point
                last = pos;
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        // Less than 2 critical points
        if (first == -1 || first == last) {
            return {-1, -1};
        }

        int maxi = last - first;

        return {mini, maxi};
    }
};
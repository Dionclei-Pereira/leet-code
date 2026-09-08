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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(-1, head);
		ListNode* current = head;
		ListNode* lastValid = &dummy;
		
		while (current != nullptr) {
			if (current->val == val) {
				lastValid->next = current->next;
				current = lastValid->next;
			} else {
                lastValid = current;
                current = current->next;
			}
		}
		
		return dummy.next;
    }
};
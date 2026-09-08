class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* groupPrev = dummy;

        while (true) {

            // Find the kth node
            ListNode* kth = groupPrev;

            for (int i = 0; i < k; i++) {

                kth = kth->next;

                if (kth == nullptr) {
                    return dummy->next;
                }
            }

            ListNode* groupNext = kth->next;

            // Reverse the group
            ListNode* prev = groupNext;
            ListNode* current = groupPrev->next;

            while (current != groupNext) {

                ListNode* next = current->next;

                current->next = prev;

                prev = current;
                current = next;
            }

            // Connect previous part to reversed group
            ListNode* oldGroupStart = groupPrev->next;

            groupPrev->next = kth;

            // Move groupPrev to the end of reversed group
            groupPrev = oldGroupStart;
        }
    }
};
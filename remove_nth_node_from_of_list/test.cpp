class Solution {
	public:
		ListNode *removeNthFromEnd(ListNode *head, int n) {
			// Note: The Solution object is instantiated only once and is reused by each test case.
			ListNode dummy(0);
			if(head == NULL) return head;
			dummy.next = head;
			ListNode *backward = &dummy;
			ListNode *forward = head;
			for(int i = 0; i < n; i++) {
				forward = forward->next;
			}
			while(forward != NULL) {
				forward = forward->next;
				backward = backward->next;
			}
			ListNode *temp = backward->next;
			backward->next = temp->next;
			if(temp == head) {
				head = temp->next;
			}
			delete temp;
			return head;
		}
};

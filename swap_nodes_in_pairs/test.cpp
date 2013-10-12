class Solution {
	public:
		ListNode *swapPairs(ListNode *head) {
			// Note: The Solution object is instantiated only once and is reused by each test case.
			ListNode **ppre = &head;
			while(true) {
				ListNode *n0 = *ppre;
				if(NULL == n0) return head;
				ListNode *n1 = n0->next;
				if(NULL == n1) return head;
				*ppre = n1;
				n0->next = n1->next;
				n1->next = n0;
				ListNode *next = n1->next;
				ppre = &(n0->next);
			}
			return head;
		}
};

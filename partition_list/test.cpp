class Solution {
	public:
		ListNode *partition(ListNode *head, int x) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			ListNode *pL = NULL, *pR = NULL;
			ListNode *pLastR = NULL;
			ListNode **ppL = &pL, **ppR = &pR;
			while(head) {
				if(head->val < x) {
					//go to left
					*ppL = head;
					ppL = &(head->next);
				} else {
					//go to right
					*ppR = head;
					pLastR = head;
					ppR = &(head->next);
				}

				head = head->next;
			}
			//link left with right
			*ppL = pR;
			if(pLastR) pLastR->next = NULL;
			return pL;
		}
};

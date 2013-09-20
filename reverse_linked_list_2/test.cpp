class Solution {
	public:
		ListNode *reverseBetween(ListNode *head, int m, int n) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			//first find the first break point
			ListNode **firstBreak = &head;
			for(int i = 0 ; i < m - 1; ++i) {
				firstBreak = &( (*firstBreak) -> next );
			}
			//find the tail and point out the mid segment start/end point
			if(*firstBreak == NULL) return head;

			//reverset the middle segment
			{
				int rStep = n - m;
				while(rStep > 0) {
					ListNode ** pprTail = firstBreak;
					for(int i = 0 ; i < rStep; ++i)
						pprTail = &((*pprTail)->next);

					ListNode *firstNode = *firstBreak;
					ListNode *lastNode = *pprTail;
					ListNode *pOut = lastNode->next;
					ListNode *ps = firstNode->next;

					if(ps == lastNode) {
						ps = firstNode;
					}

					//cout<<firstNode->val<<","<<lastNode->val<<","<<pOut<<"|";
					//return NULL;

					*firstBreak = lastNode;
					lastNode->next = ps;
					*pprTail = firstNode;
					firstNode->next = pOut;

					firstBreak = &(lastNode->next);
					rStep -= 2;

					//cout<<rStep;
				}
			}
			return head;
			{
				ListNode *t = head;
				for(int i = 0; t && i < 10; ++i) {
					cout<<t->val<<",";
					t = t->next;
				}
				return NULL;
			}
		}
};

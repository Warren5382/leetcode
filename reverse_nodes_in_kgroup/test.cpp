class Solution {
	public:
		struct RetValue{
			ListNode *pReverseHead;
			ListNode *pPrev;
			RetValue():pReverseHead(NULL),pPrev(NULL){}
		};
		RetValue reverse(ListNode *head, int k) {
			RetValue ret;
			ListNode *pReverseHead = NULL;
			ListNode *pNode = head;
			ListNode *pPrev = NULL;
			for(int i = 0; i < k; i++) {
				ListNode *pNext = pNode->next;
				if(i==k-1) {
					pReverseHead = pNode;
				}
				pNode->next = pPrev;
				pPrev = pNode;
				pNode = pNext;
			}
			ret.pPrev = head;
			head->next = pNode;
			ret.pReverseHead = pReverseHead;
			return ret;
		}
		ListNode *reverseKGroup(ListNode *head, int k) {
			int len = 0;
			ListNode *cur = head;
			while(cur != NULL) {
				len++;
				cur = cur->next;
			}
			if(len < k) return head;
			RetValue ret;
			ListNode dummy(0);
			ret.pPrev = &dummy;
			dummy.next = head;
			ret.pPrev = &dummy;
			int loop = len/k;
			for(int i = 0; i < loop; i++) {
				ListNode *last = ret.pPrev;
				ret = reverse(last->next, k);
				last->next = ret.pReverseHead;
			}
			return dummy.next;

		}
};

class Solution {
	public:
		ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
			ListNode *proot = NULL;
			ListNode **pplast = &proot;
			while(l1 || l2){
				if(l1) {
					ListNode *minNode;
					if(!l2 || l1->val <= l2->val){
						//l1 is min
						minNode = l1;
						l1 = l1->next;
					} else if(l2) {
						//l2 is min
						minNode = l2;
						l2 = l2->next;
					}
					//proceed root
					*pplast = minNode;
					pplast = &(minNode->next);
				} else {
					//l1 is empty
					*pplast = l2;
					break;
				}
			}
			return proot;
		}
};

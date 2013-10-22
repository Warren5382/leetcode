class Solution {
	public:
		class comp {
			public:
				bool operator() (const ListNode* l, const ListNode* r) const {
					return (l->val > r->val);
				}
		};
		ListNode *mergeKLists(vector<ListNode *> &lists) {
			vector<ListNode*>::iterator it = lists.begin();
			while(it != lists.end()) {
				if(*it == NULL) lists.erase(it);
				else ++it;
			}
			if(lists.size() < 1) return NULL;
			ListNode dummy(0);
			ListNode *min = NULL;
			ListNode *cur = &dummy;
			make_heap(lists.begin(), lists.end(), comp());
			while(lists.size() > 0) {
				min = lists[0];
				lists[0] = lists[0]->next;
				if(lists[0] == NULL) {
					lists.erase(lists.begin());
				}
				make_heap(lists.begin(), lists.end(), comp());
				cur->next = min;
				cur = cur->next;
			}
			return dummy.next;
		}
};

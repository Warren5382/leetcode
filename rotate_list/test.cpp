class Solution {
	public:
		ListNode *rotateRight(ListNode *head, int k) {
			if(k <= 0) return head;
			ListNode **prob = &head;
			int count = 0;
			while(*prob){
				prob = &((*prob)->next);
				++count;
			}
			if(count <= 1) return head;
			k = k % count;
			*prob = head;//form a circle

			for(int i = 0 ; i < count - k; ++i) {
				prob = &((*prob)->next);
			}
			head = *prob;
			*prob = NULL;

			return head;
		}
};

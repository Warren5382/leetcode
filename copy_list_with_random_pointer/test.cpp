class Solution {
	public:
		RandomListNode *copyRandomList(RandomListNode *head) {
			unordered_map<RandomListNode*, int> oldsite;
			unordered_map<int, RandomListNode*> newsite;
			RandomListNode *now = head;
			RandomListNode dummy(0);
			RandomListNode *pre = &dummy;
			int index = 0;
			while(now != NULL) {
				RandomListNode *temp = new RandomListNode(now->label);
				pre->next = temp;
				pre = temp;
				oldsite[now] = index;
				newsite[index] = temp;
				index++;
				now = now->next;
			}

			pre = dummy.next;
			now = head;
			while(now != NULL) {
				if(now->random != NULL) {
					index = oldsite[now->random];
					pre->random = newsite[index];
				}
				else 
					pre->random = NULL;
				now = now->next;
				pre = pre->next;
			}

			return dummy.next;
		}
};

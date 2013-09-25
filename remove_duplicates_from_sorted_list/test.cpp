class Solution {
	public:
		ListNode *deleteDuplicates(ListNode *head) {
			// Start typing your C/C++ solution below
			// DO NOT write int main() function
			ListNode* pre;
			ListNode* now;
			if(head == NULL) return head;
			if(head->next == NULL) return head;
			pre = head;
			now = head->next;
			while(now != NULL) {
				if(pre->val != now->val) {
					pre->next = now;
					pre = pre->next;
					now = now->next;
				}
				else {
					now = now->next;
				}
			}
			pre->next = now;
			return head;
		}
};

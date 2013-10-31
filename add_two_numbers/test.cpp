class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int val = 0;
        int cin = 0;
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while(l1!=NULL && l2!=NULL) {
            val = l1->val + l2->val + cin;
            cin = val/10;
            val = val%10;
            ListNode *node = new ListNode(val);
            cur->next = node;
            cur = node;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL) {
            val = l1->val + cin;
            cin = val/10;
            val = val%10;
            ListNode *node = new ListNode(val);
            cur->next = node;
            cur = node;
            l1 = l1->next;
        }
        while(l2!=NULL) {
            val = l2->val + cin;
            cin = val/10;
            val = val%10;
            ListNode *node = new ListNode(val);
            cur->next = node;
            cur = node;
            l2 = l2->next;
        }
        if(cin > 0) {
            ListNode *node = new ListNode(cin);
            cur->next = node;
            cur = node;
        }
        return dummy.next;
    }
};
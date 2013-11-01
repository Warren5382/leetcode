class Solution {
public:
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast!=NULL && fast->next!=NULL) {
            fast = fast->next;
            fast = fast->next;
            slow = slow->next;
            if(fast == slow) break;
        }
        return !(fast==NULL||fast->next==NULL);
    }
};
// Reverse a Linked List in group of Given Size.

class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    {
        // Complete this method
        if(k == 1) { return head; }

        // we have to go to the Kth Item
        int i = 0;
        struct node* prev = head;
        while( i != k) {
            if(prev == NULL and i == 0) return prev;
            if(prev == NULL) {
                // reverse the items from the curHead.
                prev = head;
                struct node*cur = prev->next;
                prev->next = NULL;
                while(cur) {
                    struct node*tmp = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = tmp;
                }
                return prev;
            }
            prev = prev->next;
            i++;
        }
        prev = reverse(prev, k);
        struct node* cur = head;
        struct node* nextNode = cur->next;
        while(i--) {
            cur->next = prev;
            prev = cur;
            cur = nextNode;
            if(cur == NULL) nextNode = NULL;
            else nextNode = cur->next;
        }
        return prev;
    }
};

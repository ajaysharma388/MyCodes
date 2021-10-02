class Solution
{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head)
    {
        // your code here
        // initialising slow and fast pointers.
        Node* slow = head;
        Node* fast = head;
        // we will keep
        // them moving until fast reached the end i.e, there is no cycle.
        // or the meet somewhere in between i.e, there is cycle in the linked list.
        while(true)
        {
            slow = slow->next;
            if(fast->next == NULL or fast->next->next == NULL) break;
            fast = fast->next->next;
            if(fast == slow) return true;
        }
        return false;
    }
};

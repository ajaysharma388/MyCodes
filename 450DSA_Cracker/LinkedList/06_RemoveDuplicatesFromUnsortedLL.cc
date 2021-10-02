// the input for this is  sorted linked list that may or may not
// contains the repeating nodes. If there are any repeating node
// in the list this method will remove the extra repeating nodes.
// Time complexity of that code would be O(N) & Space Complexity
// would be O(N).


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates( Node *head)
    {
        if(head->next == NULL) return head;
        // your code goes here
        set<int> table;
        Node *itr = NULL;
        Node *ptr = head;
        while(ptr) {
            if(table.find(ptr->data) == table.end()) {
                table.insert(ptr->data);
                if (itr == NULL) itr = ptr;
                else { itr->next = ptr; itr = itr->next; }
                ptr = ptr->next;
                itr->next = NULL;
            } else {
                Node* tmp = ptr;
                ptr = ptr->next;
                delete tmp;
            }
        }
        return head;
    }
};

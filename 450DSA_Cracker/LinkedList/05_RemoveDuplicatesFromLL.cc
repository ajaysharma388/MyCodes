// the input for this is  sorted linked list that may or may not
// contains the repeating nodes. If there are any repeating node
// in the list this method will remove the extra repeating nodes.
// Time complexity of that code would be O(N) & Space Complexity
// would be O(1).


Node *removeDuplicates(Node *head)
{
    if(head->next == NULL) return head;
    struct Node *itr = head;
    struct Node *ptr = head->next;
    while(ptr) {
        if(itr->data != ptr->data) {
            itr->next = ptr;
            itr = ptr;
            ptr = ptr->next;
        } else {
            Node* tmp = ptr;
            ptr = ptr->next;
            delete tmp;
        }
        itr->next = NULL;
    }
    return head;
}
// the input for this is  sorted linked list that may or may not
// contains the repeating nodes. If there are any repeating node
// in the list this method will remove the extra repeating nodes.
// Time complexity of that code would be O(N) & Space Complexity
// would be O(1).


Node *removeDuplicates(Node *head)
{
    if(head->next == NULL) return head;
    struct Node *itr = head;
    struct Node *ptr = head->next;
    while(ptr) {
        if(itr->data != ptr->data) {
            itr->next = ptr;
            itr = ptr;
            ptr = ptr->next;
        } else {
            Node* tmp = ptr;
            ptr = ptr->next;
            delete tmp;
        }
        itr->next = NULL;
    }
    return head;
}

class Solution
{
    int carry;
    public:
    Node* addOneHealper(Node *head)
    {
        // Your Code here
        // return head of list after adding one
        if(head->next == NULL) {
            head->data += 1;
            carry = head->data / 10;
            head->data %= 10;
            return head;
        }

        head->next = addOneHealper(head->next);
        head->data += carry;
        carry = head->data / 10;
        head->data %= 10;
        return head;
    }

    Node* addOne(Node *head) {
        carry = 0;
        head = addOneHealper(head);
        while(carry) {
            Node *ptr = new Node(carry%10);
            ptr->next = head;
            head = ptr;
            carry /= 10;
        }
        return head;
    }
};

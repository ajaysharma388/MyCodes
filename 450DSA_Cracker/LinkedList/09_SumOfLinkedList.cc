#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

void fastio(bool read = false) {
    if(read) {
        #ifndef ONLINE_JUGDE
        freopen("../../input.txt","r",stdin);
        freopen("../../output.txt","w",stdout);
        freopen("../../error.txt","w",stderr);
        #endif
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}


struct Node
{
    public:
    int data;
    Node *next;
    void __init__(const int data) {
        this->data = data;
        this->next = NULL;
    }
};


// Build the linked list iteratively.
Node* buildListIterative(int curdata, int target) {
    Node *head = NULL, *cur = NULL;
    cur = NULL;
    while(curdata <= target) {
        Node *tmp = new Node();
        tmp->__init__(curdata);
        if(cur == NULL) {
            head = tmp;
            cur = head;
        }
        else {
            cur->next = tmp;
            cur = cur->next;
        }
        curdata += 1;
    }
    return head;
}

class Solution
{
    public:
    //Function to add two numbers represented by linked list.

    static void printlinklist(struct Node *head)
    {
        while(head)
        {
            cout << head->data << " ";
            head=head->next;
        }
        cout << endl;
    }

    static int reverse(struct Node* &head) {
        struct Node* ptr = head, *itr;
        head = NULL;
        int length = 0;
        while(ptr) {
            if(head == NULL) {
                head = ptr;
                ptr = ptr->next;
                head->next = NULL;
            } else {
                head = ptr;
                ptr = ptr->next;
                head->next = itr;
            }
            itr = head;
            length += 1;
        }
        return length;
    }

    static struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        int m = reverse(first);
        int n = reverse(second);

        if(m < n) {
            swap(m,n);
            swap(first, second);
        }

        struct Node* itrFirst = first, *itrSecond = second;
        int carry = 0;
        while(itrFirst and itrSecond) {
            int data = itrFirst->data + itrSecond->data + carry;
            itrFirst->data = data%10;
            carry = data/10;
            struct Node* tmp = itrSecond;
            itrFirst = itrFirst->next;
            itrSecond = itrSecond->next;
            delete tmp;
        }
        while(itrFirst and carry) {
            int data = itrFirst->data + carry;
            itrFirst->data = data%10;
            carry = data/10;
            itrFirst = itrFirst->next;
        }
        reverse(first);
        while(carry) {
            struct Node* tmp;
            tmp->__init__(carry%10);
            tmp->next = first;
            first = tmp;
            carry /= 10;
        }
        return first;
    }
};


int main() {
  fastio(true);
  struct Node* first = buildListIterative(1, 9);
  struct Node* second = buildListIterative(1, 9);
  struct Node* head = Solution::addTwoLists(first, second);
  Solution::printlinklist(head);
  return 0;
}

// Sample Output

// 2 4 6 9 1 3 5 7 8

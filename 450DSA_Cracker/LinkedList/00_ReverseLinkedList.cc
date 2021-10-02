#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

#define ll long long int
#define endl '\n'

void fastio(bool read = false) {
    if(read) {
        #ifndef ONLINE_JUGDE
        freopen("../input.txt","r",stdin);
        freopen("../output.txt","w",stdout);
        freopen("../error.txt","w",stderr);
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


// print linked list.
void printlinklist(Node *head)
{
    while(head)
    {
        cout << head->data << " ";
        head=head->next;
    }
    cout << endl;
}

// Build the linked list recursively.
Node* buildList(int curdata, int target) {
    if(curdata == target) {
        Node* ptr = new Node();
        ptr->__init__(curdata);
        return ptr;
    }
    Node *curNode = new Node();
    curNode->__init__(curdata);
    curNode->next = buildList(curdata + 1, target);
    return curNode;
}


// Build the linked list iteratively.
Node* buildListIterative(int curdata) {
    Node *head = NULL, *cur = NULL;
    cur = NULL;
    while(curdata != 0) {
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
        curdata -= 1;
    }
    return head;
}

// Reverse linked list recursive solution.
Node* reverseLinkedList(Node* head, Node* &newHead) {
    if(head->next == NULL) {
        newHead = head;
        return newHead;
    }
    Node* tmp = reverseLinkedList(head->next, newHead);
    head->next = NULL;
    tmp->next = head;
    tmp = tmp->next;
    return tmp;
}

// Reverse linked list iterative solution.
Node* reverseLinkedListIterative(Node* head) {
    Node *newHead = NULL, *tmpPtr = NULL;
    Node *tmp = head;
    while(tmp) {
        if(newHead == NULL) {
            newHead = tmp;
            tmp = tmp->next;
            newHead->next = NULL;
        }
        else {
            tmpPtr = tmp->next;
            tmp->next = newHead;
            newHead = tmp;
            tmp = tmpPtr;
        }
    }
    return newHead;
}

int main() {
    fastio(true);
    auto start = high_resolution_clock::now();

    // Calling Tail recursive to get the linked list.
    Node* head = buildList(1, 10);
    // Calling iterative one to get the linked list.
    // Node* head = buildListIterative(10);


    // Get duration. Substart timepoints to
    // get durarion. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);

    printlinklist(head);
    Node* newHead = reverseLinkedListIterative(head);
    printlinklist(newHead);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}

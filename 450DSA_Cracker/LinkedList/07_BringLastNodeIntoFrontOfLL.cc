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


Node* modifyList(Node *head) {
	Node *ptr = head;
	Node *prev = NULL;
	while(ptr->next) {
		prev = ptr;
		ptr = ptr->next;
	}
	prev->next = NULL;
	ptr->next = head;
	return ptr;
}


int main() {
  fastio(true);
  Node *head = buildListIterative(1, 10);
  printlinklist(head);
  Node *newHead = modifyList(head);
  printlinklist(newHead);
  return 0;
}

// Sample Input :

// Sample Output :

// 1 2 3 4 5 6 7 8 9 10
// 10 1 2 3 4 5 6 7 8 9

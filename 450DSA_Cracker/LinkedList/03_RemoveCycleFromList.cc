#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define endl '\n'

void fastio(bool read = false) {
    if(read) {
        #ifndef ONLINE_JUGDE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
        freopen("error.txt","w",stderr);
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
	int i = 18;
    while(head and i)
    {
        cout << head->data << " ";
        head=head->next;
        i--;
    }
    cout << endl;
}

void addCycle(int node, Node *head) {
	Node *ptr = head;
	while(node != ptr->data and ptr) {
		ptr = ptr->next;
	}
	Node *tail = head;
	while(tail->next) {
		tail = tail->next;
	}
	tail->next = ptr;
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

Node* findCycleNode(Node *head) {
	Node *slow = head, *fast = head;
	while(true) {
		slow = slow->next;
		if(fast->next == NULL or fast->next->next == NULL) return NULL;
		fast = fast->next->next;
		if(slow == fast) return slow;
	}
}

void removeLoop(Node *head) {
	Node *loopNode = findCycleNode(head);
	if(loopNode == NULL) { return; }

	int k = 1;
	Node *ptr = loopNode->next;
	while(ptr != loopNode) {
		k += 1;
		ptr = ptr->next;
	}
    // move the kth node.
	Node *kthNode = head;
	for(int i = 0; i < k; ++i) {
		kthNode = kthNode->next;
	}
	ptr = head;
	if(ptr == kthNode) {
		// if loop includes the head node then
		// this case should be handled seperately.
	    while(ptr->next != kthNode) {
	        ptr = ptr->next;
	    }
	    ptr->next = NULL;
	}
	else {
    	// Now move kthNode and ptr until there next meet at the
    	// same point.
    	while(ptr->next != kthNode->next) {
    		ptr = ptr->next;
    		kthNode = kthNode->next;
    	}
    	kthNode->next = NULL;
	}
}


int main() {
  fastio(true);
  Node* head = buildListIterative(1, 10);
  addCycle(4, head);
  removeLoop(head);
  printlinklist(head);
  return 0;
}

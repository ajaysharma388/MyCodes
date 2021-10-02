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


class LinkedList {
	class Node {
	public:
		int data;
		Node* next;
		Node(const int data) {
			this->data = data;
			this->next = NULL;
		}
	};
	int n;
	Node *head, *tail;
public:
	LinkedList() {
		n = 0;
		this->head = this->tail = NULL;
	}
	void insert(const int val) {
		this->n++;
		if(this->head == NULL) {
			this->head = new Node(val);
			this->tail = this->head;
		} else {
			this->tail->next = new Node(val);
			this->tail = this->tail->next;
		}
	}
	void reverseList() {
		Node* newHead = NULL;
		Node* newTail = NULL;
		Node* ptr = this->head;
		while(ptr) {
			if(newHead == NULL) {
				newHead = ptr;
				ptr = ptr->next;
				newHead->next = NULL;
				newTail = newHead;
			} else {
				Node *tmp = ptr->next;
				ptr->next = newHead;
				newHead = ptr;
				ptr = tmp;
			}
		}
		this->head = newHead;
		this->tail = newTail;
	}

	void reverseList(Node* &start, Node* &end) {
		Node* newHead = NULL;
		Node* newTail = NULL;
		Node* ptr = start;
		while(ptr) {
			if(newHead == NULL) {
				newHead = ptr;
				ptr = ptr->next;
				newHead->next = NULL;
				newTail = newHead;
			} else {
				Node *tmp = ptr->next;
				ptr->next = newHead;
				newHead = ptr;
				ptr = tmp;
			}
		}
		start = newHead;
		end = newTail;
	}

	void reverseEvenChunkList() {
		Node *preStart = NULL;
		Node *start = this->head;

		Node *end = head;
		Node *out = NULL;

		while(true) {
			while(start and start->data % 2 != 0) {
				preStart = start;
				start = start->next;
			}
			if(start == NULL) break;
			end = start;
			if(start->next == NULL) break;
			out = start->next;
			while(out != NULL and out->data % 2 == 0) {
				end = end->next;
				out = out->next;
			}
			// breaking the list.
			if(start != end) {
				end->next = NULL;
				reverseList(start, end);
			}
			// Itegrating the list again.
			end->next = out;
			if(preStart == NULL) {
				head = start;
			} else {
				preStart->next = start;
				this->tail = end;
			}
			if(out == NULL) break;
			else start = out;
		}
	}

	void printList() {
		Node* itr = this->head;
		while(itr) {
			cout << itr->data << " ";
			itr = itr->next;
		}
		cout << endl;
	}
};

void solve() {
  LinkedList *list = new LinkedList();
  int n;
  cin >> n;
  while(n--) {
  	int data;
  	cin >> data;
  	list->insert(data);
  }
  list->reverseEvenChunkList();
  // cout << endl;
  list->printList();
  return;
}

int main() {
  fastio(true);
  int testcases;
  cin >> testcases;
  for(int task = 1; task <= testcases; ++task) {
  	cout << "Case #" << task << ": ";
  	solve();
  }
  return 0;
}

// Sample Input :

// 4
// 4
// 1 1 1 1
// 7
// 1 2 3 4 6 8 5
// 6
// 2 4 6 8 10 12
// 9
// 2 18 24 3 5 7 9 6 12

// Sample Output :

// Case #1: 1 1 1 1
// Case #2: 1 2 3 8 6 4 5
// Case #3: 12 10 8 6 4 2
// Case #4: 24 18 2 3 5 7 9 12 6 

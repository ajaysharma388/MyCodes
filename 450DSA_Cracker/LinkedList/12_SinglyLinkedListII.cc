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

	// DeleteFriend=false
 //    for i = 1 to Friend.length-1
 //         if (Friend[i].popularity < Friend[i+1].popularity)
 //            delete i th friend
 //            DeleteFriend=true
 //            break
 //    if(DeleteFriend == false)
 //        delete the last friend

	void deleteFriend(int k) {
		bool deleteFr = false;
		Node *ptr = head;
		Node *ptrNx;
		Node *ptrPre;
		for(int i = 1, and i < n and ptr != NULL; ++i) {
			cout << "Debug::91 => " << ptr->data << " ";
			if(ptr->data < ptrNx->data) {
				deleteFr = true;
				if(ptr == head) {
					this->head = ptr->next;
				} else {
					ptrPre->next = ptr->next;
				}
				Node *tmp = ptr;
				ptr = ptr->next;
				delete tmp;
			}
			ptrPre = ptr;
			ptr = ptrNx;
			ptrNx = ptrNx->next;
			deleteFr = false;
		}
		if(!deleteFr) {
			// delete the last node.
			ptrPre->next = NULL;
			delete ptr;
			this->tail = ptrPre;
		}
		cout << endl;
		return;
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
  int n, k;
  cin >> n >> k;
  while(n--) {
  	int data;
  	cin >> data;
  	list->insert(data);
  }

  list->deleteFriend(k);
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

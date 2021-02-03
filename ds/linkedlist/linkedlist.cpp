#include <bits/stdc++.h>
using namespace std;
void shm() {
#ifndef ONLINE_JUDGE
	freopen("D:\\cpp\\input.txt", "r", stdin);
	freopen("D:\\cpp\\output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

class Node {
public:
	int data;
	Node* next;
};
void printList(Node* n) {
	while (n != NULL) {
		cout << n->data << "->";
		n = n->next;
	}
	cout << "NULL" << endl;
	cout << endl;
}
Node* insertAtBeg(Node* head, int data) {
	Node* temp = new Node();
	temp->data = data;
	temp->next = head;
	head = temp;
	return head;
}
Node* insertAtEnd(Node* head, int data) {
	Node* trace = head;
	Node* temp = new Node();
	temp->next = NULL;
	temp->data = data;
	if (head == NULL) {
		head  =  temp;
		return head;
	}
	while (trace->next != NULL)
	{
		trace = trace->next;
	}
	trace->next = temp;
	return head;
}

void insertAfter(Node* prev, int data) {
	if (prev == NULL)
		cout << "Prev shouldn't be empty " << endl;

	Node* temp = new Node();
	temp->data = data;
	temp->next = prev->next;
	prev->next = temp;
}
void deleteItem(Node* head, int item) {
	//creating a temp to hold head ref
	Node* temp = head;
	//checking if head has item to be deleted
	if (temp != NULL && temp->data == item) {
		head = head->next;
		free(temp);
		return ;
	}
	//to track node before the current node in below loop
	Node* prevToTrack;
	while (temp != NULL && temp->data != item) {
		prevToTrack = temp;
		temp = temp -> next;
	}
	//if didnt found key wont delete anything
	if (temp == NULL) return;
	//removing the node to be deleted
	prevToTrack->next = temp->next;
	free(temp );
}
Node* allInsertions(Node* head) {
	//insert at beginning
	head = insertAtBeg(head, 10); //returning new head
	cout << "After inseting at beginning" << endl;
	printList(head);
	//insert at end
	head = insertAtEnd(head, 1000);
	cout << "After inserting at a end" << endl;
	printList(head);
	//insert at a point
	insertAfter(head->next->next, 100);
	cout << "Inserting on basis of a given key" << endl;
	printList(head);
	return head;
}
void NthNodeFromLast(Node* head, int pos) {
	int len = 0;
	Node* temp  = head;
	while (temp != NULL) {
		temp = temp -> next;
		len++;
	}
	if (pos > len)return;
	temp = head;
	for (int i = 1; i < len - pos + 1; i++)
	{
		temp = temp->next;
	}
	cout << "Node at " << pos << "th postn From Last has " << temp->data << endl;
}
Node* reverse(Node* head) {
	Node* current = head;
	Node* prev = NULL, *next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	cout << "\n After reversing Linkedlist " << endl;
	return head;
}
Node* implementations(Node* head) {

	NthNodeFromLast(head, 4);
	head = reverse(head);
	printList(head);
	return head;
}
int main()
{	shm();
	//inserting some nodes
	Node* head = new Node();
	Node* second = new Node() ;
	Node* third = new Node();
	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;
	std::cout << "created a base linked list" << std::endl;
	printList(head);//base ll
	head = allInsertions(head);//all insertions here
	//delete a given key
	deleteItem(head, 3);
	cout << "delete a given item" << endl;
	printList(head);

	head = implementations(head);

	return 0;

}


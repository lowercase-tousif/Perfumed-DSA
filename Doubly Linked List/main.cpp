#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
};

struct Node *head;


void insert_first(int x){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

	temp->data = x;

	if(head == NULL){
		head = temp;
		return;
	}

	head->prev = temp;
	temp->next = head;
	head = temp;
}

void print_doubly_ll_forward(Node *head){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp = head;

	while(temp != nullptr){
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
}

void print_doubly_ll_reverse(Node *head){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp = head;

    while(temp->next != nullptr){
        temp = temp->next;
    }

	while(temp != nullptr){
		cout << temp->data << " ";
		temp = temp->prev;
	}
	cout << endl;
 }


int main(){

	head = nullptr;

	while(1){
		string s;
		cin >> s;

		if (s == "insert"){
			int num;
			cin >> num;
			insert_first(num);
		}
		else if(s == "print_forward"){
			print_doubly_ll_forward(head);
		}
		else if(s == "print_reverse"){
			print_doubly_ll_reverse(head);
		}
		else if(s == "exit"){
			exit(0);
		}
	}
}

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *next, *prev;
};


struct Node *head;

void push(int x){
	Node *newnode = new Node;
	newnode->data = x;
	newnode->next = nullptr;
	
	if(head == nullptr){
		newnode->prev = nullptr;
		head = newnode;
		return;
	}
	
	Node *temp = head;
	
	while(temp->next != nullptr){
		temp = temp->next;
	}
	
	temp->next = newnode;
	newnode->prev = temp;
}

void print(Node *head){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	temp = head;

	while(temp != nullptr){
		cout << temp->data << " ";
		temp = temp->next;
	}

	cout << endl;
}

Node *pop(Node *head){
	if(head == nullptr){
		return nullptr;
	}
	Node *temp = head;
	head = head->next;
	
	if(head != nullptr){
		head->prev = nullptr;
	}
	return head;
}
	

int main(){
	head = nullptr;
	
	while(1){
		string s;
		cin >> s;
		
		if(s == "push"){
			int num;
			cout << "Enter number:";
			cin >> num;
			push(num);
		}
		else if(s == "print"){
			print(head);
		}else if(s == "pop"){
			head = pop(head);
			print(head);
		}
		else if(s == "e"){
			exit(0);
		}
	}
}

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
};

// Defining Head
struct Node* head;


// Inserting First into the Linked List
void insertFirst(int num){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = num;
    temp->next = head;
    head = temp;
}

// Traverse The Linked List
void traverseLL(Node* head){
    struct Node* temp = head;

    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Reverse Linked List
Node* reverseLL(Node* head){
    struct Node* previous = nullptr;
    struct Node* current = head;
    struct Node* following = head;

    while(current != nullptr){
        following = following->next;
        current->next = previous;
        previous = current;
        current = following;
    }

    return previous;
}



int main(){
    string s;
    int num;

    head = nullptr;

    while(1){
        cin >> s;

        if(s == "insert"){
            cout << "Enter the number: ";
            cin >> num;
            insertFirst(num);

        }
        else if(s == "print"){
            traverseLL(head);
        }

        else if(s == "reverse"){
            head = reverseLL(head);
        }
        else if(s == "exit"){
            exit(0);
        }
    }
}

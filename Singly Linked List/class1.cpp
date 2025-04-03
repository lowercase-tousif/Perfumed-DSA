#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }   

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

int singly_linked_list(){
    vector<int> arr = {2, 5, 8, 7};
    Node* y = new Node(arr[0]);
    cout << y->data << endl;
}

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traverseLL(Node* head){
    Node* temp = head;

    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lengthOfLL(Node* head){
    Node* temp = head;
    int count = 0;

    while(temp != nullptr){
        temp = temp->next;
        count++;
    }

    return count;
}

int checkIfPresent(Node* head, int value){
    Node* temp = head;
    while(temp){
        if(temp->data == value){
            return 1;
        }
        temp = temp->next;
    }
    
    return -1;
}

int main(){
    // singly_linked_list();

    vector<int> arr = {2, 5, 8, 7};
    Node* head = convertArr2LL(arr);
    // cout << head->data;

    traverseLL(head);

    // Length of LL
    int length = lengthOfLL(head);
    cout << "Length of the Linked List: " << length << endl;

    // Searching an element
    int searchedElement = checkIfPresent(head, 5);

    if(searchedElement == 1){
        cout << "Found" << endl;
    }
    
    else{
        cout << "Not Found" << endl;
    }
 }
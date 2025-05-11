#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
};

// temporary vector
vector<int> v;

// Head here globally defined
struct Node *head;

// insert first function
void insert_first(int num) {
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = num;
  temp->next = head;
  head = temp;
}


// print
void display(Node* head){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;

    while(temp != nullptr){
        cout << temp->data << endl;
        temp = temp->next;
    }
}

// length
void lengthLL(Node* head){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp = head;

    int count = 0;

    while(temp != nullptr){
        count++;
        temp = temp -> next;
    }

    cout << "There are only " << count << " elements in the linked list."<< endl;
}

void convertArrToLL(vector<int>&v){

   if(v.empty()){
    head = nullptr;
    return;
   }

   head->data = v[0];
   head->next = nullptr;

   struct Node* mover = (struct Node*)malloc(sizeof(struct Node));
   mover = head;

   for(int i = 1; i < v.size(); i++){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = v[i];
    temp->next = nullptr;
    mover->next = temp;
    mover = temp;
   }

   display(head);
}

// Reversing a Linked List
Node* reverseLL(Node* head){
  Node* previous = nullptr;
  Node* current = head;
  Node* following = head;

  while(current != nullptr){
    following = following->next;
    current->next = previous;
    previous = current;
    current = following;
  }
  return previous;
}

// sorting a linked list made by own
Node* sort_LL(Node *head){
    struct Node* temp = (struct Node *) malloc(sizeof(struct Node));
    temp = head;

    while(temp != nullptr){
        v.push_back(temp->data);
        temp = temp->next;
    }

    // Sorting algorithm
    for(int i = 0; i < v.size() - 1; i++){
        int min = i;
        for(int j = i + 1; j < v.size(); j++){
            if(v[j] < v[min]){
                min = j;
            }
        }

        if(min != i){
            swap(v[i], v[min]);
        }
    }
    // end of sorting algorithm
    temp = head;

    for(int i = 0; i < v.size(); i ++){
        temp->data = v[i];
        temp = temp->next;
    }
    return head;

}

// Sorting the linked list using bubble sort
void sortLL(Node* head){
   struct Node *i, *j;
    int temp;

    for(i = head; i != NULL; i = i->next){
        for(j = i->next; j != NULL; j = j->next){
            if(i->data > j->data){
                swap(i->data, j->data);
            }
        }
    }
    display(head);
}

// Searching Function
void searchLL(Node *head, int value){
    int flag = 0;
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;

    while(temp != nullptr){
        if(temp->data == value){
            flag = 1;
            break;
        }
        temp = temp->next;
    }

    if(flag){
        cout << "Element Found." << endl;
    }else{
        cout << "Element Not Found." << endl;
    }

}

// Update Function
void updateLL(Node *head, int index, int value){
    int pos = 0;

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;

    while(temp != nullptr){
        if(pos == index){
            temp->data = value;
            cout << "Element found at " << pos << endl;
            cout << "Updated the element" << endl;
        }
        temp = temp->next;
        pos++;
    }

}

// Insert last function
void insert_last(Node *head, int num){
    struct Node *newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = num;
    newnode->next = nullptr;

    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp = head;

    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newnode;
}

int main() {
  head = nullptr;

  string s;
  int num;

  while (1) {
    cin >> s;

    if (s == "i") {
      cout << "Enter a number: ";
      cin >> num;
      insert_first(num);
    }
    else if(s == "il"){
        int num;
        cin >> num;
        insert_last(head, num);
    }
    else if(s == "d"){
        display(head);
    }
    else if(s == "l"){
        lengthLL(head);
    }
    else if(s == "reverse"){
        head = reverseLL(head);
    }
    else if(s == "s"){
        head = sort_LL(head);
    }
    else if(s == "ss"){
        sortLL(head);
    }
    else if(s == "find"){
        int num;
        cout << "Enter the value you want to search:";
        cin >> num;
        searchLL(head, num);
    }
    else if(s == "update"){
        int index, value;
        cout << "Enter the index you wanna change: ";
        cin >> index;
        cout << "Enter the value: ";
        cin >> value;

        updateLL(head, index, value);
    }
    else if (s == "e") {
      exit(0);
    }
  }
}

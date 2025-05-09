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

// insertt first function
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


// sorting a linked list

void sort_LL(Node *head){
    struct Node* temp = (struct Node *) malloc(sizeof(struct Node));
    temp = head;

    while(temp != nullptr){
        v.push_back(temp->data);
        temp = temp->next;
    }

    // printing the size of the vector
    // cout << v.size() << endl;

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

    // converting the array into linked list again
    //TODO: write a function that converts the array into linked list
    convertArrToLL(v);
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
    else if(s == "d"){
        display(head);
    }
    else if(s == "l"){
        lengthLL(head);
    }
    else if(s == "s"){
        sort_LL(head);
    }
    else if (s == "e") {
      exit(0);
    }
  }
}

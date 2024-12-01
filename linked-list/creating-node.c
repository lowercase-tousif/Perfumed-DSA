#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* link;
};

void count_of_nodes(struct Node* head){
    int count = 0;
    if(head == NULL){
        printf("Linked List is empty\n");
    }

    // create a new pointer for traversing the ll
    struct Node* ptr = NULL;
    ptr = head; // without destroying the head created a temporary pointer
    while(ptr != NULL){
        count++;
        ptr = ptr->link;
    }
    printf("%d\n",count);
}

void print_data(struct Node* head){
    if(head == NULL){
        printf("Linked List is empty");
    }
     // create a new pointer for printing the data of the ll
    struct Node* ptr = NULL;
    ptr = head; // without destroying the head created a temporary pointer
    while(ptr != NULL){
        printf("%d\n",ptr->data);
        ptr = ptr->link;
    }
}

void insert_end(struct Node* head, int value){
    // create a new pointer for accessing the data of the ll and creating another temp for storing the link of ll
    struct Node* ptr = NULL, *temp;
    ptr = head; // without destroying the head created a temporary pointer

    // creating a Node
    temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = value;
    temp->link = NULL;

    while(ptr->link != NULL){
        ptr = ptr->link;
    }

    // now assigning the value at the end
    ptr->link = temp;
}

// optimal way of inserting at the end
struct Node* add_at_end(struct Node* ptr, int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->link = NULL;

    ptr->link = temp;
    return temp;
}


int main(){
    struct Node* head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 45;
    head->link = NULL;

    // struct Node* current = (struct Node*)malloc(sizeof(struct Node));
    // current->data = 98;
    // current->link = NULL;
    // head->link = current;

    // current = (struct Node*)malloc(sizeof(struct Node));
    // current->data = 3;
    // current->link = NULL;

    // head->link->link = current; // keep track of the second and the 3rd node
    // print_data(head);
    // count_of_nodes(head);

    // // inserting element at the end
    // insert_end(head,67);

    // printf("\nAfter inserting at the end: \n");
    // print_data(head);


    // Inserting in optimal way
    struct Node* temp = head;
    temp = add_at_end(temp, 20);
    temp = add_at_end(temp, 30);
    temp = add_at_end(temp, 40);

    temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
}
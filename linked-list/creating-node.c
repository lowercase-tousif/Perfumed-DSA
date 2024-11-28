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

int main(){
    struct Node* head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 45;
    head->link = NULL;

    struct Node* current = (struct Node*)malloc(sizeof(struct Node));
    current->data = 98;
    current->link = NULL;
    head->link = current;

    current = (struct Node*)malloc(sizeof(struct Node));
    current->data = 3;
    current->link = NULL;

    head->link->link = current; // keep track of the second and the 3rd node
    print_data(head);
    count_of_nodes(head);
}
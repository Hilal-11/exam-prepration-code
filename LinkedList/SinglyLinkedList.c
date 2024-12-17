#include<stdio.h>
#include<stdlib.h>



typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Insertion on Linked List
// Insertion on Linked List

void insertAtFirst(Node** head , int data){
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void insertAtEnd(Node** head , int data) {
    Node* newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;

}
void insertAtPosition(Node** head , int position , int data) {
    
    if(position == 1) {
        insertAtFirst(head , data);
        return;
    }

    Node* temp = *head;
    int count = 1;
    while(count != position-1) {
        temp = temp -> next;
        count++;
    }

    if(temp->next == NULL){
        insertAtEnd(&temp , data);
    }

    Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;

}

// Delection on Linked List
// Delection on Linked List

void deleteNode(Node** head , int key){
    Node* temp = *head;
    Node* prev = NULL;

    if(temp != NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;

    }


    if(temp == NULL) {
        printf("key %d not found in this list \n", key);
        return;
    }


    prev->next = temp->next;
    free(temp);
    


}

// Traversing on Linked List
// Traversing on Linked List

void displayLinkedList(Node* head){
    if(head == NULL) {
        return;
    }
    Node* temp = head;

    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}
void displayRecursiveForward(Node* head) {

    if(head == NULL) {
        return;
    }

    Node* temp = head;
    if(temp == NULL) {
        return;
    }

    printf("%d \t" , temp->data);
    displayRecursiveForward(temp->next);
}
void displayRecursiveBackward(Node* head) {

    if(head == NULL) {
        return;
    }

    Node* temp = head;
    if(temp == NULL) {
        return;
    }
    displayRecursiveBackward(temp->next);
    printf("%d \t" , temp->data);

}


int main() {

    Node* head = NULL;

    insertAtFirst(&head , 30);
    insertAtFirst(&head , 20);
    insertAtFirst(&head , 10);
    insertAtEnd(&head , 40);
    insertAtEnd(&head , 50);
    insertAtPosition(&head , 3 , 99);

    // deleteNode(&head , 99);

    displayLinkedList(head);

    printf("\n");

    printf("%d \t" , head->data);
    printf("%d \t" , head->next->data);
    printf("%d \t" , head->next->next->data);
    printf("%d \t" , head->next->next->next->data);
    printf("%d \t" , head->next->next->next->next->data);
    printf("%d \t" , head->next->next->next->next->next->data);
    printf("\n");

    displayRecursiveForward(head);
    printf("\n");

    displayRecursiveBackward(head);






    return 0;
}
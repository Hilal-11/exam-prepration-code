#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    return newNode;
}

void insertAtBegin(Node** head , int data) {
    Node* newNode = createNode(data);
    newNode->next = * head;

    if(*head != NULL) {
        (*head)->prev = newNode;
    }
    *head = newNode;

}

void insertAtEnd(Node** head , int data) {
    Node* newNode = createNode(data);

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(Node** head , int key , int data) {
    Node* newNode = createNode(data);
    if(*head == NULL) {
        insertAtBegin(head , data);
        return;

    }
    Node* temp = *head;

    while(temp->next != NULL) {
        temp = temp->next;
    }
    if(temp->next == NULL) {
        insertAtEnd(head , data);
    }

    newNode->next = temp->next;
    newNode->prev = temp->prev;
}

void deleteNode(Node** head , int key) {
    Node* temp = *head;

    while(temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if(temp == NULL) {

        return;
    }

    if(temp == *head) {
        *head = temp->next;

        if(*head != NULL) {
            (*head)->prev = NULL;
        }
    }
    else {
        if(temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        if(temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
    }

    free(temp);

}

void displayForward(Node* head) {
    if(head == NULL) {
        return;
    }
    Node* temp = head;
    while(temp != NULL) {
        printf("%d \t" , temp->data);
        temp = temp->next;
    }
}
void displayBackward(Node* head) {
    if(head == NULL) {
        return;
    }
    Node* temp = head;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    while(temp != NULL) {
        printf("%d \t" , temp->data);
        temp= temp->prev;
    }
}

int main() {

    Node* head = NULL;

    insertAtBegin(&head , 20);
    insertAtEnd(&head , 30);
    insertAtEnd(&head , 40);
    insertAtEnd(&head , 50);
    insertAtEnd(&head , 60);
    insertAtBegin(&head , 10);

    insertAtPosition(&head , 3 , 99);

 

    displayForward(head);

    printf("\n\n");

    displayBackward(head);

    printf("\n\n");


    printf("%d \t" , head->data);
    printf("%d \t" , head->next->data);
    printf("%d \t" , head->next->next->data);
    printf("%d \t" , head->next->next->next->data);
    printf("%d \t" , head->next->next->next->next->data);
    printf("%d \t" , head->next->next->next->next->next->data);
    printf("%d \t" , head->next->next->next->next->next->next->data);

    printf("\n\n");

    printf("%d \t" , head->next->next->next->next->next->next->data);
    printf("%d \t" , head->next->next->next->next->next->data);
    printf("%d \t" , head->next->next->next->next->data);
    printf("%d \t" , head->next->next->next->data);
    printf("%d \t" , head->next->next->data);
    printf("%d \t" , head->next->data);
    printf("%d \t" , head->data);

    return 0;
}
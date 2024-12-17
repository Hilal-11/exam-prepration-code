#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* mid;
    struct Node* right;
}Node;

struct Node* createNode(int data) {
    struct Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data= data;
    newNode->left = NULL;
    newNode->mid = NULL;
    newNode->right = NULL;

    return newNode;
}
int main() {

    struct Node* n1 = createNode(10);
    struct Node* n2 = createNode(20);
    struct Node* n3 = createNode(30);
    struct Node* n4 = createNode(40);
    struct Node* n5 = createNode(50);
    struct Node* n6 = createNode(60);
    struct Node* n7 = createNode(70);
    struct Node* n8 = createNode(80);
    struct Node* n9 = createNode(90);

    // connect node vis edges to biuild a tree

    n1->left = n2;
    n1->mid = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    n3->mid = n7;
    n3->right = n8;
    n4->right = n9;



    printf("%d \n" , n1->data);
    printf("%d \t" , n1->left->data);
    printf("%d \t" , n1->mid->data);
    printf("%d \t" , n1->right->data);








    return 0;
}

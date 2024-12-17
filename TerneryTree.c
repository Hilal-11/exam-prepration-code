#include<stdio.h>
#include<conio.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* mid;
};

struct Node* createNode(int d) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->left = NULL;
    newNode->mid = NULL;
    newNode->right = NULL;
    
};

int main() {


    //Inilization of Nodes with Memory allocation

    struct Node* node1 = createNode(10);
    struct Node* node2 = createNode(20);
    struct Node* node3 = createNode(30);
    struct Node* node4 = createNode(40);
    struct Node* node5 = createNode(50);
    struct Node* node6 = createNode(60);
    struct Node* node7 = createNode(70);
    struct Node* node8 = createNode(80);
    struct Node* node9 = createNode(90);
    struct Node* node10 = createNode(100);

    // connect the nodes via edges

    node1->left = node2;
    node1->mid = node3;
    node1->right = node4;
    node2->left = node5;
    node2->mid = node6;
    node2->right = node7;
    node3->right = node8;
    node4->left = node9;
    node4->right = node10;


    printf("%d \t" , node1->data);
    printf("%d \t" , node2->data);
    printf("%d \t" , node3->data);
    printf("%d \t" , node4->data);
    printf("%d \t" , node5->data);
    printf("%d \t" , node6->data);
    printf("%d \t" , node7->data);
    printf("%d \t" , node8->data);
    printf("%d \t" , node9->data);
    printf("%d \t" , node10->data);

    printf("\n\n");


    printf("%d \n" , node1->data);
    printf("%d \t" , node1->left->data);
    printf("%d \t" , node1->mid->data);
    printf("%d \t \n" , node1->right->data);

    printf("%d \t" , node3->right->data);







    return 0;
}
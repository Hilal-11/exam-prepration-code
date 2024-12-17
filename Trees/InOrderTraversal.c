#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;

}Node;

struct Node* createNode(int data) {
    struct Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 1 :- In-order traversal Iterative approach
// 1 :- In-order traversal Iterative approach

void inOrderTraversalItr(struct Node* root){
    struct Node* stack[100];
    int top = -1;
    struct Node* current = root;

    while(current != NULL || top != -1) {
        if(current != NULL) {
            stack[++top] = current;
            current = current->left;
        }else {
            current = stack[top--];
            printf("%d \t" , current->data);
            current = current->right;
        }
    }
}

// 1 :- In-order traversal recursive approach
// 1 :- In-order traversal recursive approach

void inOredrTraversal(Node* root) {
    if(root == NULL) {
        return;
    }
    inOredrTraversal(root->left);
    printf("%d \t" , root->data);
    inOredrTraversal(root->right);
}


int main () {

    struct Node* node1 = createNode(10);
    struct Node* node2 = createNode(20);
    struct Node* node3 = createNode(30);
    struct Node* node4 = createNode(40);
    struct Node* node5 = createNode(50);
    struct Node* node6 = createNode(60);

    // link the different nodes and build a tree
    
    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;

    printf("In-order traversal iterative approach :- ");
    inOrderTraversalItr(node1);
    printf("\n");
    printf("In-order traversal Recursive approach :- ");
    inOredrTraversal(node1);
   


    return 0;
}
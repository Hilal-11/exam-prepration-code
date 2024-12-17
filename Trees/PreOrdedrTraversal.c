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

// 1 :- pre-order traversal Iterative approach
// 1 :- pre-order traversal Iterative approach

void preOrderTraversalItr(struct Node* root){
    if(root == NULL) return;
    struct Node* stack[100]; // static stack
    int top = -1;       // stack pointer
    stack[++top] = root; // push the root node

    while(top != -1) {
        struct Node* current = stack[top--];
        printf("%d \t" , current->data); // visit Node

        // push right child first so left is processed first
        if(current->right != NULL) stack[++top] = current->right;
        if(current->left != NULL) stack[++top] = current->left;
    }
}


// 1 :- pre-order traversal recursive approach
// 1 :- pre-order traversal recursive approach

void preOredrTraversal(Node* root) {
    if(root == NULL) {
        return;
    }
    printf("%d \t" , root->data);
    preOredrTraversal(root->left);
    preOredrTraversal(root->right);
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

    printf("Pre-order traversal iterative approach :- ");
    preOrderTraversalItr(node1);
    printf("\n");
    printf("Pre-order traversal Recursive approach :- ");
    preOredrTraversal(node1);
   


    return 0;
}
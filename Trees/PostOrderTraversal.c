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

// 1 :- post-order traversal Iterative approach
// 1 :- post-order traversal Iterative approach

void postOrderTraversalItr(struct Node* root){
    if(root == NULL) return;
    struct Node* stack1[100] ; // static stack 1
    struct Node* stack2[100]; // static stack 2
    int top1 = -1;   // stack pointer 1
    int top2 = -1;   // stack pointer 2
    stack1[++top1] = root; // push the root node


    while(top1 != -1) {
        struct Node* current = stack1[top1--];
        stack2[++top2] = current;

        if(current->left != NULL) stack1[++top1] = current->left;
        if(current->right != NULL) stack2[++top2] = current->right;
    }

    while(top2 != -1) {
        printf("%d \t" , stack2[top2--]->data);
    }
}


// 1 :- post-order traversal recursive approach
// 1 :- post-order traversal recursive approach

void postOrderTraversal(Node* root) {
    if(root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d \t" , root->data);
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

    printf("Post-order traversal iterative approach :- ");
    postOrderTraversalItr(node1);
    printf("\n");
    printf("Post-order traversal Recursive approach :- ");
    postOrderTraversal(node1);
   


    return 0;
}
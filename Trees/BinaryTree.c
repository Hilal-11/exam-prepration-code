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


    // Tree Traversals 
// pre-order traversal
// in-order traversal
// post-order traversal


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





// 2 :- pre-order traversal
// 2 :- pre-order traversal

void preOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }
    printf("%d \t", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}



// 3 :- post-order traversal
// 3:- post-order traversal

void postOrderTraversal(Node* root) {
    if(root == NULL){
        return;
    }
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

    printf("In-order traversal iterative approach :- ");
    // inOrderTraversalItr(node1);
    printf("\n");
    printf("In-order traversal Recursive approach :- ");
    inOredrTraversal(node1);
    printf("\n");
    preOrderTraversal(node1);
    printf("\n");
    postOrderTraversal(node1);


    // display nodes data
    // printf("%d \t" , node1->data);
    // printf("%d \t" , node2->data);
    // printf("%d \t" , node3->data);
    // printf("%d \t" , node4->data);
    // printf("%d \t" , node5->data);
    // printf("%d \t" , node6->data);




    return 0;
}
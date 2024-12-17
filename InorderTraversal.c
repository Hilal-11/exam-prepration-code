#include<stdio.h>
#include<conio.h>
 
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int d){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
};

void postOrderTraversal(struct Node* root) {
    if(root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d \t" , root->data);
}


int main() {    

    // initilize the node (data and memory allocation)
    struct Node* firstNode = createNode(1);
    struct Node* secondNode = createNode(2);
    struct Node* thirdNode = createNode(3);
    struct Node* forthNode = createNode(4);
    struct Node* fifthNode = createNode(5);
    struct Node* sixthNode = createNode(6);




    // Connect The Node via Edges
    firstNode->left = secondNode;
    firstNode->right = thirdNode;
    secondNode->left = forthNode;
    secondNode->right = fifthNode;
    thirdNode->right = sixthNode;



    // printing the tree nodes with data
    // printf("%d" , firstNode->data);
    postOrderTraversal(firstNode);





    return 0;
}
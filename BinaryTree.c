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





int main() {    

    // initilize the node (data and memory allocation)
    struct Node* firstNode = createNode(10);
    struct Node* secondNode = createNode(20);
    struct Node* thirdNode = createNode(30);
    struct Node* forthNode = createNode(40);


    // Connect The Node via Edges
    forthNode->left = secondNode;
    firstNode->right = thirdNode;
    secondNode->left = forthNode;


    // printing the tree nodes with data
    printf("%d \t" , firstNode->data);
    printf("%d \t" , secondNode->data);
    printf("%d \t" , thirdNode->data);
    printf("%d \t" , forthNode->data);





    return 0;
}
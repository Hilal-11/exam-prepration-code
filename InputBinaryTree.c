#include<stdio.h>
#include<conio.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;

};

struct Node* createNode(int d) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;

};

struct Node* buildTree(struct Node* root , int data) {

    if(root == NULL) {
        return createNode(data);
    }

    if (data < root->data){
        root->left = buildTree(root->left , data);
    }else{
        root->right = buildTree(root->right , data);
    }
    return root;

}


struct Node* inputBinaryTree(root , data) {
    struct Node* root = NULL;
    int n , data;

    printf("Enter the number of nodes in the tree: ");
    scanf("%d", &n);


    printf("Enter value of nodes \n");
    for(int i = 0 ; i < n; i++) {
        scanf("%d" , &data);
        buildTree(root , data);
    }

    return root;
}



int main () {
    struct Node* root = NULL;
    inputBinaryTree(root , 10);



    printf("%d", root->data);
    printf("%d", root->left->data);
    printf("%d", root->right->data);




    return  0;
}
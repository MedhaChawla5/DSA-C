#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* right;
    struct node* left;
};
struct node* create(int item){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left =NULL;
    temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root,int item){
    if(root==NULL){
        return create(item);
    }
    if(item<root->data){
        root->left = insert(root->left,item);
    }
    if(item>root->data){
        root->right = insert(root->right,item);
    }
    return root;
}

void inorder(struct node* root){
    if(root){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

void preorder(struct node* root){
    if(root){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}
int search(struct node* root, int key) {
    if (root == NULL || root->data == key) {
        return (root != NULL);  
    }
    if (key > root->data) {
        return search(root->right, key);
    }
    return search(root->left, key);
}
int main(){
    //creating binary tree
    printf("Enter the value for the root");
    int m;
    scanf("%d",&m);
    struct node* root = create(m);
    while(1){
        printf("Enter a number to add in the tree , press-1 to end ");
        int num;
        scanf("%d",&num);
        if(num==-1)
            break;
        else{
            insert(root,num);
        }
    }
    
    printf("Enter a number to check for it's presence in the tree");
    int key;
    scanf("%d",&key);
   if (search(root, key)) {
        printf("The given key is present.\n");
    } else {
        root = insert(root, key);  // Update the root after insertion
        printf("Not present, successfully inserted.\n");
    }
    printf("Inorder traversal :- ");
    inorder(root);
     printf("Preorder traversal :- ");
    preorder(root);
     printf("Postorder traversal :- ");
    postorder(root);
    
    return 0;
}

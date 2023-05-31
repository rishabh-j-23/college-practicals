#include <stdio.h>
#include <stdlib.h>

typedef struct treenode tree_node;

struct treenode {
    int data;
    tree_node *left;
    tree_node *right;
};

tree_node *create_node(int data) {
    tree_node *newNode = (tree_node*)malloc(sizeof(tree_node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    return newNode;
}

tree_node* insertLeftNode(tree_node *parent, int data){
    tree_node *left = create_node(data);
    parent->left = left;
    return left;
}

tree_node* insertRightNode(tree_node *parent, int data){
    tree_node *right = create_node(data);
    parent->right = right;
    return right;
}

void preorder_traversal(tree_node *root){
    if (root != NULL) {
        printf("%d ", root->data);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void inorder_traversal(tree_node *root){
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

void postorder_traversal(tree_node *root){
    if (root != NULL) {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    tree_node *root = create_node(1);
    tree_node *left = insertLeftNode(root, 2);
    tree_node *right = insertRightNode(root, 3);

    insertLeftNode(left, 4);
    insertRightNode(left, 5);

    insertLeftNode(right, 6);
    insertRightNode(right, 7);

    printf("Preorder traversal: ");
    preorder_traversal(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder_traversal(root);
    printf("\n");

    return 0;
}

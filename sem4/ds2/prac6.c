#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node *left;
    int info;
    struct node *right;
};
struct node *insert(struct node *root, int ikey){
    struct node *tmp, *par, *ptr;
    int found = 0;
    ptr = root;
    par = NULL;
    while (ptr != NULL){

        if (ikey == ptr->info){
            found = 1;
            break;
        }
        par = ptr;
        if (ikey < ptr->info){
            ptr = ptr->left;
        }else{
            ptr = ptr->right;
        }
    }
    if (found)
        printf("\nDuplicate key");
    else{
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = ikey;
        tmp->left = NULL;
        tmp->right = NULL;
        if (par == NULL){
            root = tmp;
        }
        else if (ikey < par->info){
            par->left = tmp;
        }
        else{
            par->right = tmp;
        }
    }
    return root;
} 
struct node *case_a(struct node *root, struct node *par, struct node *ptr){
    if (par == NULL)
        root = NULL;
    else if (ptr == par->left){
        par->left = NULL;
    } else {
        par->right = NULL;
    }
    free(ptr);
    return root;
} /*End of case_a()*/
struct node *case_b(struct node *root, struct node *par, struct node *ptr){
    struct node *child, *s, *p;
    if (ptr->left != NULL) /* node to be deleted has left child */
        child = ptr->left;
    else /* node to be deleted has right child */
        child = ptr->right;
    if (par == NULL)
        root = child;
    else if (ptr == par->left)
        par->left = child;
    else
        par->right = child;
    s = in_succ(ptr);
    p = in_pred(ptr);
    if (ptr->left != NULL) /* if ptr has left subtree */
        p->right = s;
    free(ptr);
    return root;
}
struct node *case_c(struct node *root, struct node *par, struct node *ptr){
    struct node *succ, *parsucc;
    parsucc = ptr;
    succ = ptr->right;
    while (succ->left != NULL){
        parsucc = succ;
        succ = succ->left;
    }
    ptr->info = succ->info;
    root = case_b(root, parsucc, succ);
    return root;
}
struct node *in_succ(struct node *ptr){

    if (ptr->right == NULL)
        return NULL;
    ptr = ptr->right;
    while (ptr->left != NULL)
        ptr = ptr->left;
    return ptr;
}
struct node *in_pred(struct node *ptr){
    if (ptr->left == NULL)
        return NULL;
    ptr = ptr->left;
    while (ptr->right != NULL)
        ptr = ptr->right;
    return ptr;
}
void inorder(struct node *root){
    struct node *ptr;
    if (root == NULL){
        printf("Tree is empty");
        return;
    }
    ptr = root;
    while (ptr != NULL){
        if (ptr->left == NULL){
            printf("%d ", ptr->info);
            ptr = ptr->right;
        } else {
            struct node *pred = ptr->left;
            while (pred->right != NULL && pred->right != ptr)
                pred = pred->right;
            if (pred->right == NULL){
                pred->right = ptr;
                ptr = ptr->left;
            } else {
                pred->right = NULL;
                printf("%d ", ptr->info);
                ptr = ptr->right;
            }
        }
    }
}
int main() {
    int choice, num;
    struct node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 43);
    root = insert(root, 32);
    root = insert(root, 52);
    root = insert(root, 12);
    inorder(root);
    return 0;
}

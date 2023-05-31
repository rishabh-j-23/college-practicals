#include <stdio.h>
#include <malloc.h>
typedef struct node Node;
typedef struct poly Poly;
struct node {
    int coeff;
    int exp;
    Node *next;
};
struct poly {
    Node *firstNode;
    Node *lastNode;
};

Poly *resultPoly; 
void addPolyNode(Poly **poly, int coeff, int exp){
    Poly *p = *poly;
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    if(p->firstNode == NULL){
        newNode->next = NULL;
        p->firstNode = newNode;
        p->lastNode = newNode;
    } else {
        p->lastNode->next = newNode;
        newNode->next = NULL;
        p->lastNode = newNode;
    }
}
void traverse(Poly **poly){
    Poly *p = *poly;
    Node *temp = p->firstNode;

    while(temp != NULL){
        if(temp->next == NULL){
            printf(" %dx^%d ", temp->coeff, temp->exp);  
            break;  
        }
        printf(" %dx^%d + ", temp->coeff, temp->exp);
        temp = temp->next;
    }
    printf("\n");
}
void addPoly(Poly **poly1, Poly **poly2){
    Poly *p1 = *poly1;
    Poly *p2 = *poly2;

    Node *ip1 = p1->firstNode;
    Node *ip2 = p2->firstNode;

    resultPoly = (Poly*)malloc(sizeof(Poly));

    while(ip1 != NULL && ip2 != NULL){
        
        if(ip1->exp == ip2->exp){
            addPolyNode(&resultPoly, ip1->coeff+ip2->coeff, ip1->exp);
            ip1 = ip1->next;
            ip2 = ip2->next;
        }else if(ip1->exp > ip2->exp){
            addPolyNode(&resultPoly, ip1->coeff, ip1->exp);
            ip1 = ip1->next;

        } else {
            addPolyNode(&resultPoly, ip2->coeff, ip2->exp);
            ip2 = ip2->next;
        }
    }

    traverse(&resultPoly);
}
int main() {   
    Poly *poly1 = (Poly*)malloc(sizeof(Poly));
    poly1->firstNode =NULL;
    addPolyNode(&poly1, 3, 2);
    addPolyNode(&poly1, 2, 1);
    addPolyNode(&poly1, 1, 0);
    traverse(&poly1);

    Poly *poly2 = (Poly*)malloc(sizeof(Poly));
    poly2->firstNode =NULL;
    addPolyNode(&poly2, 4, 2);
    addPolyNode(&poly2, 6, 1);
    addPolyNode(&poly2, 5, 0);

    traverse(&poly2);
    printf("Result : ");
    addPoly(&poly1, &poly2);
    return 0;
}
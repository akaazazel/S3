#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(struct Node** poly, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);
    newNode->next = *poly;
    *poly = newNode;
}

struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;
    struct Node **lastPtrRef = &result;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            *lastPtrRef = createNode(poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } 
        else if (poly1->exp < poly2->exp) {
            *lastPtrRef = createNode(poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } 
        else {
            int sumCoeff = poly1->coeff + poly2->coeff;
            if (sumCoeff != 0)
                *lastPtrRef = createNode(sumCoeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
        lastPtrRef = &(*lastPtrRef)->next;
    }

    while (poly1 != NULL) {
        *lastPtrRef = createNode(poly1->coeff, poly1->exp);
        poly1 = poly1->next;
        lastPtrRef = &(*lastPtrRef)->next;
    }
    while (poly2 != NULL) {
        *lastPtrRef = createNode(poly2->coeff, poly2->exp);
        poly2 = poly2->next;
        lastPtrRef = &(*lastPtrRef)->next;
    }
    return result;
}

void displayPolynomial(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    insertTerm(&poly1, 5, 3);
    insertTerm(&poly1, 4, 2);
    insertTerm(&poly1, 2, 1);

    insertTerm(&poly2, 3, 3);
    insertTerm(&poly2, 4, 2);
    insertTerm(&poly2, 1, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    struct Node* result = addPolynomials(poly1, poly2);
    printf("Resultant Polynomial after addition: ");
    displayPolynomial(result);

    return 0;
}
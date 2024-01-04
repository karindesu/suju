#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int coef;
    int exp;
    struct Node *next;
} Node;
typedef struct {
    Node *head;
} Polynomial;
void insertTerm(Polynomial *poly, int coef, int exp) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = poly->head;
    poly->head = newNode;
}
void multiplyPolynomials(Polynomial *poly1, Polynomial *poly2, Polynomial *result) {
    result->head = NULL;

    Node *current1 = poly1->head;
    while (current1 != NULL) {
        Node *current2 = poly2->head;
        while (current2 != NULL) {
            int newCoef = current1->coef * current2->coef;
            int newExp = current1->exp + current2->exp;
            insertTerm(result, newCoef, newExp);

            current2 = current2->next;
        }
        current1 = current1->next;
    }
}
void displayPolynomial(Polynomial *poly) {
    Node *current = poly->head;
    while (current != NULL) {
        printf("%dx^%d ", current->coef, current->exp);
        if (current->next != NULL) {
            printf("+ ");
        }
        current = current->next;
    }
    printf("\n");
}
void freePolynomial(Polynomial *poly) {
    Node *current = poly->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    poly->head = NULL;
}
int main() {
    Polynomial poly1, poly2, result;
    poly1.head = poly2.head = result.head = NULL;

    int n, coef, exp;
    printf("输入第一个多项式的项数: ");
    scanf("%d", &n);
    printf("输入第一个多项式的项 (系数 和 指数):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coef, &exp);
        insertTerm(&poly1, coef, exp);
    }
    printf("输入第二个多项式的项数: ");
    scanf("%d", &n);
    printf("输入第二个多项式的项 (系数 和 指数):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coef, &exp);
        insertTerm(&poly2, coef, exp);
    }
    multiplyPolynomials(&poly1, &poly2, &result);
    printf("结果多项式: ");
    displayPolynomial(&result);
    freePolynomial(&poly1);
    freePolynomial(&poly2);
    freePolynomial(&result);

    return 0;
}

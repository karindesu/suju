#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 100
typedef struct {
    int coef;
    int exp;
} Term;

typedef struct {
    Term terms[MAX_TERMS];
    int numTerms; 
} Polynomial;

void insertTerm(Polynomial *poly, int coef, int exp) {
    if(poly->numTerms >= MAX_TERMS){
        printf("Polynomial overflow\n");
        return;
    }
    poly->terms[poly->numTerms].coef = coef;
    poly->terms[poly->numTerms].exp = exp;
    poly->numTerms++;
}

void multiplyPolynomials(Polynomial *poly1, Polynomial *poly2, Polynomial *result) {
    for (int i = 0; i < poly1->numTerms; ++i) {
        for (int j = 0; j < poly2->numTerms; ++j) {
            int newCoef = poly1->terms[i].coef * poly2->terms[j].coef;
            int newExp = poly1->terms[i].exp + poly2->terms[j].exp;
            insertTerm(result, newCoef, newExp);
        }
    }
}
void displayPolynomial(Polynomial *poly) {
    for (int i = 0; i < poly->numTerms; i++) {
        printf("%dx^%d", poly->terms[i].coef, poly->terms[i].exp);
        if (i < poly->numTerms - 1) {
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    Polynomial poly1 = {0}, poly2 = {0}, result = {0};
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

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Structure for a polynomial term
struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

// Easiest helper function: Creates a node AND appends it to the end of the list
void insertNode(struct Node** head, int coeff, int exp) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coeff = coeff;
    temp->exp = exp;
    temp->next = NULL;

    // If the list is empty, new node becomes head
    if (*head == NULL) {
        *head = temp;
        return;
    }

    // Traverse to the last node
    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = temp;
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* p1, struct Node* p2) {
    struct Node* result = NULL;

    // Traverse both lists until one becomes empty
    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            insertNode(&result, p1->coeff, p1->exp);
            p1 = p1->next;
        } 
        else if (p1->exp < p2->exp) {
            insertNode(&result, p2->coeff, p2->exp);
            p2 = p2->next;
        } 
        else {
            // Exponents are equal, add coefficients
            int sumCoeff = p1->coeff + p2->coeff;
            if (sumCoeff != 0) { // Only insert if they don't cancel out
                insertNode(&result, sumCoeff, p1->exp);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    // Copy remaining terms of polynomial 1, if any
    while (p1 != NULL) {
        insertNode(&result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    // Copy remaining terms of polynomial 2, if any
    while (p2 != NULL) {
        insertNode(&result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

// Function to print the polynomial
void printPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%dx^%d", poly->coeff, poly->exp);
        poly = poly->next;
        if (poly != NULL && poly->coeff >= 0) {
            printf(" + ");
        } else if (poly != NULL) {
            printf(" "); // Handle negative sign spacing gracefully
        }
    }
    printf("\n");
}

int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;
    struct Node* sum = NULL;

    // Creating Poly 1: 5x^3 + 4x^1 + 2x^0
    insertNode(&poly1, 5, 3);
    insertNode(&poly1, 4, 1);
    insertNode(&poly1, 2, 0);

    // Creating Poly 2: 5x^4 + 3x^3 + 8x^2
    insertNode(&poly2, 5, 4);
    insertNode(&poly2, 3, 3);
    insertNode(&poly2, 8, 2);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    // Add the polynomials
    sum = addPolynomials(poly1, poly2);

    printf("Sum Result:   ");
    printPolynomial(sum);

    return 0;
}

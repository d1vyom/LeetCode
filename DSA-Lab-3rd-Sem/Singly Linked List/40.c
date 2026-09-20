#include <stdio.h>
#include <stdlib.h>

// Define the structure for a polynomial term node
struct Node {
    int coeff;          // Coefficient of the term
    int exp;            // Exponent of the term
    struct Node* next;  // Pointer to the next term
};

// Function to create a new term node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial in descending order of exponents
void insertTerm(struct Node** head, int coeff, int exp) {
    // If coefficient is 0, we don't need to add it to the expression
    if (coeff == 0) return;

    struct Node* newNode = createNode(coeff, exp);

    // Case 1: The list is empty or the new term has a higher exponent than the head
    if (*head == NULL || exp > (*head)->exp) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    
    // Case 2: The term with the same exponent already exists, add coefficients
    if (temp->exp == exp) {
        temp->coeff += coeff;
        free(newNode); // Node isn't needed anymore
        return;
    }

    // Traverse the list to find the correct insertion position
    while (temp->next != NULL && temp->next->exp >= exp) {
        temp = temp->next;
    }

    // If an equal exponent term is found during traversal, combine them
    if (temp->exp == exp) {
        temp->coeff += coeff;
        free(newNode);
    } else if (temp->next != NULL && temp->next->exp == exp) {
        temp->next->coeff += coeff;
        free(newNode);
    } else {
        // Otherwise, insert the new node in the sorted sequence
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to display the polynomial in standard mathematical notation
void displayPolynomial(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    struct Node* temp = head;
    int isFirst = 1;

    while (temp != NULL) {
        // Handle signs (+ or -) between terms
        if (temp->coeff > 0 && !isFirst) {
            printf(" + ");
        } else if (temp->coeff < 0) {
            if (isFirst) {
                printf("-");
            } else {
                printf(" - ");
            }
        }

        // Print absolute value of coefficient (unless it's 1 and we have an x term)
        int absCoeff = abs(temp->coeff);
        if (absCoeff != 1 || temp->exp == 0) {
            printf("%d", absCoeff);
        }

        // Print the variable x and its exponent
        if (temp->exp > 0) {
            printf("x");
            if (temp->exp > 1) {
                printf("^%d", temp->exp);
            }
        }

        isFirst = 0;
        temp = temp->next;
    }
    printf("\n");
}

// Function to free dynamic memory allocated for the linked list
void freePolynomial(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Main function to demonstrate creation and representation
int main() {
    struct Node* poly = NULL;

    // Creating the polynomial: 5x^4 - 3x^2 + 7x + 2
    insertTerm(&poly, 5, 4);
    insertTerm(&poly, -3, 2);
    insertTerm(&poly, 2, 0);  // Constant term (x^0)
    insertTerm(&poly, 7, 1);  // Inserted out of order to demonstrate auto-sorting

    // Display the represented polynomial
    printf("Represented Polynomial: ");
    displayPolynomial(poly);

    // Free allocated memory
    freePolynomial(poly);

    return 0;
}

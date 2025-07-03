#include <stdio.h>

// Define logic gates
int XOR(int a, int b) {
    return a ^ b;
}

int NOT(int x) {
    return 1 - x;
}

int AND(int x, int y) {
    return x & y;
}

int OR(int x, int y) {
    return x | y;
}

int main() {
    int a, b;

    printf("For any set of inputs, A and B, the given circuit gives same output Q, except one. Which one is it?\n\n");

    // (A)
    printf("(A)\n");
    printf("A B | A⊕B | B' | (A⊕B)∧B'\n");
    printf("--------------------------\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            int xor = XOR(a, b);
            int b_bar = NOT(b);
            int result = AND(xor, b_bar);
            printf("%d %d |   %d   |  %d  |     %d\n", a, b, xor, b_bar, result);
        }
    }

    // (B)
    printf("\n(B)\n");
    printf("A B | B' | A∧B'\n");
    printf("-----------------------\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            int b_bar = NOT(b);
            int result = AND(a, b_bar);
            printf("%d %d |  %d |   %d\n", a, b, b_bar, result);
        }
    }

    // (C)
    printf("\n(C)\n");
    printf("A B | B' | A∧B' | (A∧B')∧B | A∧B'+(A∧B')∧B\n");
    printf("------------------------------------------------\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            int b_bar = NOT(b);
            int ans = AND(a, b_bar);
            int ans1 = AND(ans, b);
            int result = OR(ans, ans1);
            printf("%d %d |  %d  |   %d   |     %d     |         %d\n", a, b, b_bar, ans, ans1, result);
        }
    }

    // (D)
    printf("\n(D)\n");
    printf("A B | A' | A'+B\n");
    printf("---------------------\n");
    for (a = 0; a <= 1; a++) {
        for (b = 0; b <= 1; b++) {
            int a_bar = NOT(a);
            int result = OR(a_bar, b);
            printf("%d %d |  %d |   %d\n", a, b, a_bar, result);
        }
    }

    return 0;
}


#include <stdio.h>

// Define logic gate functions
int or_gate(int a, int b) {
    return a | b;
}

int nor_gate(int a, int b) {
    return !(a | b);
}

int final_or_gate(int a, int b) {
    return a | b;
}

// Logic circuit evaluation
int logic_circuit(int A, int B, int C) {
    int out1 = or_gate(A, B);      // First OR gate (top)
    int out2 = nor_gate(A, B);     // NOR gate (bottom left)
    int F = final_or_gate(out1, C) & final_or_gate(out2, C);  // Final logic
    return F;
}

int main() {
    int A, B, C;

    printf("A B C => F\n");
    for (A = 0; A <= 1; A++) {
        for (B = 0; B <= 1; B++) {
            for (C = 0; C <= 1; C++) {
                int F = logic_circuit(A, B, C);
                printf("%d %d %d => %d\n", A, B, C, F);
            }
        }
    }

    printf("\nThe correct answer is A=0, B=0, C=1\n");
    return 0;
}


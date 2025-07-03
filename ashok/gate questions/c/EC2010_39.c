#include <stdio.h>

// Logic gate functions
int not_gate(int x) {
    return !x;
}

int and_gate(int x, int y) {
    return x & y;
}

// 4x1 MUX logic based on A, B select lines and C, D inputs
int mux_4x1(int A, int B, int C, int D) {
    int I0 = C;
    int I1 = D;
    int I2 = not_gate(C);
    int I3 = and_gate(not_gate(C), not_gate(D));

    int select = (A << 1) | B;

    int inputs[4] = {I0, I1, I2, I3};

    return inputs[select];
}

int main() {
    int minterms[16];
    int count = 0;

    printf("A B C D => F\n");

    for (int A = 0; A <= 1; A++) {
        for (int B = 0; B <= 1; B++) {
            for (int C = 0; C <= 1; C++) {
                for (int D = 0; D <= 1; D++) {
                    int F = mux_4x1(A, B, C, D);
                    int index = (A << 3) | (B << 2) | (C << 1) | D;
                    printf("%d %d %d %d => %d\n", A, B, C, D, F);
                    if (F == 1) {
                        minterms[count++] = index;
                    }
                }
            }
        }
    }

    // Print minterms
    printf("\nMinterms where F = 1:\nF = Σm(");
    for (int i = 0; i < count; i++) {
        printf("%d", minterms[i]);
        if (i < count - 1) {
            printf(", ");
        }
    }
    printf(")\n");

    return 0;
}


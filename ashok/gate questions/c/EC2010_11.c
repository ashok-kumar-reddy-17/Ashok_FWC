#include <stdio.h>
#include <string.h>

// Logic gate functions
int NOT(int a) {
    return 1 - a;
}

int first(int a, int b) {
    return NOT(a | b);  // NOR
}

int second(int a, int b) {
    return NOT(a & b);  // NAND
}

int third(int a, int b) {
    return a ^ b;       // XOR
}

int fourth(int a, int b) {
    return NOT(a ^ b);  // XNOR
}

int fifth(int a, int b) {
    return a ^ NOT(b);
}

int sixth(int a, int b) {
    return NOT(a) | NOT(b);  // De Morgan of NAND
}

int seventh(int a, int b) {
    return NOT(NOT(a) ^ b);
}

int eighth(int a, int b) {
    return NOT(a) & NOT(b);  // De Morgan of NOR
}

// Gate names
const char* gate_names[8] = {
    "1st", "2nd", "3rd", "4th", "5th", "6th", "7th", "8th"
};

// Function pointer array
int (*gates[8])(int, int) = {
    first, second, third, fourth, fifth, sixth, seventh, eighth
};

// Store truth tables
int truth_tables[8][4];

int main() {
    int a, b;

    printf("Truth Tables for Logic Gates:\n\n");

    // Generate truth tables
    for (int i = 0; i < 8; i++) {
        printf("%s Gate\n", gate_names[i]);
        printf("A B | OUT\n");
        int index = 0;
        for (a = 0; a <= 1; a++) {
            for (b = 0; b <= 1; b++) {
                int out = gates[i](a, b);
                truth_tables[i][index++] = out;
                printf("%d %d |  %d\n", a, b, out);
            }
        }
        printf("\n");
    }

    // Compare truth tables
    printf("Matching Gate Outputs:\n\n");
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 8; j++) {
            int match = 1;
            for (int k = 0; k < 4; k++) {
                if (truth_tables[i][k] != truth_tables[j][k]) {
                    match = 0;
                    break;
                }
            }
            if (match) {
                printf("%s == %s\n", gate_names[i], gate_names[j]);
            }
        }
    }

    return 0;
}


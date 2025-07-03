#include <stdio.h>

// Logic gate functions
int not_gate(int a) {
    return !a;
}

int and_gate(int a, int b) {
    return a & b;
}

int or_gate(int a, int b) {
    return a | b;
}

// Logic circuit implementation
int logic_circuit(int x, int y) {
    int not_x = not_gate(x);
    int not_y = not_gate(y);
    
    int a = and_gate(not_x, y);
    int b = and_gate(x, not_y);
    
    int z = or_gate(a, b);
    
    return z;
}

// Print truth table
void print_truth_table() {
    int x, y, z;
    printf("X Y | Z\n");
    printf("-------\n");
    for (x = 0; x <= 1; x++) {
        for (y = 0; y <= 1; y++) {
            z = logic_circuit(x, y);
            printf("%d %d | %d\n", x, y, z);
        }
    }
}

int main() {
    printf("Truth Table for the Circuit (Q42):\n");
    print_truth_table();
    return 0;
}


#include <stdio.h>
#include <string.h>

void get_kmap_input(int kmap[8]) {
    int minterm_order[8] = {0, 1, 3, 2, 4, 5, 7, 6};
    int val;

    printf("Enter values for the 2x4 K-map (0 or 1 only):\n");
    printf("Follow this minterm order: m0 m1 m3 m2 m4 m5 m7 m6\n");

    for (int i = 0; i < 8; i++) {
        int idx = minterm_order[i];
        printf("Enter value for m%d: ", idx);
        scanf("%d", &val);
        if (val != 0 && val != 1) {
            printf("Invalid input. Only 0 or 1 allowed.\n");
            i--;  // redo input for this index
        } else {
            kmap[idx] = val;
        }
    }
}

void print_kmap(int kmap[8]) {
    printf("\nK-map (X vs YZ):\n");
    printf("        YZ\n");
    printf("       00  01  11  10\n");
    printf("X=0:   %d   %d   %d   %d\n", kmap[0], kmap[1], kmap[3], kmap[2]);
    printf("X=1:   %d   %d   %d   %d\n", kmap[4], kmap[5], kmap[7], kmap[6]);
}

void get_expression(int kmap[8], char* expression) {
    const char* labels[8] = {
        "X'Y'Z'", "X'Y'Z", "X'YZ'", "X'YZ",
        "XY'Z'", "XY'Z", "XYZ'", "XYZ"
    };

    int first = 1;
    strcpy(expression, "");

    int all_zero = 1, all_one = 1;
    for (int i = 0; i < 8; i++) {
        if (kmap[i] != 0) all_zero = 0;
        if (kmap[i] != 1) all_one = 0;
    }

    if (all_zero) {
        strcpy(expression, "0");
        return;
    }
    if (all_one) {
        strcpy(expression, "1");
        return;
    }

    for (int i = 0; i < 8; i++) {
        if (kmap[i] == 1) {
            if (!first) strcat(expression, " + ");
            strcat(expression, labels[i]);
            first = 0;
        }
    }
}

int main() {
    int kmap[8];
    char expression[256];

    get_kmap_input(kmap);
    print_kmap(kmap);
    get_expression(kmap, expression);

    printf("\nSimplified Boolean Expression (Sum of Minterms):\n");
    printf("F(X, Y, Z) = %s\n", expression);

    return 0;
}


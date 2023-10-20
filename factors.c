#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void factorize_large_number(const char* number_str) {
    unsigned long long n = strtoull(number_str, NULL, 10);

    if (n <= 1) {
        printf("Error: Input number must be greater than 1\n");
        return;
    }

    printf("%llu =", n);

    unsigned long long div = 2;
    int first = 1;

    while (n > 1) {
        if (n % div == 0) {
            if (!first) {
                printf("\n");
            }
            printf(" %llu", div);
            n /= div;
            if (n != 1) {
                printf("*");
                printf(" %llu", n);
            }
            break;
        } else {
            div++;
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open the file\n");
        return 1;
    }

    char line[256];

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0;  // Remove newline character
        factorize_large_number(line);
    }

    fclose(file);
    return 0;
}

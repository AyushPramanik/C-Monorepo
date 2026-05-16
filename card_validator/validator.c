#include <stdio.h>
#include <ctype.h>

int main() {
    char input[32];
    int digits[32];
    int len = 0;

    printf("Enter credit card number without spaces: ");

    if (scanf("%31s", input) != 1) {
        printf("Input Error.\n");
        return 1;
    }

    // Step 1: extract digits strictly
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit((unsigned char)input[i])) {
            printf("Invalid input: non-digit character detected.\n");
            return 1;
        }
        digits[len++] = input[i] - '0';
    }

    // Step 2: Luhn algorithm (RIGHT to LEFT)
    int sum = 0;
    int double_flag = 0;

    for (int i = len - 1; i >= 0; i--) {
        int digit = digits[i];

        if (double_flag) {
            digit *= 2;
            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
        double_flag = !double_flag;
    }

    // Step 3: validation check
    if (sum % 10 == 0) {
        printf("VALID NUMBER\n");
    } else {
        printf("NOT VALID\n");
    }

    return 0;
}
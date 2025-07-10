#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_password(char *password) {
    int len = strlen(password);
    
    // Check length
    if (len < 10 || len > 11) {
        return 0;
    }

    // Check if password starts with a digit
    if (!isdigit(password[0])) {
        return 0;
    }

    // Check if there are 4 alphabets
    int alpha_count = 0;
    for (int i = 0; i < len; i++) {
        if (isalpha(password[i])) {
            alpha_count++;
        }
    }
    if (alpha_count != 4) {
        return 0;
    }

    // Check conditions for alphabets
    for (int i = 1; i < len - 1; i++) {
        if (isalpha(password[i])) {
            if (!islower(password[i - 1]) || !isdigit(password[i + 1])) {
                return 0;
            }
        }
    }

    // Check ending with uppercase alphabet
    if (!isupper(password[len - 1])) {
        return 0;
    }

    // Check no special characters
    for (int i = 0; i < len; i++) {
        if (!isalnum(password[i])) {
            return 0;
        }
    }

    // Check ending digits are odd and 2nd digit is even
    if ((password[len - 1] - '0') % 2 != 1 || (password[1] - '0') % 2 != 0) {
        return 0;
    }

    // Check for duplicate values
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (password[i] == password[j]) {
                return 0;
            }
        }
    }

    // Check for at least 2 vowels
    int vowel_count = 0;
    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 10; j++) {
            if (password[i] == vowels[j]) {
                vowel_count++;
                break;
            }
        }
    }
    if (vowel_count < 2) {
        return 0;
    }

    return 1;
}

int main() {
    char password[20];

    printf("Enter your password: ");
    scanf("%s", password);

    if (is_valid_password(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is not valid.\n");
    }

    return 0;
}


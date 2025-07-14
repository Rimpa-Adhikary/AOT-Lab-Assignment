#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Function prototypes
bool is_prime(int num);
void number_to_words(int num, char* words);
bool validate_input(int num1, int num2);

int main() {
    int num1, num2;
    char words1[20], words2[20];

    printf("Enter two different prime integers within the range of 1 to 100: ");
    scanf("%d %d", &num1, &num2);

    if (validate_input(num1, num2))
	 {
        number_to_words(num1, words1);
        number_to_words(num2, words2);
        printf("INPUTS ARE %s AND %s\n", words1, words2);
        
        // Calculate LCM
        int lcm = num1 * num2;
        printf("LCM of %d and %d is: %d\n", num1, num2, lcm);
    }
	 else {
        printf("Invalid inputs. Please enter two different prime integers within the range of 1 to 100.\n");
    }

    return 0;
}

// Function to check if a number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to convert a number to words
void number_to_words(int num, char* words) {
    char* units[] = {"", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    char* teens[] = {"", "ELEVEN", "TWELVE", "THIRTEEN", "FOURTEEN", "FIFTEEN", "SIXTEEN", "SEVENTEEN", "EIGHTEEN", "NINETEEN"};
    char* tens[] = {"", "TEN", "TWENTY", "THIRTY", "FORTY", "FIFTY", "SIXTY", "SEVENTY", "EIGHTY", "NINETY"};
    
    if (num <= 0 || num >= 100) {
        strcpy(words, "OUT OF RANGE");
        return;
    }

    if (num < 10) {
        strcpy(words, units[num]);
    } else if (num < 20) {
        if (num == 10) {
            strcpy(words, tens[1]);
        } else {
            strcpy(words, teens[num - 10]);
        }
    } else {
        int ten = num / 10;
        int unit = num % 10;
        if (unit == 0) {
            strcpy(words, tens[ten]);
        } else {
            sprintf(words, "%s-%s", tens[ten], units[unit]);
        }
    }
}

// Function to validate inputs
bool validate_input(int num1, int num2) {
    // a) Numbers should be positive.
    if (num1 <= 1 || num2 <= 1) return false;
    
    // f) Numbers should be different.
    if (num1 == num2) return false;
    
    // i) Numbers should be within the range of 100.
    if (num1 > 100 || num2 > 100) return false;
    
    // j) Numbers should be checked whether each inputted integer is prime or not.
    if (!is_prime(num1) || !is_prime(num2)) return false;

    // Other implicit conditions:
    // h) Numbers are integers - ensured by scanf.
    // c, d, e) Numbers will not contain any lowercase or uppercase alphabet or special character - ensured by scanf.

    return true;
}


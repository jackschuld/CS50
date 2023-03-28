#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    long cardNumber = 0;
    char strCardNumber[256];
    int cardNumberLength;

    // CHECK CARD LENGTH
    cardNumber = get_long("Number: ");
    if (cardNumber < 4000000000000) {
        printf("INVALID\n");
    }
    else {
        // Capture cardNumber as a string to easily grab the length
        sprintf(strCardNumber, "%ld", cardNumber);
        // Capture length of strCardNumber into cardNumberLength
        cardNumberLength = strlen(strCardNumber);

        // CHECK CARD ALGORITHM
        // Multiple every other digit, starting with number's second-to-last digit, by 2
        char convertedCardNumber[256] = "";
        for (int i = cardNumberLength-2; i >= 0; i -= 2) {
            // Capture char as an int and multiply by 2
            int x = strCardNumber[i] - '0';
            char tempNumberString[2];
            x *= 2;
            // Capture int back into a char or string and concat to overall string convertedCardNumber
            sprintf(tempNumberString, "%d", x);
            strcat(convertedCardNumber, tempNumberString);
        }

        // Add up each individual digit, NOT the products themselves
        int sum = 0;
        for (int i = 0; i < strlen(convertedCardNumber); i++) {
            int x = convertedCardNumber[i] - '0';
            sum += x;
        }

        // Same as previous, except capture odd digits from end and add to the sum
        for (int i = cardNumberLength-1; i >= 0; i -= 2) {
            int x = strCardNumber[i] - '0';
            sum += x;
        }

        // CHECK CARD COMPANY
        if (sum % 10 == 0) {
            if (strCardNumber[0] == '4' && (strlen(strCardNumber) == 13 || strlen(strCardNumber) == 16)) {
                printf("VISA\n");
            }
            else if (strCardNumber[0] == '3' && (strCardNumber[1] == '4' || strCardNumber[1] == '7') && strlen(strCardNumber) == 15) {
                printf("AMEX\n");
            }
            else if (strCardNumber[0] == '5' && (strCardNumber[1] == '1' || strCardNumber[1] == '2' || strCardNumber[1] == '3' || strCardNumber[1] == '4' || strCardNumber[1] == '5') && strlen(strCardNumber) == 16) {
                printf("MASTERCARD\n");
            }
            else {
                printf("INVALID\n");
            }
        }
        else {
            printf("INVALID\n");
        }
    }
}
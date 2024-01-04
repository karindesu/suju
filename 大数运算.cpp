#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_DIGITS 1000
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}
void subtractBigNumbers(char *num1, char *num2, char *result) {
    int len1 = strlen(num1), len2 = strlen(num2);
    int carry = 0;
    reverseString(num1);
    reverseString(num2);
    for (int i = 0; i < len1; i++) {
        int sub = ((num1[i] - '0') - (i < len2 ? (num2[i] - '0') : 0) - carry);
        if (sub < 0) {
            sub = sub + 10;
            carry = 1;
        } else {
            carry = 0;
        }
        result[i] = sub + '0';
    }
    for (int i = len1 - 1; i >= 0; i--) {
        if (result[i] == '0') {
            result[i] = '\0';
        } else {
            break;
        }
    }
    reverseString(result);
    reverseString(num1);
    reverseString(num2);

    if (!result[0]) {
        strcpy(result, "0");
    }
}
void multiplyBigNumbers(char *num1, char *num2, char *result) {
    int len1 = strlen(num1), len2 = strlen(num2);

    if (len1 == 0 || len2 == 0) {
        strcpy(result, "0");
        return;
    }
    int *resultArray = (int *)calloc(len1 + len2, sizeof(int));
    reverseString(num1);
    reverseString(num2);
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            resultArray[i + j] += (num1[i] - '0') * (num2[j] - '0');
            resultArray[i + j + 1] += resultArray[i + j] / 10;
            resultArray[i + j] %= 10;
        }
    }
    int indexResult = len1 + len2 - 1;
    while (indexResult >= 0 && resultArray[indexResult] == 0) indexResult--;
    if (indexResult == -1) {
        strcpy(result, "0");
    } else {
        int i = 0;
        while (indexResult >= 0) {
            result[i++] = (resultArray[indexResult--] + '0');
        }
        result[i] = '\0';
    }
    free(resultArray);
    reverseString(num1);
    reverseString(num2);
}
void addBigNumbers(char *number1, char *number2, char *result) {
    int len1 = strlen(number1), len2 = strlen(number2);
    int maxLen = len1 > len2 ? len1 : len2;
    int carry = 0;
    int indexResult = 0;
    reverseString(number1);
    reverseString(number2);
    for (int i = 0; i < maxLen; i++) {
        int digit1 = i < len1 ? number1[i] - '0' : 0;
        int digit2 = i < len2 ? number2[i] - '0' : 0;
        int sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result[indexResult++] = (sum % 10) + '0';
    }
    if (carry > 0) {
        result[indexResult++] = carry + '0';
    }
    result[indexResult] = '\0';
    reverseString(result);
}
int main() {
    char num1[MAX_DIGITS];
    char num2[MAX_DIGITS];
    char result[MAX_DIGITS * 2];
    printf("输入第一个数: ");
    scanf("%s", num1);
    printf("输入第二个数: ");
    scanf("%s", num2);
    addBigNumbers(num1, num2, result);
    printf("加法: %s\n", result);
    subtractBigNumbers(num1, num2, result);
    printf("减法: %s\n", result);
    multiplyBigNumbers(num1, num2, result);
    printf("乘法: %s\n", result);
    return 0;
}

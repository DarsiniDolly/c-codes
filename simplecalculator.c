#include <stdio.h>

typedef int (*Operation)(int, int);

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int processInput(int a, int b, char operator, Operation op) {
    return op(a, b);
}

int main() {
    int num1, num2, result;
    char operator;
    char exitKey;

    Operation operation;

    while (1) {
        printf("Enter the first number: ");
        scanf("%d", &num1);

        printf("Enter the operator (+, -, *, /): ");
        scanf(" %c", &operator);

        printf("Enter the second number: ");
        scanf("%d", &num2);


        // Assign the appropriate function pointer based on the operator
        switch (operator) {
            case '+':
                operation = add;
                break;
            case '-':
                operation = subtract;
                break;
            case '*':
                operation = multiply;
                break;
            case '/':
                operation = divide;
                break;
            default:
                printf("Invalid operator! Please try again.\n");
                continue;  // Restart the loop if the operator is invalid
        }

        // Perform the operation and display the result
        result = processInput(num1, num2, operator, operation);
        printf("Result: %d\n\n", result);

        printf("Press 'q' to exit or any other key to continue...\n");
        scanf(" %c", &exitKey);
        if (exitKey == 'q')  // Check if 'q' key is pressed
            break;
    }

    return 0;
}

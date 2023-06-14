// Implemented stack using linked list to create a normal calculator //
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
} Stack;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }

    Node* temp = stack->top;
    stack->top = stack->top->next;
    int popped = temp->data;
    free(temp);
    return popped;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }

    return stack->top->data;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int performOperation(int operand1, int operand2, char operator) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            return 0;
    }
}
// applied BODMAS rule//
int getPrecedence(char operator) {
    if (operator == '*' || operator == '/')
        return 2;
    else if (operator == '+' || operator == '-')
        return 1;
    else
        return 0;
}

int calculateExpression(char* expression) {
    Stack* operandStack = createStack();
    Stack* operatorStack = createStack();

    for (int i = 0; expression[i] != '\0'; i++) {
        if (expression[i] == ' ')
            continue;

        if (expression[i] >= '0' && expression[i] <= '9') {
            int operand = 0;
            while (expression[i] >= '0' && expression[i] <= '9') {
                operand = operand * 10 + (expression[i] - '0');
                i++;
            }
            i--;

            push(operandStack, operand);
        }
        else if (expression[i] == '(') {
            push(operatorStack, expression[i]);
        }
        else if (expression[i] == ')') {
            while (!isEmpty(operatorStack) && peek(operatorStack) != '(') {
                int operand2 = pop(operandStack);
                int operand1 = pop(operandStack);
                char operator = pop(operatorStack);
                int result = performOperation(operand1, operand2, operator);
                push(operandStack, result);
            }

            if (!isEmpty(operatorStack) && peek(operatorStack) == '(') {
                pop(operatorStack);
            }
        }
        else if (isOperator(expression[i])) {
            while (!isEmpty(operatorStack) && peek(operatorStack) != '(' && getPrecedence(peek(operatorStack)) >= getPrecedence(expression[i])) {
                int operand2 = pop(operandStack);
                int operand1 = pop(operandStack);
                char operator = pop(operatorStack);
                int result = performOperation(operand1, operand2, operator);
                push(operandStack, result);
            }

            push(operatorStack, expression[i]);
        }
    }

    while (!isEmpty(operatorStack)) {
        int operand2 = pop(operandStack);
        int operand1 = pop(operandStack);
        char operator = pop(operatorStack);
        int result = performOperation(operand1, operand2, operator);
        push(operandStack, result);
    }

    return pop(operandStack);
}

int main() {
    char input[100];
    char ch;
    int index = 0;
// if the user presses q it will exit or else it will process until pressess q//
    printf("Enter expressions (press 'q' to exit):\n");

    while (true) {
        ch = getchar();

        if ( ch == 'q') { //  'q' to exit
            break;
        }
        else if (ch == '\n') { // Enter key
            input[index] = '\0';
            int result = calculateExpression(input);
            printf("Result: %d\n", result);
            index = 0;
            printf("Enter expressions (press'q' to exit):\n");
        }
        else {
            input[index++] = ch;
            printf("%c", ch);
        }
    }

    return 0;
}

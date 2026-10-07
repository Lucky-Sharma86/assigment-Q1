#include <stdio.h>

#define MAX 7

int stack[MAX]; 
int top = -1;

void push() {
    int value;
    if (top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        printf("Enter value: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
    }
}

void pop() {
    if (top == -1) {
        printf("Stack underflow\n");
    } else {
        printf("Popped value: %d\n", stack[top]);
        top--;
    }
}

void peek() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Top element: %d\n", stack[top]);
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("Stack elements (top to bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\n--- Stack Menu ---\n");
        printf("1 for push\n");
        printf("2 for pop\n");
        printf("3 for peek\n");
        printf("4 for display\n");
        printf("5 for exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
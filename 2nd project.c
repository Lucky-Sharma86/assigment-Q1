#include <stdio.h>

#define MAX 5  // Semicolon (;) hata diya gaya hai

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue() {
    // Check Overflow
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow!\n");
        return;
    }
    
    int x;
    printf("Enter value of x: ");
    scanf("%d", &x);

    // First element insertion
    if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    
    queue[rear] = x;
    printf("Inserted: %d\n", x);
}

void dequeue() {
    // Check Underflow
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Dequeued value: %d\n", queue[front]);

    // Single element remaining case
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void frontElement() {
    if (front == -1) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

void display() {
    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Front Element\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                frontElement();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Program ended.\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);

    return 0;
}
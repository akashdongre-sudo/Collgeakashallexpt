#include <stdio.h>

#define MAX 10

char queue[MAX][20];
int front = -1, rear = -1;

void enqueue(char alert[]) {
    if (rear == MAX - 1)
        printf("Queue Overflow!\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        int i = 0;
        while (alert[i] != '\0') {
            queue[rear][i] = alert[i];
            i++;
        }
        queue[rear][i] = '\0';
        printf("%s added to queue.\n", alert);
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("No active alerts.\n");
    else {
        printf("Removed alert: %s\n", queue[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

void display() {
    if (front == -1)
        printf("No active alerts.\n");
    else {
        printf("\nActive Heatwave Alerts:\n");
        for (int i = front; i <= rear; i++)
            printf("%s\n", queue[i]);
    }
}

int main() {
    float temperature;
    int choice;

    do {
        printf("\n1. Enter Temperature\n2. Display Active Alerts\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter temperature in Celsius: ");
                scanf("%f", &temperature);

                if (temperature >= 45) {
                    printf("RED ALERT\n");
                    enqueue("Red Alert");
                }
                else if (temperature >= 43) {
                    printf("ORANGE ALERT\n");
                    enqueue("Orange Alert");
                }
                else if (temperature >= 40) {
                    printf("YELLOW ALERT\n");
                    enqueue("Yellow Alert");
                }
                else {
                    printf("Temperature is below 40 degrees.\n");
                    printf("Removing all active alerts...\n");
                    while (front != -1)
                        dequeue();
                }
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}

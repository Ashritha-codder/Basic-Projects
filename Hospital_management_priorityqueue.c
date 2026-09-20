#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Patient {
    int id;
    char name[50];
    int priority;
};

struct Patient pq[MAX];

int front = -1;
int rear = -1;

/* Function to add a patient */
void addPatient() {
    struct Patient p;
    int i;

    if (rear == MAX - 1) {
        printf("Queue is full!\n");
        return;
    }

    printf("Enter Patient ID: ");
    scanf("%d", &p.id);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", p.name);

    printf("Enter Priority (1 = Emergency, 2 = Normal): ");
    scanf("%d", &p.priority);

    if (p.priority != 1 && p.priority != 2) {
        printf("Invalid priority! Please enter 1 or 2.\n");
        return;
    }

    /* First patient */
    if (front == -1) {
        front = 0;
        rear = 0;
        pq[rear] = p;
        printf("Patient added successfully!\n");
        return;
    }

    /*
       Shift patients to the right until
       the correct priority position is found.
       Priority 1 comes before priority 2.
    */
    for (i = rear; i >= front; i--) {
        if (pq[i].priority > p.priority) {
            pq[i + 1] = pq[i];
        } else {
            break;
        }
    }

    pq[i + 1] = p;
    rear++;

    printf("Patient added successfully!\n");
}

/* Function to treat the patient at the front */
void treatPatient() {
    if (front == -1 || front > rear) {
        printf("No patients in queue.\n");
        return;
    }

    printf(
        "Treating Patient: ID=%d, Name=%s, Priority=%d\n",
        pq[front].id,
        pq[front].name,
        pq[front].priority
    );

    front++;

    /* Reset queue when all patients are treated */
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

/* Function to display all patients */
void displayPatients() {
    int i;

    if (front == -1 || front > rear) {
        printf("No patients in queue.\n");
        return;
    }

    printf("\n--- Patient List ---\n");

    for (i = front; i <= rear; i++) {
        printf(
            "ID: %d | Name: %s | Priority: %d\n",
            pq[i].id,
            pq[i].name,
            pq[i].priority
        );
    }
}

/* Main function */
int main() {
    int choice;

    while (1) {
        printf("\n--- Hospital Management System ---\n");
        printf("1. Add Patient\n");
        printf("2. Treat Patient\n");
        printf("3. Display Patients\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addPatient();
                break;

            case 2:
                treatPatient();
                break;

            case 3:
                displayPatients();
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
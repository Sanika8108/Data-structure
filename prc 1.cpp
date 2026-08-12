#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Employee {
    int id;
    char name[50];
    float salary;
    struct Employee *next;
};

void insertEmployee(struct Employee **head) {
    struct Employee *newNode =
        (struct Employee *)malloc(sizeof(struct Employee));

    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter Employee ID: ");
    scanf("%d", &newNode->id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", newNode->name);

    printf("Enter Employee Salary: ");
    scanf("%f", &newNode->salary);

    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Employee *temp = *head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    printf("Employee inserted successfully.\n");
}


void displayEmployees(struct Employee *head) {
    if (head == NULL) {
        printf("No employee records found.\n");
        return;
    }

    printf("\n--- Employee Records ---\n");

    while (head != NULL) {
        printf("ID: %d\n", head->id);
        printf("Name: %s\n", head->name);
        printf("Salary: %.2f\n", head->salary);
        printf("------------------------\n");

        head = head->next;
    }
}


void deleteEmployee(struct Employee **head, int id) {
    struct Employee *temp = *head;
    struct Employee *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Employee with ID %d not found.\n", id);
        return;
    }

    if (prev == NULL)
        *head = temp->next;
    else
        prev->next = temp->next;

    free(temp);

    printf("Employee deleted successfully.\n");
}


void freeList(struct Employee **head) {
    struct Employee *temp;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    struct Employee *head = NULL;
    int choice, id;

    do {
        printf("\n===== Employee Management =====\n");
        printf("1. Insert Employee\n");
        printf("2. Display Employees\n");
        printf("3. Delete Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertEmployee(&head);
                break;

            case 2:
                displayEmployees(head);
                break;

            case 3:
                printf("Enter Employee ID to delete: ");
                scanf("%d", &id);
                deleteEmployee(&head, id);
                break;

            case 4:
                freeList(&head);
                printf("Program terminated.\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}

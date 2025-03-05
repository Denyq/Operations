#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void insert(int value) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = NULL;
    if (head == NULL) {
        head = ptr;
    } else {
        struct Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = ptr;
    }
}

void traverse(void) {
    struct Node *current = head;
    if (current == NULL) {
        printf("List is empty\n");
    } else {
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void search(int value) {
    struct Node *current = head;
    bool status = false;
    while (current != NULL) {
        if (current->data == value) {
            status = true;
            break;
        }
        current = current->next;
    }
    if (status) {
        printf("Value found\n");
    } else {
        printf("Value has not been found\n");
    }
}

void delete(int value) {
    struct Node *current = head, *prev = NULL;
    if (current != NULL && current->data == value) {
        head = current->next;
        free(current);
        printf("Value deleted\n");
        return;
    }
    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Value not found\n");
        return;
    }
    prev->next = current->next;
    free(current);
    printf("Value deleted\n");
}

int main() {
    int choice, value;
    do {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Traverse\n");
        printf("3. Search\n");
        printf("4. Delete\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                traverse();
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete(value);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

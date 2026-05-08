#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[10];
    int score;
    struct Node* next;
} Node;

Node* head = NULL;

void add(char* name, int score) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* now = head;

    while (now->next != NULL) {
        now = now->next;
    }

    now->next = newNode;
}

void delete(char* name) {
    Node* now = head;
    Node* prev = NULL;

    while (now != NULL) {
        if (strcmp(now->name, name) == 0) {
            if (prev == NULL) {
                head = now->next;
            } else {
                prev->next = now->next;
            }

            free(now);
            return;
        }

        prev = now;
        now = now->next;
    }
}

void print() {
    Node* now = head;

    while (now != NULL) {
        printf("%s %d\n", now->name, now->score);
        now = now->next;
    }
}

void quit() {
    Node* now = head;

    while (now != NULL) {
        Node* temp = now;
        now = now->next;
        free(temp);
    }

    head = NULL;
}

int main() {
    char input[10];

    while (1) {
        scanf("%s", input);

        if (strcmp(input, "add") == 0) {
            char name[10];
            int score;

            scanf("%s %d", name, &score);
            add(name, score);
        }
        else if (strcmp(input, "delete") == 0) {
            char name[10];

            scanf("%s", name);
            delete(name);
        }
        else if (strcmp(input, "print") == 0) {
            print();
        }
        else if (strcmp(input, "quit") == 0) {
            quit();
            break;
        }
    }

    return 0;
}

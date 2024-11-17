#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX (50)

struct NODE {
    char name[NAME_MAX];
    int score;
    struct NODE* link;
};

struct NODE* head;

struct NODE* create_node(char* name, int score) {
    struct NODE* new_node = (struct NODE*)malloc(sizeof(struct NODE));
    strcpy_s(new_node->name, NAME_MAX, name);
    new_node->score = score;
    new_node->link = NULL;

    return new_node;
}

void insert_node_sorted(struct NODE* new_node) {
    struct NODE* cur = head;
    // Find the correct position to insert
    while (cur->link != NULL && cur->link->score >= new_node->score) {
        cur = cur->link;
    }
    new_node->link = cur->link;
    cur->link = new_node;
}

void print_node() {
    struct NODE* cur = head->link;
    printf("--------------------\n");
    while (cur != NULL) {
        printf("%s : %d\n", cur->name, cur->score);
        cur = cur->link;
    }
    printf("--------------------\n");
}

int delete_node(char* name) {
    struct NODE* prev = head;
    struct NODE* cur = head->link;
    while (cur != NULL) {
        if (strcmp(name, cur->name) == 0) {
            prev->link = cur->link;
            free(cur);
            return 1;
        }

        prev = cur;
        cur = cur->link;
    }
    return 0;
}

int main() {
    head = (struct NODE*)malloc(sizeof(struct NODE));
    head->link = NULL;

    int inst;
    int iteration = 1;

    char name[NAME_MAX];
    int score;

    while (iteration) {
        printf("1. �л� ���� �Է�\n");
        printf("2. �л� ����\n");
        printf("3. ���α׷� ����\n");
        printf("��� �Է�: ");
        scanf_s("%d", &inst);

        switch (inst) {
        case 1:
            printf("�л� �̸�: ");
            scanf_s("%s", name, NAME_MAX);
            printf("����: ");
            scanf_s("%d", &score);
            // Create and insert node in sorted order
            insert_node_sorted(create_node(name, score));
            break;
        case 2:
            printf("������ �л��� �̸�: ");
            scanf_s("%s", name, sizeof(name));
            if (delete_node(name)) {
                printf("�л� ���� �Ϸ�\n");
            }
            else {
                printf("�л��� ã�� �� �����ϴ�\n");
            }
            break;
        case 3:
        default:
            iteration = 0;
            break;
        }

        print_node();
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX (50)

typedef enum {
    RANK1 = 1,
    RANK2,
    RANK3,
    RANK4
} Rank;

struct Customer {
    char customerName[NAME_MAX];
    Rank rank;
    int order_amount;
    int point;
    struct Customer* prev;
    struct Customer* next;
};

struct Customer* head;

struct Customer* create_customer(char* name, Rank rank, int order_amount, int point) {
    struct Customer* new_customer = (struct Customer*)malloc(sizeof(struct Customer));
    strcpy_s(new_customer->customerName, NAME_MAX, name);
    new_customer->rank = rank;
    new_customer->order_amount = order_amount;
    new_customer->point = point;
    new_customer->prev = new_customer->next = NULL;

    return new_customer;
}

int compare_priority(struct Customer* ct1, struct Customer* ct2) {
    if (ct1->rank != ct2->rank)
        return ct1->rank - ct2->rank;
    if (ct1->order_amount != ct2->order_amount)
        return ct2->order_amount - ct1->order_amount;
    return ct2->point - ct1->point;
}

void insert_customer(struct Customer* new_customer) {
    if (head == NULL) {
        head = new_customer;
        return;
    }

    struct Customer* cur = head;
    while (cur != NULL && compare_priority(cur, new_customer) < 0) {
        cur = cur->next;
    }

    if (cur == NULL) {
        struct Customer* last = head;
        while (last->next != NULL)
            last = last->next;
        last->next = new_customer;
        new_customer->prev = last;
    }
    else {
        if (cur->prev != NULL)
            cur->prev->next = new_customer;
        new_customer->prev = cur->prev;
        new_customer->next = cur;
        cur->prev = new_customer;

        if (cur == head)
            head = new_customer;
    }
}

void print_customers() {
    struct Customer* cur = head;
    printf("---------- 고객 목록 ----------\n");
    while (cur != NULL) {
        printf("이름: %s, 등급: %d, 주문량: %d, 포인트: %d\n",
            cur->customerName, cur->rank, cur->order_amount, cur->point);
        cur = cur->next;
    }
    printf("------------------------------\n");
}

int delete_customer(char* name) {
    struct Customer* cur = head;
    while (cur != NULL) {
        if (strcmp(cur->customerName, name) == 0) {
            if (cur->prev != NULL)
                cur->prev->next = cur->next;
            if (cur->next != NULL)
                cur->next->prev = cur->prev;
            if (cur == head)
                head = cur->next;
            free(cur);
            return 1;
        }
        cur = cur->next;
    }
    return 0;
}

void update_customer(char* name, Rank rank, int order_amount, int point) {
    struct Customer* cur = head;
    while (cur != NULL) {
        if (strcmp(cur->customerName, name) == 0) {
            cur->rank = rank;
            cur->order_amount = order_amount;
            cur->point = point;
            delete_customer(name);
            insert_customer(create_customer(name, rank, order_amount, point));
            return;
        }
        cur = cur->next;
    }
    printf("고객을 찾을 수 없습니다!\n");
}

int main() {
    head = NULL;

    int choice, rank, order_amount, point;
    char name[NAME_MAX];

    while (1) {
        printf("1. 고객 추가\n");
        printf("2. 고객 삭제\n");
        printf("3. 고객 수정\n");
        printf("4. 전체 고객 출력\n");
        printf("5. 종료\n");
        printf("명령어 입력: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            printf("고객 이름: ");
            scanf_s("%s", name, NAME_MAX);
            printf("등급 (1-4): ");
            scanf_s("%d", &rank);
            printf("주문량: ");
            scanf_s("%d", &order_amount);
            printf("포인트: ");
            scanf_s("%d", &point);
            insert_customer(create_customer(name, (Rank)rank, order_amount, point));
            break;
        case 2:
            printf("삭제할 고객 이름: ");
            scanf_s("%s", name, NAME_MAX);
            if (!delete_customer(name))
                printf("고객을 찾을 수 없습니다!\n");
            break;
        case 3:
            printf("수정할 고객 이름: ");
            scanf_s("%s", name, NAME_MAX);
            printf("새 등급 (1-4): ");
            scanf_s("%d", &rank);
            printf("새 주문량: ");
            scanf_s("%d", &order_amount);
            printf("새 포인트: ");
            scanf_s("%d", &point);
            update_customer(name, (Rank)rank, order_amount, point);
            break;
        case 4:
            print_customers();
            break;
        case 5:
            exit(0);
        default:
            printf("잘못된 입력입니다. 다시 시도해주세요.\n");
        }
    }

    return 0;
}

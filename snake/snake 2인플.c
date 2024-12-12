#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

// ���� ����
int i, j, height = 20, width = 20;
int gameover, score1 = 0, score2 = 0;
int x1, y1, x2, y2, flag1, flag2;
int fruitx, fruity, goldenx, goldeny, bombx, bomby;
int tail1_x[100], tail1_y[100], length1 = 0;
int tail2_x[100], tail2_y[100], length2 = 0;

// �Լ� ����
void setup();
void draw();
void input();
void logic();

void setup() {
    gameover = 0;

    // �÷��̾� 1�� 2�� �ʱ� ��ġ�� �������� ����
    x1 = rand() % (height - 2) + 1;
    y1 = rand() % (width - 2) + 1;

    x2 = rand() % (height - 2) + 1;
    y2 = rand() % (width - 2) + 1;

    // ����, Ȳ�ݻ��, ��ź ��ġ�� �������� ����
    fruitx = rand() % (height - 2) + 1;
    fruity = rand() % (width - 2) + 1;

    goldenx = rand() % (height - 2) + 1;
    goldeny = rand() % (width - 2) + 1;

    bombx = rand() % (height - 2) + 1;
    bomby = rand() % (width - 2) + 1;

    // �ʱ� ���� ����
    length1 = 0;
    length2 = 0;
}

void draw() {
    system("cls");

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // ��� ���
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("#");
            }
            // �÷��̾� 1�� �� ���
            else if (i == x1 && j == y1) {
                printf("1");
            }
            // �÷��̾� 1�� �� ���
            else if (i == x2 && j == y2) {
                printf("2");
            }
            else if (i == fruitx && j == fruity) {
                printf("*"); // ����
            }
            else if (i == goldenx && j == goldeny) {
                printf("$"); // Ȳ�ݻ��
            }
            else if (i == bombx && j == bomby) {
                printf("!"); // ��ź
            }
            else {
                int printed = 0;
                for (int k = 0; k < length1; k++) {
                    if (tail1_x[k] == i && tail1_y[k] == j) {
                        printf("@");
                        printed = 1;
                        break;
                    }
                } //�÷��̾� 1�� �� �������
                for (int k = 0; k < length2; k++) {
                    if (tail2_x[k] == i && tail2_y[k] == j) {
                        printf("@");
                        printed = 1;
                        break;
                    }
                } //�÷��̾� 2�� �� �������
                if (!printed) printf(" ");
                //��ĭ ���
            }
        }
        printf("\n");
    }
    printf("�÷��̾� 1\n");
    printf("�� : W, �Ʒ� : S, �� : A, �� : D\n");
    printf("�÷��̾� 2\n");
    printf("�� : I, �Ʒ� : K, �� : J, �� : L\n");
    // ���� ǥ��
    printf("XŰ ������ ���� ����\n");
    printf("�÷��̾� 1 ����: %d\n", score1);
    printf("�÷��̾� 2 ����: %d\n", score2);
}

void input() {
    if (_kbhit()) {
        switch (getch()) {
            // �÷��̾� 1
        case 'w': flag1 = 4; break;
        case 'a': flag1 = 1; break;
        case 's': flag1 = 2; break;
        case 'd': flag1 = 3; break;
            // �÷��̾� 2
        case 'i': flag2 = 4; break;
        case 'j': flag2 = 1; break;
        case 'k': flag2 = 2; break;
        case 'l': flag2 = 3; break;
            // ���� ����
        case 'x': gameover = 1; break;
        }
    }
}

void logic() {
    Sleep(200);

    // �÷��̾� 1 ���� �̵�
    for (int k = length1; k > 0; k--) {
        tail1_x[k] = tail1_x[k - 1];
        tail1_y[k] = tail1_y[k - 1];
    }
    tail1_x[0] = x1;
    tail1_y[0] = y1;

    // �÷��̾� 2 ���� �̵�
    for (int k = length2; k > 0; k--) {
        tail2_x[k] = tail2_x[k - 1];
        tail2_y[k] = tail2_y[k - 1];
    }
    tail2_x[0] = x2;
    tail2_y[0] = y2;

    // �÷��̾� 1 ���� ������Ʈ
    switch (flag1) {
    case 1: y1--; break;
    case 2: x1++; break;
    case 3: y1++; break;
    case 4: x1--; break;
    }

    // �÷��̾� 2 ���� ������Ʈ
    switch (flag2) {
    case 1: y2--; break;
    case 2: x2++; break;
    case 3: y2++; break;
    case 4: x2--; break;
    }

    //�÷��̾� 1,2�� ���� ����� �� ���� ����
    //�Ӹ��� �Ӹ�
    if (x1 == x2 && y1 == y2) {
        gameover = 1;
    }
    //�Ӹ��� ����
    for (int k = 0; k < length1; k++) {
        if (x2 == tail1_x[k] && y2 == tail1_y[k]) {
            gameover = 1;
        }
    }
    for (int k = 0; k < length2; k++) {
        if (x1 == tail2_x[k] && y1 == tail2_y[k]) {
            gameover = 1;
        }
    }


    // ��� �浹 �� ���� ����
    if (x1 <= 0 || x1 >= height - 1 || y1 <= 0 || y1 >= width - 1 || length1 < 0 ||
        x2 <= 0 || x2 >= height - 1 || y2 <= 0 || y2 >= width - 1 || length2 < 0) {
        gameover = 1;
    }

    // ���� �浹
    if (x1 == fruitx && y1 == fruity) {
        score1 += 10;
        length1++;
        fruitx = rand() % (height - 2) + 1;
        fruity = rand() % (width - 2) + 1;
    }
    if (x2 == fruitx && y2 == fruity) {
        score2 += 10;
        length2++;
        fruitx = rand() % (height - 2) + 1;
        fruity = rand() % (width - 2) + 1;
    }

    // Ȳ�ݻ�� �浹
    if (x1 == goldenx && y1 == goldeny) {
        length1 += 2;
        score1 += 20;
        goldenx = rand() % (height - 2) + 1;
        goldeny = rand() % (width - 2) + 1;
    }
    if (x2 == goldenx && y2 == goldeny) {
        length2 += 2;
        score2 += 20;
        goldenx = rand() % (height - 2) + 1;
        goldeny = rand() % (width - 2) + 1;
    }

    // ��ź �浹
    if (x1 == bombx && y1 == bomby) {
        if (length1 >= 3) {
            length1 -= 3;
            score1 -= 30;
        }
        else //������ ������ �����Ǵ� �������� ���� ��
        {
            gameover = 1;
            score1 -= 30;
        }
        bombx = rand() % (height - 2) + 1;
        bomby = rand() % (width - 2) + 1;
    }
    if (x2 == bombx && y2 == bomby) {
        if (length2 >= 3) {
            length2 -= 3;
            score2 -= 30;
        }
        else //������ ������ �����Ǵ� �������� ���� ��
        {
            gameover = 1;
            score2 -= 30;
        }
        bombx = rand() % (height - 2) + 1;
        bomby = rand() % (width - 2) + 1;
    }
}

void main() {
    //���� �ʱ�ȭ
    srand(time(NULL));
    setup();
    //���� ����
    while (!gameover) {
        draw();
        input();
        logic();
    }
    //���� ���
    printf("\n���� ����!\n");
    printf("�÷��̾� 1 ����: %d\n", score1);
    printf("�÷��̾� 2 ����: %d\n", score2);
    if (score1 > score2) {
        printf("�÷��̾� 1 �¸�!\n");
    }
    else if (score1 < score2) {
        printf("�÷��̾� 2 �¸�!\n");
    }
    else // ������ �Ȱ��� ��
    {
        printf("���º�!\n");
    }
}

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>

// 변수 선언
int i, j, height = 20, width = 20;
int gameover, score1 = 0, score2 = 0;
int x1, y1, x2, y2, flag1, flag2;
int fruitx, fruity, goldenx, goldeny, bombx, bomby;
int tail1_x[100], tail1_y[100], length1 = 0;
int tail2_x[100], tail2_y[100], length2 = 0;

// 함수 선언
void setup();
void draw();
void input();
void logic();

void setup() {
    gameover = 0;

    // 플레이어 1과 2의 초기 위치를 랜덤으로 설정
    x1 = rand() % (height - 2) + 1;
    y1 = rand() % (width - 2) + 1;

    x2 = rand() % (height - 2) + 1;
    y2 = rand() % (width - 2) + 1;

    // 열매, 황금사과, 폭탄 위치를 랜덤으로 설정
    fruitx = rand() % (height - 2) + 1;
    fruity = rand() % (width - 2) + 1;

    goldenx = rand() % (height - 2) + 1;
    goldeny = rand() % (width - 2) + 1;

    bombx = rand() % (height - 2) + 1;
    bomby = rand() % (width - 2) + 1;

    // 초기 길이 설정
    length1 = 0;
    length2 = 0;
}

void draw() {
    system("cls");

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // 경계 출력
            if (i == 0 || i == height - 1 || j == 0 || j == width - 1) {
                printf("#");
            }
            // 플레이어 1의 뱀 출력
            else if (i == x1 && j == y1) {
                printf("1");
            }
            // 플레이어 1의 뱀 출력
            else if (i == x2 && j == y2) {
                printf("2");
            }
            else if (i == fruitx && j == fruity) {
                printf("*"); // 열매
            }
            else if (i == goldenx && j == goldeny) {
                printf("$"); // 황금사과
            }
            else if (i == bombx && j == bomby) {
                printf("!"); // 폭탄
            }
            else {
                int printed = 0;
                for (int k = 0; k < length1; k++) {
                    if (tail1_x[k] == i && tail1_y[k] == j) {
                        printf("@");
                        printed = 1;
                        break;
                    }
                } //플레이어 1의 뱀 꼬리출력
                for (int k = 0; k < length2; k++) {
                    if (tail2_x[k] == i && tail2_y[k] == j) {
                        printf("@");
                        printed = 1;
                        break;
                    }
                } //플레이어 2의 뱀 꼬리출력
                if (!printed) printf(" ");
                //빈칸 출력
            }
        }
        printf("\n");
    }
    printf("플레이어 1\n");
    printf("위 : W, 아래 : S, 왼 : A, 오 : D\n");
    printf("플레이어 2\n");
    printf("위 : I, 아래 : K, 왼 : J, 오 : L\n");
    // 점수 표시
    printf("X키 누르면 게임 종료\n");
    printf("플레이어 1 점수: %d\n", score1);
    printf("플레이어 2 점수: %d\n", score2);
}

void input() {
    if (_kbhit()) {
        switch (getch()) {
            // 플레이어 1
        case 'w': flag1 = 4; break;
        case 'a': flag1 = 1; break;
        case 's': flag1 = 2; break;
        case 'd': flag1 = 3; break;
            // 플레이어 2
        case 'i': flag2 = 4; break;
        case 'j': flag2 = 1; break;
        case 'k': flag2 = 2; break;
        case 'l': flag2 = 3; break;
            // 게임 종료
        case 'x': gameover = 1; break;
        }
    }
}

void logic() {
    Sleep(200);

    // 플레이어 1 꼬리 이동
    for (int k = length1; k > 0; k--) {
        tail1_x[k] = tail1_x[k - 1];
        tail1_y[k] = tail1_y[k - 1];
    }
    tail1_x[0] = x1;
    tail1_y[0] = y1;

    // 플레이어 2 꼬리 이동
    for (int k = length2; k > 0; k--) {
        tail2_x[k] = tail2_x[k - 1];
        tail2_y[k] = tail2_y[k - 1];
    }
    tail2_x[0] = x2;
    tail2_y[0] = y2;

    // 플레이어 1 방향 업데이트
    switch (flag1) {
    case 1: y1--; break;
    case 2: x1++; break;
    case 3: y1++; break;
    case 4: x1--; break;
    }

    // 플레이어 2 방향 업데이트
    switch (flag2) {
    case 1: y2--; break;
    case 2: x2++; break;
    case 3: y2++; break;
    case 4: x2--; break;
    }

    //플레이어 1,2가 서로 닿았을 때 게임 종료
    //머리와 머리
    if (x1 == x2 && y1 == y2) {
        gameover = 1;
    }
    //머리와 꼬리
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


    // 경계 충돌 및 게임 종료
    if (x1 <= 0 || x1 >= height - 1 || y1 <= 0 || y1 >= width - 1 || length1 < 0 ||
        x2 <= 0 || x2 >= height - 1 || y2 <= 0 || y2 >= width - 1 || length2 < 0) {
        gameover = 1;
    }

    // 열매 충돌
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

    // 황금사과 충돌
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

    // 폭탄 충돌
    if (x1 == bombx && y1 == bomby) {
        if (length1 >= 3) {
            length1 -= 3;
            score1 -= 30;
        }
        else //꼬리의 갯수가 차감되는 갯수보다 적을 때
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
        else //꼬리의 갯수가 차감되는 갯수보다 적을 때
        {
            gameover = 1;
            score2 -= 30;
        }
        bombx = rand() % (height - 2) + 1;
        bomby = rand() % (width - 2) + 1;
    }
}

void main() {
    //게임 초기화
    srand(time(NULL));
    setup();
    //게임 실행
    while (!gameover) {
        draw();
        input();
        logic();
    }
    //점수 출력
    printf("\n게임 종료!\n");
    printf("플레이어 1 점수: %d\n", score1);
    printf("플레이어 2 점수: %d\n", score2);
    if (score1 > score2) {
        printf("플레이어 1 승리!\n");
    }
    else if (score1 < score2) {
        printf("플레이어 2 승리!\n");
    }
    else // 점수가 똑같을 때
    {
        printf("무승부!\n");
    }
}

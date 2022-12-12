#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_SIZE  50
#define NUM_SIZE   50
#define GROUP_SIZE 50
#define LAN_SIZE   50

enum clas {
    SW = 1,
    HW,
    COM
};
typedef struct stu {
    char name[NAME_SIZE];
    char number[NUM_SIZE];
    char group[GROUP_SIZE];
    enum clas depart;
}STU;

typedef char element;
typedef struct Qnode {
    element name[NAME_SIZE];
    element number[NUM_SIZE];
    element Lan[LAN_SIZE];
    struct Qnode *link;
} Qnode;
typedef struct {
    Qnode *front, *rear;
} LQueueType;

void menu1(STU library[], int *count);
void menu2(LQueueType *LQ1);
void menu3();

void a_student(int n, int arr[]);
void b_student(int n, int arr[]);

void add(STU library[], int *count);
void search(STU library[], const int *count);
void print(STU library[], const int *count);

LQueueType *createLinkedQueue();
int isEmpty(LQueueType *LQ);
void enQueue(LQueueType *LQ);
element deQueue(LQueueType *LQ);
void printLQ(LQueueType *LQ);

int main() {
    LQueueType *LQ1 = createLinkedQueue();
    STU         stu[50];
    int         count = 0;
    int         choice;
    int         running = 1;
    while(running){
        printf("===================\n");
        printf("  1. 반 관리\n");
        printf("  2. 수강 신청 및 삭제\n");
        printf("  3. 신입생 관리\n");
        printf("  4. 종료\n");
        printf("===================\n");
        scanf("%d", &choice);
        printf("\n\n");
        switch (choice){
            case 1:
                menu1(stu, &count);
                break;
            case 2:
                menu2(LQ1);
                break;
            case 3:
                menu3();
                break;
            case 4:
                running = 0;
                break;
            default:
                printf("올바르지 않은 번호입니다.");
                break;
        }
    }

    return 0;
}

void menu1(STU library[], int *count) {
    int choice;
    while (1) {
        printf("===================\n");
        printf("  1. 데이터 추가\n");
        printf("  2. 데이터 출력\n");
        printf("  3. 반 검색\n");
        printf("  4. 뒤로가기\n");
        printf("===================\n");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                add(library, count);
                break;
            case 2:
                print(library, count );
                break;
            case 3:
                search(library, count);
                break;
            case 4:
                printf("\n\n");
                return;
            default:
                printf("올바르지 않은 번호입니다.");
                break;
        }
    }
}
void menu2(LQueueType *LQ1){
    int choice;
    do {
        printf("======================\n");
        printf(" 1. 수강할 언어 등록\n");
        printf(" 2. 등록한 과목 출력\n");
        printf(" 3. 수강한 언어 취소\n");
        printf(" 4. 뒤로가기\n");
        printf("======================\n");
        printf("원하는 서비스의 번호를 입력하세요 : ");
        scanf("%d",&choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                enQueue(LQ1);
                break;
            case 2:
                printf("등록 중인 과목 목록입니다.\n");
                printLQ(LQ1);
                break;
            case 3:
                deQueue(LQ1);
                break;
            case 4:
                printf("\n\n");
                return;
            default:
                printf("올바르지 않은 번호입니다.");
                break;
        }
    } while (choice != '4');
}
void menu3(){
    int n;
    int arr[100];
    int select;
    int i, tmp = 0;
    printf("신입생 수를 입력하세요 : ");
    scanf("%d",&n);
    printf("신입생 학년번호를 입력해주세요 : \n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("메뉴 (1. 오름차순 정렬, 2. 내림차순 정렬) : ");
    scanf("%d", &select);

    switch (select) {
        case 1:
            a_student(n, arr);
            break;
        case 2:
            b_student(n, arr);
            break;
        default:
            printf("잘못 입력하셨습니다.");
            break;
    }
    printf("결과 : ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n\n\n");
}

void a_student(int n, int arr[]) {
    int i, j, tmp = 0;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (arr[i] > arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

void b_student(int n, int arr[]) {
    int i, j, tmp = 0;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (arr[i] < arr[j]) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}


void add(STU library[], int* count) {
    int type;
    fflush(stdin);
    printf("이름 : ");
    fgets(library[*count].name, NAME_SIZE, stdin);
    printf("반 : ");
    fgets(library[*count].group, GROUP_SIZE, stdin);
    printf("번호 : ");
    fgets(library[*count].number, NUM_SIZE, stdin);
    printf("학과 (1.소프트웨어개발과, 2.임베디드소프트웨어과, 3.공통과정) : ");
    scanf("%d", &type);
    if(type >= SW && type <= COM)
        library[*count].depart = type;
    else
        library[*count].depart = SW;
    (*count)++;
    printf("\n\n");
}


void search(STU library[], const int *count) {
    int i;
    char name[NAME_SIZE];
    fflush(stdin);
    printf("찾고 싶은 이름을 입력하세요 : ");
    fgets(name, NAME_SIZE, stdin);
    for(i=0; i<*count; i++) {
        if(strcmp(name, library[i].name) == 0) {
            printf("해당 학생의 반은 %s반입니다.\n", library[i].group);
            return;
        }
    }
    printf("찾는 신입생이 없습니다.\n\n\n");
}

void print(STU library[], const int *count) {
    int i;
    fflush(stdin);
    for(i=0; i < *count; i++) {
        printf("\n이름 : %s", library[i].name);
        printf("반 : %s", library[i].group);
        printf("번호 : %s", library[i].number);
        if(library[i].depart == 1)
            printf("소프트웨어개발과\n");
        else if(library[i].depart == 2)
            printf("임베디드소프트웨어과\n");
        else
            printf("공통과정\n");
    }
    printf("\n\n");
}
LQueueType *createLinkedQueue() {
    LQueueType *LQ;
    LQ = (LQueueType *)malloc(sizeof(LQueueType));
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}

int isEmpty(LQueueType *LQ) {
    if (LQ->front == NULL) {
        printf("\n등록된 언어가 없습니다.\n");
        return 1;
    }
    else return 0;
}

void enQueue(LQueueType *LQ) {
    Qnode *newNode = (Qnode*)malloc(sizeof(Qnode));
    printf("이름 : ");
    scanf("%s",newNode->name);
    getchar();
    printf("아이디 : ");
    fgets(newNode->number, NUM_SIZE, stdin);
    printf("수강할 언어 : ");
    fgets(newNode->Lan, LAN_SIZE, stdin);
    newNode->link = NULL;
    printf("\n등록 완료\n");
    if (LQ->front == NULL) {
        LQ->front = newNode;
        LQ->rear = newNode;
    }
    else {
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }
    printf("\n\n");
}

element deQueue(LQueueType *LQ) {
    Qnode *old = LQ->front;
    if (isEmpty(LQ)) return 0;
    else {
        LQ->front = LQ->front->link;
        if (LQ->front == NULL)
            LQ->rear = NULL;
        printf("\n%s 신입생의 수강이 취소되었습니다.\n\n\n", old->name);
        free(old);
        return 1;
    }
}

void printLQ(LQueueType *LQ) {
    Qnode *temp = LQ->front;
    printf("\n");
    while (temp){
        printf("이름 : %s\n", temp->name);
        printf("등록한 언어 : %s\n", temp->Lan);
        temp = temp->link;
    }
    printf("\n");
}
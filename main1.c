#include <stdio.h>
#include <malloc.h>

typedef char element;
typedef struct Qnode {
    element Name[15];
    element ID[18];
    element Lan[40];
    struct Qnode *link;
} Qnode;

typedef struct {
    Qnode *front, *rear;
} LQueueType;

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
    gets(newNode->Name);
    printf("아이디 : ");
    gets(newNode->ID);
    printf("수강할 언어 : ");
    gets(newNode->Lan);
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
}

element deQueue(LQueueType *LQ) {
    Qnode *old = LQ->front;
    if (isEmpty(LQ)) return 0;
    else {
        LQ->front = LQ->front->link;
        if (LQ->front == NULL)
            LQ->rear = NULL;
        printf("\n%s 신입생의 수강이 취소되었습니다.\n", old->Name);
        free(old);
        return 1;
    }
}

void printLQ(LQueueType *LQ) {
    Qnode *temp = LQ->front;
    while (temp){
        printf("\n이름 : %s\n", temp->Name);
        printf("등록한 언어 : %s\n", temp->Lan);
        temp = temp->link;
    }
}

void main(){
    LQueueType *LQ1 = createLinkedQueue();
    int choice;
    do {
        printf("======================\n");
        printf(" 1. 수강할 언어 등록\n");
        printf(" 2. 등록한 과목 출력\n");
        printf(" 3. 수강한 언어 취소\n");
        printf(" 4. 종료\n");
        printf("======================\n");
        printf("원하는 서비스의 번호를 입력하세요 : ");
        choice = getchar();
        fflush(stdin);
        switch (choice) {
        case '1':
            enQueue(LQ1);
            break;
        case '2':
            printf("등록 중인 과목 목록입니다.\n");
            printLQ(LQ1);
            break;
        case '3':
            deQueue(LQ1);
            break;
        case '4':
            break;
        default:
            printf("올바르지 않은 번호입니다.");
        }
    } while (choice != '4');
}
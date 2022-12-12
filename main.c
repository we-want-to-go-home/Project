#include <stdio.h>
#include <string.h>
#define NAME_SIZE 50
#define NUM_SIZE 50
#define GROUP_SIZE 50

enum clas
{
   SW,
   HW,
   COM
};

typedef struct stu
{
   char name[NAME_SIZE];
   char number[NUM_SIZE];
   char group[GROUP_SIZE];
   enum clas depart;
} STU;

void add(STU library[], int count);
void menu();
int input();
void search(STU library[], int count);
void print(STU library[], int count);

int main()
{
   int num, count = 0;
   STU library[30] = {'\0'};
   while (1)
   {
      menu();
      num = input();
      switch (num)
      {
      case 1:
         add(library, count);
         count++;
         continue;

      case 2:
         print(library, count);
         continue;

      case 3:
         search(library, count);
         continue;

      case 4:
         return -1;
      }
      return 0;
   }
}

void add(STU library[], int count)
{
   int type;
   fflush(stdin);
   printf("이름 : ");
   gets(library[count].name);
   printf("반 : ");
   gets(library[count].group);
   printf("번호 : ");
   gets(library[count].number);
   printf("학과 (1.소프트웨어개발과, 2.임베디드소프트웨어과, 3.공통과정) : ");
   scanf("%d", &type);
   if (type >= SW && type <= COM)
      library[count].depart = type;
   else
      library[count].depart = SW;
}

void menu()
{
   printf("===================\n");
   printf("  1. 데이터 추가\n");
   printf("  2. 데이터 출력\n");
   printf("  3. 반 검색\n");
   printf("  4. 종료\n");
   printf("===================\n");
}

int input()
{
   int num;
   printf("원하는 서비스의 번호를 입력하세요 : ");
   scanf("%d", &num);
   printf("\n");
   if (num >= 5)
      printf("올바르지 않은 번호입니다.");
   return num;
}

void search(STU library[], int count)
{
   int i;
   char name[NAME_SIZE];
   fflush(stdin);
   printf("찾고 싶은 이름을 입력하세요 : ");
   gets(name);
   for (i = 0; i < count; i++)
   {
      if (strcmp(name, library[i].name) == 0)
      {
         printf("해당 학생의 반은 %s반입니다.\n", library[i].group);
         return;
      }
   }
   printf("찾는 신입생이 없습니다.\n");
}

void print(STU library[], int count)
{
   int i;
   fflush(stdin);
   for (i = 0; i < count; i++)
   {
      printf("이름 : %s\n", library[i].name);
      printf("반 : %s\n", library[i].group);
      printf("번호 : %s\n", library[i].number);
      if (library[i].depart == 1)
         printf("소프트웨어개발과\n");
      else if (library[i].depart == 2)
         printf("임베디드소프트웨어과\n");
      else
         printf("공통과정\n");
      printf("\n");
   }
}
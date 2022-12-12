#include <stdio.h>

int n;

void a_student(int arr[])
{
   int i, j, tmp = 0;
   for (i = 0; i < n; i++)
   {
      for (j = i; j < n; j++)
      {
         if (arr[i] > arr[j])
         {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
         }
      }
   }
}

void b_student(int arr[])
{
   int i, j, tmp = 0;
   for (i = 0; i < n; i++)
   {
      for (j = i; j < n; j++)
      {
         if (arr[i] < arr[j])
         {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
         }
      }
   }
}

int main()
{
   int arr[100];
   int select;
   int i, tmp = 0;
   printf("신입생 수를 알려주세요!: ");
   scanf("%d", &n);
   printf("신입생 번호를 입력해주세요! : ");
   for (i = 0; i < n; i++)
      scanf("%d", &arr[i]);
   printf("메뉴: 1 - 오름차순 정렬, 2 - 내림차순 정렬 \n");
   printf("선택 : ");
   scanf("%d", &select);

   switch (select)
   {
   case 1:
      a_student(arr);
      break;
   case 2:
      b_student(arr);
      break;
   default:
      printf("잘못 입력하셨습니다.");
      break;
   }
   printf("결과 : ");
   for (i = 0; i < n; i++)
      printf("%d ", arr[i]);
   printf("\n");
}
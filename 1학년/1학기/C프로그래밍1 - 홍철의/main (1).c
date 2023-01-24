
#include <stdio.h>

int main(void)
{
	//1번
	int x1,y1,x2,y2, area;

	printf("1. 좌상단의 (x,y) 좌표 : ");

	scanf("%d %d",&x1,&y1);

	printf("2. 우하단의 (x,y) 좌표 : ");

	scanf("%d %d",&x2,&y2);

	area = (x2-x1)*(y2-y1);

	printf("넓이 : %d\n", area);
  printf("\n");

/*
1. 좌상단의 (x,y) 좌표 : 2 4
2. 우하단의 (x,y) 좌표 : 4 8
넓이 : 8
*/
	//2번
  char ch, up;  
	printf("문자 입력 : ");

	scanf("%s", &ch);

	if ('a' <= ch && ch <= 'z')

	{
		up = ch - 32;
		printf("대문자 변환 : %c\n", up);

	}else if ('A' <= ch && ch <= 'Z')
	{
		printf("대문자 변환 : %c\n", ch);
	}

	printf("\n");

/*
문자 입력 : b
대문자 변환 : B
*/

	//3번
	int num,num1,num2,num3;

	printf("세자리 양의 정수 입력 : ");

	scanf("%d",&num);

	num1 = num/100;

	num2 = (num%100)/10;

	num3 = (num%10);

	printf("일의 자리 : %d\n",num3);

	printf("십의 자리 : %d\n",num2);

	printf("백의 자리 : %d\n",num1);

  /*
세자리 양의 정수 입력 : 357
일의 자리: 7
십의 자리: 5
백의 자리: 3
  */

	return 0;
}

/*실제 출력 결과

*/
/*예시 출력 결과
좌상단의 (x,y) 좌표: 2 4
우하단의 (x,y) 좌표: 4 8
넓이 : 8

문자 입력 : b
대문자 변환 : B

세자리 양의 정수 입력 : 357
일의 자리: 7
십의 자리: 5
백의 자리: 3
계속하려면 아무 키나 누르십시오 . . .
*/

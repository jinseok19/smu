#include <stdio.h>

 

int main()

{

	#1

	
  
	int x1,y1,x2,y2, area;

	

	printf("1. 좌상단의 (x,y) 좌표 : ");

	scanf("%d %d",&x1,&y1);

	printf("2. 우하단의 (x,y) 좌표 : ");

	scanf("%d %d",&x2,&y2);

	

	area = (x2-x1)*(y2-y1);

	printf("널이 : %d\n", area);
  printf("\n");
	

	#2
  char ch, up;  
	printf("문자를 입력하세요 : ");

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

	

	#3

	

	int num,num1,num2,num3;

	printf("세자리 양의 정수 입력 : ");

	scanf("%d",&num);

	

	num1 = num/100;

	num2 = (num%100)/10;

	num3 = (num%10);

	

	printf("일의 자리 : %d\n",num3);

	printf("십의 자리 : %d\n",num2);

	printf("백의 자리 : %d\n",num1);

	

 

	return 0;

}
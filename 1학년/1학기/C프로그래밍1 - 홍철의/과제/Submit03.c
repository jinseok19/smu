#include <stdio.h>

 

int main()

{

	#1

	
  
	int x1,y1,x2,y2, area;

	

	printf("1. �»���� (x,y) ��ǥ : ");

	scanf("%d %d",&x1,&y1);

	printf("2. ���ϴ��� (x,y) ��ǥ : ");

	scanf("%d %d",&x2,&y2);

	

	area = (x2-x1)*(y2-y1);

	printf("���� : %d\n", area);
  printf("\n");
	

	#2
  char ch, up;  
	printf("���ڸ� �Է��ϼ��� : ");

	scanf("%s", &ch);

	if ('a' <= ch && ch <= 'z')

	{
		up = ch - 32;
		printf("�빮�� ��ȯ : %c\n", up);

	}else if ('A' <= ch && ch <= 'Z')
	{
		printf("�빮�� ��ȯ : %c\n", ch);
	}

	printf("\n");

	

	#3

	

	int num,num1,num2,num3;

	printf("���ڸ� ���� ���� �Է� : ");

	scanf("%d",&num);

	

	num1 = num/100;

	num2 = (num%100)/10;

	num3 = (num%10);

	

	printf("���� �ڸ� : %d\n",num3);

	printf("���� �ڸ� : %d\n",num2);

	printf("���� �ڸ� : %d\n",num1);

	

 

	return 0;

}
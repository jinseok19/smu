#include <stdio.h>
#include <stdlib.h>

void get_2int(int* a, int* b)
{
	//�Ʒ��� �ϼ��Ͻÿ�.
	
}
int add1(int a, int b)
{
	//�Ʒ��� �ϼ��Ͻÿ�.
	
}
void add2(int *sum, int a, int b) 
{
	//�Ʒ��� �ϼ��Ͻÿ�.
	
}
double func(int* a, int* b)
{
	double avg = (*a + *b) / 2.0; //1��
	int tmp;
	//�Ʒ��� �ϼ��Ͻÿ�.
	
}
int main(void)
{
	//1��
	int a, b, sum;

	get_2int(&a, &b);
	add2(&sum, a, b);
	printf("��: %d-%d\n", add1(a, b), sum);

	//2��
	double avg = func(&a, &b);
	printf("��:%d, ��: %d, ���:%.2f\n", a, b, avg);

	return 0;
}


/*���� ��°��

*/
/*���� ��°��
2���� ������ �Է��Ͻÿ�.: 15 20
��: 35-35
��:35, ��: 5, ���:17.50
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/

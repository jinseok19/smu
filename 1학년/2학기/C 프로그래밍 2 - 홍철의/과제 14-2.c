
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

char* get_aop(char* a[], int t_num, int c_num, char *p)
{
	*p = *(*(a + t_num - 1) + c_num);
	return a[t_num - 1];
}
char* get_poa(char(*a)[80], int t_num, int c_num, char* p)
{
	*p = *(*(a + t_num - 1) + c_num);
	return a[t_num - 1];
}

int add(int op1, int op2)
{
	return op1 + op2;
}
int subtract(int op1, int op2)
{
	return op1 - op2;
}
int main(void)
{
	char *traffics_aop[] = { "car", "train", "ship", "airplane" };
	char traffics_poa[][80] = { "car", "train", "ship", "airplane" };
	int traffic_num, char_num, size= 4;
	char ch;

	for (int i = 0; i < size; i++)
		printf("%d. %s\n", i + 1, traffics_aop[i]);
	printf("������ܹ�ȣ : ");
	scanf("%d", &traffic_num);
	printf("���� �ε���: ");
	scanf("%d", &char_num);

	//�Ʒ��� �ϼ��Ͻÿ�. get_aop()�� ȣ���Ͻÿ�.


	//�Ʒ��� �ϼ��Ͻÿ�. get_poa()�� ȣ���Ͻÿ�.



	int op1, op2;
	char str[80];
	printf("���� ����: ");
	scanf("%s", str);
	sscanf(str, "%d%c%d", &op1, &ch, &op2);

	//�Ʒ��� �ϼ��Ͻÿ�. �Լ� ������ pf()�� �����ϰ� ȣ���Ͻÿ�.



	return 0;
}

/*���� ��°��

*/
/*���� ��°��
1. car
2. train
3. ship
4. airplane
������ܹ�ȣ : 4
���� �ε���: 3
�������: airplane, ����: p
�������: airplane, ����: p
���� ����: 5-2
5-2= 3
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/

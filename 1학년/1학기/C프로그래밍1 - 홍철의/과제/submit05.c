#include <stdio.h>



int main(void) {
	
	//1��
	int a, b, c, max, min;
	max = 0;
	min = 100;
	printf("3���� ������ �Է��Ͻÿ�: ");
	scanf("%d %d %d", &a, &b, &c);

	if (a > b && a>c) {
	max = a;
	}
	else if (b > a && b > c) {
	max = b;
	}
	else {
	max = c;
	}

	if (a < b && a < c) {
	min = a;
	}
	else if (b < a && b < c) {
	min = b;
	}
	else {
	min = c;
	}
	printf("�ִ밪: %d, �ּҰ�: %d\n", max, min);

	printf("\n");
	
	//2
	unsigned char num1 = 3;

	num1 = num1 << 3;
	num1 = num1 >> 2;
	printf("3*8/4= %u\n", num1);

	printf("\n");
	
	
	//3
	int k;
	printf("���� �Է�: ");
	scanf("%d", &k);

	k = ~k;
	k++;
	printf("��ȣ�� �ٲ� ���: %d\n", k);

	return 0;

}
/*���� ��� ���
3���� ������ �Է��Ͻÿ�: 12 33 54
�ִ밪: 54, �ּҰ�: 12

3*8/4= 6

���� �Է�: 5
��ȣ�� �ٲ� ���: -5
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/

/*���� ��� ���
3���� ������ �Է��Ͻÿ�: 12 33 54
�ִ밪: 54, �ּҰ�: 12

3*8/4= 6

���� �Է�: 5
��ȣ�� �ٲ� ���: -5
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
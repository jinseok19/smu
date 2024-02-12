
#include <stdio.h>
#include <stdlib.h>

//1�� �Լ� ����
int get_gcd(int n1, int n2)
{
	int i;
	for (i = n1 >= n2 ? n2 : n1; i > 1; i--)
	{//�Ʒ��� �ϼ��Ͻÿ�
		if (n1 % i == 0 && n2 % i == 0) {
			return i;
		}

	}
	return 1;
}
//2�� �Լ� ����
int get_n(int n)
{
	int k = 0, result = 1;
	//�Ʒ��� �ϼ��Ͻÿ�
	while (result <= n) {
		result = 2 << k;
		k++;
	}
	return k-1;
}
//3�� �Լ� ����
const int BREAD = 500;
const int SNACK = 700;
const int DRINK = 400;

void get_cases(int money)
{
	int i, j, k;

	for (i = 1; i < money / BREAD; i++)
	{//�Ʒ��� �ϼ��Ͻÿ�
		for (j = 1; j < money / SNACK; j++) {

			for (k = 1; k < money / DRINK; k++) {
				if (BREAD * i + SNACK * j + DRINK * k == money) {
					printf("ũ���� %d��, ����� %d��, ��  �� %d��\n", i, j, k);

				}

			}

		}


	}
	
}

int main(void)
{
	//1
	int n1, n2;

	printf("�� ���� ���� �Է� : ");
	scanf_s("%d %d", &n1, &n2);
	printf("�� ���� �ִ����� : %d\n\n", get_gcd(n1, n2));

	//2��
	int n;

	printf("��� n �Է�: ");
	scanf_s("%d", &n);
	printf("������ �����ϴ� k�� �ִ��� %d\n\n", get_n(n));

	//3��
	int money = 3500;

	printf("���� �����ϰ� �ִ� �ݾ�: %d\n", money);
	get_cases(money);

	return 0;
}

/*���� ��� ���
�� ���� ���� �Է� : 6 9
�� ���� �ִ����� : 3

��� n �Է�: 256
������ �����ϴ� k�� �ִ��� 8

���� �����ϰ� �ִ� �ݾ�: 3500
ũ���� 1��, ����� 2��, ��  �� 4��
ũ���� 2��, ����� 3��, ��  �� 1��
ũ���� 4��, ����� 1��, ��  �� 2��

C:\Users\rlawl\OneDrive\���� ȭ��\C code\Project1\x64\Debug\Project1.exe(���μ��� 25960��)��(��) ����Ǿ����ϴ�(�ڵ�: 0 ��).
�� â�� �������� �ƹ� Ű�� ��������...
*/
/*���� ��� ���
�� ���� ���� �Է� : 6 9
�� ���� �ִ����� : 3

��� n �Է�: 256
������ �����ϴ� k�� �ִ��� 8

���� �����ϰ� �ִ� �ݾ�: 3500
ũ���� 1��, ����� 2��, ��  �� 4��
ũ���� 2��, ����� 3��, ��  �� 1��
ũ���� 4��, ����� 1��, ��  �� 2��
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/

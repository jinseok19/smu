
#include <stdio.h>
#include <stdlib.h>

int iterative(int n1, int n2)
{
	//�Ʒ��� �ϼ��Ͻÿ�
	int result = 1;
	for (int i = 0; i < n2; i++)
	{
		result *= n1;
	}

	return result;
}
int recursive(int n1, int n2)
{
	//�Ʒ��� �ϼ��Ͻÿ�
	if (n2 == 0) return 1;

	else if ((n2 % 2) == 0) return  recursive(n1 * n1, n2 / 2);

	else return n1 * recursive(n1 * n1, (n2 - 1) / 2);
}

//�Ʒ��� �ϼ��Ͻÿ�, ���� ������ �ܺο��� �Լ� ����
int op;
extern int add();


int main(void)
{
	//1, 2��
	int n;

	printf("2�� �¼� �Է�: ");
	scanf_s("%d", &n);
	printf("�ݺ�: 2�� %d���� %d\n", n, iterative(2, n));
	printf("��ȯ: 2�� %d���� %d\n", n, recursive(2, n));

	//3��
	for (int i = 0; i < 3; i++)
	{
		printf("���� �Է�: ");
		scanf_s("%d", &op);
		printf("��: %d\n", add());
	}

	return 0;
}

/*���� ��� ���
2�� �¼� �Է�: 8
�ݺ�: 2�� 8���� 256
��ȯ: 2�� 8���� 256
���� �Է�: 3
��: 3
���� �Է�: 5
��: 8
���� �Է�: 7
��: 15

C:\Users\rlawl\OneDrive\���� ȭ��\C code\Project1\x64\Debug\Project1.exe(���μ��� 9604��)��(��) ����Ǿ����ϴ�(�ڵ�: 0��).
�� â�� �������� �ƹ� Ű�� ��������...
*/
/*���� ��� ���
2�� �¼� �Է�: 8
�ݺ�: 2�� 8���� 256
��ȯ: 2�� 8���� 256
���� �Է�: 3
��: 3
���� �Է�: 5
��: 8
���� �Է�: 7
��: 15
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/

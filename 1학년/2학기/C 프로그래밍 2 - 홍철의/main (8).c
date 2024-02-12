
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 80

void prob_1(char* s, int f[])
{
	//���ο� ������ �������� ���ÿ�.
	//����ó�� ���̺귯���� �̿��Ͻÿ�.
	//�Ʒ��� �ϼ��Ͻÿ�.
	while (*s != '\0') {
		if (isdigit(*s)) {
			f[*s - '0']++;
			s++;
		}
		else
			s++;
		
	};

}
void prob_2(char* s1, char* s2)
{
	//���ο� ������ �������� ���ÿ�.
	//strcat()�� ���� ���ڿ� ó�� ���̺귯���� �̿����� ���ÿ�.
	//�Ʒ��� �ϼ��Ͻÿ�.
	while (*s1 !='\0')
	{
		s1++;
	}
	while (*s2 !='\0')
	{
		*s1 = *s2;
		s2++;
		s1++;
	}
	
}
void prob_3(int d[], int size)
{
	int i;
	//���ο� ������ �������� ���ÿ�.
	//�Ʒ��� �ϼ��Ͻÿ�.
	for (i = 0; i < size; i++) {
		switch (d[i]) {
		case 1:
			printf("��");
			break;
		case 2:
			printf("��");
			break;
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		case 5:
			printf("��");
			break;
		case 6:
			printf("��");
			break;
		case 7:
			printf("ĥ");
			break;
		case 8:
			printf("��");
			break;
		case 9:
			printf("��");
		default:
			continue;

		}
		switch (i) {
		case 0:
			printf("õ");
			break;
		case 1:
			printf("��");
			break;
		case 2:
			printf("��");
			break;
		}
	}
		printf("\n");

}
int main(void)
{
	//1��
	char str[SIZE];
	int freq[10] = { 0 };
	printf("���ڿ��� �Է��Ͻÿ�: ");
	gets_s(str, sizeof(str));

	prob_1(str, freq);
	for (int i = 0; i < 10; i++) {
		if (freq[i])
			printf("(%d,%d)", i, freq[i]);
	}
	printf("\n");

	//2��
	char str1[SIZE] = "C ��� ", * str2 = "����մϴ�.";
	prob_2(str1, str2);
	printf("�� ���ڿ��� ���� ���: %s\n", str1);

	//3��
	int i, j;
	int num;
	int digits[4];
	printf("10000���� ���� ���� ���� �Է�: ");
	scanf_s("%d", &num);
	//������ 4�ڸ��� �迭�� �ٲ�, ���� 504 ->{0, 5, 0, 4}
	for (i = 1000, j = 0; i > 0; i /= 10, j++) {
		digits[j] = num / i;
		num %= i;
	}
	prob_3(digits, 4);

	return 0;
}

/*���� ��°��
���ڿ��� �Է��Ͻÿ�: 125-589
(1,1)(2,1)(5,2)(8,1)(9,1)
�� ���ڿ��� ���� ���: C ��� ����մϴ�.
10000���� ���� ���� ���� �Է�: 504
�����

C:\Users\rlawl\OneDrive\���� ȭ��\C code\Project1\x64\Debug\Project1.exe(���μ��� 16496��)��(��) ����Ǿ����ϴ�(�ڵ�: 0 ��).
�� â�� �������� �ƹ� Ű�� ��������...
*/
/*���� ��°��
���ڿ��� �Է��Ͻÿ�: 125-589
(1,1)(2,1)(5,2)(8,1)(9,1)
�� ���ڿ��� ���� ���: C ��� ����մϴ�.
10000���� ���� ���� ���� �Է�: 504
�����
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/

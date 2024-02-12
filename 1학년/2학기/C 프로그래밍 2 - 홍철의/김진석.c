#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 80

void prob_1(char s1[], char s2[], char s3[], char s4[])
{
	char* seps = " ,\t\n";
	char* token;

	token = strtok(s1, seps);

	//�Ʒ��� �ϼ��Ͻÿ�. ���ο� ������ �������� ���ÿ�.
	s4[0] = '\0';

	while (token != NULL)
	{
		if (strcmp(token, s2) == 0)
			strcat(s4, s3);
		else
			strcat(s4, token);
		token = strtok(NULL, seps);
		strcat(s4, " ");
	};

}

double prob_2(char s1[], char s2[], char s3[])
{
	char* s;
	int sum = 0, cnt = 0;

	//�Ʒ��� �ϼ��Ͻÿ�. ���ο� ������ �������� ���ÿ�.
	while (*s3 != '\0') {
		if (isdigit(*s3)) {

			sum += *s3 - '0';
			cnt++;

		};
		s3++;
	}
	return (double)sum / cnt;
}

int prob_3(char name[][2][20])
{
	int i, age, max_idx, max_age;

	max_idx = 0;
	sscanf(name[0][1], "%d", &max_age);

	//�Ʒ��� �ϼ��Ͻÿ�. ���ο� ������ �������� ���ÿ�.
	for (i = 1; i <3; i++) {
		age = atoi(name[i][1]);

		if (age> max_age) {

			max_idx = i;
			max_age = age;

		}
	}

	return max_idx;
}
int main(void)
{
	//1��
	char str[SIZE];
	char find[SIZE], replace[SIZE], target[SIZE];

	printf("�����ڿ��� �Է��Ͻÿ�: ");
	gets_s(str, sizeof(str));
	printf("ã�� ���ڿ�: ");
	scanf("%s", find);
	printf("�ٲ� ���ڿ�: ");
	scanf("%s", replace);
	prob_1(str, find, replace, target);
	printf("�ٲ� ���ڿ��� %s\n", target);
	getchar();

	//2��
	char str1[20], str2[20], str3[40];
	printf("str1 ���ڿ� �Է�: ");
	gets_s(str1, sizeof(str1));
	printf("str2 ���ڿ� �Է�: ");
	gets_s(str2, sizeof(str2));
	sprintf(str3, "%s, %s", str1, str2);
	printf("str3: %s\n", str3);
	printf("������ ���: %.2f\n", prob_2(str1, str2, str3));

	//3��
	char name[3][2][20];

	for (int i = 0; i < 3; i++) {
		printf("%d. �̸� ����: ", i);
		scanf("%s %s", name[i][0], name[i][1]);
	}
	int idx = prob_3(name);
	printf("�ְ����: %s, %s\n", name[idx][0], name[idx][1]);

	return 0;
}
/*���� ��°��
�����ڿ��� �Է��Ͻÿ�: I love C program
ã�� ���ڿ�: love
�ٲ� ���ڿ�: like
�ٲ� ���ڿ��� I like C program
str1 ���ڿ� �Է�: 1. c 35
str2 ���ڿ� �Է�: 2. c++ 20
str3: 1. c 35, 2. c++ 20
������ ���: 2.17
0. �̸� ����: �̼��� 35
1. �̸� ����: ������ 15
2. �̸� ����: ������ 50
�ְ����: ������, 50
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
/*���� ��°��
�����ڿ��� �Է��Ͻÿ�: I love C program
ã�� ���ڿ�: love
�ٲ� ���ڿ�: like
�ٲ� ���ڿ��� I like C program
str1 ���ڿ� �Է�: 1. c 35
str2 ���ڿ� �Է�: 2. c++ 20
str3: 1. c 35, 2. c++ 20
������ ���: 2.17
0. �̸� ����: �̼��� 35
1. �̸� ����: ������ 15
2. �̸� ����: ������ 50
�ְ����: ������, 50
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/

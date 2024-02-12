
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define SIZE 3
struct student {
	int number;	// �й�
	char name[20];	// �̸�
	double gpa;	// ����
};

void f1(FILE* fp, char* find) {
	int linenumber = 0;
	char line[256];

	printf("�˻��������\n");
	//�Ʒ��� �ϼ��Ͻÿ�. fgets(), fputs(), feof(), strstr()�� ����Ͻÿ�.
	//feof()�� �Ⱦ��� ���α׷� �����մϴ�.
	while (!feof(fp))
	{
		linenumber++;

		fgets(line, sizeof(line), fp);

		// �˻�
		if (strstr(line, find) != NULL)
		{
			fputs("%d:   %s", linenumber, line);
		}
	}
	


}
void f2(FILE* fp) {
	int line_no = 0, word_no = 0;
	char line[256], * token;
	char* delim = " \n\t\r";

	//�Ʒ��� �ϼ��Ͻÿ�. fgets(), feof(), strtok()�� ����Ͻÿ�.
	//feof()�� �Ⱦ��� ���α׷� �����մϴ�.

	while (!feof(fp))
	{
		fgets(line, sizeof(line), fp);

		token = strtok(line, delim);
		while (token)
		{
			word_no++;
			token = strtok(NULL, delim);
		}
		line_no++;
	}

	printf("\n");
	printf("�ܾ� �� : %5d\n", word_no);
	printf("�� ��   : %5d\n", line_no);
	printf("\n");

}
void f3() {
	FILE* fp;
	//�Ʒ��� �ϼ��Ͻÿ�. "#���: �౸" �� �߰��Ͻÿ�.
	if ((fp = fopen("student.txt", "a")) == NULL)
	{
		fprintf(stderr, "�б⸦ ���� ������ �� �� �����ϴ�.\n");
		exit(1);
	}
	fputs("##���: �౸\n", fp);

	fclose(fp);
}

void f4(FILE* fp, int stu_no, double stu_gpa) {
	struct student s;

	printf("������ �л� ���ڵ�\n");
	fseek(fp, 0, SEEK_SET);
	while (fread(&s, sizeof(struct student), 1, fp) == 1) {
		if (s.number == stu_no) {
			//�Ʒ��� �ϼ��Ͻÿ�

			s.gpa = stu_gpa;
			fseek(fp, -(int)sizeof(struct student), SEEK_CUR);
			fwrite(&s, sizeof(struct student), 1, fp);
			break;
		}
	}
}
int main(void)
{
	FILE* fp = NULL;
	char buf[100];

	//1��
	char filename[80], find[80];

	printf("ã�� ���ϸ�: ");
	scanf("%s", filename);
	printf("ã�� ���ڿ�: ");
	scanf("%s", find);

	if ((fp = fopen(filename, "r")) == NULL)
	{
		printf("can't open the file [%s]\n", filename);
		exit(1);
	}

	f1(fp, find);
	rewind(fp);

	//2��
	f2(fp);
	fclose(fp);

	//3��
	if ((fp = fopen("student.txt", "wt")) == NULL)
	{
		fprintf(stderr, "����� ���� ������ �� �� �����ϴ�.\n");
		exit(1);
	}
	fputs("#�̸�: ȫ�浿\n", fp);
	fclose(fp);

	f3();

	//student.txt �� �޸������� ���� ������ �Ʒ��� ������ Ȯ���� ������.
	//#�̸�: ȫ�浿
	//##���: �౸
	if ((fp = fopen("student.txt", "rt")) == NULL)
	{
		fprintf(stderr, "�б⸦ ���� ������ �� �� �����ϴ�.\n");
		exit(1);
	}
	while (fgets(buf, 100, fp)) {
		printf("%s", buf);
	}

	//4��
	struct student table[SIZE] = {
		{ 1, "Kim", 3.99 },
		{ 2, "Min", 2.68 },
		{ 3, "Lee", 4.01 }
	};
	struct student s;
	int stu_no;
	double stu_gpa;

	// ���� ������ ���� ���� ����.
	if ((fp = fopen("student.dat", "wb+")) == NULL)
	{
		fprintf(stderr, "����� ���� ������ �� �� �����ϴ�.\n");
		exit(1);
	}
	// �迭�� ���Ͽ� �����Ѵ�.
	fwrite(table, sizeof(struct student), SIZE, fp);

	printf("���� �л� ���ڵ�\n");
	fseek(fp, 0, SEEK_SET);
	while (fread(&s, sizeof(struct student), 1, fp) == 1) {
		printf("%d, %s, %.2f\n", s.number, s.name, s.gpa);
	}
	printf("������ �й�: ");
	scanf("%d", &stu_no);
	printf("������ ����: ");
	scanf("%lf", &stu_gpa);

	f4(fp, stu_no, stu_gpa);

	fseek(fp, 0, SEEK_SET);
	while (fread(&s, sizeof(struct student), 1, fp) == 1) {
		printf("%d, %s, %.2f\n", s.number, s.name, s.gpa);
	}

	fclose(fp);

	return 0;
}

/*���� ��°��
ã�� ���ϸ�: main.c
ã�� ���ڿ�: seek
�˻��������
82:     fseek(fp, 0, SEEK_SET);
88:                     fseek(fp, -(int)sizeof(struct student), SEEK_CUR);
163:    fseek(fp, 0, SEEK_SET);
174:    fseek(fp, 0, SEEK_SET);
189:   ã�� ���ڿ�: seek
191:   75 :    fseek(fp, 0, SEEK_SET);
192:   80 :                    fseek(fp, -(int)sizeof(struct student), SEEK_CUR);
193:   155 :   fseek(fp, 0, SEEK_SET);
194:   166 :   fseek(fp, 0, SEEK_SET);
195:   181 : ã�� ���ڿ�: seek
196:   185 : 76 :    fseek(fp, 0, SEEK_SET);
197:   186 : 81 :                    fseek(fp, -(int)sizeof(struct student), SEEK_CUR);
199:   187 : 156 :   fseek(fp, 0, SEEK_SET);
200:   188 : 167 :   fseek(fp, 0, SEEK_SET);

�ܾ� �� :   564
�� ��   :   219

#�̸�: ȫ�浿
##���: �౸
���� �л� ���ڵ�
1, Kim, 3.99
2, Min, 2.68
3, Lee, 4.01
������ �й�: 2
������ ����: 1.5
������ �л� ���ڵ�
1, Kim, 3.99
2, Min, 1.50
3, Lee, 4.01

C:\Users\rlawl\OneDrive\���� ȭ��\C code\Project1\x64\Debug\Project1.exe(���μ��� 31312��)��(��) ����Ǿ����ϴ�(�ڵ�: 0 ��).
�� â�� �������� �ƹ� Ű�� ��������...
*/
/*���� ��°��
ã�� ���ϸ�: main.c
ã�� ���ڿ�: seek
�˻��������
75 :    fseek(fp, 0, SEEK_SET);
80 :                    fseek(fp, -(int)sizeof(struct student), SEEK_CUR);
155 :   fseek(fp, 0, SEEK_SET);
166 :   fseek(fp, 0, SEEK_SET);
181 : ã�� ���ڿ�: seek
185 : 76 :    fseek(fp, 0, SEEK_SET);
186 : 81 :                    fseek(fp, -(int)sizeof(struct student), SEEK_CUR);

187 : 156 :   fseek(fp, 0, SEEK_SET);
188 : 167 :   fseek(fp, 0, SEEK_SET);

�ܾ� �� :   531
�� ��   :   206

#�̸�: ȫ�浿
##���: �౸
���� �л� ���ڵ�
1, Kim, 3.99
2, Min, 2.68
3, Lee, 4.01
������ �й�: 2
������ ����: 1.5
������ �л� ���ڵ�
1, Kim, 3.99
2, Min, 1.50
3, Lee, 4.01
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/

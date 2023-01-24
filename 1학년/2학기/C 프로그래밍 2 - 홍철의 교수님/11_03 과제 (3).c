
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct point {
	int x, y;
};
struct circle {
	struct point center;
	int r;
};

int equal_value(struct circle c1, struct circle c2)
{
	if (c1.r == c2.r)
		return 1;
	else
		return 0;		


	




}

int equal_ref(struct circle* c1, struct circle* c2)
{
	//�Ʒ��� �ϼ��Ͻÿ�
	if (c1->r == c2->r)
		return 1;
	else
		return 0;

}

int include(struct circle c1, struct circle c2)
{
	//�Ʒ��� �ϼ��Ͻÿ�
	if ((c1.center.x + c1.r >= c2.center.x + c2.r) & (c1.center.y + c1.r >= c2.center.y + c2.r))
		return 1;
	else
		return 0;

}

double length(struct point* p1, struct point* p2) {
	//�Ʒ��� �ϼ��Ͻÿ�
	return sqrt(pow((p1->x - p2->x), 2) + pow((p1->y - p2->y), 2));

}
int main(void)
{
	//1,2��
	struct circle c1 = { 1, 2, 10 };
	struct circle c2 = { 2, 3, 5 };

	printf("���� ��ġ ����: ");
	equal_value(c1, c2) ? printf("����") : printf("�ٸ���");
	printf("\n");
	printf("���� ��ġ ����: ");
	equal_ref(&c1, &c2) ? printf("����") : printf("�ٸ���");
	printf("\n");

	//3��
	printf("���� ����: ");
	include(c1, c2) ? printf("�����Ѵ�") : printf("�������� �ʴ´�");
	printf("\n");
	//3��

	//4��
	double d = length(&(c1.center), &(c2.center));
	printf("���� = %.2f\n", d);

	return 0;
}
/*���� ��°��
���� ��ġ ����: �ٸ���
���� ��ġ ����: �ٸ���
���� ����: �����Ѵ�
���� = 1.41

C:\Users\rlawl\OneDrive\���� ȭ��\C code\Project4\x64\Debug\Project4.exe(���μ��� 33592��)��(��) ����Ǿ����ϴ�(�ڵ�: 0 ��).
�� â�� �������� �ƹ� Ű�� ��������...



*/
/*���� ��°��
���� ��ġ ����: �ٸ���
���� ��ġ ����: �ٸ���
���� ����: �����Ѵ�
���� = 1.41
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/

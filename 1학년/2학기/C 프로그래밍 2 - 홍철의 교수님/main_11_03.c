
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
	//�Ʒ��� �ϼ��Ͻÿ�


}

int equal_ref(struct circle* c1, struct circle* c2)
{
	//�Ʒ��� �ϼ��Ͻÿ�


}

int include(struct circle c1, struct circle c2)
{
	//�Ʒ��� �ϼ��Ͻÿ�



}

double length(struct point *p1, struct point *p2) {
	//�Ʒ��� �ϼ��Ͻÿ�
	

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

*/
/*���� ��°��
���� ��ġ ����: �ٸ���
���� ��ġ ����: �ٸ���
���� ����: �����Ѵ�
���� = 1.41
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/

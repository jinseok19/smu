#define _USE_MATH_DEFINES
#define FALSE 0
#define TRUE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//1��
typedef struct point {
	int x, y;
} Point;
enum shape_enum { RECT, CIRCLE };
typedef struct rectangle {
	Point p1, p2;
} Rectangle;
typedef struct circle {
	Point p;
	int radius;
} Circle;

struct shape_struc {
	enum shape_enum type;
	union {
		Rectangle rect;
		Circle cir;
	} data;
};

//2��    
struct date {
	int year;
	int month;
	int day;
};
typedef struct {
	enum { F, M } sex;
	union {
		int children;
		int beard;
	} u;
} sex_type;

typedef struct {
	char name[10];
	struct date* sd;   // �����͸� ����Ͽ� ����ü ��� ����
	sex_type sex_info;
} human_being;



int rect_area(Rectangle rect)
{
	return (rect.p2.x - rect.p1.x) * (rect.p2.y - rect.p1.y);
}
double circle_area(Circle cir)
{
	return M_PI * cir.radius * cir.radius;
}
void shape_area(struct shape_struc shape) {
	//�Ʒ��� �ϼ��Ͻÿ�.
	if (shape.type == CIRCLE) {
		printf("�� ���� : %.2f\n", circle_area(shape.data.cir));
		
	}
	else {
		printf("�簢�� ���� : %d\n", rect_area(shape.data.rect));
	}
}
void print_person(human_being* person)
{
	//�Ʒ��� �ϼ��Ͻÿ�.
	if (person->sex_info.sex == M) {
		if (person->sex_info.u.beard == FALSE) {
			printf("�̸�: %s, ������� : %d. %02d. %02d. ������ �⸥�� �ʴ´�.\n", person->name, person->sd->year, person->sd->month, person->sd->day);
		}
		else if(person->sex_info.u.beard == TRUE){
			printf("�̸�: %s, ������� : %d. %02d. %02d. ������ �⸥��.\n", person->name, person->sd->year, person->sd->month, person->sd->day);
		}
		
	}
	else if(person->sex_info.sex == F) {
		printf("�̸�: %s, ������� : %d. %02d. %02d. �ڳ�� : %d\n", person->name, person->sd->year, person->sd->month, person->sd->day, person->sex_info.u.children);
	}
	
}
int main(void)
{
	//1��
	struct shape_struc shapes[2] = { {CIRCLE, 20,20, 50}, {RECT, 20, 10, 90, 80 } };

	for (int i = 0; i < 2; i++)
		shape_area(shapes[i]);

	////2��
	human_being person1, person2;
	struct date d1 = { 2002, 5, 5 }, d2 = { 2000, 4, 5 };

	strcpy(person1.name, "ö��");
	person1.sd = &d1;
	person1.sex_info.sex = M;
	person1.sex_info.u.beard = FALSE;

	strcpy(person2.name, "����");
	person2.sd = &d2;
	person2.sex_info.sex = F;
	person2.sex_info.u.children = 4;

	print_person(&person1);
	print_person(&person2);

	return 0;
}

/*���� ��°��
�� ���� : 7853.98
�簢�� ���� : 4900
�̸�: ö��, ������� : 2002. 05. 05. ������ �⸥�� �ʴ´�.
�̸�: ����, ������� : 2000. 04. 05. �ڳ�� : 4

C:\Users\rlawl\OneDrive\���� ȭ��\C code\Project1\x64\Debug\Project1.exe(���μ��� 22568��)��(��) ����Ǿ����ϴ�(�ڵ�: 0 ��).
�� â�� �������� �ƹ� Ű�� ��������...


*/
/*���� ��°��
�� ����: 7853.98
�簢�� ����: 4900
�̸�: ö��,  ������� : 2002. 05. 05. ������ �⸥�� �ʴ´�.
�̸�: ����,  ������� : 2000. 04. 05. �ڳ��: 4
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/

#define _USE_MATH_DEFINES
#define FALSE 0
#define TRUE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//1번
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

//2번    
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
	struct date* sd;   // 포인터를 사용하여 구조체 멤버 선언
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
	//아래를 완성하시오.
	if (shape.type == CIRCLE) {
		printf("원 넓이 : %.2f\n", circle_area(shape.data.cir));
		
	}
	else {
		printf("사각형 넓이 : %d\n", rect_area(shape.data.rect));
	}
}
void print_person(human_being* person)
{
	//아래를 완성하시오.
	if (person->sex_info.sex == M) {
		if (person->sex_info.u.beard == FALSE) {
			printf("이름: %s, 생년월일 : %d. %02d. %02d. 수염을 기른지 않는다.\n", person->name, person->sd->year, person->sd->month, person->sd->day);
		}
		else if(person->sex_info.u.beard == TRUE){
			printf("이름: %s, 생년월일 : %d. %02d. %02d. 수염을 기른다.\n", person->name, person->sd->year, person->sd->month, person->sd->day);
		}
		
	}
	else if(person->sex_info.sex == F) {
		printf("이름: %s, 생년월일 : %d. %02d. %02d. 자녀수 : %d\n", person->name, person->sd->year, person->sd->month, person->sd->day, person->sex_info.u.children);
	}
	
}
int main(void)
{
	//1번
	struct shape_struc shapes[2] = { {CIRCLE, 20,20, 50}, {RECT, 20, 10, 90, 80 } };

	for (int i = 0; i < 2; i++)
		shape_area(shapes[i]);

	////2번
	human_being person1, person2;
	struct date d1 = { 2002, 5, 5 }, d2 = { 2000, 4, 5 };

	strcpy(person1.name, "철수");
	person1.sd = &d1;
	person1.sex_info.sex = M;
	person1.sex_info.u.beard = FALSE;

	strcpy(person2.name, "영희");
	person2.sd = &d2;
	person2.sex_info.sex = F;
	person2.sex_info.u.children = 4;

	print_person(&person1);
	print_person(&person2);

	return 0;
}

/*실제 출력결과
원 넓이 : 7853.98
사각형 넓이 : 4900
이름: 철수, 생년월일 : 2002. 05. 05. 수염을 기른지 않는다.
이름: 영희, 생년월일 : 2000. 04. 05. 자녀수 : 4

C:\Users\rlawl\OneDrive\바탕 화면\C code\Project1\x64\Debug\Project1.exe(프로세스 22568개)이(가) 종료되었습니다(코드: 0 개).
이 창을 닫으려면 아무 키나 누르세요...


*/
/*예시 출력결과
원 넓이: 7853.98
사각형 넓이: 4900
이름: 철수,  생년월일 : 2002. 05. 05. 수염을 기른지 않는다.
이름: 영희,  생년월일 : 2000. 04. 05. 자녀수: 4
계속하려면 아무 키나 누르십시오 . . .
*/


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
	//아래를 완성하시오
	if (c1->r == c2->r)
		return 1;
	else
		return 0;

}

int include(struct circle c1, struct circle c2)
{
	//아래를 완성하시오
	if ((c1.center.x + c1.r >= c2.center.x + c2.r) & (c1.center.y + c1.r >= c2.center.y + c2.r))
		return 1;
	else
		return 0;

}

double length(struct point* p1, struct point* p2) {
	//아래를 완성하시오
	return sqrt(pow((p1->x - p2->x), 2) + pow((p1->y - p2->y), 2));

}
int main(void)
{
	//1,2번
	struct circle c1 = { 1, 2, 10 };
	struct circle c2 = { 2, 3, 5 };

	printf("넓이 일치 여부: ");
	equal_value(c1, c2) ? printf("같다") : printf("다르다");
	printf("\n");
	printf("넓이 일치 여부: ");
	equal_ref(&c1, &c2) ? printf("같다") : printf("다르다");
	printf("\n");

	//3번
	printf("포함 여부: ");
	include(c1, c2) ? printf("포함한다") : printf("포함하지 않는다");
	printf("\n");
	//3번

	//4번
	double d = length(&(c1.center), &(c2.center));
	printf("길이 = %.2f\n", d);

	return 0;
}
/*실제 출력결과
넓이 일치 여부: 다르다
넓이 일치 여부: 다르다
포함 여부: 포함한다
길이 = 1.41

C:\Users\rlawl\OneDrive\바탕 화면\C code\Project4\x64\Debug\Project4.exe(프로세스 33592개)이(가) 종료되었습니다(코드: 0 개).
이 창을 닫으려면 아무 키나 누르세요...



*/
/*예시 출력결과
넓이 일치 여부: 다르다
넓이 일치 여부: 다르다
포함 여부: 포함한다
길이 = 1.41
계속하려면 아무 키나 누르십시오 . . .
*/


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
	//아래를 완성하시오


}

int equal_ref(struct circle* c1, struct circle* c2)
{
	//아래를 완성하시오


}

int include(struct circle c1, struct circle c2)
{
	//아래를 완성하시오



}

double length(struct point *p1, struct point *p2) {
	//아래를 완성하시오
	

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

*/
/*예시 출력결과
넓이 일치 여부: 다르다
넓이 일치 여부: 다르다
포함 여부: 포함한다
길이 = 1.41
계속하려면 아무 키나 누르십시오 . . .
*/

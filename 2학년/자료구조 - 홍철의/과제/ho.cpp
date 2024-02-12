
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

struct point
{
	int x, y;
};

void get_max_min(int* p, int* last_p, int* max, int* min)
{
	//새로운 변수를 선언하지 마시오.
	//배열의 차원(3x5)의 상수를 사용하지 마시오.
	*max = *min = *p++;

	//아래를 완성하시오.
	while (p <= last_p) {
		if (*max < *p) {
			*max = *p;
		}
		else if (*min > *p) {
			*min = *p;
		}
		p++;
	}
}

double get_distance(point* p, int size)
{
	//새로운 변수를 선언하지 마시오.
	int i, j;
	double tmp, distance = 0.0;

	//아래를 완성하시오.수학함수를 이용하시오.
	for (i = 0; i <= size; i++) {
		for (j = i+1; j < size; j++) {
			tmp = sqrt(pow(abs(p[j].x - p[i].x), 2) + pow(abs(p[j].y - p[i].y), 2));
			if (distance < tmp) {
				distance = tmp;
			}
			
				
			
		}
		
	}
	

	return distance;
}
int main(void)
{
	int list[3][5];
	int i, j, max, min;

	//문제 1.
	srand(1);
	printf("list:\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 5; j++) {
			list[i][j] = rand() % 100 + 101;
			printf("%5d", list[i][j]);
		}
		printf("\n");
	}
	get_max_min(*list, *(list + 2) + 4, &max, &min);
	printf("최대값: %d, 최소값: %d\n", max, min);

	//문제 2.
	point point_arr[5] =
	{
		3, 5,
		4, 9,
		1, 9,
		6, 2,
		8, 3,
	};

	printf("\n최대 거리: %.2f\n", get_distance(point_arr, 5));

	return 0;
}

/*실제출력결과
list:
  142  168  135  101  170
  125  179  159  163  165
  106  146  182  128  162
최대값: 182, 최소값: 101

최대 거리: 9.22

C:\Users\rlawl\OneDrive\바탕 화면\상명대학교\2학년\자료구조\03_22\Project1\x64\Debug\Project1.exe(프로세스 55068개)이(가) 종료되었습니다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...
*/
/*
예시 출력
list:
  142  168  135  101  170
  125  179  159  163  165
  106  146  182  128  162
최대값: 182, 최소값: 101

최대 거리: 9.22
계속하려면 아무 키나 누르십시오 . . .
*/
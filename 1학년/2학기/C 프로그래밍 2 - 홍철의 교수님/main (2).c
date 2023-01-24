#include <stdio.h>
#include <stdlib.h>

//1번 함수를 완성하시오.
void prob_1(int* p1, int* p2, int* p3) {
	int tmp;

	//아래를 완성하시오
	tmp = *p1;
	*p1 = *p2;
	*p2 = *p3;
	*p3 = tmp;
}

double prob_2(int* p, int size) {
	int i, sum = 0;
	//2번 함수를 완성하시오.
	for (i = 0; i < size; i++) {
		sum += p[i * size];
	}


	return (double)sum / size;
}



double prob_3(int* p, int* q, int* sum) {
	int cnt;//배열의 크기

	//3번 함수를 완성하시오. 상수를 사용하지 마시오,예로 평균을 구하기 위하여 배열 크기 16
	//배열의 크기를 함수안에 계산하시오.
	cnt = q - p;
	while (p < q) {
		*sum += *p++;

	}
	return (double)*sum / cnt;
}
int main(void) {
	//1번
	int n1 = 3, n2 = 6, n3 = 9;
	printf("1번 전: n1:%d, n2:%d, n3:%d\n", n1, n2, n3);
	prob_1(&n1, &n2, &n3);
	printf("1번 후: n1:%d, n2:%d, n3:%d\n", n1, n2, n3);

	//2번
	int k = 1, a[4][4];
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			a[i][j] = k++;
		}
	}
	for (int i = 0; i < 4; i++)
		printf("%d번째 열 평균: %.2f\n", i, prob_2(a[0] + i, 4));

	//3번
	int sum = 0;
	double avg = prob_3((int*)a, (int*)a + 16, &sum);
	printf("배열 a의 합: %d, 평균: %.2f\n", sum, avg);

	return 0;
}

/*실제 출력결과
1번 전: n1:3, n2:6, n3:9
1번 후: n1:6, n2:9, n3:3
0번째 열 평균: 7.00
1번째 열 평균: 8.00
2번째 열 평균: 9.00
3번째 열 평균: 10.00
배열 a의 합: 136, 평균: 8.50

C:\Users\rlawl\OneDrive\바탕 화면\C code\Project1\x64\Debug\Project1.exe(프로세스 25472개)이(가) 종료되었습니다(코드: 0 개).
이 창을 닫으려면 아무 키나 누르세요...
*/
/*예시 출력결과
1번 전: n1:3, n2:6, n3:9
1번 후: n1:6, n2:9, n3:3
0번째 열 평균: 7.00
1번째 열 평균: 8.00
2번째 열 평균: 9.00
3번째 열 평균: 10.00
배열 a의 합: 136, 평균: 8.50
계속하려면 아무 키나 누르십시오 . . .
*/

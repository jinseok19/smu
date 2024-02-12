
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int fib_recur(int n) //순환 알고리즘으로 피보나치 수 계산
{
	//아래를 완성하시오.
	if (n <= 1)
		return n;
	return fib_recur(n - 1) + fib_recur(n - 2);
	

}
int fib_iter(int n)//피보나치 수 저장을 위해 배열 사용
{
	int* arr = new int[n + 1];
	arr[0] = 0, arr[1] = 1;
	//아래를 완성하시오.
	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}


	int result = arr[n];
	delete[] arr;
	return result;
}
int main()
{
	clock_t start, stop;
	double duration;
	int n;

	start = clock(); //측정시작
	n = fib_iter(40);
	stop = clock(); //측정종료
	duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
	printf("반복: fib(40)= %d, 수행시간은 %f초입니다.\n", n, duration);

	start = clock(); //측정시작
	n = fib_recur(40);
	stop = clock(); //측정종료
	duration = ((double)stop - (double)start) / CLOCKS_PER_SEC;
	printf("순환: fib(40)= %d, 수행시간은 %f초입니다.\n", n, duration);

	return 0;
}
/*실제출력결과
반복: fib(40)= 102334155, 수행시간은 0.000000초입니다.
순환: fib(40)= 102334155, 수행시간은 0.943000초입니다.

C:\Users\rlawl\OneDrive\바탕 화면\상명대학교\2학년\자료구조\03_15\x64\Debug\03_15.exe(프로세스 22268개)이(가) 종료되었습니다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...

*/
/*예시출력결과
반복: fib(40)= 102334155, 수행시간은 0.000000초입니다.
순환: fib(40)= 102334155, 수행시간은 7.426000초입니다.
계속하려면 아무 키나 누르십시오 . . .
*/
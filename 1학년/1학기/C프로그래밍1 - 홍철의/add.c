
#include <stdio.h>

//main.c의 전역변수 op를 extern 을 사용하여 외부 연결
extern int op;


int add() {
	//static 키워드를 사용하여 정수 변수 sum 선언한후 외부연결 변수 op를 sum에 더한 후 sum 반환
	static int sum;
	sum += op;
	return sum;


}
#include <stdio.h>

int main(void)

{

	//1번

	for (int i = 0; i < 4; i++) {// 1번 문제를 4번 반복합니다.

		//아래를 완성하시오.

		int num;

		printf("1개의 양의 정수를 입력하시오 : ");

		scanf_s("%d", &num);

		if (num % 6 == 0 && num % 9 == 0) {

			printf("%d는 6과 9의 배수입니다.\n", num);
		}
		else if (num % 6 == 0) {
			printf("%d는 6의 배수입니다.\n", num);
		}

		else if (num % 9 == 0) {
			printf("%d는 9의 배수 입니다.\n", num);
		}
		else

		{
			printf("%d은 6또는 9의 배수가 아닙니다.\n", num);
		}
	}



	int n;



	//2번, if else 문을 이용하여 완성하시오.

	printf("\n한자리 양의 정수 입력 : ");

	scanf_s("%d", &n);

	//아래를 완성하시오.

	if (n % 2 == 0)

	{
		printf("%d는 짝수입니다.\n", n);
	}

	else

	{
		printf("%d는 홀수입니다.\n", n);
	}

	//3번, switch문을 이용하여 완성하시오.

	printf("\n한자리 양의 정수 입력 : ");

	scanf_s("%d", &n);

	//아래를 완성하시오.

	switch (n)

	{
	case 0:

	case 2:

	case 4:

	case 6:

	case 8:

		printf("%d는 짝수입니다.\n", n);

		break;

	default:

		printf("%d는 홀수입니다.\n", n);

	}

	return 0;

}



/*실제 출력 결과

1개의 양의 정수를 입력하시오: 12
12는 6의 배수입니다.
1개의 양의 정수를 입력하시오: 18
18는 6과 9의 배수입니다.
1개의 양의 정수를 입력하시오: 9
9는 9의 배수입니다.
1개의 양의 정수를 입력하시오: 10
10는 6또는 9의 배수가 아닙니다.

한자리 양의 정수 입력 : 8
8는 짝수입니다.

한자리 양의 정수 입력 : 5
5는 홀수입니다.

계속하려면 아무 키나 누르십시오 . . .

*/

/*예시 출력 결과

1개의 양의 정수를 입력하시오: 12

12는 6의 배수입니다.

1개의 양의 정수를 입력하시오: 18

18는 6과 9의 배수입니다.

1개의 양의 정수를 입력하시오: 9

9는 9의 배수입니다.

1개의 양의 정수를 입력하시오: 10

10는 6또는 9의 배수가 아닙니다.



한자리 양의 정수 입력 : 8

8는 짝수입니다.



한자리 양의 정수 입력 : 5

5는 홀수입니다.

계속하려면 아무 키나 누르십시오 . . .

*/
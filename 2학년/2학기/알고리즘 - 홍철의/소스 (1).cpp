#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 20
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void prob13() {
    int n, min_n, max_n;//min_n: n의 최소값, max_n: n의 최대값
    min_n = max_n = 2;
    double A = 10.0 * max_n * max_n;
    double B = 300.0 * log2(max_n);
    while (A <= B) { //A>B의 max_n을 구함
        min_n = max_n;
        max_n *= 2;
        A = 10.0 * max_n * max_n;
        B = 300.0 * log2(max_n);
    }
    printf("초기 min_n= %d, A:%.0f, B:%.0f\n", min_n, 10.0 * min_n * min_n, 300.0 * log2(min_n));
    printf("     max_n= %d, A:%.0f, B:%.0f\n", max_n, 10.0 * max_n * max_n, 300.0 * log2(max_n));

    //초기값 8과 16사이에서 최적의 n을 효율적으로 구하는 코드 작성(수치해석 이분법 참조)
    while (max_n - min_n > 1) {
        //아래를 완성하시오.
        n = (min_n + max_n) / 2;
        A = 10.0 * n * n;
        B = 300.0 * log2(n);
        if (A > B)
            max_n = n;
        else // A<=B
            min_n = n;



    }
    printf("최종 n= %d, A:%.0f, B:%.0f\n", max_n, 10.0 * max_n * max_n, 300.0 * log2(max_n));
}

int partition(int list[], int left, int right)
{
    int pivot, temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do {
        do
            low++;
        while (low <= right && list[low] < pivot);
        do
            high--;
        while (high >= left && list[high] > pivot);
        if (low < high) SWAP(list[low], list[high], temp);
    } while (low < high);

    SWAP(list[left], list[high], temp);
    return high;
}
void prob33()
{
    int list[MAX_SIZE];
    int i, n;

    n = MAX_SIZE;
    int left = 0, right = n - 1;
    int pivot;
    int median_index = (left + right) / 2;//n은 2의 배수라 가정

    srand(1);
    printf("초기배열: ");
    for (i = 0; i < n; i++) {
        list[i] = rand() % 20 + 1;
        printf("%d,", list[i]);
    }
    printf("\n");

    do {
        //아래를 완성하시오.
        pivot = partition(list, left, right);
        if (pivot < median_index) {
            left = pivot + 1;
        }
        else if (pivot > median_index) {
            right = pivot - 1;
        }
    } while (pivot != median_index);

    printf("최소 부분 배열: ");
    for (i = 0; i <= pivot; i++)
        printf("%2d ", list[i]);
    printf("\n");
    printf("최대 부분 배열: ");
    for (i = pivot + 1; i < n; i++)
        printf("%2d ", list[i]);
    printf("\n");
}
int main(void)
{
    //13번
    prob13();

    //33번
    prob33();

    return 0;
}

/*예시 출력
초기 min_n= 8, A:640, B:900
    max_n= 16, A:2560, B:1200
최종 n= 10, A:1000, B:997
초기배열: 2,8,15,1,10,5,19,19,3,5,6,6,2,8,2,12,16,3,8,17,
최소 부분 배열:  1  2  2  2  5  5  6  3  3  6
최대 부분 배열:  8  8  8 10 15 12 16 19 19 17
계속하려면 아무 키나 누르십시오 . . .
*/

/*실제 출력

초기 min_n= 8, A:640, B:900
     max_n= 16, A:2560, B:1200
최종 n= 10, A:1000, B:997
초기배열: 2,8,15,1,10,5,19,19,3,5,6,6,2,8,2,12,16,3,8,17,
최소 부분 배열:  1  2  2  2  5  5  6  3  3  6
최대 부분 배열:  8  8  8 10 15 12 16 19 19 17

C:\Users\rlawl\OneDrive\바탕 화면\상명대학교\2학년\2학기\알고리즘 - 홍철의\Project2\x64\Debug\Project2.exe(프로세스 24452개)이(가) 종료되었습니다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10001
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

int list[MAX_SIZE];
int n;

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

int main(void)
{
    n = MAX_SIZE;
    int left = 0, right = n - 1;
    int pivot;
    int median_index = (left + right) / 2;//n은 홀수라 가정

    int i;

    srand(1);
    for (i = 0; i < n; i++)
        list[i] = rand() % 10000;
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

    printf("중앙값: %d\n", list[pivot]);

    return 0;
}
/*실제 출력
시간 복잡도 : O(n) partition 함수의 시간복잡도는 O(n)이다. 그런데 pivot의 위치는 평균적으로 중간에
위치하므로 다음 partition 함수의 구간은 n/2 
n + n/2 + n/4 + n/8 + ... = 2n
2n은 O(n)이다. 

중앙값: 4536

C:\Users\rlawl\OneDrive\바탕 화면\상명대학교\2학년\자료구조\05_24\Project1\x64\Debug\Project1.exe(프로세스 37060개)이(가) 종료되었습니다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...


*/
/*예시 출력
중앙값: 4536
계속하려면 아무 키나 누르십시오 . . .
*/
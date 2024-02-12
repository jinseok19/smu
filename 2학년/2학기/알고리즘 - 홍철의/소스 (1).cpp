#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 20
#define SWAP(x, y, t) ( (t)=(x), (x)=(y), (y)=(t) )

void prob13() {
    int n, min_n, max_n;//min_n: n�� �ּҰ�, max_n: n�� �ִ밪
    min_n = max_n = 2;
    double A = 10.0 * max_n * max_n;
    double B = 300.0 * log2(max_n);
    while (A <= B) { //A>B�� max_n�� ����
        min_n = max_n;
        max_n *= 2;
        A = 10.0 * max_n * max_n;
        B = 300.0 * log2(max_n);
    }
    printf("�ʱ� min_n= %d, A:%.0f, B:%.0f\n", min_n, 10.0 * min_n * min_n, 300.0 * log2(min_n));
    printf("     max_n= %d, A:%.0f, B:%.0f\n", max_n, 10.0 * max_n * max_n, 300.0 * log2(max_n));

    //�ʱⰪ 8�� 16���̿��� ������ n�� ȿ�������� ���ϴ� �ڵ� �ۼ�(��ġ�ؼ� �̺й� ����)
    while (max_n - min_n > 1) {
        //�Ʒ��� �ϼ��Ͻÿ�.
        n = (min_n + max_n) / 2;
        A = 10.0 * n * n;
        B = 300.0 * log2(n);
        if (A > B)
            max_n = n;
        else // A<=B
            min_n = n;



    }
    printf("���� n= %d, A:%.0f, B:%.0f\n", max_n, 10.0 * max_n * max_n, 300.0 * log2(max_n));
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
    int median_index = (left + right) / 2;//n�� 2�� ����� ����

    srand(1);
    printf("�ʱ�迭: ");
    for (i = 0; i < n; i++) {
        list[i] = rand() % 20 + 1;
        printf("%d,", list[i]);
    }
    printf("\n");

    do {
        //�Ʒ��� �ϼ��Ͻÿ�.
        pivot = partition(list, left, right);
        if (pivot < median_index) {
            left = pivot + 1;
        }
        else if (pivot > median_index) {
            right = pivot - 1;
        }
    } while (pivot != median_index);

    printf("�ּ� �κ� �迭: ");
    for (i = 0; i <= pivot; i++)
        printf("%2d ", list[i]);
    printf("\n");
    printf("�ִ� �κ� �迭: ");
    for (i = pivot + 1; i < n; i++)
        printf("%2d ", list[i]);
    printf("\n");
}
int main(void)
{
    //13��
    prob13();

    //33��
    prob33();

    return 0;
}

/*���� ���
�ʱ� min_n= 8, A:640, B:900
    max_n= 16, A:2560, B:1200
���� n= 10, A:1000, B:997
�ʱ�迭: 2,8,15,1,10,5,19,19,3,5,6,6,2,8,2,12,16,3,8,17,
�ּ� �κ� �迭:  1  2  2  2  5  5  6  3  3  6
�ִ� �κ� �迭:  8  8  8 10 15 12 16 19 19 17
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/

/*���� ���

�ʱ� min_n= 8, A:640, B:900
     max_n= 16, A:2560, B:1200
���� n= 10, A:1000, B:997
�ʱ�迭: 2,8,15,1,10,5,19,19,3,5,6,6,2,8,2,12,16,3,8,17,
�ּ� �κ� �迭:  1  2  2  2  5  5  6  3  3  6
�ִ� �κ� �迭:  8  8  8 10 15 12 16 19 19 17

C:\Users\rlawl\OneDrive\���� ȭ��\�����б�\2�г�\2�б�\�˰��� - ȫö��\Project2\x64\Debug\Project2.exe(���μ��� 24452��)��(��) ����Ǿ����ϴ�(�ڵ�: 0��).
�� â�� �������� �ƹ� Ű�� ��������...

*/
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
    int median_index = (left + right) / 2;//n�� Ȧ���� ����

    int i;

    srand(1);
    for (i = 0; i < n; i++)
        list[i] = rand() % 10000;
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

    printf("�߾Ӱ�: %d\n", list[pivot]);

    return 0;
}
/*���� ���
�ð� ���⵵ : O(n) partition �Լ��� �ð����⵵�� O(n)�̴�. �׷��� pivot�� ��ġ�� ��������� �߰���
��ġ�ϹǷ� ���� partition �Լ��� ������ n/2 
n + n/2 + n/4 + n/8 + ... = 2n
2n�� O(n)�̴�. 

�߾Ӱ�: 4536

C:\Users\rlawl\OneDrive\���� ȭ��\�����б�\2�г�\�ڷᱸ��\05_24\Project1\x64\Debug\Project1.exe(���μ��� 37060��)��(��) ����Ǿ����ϴ�(�ڵ�: 0��).
�� â�� �������� �ƹ� Ű�� ��������...


*/
/*���� ���
�߾Ӱ�: 4536
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/
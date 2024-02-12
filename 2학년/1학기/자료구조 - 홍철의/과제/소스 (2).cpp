#include <stdio.h>
# include <stdlib.h>
#define MAX_ELEMENT 200
#define SEL_NUM 10
#define MAX_HEAP_SIZE 11
typedef struct {
	int list[MAX_HEAP_SIZE + 1];
	int heap_size;

}HeapType;

void init(HeapType* h) {
	h->heap_size = 0;

}
//최대힙 삽입 함수
void insert_max_heap(HeapType* h, int item) {
	int i;
	i = ++(h->heap_size);
	
	// 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
	while ((i != 1) && (item > h->list[i / 2])) {
		h->list[i] = h->list[i / 2];
		i /= 2;
	}
	h->list[i] = item; //새로운 노드를 삽입
 }

//루트의 키를 item으로 대체한 후 최대힙 재구성
void delete_max_heap(HeapType* h, int item) {
	int parent, child;
	
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {// 현재 노드의 자식노드중 더 큰 자식노드를
		if ((child < h->heap_size) && (h->list[child]) < h->list[child + 1]) {
			child++;
		}
		if (item >= h->list[child]) {
			break;
		}
		// 한단계 아래로 이동
		h->list[parent] = h->list[child];
		parent = child;
		child *= 2;
	}
	h->list[parent] = item;
}

int main() {
	int i;
	int list[MAX_ELEMENT];
	HeapType heap;

	init(&heap);
	srand(1);
	printf("대상 리스트");
	for (int i = 0; i < MAX_ELEMENT; i++) {
		list[i] = rand() % 100;
		if (i % 10 == 0) {
			printf("\n");
		}
		printf("%d ", list[i]);
	}
	printf("\n");
	for (i = 0; i < MAX_HEAP_SIZE; i++) {
		insert_max_heap(&heap, list[i]);
	}
	for (; i < MAX_ELEMENT; i++) {
		delete_max_heap(&heap, list[i]);
	}
	printf("\n작은 키 %d 선택 리스트 \n", SEL_NUM);
	for (int i = 2; i <= MAX_HEAP_SIZE; i++) {
		printf("%d ", heap.list[i]);
	}
	printf("\n");
	
	return 0;
}
/*

새로운 알고리즘 제안

크기가 11인 최대힙을 사용하여 입력순으로 구축시 루트에는 최대값이 위치하고
인덱스 2부터 11에는 현재까지 입력된 값중에서 가장 작은 값이 위치한다.
다음 단계에서 새로운 입력값을 루트에 위치시킨후 최대힙을 재구성하면
루트에는 힙에서 큰 값이 이외의 노트에는 10개의 가장 작은 값이 반복적으로 
위치하게 된다.

*/

/*
결과

대상 리스트
41 67 34 0 69 24 78 58 62 64
5 45 81 27 61 91 95 42 27 36
91 4 2 53 92 82 21 16 18 95
47 26 71 38 69 12 67 99 35 94
3 11 22 33 73 64 41 11 53 68
47 44 62 57 37 59 23 41 29 78
16 35 90 42 88 6 40 42 64 48
46 5 90 29 70 50 6 1 93 48
29 23 84 54 56 40 66 76 31 8
44 39 26 23 37 38 18 82 29 41
33 15 39 58 4 30 77 6 73 86
21 45 24 72 70 29 77 73 97 12
86 90 61 36 55 67 55 74 31 52
50 50 41 24 66 30 7 91 7 37
57 87 53 83 45 9 9 58 21 88
22 46 6 30 13 68 0 91 62 55
10 59 24 37 48 83 95 41 2 50
91 36 74 20 96 21 48 99 68 84
81 34 53 99 18 38 0 88 27 67
28 93 48 83 7 21 10 17 13 14

작은 키 10 선택 리스트
3 5 1 2 4 4 0 0 2 0

C:\Users\rlawl\OneDrive\바탕 화면\상명대학교\2학년\자료구조\05_03\Project1\x64\Debug\Project1.exe(프로세스 7200개)이(가) 종료되었습니다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...

*/
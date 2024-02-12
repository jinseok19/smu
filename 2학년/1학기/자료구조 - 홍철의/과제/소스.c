
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAZE_SIZE 8

typedef struct {		// 교체!
	short r;
	short c;
} element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s)
{
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}
// 피크함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}
// ===== 스택 코드의 끝 ===== 


element here = { 1,0 }, entry = { 1,0 };

//char maze[MAZE_SIZE][MAZE_SIZE] = {
//	{ '1', '1', '1', '1', '1', '1' },
//{ 'e', '0', '1', '0', '0', '1' },
//{ '1', '0', '0', '0', '1', '1' },
//{ '1', '0', '1', '0', '1', '1' },
//{ '1', '0', '1', '0', '0', 'x' },
//{ '1', '1', '1', '1', '1', '1' },
//};
int maze[MAZE_SIZE][MAZE_SIZE] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1},
	{ 0, 0, 0, 0, 0, 1, 0, 1},
	{ 1, 0, 1, 1, 1, 1, 0, 1},
	{ 1, 0, 1, 1, 0, 0, 0, 1},
	{ 1, 0, 0, 0, 0, 1, 1, 1},
	{ 1, 0, 1, 0, 1, 0, 1, 1},
	{ 1, 0, 1, 0, 0, 0, 0, INT_MAX },
	{ 1, 1, 1, 1, 1, 1, 1, 1},
};
// 위치를 스택에 삽입
void push_loc(StackType* s, int r, int c)
{
	if (r < 0 || c < 0) return;
	if (maze[r][c] == 0 || maze[r][c] == INT_MAX) {
		//if (maze[r][c] != '1' && maze[r][c] != '.') {
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}
// 미로를 화면에 출력한다. 
void maze_print(int maze[MAZE_SIZE][MAZE_SIZE])
{
	//printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			if (maze[r][c] == INT_MAX)
				printf("%3c", 'x');
			else if (maze[r][c] == 2)
				printf("%3c", 'e');
			else
				printf("%3d", maze[r][c]);
		}
		printf("\n");
	}
}
//현재 위치에서 4방향중 가장 늦게 방문한 위치(스텝수가 가장 큰값)을 찾음
void get_max_step(element current, element* next) {
	int r = current.r, c = current.c;
	int step = maze[r][c];

	//아래를 완성하시오.

	if (r - 1 > 0 && c > 0 && step < maze[current.r - 1][current.c]) {
		step = maze[r - 1][c];
		next->r = r - 1;
		next->c = c;
	}
	if (r + 1 > 0 && c > 0 && step < maze[r + 1][c]) {
		step = maze[r + 1][c];
		next->r = r + 1;
		next->c = c;
	}
	if (r > 0 && c - 1 > 0 && step < maze[r][c - 1]) {
		step = maze[r][c - 1];
		next->r = r;
		next->c = c - 1;
	}
	if (r > 0 && c + 1 > 0 && step < maze[r][c + 1]) {
		step = maze[r][c + 1];
		next->r = r;
		next->c = c + 1;
	}

}
void path(int maze[MAZE_SIZE][MAZE_SIZE]) {
	element next;
	here = entry;
	printf("미로 경로: ");
	while (maze[here.r][here.c] != INT_MAX) {
		printf("(%d,%d)", here.r, here.c);
		get_max_step(here, &next);
		here = next;
	}
	printf("(%d,%d)\n", here.r, here.c);
}
int steps = 2;
void prob1(void)
{
	int r, c;
	StackType s;

	printf("최초 미로\n");
	maze_print(maze);
	init_stack(&s);
	here = entry;
	while (maze[here.r][here.c] != INT_MAX) {
		r = here.r;
		c = here.c;
		maze[r][c] = steps++;
		//maze_print(maze);
		push_loc(&s, r - 1, c);
		push_loc(&s, r + 1, c);
		push_loc(&s, r, c - 1);
		push_loc(&s, r, c + 1);
		if (is_empty(&s)) {
			printf("실패\n");
			return;
		}
		else
			here = pop(&s);
	}
	printf("최종 미로\n");
	maze_print(maze);
	printf("성공\n");
	path(maze);
}

#define ROWS 3
#define COLS 4
int fsum_1(int a[][COLS]) {
	int sum = 0;

	//아래를 완성하시오. a에 대한 2차원 배열로 접근
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			sum += a[i][j];
		}
	}
	return sum;
}
int fsum_2(int* p) {
	int sum = 0;

	//아래를 완성하시오. p에 대한 일차원 포인터로 접근
	for (int i = 0; i < ROWS * COLS; i++) {
		sum += *p++;
	}

	return sum;
}
int fsum_3(int(*p)[COLS]) {
	int sum = 0;

	//아래를 완성하시오. p에 대한 2차원 배열로 접근
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			sum += p[i][j];
		}
	}

	return sum;
}
int fsum_4(int(*p)[COLS]) {
	int sum = 0;

	//아래를 완성하시오. p에 대한 1차원 배열로 접근
	for (int i = 0; i < ROWS * COLS; i++) {
		sum += (*p)[i];
	}

	return sum;
}
void prob2(void)
{
	int arr[ROWS][COLS] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	int sum1 = fsum_1(arr);
	int sum2 = fsum_2(arr[0]);
	int sum3 = fsum_3(arr);
	int sum4 = fsum_4(arr);

	printf("sum1:%d, sum2:%d, sum3:%d, sum4:%d\n", sum1, sum2, sum3, sum4);
}
int main(void)
{
	prob1();
	prob2();

	return 0;
}
/*실제출력
최초 미로
  1  1  1  1  1  1  1  1
  0  0  0  0  0  1  0  1
  1  0  1  1  1  1  0  1
  1  0  1  1  0  0  0  1
  1  0  0  0  0  1  1  1
  1  0  1  0  1  0  1  1
  1  0  1  0  0  0  0  x
  1  1  1  1  1  1  1  1
최종 미로
  1  1  1  1  1  1  1  1
  e  3  4  5  6  1 17  1
  1  7  1  1  1  1 16  1
  1  8  1  1 13 14 15  1
  1  9 10 11 12  1  1  1
  1  0  1 18  1  0  1  1
  1  0  1 19 20 21 22  x
  1  1  1  1  1  1  1  1
성공
미로 경로: (1,0)(1,1)(2,1)(3,1)(4,1)(4,2)(4,3)(5,3)(6,3)(6,4)(6,5)(6,6)(6,7)
sum1:78, sum2:78, sum3:78, sum4:78

C:\Users\rlawl\OneDrive\바탕 화면\상명대학교\2학년\자료구조\03_29\03_29_project\x64\Debug\03_29_project.exe(프로세스 15504개)이(가) 종료되었습니다(코드: 0개).
이 창을 닫으려면 아무 키나 누르세요...

*/
/*예시출력
최초 미로
  1  1  1  1  1  1  1  1
  0  0  0  0  0  1  0  1
  1  0  1  1  1  1  0  1
  1  0  1  1  0  0  0  1
  1  0  0  0  0  1  1  1
  1  0  1  0  1  0  1  1
  1  0  1  0  0  0  0  x
  1  1  1  1  1  1  1  1
최종 미로
  1  1  1  1  1  1  1  1
  e  3  4  5  6  1 17  1
  1  7  1  1  1  1 16  1
  1  8  1  1 13 14 15  1
  1  9 10 11 12  1  1  1
  1  0  1 18  1  0  1  1
  1  0  1 19 20 21 22  x
  1  1  1  1  1  1  1  1
성공
미로 경로: (1,0)(1,1)(2,1)(3,1)(4,1)(4,2)(4,3)(5,3)(6,3)(6,4)(6,5)(6,6)(6,7)
sum1:78, sum2:78, sum3:78, sum4:78
계속하려면 아무 키나 누르십시오 . . .
*/
import numpy as np

def array1():
    a = np.array([[1,2],[3,4]])
    b = np.array([[1,3],[2,4]])
    print(a@b) # a, b 의 행렬 곱
    print(a.T) # a의 전치 행렬
    print(np.linalg.det(a)) # a의 행렬식
    print(np.linalg.inv(b)) # b의 역행렬

def insertion(arr, n):
    
    for i in range(1,n):
        tmp = arr[i]
        j = i -1
        t = i
        while (j >= 0):
            if arr[j] > tmp:
                arr[j + 1] = arr[j]
                t = j
            j -= 1
        arr[t] = tmp

    return arr


def selectionsort(arr, n):

    for i in range(1,n):
        max = n-i
        for j in range(0,n-i):
            if arr[j] > arr[max]:
                max = j
        
        if max != n-i:
            tmp = arr[n-i]
            arr[n-i] = arr[max]
            arr[max] = tmp

    return arr 

# 미로 찾기 프로그램(그래프 탐색)
# 입력: 미로 정보 g, 출발점 start, 도착점 end
# 출력: 미로를 나가기 위한 이동 경로는 문자열, 나갈 수 없는 미로면 물음표("?")

def solve_maze(g, start, end):
    qu = []       # 기억 장소 1: 앞으로 처리해야 할 이동 경로를 큐에 저장
    done = set()  # 기억 장소 2: 이미 큐에 추가한 꼭짓점들을 집합에 기록(중복 방지)

    qu.append(start)  # 출발점을 큐에 넣고 시작
    done.add(start)   # 집합에도 추가

    while qu:           # 큐에 처리할 경로가 남아 있으면
        p = qu.pop(0)   # 큐에서 처리 대상을 꺼냄
        v = p[-1]       # 큐에 저장된 이동 경로의 마지막 문자가 현재 처리해야 할 꼭짓점
        if v == end:    # 처리해야 할 꼭짓점이 도착점이면(목적지 도착!)
            return p    # 지금까지의 전체 이동 경로를 돌려주고 종료
        for x in g[v]:  # 대상 꼭짓점에 연결된 꼭짓점들 중에
            if x not in done:     # 아직 큐에 추가된 적이 없는 꼭짓점을
                qu.append(p + x)  # 이동 경로에 새 꼭짓점으로 추가하여 큐에 저장하고
                done.add(x)       # 집합에도 추가함

    # 탐색을 마칠 때까지 도착점이 나오지 않으면 나갈 수 없는 미로임
    return "?"

# 미로 정보
# 미로의 각 위치에 알파벳으로 이름을 지정
# 각 위치에서 한 번에 이동할 수 있는 모든 위치를 선으로 연결하여 그래프로 표현
maze = {
    'a': ['b','e'],
    'b': ['c'],
    'c': ['d'],
    'd': ['d'],
    'e': ['f', 'i'],
    'f': ['g'],
    'g': ['k', 'h'],
    'h': ['l'],
    'i': ['i'],
    'j': ['n'],
    'k': ['j'],
    'l': ['l'],
    'm': ['m'],
    'n': ['m', 'o'],
    'o': ['p'],
    'p': ['p']
}
print(solve_maze(maze, 'a', 'p'))


arr2 = [5,12,6,2,4,8]
n1 = len(arr2)

print(insertion(arr2, n1))
print(selectionsort(arr2, n1))
print(solve_maze(maze, 'a', 'p'))
print(array1())
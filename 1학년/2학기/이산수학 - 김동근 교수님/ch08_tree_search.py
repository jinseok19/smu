#이분탐색
def binsearch(a,x):
    start = 0
    end = len(a) -1
    while start<=end:
        mid = (start + end)//2
        if x ==a[mid]:
            return mid
        elif x > a[mid]:
            start = mid +1
        else:
            end = mid -1
    return -1
d = [2,4,5,16,21,34,48,56,72,82,90]
print(binsearch(d, 72)) 

#순차탐색
def searchlist(a,x):
    n = len(a)
    for i in range(0,n):
        if x==a[i]:
            return i;
    return -1
v = [16,4,99,21,15,34,7,33]
print(searchlist(v, 33))

graph = {
    'A':['B','C'],
    'B':['A','D'],
    'C':['A','G','H','I'],
    'D':['B','E','F'],
    'E':['D'],
    'F':['D'],
    'G':['C'],
    'H':['C'],
    'I':['C','J'],
    'J':['I']}

def my_dfs(graph, start):
    visited = list()
    need_visit = list()
    need_visit.append(start)
    while need_visit:
        node = need_visit.pop()
        if node not in visited:
            visited.append(node)
            need_visit.extend(graph[node])
    return visited

def my_bfs(graph, start):
    visited = list()
    need_visit = list()
    need_visit.append(start)
    while need_visit:
        node = need_visit.pop(0)
        if node not in visited:
            visited.append(node)
            need_visit.extend(graph[node])
    return visited
print("DFS",my_dfs(graph,'A'))
print("BFS",my_bfs(graph,'A'))
 



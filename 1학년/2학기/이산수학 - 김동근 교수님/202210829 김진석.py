def my_maze(g, start, end):
    qu =[]
    done = set()
    qu.append(start)
    done.add(start)
    while qu:
        p = qu.pop(0)
        v = p[-1]
        if v== end:
            return p
        for x in g[v]:
            if x not in done:
                qu.append(p + x)
                done.add(x)
    return "?"

maze = {
    'a': ['b'],
    'b': ['c'],
    'c': ['d','g'],
    'd': ['d'],
    'e': ['i'],
    'f' : ['e'],
    'g': ['f','k','h'],
    'l': ['l'],
    'h': ['l'],
    'i': ['j'],
    'j': ['n'],
    'k': ['k'],
    'm': ['m'],
    'n': ['m','o'],
    'o': ['p']


}

print(my_maze(maze, 'a','p'))
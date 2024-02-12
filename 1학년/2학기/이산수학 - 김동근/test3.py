def test_1():
    a = tuple(i for i in range(1,6))
    print(a)
    b = tuple(i for i in range(1,6))
    print(b)

    d = 1

    for i in a:
        for j in b:
            c = i*j
            if c % 2 ==0:
                print("{0}회 출력 {1}, {2} = 짝수".format(d, i, j))
                d = d+1
    print("관계 순서쌍의 개수 {0} 개".format(d-1))



def test_2():

    a = tuple(i for i in range(1,6))
    print(a)
    b = tuple(i for i in range(1,6))
    print(b)

    d = 1

    for i in a:
        for j in b:
            c = 2*i+j
            if c >=4 and c<10:
                print("{0}회 출력 {1}, {2} = {3}".format(d, i, j,c))
                d += 1
    print("관계 순서쌍의 개수 {0} 개".format(d-1))


test_2()
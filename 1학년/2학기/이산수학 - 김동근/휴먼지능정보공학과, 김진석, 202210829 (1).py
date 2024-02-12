def MyFac(n):
    if n==0:
        return 1

    return n * MyFac(n-1)

def MySet():

    A = set([1,2,3,4,5])
    B = set([1,3,5,7,9])



    inter = A & B
    union = A | B
    differ = A-B
    print("교집합: ",inter)
    print("교집합의 기수: ", len(inter))
    print("합집합: ",union)
    print("합집합의 기수: ", len(union))
    print("차집합: ",differ)
    print("차집합의 기수: ", len(differ))

def MyLogic():
    bool_p = [True,True,False,False]
    bool_q = [True,False,True,False]
    print("========================")
    print(" p^q -> p")
    for i in range(len(bool_p)):
        P = bool_p[i]
        Q = bool_q[i]
        NPandQ =not( P and Q)
        NPandQorP = NPandQ or P

        print("{0}".format(NPandQorP))
    print('모두 True 이므로 항진 명제')
    print("========================")
    print('q->(p->q)')
    for i in range(len(bool_p)):
        P = bool_p[i]
        Q = bool_q[i]

        NQ = not Q
        NPorQ = not P or Q
        NQorNPorQ = NQ or NPorQ
        print("{0}".format(NQorNPorQ))
    print('모두 True 이므로 항진 명제')
def A():
    a=tuple(i for i in range(1,6))

    print('집합 R')
    for i in a:
        for j in a:
            c = 2*i^2 - j
            if c>=4:
                
                print('({0},{1})'.format(i, j), end= '')             
   

print(MyFac(10))
MySet()
MyLogic()
A()
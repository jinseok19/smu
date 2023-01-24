# p -> q
p = [True, True, True,True, False, False, False, False]
q = [True,True, False, False, True, True, False, False]
r = [True, False, True, False, True, False, True,False]

for i in range(len(p)):
    P = p[i]
    Q = q[i]
    R = r[i]

    PornotR = P or (not(R))
    notPorQ = not(P) or Q

    PornotRandnotPorQ = PornotR and notPorQ

    print(PornotRandnotPorQ)

    notPandQ = not(P and Q)
    


# def my_hanoi(n, from_post, to_post, aux_post):
    # if n==1: #원반 한 개를 옮기다면 (옮기는 원반이 한 개 라면)
    #     print(from_post, "---->", to_post) # 바로 옮기면 됨
    #     return
    # #원반 n-1개를 보조기둥으로 이동한다 (즉 to_post를 보조 기둥으로 한다)
    # my_hanoi(n-1, from_post, aux_post, to_post)
    # #가장 큰 원반을 목적지로 이동한다
    # print(from_post,"---->",to_post)
    # #보조 기둥에 있는 원반 n-1개를 목적지로 이동한다(즉, from_post를 보조 기둥으로 한다)
    # my_hanoi(n-1,aux_post, to_post, from_post)


# def hanoi_test():
    # num = input("원반의 개수를 입력하세요")
    # print("원반의 개수",num)
    # my_hanoi(int(num),1,3,2)
        
# hanoi_test()
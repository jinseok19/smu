import operator

def ch02_exam1():
    bool_p = [True,True,False,False]
    bool_q = [True,False,True,False]
    print("========================")
    print("p\t q\t p^q")
    for i in range(len(bool_p)):
        P = bool_p[i]
        Q = bool_q[i]
        PandQ = P and Q
        print("{0}\t {1}\t {2} ".format(P,Q,PandQ))
        print("========================")
        print("p\t q\t pvq")
    for i in range(len(bool_p)):
        P = bool_p[i]
        Q = bool_q[i]
        PorQ = P or Q
        print("{0}\t {1}\t {2} ".format(P,Q,PorQ))
        print("========================")
        print("p\t q\t p+q")
    for i in range(len(bool_p)):
        P = bool_p[i]
        Q = bool_q[i]
        PxorQ = operator.xor(P,Q)
        print("{0}\t {1}\t {2} ".format(P,Q,PxorQ))
ch02_exam1()

def ch02_exam2():
    bool_p = [True,True,True,True,False,False,False,False]
    bool_q = [True,True,False,False,True,True,False,False]
    bool_r = [True,False,True,False,True,False,True,False]
    print("========================")
    print("p\t q\t r\t ~(p^q)\t\t (q v r)\t ~(p^q) v (q v r)")
    for i in range(len(bool_p)):
        P = bool_p[i]
        Q = bool_q[i]
        R = bool_r[i]
        notPandQ = not(P and Q)
        QorR = Q or R
        notPandQorQorR = notPandQ or QorR
        print("{0}\t {1}\t {2}\t {3}\t\t {4}\t\t{5}\t\t".format(P,Q,R,notPandQ,QorR,notPandQorQorR))
ch02_exam2()


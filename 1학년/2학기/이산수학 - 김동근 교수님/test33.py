def maxnum(a,b,c):
    x = a
    if (b> x):
        x= b
    elif (c> x):
        x= c
    print(x)
maxnum(1,2,3)


def A():
    i =0
    while(i<=20):
        x = 1
        x +=1
        if(i< 20):
            x = 10
        else:
            x = 0
        i +=2
    print(i,x)

A()


def gcd(a, b):
    if (a< b):
        tmp =a 
        a = b
        b = tmp

    while (b !=0):
        r = a% b
        a = b
        b= r
    return a

print(gcd(2, 8))
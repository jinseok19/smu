print("두 수를 입력 하세요")
a,b = map(int,input().split())
print("연산자를 입력하세요")
c = input()

if c=="+":
    d = a+b
elif c=="-":
    d = a-b
elif c=="*":
    d = a*b
elif c=="/":
    d= a/b
print(d)

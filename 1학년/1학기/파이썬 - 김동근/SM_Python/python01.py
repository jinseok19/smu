

def r():   
    a = input("묵 찌 빠 중 하나를 내주세요.종료하시려면 엔터를 눌러주세요:")
    if a=="묵":
        print("묵")
        r()
    
    elif a=="찌":
        print("찌")
        r()
    elif a=="빠":
        print("빠")
        r()
    elif a=="":
        print("종료")
        return
    
    else:
        print("오류")
        r()
    
    
r()


       
def exam1():
    name = input("이름을 입력하세요")
    print("안녕하세요",name,"님 반갑습니다")
    
   

def exam2():
#두 수를 입력받는다
    a = int(input("첫번째 숫자"))
    b = int(input("두번째 숫자"))

#연산을 수행한다
    hap = a+b
    cha = a-b
    gop = a*b
    bun = a/b

#결과를 출력한다
    print(a,"+",b,"=",hap)
    print(a,"-",b,"=",cha)
    print(a,"*",b,"=",gop)
    print(a,"/",b,"=",bun)

exam1()
exam2()

   
    
    

        
    







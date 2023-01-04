import time
import random
from datetime import datetime 


def TimeCheck():
    ## TimeCheck 함수를 수정하지 말아주세요
    ## 함수 호출 시간을 출력합니다
    now = datetime.now()
    print("\n")
    print("실행일자:{0}\t실행시간{1}".format(now.date(),now.time()))
    print("\n")

    
def DisplayMenu():
    print("==========================파이썬 2분반 중간고사===========================")
    print("== 1.나이계산(5점)\t 2.사칙연산(10점)\t 3.가로구구단계산(10점)\t==")
    print("== 4.주사위게임(15점)\t 5.타이머게임(15점)\t 6.묵찌빠게임(20점)\t==")
    print("== 7.윷놀이게임(20점)\t 8.전체실행(5점)\t 9.전체종료\t\t==")
    print("==========================================================================")
    
def GetMenu():
    num = int(input("실행할 문제 번호를 입력하세요"))
    return num
              
def exam1(): #나이계산
    print("exam1-나이계산") ## 출력문은 수정하지 마세요

    ## 1) 사용자에게 각각 이름,학과, 학번, 출생연도를 입력받고
    ## 2) "안녕하세요 OO학과 OOO님 반갑습니다. 당신은 OOOO년에 출생하여 현재 OO세 입니다"라는 메시지를
    ## 3) 화면에 출력
    
    
    ## 출력결과
    ## 이름:상명
    ## 학과:휴먼지능정보공학
    ## 학번:123456
    ## 출생연도:2003
    ## 안녕하세요 휴먼지능정보공학과 상명님 반갑습니다. 당신은 2003년에 출생하여 현재 2O세 입니다
    
    
    

    ## 
    # 여기부터 코딩 !! ##
    ## 
    name = input("이름:")
    department = input("학과:")
    num = int(input("학번:"))
    year = int(input("출생년도:"))
    age = 2023-year
    print("안녕하세요 {0} {1}님 반갑습니다. 당신은 {2}년에 출생하여 현재 {3}세 입니다".format(department,name,year,age))
    
    TimeCheck() ## TimeCheck 함수 호출을 변경하지 말아주세요
        
def exam2(): 
    print("exam2-사칙연산") ## 출력문은 수정하지 마세요

    ## 1) 사용자에게 두 개의 숫자와 사칙연산자를 입력받고
    ## 2) 사칙연산자에 따라 각각 덧셈, 곱셈, 뺄셈, 나눗셈을 수행하고
    ## 3) 사칙연산 결과를 아래와 같이 화면에 출력
    
    ## 출력결과
    ## 첫번째 숫자:1
    ## 두번째 숫자:2
    ## 연산자:+
    ## 연산결과:1+2=3
    

    ## 
    # 여기부터 코딩 !! ##
    ## 
    a = int(input("첫번째 숫자:"))
    b = int(input("두번째 숫자:"))
    c = input("연산자:")

    if c=="+":
        d = a+b
    elif c=="-":
        d = a-b
    elif c=="*":
        d = a*b
    elif c=="/":
        d= a/b
    print("연산결과:{0}{1}{2}={3}".format(a,c,b,d))

    TimeCheck() ## TimeCheck 함수 호출을 변경하지 말아주세요
    
    
def exam3():
    print("exam3-가로구구단계산") ## 출력문은 수정하지 마세요
    ## 1) 사용자에게 시작 구구단 값과 종료 구구단 값을 입력받아
    ## 2) 구구단 연산을 수행하고
    ## 3) 구구단 연산 결과를 가로로 화면에 출력
    
    ## 출력결과
    ## 시작구구단:3
    ## 종료구구단:4
    ## 3x1=3    4x1=4
    ## 3x2=6    4x2=8
    ## ...
    ## 3x9=27   4x9=36


    ## 
    # 여기부터 코딩 !! ##
    ##
    start_gugudan = int(input("시작구구단:"))
    end_gugudan = int(input("종료구구단:"))

    def gugudan(a, b):

        for i in range(1, 10):
            for j in range(a, b+1):
                k = i*j
                print('{0}x{1}={2}'.format(j, i, k),end = '\t')
            print()
        return


    gugudan(start_gugudan, end_gugudan)
    
    TimeCheck() ## TimeCheck 함수 호출을 변경하지 말아주세요
    

def exam4():
    print("exam4-주사위게임") ## 출력문은 수정하지 마세요
    ## 1) 무작위로 주사위를 5번 굴려서 나온 주사위 눈의 결과를 출력하고
    ## 2) 주사위 눈의 합의 계산하여 출력하고
    ## 3) 주사위 눈의 합이 홀수이면 홀수라고 출력하고
    ## 3) 주사위 눈의 합이 짝수이면 짝수라고 출력
        
    ## 출력결과
    ## 1번째 주사위:1
    ## 2번째 주사위:2
    ## 3번째 주사위:3
    ## 4번째 주사위:4
    ## 5번째 주사위:5
    ## 주사위 합:15
    ## 주사위 합은 홀수

    ## 
    # 여기부터 코딩 !! ##
    ## 
    sum = 0
    for i in range(1,6):

        RandomNum = random.randint(1, 6)
        print("{0}번째 주사위:{1}".format(i,RandomNum))
        sum += RandomNum

    print("주사위 합:{0}".format(sum))
    if sum %2 == 0:
      print("주사위 합은 짝수")
    else:
      print("주사위 합은 홀수")
  
    TimeCheck() ## TimeCheck 함수 호출을 변경하지 말아주세요

def exam5():
    print("exam5-타이머게임") ## 출력문은 수정하지 마세요

    ## 1) 사용자로부터 타이머 설정시간(초)를 입력받고
    ## 2) 사용자가 엔터를 누르면 타이머가 시작되고
    ## 3) 사용자가 다시 엔터를 누르면 타이머가 종료되고
    ## 4) 사용자가 입력한 타이머 설정시간과 타이머 실제 동작 시간을 출력하고
    ## 5) 타이머 설정시간과 실제 동작 시간을 비교하여
    ## 5) 타이머 동작시간이 일치하면 카운트 맞추기 성공
    ## 5) 타이머 동작시간이 불일치하면 카운트 맞추기 실패라고 출력
    
        
    ## 출력결과
    ## 타이머설정시간(초):3
    ## 엔터를 누르면 타이머 시작
    ## 타이머 시작됨    
    ## 엔터를 누르면 타이머 종료
    ## 타이머 종료됨
    ## 타이머 실제 동작시간:3초
    ## 타이머 카운트 맞추기 성공!!
    
    
    ## 
    # 여기부터 코딩 !! ##
    ##
    SetTime = int(input("타이머설정시간(초):"))

    Start = input("엔터를 누르면 타이머 시작")
    Start_time = time.time()
    print("타이머 시작됨")

    End = input("엔터를 누르면 타이머 종료")
    End_time = time.time()
    print("타이머 종료됨")

    Result = round(End_time-Start_time)


    print("타이머 실제 동작시간:{0}초".format(Result))

    if Result == SetTime:
        print("타이머 카운트 맞추기 성공!!")
    else:
        print("타이머 카운트 맞추기 실패!!")
    TimeCheck() ## TimeCheck 함수 호출을 변경하지 말아주세요

    
def exam6():
    print("exam6-묵찌빠게임") ## 출력문은 수정하지 마세요
    ## 1) 사용자로부터 묵, 찌, 빠 중 하나를 입력받고
    ## 2) 컴퓨터는 무작위로 묵, 찌, 빠 중 하나를 생성하고
    ## 3) 사용자와 컴퓨터의 묵찌빠 승패 결과를 비교하여 출력
    ## 4) 사용자에게 게임의 계속 실행 여부를 입력받아
    ## 5) 계속하는 경우 1,2,3번을 재실행하고
    ## 6) 종료하는 경우 게임을 종료
    
            
    ## 출력결과
    ## 묵,찌,빠중 하나를 입력(사용자):묵
    ## 묵,찌,빠중 하나를 생성(컴퓨터):찌
    ## 사용자가 이김
    ## 게임계속(y/n)?y
    ## 묵,찌,빠중 하나를 입력(사용자):묵
    ## 묵,찌,빠중 하나를 생성(컴퓨터):묵
    ## 서로 비김
    ## 게임계속(y/n)?n
    ## 게임종료
     
    
    
    
    ## 
    # 여기부터 코딩 !! ##
    ##
    def playrsp():  
        user = input("묵,찌,빠중 하나를 입력(사용자):")
        Ai = random.randint(1, 3)
        if Ai == 1:
            RAi = "묵"
        elif Ai == 2:
            RAi = "찌"
        else:
            RAi = "빠"
        print("묵,찌,빠중 하나를 생성(컴퓨터):{0}".format(RAi))

        if user == RAi:
            print("서로 비김")
        elif user == "찌" and RAi == "묵":
            print("컴퓨터가 이김")
        elif user == "묵" and RAi == "빠":
            print("컴퓨터가 이김")
        elif user == "빠" and RAi == "찌":
            print("컴퓨터가 이김")
        else:
            print("사용자가 이김")
            
        answer = input("게임계속(y/n)?")
        if answer == "y":
              playrsp()
        else:
            print("게임종료")
    playrsp()
    TimeCheck() ## TimeCheck 함수 호출을 변경하지 말아주세요

    

def exam7():
    print("exam7-윷놀이게임") ## 출력문은 수정하지 마세요
    ## 1) 사용자가 도,개,걸,윷,모 중 하나를 입력하고
    ## 2) 컴퓨터가 도,개,걸,윷,모 중 무작위로 하나를 생성하고 
    ## 3) 각각 사용자와 컴퓨터가 입력한 윷의 결과에 따라 말의 이동 칸수를 출력
    ## 4) 사용자에게 게임의 계속 실행 여부를 입력받아
    ## 5) 계속하는 경우 1,2,3번을 재실행하고
    ## 6) 종료하는 경우 게임을 종료
    ## 단, 리스트를 활용
    
            
    ## 출력결과
    ## 도,개,걸,윷,모 중 하나를 입력(사용자):도
    ## 도,개,걸,윷,모 중 하나를 생성(컴퓨터):걸
    ## 사용자 1칸 이동
    ## 컴퓨터 3칸 이동
    ## 게임계속(y/n)?y
    ## 도,개,걸,윷,모 중 하나를 입력(사용자):도
    ## 도,개,걸,윷,모 중 하나를 생성(컴퓨터):개
    ## 사용자 1칸 이동
    ## 컴퓨터 2칸 이동
    ## 게임계속(y/n)?n
    ## 게임종료
            
    
    ## 
    # 여기부터 코딩 !! ##
    ## 

  
    def yut():
        yuts = ["도","개","걸","윷","모"]  
        yut_user = input("도,개,걸,윷,모 중 하나를 입력(사용자):")
        yut_Ai = random.choice(yuts)
        if yut_Ai == "도":
            yAI = 1
        elif yut_Ai == "개":
            yAI = 2
        elif yut_Ai == "걸":
            yAI = 3
        elif yut_Ai == "윷":
            yAI = 4
        else:
            yAI = 5
        print("도,개,걸,윷,모, 중 하나를 생성(컴퓨터):{0}".format(yut_Ai))

        if yut_user == "도":
          print("사용자 1칸 이동")
        elif yut_user == "개":
          print("사용자 2칸 이동")
        elif yut_user =="걸":
          print("사용자 3칸 이동")
        elif yut_user =="윷":
          print("사용자 4칸 이동")
        else:
          print("사용자 5칸 이동")
        
        print("컴퓨터 {0}칸 이동".format(yAI))
            
        answer = input("게임계속(y/n)?")
        if answer == "y":
              yut()
        else:
            print("게임종료")
    yut()

    TimeCheck() ## TimeCheck 함수 호출을 변경하지 말아주세요
    
def exam8():
    print("exma9-전체실행") ## 출력문은 수정하지 마세요
    ## 1) 중간고사 문제 exam1~8번까지 차례대로 실행
    
    ## 
    # 여기부터 코딩 !! ##
    ## 
    exam1()
    exam2()
    exam3()
    exam4()
    exam5()
    exam6()
    exam7()
    
    TimeCheck() ## TimeCheck 함수 호출을 변경하지 말아주세요

      

def MidTerm():
    ## 아래 3개의 함수 호출은 변경하지 마시고
    ## 1) 사용자로부터 문제 번호를 입력받아 해당 함수를 호출하는 방식으로 코딩
    ## 2) 한 개 문제 실행이 종료되면 사용자에게 다음 실행할 문제 번호를 다시 입력받음
    ## 3) 사용자로부터 전체종료 9를 입력받으면 실행 종료

    
    TimeCheck()
    DisplayMenu()

        
    ## 
    # 여기부터 코딩 !! ##
    ## 

  
    while True:
        num = GetMenu()
        if num==9:
           print("전체종료합니다")
           break

        elif num==1:
            exam1()
        elif num==2:
            exam2()
        elif num==3:
            exam3()
        elif num==4:
            exam4()
        elif num==5:
            exam5()
        elif num==6:
            exam6()
        elif num==7:
            exam7()
        elif num==8:
            exam8()
        
       

MidTerm()

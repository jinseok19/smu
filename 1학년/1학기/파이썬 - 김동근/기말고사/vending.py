#python 자판기 version 0519
import datetime
import random
Beverage = {"사이다":[600,20,"칠성"],"캔커피":[800,20,"레쓰비"],"생수":[500,20,"삼다수"],"이온음료":[1000,20,"포카리"]}

balance = 5000
  
def DisplayMenu():
    print("==============상명 파이썬 자판기===================")
    print("\n")
    print("1. 메뉴보기")
    print("2. 제고현황")
    print("3. 음료 판매")
    print("4. 영수증출력")
    print("5. 종료하기")
    print("\n")
    print("---------------------------------------------------")
    print("현재잔고는 {0} 원".format(balance))
    print("===================================================")


def Menu1():
    print("******상명 파이썬 자판기 메뉴******")
    for k in Beverage:
        print("음로:{0}\t재고:{1}원".format(k,Beverage[k][0]))

def Menu2():
    print("******음료 재고 현황******")
    for k in Beverage:
        print("음로:{0}\t재고:{1}개".format(k,Beverage[k][1]))
def Menu3():
    money = int(input("투입금액을 입력하세요"))
    print("사용자가 {0}원 투입했습니다".format(money))
    select = input("음료를 선택하세요")

    if select in Beverage: #메뉴 유무 판별
        print("{0}가 메뉴에 있습니다.".format(select))
        select_count = int(input("수량을 선택하세요"))
        Beverage[select][1] -= select_count #남은 수량 구하기
        print("{0}음료 재고가 {1}개 남았습니다.".format(select,Beverage[select][1]))
        print("------------------------------------")
        Menu2()
        print("------------------------------------")
        print("사용자가 {0}를 {1}개 선택했습니다".format(select,select_count))
        print("총액은 {0}원 입니다".format(Beverage[select][0]*select_count))
        if Beverage[select][0]*select_count > money:
            print("돈이 부족합니다")
            Menu3()

        else:    
            return_money = money-(Beverage[select][0]*select_count) # 잔돈 구하기
            print("거스름돈은 {0}원 입니다".format(return_money))
            global balance
            balance += Beverage[select][0]*select_count# 잔고 구하기
            print("현재 잔고는 {0}원 입니다".format(balance))
            print("이용해주셔서 감사합니다!!!")
            
            result_log = [select,select_count,money,Beverage[select][0],return_money]
            print(result_log)
            return result_log
    else:
        print("{0}가 메뉴에 없습니다".format(select))
    


def Menu4():
    print("------영수증------")
    now_time = datetime.datetime.now()
    print("판매시간:{0}".format(now_time.strftime("%Y/%m/%d %H:%M:%S")))
    
    #print("음료이름 {0}".format(t))
    # print("음료수량 {0}".format())
    # print("음료금액 {0}".format())
    # print("총액 {0}".format())
    # print("잔액(거스름돈) {0}".format())
    ok_num_check = []
    ok_num = []
    while True:
        for _ in range(0,4):
            rand_num = random.randint(0,9)
            ok_num.append(rand_num)
        if ok_num not in ok_num_check: # 이미 생성한 인증번호가 있는지 확인
            ok_num_check.append(ok_num)
            result_ok = ''.join(map(str, ok_num))
            print("승인번호: {0}".format(result_ok))
            break

    
def Menu5():
    print("menu 5")


def VendingMachine():
    DisplayMenu()
    num = int(input("메뉴선택"))
    if num ==1:
        Menu1()
    elif num ==2:
        Menu2()
    elif num ==3:
        Menu3()
    elif num ==4:
        Menu4()
    elif num ==5:
        Menu5()
    

VendingMachine()
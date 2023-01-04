import random
import time


def SelectGame():
    num = int(input("게임번호를 입력하세요:"))

    return num


def DisplayMenu():

    print("==============================================================상명 오락실================================================================================")
    print("\t 1. 주사위게임 \t 2.타이머 게임 \t 3. 가위바위보 게임 \t  4. 윷놀이 \t 5. 카드게임 \t 6. 주사위 게임2 \t 0. 게임 종료")
    print("========================================================================================================================================================")


def PlayDice():
    print("주사위 게임 시작")

    count1 = int(input("주사위를 던질 횟수를 입력하세요:"))
    sum = 0
    for i in range(count1):

        RandomNum = random.randint(1, 6)
        print("던진 주사위 눈", RandomNum)
        sum += RandomNum

    print("주사위의 총 합 : {0}".format(sum))

    if sum >= 10:
        print("100점")
    elif sum >= 5:
        print("50점")
    else:
        print("0점")


def PlayTimer():
    print("타이머 게임을 시작합니다.")
    SetTime = int(input("카운트할 시간(초)를 입력하세요:"))

    Start = input("엔터를 누르면 타이머를 시작합니다.")
    Start_time = time.time()

    End = input("엔터를 누르면 타이머를 종료합니다.")
    End_time = time.time()

    Result = End_time-Start_time
    RResult = round(Result)

    print("끝난 시간: {0}".format(Result))
    print("끝난 시간:{0}".format(RResult))
    if RResult == SetTime:
        print("100점")
    else:
        print("0점")


def PlayRSP():
    print("가위바위보 게임을 시작합니다.")

    user = input("가위바위보중 하나를 입력하세요 :")

    Ai = random.randint(1, 3)
    if Ai == 1:
        RAi = "가위"
    elif Ai == 2:
        RAi = "바위"
    else:
        RAi = "보"

    print("사용자는 {0}을 냈습니다.".format(user))
    print("Ai는 {0}을 냈습니다.".format(RAi))

    RSP(user, RAi)


def RSP(user, RAi):
    if user == RAi:
        print("=================AI 승리=====================")
    elif user == "가위" and RAi == "바위":
        print("=================AI 승리=====================")
    elif user == "바위" and RAi == "보":
        print("=================AI 승리=====================")
    elif user == "보" and RAi == "가위":
        print("=================AI 승리=====================")
    else:
        print("====================User 승리=====================")


def backdo():
    backls = ["도", "빽도"]
    backdo_1 = random.choice(backls)

    return backdo_1


def PlayYut():
    print("윷놀이 게임을 시작합니다.")
    playcount = 0
    count = 0
    while True:
        y = input("계속할려면 y입력하세요 그만 하실려면 n을 누르세요")
        if y == 'y':
            playcount += 1

            yuts = []

            for i in range(1, 5, 1):
                yut = random.randint(0, 1)
                yuts.append(yut)

            yutCount = yuts.count(1)

            if yutCount == 0:
                count += 1
                print("윷")
            elif yutCount == 1:
                print(backdo())
            elif yutCount == 2:
                print("개")
            elif yutCount == 3:
                print("걸")
            elif yutCount == 4:
                print("모")
            else:
              print(playcount, '번 던졌습니다. 윷은', count, '번 나왔습니다.')
              break


def PlayCard():
    print("카드게임을 시작합니다.")
    card_color = ["Red", "Black"]
    card_num = ["2", "3", "4", "5","6","7","8","9","10","J","Q","K","A"]
    red_shape = ["하트(♡)", "다이아몬드(◆)"]
    black_shape = ["스페이드(♠)", "클로버(♧)"]

    color = random.choice(card_color)
    print(color)
    num = random.choice(card_num)
    print(num)

    if color == "Black":
        bshape = random.choice(black_shape)
        print("당신이 뽑은 카드는", color, num, bshape,"입니다.")
    else:
        rshape = random.choice(red_shape)
        print("당신이 뽑은 카드는", color, num, rshape,"입니다.")


def dice2(player):
      playersum = 0
      for i in range(1, 6, 1):
            dice22 = random.randint(1, 6)
            playersum += dice22
      player.append(playersum)


def dicegame2():
    com = []
    hum = []
    while True:
      dice2(com)
      dice2(hum)
      if 20 in com:
        print("컴퓨터 승리")
        break
      elif 20 in com and 20 in hum:
        print("무승부 입니다.")
        break
      elif 20 in hum:
        print("플레이어 승리")
        break


def Meue():

    DisplayMenu()
    while True:
        num = SelectGame()
        print(num, "을 선택하셨습니다!!")

        if num == 1:
            PlayDice()
            DisplayMenu()

        elif num == 2:
            PlayTimer()
            DisplayMenu()
        elif num == 3:
            PlayRSP()
            DisplayMenu()
        elif num == 4:
            PlayYut()
            DisplayMenu()
        elif num == 5:
            PlayCard()
            DisplayMenu()
        elif num == 6:
            dicegame2()
            DisplayMenu()
        elif num == 0:
            print("게임을 종료합니다.")
            break
        else:
            print("잘못입력하셨습니다.")
            return


Meue()


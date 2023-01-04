'''
인덱스
-> 변수 값의 주소를 가지고 있음.

+ : 결합, 연결 연산자
* : 반복 연산자

조건은 반복문 또는 불연산 할때 사용함.
리스트 : 순서가 있고 수정 가능한 데이터의 집합

del : 리스트의 요소를 지우는 연산자(메소드)

append() : 맨 마지막에 요소를 추가하는 함수

reverse() : 요소들을 반전 시킴.

insert(index, 요소)

remove(요소)

pop() : 인덱스 마직막 요소 꺼내기(스택 구조 LIFO)| 자료구조 : 스택, 큐

extend() : 맨 뒤에 추가함.

find() : 문자열 객체가 가지고 있는 함수




a = '상명대'

print(a[:1])


a.rfind()
b = [4,1,2,3]
b.remove()

b.pop()
b.count()
b.extend()



treaser_box = [1,2,"보","물","보물","1","2","물보","보물"," 보물",['보','물'],"보물"]

find_box = treaser_box.index("보물")


print(find_box)


import random
def backdo():
    backls = ["도","빽도"]
    backdo_1 = random.choice(backls)

    return backdo_1


yuts =[]

for i in range(1,5,1):
    yut = random.randint(0,1)
    yuts.append(yut)

yutCount = yuts.count(1)

if yutCount ==0:
    print("윷")
elif yutCount ==1:
    print(backdo())
elif yutCount ==2:
    print("개")
elif yutCount ==3:
    print("걸")
elif yutCount ==4:
    print("모")

def yutresult():
    result =[]


'''

'''if yuts[0] ==1 and yuts[1]==yuts[2]==yuts[3]==0:
    print("도")
elif yuts[0]==yuts[1] ==1 and yuts[2] ==yuts[3]==0:
    print("개")
elif yuts[0]==yuts[1] == yuts[2] ==1 and yuts[3]==0:
    print("걸")
elif yuts[0]==yuts[1] == yuts[2] == yuts[3]==1:
    print("모")
else :
    print("윷")
'''
import random

def dice2(player):
        playersum =0
        for i in range(1,6,1):
            dice22 = random.randint(1,6)
            playersum +=dice22
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
        
dicegame2()

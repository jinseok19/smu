import turtle #turtle 모듈을  불러옴

import random #random 모듈을  불러옴 

for i in range(10): # 영역에 포함된 코드를 10번 반복함. ** 밑의 반복문이 끝났을 때 1씩 증가하며 반복함.
    for j in range(5): # 영역에 포함된 코드를 5번 반복함.
        
        col = random.randint(0,3) # col 변수에 random  모듈의 randint 함수를 사용해 0부터 3까지의 정수 중 하나를 무작위로 추출해 저장함. (1)
        if (0== col): # col 변수의 값이 0 이면 선 색을 노란색으로 지정함.
            turtle.pencolor("yellow")
        elif (1==col): # col 변수의 값이 1이면 선 색을 파란색으로 지정함.
            turtle.pencolor("blue")
        elif (2==col): # col 변수의 값이 2이면 선 색을 빨간색으로 지정함.
            turtle.pencolor("red")
        elif (3==col): # col 변수의 값이 3이면 선 색을 초록색으로 지정함.
            turtle.pencolor("green")

        col = random.randint(0,4) # 다시 col 변수에 0부터 4까지의 정수 중 하나를 무작위로 추출해 저장함. (2)
        if(0==col): # col 변수의 값이 0 이면 색상을 빨간색으로 지정함.
            turtle.color('red')
        elif(1==col): # col 변수의 값이 1 이면 색상을 파란색으로 지정함.
            turtle.color('blue')
        elif(2==col): # col 변수의 값이 2 이면 색상을 초록색으로  지정함.
            turtle.color('green')
        elif(3==col): # col 변수의 값이 3 이면 색상을 보라색으로 지정함.
            turtle.color('purple')
        elif(4==col): # col 변수의 값이 4 이면 색상을 노란색으로 지정함.
            turtle.color('yellow')

        sel = random.randint(0,4) # sel 변수에 0부터 4까지의 정수 중 하나를 무작위로 추출해 저장함. (3)
        if (0==sel): # sel 변수의 값이 0 이면 (1)에서 선택된 선 색으로 50부터 100까지의 정수 중 무작위로 값을 추출해 화살표 방향으로 추출값 만큼 픽셀 움직임.
            turtle.forward(random.randint(50,100))
        elif(1==sel): # sel 변수의 값이 1이면 90 부터 360까지의 정수 중 무작위로 값을 추출해 그 값만큼 시계 방향으로 회전함.
            turtle.right(random.randint(90,360))
        elif (2==sel): # sel 변수의 값이 2이면 -100 부터 -20의 정수 중 무작위로 값을 추출해 원을 그리고 (2)에서 선택된 색상으로 모든 폐쇠된 영역을 채우고 end_fill()함수를 이용해 이후에 만들어지는 원은 영역을 채우지 않게 함.
            turtle.begin_fill()
            turtle.circle(random.randint(-100,-20))
            turtle.end_fill()
        elif(3==sel): # sel 변수의 값이 3이면 30부터 50까지의 정수 중 무작위로 값을 추출해 화살표 방향으로 추출값 만큼 픽셀 움직임.
            turtle.forward(random.randint(30,50))
        elif(4==sel): # sel 변수의 값이 4이면 20부터 100까지의 정수 중 무작위로 값을 추출해 원을 그림.
            turtle.circle(random.randint(20,100))

    a = float(random.randint(-300,300)) # 변수 a에 실수 형식으로 -300 부터 300까지의 값중 하나를 무작위로 추출해 저장함.
    b = float(random.randint(-300,300)) # 변수 b에 실수 형식으로 -300 부터 300까지의 값중 하나를 무작위로 추출해 저장함.
    turtle.goto(a,b) # 화살표의 좌표를 a,b  값으로 이동함.
    

        
            

import random

  
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
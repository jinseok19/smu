# class 단계 클레스는 자료형이다
#1. 생성
#2. 호출
#3. 활용
class Car:
    #데이터(필드)
    car_number = ''
    car_color = ''
    car_speed = 0

    #함수(메소드)
    def speed_up(self, pedal_value): # 함수의 자기 자신을 메게변수로 선언하는 것이 규칙
        self.car_speed += pedal_value
        print("자동차 속도는 {0}입니다".format(self.car_speed))
        
    def check_car_clor(self):
        
        print("자동차는 {0}색 입니다".format(self.car_color))
    
    def number(self):
        print("자동차 번호는 {0}입니다".format(self.car_number))

# 식별
# 인스턴스로 식별
# myCar_first = 인스턴스
myCar_first = Car() # 객체 인스턴스 ,객체  
myCar_first.car_number = '1234'
myCar_first.speed_up(10)
color = input("자동차 색상을 입력하세요:")
myCar_first.car_color = color
myCar_first.check_car_clor()
myCar_first.number()

# myCar_second = 인스턴스
myCar_second = Car()
myCar_second.car_number = '5678'
myCar_second.speed_up(20)
color = input("자동차 색상을 입력하세요:")
myCar_second.car_color = color
myCar_second.check_car_clor()
myCar_second.number()









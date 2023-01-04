def MyAge(year):
    age = 2022 - year

    return age
    
def test():
    name = input("이름입력")
    year = int(input("년도입력"))

    ##
    age = MyAge(year)
    #age = 2022 - year

    print(name,"의 나이는", age,"세 입니다")

test()

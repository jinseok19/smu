#나라이름으로 수도 구하기

city_country = {"한국" : "서울", "그리스" : "아테네", "프랑스" : "파리", "미국" : "워싱턴", "영국" : "런던"}

def DisplayMenu():
    print("======국가별 수도 찾기 v01.1 ================")
    #exam1()
    #exam2()
    exam3()

def exam1():
    city = input("국가 이름을 입력해주세요 : ")
    if city in city_country.keys():
        print("수도는 :", city_country.get(city))
    elif city not in city_country.keys():
        print("없음")
        return

def exam2():
    add_city, add_value = map(str,input("추가할 국가와 수도를 입력해주세요 : ").split())
    city_country[add_city] = add_value
    if add_city in city_country.keys():
        print("정상적으로 추가되었습니다.")
        print(city_country)
    else:
        print("추가를 실패했습니다.")

def exam3():
    print("번호 \t 국가 \t 수도")
    print("------------------------")

    city_num = 1
    for k in city_country:
        print(city_num, "\t", k, "\t", city_country.get(k))
        city_num += 1

    print("------------------------")
DisplayMenu()
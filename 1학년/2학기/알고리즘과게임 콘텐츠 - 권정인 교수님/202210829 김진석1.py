def bubble_Asort(data):


    for i in range(len(data)-1,0,-1):

        for j in range(0,i,1):

            if data[j] > data[j+1]: #  ASC  : >   //// DESC : < 

                data[j], data[j+1] = data[j+1], data[j]

        print(len(data)-i,"번째 : ",  data)
    print("\n 정렬 후 A데이터 : ", data)

    

def bubble_Dsort(data):


    for i in range(len(data)-1,0,-1):

        for j in range(0,i,1):

            if data[j] < data[j+1]: #  ASC  : >   //// DESC : < 

                data[j], data[j+1] = data[j+1], data[j]

        print(len(data)-i,"번째 : ",  data)
    print("\n 정렬 후 D데이터 : ", data)




data = []

n=int(input("몇개 데이터 만들까요?"))

for i in range(0,n,1):
    
    num=int(input("숫자 입력 : "))
    data.append(num)

print("정렬 전 데이터 : ",data)

grade = input("정렬 방식 A or D : ")


if grade == "D" or grade == "d":
    
    bubble_Dsort(data)

elif grade == "A" or grade=="a":
    
    bubble_Asort(data)
else:
    print('정렬 방식 다시 선택')
    




















    

n = int(input("몇개의 숫자를 입력하겠습니까?"))
sort_list = []
for i in range(n):
    num = int(input("숫자를 입력하세요. :"))
    sort_list.append(num)

print("정렬전 데이터 :",   sort_list)

updown = input("정렬 방식 A or D :")

if updown == 'A' or updown =='a':

    for k in range(1, len(sort_list)):
        temp = sort_list[k]
        j=k-1

        while j>=0 and sort_list[j] > temp:
            sort_list[j+1] = sort_list[j]

            j=j-1

        sort_list[j+1] = temp
        print("%d 회전 %s"%(k, sort_list))
    print("정렬 후 데이터", sort_list)

elif updown == 'D' or updown =='d':

    for k in range(1, len(sort_list)):
        temp = sort_list[k]
        j=k-1

        while j>=0 and sort_list[j] < temp:
            sort_list[j+1] = sort_list[j]

            j=j-1

        sort_list[j+1] = temp
        print("%d 회전 %s"%(k, sort_list))
    print("정렬 후 데이터", sort_list)
    

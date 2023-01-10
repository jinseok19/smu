def binry_search(list_1,item):

    left = 0
    right = len(list_1)-1
    while left<=right:
        mid =(left + right) // 2
        if item == list_1[mid]:
            return 1
        elif item > list_1[mid]:
               left = mid +1
        else:
               right = mid -1
    return -1

            

    
students = [2022100,2022101,2022121,2022130,2022151,2022160,2022171]
num = int(input("출석 여부를 알고 싶은 응시번호 입력:"))

attend=binry_search(students,num)

if attend ==1:
    print("출석해서 시험본 학생입니다. 시험지 찾아보세요")
else:
    print("출석하지 않아서 시험지가 없습니다.")


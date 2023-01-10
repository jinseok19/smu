def search(use_name, stu_name, stu_height):
    result = "이름 없음, 다시 입력"
    
    for i in range(0, len(stu_name)):

        if use_name == stu_name[i]:

            return stu_height[i]
    return result

stu_name = ['미선','지연','성식','민석','지민','소현','정국']

stu_height = [150,165,170,177,168,158,163]

print(stu_name)

while True:
    use_name = input("학생 이름 입력 : ")

    if use_name =="end":
        break

    else:
        print(search(use_name, stu_name, stu_height))
        
    

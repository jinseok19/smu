a = int(input("성인 인원수: "))
y = int(input("청소년 인원수: "))
k = int(input("어린이 인원수: "))
total = 0
if a> 0 :
    total = a * 13000
    print("성인:" , a, end = " ")

if y> 0:
    total += (y * 11000)
    print("청소년:" , y,end = " ")

if k>0:
    print("어린이:",k,end = " ")
print("요금합계",total)


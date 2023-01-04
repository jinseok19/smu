'''
리스트 예제 1
사용자로부터 숫자를 입력받는다.
for문을 이용하여 1부터 입력받은 숫자 사이 중 홀수를 찾아서 리스트A에 저장하고 출력한다.
for문을 이용하여 1부터 입력받은 숫자 사이 중 짝수를 찾아서 리스트B에 저장하고 출력한다.
for문을 이용하여 1부터 입력받은 숫자까지 값을 리스트C에 저장하고 출력한다.

수도 찾기

'''

#num_1 = int(input())# int 형식으로 입력 받음
# list_a, list_b,list_c = [],[],[] # 리스트로 초기화

# for i in range(1,num_1+1): #1부터 입력한 값까지
#     list_c.append(i) # 각 리스트에 저장
#     if i%2==0: # 짝수 판별
#         list_b.append(i)
#     else: # 홀수 판별
#         list_a.append(i)

   

# print(list_a,list_b,list_c)

def FileTest2():
    inFile = None
    inString = ""
    inFile = open('김진석_202210829.txt','r', encoding= 'utf-8')
    
    
    while True:
        inString = inFile.readline()
        if inString =="":
            break
        print(inString, end = '')
    inFile.close()
    print()

FileTest2()


'''def my_gugudan(a,b):

    for i in range(a,b+1):
        
        print("{0}단".format(i))
        for j in range(1,10):
            print("{0} * {1} = {2}".format(i,j,i*j))
        print("")
    

'''
'''
for i in range(a,b+1,1):
    print("{0}단".format(i))
    for j in range(1,10):
        print("{0} * {1} = {2}".format(i,j,i*j))
    print("")
'''
'''

print('시작 구구단을 입력하세요')
a = int(input())
print('종료 구구단을 입력하세요')
b = int(input())

def gugudan(a, b):

    for i in range(1, 11):
        for j in range(a, b+1):
            print(j, 'x', i, '=', j*i, end='\t')
        print()
    return


gugudan(a, b)
'''





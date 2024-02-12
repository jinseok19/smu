dan = int(input('단 입력 :'))

updown = input('정렬 방식 A or D:')

if 'A' in updown or 'a' in updown:
    k = 1
    while(k<10):
        print('{0} 단 X  {1} = {2}'.format(dan, k, dan*k))
        k +=1
        
elif 'D' in updown or 'd' in updown:
    k = 9
    while(k>0):
        print('{0} 단 X  {1} = {2}'.format(dan, k, dan*k))
        k -=1
        
else:
    print('정렬 방식 다시 선택')

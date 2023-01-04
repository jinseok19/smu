import random


# Quiz 5.6
def passwd(length) :
    pw = str()
    chars = 'abcdefghijklmnopqrstuvwxyz' + '0123456789' + '!@#$%!^&*'

    for _ in range(1, length+1):
        pw = pw + random.choice(chars)
    return pw

print(passwd(8))

# Quiz 5.15

bigdata  = []
nodata =[]

for i in range(100):
    bigdata.append(random.randint(1,33))
print(bigdata)

nodata = [i for i in range(1,34) if i not in bigdata]

print('존재하지 않는 값(들):', nodata)


#for i in range(1,34):
   # if i not in bigdata:
        #.append(i)
        
#Quiz 5.16
#1
def times2(c):
      for i in range(0,len(c)):
        c[i] = c[i]*2
      print(c)

nums = [1,2,3]
times2(nums)

#2
def times2(k):
    k[0] = k[0] *2
    k[1] = k[1] *2

a=[1,2]
b=[3,4]
times2(a)
times2(b)
print('a=',a,'b=',b)

#3
fruitdb =[['사과',1020],['오렌지',880],['포도',3160]]
for i in range(len(fruitdb)):
    print(fruitdb[i][0])

#4
for i in range(len(fruitdb)) :
    print('* 과일명:',fruitdb[i][0], '(',fruitdb[i][1],')원')

#5
sum = 0
for i in range(len(fruitdb)):
    sum += fruitdb[i][1]
avg = sum/len(fruitdb)
print('%.1f원' %avg)

#6
def makelotto(a):
    while len(a)<6:
        lotto = random.randint(1,45)
        if lotto not in a:
            a.append(lotto)
            


win =[]
my =[]

makelotto(win)
makelotto(my)
win.sort()
my.sort()
print('금주 번호: ',win)
print('나의 번호: ',my)




text = "AI! 나는 인공지능 로봇 입니다. 나는 'AI 로봇' 입니다."
people = ['홍','이','김','이','이','김']

def max_count(text):
  skips = ['.',',',';',':','!',"'"]
  
  for ch in skips:
    text = text.replace(ch,'')
  counts = {}
  
  for i in text.split(' '):
    if i in counts:
      counts[i] += 1
    else:
      counts[i] = 1
      
  return counts

def max_count1(text):
  counts ={}
  for i in text:
    if i in counts:
      counts[i] += 1
    else:
      counts[i] = 1
      
  return counts
counts = max_count1(people)

print(max_count(text))
print(max_count1(people))
print(counts)
print(max(counts, key = counts.get))
print(max(counts.values()))
print(counts.items())

for name, count in counts.items():
  print(name,count)

human = ['홍','홍','김','이','홍','김']
def max_count2(human):
  counts = {}
  for i in human:
    if i in counts:
      counts[i] +=1
    else:
      counts[i] = 1
  return counts
counts = max_count2(human)

first = []

max_num = max(counts.values()) 
for name, count in counts.items():
  print(name,':',count, '번')
  if count == max_num:
    first.append(name)
print('1등:',first)
   
a = [['도윤',21],['하준',20],['시우',22]]

for x, y in a:
  print(x,':',y,'세')

def fib(n):
  a, b = 0, 1
  while b < n:
    print(b,end = " ")
    a, b = b, b+a
print(fib(8))

def fib2(n):
  result = []
  a, b = 0, 1
  while b < n:
    result.append(b)
    
    a, b = b, b+a
  return result

a = fib2(8)
print(a)


class You:
  name = ''
  def setname(self, n):
    self.name = n
  
  def setage(self, n):
    self.age = n
    
  def show(self):
    print('이름:', self.name, '나이',self.age)

my = You()
my.setname('준서')
my.setage(21)
my.show()
'''
class Calc:
  def __init__(self,n1,n2):
    self.a = n1
    self.b = n2
    
  def calculate(self, op):
    if op == '+':
      print(self.a,'+',self.b, '=',self.a+self.b)
    else:
      print(self.a,'*',self.b, '=',self.a*self.b)

num1 = int(input('Num1:'))
num2 = int(input('Num2:'))

obj = Calc(num1,num2)
obj.calculate('+')
obj.calculate('*')
'''
fruitdb = {'사과':1020,'오렌지':880}
fruitdb['사과'] += 1
print(fruitdb)

print(fruitdb['사과'])

for name in fruitdb:
  print(name, ': ',fruitdb[name])

for name, num in fruitdb.items():
  print(name, num)
  

word = 'Python Programming'
letters = set(word)
print(len(letters))

pack = [(0,0),(1,1)]

for (x,y) in pack:
  print(x,y)
  

k = [1,2,3]
k.insert(-2,5)
print(k)

def new(n, x):
  n =2
  x.append(x[-1]+1)
  print('new',n,x)

def one():
  n=1
  x=[0,1,2]
  print('one:',n,x)
  new(n,x)
  print('one:',n,x)
print(one())

B = [1,2,1,2,1,2,'wls',11]
all = B + ['동형',25]
print(all)
print(str(len(all)))
print(B[1::2])
seq = 'Hello!'
for s in seq:
  print(s)
  
animal = 'elephant'
print(animal[::-1])

for i in range(1, 4):
  for j in range(1, i+1):
    print(j, end='')
  print()
  
for i in range(3,8,2):
  print(i)
  '''
import time
for i in range(10,0,-1):
  print(i)
  time.sleep(1)
print("Fire!")
'''
grade = 80
if (grade>80):
  print("dd")
  
adult = input()


adult = int(adult)

print(bool(adult))
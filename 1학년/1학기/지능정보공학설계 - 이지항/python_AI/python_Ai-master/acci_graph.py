import pandas as pd
import matplotlib.pyplot as plt


plt.rc('font', family='Malgun Gothic')

acci = pd.read_csv('acci.csv', encoding='cp949')#euc-kr
print(acci.head())

#1
print(acci.mean(axis=0, numeric_only  = True)) # 발생건수 ,사망자수, 부상자수, 중상, 경상, 부상신고의 평균

#2
acci.index = acci['법규위반']+'/'+acci['주야']

dead = acci['사망자수']

plt.bar(
    acci.index,
    dead
)
plt.title("교통법규위반 사망자 수")
plt.xlabel("교통법규위반")
plt.ylabel("사망자 수")
plt.xticks(rotation = 270)
plt.show()

#3
a = acci['부상자수']
plt.plot(acci.index,a,marker = 'o',label = "부상자수")
b = acci['중상']
plt.plot(acci.index,b,marker = 'o',label = "중상자수")
c = acci['경상']
plt.plot(acci.index,c,marker = 'o',label = "경상자수")

plt.xticks(rotation = 270)
plt.legend(loc='upper left',ncol = 1)
plt.xlabel("교통법규위반")
plt.ylabel("수")
plt.title("부상자, 중상, 경상자 수 line 그래프")

plt.show()
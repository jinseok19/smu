import pandas as pd
import matplotlib.pyplot as plt
import platform

if platform.system() == 'Windows':
    plt.rc('font', family='Malgun Gothic')

acci = pd.read_csv('acci.csv', encoding='cp949')#euc-kr

x = pd.DataFrame(acci, columns = ['법규위반', '주야', '발생건수','사망자수','부상자수','중상','경상','부상신고'])
#1
print(acci.mean(axis=0)) # 발생건수 ,사망자수, 부상자수, 중상, 경상, 부상신고의 평균
print(acci.mean(numeric_only=True))



#2
acci.index = acci['법규위반']+'/'+acci['주야']

ax = acci['사망자수'].plot(
    kind = 'bar',
    title = '교통사고 사망자수',
    figsize=(12,12),
    legend = True,
    xlabel = "법규위반",
    ylabel = "사망자수"
    
    )



plt.xticks(rotation = 90)
plt.show()

a = acci['부상자수']
plt.plot(acci.index,a,marker = 'o',label = "부상자수")
b = acci['중상']
plt.plot(acci.index,b,marker = 'o',label = "중상자수")
c = acci['경상']
plt.plot(acci.index,c,marker = 'o',label = "경상자수")

plt.xticks(rotation = 90)
plt.legend(loc='upper left',ncol = 1)
plt.xlabel("교통법규위반")
plt.ylabel("수")
plt.title("부상자, 중상, 경상자 수 line 그래프")

plt.show()
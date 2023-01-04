import pandas as pd
import matplotlib.pyplot as plt
import numpy as np




plt.rc('font', family='Malgun Gothic')

acci = pd.read_csv('acci1.csv', encoding='cp949')#euc-kr

# 1번 문제
x = pd.DataFrame(acci.groupby(acci['법규위반']).sum(), columns = ['발생건수','사망자수','부상자수'])
print(x)


# 2번 문제
#Simple Feature Scaling
x['발생건수'] =  x['발생건수'] / x['발생건수'].max()

x['사망자수'] =  x['사망자수'] / x['사망자수'].max()

x['부상자수'] =  x['부상자수'] / x['부상자수'].max()

print("======================================================================")
print(x)
# 3-1 문제
nx  = acci['법규위반'].unique()
xs = np.arange(len(nx))
width = 0.25
ax=plt.axes()
plt.xticks(xs, nx, rotation = 45)
plt.xlabel('교통법규 위반')
plt.ylabel('발생건수/사망자수/부상자수')
plt.title('Simple Feature Scaling')
plt.bar(xs, x['발생건수'], width, label = '발생건수')
plt.bar(xs + width, x['사망자수'], width, label = '사망자수')
plt.bar(xs + 2*width, x['부상자수'], width, label = '부상자수')

plt.legend(loc="upper left")

plt.show()

#Min-Max

x['발생건수'] = (x['발생건수'] - x['발생건수'].min()) / (x['발생건수'].max() - x['발생건수'].min())
x['사망자수'] = (x['사망자수'] - x['사망자수'].min()) / (x['사망자수'].max() - x['사망자수'].min())
x['부상자수'] = (x['부상자수'] - x['부상자수'].min()) / (x['부상자수'].max() - x['부상자수'].min())
print("==============================================================================")
print(x)




#3-2번 문제
nx  = acci['법규위반'].unique()
xs = np.arange(len(nx))
width = 0.25

plt.xticks(xs, nx, rotation = 45)
plt.xlabel('교통법규 위반')
plt.ylabel('발생건수/사망자수/부상자수')
plt.title('Min-Max')
plt.bar(xs, x['발생건수'], width, label = '발생건수')
plt.bar(xs + width, x['사망자수'], width, label = '사망자수')
plt.bar(xs + 2*width, x['부상자수'], width, label = '부상자수')

plt.legend(loc="upper left")

plt.show()

# 문제 4번

group_name = ['Low','Mid','High']
x['발생건수_빈도수'], mybin1 = pd.cut(x['발생건수'],3,labels = group_name, retbins = True)
x['사망자수_빈도수'], mybin2 = pd.cut(x['사망자수'],3,labels = group_name, retbins = True)
x['부상자수_빈도수'], mybin3 = pd.cut(x['부상자수'],3,labels = group_name, retbins = True)
print("==========================================================================")
print(x)
print("발생건수_빈도수 : ",mybin1)
print("사망자수_빈도수 : ", mybin2)
print("부상자수_빈도수 : ", mybin3)
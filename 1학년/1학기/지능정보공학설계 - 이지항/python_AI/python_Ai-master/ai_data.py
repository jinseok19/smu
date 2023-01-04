import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

x = pd.Series([7,3,5,8],index=['서울','대구','부산','광주'])
y = pd.Series([2,4,5,1],index=['대구','부산','서울','대전'])
medal = [1,3,2,4,2,3]
z = pd.Series(medal)

data = {'age' : [23,43,12,45],
        'name' : ['민준','현우','서연','동현'],
        'height' : [175.3,180.3,165.8,172.7]}
k = pd.DataFrame(data, columns=['name', 'age', 'height'])
print(x)
print(x[['서울', '대구']])
print(x.index)
print(x.values)
print(sorted(x.index))
print(sorted(x.values))
print(x+y)
print(pd.unique(z))# 중복제거
print(k)
print(k.name)
print(k.mean(axis=0))
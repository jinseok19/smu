import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

acci = pd.read_csv('acci.csv', encoding='cp949')
print(acci.head())
print(acci.mean(numeric_only=True))

print(acci.columns)
violation_of_regulations = acci.loc[:,['법규위반']]
dead = acci.loc[:,['사망자수']]


plt.bar(violation_of_regulations,dead)

plt.show()

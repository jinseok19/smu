# -*- coding: utf-8 -*-
"""
Created on Wed May 26 11:35:01 2021

@author: jeehang
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from matplotlib import rcParams

rcParams['font.family'] = 'malgun gothic'

accident = pd.read_csv('acci.csv', encoding='cp949')

# Question 1

mean = accident.mean()
print (mean)

# Question 2 - 1

x = accident["violation"]
y = accident["dead"]

plt.xticks(rotation = 45)
plt.xlabel('Types of Traffic Violations')
plt.ylabel('Number of Dead')

plt.bar(x, y)
plt.show()

# Question 3 - 1

x = accident["violation"]
y1 = accident["injuried"]
y2 = accident["heavy"]
y3 = accident["light"]

plt.xticks(rotation = 45)
plt.xlabel('Types of Traffic Violations')
plt.ylabel('Number of Injuried')

plt.plot(x, y1, "o-", linewidth = 1, label='부상자수')
plt.plot(x, y2, "o-", linewidth = 1, label='중상자수')
plt.plot(x, y3, "o-", linewidth = 1, label='경상자수')

plt.legend(loc="upper left")

plt.show()


# -*- coding: utf-8 -*-
"""
Created on Thu May 27 11:52:14 2021

@author: jeehang
"""

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.font_manager as fm
from matplotlib import rcParams

rcParams['font.family'] = 'malgun gothic'
accident = pd.read_csv('acci.csv', engine='python')

# Question 2 - 2

x = accident["violation"]
y = accident["dead"]

days = [y.values[i] for i in range(0, len(y), 2)]
nights = [y.values[i] for i in range(1, len(y), 2)]

print(days)

print(nights)
nx = x.unique()
xs = np.arange(len(nx))
width = 0.4

plt.xticks(xs, nx, rotation = 45)
plt.xlabel('Types of Traffic Violations')
plt.ylabel('Number of Dead')

plt.bar(xs - width/2, days, width, label = '주간')
plt.bar(xs + width/2, nights, width, label = '야간')

plt.legend(loc="upper left")

plt.show()

# Question 3 - 2

x = accident["violation"]
y1 = accident["injuried"]
y1_days = [y1.values[i] for i in range(0, len(y1), 2)]
y1_nights = [y1.values[j] for j in range(1, len(y1), 2)]

y2 = accident["heavy"]
y2_days = [y2.values[i] for i in range(0, len(y2), 2)]
y2_nights = [y2.values[j] for j in range(1, len(y2), 2)]

y3 = accident["light"]
y3_days = [y3.values[i] for i in range(0, len(y3), 2)]
y3_nights = [y3.values[j] for j in range(1, len(y3), 2)]

plt.xticks(rotation = 45)
plt.xlabel('Types of Traffic Violations')
plt.ylabel('Number of Injuried')

plt.plot(x.unique(), y1_days, "o-", linewidth = 1, label='Total')
plt.plot(x.unique(), y2_days, "o-", linewidth = 1, label='Heavy')
plt.plot(x.unique(), y3_days, "o-", linewidth = 1, label='Light')

plt.legend(loc="upper left")

plt.show()
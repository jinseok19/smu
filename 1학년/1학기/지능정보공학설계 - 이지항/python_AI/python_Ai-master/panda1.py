# -*- coding: utf-8 -*-
"""
Created on Mon May 24 23:08:21 2021

@author: admin
"""

import pandas as pd
import matplotlib.pyplot as plt

accident = pd.read_csv("acci.csv", engine="python")

df = pd.DataFrame(accident)

print (df)


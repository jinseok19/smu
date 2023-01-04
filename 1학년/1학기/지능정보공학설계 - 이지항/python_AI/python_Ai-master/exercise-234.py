# -*- coding: utf-8 -*-
"""
Created on Tue Jun  1 22:05:00 2021

@author: jeehang
"""

import pandas as pd
import matplotlib.pyplot as plt
from scipy.spatial import distance
import cartopy.crs as ccrs
import cartopy.feature as cfeature

# compute the euclidean distance
def euc(a,b) :
    return distance.euclidean(a, b)

proj = ccrs.Mercator()
plt.figure(figsize = (10, 10))

ax = plt.axes(projection = proj)
ax.set_extent((-25.0, 20.0, 52.0, 10.0))

ax.add_feature(cfeature.LAND)
ax.add_feature(cfeature.OCEAN)
ax.add_feature(cfeature.COASTLINE)
ax.add_feature(cfeature.BORDERS, linestyle=':');

# read data from bird_tracking.csv
birdata = pd.read_csv('bird_tracking.csv')
bird_names = pd.unique(birdata.bird_name)

sindex = 2500                           # start index
eindex = 7500                           # end index

# Bird Eric
ix = birdata.bird_name == "Eric"
x, y = birdata.longitude[ix], birdata.latitude[ix]
i = [x[sindex], y[sindex]]
j = [x[eindex], y[eindex]]

ax.plot(x[sindex:eindex], y[sindex:eindex], '.', transform=ccrs.Geodetic());
print('Eric', euc(i, j))

# Bird Nico
ix = birdata['bird_name'] == 'Nico'
x, y = birdata.longitude[ix], birdata.latitude[ix]

start = len(x)
dest = len(y)
i = [x[start+sindex], y[start+sindex]]
j = [x[dest+eindex], y[dest+eindex]]

ax.plot(x[sindex:eindex], y[sindex:eindex], '.', transform=ccrs.Geodetic());
print('Nico', euc(i, j))

# Bird Sanne
ix = birdata['bird_name'] == 'Sanne'
x, y = birdata.longitude[ix], birdata.latitude[ix]

start = start + len(x)
dest = dest + len(x)
i = [x[start+sindex], y[start+sindex]]
j = [x[dest+eindex], y[dest+eindex]]

ax.plot(x[sindex:eindex], y[sindex:eindex], '.', transform=ccrs.Geodetic());
print('Sanne', euc(i, j))

plt.show()

# p236 - Check which bird flew the longest distance

longest = 0
distlist = []

ix = birdata['bird_name'] == 'Eric'
x, y = birdata.longitude[ix], birdata.latitude[ix]
i = [x[0], y[0]]

for ind in range(len(x) - 1):

    j = [x[ind + 1], y[ind + 1]]
    newlength = euc(i, j)
    distlist.append(newlength)

    if (euc(i, j) > longest):
        longest = newlength

print('Longest=', longest)

bird_name = pd.unique(birdata.bird_name)
bird_dist = {}
start = 0
end = 0
count = 0

for bird_name in bird_names:
    
    ix = birdata['bird_name'] == bird_name
    x, y = birdata.longitude[ix], birdata.latitude[ix]
    longest = 0
    i = [x[start], y[start]]
    
    for ind in range(len(x)-1):
    
        j = [x[start + ind + 1], y[start + ind + 1]]
        newlength = euc(i, j)
        distlist.append(newlength)
        if (euc(i, j) > longest):
            longest = newlength
            
    bird_dist[bird_names[count]] = longest
    count = count + 1
    start = start + len(x)
    dest = dest + len(x)

print(bird_dist)
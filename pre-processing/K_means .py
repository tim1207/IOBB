import pandas as pd 
import numpy as np
import numpy.linalg
import math
import csv
from sklearn import *
import matplotlib
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans

np.random.seed(19680801)
source ="../All_Data/20220408拿放資料/手2022-04-08 134400-4.csv"

data,train_data=[],[]
i=0
with open(source, newline='') as csvfile:

    rows = csv.reader(csvfile)
        
    for row in rows:
        if i==0:
            label=np.array(row[1:len(row)-1])
        else:
            train_data.append(row[1:len(row)-1])
        i+=1
    for i in range(len(train_data)):
        for j in range(len(train_data[0])):
            train_data[i][j]=float(train_data[i][j])
    
dataSeries= np.array(train_data)
print(dataSeries)

k_range = range(2, 11)
distortions = []
scores = []
# 記錄每種 K 值建出的 KMeans 模型的成效
# for i in k_range:
#     kmeans = KMeans(n_clusters=i).fit(dx)
#     distortions.append(kmeans.inertia_) # 誤差平方和 (SSE)
#     scores.append(silhouette_score(dx, kmeans.predict(dx))) # 側影係數
title=["G","M","A","Q"]

for i in range(0,12,3):
    kmeans = KMeans(n_clusters=6)
    kmeans.fit(dataSeries[:,i:i+3])
    new_dy = kmeans.predict(dataSeries[:,i:i+3])

    plt.rcParams['font.size'] = 14
    plt.figure(figsize=(64,64))
    ax = plt.axes(projection='3d')
    plt.title(title[i//3])
    ax.scatter3D(dataSeries.T[i], dataSeries.T[i+1], dataSeries.T[i+2],c=new_dy, cmap=plt.cm.Set1)
    
    plt.show()
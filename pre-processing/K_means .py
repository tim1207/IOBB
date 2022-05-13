import pandas as pd 
import numpy as np
import numpy.linalg
import math
import csv
from sklearn import *
import matplotlib
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans
# from func import smooth ,preProcessing

data = pd.read_csv("All_Data/20220408拿放資料/手2022-04-08 134400-4.csv")
data = np.array(data)
# data = preProcessing(data)
print(data[:,14])

for i in range(0,12,3):
    kmeans = KMeans(n_clusters=6)
    kmeans.fit(data[:,i:i+3])
    new_dy = kmeans.predict(data[:,i:i+3])

    plt.rcParams['font.size'] = 14
    plt.figure(figsize=(20,10))
    ax = plt.axes(projection='3d')
    # plt.title([i//3])
    ax.scatter3D(data.T[i], data.T[i+1], data.T[i+2],c=new_dy, cmap=plt.cm.Set1)
    
    plt.show()
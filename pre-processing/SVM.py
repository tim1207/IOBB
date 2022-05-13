from sklearn import datasets
import pandas as pd
import csv
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.preprocessing import StandardScaler

np.random.seed(202205456)

source = "All_Data/new_data/手2022-05-06 114900-4.csv"
source1 = "All_Data/new_data/腳2022-05-06 120000-4.csv"

data,train_data,label=[],[],[]

k=0
with open(source, newline='') as csvfile:

    rows = csv.reader(csvfile)
        
    for row in rows:
        if k!=0:
            label.append(row[len(row)-1])
            train_data.append(row[1:4]+row[7:10])
        k+=1
    for i in range(len(train_data)):
        for j in range(len(train_data[0])):
            train_data[i][j]=float(train_data[i][j])
    
dataSeries= np.array(train_data)
#  1 2 3 7 8 9
labelSeries = np.array(label)
# 16
X_train, X_test, y_train, y_test = train_test_split(dataSeries, labelSeries,test_size=0.05, random_state=2222)


svm = SVC(kernel="rbf",gamma = 0.5, probability=True)
svm.fit(X_train,y_train)

predict = svm.predict(X_test)
predictP = svm.predict_proba(X_test)
print(predictP)
svm_score = svm.score(X_test, y_test)
print(svm_score)

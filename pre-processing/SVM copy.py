from sklearn import datasets
import pandas as pd
import csv
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.svm import SVC
from sklearn.preprocessing import StandardScaler
from scipy.fftpack import fft 

np.random.seed(202205456)

source = "All_Data/new_data/手2022-05-06 114900-4.csv"
source1 = "All_Data/new_data/腳2022-05-06 120000-4.csv"

data = pd.read_csv(source)
dataSeries = np.array(data)

#  1 2 3 7 8 9
labelSeries = dataSeries[:,16]
# 16
# X_train, X_test, y_train, y_test = train_test_split(np.real(fft(dataSeries[:,1:3])), labelSeries,test_size=0.05, random_state=2222)

X_train, X_test, y_train, y_test = train_test_split(dataSeries[:,1:4]+dataSeries[:,7:10], labelSeries,test_size=0.05, random_state=2222)

svm = SVC(kernel="rbf",gamma = 0.5, probability=True)
svm.fit(X_train,y_train)

predict = svm.predict(X_test)
print(predict )
predictP = svm.predict_proba(X_test)
svm_score = svm.score(X_test, y_test)
print(svm_score)


# print(fft(dataSeries[:,1]))

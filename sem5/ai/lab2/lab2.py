import pandas as pd
import numpy as np
from matplotlib import pyplot as plt
from sklearn.linear_model import LinearRegression
from sklearn.datasets import load_diabetes
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_absolute_error, mean_squared_error, mean_absolute_percentage_error
# x = np.arange(-3,3, 0.1).reshape((-1,1))
# y = np.tanh(x) + np.random.randn(*x.shape)*0.2
# ypred = LinearRegression().fit(x,y).predict(x)
# plt.scatter(x,y)
# plt.xlabel('x')
# plt.ylabel('y')
# plt.plot(x, ypred)
# plt.legend([ 'F(x) - aproksymująca','f(x) - aproksymowana zaszumiona'])
# plt.show()


bh_data = pd.read_excel("practice_lab_2.xlsx")
bh_arr = bh_data.values
X, y = bh_arr[:,:-1], bh_arr[:,-1]
# X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.2,random_state= 221, shuffle=False)
# linReg = LinearRegression()
# linReg.fit(X_train, y_train)
# y_pred = linReg.predict(X_test)
# minval = min(y_test.min(), y_pred.min())
# maxval = max(y_test.max(), y_pred.max())
# plt.scatter(y_test, y_pred)
# plt.plot([minval, maxval], [minval, maxval])
# plt.xlabel('y_test')
# plt.ylabel('y_pred')
# plt.show()

# bh_data = pd.read_excel("practice_lab_2.xlsx")
# bh_arr = bh_data.values
# X, y = bh_arr[:,:-1], bh_arr[:,-1]
# X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.2, random_state=221, shuffle=True)
# linReg = LinearRegression()
# linReg.fit(X_train, y_train)
# y_pred = linReg.predict(X_test)
# mse = mean_squared_error(y_test, y_pred)
# mae = mean_absolute_error(y_test, y_pred)
# mape = mean_absolute_percentage_error (y_test, y_pred)

# plt.boxplot(y_train)
# plt.show()

#zadanie2.1
# import seaborn as sns
# dataplot = sns.heatmap(bh_data.corr(), cmap = "BuPu", annot=True)
# ##plt.matshow(bh_data.corr())
# plt.show()

#zadanie2.2

def wytestujuj(liczba_powtorzen, outliers_action='nothing'):
    s = 0
    for i in range(liczba_powtorzen):
        X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.2, random_state=221, shuffle=True)
        linReg = LinearRegression()
        outliers = np.abs((y_train - y_train.mean())/y_train.std())>2.5
        
        
        linReg.fit(X_train, y_train)
        y_pred = linReg.predict(X_test)
        mape = mean_absolute_percentage_error (y_test, y_pred)
        s += mape
    return s/liczba_powtorzen

print(wytestujuj(2))

# bh_data = pd.read_excel("practice_lab_2.xlsx")
# bh_arr = bh_data.values
# X, y = bh_arr[:,:-1], bh_arr[:,-1]
# X_train, X_test, y_train, y_test = train_test_split(X,y,test_size=0.2, random_state=221, shuffle=True)
# linReg = LinearRegression()
# linReg.fit(X_train, y_train)
# y_pred = linReg.predict(X_test)
# mse = mean_squared_error(y_test, y_pred)
# mae = mean_absolute_error(y_test, y_pred)
# mape = mean_absolute_percentage_error (y_test, y_pred)

# plt.boxplot(y_train)
# plt.show()

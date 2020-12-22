#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Sample code of HW4, Problem 3
"""

import matplotlib.pyplot as plt
import pickle
import math
import numpy as np
from scipy import linalg

myfile = open('hw4_p3_data.pickle', 'rb')
mydict = pickle.load(myfile)

X_train = mydict['X_train'] # x_1 ... x_n
X_test = mydict['X_test'] # x_n+1 ...x_n+m
Y_train = mydict['Y_train']
Y_test = mydict['Y_test']

sigma = 0.1
sigma_f = 1.0
ls = [0.06, 0.2]

fp = open("3b_result.txt", "w")

def cov(xi, xj, l):
    top = xi - xj
    top = top * top * (-1)
    down = 2 * l * l
    ans = math.exp(top / down)
    return ans

for l in ls:
    fp.write("l = " + str(l) + "\n")

    predictive_mean = []
    predictive_std = []
    p1 = []
    p2 = []
    p3 = []
    p1_ = []
    p2_ = []
    p3_ = []
    
    for k in range(0, len(X_test)):
        ka = []
        for i in range(0, len(X_train)):
            ka.append(cov(X_train[i], X_test[k], l))

        kb = []
        for i in range(0, len(X_train)):
            tmp = []
            for j in range(0, len(X_train)):
                tmp.append(cov(X_train[i], X_train[j], l))
                if i == j:
                    tmp[j] = tmp[j] + 0.01 # sigma * sigma
            kb.append(tmp)

        kbi = linalg.inv(kb)
        a0 = np.matmul(ka, kbi)
        a1 = np.matrix.transpose(Y_train)
        ans = np.matmul(a0, a1)

        cok = cov(X_test[k], X_test[k], l)
        a2 = np.matmul(ka, kbi)
        a3 = np.matrix.transpose(np.array(ka))
        var = cok - np.matmul(a2, a3)

        predictive_mean.append(ans)
        predictive_std.append(np.sqrt(var))
        p1.append(ans - np.sqrt(var))
        p2.append(ans - 2*np.sqrt(var))
        p3.append(ans - 3*np.sqrt(var))
        p1_.append(ans + np.sqrt(var))
        p2_.append(ans + 2*np.sqrt(var))
        p3_.append(ans + 3*np.sqrt(var))

        fp.write("predicted mean: " + str(ans) + "\n")
        fp.write("answer: " + str(Y_test[k]) + "\n")
        fp.write("predicted std: " + str(np.sqrt(var)) + "\n")
        fp.write("\n")

    fig = plt.figure()
    plt.plot(X_train, Y_train, linestyle='', color='b', markersize=3, marker='+',label="Training data")
    plt.plot(X_test, Y_test, linestyle='', color='orange', markersize=2, marker='^',label="Testing data")
    plt.plot(X_test, predictive_mean, linestyle=':', color='green')
    plt.fill_between(X_test.flatten(), p1, p1_, color='green', alpha=0.13)
    plt.fill_between(X_test.flatten(), p2, p2_, color='green', alpha=0.07)
    plt.fill_between(X_test.flatten(), p3, p3_, color='green', alpha=0.04)
    plt.xlabel("X")
    plt.ylabel("Y")
    plt.show()
    fig.show()
    plt.close()
    fp.write("\n")

fp.close()
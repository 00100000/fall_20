#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np
import math

fp = open("4b_result.txt", "w")

for n in [1000, 100000, 10000000]:
    fp.write("n = " + str(n) + "\n")
    sum = 0
    for i in range(0, n):
        x = np.random.uniform(-1, 1)
        y = np.random.uniform(-1, 1)
        if x*x + 2*y*y <= 1:
            sum = sum + 1
    sum = sum / n
    sum = sum * 4
    fp.write(str(sum) + "\n\n")

fp.close()
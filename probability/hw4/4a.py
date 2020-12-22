#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import numpy as np
import math

fp = open("4a_result.txt", "w")

for n in [1000, 100000]:
    fp.write("n = " + str(n) + "\n")
    for t in range(0, 20):
        draw = np.random.normal(0, 1, n)
        sum = 0
        for z in draw:
            sum = ( sum + math.cos(z) )
            sum = ( sum + math.sin(2*z) )
        sum = sum / n
        fp.write(str(sum) + "\n")
    fp.write("\n")

fp.close()
import sys
import math

n = int(input())
mn = 10005
if n > 0:
    for i in input().split():
        t = int(i)
        mn = t if (abs(mn) > abs(t)) or (abs(t) == abs(mn) and t > mn) else mn
else:
    mn = 0
print(mn)

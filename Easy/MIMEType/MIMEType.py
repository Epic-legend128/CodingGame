import sys
import math

n = int(input())  # Number of elements which make up the association table.
q = int(input())  # Number Q of file names to be analyzed.
match = {}
for i in range(n):
    inputs = input().split(' ')
    match[inputs[0].lower()] = inputs[1]
    #print(inputs)
    
for i in range(q):
    fname = input().lower()
    #print(fname)
    if fname.__contains__('.'):
        fname=fname.split('.')
        if fname[len(fname)-1] in match.keys():
            print(match[fname[len(fname)-1]])
        else:
            print("UNKNOWN")
    else:
        print("UNKNOWN")

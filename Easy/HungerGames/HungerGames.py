import sys
import math

killer = {}
killed = {}
names = []

tributes = int(input())
for i in range(tributes):
    player_name = input()
    names.append(player_name)
    killer[player_name] = "Winner"
    killed[player_name] = []
turns = int(input())
names.sort()
for i in range(turns):
    info = input().split(' ')
    #print(info)
    if info[1] == "killed":
        for j in range(2, len(info)):
            current = info[j]
            if (info[j][len(info[j])-1] == ','):
                current = current[0:len(current)-1]
                info[j] = current
            killer[current] = info[0]
        killed[info[0]] += (info[2:])

for i in range(tributes-1):
    name = names[i]
    print("Name: "+name)
    if len(killed[name]) > 0:
        killed[name].sort()
        print("Killed: "+', '.join(killed[name]))
    else:
        print("Killed: None")
    print("Killer: "+killer[name])
    print()
name = names[tributes-1]
print("Name: "+name)
if len(killed[name]) > 0:
    killed[name].sort()
    print("Killed: "+', '.join(killed[name]))
else:
    print("Killed: None")
print("Killer: "+killer[name])

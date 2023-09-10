import sys

x = int(sys.stdin.readline())
s=[]
while (x):
    s.append(x%2)
    x=x//2
print(s.count(1))
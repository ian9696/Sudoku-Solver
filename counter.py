
from pyeda.inter import *
import sys

sys.setrecursionlimit(10000)

a=[]
with open(sys.argv[1]) as fileIn:
    for line in fileIn:
        a.append(list(map(int, line.split())))

N=len(a)
n=int(N**(1/2))

x=exprvars('x', N, N, N)

f=1

for i in range(N):
    for k in range(N):
        f=f&OneHot(*[x[i][j][k] if a[i][j]==0 else 1 if a[i][j]==k+1 else 0 for j in range(N)])

for j in range(N):
    for k in range(N):
        f=f&OneHot(*[x[i][j][k] if a[i][j]==0 else 1 if a[i][j]==k+1 else 0 for i in range(N)])

for i in range(N):
    for j in range(N):
        if a[i][j]==0:
            f=f&OneHot(*[x[i][j][k] for k in range(N)])

for i in range(n):
    for j in range(n):
        for k in range(N):
            t=[]
            for l in range(n):
                for m in range(n):
                    u=i*n+l
                    v=j*n+m
                    t.append(x[u][v][k] if a[u][v]==0 else 1 if a[u][v]==k+1 else 0)
            f=f&OneHot(*t)

with open(sys.argv[2], 'w') as fileOut:
    fileOut.write('%d\n'%(f.to_cnf().satisfy_count()))


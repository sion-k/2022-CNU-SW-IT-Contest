import sys
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
a = list(map(int,input().split()))
tmp = 0
for i in range(n):
    for j in range(i, n):
        tmp = max(tmp, a[j] - a[i])
print(str(tmp)+'\n')

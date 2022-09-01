import sys
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
a = list(map(int,input().split()))
q = int(input())
for _ in range(q):
    o, l, r = map(int,input().split())
    if o == 1:
        a[l-1] = r
    else:
        tmp = 0
        for i in range(l - 1, r):
            for j in range(i, r):
                tmp = max(tmp, a[j] - a[i])
        print(str(tmp))
        print("\n")

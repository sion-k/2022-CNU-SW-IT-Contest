n = int(input())
a = [*map(int, input().split())]

def lps(p):
    sum, cnt = a[p], 1
    for i in range(p + 1, n):
        if sum >= a[i]:
            sum += a[i]
            cnt += 1
    return cnt

ret = 0
for i in range(n):
    ret = max(ret, lps(i))

print(ret)

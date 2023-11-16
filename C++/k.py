n = int(input())

for i in range(n):
    s = input().split(' ')
    for i in range(len(s)):
        s[i] = int(s[i])
    m,k,a1,ak = s
    m -= ((a1) + ak * k)
    mn = 100000000000
    if(m <= 0):
        mn = 0
        m*=-1
    mn = min(mn,m // (k))
    print(mn)



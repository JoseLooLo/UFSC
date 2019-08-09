m,n = input().split()
m = int(m)
n = int(n)

#n**m
resu = 1
for i in range(n):
    resu *= m
print(resu)

resu = 1
i = 0
while i < n:
    resu *= m
    i+=1
print(resu)

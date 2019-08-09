a,b = input().split()
a = int(a)
b = int(b)
c = 0
for i in range(a,b+1):
    c +=i
print("soma = %d" % (c))
print("media = %f" % (c/(b-a+1)))

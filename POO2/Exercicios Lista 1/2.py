a,b = input().split()
a = int(a)
b = int(b)
if a > b:
    print("%d eh o maior" % (a))
elif b > a:
    print("%d eh o maior" % (b))
else:
    print("sao iguais")

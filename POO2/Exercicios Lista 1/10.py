a,b = input().split()
a = int(a)
b = int(b)
soma = 0
qnt = 0
for i in range(a,b+1):
    if i % 2 != 0:
        soma += i
        qnt += 1

print("soma = %d" % (soma))
print("media = %f" % (soma/qnt))

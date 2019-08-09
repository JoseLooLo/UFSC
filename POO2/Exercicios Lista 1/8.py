"""
Esse exercicio é ambiguo
"""
a = int(input())
b = 0
for i in range(a):
    if i % 3 == 0 or i % 5 == 0 or i % 7 == 0:
        b += i
    if i % 8 == 0:
        b -=i
print (b)

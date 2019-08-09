a,b,c = input().split()
a = int(a)
b = int(b)
c = int(c)
media = (a+b+c)/3
if media < 3:
    print("Reprovado")
elif media >= 5.76:
    print("Aprovado")
else:
    print("Exame")

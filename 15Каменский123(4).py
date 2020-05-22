import os.path
if os.path.exists('1.txt')==False :
    print('There is not file')
    exit(909)
f=open('1.txt' , 'r')
m=n=0
k=0
while True :
    a=f.read(1)
    if not a:
      break
    if a!= ' ':
        k=1
        if int(a)%2==0:
            n=n+int(a)
        else:
            m=m+int(a)
if k==0:
    print('Файл пуст')
else:
    if n>m :
               print('Сумма четных больше')
    elif (n-m)==0 and m!=0:
               print('Суммы четных и нечетных чисел равны')
    else:
               print('Нечетных больше')
f.close()

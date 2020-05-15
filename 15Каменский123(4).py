import os.path
if os.path.exists('1.txt')==False :
    print('There is not file')
    exit(909)
f=open('1.txt' , 'r')
while True :
    a=f.read(1)
    if not a:
      break
    if a!= ' ':
        if int(a)%2==0:
            n=n+1
        else:
            m=m+1
if n==m==0:
    print('Файл пуст')
else:
    if n>m :
               print('Четных больше')
    elif (n-m)==0 and m!=0:
               print('Четных и нечетных чисел поровну')
    else:
               print('Нечетных больше')
f.close()

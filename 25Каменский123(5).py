import os.path
if os.path.exists('1.txt')==False :
    print('There is not file')
    exit(909)
f=open('1.txt' , 'r')
n=0
b=[1,2,3,4,5]
c=[1,2,3,4,5]
v=0
pr=5
g=0
while True :
    a=f.read(1)
    if not a:
      break
    if a!= ' ':
        v=1
        for i in range(0,5):
          if int(a)==b[i] and int(a)!=0:
           n=n+1
           b[i]=0
        for i in range(0,5):
           if int(a)!= c[i]:
               pr=pr-1
               if pr==0:
                   g=g+1
        pr=5 
if v==1:
    print(n)
else:
    print('Empty file')
if g!=0:
    print('В последовательности существует(ют) число(а),не принадлежее(ие) множеству [1,2,3,4,5]!')
f.close()


def maxi(a, b):
    c=0
    if a>b:
        c=a
    else:
        c=b
    return(c)

import os.path
if os.path.exists('1.txt')==False :
    print('There is not file')
    exit(909)
f=open('1.txt', 'r')
b=f.read(1)
if not b:
    print('Empty file')
    exit(1)
if b==' ':
    b=f.read(1)
    if not b:
        print('Empty file')
        exit(2)
v=0
m=n=0
while True:
    c=f.read(1)
    if not c:
        break
    if c!=' ':
        v=1
        if int(b)<int(c):
            n=1
            while True:
                q=f.read(1)
                if not q:  
                   break
                if q!=' ':
                    if int(q)!=int(c):
                        break
                    n=n+1
            if c<q:
               n=1
            b=q
            d=maxi(m, n)
            n=0
            m=d
        elif int(b)==int(c):
            n=2
            pr=2
            while True:
                q=f.read(1)
                if not q:  
                   break
                if q!=' ':
                    if int(q)!=int(c):
                        break
                    n=n+1
            if c<q:
               n=1
            b=q
            d=maxi(m, n)
            n=0
            m=d
        else:
            b=c
if v!=1:
    print(1)
else:
    print(d)
f.close()

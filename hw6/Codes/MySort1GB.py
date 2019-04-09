import threading
import time
global tr
threadnum = input("Enter number of threads ")
file = open("64/record_1GB.txt","r")
a = file.readlines()
sublistsize = int(len(a)/int(threadnum))

def MergeAndSort(L,R,m):
    i = 0    
    j = 0         
    n1 = len(L)
    n2 = len(R)
    arr = []
    while(i<len(L) and j<len(R)):
        if L[i] <= R[j]:
            arr.append(L[i])
            i =i + 1
        else: 
            arr.append(R[j])
            j =j + 1

    while i < n1: 
        arr.append(L[i])
        i =i + 1
      
    while j < n2: 
        arr.append(R[j])
        j =j + 1
    fname = 'merge' + str(m) + '.txt'
    f = open(fname,'w+')
    f.write(''.join(arr))
    f.close()

def funcallto(k):
    x[k].sort()
    tr = str(k)
    tr = 'o' + tr + '.txt'
    f = open(tr,'w+')
    f.write(''.join(x[k]))
    f.close()

def divide_list(l, n): 
    for i in range(0, len(a), n):  
        yield a[i:i + n]
        
n = sublistsize
x = list(divide_list(a, n))
start = time.time()
for k in range(0,int(threadnum)):
    instth = 't' + str(k)
    print("thread " + instth + " sorting done")
    instth = threading.Thread(target=funcallto(k))
    instth.start()

for l in range(0,int(threadnum)):
    instth.join()

for m in range(0,int(int(threadnum)/2)):
    MergeAndSort(x[m],x[m+1],m)
 
end = time.time() 
print("Done! Time required is " + str(end - start) +"sec")
print("Sorting output is stored in merge0.txt file")
file.close() 

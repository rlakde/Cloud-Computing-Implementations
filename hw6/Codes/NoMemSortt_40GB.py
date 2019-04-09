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
for k in range(0,int(threadnum)/2):
    instth = 't' + str(k)
    print("thread " + instth + " sorting done")
    instth = threading.Thread(target=funcallto(k))
    instth.start()

for l in range(0,int(threadnum)/2):
    instth.join()
	
for kk in range(int(threadnum)/2,int(threadnum)):
    instth = 't' + str(kk)
    print("thread " + instth + " sorting done")
    instth = threading.Thread(target=funcallto(kk))
    instth.start()

for ll in range(int(threadnum)/2,int(threadnum)):
    instth.join()

file1 = open("o0.txt","r")
t0 = file1.readlines()
file1.close()
file2 = open("o1.txt","r")
t1 = file2.readlines()
file2.close()
MergeAndSort(t0,t1,1)


file3 = open("o2.txt","r")
t2 = file3.readlines()
file3.close()
file4 = open("o3.txt","r")
t3 = file4.readlines()
file4.close()
MergeAndSort(t2,t3,2)

file4 = open("o4.txt","r")
t4 = file4.readlines()
file4.close()
file5 = open("o5.txt","r")
t5 = file5.readlines()
file5.close()
MergeAndSort(t4,t5,3)

file6 = open("o6.txt","r")
t6 = file6.readlines()
file6.close()
file7 = open("o7.txt","r")
t7 = file7.readlines()
file7.close()
MergeAndSort(t6,t7,4)

file8 = open("merge1.txt","r")
t8 = file8.readlines()
file8.close()
file9 = open("merge2.txt","r")
t9 = file9.readlines()
file9.close()
MergeAndSort(t8,t9,5)

file10 = open("merge3.txt","r")
t10 = file10.readlines()
jj = 0
for el in t10:
	t10[jj] = el[:10]
	jj = jj + 1
file10.close()
file11 = open("merge4.txt","r")
t11 = file11.readlines()
jj = 0
for el in t11:
	t11[jj] = el[:10]
	jj = jj + 1
file11.close()
MergeAndSort(t10,t11,6)

file12 = open("merge5.txt","r")
t12 = file12.readlines()
jj = 0
for el in t12:
	t12[jj] = el[:10]
	jj = jj + 1
file12.close()
file13 = open("merge6.txt","r")
t13 = file13.readlines()
jj = 0
for el in t13:
	t13[jj] = el[:10]
	jj = jj + 1
file13.close()
MergeAndSort(t12,t13,7)
end = time.time()
print("Done! Time required is " + str(end - start) +"sec")
print("Sorting output is stored in merge7.txt file")
file.close() 

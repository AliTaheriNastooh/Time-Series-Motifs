import time

def match(a, b, R):
    count = 0
    for i in range(len(a)):
        if(type(a)is str):
            if(a[i]!=b[i]):
                count = count+1
        else:
            count = count + abs(a[i]-b[i])
    if(count<=R):
        return True
    else:
        return False

def Algorithm_Find_Motif_Brute_Force(T,n,R):
    target = open("output.txt", 'a')
    for i in range (len(T)-n+1):
        count = 0
        pointers = []
        for j in range(i+n,len(T)-n+1):
            if (match(T[i:i+n], T[j:j+n], R)):
                count = count+1
                pointers += [j]
                target.write(str(T[i:i+n]))
                target.write(" --- ")
                target.write(str(T[j:j+n]))
                target.write("\n")
    target.close()

target = open("output.txt", 'w')
target.close()
tm = open("outputTime.txt",'w')
with open("input2.txt", "r") as ins:
    arr = []
    for line in ins:
        arr.append(line)
for k in [2,5,6]:
    start_time = time.time()
    for i in range(1000):
        string1=arr[i].split()
        Algorithm_Find_Motif_Brute_Force(string1[0], k, 3)
    tm.write(str(time.time()-start_time))
    tm.write("\n")
tm.write("\n")

arr2=[[]]
with open("input1.txt", "r") as ins:
    arr = []
    for line in ins:
        arr.append(line)
for i in range(len(arr)):
    temp = arr[i].split()
    arr2 += [[]]
    for j in range(len(temp)):
        arr2[i] += [ord(temp[j])-48]
for k in[2, 5, 6]:
    start_time = time.time()
    for i in range(len(arr2)):
        Algorithm_Find_Motif_Brute_Force(arr2[i], k ,3 )
    tm.write(str(time.time()-start_time))
    tm.write("\n")


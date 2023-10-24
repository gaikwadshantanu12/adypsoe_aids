"""
Experiment No. 11:
(a) Write a Python Program to store roll numbers of student in array who attended training program in random order.
"""

def Linsearch(arr,x):
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1

def Sentsearch(arr,x):
    l = len(arr)
    arr.append(x)
    i = 0
    while(arr[i]!=x):
        i = i+1
    if(i!=l):
        return i
    else:
        return -1

#Driver Code
n = int(input("\nHow many Students are there ? "))
array = []
i=0
for i in range(n):
    item = int(input("Enter roll number : "))
    array.append(item)

print("\nThe Roll Numbers of Students are ...")
print(array)
while(True):
    print("\nMain Menu")
    print("1. Linear Search")
    print("2. Sentinel Search")
    print("3. Exit")
    choice = int(input("Enter your choice : "))
    if(choice == 1):
        key = int(input("\nEnter the roll number to search if student has attended the training program or not ? "))
        location = Linsearch(array,key)
        if(location !=-1):
            print("Yes, the student attended the training program!!!")
        else:
            print("No, the student has not attended the training program!!!")
    elif(choice == 2):
        key = int(input("\nEnter the roll number to search if student has attended the training program or not ? "))
        location = Sentsearch(array,key)
        if(location !=-1):
            print("Yes, the student attended the training program!!!")
        else:
            print("No, the student has not attended the training program!!!")
    else:
        print("Exiting")
        break
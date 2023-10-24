"""
Experiment No. 15 :
Write a Python program to store second year percentage of students in array.
Write a function for sorting array of floating point numbers in ascending order using
    a) Insertion Sort
    b) Shell sort and display top five scores
"""

def InsertSort(arr, n):
    i = 1
    for i in range(n):
        temp = arr[i]
        j = i - 1
        while ((j >= 0) & (arr[j] > temp)):
            arr[j + 1] = arr[j]
            j = j - 1
        arr[j + 1] = temp

    print(arr)
    print("Top Five Scores are...")
    for i in range(len(arr) - 1, 1, -1):
        print(arr[i])

def ShellSort(arr, n):
    d = n // 2
    while d > 0:
        for i in range(d, n):
            temp = arr[i]
            j = i
            while (j >= d and arr[j - d] > temp):
                arr[j] = arr[j - d]
                j -= d

            arr[j] = temp
        d = d // 2

    print(arr)
    print("Top Five Scores are...")
    for i in range(len(arr) - 1, 1, -1):
        print(arr[i])

# Driver Code
n = int(input("How many students are there? "))
array = []
i = 0
for i in range(n):
    item = float(input("Enter percentage marks : "))
    array.append(item)

print("\nYou have entered following scores...")
print(array)
while (True):
    print("\nMain Menu")
    print("1. Insertion Sort")
    print("2. Shell Sort")
    print("3. Exit")
    choice = int(input("\nEnter your Choice : "))
    if (choice == 1):
        print("\nThe sorted Scores are...")
        InsertSort(array, n)
    elif (choice == 2):
        print("\nThe sorted Scores are...")
        ShellSort(array, n)
    else:
        print("Exiting")
        break
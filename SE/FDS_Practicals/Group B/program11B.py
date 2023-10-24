"""
Experiment No. 11:
(b) Write a Python Program to store roll numbers of student in array who attended training program in sorted order.
Write a function for searching whether particular student attended training program or not,
using Binary Search and Fibonacci Search.
"""

def Binsearch(arr, KEY):
    low = 0
    high = len(arr) - 1
    m = 0
    while (low <= high):
        m = (low + high) // 2  # mid of the array is obtained
        if (KEY < arr[m]):
            high = m - 1  # search the left sub list
        elif (KEY > arr[m]):
            low = m + 1  # search the right sub list
        else:
            return m

    return -1  # if element is not present in the list

def FibSearch(arr, key, n):
    # Initialize Fibonacci numbers
    b = 0
    a = 1
    f = b + a

    # f is going to store the smallest
    # Fibonacci Number greater than or equal to n
    while (f < n):
        b = a
        a = f
        f = b + a
        # Marks the eliminated range from front
    offset = -1

    # while there are elements to be inspected.
    # we compare arr[i] with key.
    while (f > 1):

        # Check if b is a valid location
        i = min(offset + b, n - 1)

        # If key is greater than the value at
        # index b, cut the subarray array
        # from offset to i
        if (arr[i] < key):
            f = a
            a = b
            b = f - a
            offset = i

            # If key is lesser than the value at
        # index b, cut the subarray
        # after i+1
        elif (arr[i] > key):
            f = b
            a = a - b
            b = f - a

        # element found. return index
        else:
            return i

            # comparing the last element with key
    if (a and arr[offset + 1] == key):
        return offset + 1

        # element not found. return -1
    return -1

# Driver Code
n = int(input("\nHow many Students are there ? "))
array = []
i = 0
print()
for i in range(n):
    item = int(input("Enter roll number : "))
    array.append(item)

print("\nThe Roll Numbers of Students are ...")
print(array)

while (True):
    print("\nMain Menu")
    print("1. Binary Search")
    print("2. Fibonacci Search")
    print("3. Exit")
    choice = int(input("Enter your choice : "))
    if (choice == 1):
        key = int(input("\nEnter the roll number to search if student has attended the training program or not ? "))
        location = Binsearch(array, key)
        if (location != -1):
            print("Yes, the student attended the training program!!!")
        else:
            print("No, the student has not attended the training program!!!")
    elif (choice == 2):
        key = int(input("\nEnter the roll number to search if student has attended the training program or not ? "))
        location = FibSearch(array, key, n)
        if (location != -1):
            print("\nYes, the student attended the training program!!!")
        else:
            print("\nNo, the student has not attended the training program!!!")
    else:
        print("\nExiting")
        break
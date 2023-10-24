"""
Experiment No. 12 :
a) Write a Python program to store names and mobile numbers of your friends in sorted order on names.
Search your friend from list using binary search (recursive and non- recursive).Insert friend if not present in phonebook.

b) Write a Python program to store names and mobile numbers of your friends in sorted order on names.
Search your friend from list using Fibonacci search. Insert friend if not present in phonebook.
"""

def min(x, y):
    if (x < y):
        return x
    else:
        return y

def fibsearch(arr, x, n):
    f2 = 1
    f1 = 0
    fibm = f2 + f1

    while (fibm < n):
        f2 = f1
        f1 = fibm
        fibm = f2 + f1
    offset = -1

    while (fibm > 1):
        i = min(offset + f2, n - 1)

        if arr[i][0] < x:
            fibm = f1
            f1 = f2
            f2 = fibm - f1
            offset = i
        elif arr[i][0] > x:
            fibm = f2
            f1 = f1 - f2
            f2 = fibm - f1
        else:
            return i

        if (f1 and arr[offset + 1][0] == x):
            return offset + 1
    return -1

def binary_search(arr, low, high, x):
    if high >= low:
        mid = (high + low) // 2
        if arr[mid][0] == x:
            return mid
        elif arr[mid][0] > x:
            return binary_search(arr, low, mid - 1, x)
        else:
            return binary_search(arr, mid + 1, high, x)
    else:
        return -1

def insert(phbk, x1):
    c = [x1]
    mob = int(input("Enter Mobile number of your friend : "))
    c.append(mob)
    print(c)
    phbk.append(c)
    print(phbk)
    sort1(phbk)

def sort1(phbk):
    for j in range(len(phbk)):
        swapped = False
        i = 0
        while i < (len(phbk) - 1):
            if phbk[i][0] > phbk[i + 1][0]:
                phbk[i], phbk[i + 1] = phbk[i + 1], phbk[i]
                swapped = True
            i = i + 1
        if swapped == False:
            break
    print("After sorting phonebook : ", phbk)

if __name__ == "__main__":
    phbk = [["Shantanu", 9146224192], ["Neha", 1234567890], ["Ajinkya", 1234567890], ["Sayali", 1234567890],
            ["Sankalp", 1234567890], ["Nandini", 1234567890]]
    n = len(phbk)
    for i in range(n):
        print(phbk[i])
    print()
    while 1:
        x = input("Enter the friend name you want to search : ")
        #print(x)
        print("\n_____MENU_____")
        print("1.Fibonnaci search.")
        print("2.Binary search.")
        print("____THE END___")

        ch = int(input("Enter your choice : "))

        if (ch == 1):
            result = fibsearch(phbk, x, n)
            if result != -1:
                print("\nElement is present at place", result + 1)
                print("Phone number = ", phbk[result][1])
            else:
                print(x, "is not in phonebook")
                choice = input("\nDo you want to insert it ? y/n : ")
                if choice == 'y':
                    insert(phbk, x)
                    print("Record is now successfully added.")
            choice1 = input("\nDo you want to continue enter ? y/n : ")
            print()
            if choice1 == 'n':
                print("_____THE END_____")
                break
        elif (ch == 2):
            result = binary_search(phbk, 0, n - 1, x)
            if result != -1:
                print("\nElement is present at place", result + 1)
                print("Phone number = ", phbk[result][1])
                print()
            else:
                print(x, "is not in phonebook")
                choice = input("Do you want to insert it ? y/n : ")
                if choice == 'y':
                    insert(phbk, x)
                    print("Record is now successfully added.")
            choice1 = input("Do you want to continue enter ? y/n : ")
            print()
            if choice1 == 'n':
                print("_____THE END_____")
                break
        elif (ch == 3):
            print("___THE END___")
            break
        else:
            print("Wrong choice!!! Please, enter again.")
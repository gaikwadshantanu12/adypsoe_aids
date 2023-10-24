"""
Experiment No. 3 :
Write a Python program for department library which has N books, write functions for following :
     a) Delete the duplicate entries
     b) Display books in ascending order based on cost of books
     c) Count number of books with cost more than 500
     d) Copy books in a new list which has cost less than 500.
"""

def Sorting(Books, N):
    # sorting in ascending order
    for i in range(N):
        for j in range(i + 1, N):
            if (Books[i][1] > Books[j][1]):
                temp1 = Books[i][0]
                Books[i][0] = Books[j][0]
                Books[j][0] = temp1

                temp2 = Books[i][1]
                Books[i][1] = Books[j][1]
                Books[j][1] = temp2
    print("The Books  are...")
    print(Books)

def DeleteDuplicates(Books):
    # Deleting Duplicate Entries
    Final_Books_List = []
    for num in Books:
        if num not in Final_Books_List:
            Final_Books_List.append(num)
    print("On removing Duplicates")
    print(Final_Books_List)

def MoreCost(Books, N):
    # counting number of books having >500 cost
    cnt = 0
    for isbn in range(N):
        if (Books[isbn][1] > 500):
            cnt = cnt + 1
    print("Number of Books having cost> 500 are : ", cnt)

def LessCost(Books, N):
    # counting number of books having <500 cost
    cnt = 0

    for isbn in range(N):
        if (Books[isbn][1] < 500):
            cnt = cnt + 1
    new_List = [[0 for cost in range(2)] for isbn in range(cnt)]

    for isbn in range(N):
        if (Books[isbn][1] < 500):
            new_List[isbn][0] = Books[isbn][0]
            new_List[isbn][1] = Books[isbn][1]

    print("\nBooks having the cost less than 500 are...")
    print("\nISBN \t COST")
    for isbn in range(cnt):
        print(" ", new_List[isbn][0], "\t", new_List[isbn][1])

# Driver Code
N = int(input("Input number of books : "))
Books = [[0 for cost in range(2)] for isbn in range(N)]
for isbn in range(N):
    ISBN = int(input("Enter the ISBN : "))
    Books[isbn][0] = ISBN
    COST = int(input("Enter the cost : "))
    Books[isbn][1] = COST

print("The Books  are...")
print(Books)
while (True):
    print("\nDepartment Library Books Demo")
    print("1. Delete Duplicate Entries")
    print("2. Display Books in Ascending Order based on Cost books")
    print("3. Display total Number of Books with cost more than 500")
    print("4. Display new list which has cost less than 500")
    choice = int(input("Enter your choice : "))
    if (choice == 1):
        DeleteDuplicates(Books)
    elif (choice == 2):
        Sorting(Books, N)
    elif (choice == 3):
        MoreCost(Books, N)
    elif (choice == 4):
        LessCost(Books, N)
    else:
        print("Exiting")
        break
"""
Experiment No. 10 :
Write a python program for sparse matrix realization and operations on it-
Transpose, Fast Transpose and addition of two matrices
"""

def create(s, row_num, col_num, non_zero_values):
    s[0][0] = row_num
    s[0][1] = col_num
    s[0][2] = non_zero_values
    print()
    for k in range(1, non_zero_values + 1):
        row = int(input("Enter row value : "))
        col = int(input("Enter col value : "))
        element = int(input("Enter the element : "))
        s[k][0] = row
        s[k][1] = col
        s[k][2] = element

def display(s):
    print("Row\tcol\t Non_Zero_values")
    for i in range(0, (s[0][2] + 1)):
        for j in range(0, 3):
            print(s[i][j], "\t", end='')
        print()

def add(s1, s2):
    i = 1
    j = 1
    k = 1
    s3 = []
    if ((s1[0][0] == s2[0][0]) and (s1[0][1] == s2[0][1])):
        # traversing thru all the terms
        while ((i <= s1[0][2]) and (j <= s2[0][2])):
            if (s1[i][0] == s2[j][0]):
                temp = []
                if (s1[i][1] == s2[j][1]):
                    temp.append(s1[i][0])
                    temp.append(s1[i][1])
                    temp.append(s1[i][2] + s2[j][2])
                    s3.append(temp)
                    i += 1
                    j += 1
                    k += 1
                elif (s1[i][1] < s2[j][1]):
                    temp.append(s1[i][0])
                    temp.append(s1[i][1])
                    temp.append(s1[i][2])
                    s3.append(temp)
                    i += 1
                    k += 1
                else:
                    temp.append(s2[j][0])
                    temp.append(s2[j][1])
                    temp.append(s2[j][2])
                    s3.append(temp)
                    j += 1
                    k += 1
            elif (s1[i][0] < s2[j][0]):
                temp = []
                temp.append(s1[i][0])
                temp.append(s1[i][1])
                temp.append(s1[i][2])
                s3.append(temp)
                i += 1
                k += 1
            else:
                temp = []
                temp.append(s1[j][0])
                temp.append(s1[j][1])
                temp.append(s1[j][2])
                s3.append(temp)
                j += 1
                k += 1
        # copying remaining terms
        while (i <= s1[0][2]):  # s1 is greater than s2
            temp = []
            temp.append(s1[i][0])
            temp.append(s1[i][1])
            temp.append(s1[i][2])
            s3.append(temp)
            i += 1
            k += 1
        while (j <= s2[0][2]):  # s2 is greater than s1
            temp = []
            temp.append(s2[j][0])
            temp.append(s2[j][1])
            temp.append(s2[j][2])
            s3.append(temp)
            j += 1
            k += 1
            # assigning total rows, total columns
        # and total non zero values as a first row
        # in resultant matrix
        s3.insert(0, [s1[0][0], s1[0][1], k - 1])
    else:
        print("\nAddition is not possible")

    print("\nAddition of Sparse Matrix ...")
    print("Row  Col  Non_Zero_values")
    for row in s3:
        for element in row:
            print(element, end="    ")
        print()

def transpose(s1, row_num, col_num, s2, cols, non_zero_values):
    s2[0][0] = col_num
    s2[0][1] = row_num
    s2[0][2] = non_zero_values
    nxt = 1
    for c in range(0, col_num):
        # for each column scan all the terms for a 'term' in that column
        for Term in range(1, non_zero_values + 1):
            if (s1[Term][1] == c):
                # Interchange Row and Column
                s2[nxt][0] = s1[Term][1]
                s2[nxt][1] = s1[Term][0]
                s2[nxt][2] = s1[Term][2]
                nxt = nxt + 1

def fast_transpose(s1, row_num, col_num, s2, cols, non_zero_values):
    s2[0][0] = col_num
    s2[0][1] = row_num
    s2[0][2] = non_zero_values
    rterm = []
    rpos = []
    if non_zero_values > 0:
        for i in range(col_num):
            rterm.insert(i, 0)
        for i in range(1, non_zero_values + 1):
            # rterm[s1[i][1]]++
            index = s1[i][1]
            val = rterm.pop(index)
            rterm.insert(index, val + 1)
        rpos.insert(0, 1)
        for i in range(1, col_num + 1):
            # rpos[i]=rpos[i-1]+ rterm[(i - 1)]
            rpos_val = rpos[i - 1]
            rterm_val = rterm[i - 1]
            rpos.insert(i, (rpos_val + rterm_val))
        for i in range(1, non_zero_values + 1):
            j = rpos[s1[i][1]]
            s2[j][0] = s1[i][1]
            s2[j][1] = s1[i][0]
            s2[j][2] = s1[i][2]
            rpos[s1[i][1]] = j + 1

# Driver Code
print("\n Program for performing Sparse Matrix Operations")
while (True):
    print("\n1. Addition of Two Matrices")
    print("2. Simple Transpose")
    print("3. Fast Transpose")
    print("4. Exit")
    choice = int(input("Enter your choice : "))
    if (choice == 1):
        # addition of two matrices
        row_num1 = int(input("\nInput total number of rows for first matrix : "))
        col_num1 = int(input("Input total number of columns for first matrix : "))
        non_zero_values1 = int(input("Input total number of non-zero values : "))
        cols = 3
        s1 = [[0 for col in range(cols)] for row in range(non_zero_values1 + 1)]
        # creating first sparse matrix
        create(s1, row_num1, col_num1, non_zero_values1)
        print("\nFirst sparse matrix is ")
        display(s1)

        row_num2 = int(input("\nInput total number of rows for second matrix : "))
        col_num2 = int(input("Input total number of columns for second matrix : "))
        non_zero_values2 = int(input("Input total number of non-zero values : "))
        s2 = [[0 for col in range(cols)] for row in range(non_zero_values2 + 1)]
        # creating second sparse matrix
        create(s2, row_num2, col_num2, non_zero_values2)
        print("\nSecond sparse matrix is ")
        display(s2)
        # Performing and displaying addition of two sparse matrices
        add(s1, s2)
    elif (choice == 2):
        # Simple transpose
        row_num = int(input("\nInput total number of rows for first matrix : "))
        col_num = int(input("Input total number of columns for first matrix : "))
        non_zero_values = int(input("Input total number of non-zero values : "))
        cols = 3
        s = [[0 for col in range(cols)] for row in range(non_zero_values + 1)]
        trans_s = [[0 for col in range(cols)] for row in range(non_zero_values + 1)]
        create(s, row_num, col_num, non_zero_values)
        print("\nOriginal sparse matrix is ")
        display(s)
        transpose(s, row_num, col_num, trans_s, cols, non_zero_values)
        print("\nTransposed sparse matrix is ")
        display(trans_s)
    elif (choice == 3):
        # fast transpose
        row_num = int(input("\nInput total number of rows for first matrix : "))
        col_num = int(input("Input total number of columns for first matrix : "))
        non_zero_values = int(input("Input total number of non-zero values : "))
        cols = 3
        s = [[0 for col in range(cols)] for row in range(non_zero_values + 1)]
        trans_s = [[0 for col in range(cols)] for row in range(non_zero_values + 1)]
        create(s, row_num, col_num, non_zero_values)
        print("\nOriginal sparse matrix is ")
        display(s)
        fast_transpose(s, row_num, col_num, trans_s, cols, non_zero_values)
        print("\nTransposed sparse matrix is ")
        display(trans_s)
    else:
        print("\nExiting")
        break
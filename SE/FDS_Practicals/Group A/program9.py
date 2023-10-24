"""
Experiment No. 9 :
Write a Python Program to compute following computation on matrices :
    a) Addition of two matrices
    b) Subtraction of two matrices
    c) Multiplication of two matrices
    d) Transpose of a matrix
"""

import numpy

# initializing matrices
x = numpy.array([[1, 2], [4, 5]])
y = numpy.array([[7, 8], [9, 10]])

# using add() to add matrices
print("\nThe element wise addition of matrix is : ")
print(numpy.add(x, y))

# using subtract() to subtract matrices
print("\nThe element wise subtraction of matrix is : ")
print(numpy.subtract(x, y))

# using dot() to multiply matrices
print("\nThe product of matrices is : ")
print(numpy.dot(x,y))

# using "T" to transpose the matrix
print("\nThe transpose of given matrix is : ")
print(x.T)
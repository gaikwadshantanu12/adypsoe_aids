"""
Experiment No. 4 :
Write a Python program that computes the net amount of a bank account based a transaction log from console input.
The transaction log format is shown as following:
D 100 W 200 (Withdrawal is not allowed if balance is going negative.
Write functions for withdraw and deposit) D means deposit while W means withdrawal.
Suppose the following input is supplied to the program: D 300 D 300 W 200 D 100 Then, the output should be: 500
"""

balance = 0
while True:
    # input the transaction
    myStr = input("Enter transaction : ")
    transaction = myStr.split(" ")

    type = transaction[0]
    amount = int(transaction[1])
    # "D" for deposit, "W" for withdrawal
    if (type == "D" or type == "d"):
        balance += amount
    elif (type == "W" or type == "w"):
        balance -= amount
    else:
        print("Exiting")
        break

# print the net amount
print("Total Balance : ", balance)
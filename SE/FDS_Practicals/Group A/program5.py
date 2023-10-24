"""
Experiment No. 5 :
Write a Python program to compute following operations on String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular character in the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string.
"""

# a) To display word with the longest length
sentence = input("Enter sentence : ")
longest = max(sentence.split(), key=len)
print("\nLongest word is : ", longest)
print("And its length is : ", len(longest))

# b) To determines the frequency of occurrence of particular character in the string
# using naive method to get count of each element in string
all_freq = {}

for i in sentence:
    if i in all_freq:
        all_freq[i] += 1
    else:
        all_freq[i] = 1

# printing result
print("Count of all characters in sentence is :\n "
      + str(all_freq))

# c) To check whether given string is palindrome or not
text="malayalam"
print("\nGiven text is "+text)
rev=reversed(text)
if list(text)==list(rev):
    print("its a palindrome")
else:
    print("its not a palindrome")

# d) To display index of first appearance of the substring
sub_str1 =str(input("\nEnter word : "))
print("Index of first appearance of the substring "+sub_str1+" is - ",sentence.find(sub_str1))

#check if Substring found or not.
if(sentence.find(sub_str1)==-1):
    print("Result - Substring Not Found")
else:
    print("Result - Substring found")

#  e) To count the occurrences of each word in a given string.
print("\nFollowing are the count the frequency of each word in a given string")
def freq(sentence):
    # break the string into list of words
    sentence = sentence.split()
    str2 = []

    # loop till string values present in list str
    for i in sentence:
        # checking for the duplicacy
        if i not in str2:
            # insert value in str2
            str2.append(i)
    for i in range(0, len(str2)):
        # count the frequency of each word(present in str2) in sentence and print
        print('count of frequency', str2[i], 'is :', sentence.count(str2[i]))

def main():
    # call freq function
    freq(sentence)

main()  # call main function
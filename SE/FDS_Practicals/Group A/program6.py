"""
Experiment No. 6 :
It is decided that weekly greetings are to be furnished to wish the students having their birthdays in that week.
The consolidated sorted list with desired categorical information is to be provided to the authority.
Write a python program to store students PRNs with date and month of birth.
Let List_A and List_B be the two list for two SE Computer divisions.
Lists are sorted on date and month. Merge these two lists into third list “List_SE_Comp_DOB” resulting in
sorted information about Date of Birth of SE Computer students.
"""

from datetime import datetime

List_A = [{'PRN': 'a101', 'birthdate': '02-03'},
          {'PRN': 'a102', 'birthdate': '01-12'},
          {'PRN': 'a113', 'birthdate': '09-01'},
          {'PRN': 'a104', 'birthdate': '01-05'}
          ]

# printing initial list
print("List A is...")
for item in List_A:
    print(item)

# code to sort list on date
List_A.sort(key=lambda x: datetime.strptime(x['birthdate'], '%d-%m'))

# printing final list
print("After Sorting - ")
for item in List_A:
    print(item)

List_B = [{'PRN': 'b111', 'birthdate': '05-10'},
          {'PRN': 'b103', 'birthdate': '12-02'},
          {'PRN': 'b112', 'birthdate': '09-09'},
          {'PRN': 'b114', 'birthdate': '16-05'}
          ]

# printing initial list
print("\nList B is...")
for item in List_B:
    print(item)

# code to sort list on date
List_B.sort(key=lambda x: datetime.strptime(x['birthdate'], '%d-%m'))

# printing final list
print("After Sorting - ")
for item in List_B:
    print(item)
List_SE_Comp_DOB = []
List_SE_Comp_DOB = List_A + List_B
print("\n Resultant Merged List sorted according to Birthdate is ...");
List_SE_Comp_DOB.sort(key=lambda x: datetime.strptime(x['birthdate'], '%d-%m'))
for item in List_SE_Comp_DOB:
    print(item)
"""
To create ADT that implement the "set" concept.
a. Add (new Element) - Place a value into the set ,
b. Remove (element) Remove the value
c. Contains (element) Return true if element is in collection,
d. Size () Return number of values in collection Iterator () Return an iterator used to loop over collection,
e. Intersection of two sets ,
f. Union of two sets,
g. Difference between two sets,
h. Subset
"""

mySet = set()
mySet1 = set()
mySet2 = set()

def insertSingleElement(element_to_insert):
    mySet.add(element_to_insert)

def insertMultipleElement(list_of_elements):
    mySet.update(list_of_elements)

def searchElement(element_to_search):
    if element_to_search in mySet:
        print("Element present in set !")
    else:
        print("Element not present in set !")

def removeElement(element_to_remove):
    if element_to_remove in mySet:
        mySet.remove(element_to_remove)
        print("Element removed successfully !")
    else:
        print("Element not present in set ! We can't remove it !")

def displayElements():
    for i in mySet:
        print(i,end="\t")
    print()

def lengthOfSet():
    print(f"Length of Set = {len(mySet)}")

def takeInputForUnionAndIntersection():
    mySet1.clear()
    mySet2.clear()
    no_of_elements = int(input("\nHow many elements you want to insert in set-1 ? "))
    list_of_elements = list()
    for i in range(no_of_elements):
        list_of_elements.append(input(f"Enter element {i + 1} : "))
    mySet1.update(list_of_elements)

    no_of_elements = int(input("\nHow many elements you want to insert in set-2 ? "))
    list_of_elements = list()
    for i in range(no_of_elements):
        list_of_elements.append(input(f"Enter element {i + 1} : "))
    mySet2.update(list_of_elements)

def unionOfTwoSets():
    takeInputForUnionAndIntersection()
    print(f"\nSet-1 = {mySet1} \t& \tSet-2 = {mySet2}")
    print(f"Union of Sets = {mySet1.union(mySet2)}")

def intersectionOfTwoSets():
    takeInputForUnionAndIntersection()
    print(f"\nSet-1 = {mySet1} \t& \tSet-2 = {mySet2}")
    print(f"Intersection of Sets = {mySet1.intersection(mySet2)}")

def differenceOfTwoSets():
    takeInputForUnionAndIntersection()
    print(f"\nSet-1 = {mySet1} \t& \tSet-2 = {mySet2}")
    print(f"Difference of Sets #A-B = {mySet1.difference(mySet2)}")
    print(f"Difference of Sets #B-A = {mySet2.difference(mySet1)}")

def symmetricDifferenceOfTwoSets():
    takeInputForUnionAndIntersection()
    print(f"\nSet-1 = {mySet1} \t& \tSet-2 = {mySet2}")
    print(f"Symmetric Difference of Sets = {mySet1.symmetric_difference(mySet2)}")

def displayMenu():
    print(f"\n!!!!!!!!!!!!!!! MENU !!!!!!!!!!!!!!!"
          f"\n01. Insert Single Element"
          f"\n02. Insert Multiple Element"
          f"\n03. Search Particular Element"
          f"\n04. Remove Particular Element"
          f"\n05. Display Set Elements"
          f"\n06. Length of Set"
          f"\n07. Union of Two Sets"
          f"\n08. Intersection of Two Sets"
          f"\n09. Difference of Two Sets"
          f"\n10. Symmetric Difference of Two Sets"
          f"\n0. Exit")

while True:
    displayMenu()

    choice = int(input("Enter Your Choice : "))

    if choice == 0:
        break

    elif choice not in range(1, 11):
        print("Invalid Choice !")

    elif choice == 1:
        element_to_insert = int(input("\nEnter the element to insert : "))
        insertSingleElement(element_to_insert)

    elif choice == 2:
        no_of_elements = int(input("\nHow many elements you want to insert ? "))
        list_of_elements = list()
        for i in range(no_of_elements):
            list_of_elements.append(int(input(f"Enter element no. {i+1} : ")))
        insertMultipleElement(list_of_elements)

    elif choice == 3:
        element_to_search = int(input("\nEnter element to search : "))
        searchElement(element_to_search)

    elif choice == 4:
        element_to_remove = int(input("\nEnter element to remove : "))
        removeElement(element_to_remove)

    elif choice == 5:
        displayElements()

    elif choice == 6:
        lengthOfSet()

    elif choice == 7:
        unionOfTwoSets()

    elif choice == 8:
        intersectionOfTwoSets()

    elif choice == 9:
        differenceOfTwoSets()

    elif choice == 10:
        symmetricDifferenceOfTwoSets()

print("\n\nThank You !!\tProgrammed By - Shantanu Anant Gaikwad !!")
import Pyro4

# Get the server object using its URI
uri = input("Enter the server URI : ")
string_concatenator = Pyro4.Proxy(uri)

# Get inputs string from the user
str1 = input("Enter first string : ")
str2 = input("Enter second string : ")

# Call the remote method on the server
result = string_concatenator.concatenate(str1, str2)

print("Concatenated String : ", result)
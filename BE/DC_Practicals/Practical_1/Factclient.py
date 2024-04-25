import xmlrpc.client
# Create an XML-RPC client
with xmlrpc.client.ServerProxy("http://localhost:8000/RPC2") as proxy:
    try:
        # Replace 5 with the desired integer value
        #input_value = 5
        input_value_str=input("Enter the number : ")
        input_value=int(input_value_str)
        
        result = proxy.calculate_factorial(input_value)
        print(f"Factorial of {input_value} is : {result}")
    except Exception as e:
        print(f"Error: {e}")

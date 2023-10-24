# implement Diffie Hellman key exchange algorithm 

import random

def generate_key(p, g, x):
    return (g ** x) % p

def generate_shared_secret(p, key, x):
    return (key ** x) % p

# Generate random prime number p
p = random.randint(1000, 5000)
while True:
    if all(p % i != 0 for i in range(2, int(p ** 0.5) + 1)):
        break
    p += 1

# Generate random primitive root g
g = random.randint(2, p-2)
while pow(g, (p-1)//2, p) == 1:
    g = random.randint(2, p-2)

# Generate random private keys
a = random.randint(2, p-1)
b = random.randint(2, p-1)

# Generate public keys
A = generate_key(p, g, a)
B = generate_key(p, g, b)

# Generate shared secret keys
s1 = generate_shared_secret(p, B, a)
s2 = generate_shared_secret(p, A, b)

# Print the keys
print("p:", p)
print("g:", g)
print("a:", a)
print("A:", A)
print("b:", b)
print("B:", B)
print("s1:", s1)
print("s2:", s2)

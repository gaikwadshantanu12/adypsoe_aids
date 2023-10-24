#  implementation of RSA algorithm 

import random
def generate_keypair(p, q):
    n = p * q
    phi = (p - 1) * (q - 1)
    e = random.randrange(1, phi)
    gcd_result = gcd(e, phi)
    while gcd_result != 1:
        e = random.randrange(1, phi)
        gcd_result = gcd(e, phi)
    d = modinv(e, phi)
    return ((e, n), (d, n))

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    return x % m

def egcd(a, b):
    if a == 0:
        return (b, 0, 1)
    else:
        gcd, x, y = egcd(b % a, a)
        return (gcd, y - (b // a) * x, x)

def encrypt(pk, plaintext):
    e, n = pk
    cipher = [pow(ord(char), e, n) for char in plaintext]
    return cipher

def decrypt(pk, ciphertext):
    d, n = pk
    plain = [chr(pow(char, d, n)) for char in ciphertext]
    return ''.join(plain)

if __name__ == '__main__':
    p = int(input("Enter a prime number (p): "))
    q = int(input("Enter another prime number (q): "))
    public, private = generate_keypair(p, q)
    print("Public key: ", public)
    print("Private key: ", private)
    message = input("Enter a message to encrypt with the public key: ")
    ciphertext = encrypt(public, message)
    print("Encrypted message: ", ciphertext)
    plaintext = decrypt(private, ciphertext)
    print("Decrypted message: ", plaintext)

# implement DES algorithm 

import binascii
from Cryptodome.Cipher import DES

def pad(data):
    padding = 8 - (len(data) % 8)
    return data + (b'\0' * padding)

def des_encrypt(key, data):
    data = pad(data)
    iv = b'\0' * 8
    des = DES.new(key, DES.MODE_CBC, iv)
    return des.encrypt(data)

def des_decrypt(key, data):
    iv = b'\0' * 8
    des = DES.new(key, DES.MODE_CBC, iv)
    return des.decrypt(data)

key = b'secret_k'
plaintext = b'Hello Students, Please come to class'

ciphertext = des_encrypt(key, plaintext)
print('Ciphertext : ', binascii.hexlify(ciphertext))

decryptedtext = des_decrypt(key, ciphertext)
print('Decrypted text : ', decryptedtext.strip())

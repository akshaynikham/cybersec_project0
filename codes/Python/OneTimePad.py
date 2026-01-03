import os 

def xorstring(s1, s2):
    return bytes([a^b for a,b in zip(s1, s2)])

message = "Hello".encode()
key = os.urandom(len(message))
ciphertext = xorstring(message,key)
decrypted = xorstring(ciphertext, key)

print(f"Original: {message.decode()}")
print(f"key (Hex): {key.hex()}")
print(f"Encrypted: {ciphertext.hex()}")
print(f"Decrypted: {decrypted.decode()}")





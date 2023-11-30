from Crypto.Cipher import DES3
from Crypto.Util.Padding import pad, unpad
from Crypto.Random import get_random_bytes
from Crypto.Util.strxor import strxor

def encrypt_block(plaintext_block, iv, key):
    cipher = DES3.new(key, DES3.MODE_ECB)
    xor_result = strxor(plaintext_block, iv)
    ciphertext_block = cipher.encrypt(xor_result)
    return ciphertext_block

def encrypt_cbc(plaintext, key):
    cipher = DES3.new(key, DES3.MODE_ECB)
    block_size = DES3.block_size

    # Generate a random IV (Initialization Vector)
    iv = get_random_bytes(block_size)

    # Pad the plaintext to be a multiple of block_size
    padded_plaintext = pad(plaintext.encode(), block_size)

    # Divide the plaintext into blocks
    blocks = [padded_plaintext[i:i+block_size] for i in range(0, len(padded_plaintext), block_size)]

    # Initialize the ciphertext with the IV
    ciphertext = iv

    # Encrypt each block in CBC mode
    for block in blocks:
        encrypted_block = encrypt_block(block, ciphertext[-block_size:], key)
        ciphertext += encrypted_block

    return ciphertext

def main():
    # Example plaintext and key
    plaintext = "This is a secret message."
    key = get_random_bytes(24)  # 3DES key size is 24 bytes

    # Encrypt using 3DES in CBC mode
    ciphertext = encrypt_cbc(plaintext, key)

    print("Plaintext:", plaintext)
    print("Ciphertext:", ciphertext.hex())

if __name__ == '__main__':
    main()

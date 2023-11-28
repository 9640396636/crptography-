#include <stdio.h>
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return -1; // Inverse does not exist
}
void decryptAffineCipher(int a, int b, char ciphertext[]) {
    int m = 26; // Size of the alphabet
    int aInverse = modInverse(a, m);   
    if (aInverse == -1) {
        printf("Modular inverse does not exist.\n");
        return;
    }
    printf("Decrypted message: ");
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            int x = ciphertext[i] - 'A';
            int decryptedChar = (aInverse * (x - b + m)) % m;
            printf("%c", (char)(decryptedChar + 'A'));
        } else {
            printf("%c", ciphertext[i]);
        }
    }
    printf("\n");
}
int main() {
    char ciphertext[] = "YOURCIPHERTEXT";   
    int a = 1; 
    int b1 = 'B' - 'A'; 
    int b2 = 'U' - 'A';
    for (a = 1; a < 26; a++) {
        if ((a * b1) % 26 == 1) {
            break;
        }
    }
    printf("Found key: a = %d, b = %d\n", a, b1);
    decryptAffineCipher(a, b1, ciphertext);
    return 0;
}

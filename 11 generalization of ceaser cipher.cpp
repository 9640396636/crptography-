#include <stdio.h>
#include <ctype.h>
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++)
        if ((a * x) % m == 1)
            return x;
    return 1;
}
char encrypt(char ch, int a, int b) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        return (char)((a * (ch - base) + b) % 26 + base);
    }
    return ch;
}
char decrypt(char ch, int a, int b) {
    if (isalpha(ch)) {
        char base = isupper(ch) ? 'A' : 'a';
        int aInverse = modInverse(a, 26);
        return (char)((aInverse * (ch - base - b + 26) % 26) + base);
    }
    return ch;
}
int main() {
    int a, b;
   
    printf("Enter the value of a (must be coprime with 26): ");
    scanf("%d", &a);
    if (a <= 0 || a % 2 == 0 || a % 13 == 0) {
        printf("Invalid value of 'a'. It must be a positive integer coprime with 26.\n");
        return 1;
    }
    printf("Enter the value of b: ");
    scanf("%d", &b);
    char plaintext = 'A';
    char ciphertext = encrypt(plaintext, a, b);
    printf("Encryption Example:\n");
    printf("Plaintext: %c\n", plaintext);
    printf("Ciphertext: %c\n", ciphertext);
    char decryptedText = decrypt(ciphertext, a, b);
    printf("\nDecryption Example:\n");
    printf("Ciphertext: %c\n", ciphertext);
    printf("Decrypted Text: %c\n", decryptedText);
    return 0;
}

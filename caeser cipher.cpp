#include <stdio.h>
#include <string.h>
void caesarCipherEncrypt(char *input, int key) {
    int i;
    for (i = 0; input[i] != '\0'; ++i) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = ((input[i] - 'A' + key) % 26) + 'A';
        }
        else if (input[i] >= 'a' && input[i] <= 'z') {
            input[i] = ((input[i] - 'a' + key) % 26) + 'a';
        }
    }
}
void caesarCipherDecrypt(char *input, int key) {
    caesarCipherEncrypt(input, -key);
}
int main() {
    char message[100];
    int key;
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = '\0';
    printf("Enter encryption key (1-25): ");
    scanf("%d", &key);
    caesarCipherEncrypt(message, key);
    printf("Encrypted message: %s\n", message);
    caesarCipherDecrypt(message, key);
    printf("Decrypted message: %s\n", message);
    return 0;
}

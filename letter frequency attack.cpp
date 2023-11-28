#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define ALPHABET_SIZE 26
void letterFrequencyAttack(char *ciphertext, int topPlaintexts) {
    int i, j, k;
    int frequency[ALPHABET_SIZE] = {0};
    for (i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            frequency[ciphertext[i] - base]++;
        }
    }
    int maxFrequency = 0;
    char mostFrequentLetter;
    for (i = 0; i < ALPHABET_SIZE; i++) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            mostFrequentLetter = 'A' + i;
        }
    }
    printf("Most frequent letter in ciphertext: %c\n", mostFrequentLetter);
    int shift = mostFrequentLetter - 'E';
    if (shift < 0) {
        shift += ALPHABET_SIZE;
    }
    printf("Estimated shift: %d\n", shift);
    printf("\nTop %d possible plaintexts:\n", topPlaintexts);
    for (j = 0; j < topPlaintexts; j++) {
        printf("%d. ", j + 1);
        for (k = 0; k < strlen(ciphertext); k++) {
            if (isalpha(ciphertext[k])) {
                char base = isupper(ciphertext[k]) ? 'A' : 'a';
                char decryptedChar = (ciphertext[k] - base - shift + ALPHABET_SIZE) % ALPHABET_SIZE + base;
                printf("%c", decryptedChar);
            } else {
                printf("%c", ciphertext[k]);
            }
        }
        printf("\n");
        shift++; 
    }
}
int main() {
    char ciphertext[] = "AHGS SHJS EGS";
    int topPlaintexts = 5;
    printf("Ciphertext: %s\n", ciphertext);
    letterFrequencyAttack(ciphertext, topPlaintexts);

    return 0;
}

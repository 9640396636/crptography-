#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// English letter frequency table (source: https://en.wikipedia.org/wiki/Letter_frequency)
const float letterFrequency[ALPHABET_SIZE] = {
    0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 0.06094,
    0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749, 0.07507, 0.01929,
    0.00095, 0.05987, 0.06327, 0.09056, 0.02758, 0.00978, 0.02360, 0.00150,
    0.01974, 0.00074
};

// Function to calculate the sum of squared differences between observed and expected letter frequencies
float calculateFitness(const int* letterCounts, int textLength) {
    float fitness = 0.0;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        float observedFrequency = (float)letterCounts[i] / textLength;
        fitness += (observedFrequency - letterFrequency[i]) * (observedFrequency - letterFrequency[i]);
    }

    return fitness;
}

// Function to decrypt the ciphertext using a given key
void decrypt(const char* ciphertext, int key, char* plaintext) {
    int i = 0;

    while (ciphertext[i] != '\0') {
        if (ciphertext[i] == ' ') {
            plaintext[i] = ' ';
        } else {
            plaintext[i] = ((ciphertext[i] - 'A' - key + ALPHABET_SIZE) % ALPHABET_SIZE) + 'A';
        }
        i++;
    }

    plaintext[i] = '\0';
}

int main() {
    char ciphertext[1000];
    printf("Enter the ciphertext (uppercase letters and spaces only): ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    int letterCounts[ALPHABET_SIZE] = {0};
    int textLength = 0;

    // Count the frequency of each letter in the ciphertext
    for (int i = 0; ciphertext[i] != '\0'; i++) {
        if (ciphertext[i] >= 'A' && ciphertext[i] <= 'Z') {
            letterCounts[ciphertext[i] - 'A']++;
            textLength++;
        }
    }

    // Perform a frequency analysis attack
    printf("\nPossible plaintexts in rough order of likelihood:\n");

    for (int key = 0; key < ALPHABET_SIZE; key++) {
        char plaintext[1000];
        decrypt(ciphertext, key, plaintext);
        float fitness = calculateFitness(letterCounts, textLength);

        // Print the decrypted text and fitness value
        printf("\nKey: %2d | Fitness: %f\n", key, fitness);
        printf("Plaintext: %s\n", plaintext);
    }

    return 0;
}

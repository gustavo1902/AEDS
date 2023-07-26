#include <stdio.h>
#include <string.h>

// Função para comprimir uma string usando Run-Length Encoding (RLE)
char* compressRLE(const char* input) {
    int input_length = strlen(input);
    char* compressed = (char*)malloc(2 * input_length * sizeof(char)); // Estimativa de tamanho máximo de saída

    int compressed_index = 0;
    int count = 1;

    for (int i = 1; i <= input_length; i++) {
        if (input[i] != input[i - 1] || i == input_length) {
            compressed[compressed_index++] = input[i - 1];
            compressed[compressed_index++] = count + '0';
            count = 1;
        } else {
            count++;
        }
    }

    compressed[compressed_index] = '\0';
    return compressed;
}

// Função para descomprimir uma string usando Run-Length Encoding (RLE)
char* decompressRLE(const char* input) {
    int input_length = strlen(input);
    char* decompressed = (char*)malloc(input_length * sizeof(char)); // Estimativa de tamanho máximo de saída

    int decompressed_index = 0;
    for (int i = 0; i < input_length; i += 2) {
        char character = input[i];
        int count = input[i + 1] - '0';
        for (int j = 0; j < count; j++) {
            decompressed[decompressed_index++] = character;
        }
    }

    decompressed[decompressed_index] = '\0';
    return decompressed;
}

int main() {
    const char* original = "aaabbbbccddddeeee";
    printf("Original: %s\n", original);

    char* compressed = compressRLE(original);
    printf("Compressed: %s\n", compressed);

    char* decompressed = decompressRLE(compressed);
    printf("Decompressed: %s\n", decompressed);

    free(compressed);
    free(decompressed);

    return 0;
}

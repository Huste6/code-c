#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void copyByCharacter(FILE* source, FILE* destination) {
    clock_t start = clock();
    int ch;
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }
    clock_t end = clock();
    double executionTime = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
    printf("Copy by character completed in %.2f milliseconds.\n", executionTime);
}

void copyByLine(FILE* source, FILE* destination) {
    clock_t start = clock();
    char line[256];
    while (fgets(line, sizeof(line), source) != NULL) {
        fputs(line, destination);
    }
    clock_t end = clock();
    double executionTime = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
    printf("Copy by line completed in %.2f milliseconds.\n", executionTime);
}

void copyByBlock(FILE* source, FILE* destination, int blockSize) {
    clock_t start = clock();
    char* buffer = (char*)malloc(blockSize);
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, blockSize, source)) > 0) {
        fwrite(buffer, 1, bytesRead, destination);
    }
    free(buffer);
    clock_t end = clock();
    double executionTime = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;
    printf("Copy by block (block size: %d bytes) completed in %.2f milliseconds.\n", blockSize, executionTime);
}

int main() {
    char sourceFile[256];
    char destinationFile[256];
    int choice;
    int blockSize;

    printf("Enter the path of the source file: ");
    fgets(sourceFile, sizeof(sourceFile), stdin);
    sourceFile[strcspn(sourceFile, "\n")] = '\0';

    printf("Enter the path of the destination file: ");
    fgets(destinationFile, sizeof(destinationFile), stdin);
    destinationFile[strcspn(destinationFile, "\n")] = '\0';

    FILE* source = fopen(sourceFile, "r");
    if (source == NULL) {
        printf("Failed to open the source file.\n");
        return 1;
    }

    FILE* destination = fopen(destinationFile, "w");
    if (destination == NULL) {
        printf("Failed to open the destination file.\n");
        fclose(source);
        return 1;
    }

    fseek(source, 0L, SEEK_END);
    long sourceFileSize = ftell(source);
    rewind(source);

    if (sourceFileSize < 640 * 1024) {
        printf("Source file size must be at least 640KB.\n");
        fclose(source);
        fclose(destination);
        return 1;
    }

    while (1) {
        printf("\nCopy Menu:\n");
        printf("1. Copy by character\n");
        printf("2. Copy by line\n");
        printf("3. Copy by block - optional size\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                copyByCharacter(source, destination);
                break;
            case 2:
                copyByLine(source, destination);
                break;
            case 3:
                printf("Enter the block size: ");
                scanf("%d", &blockSize);
                copyByBlock(source, destination, blockSize);
                break;
            case 4:
                fclose(source);
                fclose(destination);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

        rewind(source);
        rewind(destination);
    }

    return 0;
}

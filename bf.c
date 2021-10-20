#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* readFile(char* filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error: unable to open file\n");
        exit(1);
    }

    fseek(file, 0L, SEEK_END);
    long file_len = ftell(file);
    rewind(file);

    char *file_buf = malloc(file_len * sizeof(char) + 1);
    file_buf[file_len] = '\0';

    fread(file_buf, file_len, sizeof(char), file);
    fclose(file);

    return file_buf;
}

void interpret(char* source, int tape_size) {
    unsigned char tape[tape_size]; // max tape size is 30000 but 9999 is sufficient for most small programs
    unsigned char* head = tape;
    char current_char;
    size_t i;
    size_t loop;

    for (i = 0; source[i] !=0; i++) {
        current_char = source[i];
        if (current_char == '>') {
            ++head;
        } else if (current_char == '<') {
            --head;
        } else if (current_char == '+') {
            ++*head;
        } else if (current_char == '-') {
            --*head;
        } else if (current_char == '.') {
            putchar(*head);
        } else if (current_char == ',') {
            *head = getchar();
        } else if (current_char == '[') {
            continue;
        } else if (current_char == ']' && *head) {
            loop = 1;
            while (loop > 0) {
                current_char = source[--i];
                if (current_char == '[') {
                    loop--;
                } else if (current_char == ']') {
                    loop++;
                }
            }
        }
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s -f file.bf [tape size (optional)]\n", argv[0]);
        exit(2);
    }

    int tape_size = (argc == 4) ? atoi(argv[3]) : 9999;

    //printf("Executing %s with tape size: %d\n", argv[2], tape_size); // add verbose flag
    char *file_buf = readFile(argv[2]);
    interpret(file_buf, tape_size);  
    free(file_buf);
}
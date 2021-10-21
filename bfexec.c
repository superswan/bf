#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

unsigned char* interpret(char* source, int tape_size) {
    unsigned char tape[tape_size]; // max tape size is 30000 but 9999 is sufficient for most small programs
    unsigned char* head = tape;
    char current_char;
    size_t i;
    size_t loop;
    int output_length = 1;

    unsigned char* output = malloc(1);
    output[0] = "\0";

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
            //putchar(*head);
            output_length+=1;
            output = realloc(output, output_length+1);
            output[output_length-1] = (*head);
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

    return output;
}

char *bf= \
">--->--->--->->--->->--->>->>->->>->->+++>+++>-->--->->->++>+++>--->-->--->->+>->->>--->->++>+++>--->+>+>--->+>->->+++>+++>-->-->--->->+[<+++[-<+++++++>]<+++[-<+++++++>]<+++[.>]<]";

int main() {
    unsigned char* bf_cmd = interpret(bf, 9999);

    printf("%s", bf_cmd);
   
    return 0;
}
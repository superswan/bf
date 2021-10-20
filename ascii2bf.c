/*
Converts ASCII characters to brainfuck program.

example:
    File 'helloworld' contains string "Hello, World!"
    $ ascii2bf "$(cat helloworld)"
    >--->--->--->++>+>--->->--->->>-->->->->->+++>-->->>++>-->+>+>--->->+++>--->+++>-->->>-->->>-->->>--->->->>-->+[<+++[-<+++++++>]<+++[-<+++++++>]<+++[.>]<]
    $ ascii2bf "$(cat helloworld)" > helloworld.bf
    $ bf -f helloworld.bf
    Hello, World!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char *argv[]) {
    char *text = argv[1];
    int text_length = strlen(text);
    
    char byte;
    char *bfchar;
    int bfchar_size;

    char *header = ">--->--->--->";
    char *footer = "+[<+++[-<+++++++>]<+++[-<+++++++>]<+++[.>]<]";
    char *iter[] = { 
        "---",
        "--",
        "-",
        "",
        "+",
        "++",
        "+++"
    };
    
    int output_length = strlen(header);
    int footer_length = strlen(footer);

    char *output_string = malloc(output_length + 1);
    strcpy(output_string, header);

    for (int i = text_length-1; i >= 0; i--) {
        byte = text[i];

        for (int j = 0; j < 3; j++) {
            bfchar = iter[byte % 7];
            byte = floor(byte / 7);
            bfchar_size = strlen(bfchar);
            
            output_length += bfchar_size + 2;
            output_string = (char *)realloc(output_string, output_length);
            strncat(output_string, bfchar, bfchar_size + 1);
            strncat(output_string, ">", 2);
        }      
    }

    output_length += footer_length+1;
    output_string = (char *)realloc(output_string, output_length);
    strncat(output_string, footer, footer_length+2);
    printf("%s\n", output_string);

    free(output_string);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bwt.h"
#include "buffer.h"

char *file_to_string(FILE *file);
void tr(char *text, char target, char replacement);

int main(int argc, char **argv) {
    char *message = file_to_string(stdin);
    tr(message, '\n', '$');
    char *transformed = bwt(message);
    printf("%s\n", transformed);
    free(transformed);
    free(message);
    return 0;
}

char *file_to_string(FILE *file) {
    Buffer *buffer = create_buffer();
    char block[1025];
    while (! feof(file)) {
        int bytes_read = fread(block, 1, 1024, file);
        block[bytes_read] = '\0';
        buffer_append(buffer, block);
    }
    return drop_buffer(buffer);
}

void tr(char *text, char target, char replacement) {
    for (int i = 0; i < strlen(text); i++) {
        if (text[i] == target) {
            text[i] = replacement;
        }
    }
}

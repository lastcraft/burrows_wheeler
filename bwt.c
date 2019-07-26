#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"

char *file_to_string(FILE *file);

int main(int argc, char **argv) {
    char *message = file_to_string(stdin);
    printf("%s\n", message);
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

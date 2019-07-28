#include <stdlib.h>
#include <stdio.h>
#include "buffer.h"
#include "ring.h"

char *file_to_string(FILE *file);

int main(int argc, char **argv) {
    char *message = file_to_string(stdin);
    printf("%s\n", message);
    Ring *ring1 = create_ring(message, 0);
    char *text_0 = ring_to_string(ring1);
    printf("%s\n", text_0);
    free(text_0);
    Ring *ring2 = create_ring(message, 1);
    char *text_1 = ring_to_string(ring2);
    printf("%s\n", text_1);
    free(text_1);
    free(ring2);
    free(ring1);
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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "buffer.h"
#include "ring.h"

char *file_to_string(FILE *file);
void tr(char *text, char target, char replacement);
char *bwt(char *text);
int compare_ring_pointer(const void *ringp1, const void *ringp2);

int main(int argc, char **argv) {
    char *message = file_to_string(stdin);
    tr(message, '\n', '$');
    printf("\"%s\"\n", message);
    char *transformed = bwt(message);
    printf("\"%s\"\n", transformed);
    free(transformed);
    free(message);
    return 0;
}

char *bwt(char *text) {
    int length = strlen(text);
    Ring **ring_list = (Ring **)malloc(sizeof(Ring *) * length);
    for (int i = 0; i < length; i++) {
        ring_list[i] = create_ring(text, i);
    }
    qsort(ring_list, length, sizeof(Ring *), compare_ring_pointer);
    char *transformed = (char *)malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < length; i++) {
        transformed[i] = at(ring_list[i], length - 1);
    }
    transformed[length] = '\0';
    for (int i = 0; i < length; i++) {
        free_ring(ring_list[i]);
    }
    free(ring_list);
    return transformed;
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

int compare_ring_pointer(const void *ringp1, const void *ringp2) {
    return compare_ring(*(Ring **)ringp1, *(Ring **)ringp2);
}


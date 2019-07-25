#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    size_t memory_size;
    unsigned long length;
    char *characters;
} Buffer;

Buffer *create_buffer(void);
int buffer_append(Buffer *buffer, char *suffix);
char *drop_buffer(Buffer *buffer);
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

Buffer *create_buffer(void) {
    Buffer *buffer = (Buffer *)malloc(sizeof(Buffer));
    buffer->memory_size = 1024;
    buffer->characters = (char *)malloc(buffer->memory_size * sizeof(char));
    buffer->length = 0;
    buffer->characters[buffer->length] = '\0';
    return buffer;
}

int buffer_append(Buffer *buffer, char *suffix) {
    if (buffer == NULL) {
        return 0;
    }
    if (buffer->memory_size < buffer->length + strlen(suffix)) {
        buffer->memory_size = buffer->length * 2 + strlen(suffix);
        buffer->characters = (char *)realloc(buffer->characters, buffer->memory_size * sizeof(char));
        if (buffer->characters == NULL) {
            free(buffer);
            return 0;
        }
    }
    strncpy(buffer->characters + buffer->length, suffix, strlen(suffix));
    buffer->length = buffer->length + strlen(suffix);
    buffer->characters[buffer->length] = '\0';
    return strlen(suffix);
}

char *drop_buffer(Buffer *buffer) {
    char *characters = buffer->characters;
    free(buffer);
    return characters;
}

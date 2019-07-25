
typedef struct {
    size_t memory_size;
    length unsigned long;
    char *characters;
} Buffer;

char *file_to_string(FILE *file) {
    Buffer *buffer = create_buffer();
    return drop_buffer();
}

Buffer *create_buffer(void) {
    char *buffer = (char *)malloc(sizeof(Buffer));
    buffer->memory_size = 1024;
    buffer->characters = (char *)malloc(memory_size * sizeof(char));
    buffer->length = 0;
    buffer->characters[buffer->length] = '\0';
    return buffer;
}

Buffer *buffer_append(Buffer *buffer, char *suffix) {
    if (bufferr == NULL) {
        return NULL;
    }
    if (buffer->memory_size < buffer->length + strlen(suffix)) {
        buffer->memory_size = (buffer->length + strlen(suffix)) * 2;
        buffer->characters = (char *)realloc(buffer->characters, buffer->memory_size * sizeof(char));
        if (buffer->characters == NULL) {
            free(buffer);
            return NULL;
        }
    }
    strncpy(buffer->characters + buffer->length, suffix, strlen(suffix));
    buffer->length = buffer->length + strlen(suffix);
    buffer->characters[buffer->length] = '\0';
    return buffer;
}

char *drop_buffer(Buffer *buffer) {
    char *characters = buffer->characters;
    free(buffer);
    return characters;
}

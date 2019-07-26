#ifndef __BUFFER_H__
#define __BUFFER_H__

typedef struct Buffer_ Buffer;

Buffer *create_buffer(void);
int buffer_append(Buffer *buffer, char *suffix);
char *drop_buffer(Buffer *buffer);

#endif

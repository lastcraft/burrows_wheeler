#ifndef __RING_H__
#define __RING_H__

typedef struct Ring_ Ring;

Ring *create_ring(char *text, unsigned int start);
void free_ring(Ring *ring);
int compare_ring(const Ring *ring1, const Ring *ring2);
char *ring_to_string(const Ring *ring);
void print_ring(const Ring *ring);

#endif

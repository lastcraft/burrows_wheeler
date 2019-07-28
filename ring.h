#ifndef __RING_H__
#define __RING_H__

typedef struct Ring_ Ring;

Ring *create_ring(char *text, int start);
void free_ring(Ring *ring);
int compare_ring(Ring *ring1, Ring *ring2);
char *ring_to_string(Ring *ring);

#endif

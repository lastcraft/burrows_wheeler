#include "ring.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define min(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a < _b ? _a : _b; })

struct Ring_ {
    int length;
    int start;
    char *text;
};

char at(Ring *ring, int position);
bool is_same(Ring *ring1, Ring *ring2);
int compare_char(char ch1, char ch2);

Ring *create_ring(char *text, int start) {
    Ring *ring = (Ring *)malloc(sizeof(Ring));
    ring->start = start;
    ring->length = strlen(text);
    ring->text = text;
    return ring;
}

void free_ring(Ring *ring) {
    free(ring);
}

int compare_ring(Ring *ring1, Ring *ring2) {
    for (int i = 0, size = min(ring1->length, ring2->length); i < size; i++) {
        if (compare_char(at(ring1, i), at(ring2, i)) != 0) {
            return compare_char(at(ring1, i), at(ring2, i));
        }
    }
    if (ring1->length == ring2->length) {
        return 0;
    } else if (ring1->length > ring2->length) {
        return 1;
    } else {
        return -1;
    }
}

char *ring_to_string(Ring *ring) {
    char *text = (char *)malloc((ring->length + 1) * sizeof(char));
    text[ring->length] = '\0';
    memcpy(text, ring->text + ring->start, (ring->length - ring->start) * sizeof(char));
    memcpy(text + ring->length - ring->start, ring->text, ring->start * sizeof(char));
    return text;
}

char at(Ring *ring, int position) {
    int offset = position + ring->start;
    if (offset >= ring->length) {
        offset -= ring->length;
    }
    return ring->text[offset];
}

bool is_same(Ring *ring1, Ring *ring2) {
    return (ring1->text == ring2->text) && (ring1->start == ring2->start);
}

int compare_char(char ch1, char ch2) {
    if (ch1 < ch2) {
        return -1;
    } else if (ch1 < ch2) {
        return 1;
    } else {
        return 0;
    }
}

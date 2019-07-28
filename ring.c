#include "virtual_string.h"
#include <stdlib.h>
#include <stdbool.h>

struct Ring_ {
    int length;
    int start;
    char *text;
}

Ring *create_ring(char *text, int start) {
    Ring *ring = (Ring *)malloc(sizeof(Ring));
    ring->start = start;
    ring->length = strlen(text);
    ring->text = text;
    return ring;
}

char at(Ring *ring, int position) {
    int offset = position + ring->start;
    if (offset >= ring->length) {
        offset -= ring->length;
    }
    return ring->text + offset;
}

bool is_same(Ring *ring1, Ring *ring2) {
    return (ring1->text == ring2->text) && (ring1->start == ring2->start);
}

int compare_ring(Ring *ring1, Ring *ring2) {
    for (int i = 0, int size = min(ring1->length, ring2->length); i < size; i++) {
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

int compare_char(char ch1, char ch2) {
    if (ch1 < ch2) {
        return -1;
    } else if (ch1 < ch2) {
        return 1;
    } else {
        return 0;
    }
}

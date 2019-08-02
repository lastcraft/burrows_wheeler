#include "rotation.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

struct Ring_ {
    unsigned int length;
    unsigned int start;
    char *text;
};

char at(const Ring *ring, const int position);
bool is_same(const Ring *ring1, const Ring *ring2);
int compare_char(const char ch1, const char ch2);

Ring *create_ring(char *text, unsigned int start) {
    Ring *ring = (Ring *)malloc(sizeof(Ring));
    ring->start = start;
    ring->length = strlen(text);
    ring->text = text;
    return ring;
}

void free_ring(Ring *ring) {
    free(ring);
}

int compare_ring(const Ring *ring1, const Ring *ring2) {
    int smallest = ring1->length < ring2->length ? ring1->length : ring2->length;
    for (int i = 0; i < smallest; i++) {
        int comparison = compare_char(at(ring1, i), at(ring2, i));
        if (comparison != 0) {
            return comparison;
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

char *ring_to_string(const Ring *ring) {
    char *text = (char *)malloc((ring->length + 1) * sizeof(char));
    text[ring->length] = '\0';
    memcpy(text, ring->text + ring->start, (ring->length - ring->start) * sizeof(char));
    memcpy(text + ring->length - ring->start, ring->text, ring->start * sizeof(char));
    return text;
}

char at(const Ring *ring, const int position) {
    int offset = position + ring->start;
    if (offset >= ring->length) {
        offset -= ring->length;
    }
    return ring->text[offset];
}

void print_ring(const Ring *ring) {
    char *rotation = ring_to_string(ring);
    printf("Ring %p %u/%u: %s", ring, ring->start, ring->length, rotation);
    free(rotation);
}

bool is_same(const Ring *ring1, const Ring *ring2) {
    return (ring1->text == ring2->text) && (ring1->start == ring2->start);
}

int compare_char(const char ch1, const char ch2) {
    if (ch1 < ch2) {
        return -1;
    } else if (ch1 > ch2) {
        return 1;
    } else {
        return 0;
    }
}

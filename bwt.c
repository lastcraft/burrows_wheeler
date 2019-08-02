#include <stdlib.h>
#include <string.h>
#include "ring.h"
#include "bwt.h"

int compare_ring_pointer(const void *ringp1, const void *ringp2);

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

int compare_ring_pointer(const void *ringp1, const void *ringp2) {
    return compare_ring(*(Ring **)ringp1, *(Ring **)ringp2);
}


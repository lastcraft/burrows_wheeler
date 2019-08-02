#include <stdlib.h>
#include <string.h>
#include "rotation.h"
#include "bwt.h"

int compare_rotation_pointer(const void *rotation_p1, const void *rotation_p2);

char *bwt(char *text) {
    int length = strlen(text);
    Rotation **rotation_list = (Rotation **)malloc(sizeof(Rotation *) * length);
    for (int i = 0; i < length; i++) {
        rotation_list[i] = create_rotation(text, i);
    }
    qsort(rotation_list, length, sizeof(Rotation *), compare_rotation_pointer);
    char *transformed = (char *)malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < length; i++) {
        transformed[i] = at(rotation_list[i], length - 1);
    }
    transformed[length] = '\0';
    for (int i = 0; i < length; i++) {
        free_rotation(rotation_list[i]);
    }
    free(rotation_list);
    return transformed;
}

char *reverse_bwt(char *bwt) {
    return NULL;
}

int compare_rotation_pointer(const void *rotation_p1, const void *rotation_p2) {
    return compare_rotation(*(Rotation **)rotation_p1, *(Rotation **)rotation_p2);
}


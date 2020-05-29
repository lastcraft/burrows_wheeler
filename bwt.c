#include <stdlib.h>
#include <string.h>
#include "rotation.h"
#include "bwt.h"

struct SuffixList_ {
    char **grid;
    unsigned int length;
};
typedef struct SuffixList_ SuffixList;

int compare_rotation_pointer(const void *rotation_p1, const void *rotation_p2);
SuffixList *create_suffix_list(unsigned int length);
void free_suffix_list(SuffixList *suffixes);
void populate_column(SuffixList *suffixes, int offset, char *characters);
int compare_suffix(void *suffix1, void *suffix2, void *_offset);

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
    SuffixList *suffixes = create_suffix_list(strlen(bwt));
    populate_column(suffixes, strlen(bwt) - 1, bwt);
    free_suffix_list(suffixes);
    return strdup("(not implemented)");
}

int compare_rotation_pointer(const void *rotation_p1, const void *rotation_p2) {
    return compare_rotation(*(Rotation **)rotation_p1, *(Rotation **)rotation_p2);
}

SuffixList *create_suffix_list(unsigned int length) {
    SuffixList *suffixes = (SuffixList *)malloc(sizeof(SuffixList));
    suffixes->length = length;
    for (int i = 0; i < suffixes->length; i++) {
        suffixes->grid[i] = (char *)malloc((suffixes->length + 1) * sizeof(char));
        suffixes->grid[i][suffixes->length] = '\0';
    }
    return suffixes;
}

void free_suffix_list(SuffixList *suffixes) {
    for (int i = 0; i < suffixes->length; i++) {
        free(suffixes->grid[i]);
    }
    free(suffixes);
}

void populate_column(SuffixList *suffixes, int offset, char *characters) {
    for (int i = 0; i < suffixes->length; i++) {
        suffixes->grid[i][offset] = characters[i];
    }
}

int compare_suffix(void *suffix1, void *suffix2, void *offset) {
    return strcmp(suffix1 + (int)offset, suffix2 + (int)offset);
}

#include "rotation.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

struct Rotation_ {
    unsigned int length;
    unsigned int start;
    char *text;
};

char at(const Rotation *ring, const int position);
bool is_same(const Rotation *ring1, const Rotation *ring2);
int compare_char(const char ch1, const char ch2);

Rotation *create_rotation(char *text, unsigned int start) {
    Rotation *rotation = (Rotation *)malloc(sizeof(Rotation));
    rotation->start = start;
    rotation->length = strlen(text);
    rotation->text = text;
    return rotation;
}

void free_rotation(Rotation *rotation) {
    free(rotation);
}

int compare_rotation(const Rotation *rotation1, const Rotation *rotation2) {
    int smallest = rotation1->length < rotation2->length ? rotation1->length : rotation2->length;
    for (int i = 0; i < smallest; i++) {
        int comparison = compare_char(at(rotation1, i), at(rotation2, i));
        if (comparison != 0) {
            return comparison;
        }
    }
    if (rotation1->length == rotation2->length) {
        return 0;
    } else if (rotation1->length > rotation2->length) {
        return 1;
    } else {
        return -1;
    }
}

char *rotation_to_string(const Rotation *rotation) {
    char *text = (char *)malloc((rotation->length + 1) * sizeof(char));
    text[rotation->length] = '\0';
    memcpy(text, rotation->text + rotation->start, (rotation->length - rotation->start) * sizeof(char));
    memcpy(text + rotation->length - rotation->start, rotation->text, rotation->start * sizeof(char));
    return text;
}

char at(const Rotation *rotation, const int position) {
    int offset = position + rotation->start;
    if (offset >= rotation->length) {
        offset -= rotation->length;
    }
    return rotation->text[offset];
}

void print_rotation(const Rotation *rotation) {
    char *text = rotation_to_string(rotation);
    printf("Rotation %p %u/%u: %s", rotation, rotation->start, rotation->length, text);
    free(text);
}

bool is_same(const Rotation *rotation1, const Rotation *rotation2) {
    return (rotation1->text == rotation2->text) && (rotation1->start == rotation2->start);
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

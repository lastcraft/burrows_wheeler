#ifndef __ROTATION_H__
#define __ROTATION_H__

typedef struct Rotation_ Rotation;

Rotation *create_rotation(char *text, unsigned int start);
void free_rotation(Rotation *rotation);
int compare_rotation(const Rotation *rotation1, const Rotation *rotation2);
char *rotation_to_string(const Rotation *rotation);
char at(const Rotation *rotation, const int position);
void print_rotation(const Rotation *rotation);

#endif

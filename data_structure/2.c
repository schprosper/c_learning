#include <stdio.h>

struct Student {
    int id;
    float score;
    char *name ;
};

int main(void) {
    struct Student s1;
    struct Student s2;
    struct Student arr[2];

    s1.id = 1001;
    s1.score = 88.5;
    s1.name = "AA";

    arr[0].id = 1002;

    printf("student1: id=%d, score=%.1f\n", s1.id, s1.score);
    printf("student2: id=%d, score=%.1f\n", s2.id, s2.score);

    return 0;
}
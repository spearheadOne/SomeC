#include <stdio.h>
#include "set.h"

static int match_int(const void *a, const void *b) {
    return *(const int *)a == *(const int *)b;
}

int main(void) {
    Set set;
    int values[] = {1, 2, 2};
    set_init(&set, match_int, NULL);
    for (int i = 0; i < 3; i++) {
        if (set_insert(&set, &values[i]) < 0) {
            set_destroy(&set);
            return 1;
        }
    }
    printf("Set size %d\n", set_size(&set));
    void *data = &values[0];
    if (set_remove(&set, &data) != 0) {
        set_destroy(&set);
        return 1;
    }
    printf("Removed %d; size %d\n", *(int *)data, set_size(&set));
    set_destroy(&set);
    puts("Set has been destroyed");
    return 0;
}

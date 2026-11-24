#include <stdio.h>
#include "chtbl.h"

static int hash_int(const void *key) {
    return (int)((unsigned int)*(const int *)key % 4);
}

static int match_int(const void *a, const void *b) {
    return *(const int *)a == *(const int *)b;
}

int main(void) {
    CHTbl table;
    int values[] = {1, 5, 2};
    if (chtbl_init(&table, 4, hash_int, match_int, NULL) != 0)
        return 1;
    for (int i = 0; i < 3; i++) {
        if (chtbl_insert(&table, &values[i]) != 0) {
            chtbl_destroy(&table);
            return 1;
        }
    }
    printf("Hash table size %d\n", chtbl_size(&table));
    void *data = &values[1];
    if (chtbl_lookup(&table, &data) != 0 || chtbl_remove(&table, &data) != 0) {
        chtbl_destroy(&table);
        return 1;
    }
    printf("Removed %d; size %d\n", *(int *)data, chtbl_size(&table));
    chtbl_destroy(&table);
    puts("Hash table destroyed");
    return 0;
}

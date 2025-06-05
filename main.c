#include "storage.h"
#include <stdio.h>

define_storage_of_type(int)
define_storage_of_type(float)

int main() {
	int_storage_t is = int_storage_new();
    int_storage_insert(is, 1234);
    int i = int_storage_get(is);
    printf("%d\n", i);
    int_storage_destroy(is);

    float_storage_t fs = float_storage_new();
    float_storage_insert(fs, 1.2345);
    float f = float_storage_get(fs);
    printf("%f\n", f);
    float_storage_destroy(fs);
}

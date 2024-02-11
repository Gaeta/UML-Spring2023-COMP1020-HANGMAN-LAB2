#include "my_string.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    MY_STRING hMy_string_default = my_string_init_default();
    if (!hMy_string_default) {
        fprintf(stderr, "Failed to initialize default string\n");
        return 1;
    }
    // Demonstrate use of hMy_string_default
    int capacity_default = my_string_get_capacity(hMy_string_default);
    int size_default = my_string_get_size(hMy_string_default);
    printf("Default Capacity: %d, Default Size: %d\n", capacity_default, size_default);

    MY_STRING hMy_string_c = my_string_init_c_string("Hello, World!");
    if (!hMy_string_c) {
        fprintf(stderr, "Failed to initialize string from C-string\n");
        my_string_destroy(&hMy_string_default); // cleanup
        return 1;
    }
    // Demonstrate use of hMy_string_c
    int capacity_c = my_string_get_capacity(hMy_string_c);
    int size_c = my_string_get_size(hMy_string_c);
    printf("C-string Capacity: %d, C-string Size: %d\n", capacity_c, size_c);

    int compare_result = my_string_compare(hMy_string_default, hMy_string_c);
    printf("Comparison Result: %d\n", compare_result);

    my_string_destroy(&hMy_string_default);
    my_string_destroy(&hMy_string_c);
    return 0;
}

#include <stdio.h>
#include <stdbool.h>


bool in_range(size_t value, size_t min, size_t max, const char range[2]) {
    if(min >= max && value != min && value != max)
        return false;
    if(range[0] == 91 && range[1] == 93) { // []
        return value >= min && value <= max;
    }
    if(range[0] == 40 && range[1] == 93) { // (]
        return value > min && value <= max;
    }
    if(range[0] == 91 && range[1] == 41) { // [)
        return value >= min && value < max;
    }
    if(range[0] == 40 && range[1] == 41) { // ()
        return value > min && value < max;
    }
    fprintf(stderr, "Error: the format specified in 'range' should be: [], [), (] or ()\n");
    return false;
}

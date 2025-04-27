#ifndef MANDELBROT_H
#define MANDELBROT_H

#include <stdbool.h>
#include "../ppmmath/ppmmath.h"


#define MAX_SET_ITERATIONS 100


bool point_belongs_to_set(ComplexNumber c, size_t *channel);


#endif

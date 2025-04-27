
#ifndef PPMMATH_H
#define PPMMATH_H

#include <math.h>
#include "../ppmgraphics/ppmgraphics.h"

#define REAL_MIN -2.5
#define REAL_MAX 1

#define IMAGINARY_MIN -1
#define IMAGINARY_MAX 1

typedef struct {

    float realPart;
    float imaginaryPart;
    float i;


} ComplexNumber;

floatVector u32_vec_to_float_vec(const u32Vector* vec);
ComplexNumber pixel_to_complex_p(Pixel p, const u64 WIDTH, const u64 HEIGHT);


#endif

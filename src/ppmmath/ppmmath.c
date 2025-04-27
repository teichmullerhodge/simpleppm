#include "ppmmath.h"
#include <stdbool.h>

ComplexNumber pixel_to_complex_p(Pixel p, const u64 WIDTH, const u64 HEIGHT) {

    ComplexNumber c;
    floatVector vec = u32_vec_to_float_vec(&p.position);


    c.realPart = REAL_MIN + vec.x * (REAL_MAX - REAL_MIN) /  WIDTH;
    c.imaginaryPart = IMAGINARY_MIN + vec.y * (IMAGINARY_MAX - IMAGINARY_MIN) /  HEIGHT;
    return c;
}


floatVector u32_vec_to_float_vec(const u32Vector* vec) {
    return (floatVector) {
        (float)vec->x,(float)vec->y
    };
}

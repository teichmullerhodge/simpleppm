#include "mandelbrot.h"


bool point_belongs_to_set(ComplexNumber c, size_t *channel){

    float zreal = 0;
    float zimag = 0;
    bool belongs = false;
    size_t j = 0;
    for(size_t k = 0; k < MAX_SET_ITERATIONS; k++) {
        float temp = zreal * zreal - zimag * zimag + c.realPart;
        zimag = 2 * zreal * zimag + c.imaginaryPart;
        zreal = temp;
        if((zreal * zreal) + (zimag * zimag) > 4.0) {
            belongs = true;
            break;
        }
        j++;
    }
    *channel = j;
    return belongs;
}

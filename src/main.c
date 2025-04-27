#include <stdio.h>
#include "mandelbrot/mandelbrot.h"
#include "ppmmath/ppmmath.h"
#include "declarations/declarations.h"
#include "ppmgraphics/ppmgraphics.h"
#include <stdlib.h>
#define MANDELBROT_PATH "../ppms/mandelbrot.ppm"

int main(int argc, char **argv){
    (void)argc;
    (void)argv;

    const u64 WIDTH = 3840;
    const u64 HEIGHT = 2160;
    const u64 SIZE = WIDTH * HEIGHT;
    Pixel *pixels = malloc(sizeof(Pixel) * SIZE);
    u64 lines = 0;
    u64 xpos = 0;
    for(size_t k = 0; k < SIZE; k++) {
        if(k % WIDTH == 0) {
            lines++;
            xpos = 0;
        }

        pixels[k].position.x = xpos;
        pixels[k].position.y = lines;
        ComplexNumber c = pixel_to_complex_p(pixels[k], WIDTH, HEIGHT);
        size_t j = 0;
        if(point_belongs_to_set(c, &j)){


            pixels[k].color = (Color){35, j, 175};
            xpos++;
            continue;
        }

        pixels[k].color = (Color){0, 0, 0};
        xpos++;

    }

    PPMImage *image = new_ppm_image(MANDELBROT_PATH, WIDTH, HEIGHT, pixels);
    free_ppm_image(image);
    free(pixels);
    return 0;
}

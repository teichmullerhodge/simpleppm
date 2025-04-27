#include "ppmgraphics.h"
#include <stdlib.h>

u32Vector new_2dv(u32 x, u32 y) {
    return (u32Vector) {x, y};
}

Color new_color(u8 r, u8 g, u8 b) {
    return (Color) {r, g, b};
}

Pixel new_pixel(u32Vector pos, Color color) {
    return (Pixel) { pos, color };
}

PPMImage* new_ppm_image(char *path, u32 width, u32 height, Pixel *pixels) {

    PPMImage *img = (PPMImage*) malloc(sizeof(PPMImage));
    img->path = path;
    img->fp = fopen(img->path, "w");
    if(img->fp == NULL) {
        perror("Error opening the file specified in path");
        return NULL;

    }
    img->width = width;
    img->height = height;
    img->pixels = NULL;
    img->npixels = img->width * img->height;

    fprintf(img->fp, "%s%d %d\n%d\n", PPM_SIGNATURE, img->width, img->height, MAX_COLOR_VALUE);

    if(pixels) {
        for(size_t k = 0; k < img->npixels; k++){

            fprintf(img->fp, "%d %d %d ", pixels[k].color.r, pixels[k].color.g, pixels[k].color.b);
        }
    }
    img->pixels = pixels;
    return img;
}

void free_ppm_image(PPMImage *img) {
    if(img){
        fclose(img->fp);
        free(img);
    }

    return;
}

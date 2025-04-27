
#ifndef PPMGRAPHICS_H
#define PPMGRAPHICS_H

#include <stdint.h>
#include "../declarations/declarations.h"
#include <stdio.h>

typedef struct {

    u32 x;
    u32 y;

} u32Vector;

typedef struct {

    float x;
    float y;

} floatVector;


typedef struct {

    u8 r;
    u8 g;
    u8 b;

} Color;

typedef struct {

    u32Vector position;
    Color color;

} Pixel;

typedef struct {

    char *path;
    FILE *fp;
    u32 width;
    u32 height;
    Pixel *pixels;
    u64 npixels;

} PPMImage;


#define PPM_SIGNATURE "P3\n"
#define MAX_COLOR_VALUE 255


u32Vector new_2dv(u32 x, u32 y);
Color new_color(u8 r, u8 g, u8 b);
Pixel new_pixel(u32Vector pos, Color color);
PPMImage* new_ppm_image(char *filename, u32 width, u32 height, Pixel* pixels);
void free_ppm_image(PPMImage *img);


#endif

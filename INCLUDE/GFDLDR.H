#ifndef GFD_LOADER_H
#define GFD_LOADER_H

#include <stdio.h>
#include <stdlib.h>

GFD_FORMAT typedef struct _gfd_stl_header
{
    unsigned char header[80];       //80 bytes
    unsigned int triangles_number;  //4 bytes
    
} gfdSTLHeader; //84 bytes

GFD_FORMAT typedef struct _gfd_stl_triangle
{
    float normal_vector[3];               //12 bytes  x, y, z
    float vertex1[3];                     //12 bytes  x, y, z
    float vertex2[3];                     //12 bytes  x, y, z
    float vertex3[3];                     //12 bytes  x, y, z
	unsigned short attribute_byte_count;  //2 bytes

} GFD_ATTR_ALIGNED(2) gfdSTLTriangle; //50 bytes
/*
GFD_FORMAT typedef struct _gfd_stl_file
{
    gfdSTLHeader header;
    gfdSTLTriangle triangles;

} gfdSTLFile;
*/
GFD_FORMAT static gfdSTLTriangle* gfdLoadSTL(const char* path, gfdSTLHeader* header)
{
    FILE* file = fopen(path, "rb");
    if (!file) {
        perror("file cannot opened!");
        return NULL;
    }
    fread(header, sizeof(gfdSTLHeader), 1, file);
    
    gfdSTLTriangle* triangles = (gfdSTLTriangle*)malloc(header->triangles_number * sizeof(gfdSTLTriangle));
    gfdSTLTriangle one_triangle;
    
    unsigned int i;
    for(i = 0; i < header->triangles_number; i++)
    {
        fread(&one_triangle, sizeof(gfdSTLTriangle), 1, file);
        
        triangles[i] = one_triangle;
    }

    fclose(file);

    return triangles;
}

#endif//GFD_LOADER_H

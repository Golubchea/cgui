#ifndef __VBM_H__
#define __VBM_H__

#include <stdbool.h>
#include "glad.h"
typedef struct VBM_HEADER_t
{
    unsigned int magic;
    unsigned int size;
    char name[64];
    unsigned int num_attribs;
    unsigned int num_frames;
    unsigned int num_vertices;
    unsigned int num_indices;
    unsigned int index_type;
} VBM_HEADER;

typedef struct VBM_ATTRIB_HEADER_t
{
    char name[64];
    unsigned int type;
    unsigned int components;
    unsigned int flags;
} VBM_ATTRIB_HEADER;

typedef struct VBM_FRAME_HEADER_t
{
    unsigned int first;
    unsigned int count;
    unsigned int flags;
} VBM_FRAME_HEADER;

typedef struct VBM_VEC4F_t
{
    float x;
    float y;
    float z;
    float w;
} VBM_VEC4F;

typedef struct VBObject_t
{
    GLuint m_vao;
    GLuint m_attribute_buffer;
    GLuint m_index_buffer;
    VBM_HEADER m_header;
    VBM_ATTRIB_HEADER * m_attrib;
    VBM_FRAME_HEADER * m_frame;

}VBObject;







VBObject *VBObject_new(VBObject* VBObj );
void VBObject_destroy(VBObject* VBObj );
bool VBObject_LoadFromVBM(VBObject * VBObj,const char * filename, int vertexIndex, int normalIndex, int texCoord0Index);
void VBObject_render(VBObject *v,unsigned int frame_index, unsigned int instances);
bool VBObject_Free(VBObject* VBObj);


#endif /* __VBM_H__ */

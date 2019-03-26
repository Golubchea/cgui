#include <glad.h>
#include <string.h>
#include "vbm.h"
#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

VBObject *VBObject_new(VBObject* VBObj )
{
    VBObj=(VBObject*)malloc(sizeof(VBObject));
    VBObj->m_vao=0;
    VBObj->m_attribute_buffer=0;
    VBObj->m_index_buffer=0;
    VBObj->m_attrib=0;
    VBObj->m_frame=0;
    return VBObj;
}

bool VBObject_Free( VBObject *v)
{
    glDeleteBuffers(1, &v->m_index_buffer);
    v->m_index_buffer = 0;
    glDeleteBuffers(1, &v->m_attribute_buffer);
    v->m_attribute_buffer = 0;
    glDeleteVertexArrays(1, &v->m_vao);
    v->m_vao = 0;

    free(v->m_attrib ) ; //     mem_leak
    v->m_attrib = NULL;

    free(v->m_frame) ;    // mem_leak
    v->m_frame = NULL;

    return true;
}

void VBObject_destroy(VBObject* VBObj)
{
    VBObject_Free(VBObj);
    free(VBObj);
}

bool VBObject_LoadFromVBM(VBObject *v ,const char * filename, int vertexIndex, int normalIndex, int texCoord0Index)
{
    FILE * f = NULL;

    f = fopen(filename, "rb");
    if(f == NULL)
        return false;

    fseek(f, 0, SEEK_END);
    size_t filesize = ftell(f);
    fseek(f, 0, SEEK_SET);

    unsigned char * data = (unsigned char*)malloc(filesize*sizeof(unsigned char))  ;
    unsigned char * raw_data;
    fread(data, filesize, 1, f);
    fclose(f);

    VBM_HEADER * header = (VBM_HEADER *)data;
    raw_data = data + sizeof(VBM_HEADER) + header->num_attribs * sizeof(VBM_ATTRIB_HEADER) + header->num_frames * sizeof(VBM_FRAME_HEADER);
    VBM_ATTRIB_HEADER * attrib_header = (VBM_ATTRIB_HEADER *)(data + sizeof(VBM_HEADER));
    VBM_FRAME_HEADER * frame_header = (VBM_FRAME_HEADER *)(data + sizeof(VBM_HEADER) + header->num_attribs * sizeof(VBM_ATTRIB_HEADER));
    unsigned int total_data_size = 0;

    memcpy(&v->m_header, header, sizeof(VBM_HEADER));
    v->m_attrib = (VBM_ATTRIB_HEADER*)malloc(header->num_attribs*sizeof(VBM_ATTRIB_HEADER) );
    memcpy(v->m_attrib, attrib_header, header->num_attribs * sizeof(VBM_ATTRIB_HEADER));

    v->m_frame = (VBM_FRAME_HEADER*)malloc(header->num_frames*sizeof(VBM_FRAME_HEADER)  );
    memcpy(v->m_frame, frame_header, header->num_frames * sizeof(VBM_FRAME_HEADER));

    glGenVertexArrays(1, &v->m_vao);
    glBindVertexArray(v->m_vao);
    glGenBuffers(1, &v->m_attribute_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, v->m_attribute_buffer);

    unsigned int i;

    for (i = 0; i < header->num_attribs; i++) {
        int attribIndex = i;

        if(attribIndex == 0)
            attribIndex = vertexIndex;
        else if(attribIndex == 1)
            attribIndex = normalIndex;
        else if(attribIndex == 2)
            attribIndex = texCoord0Index;

        glVertexAttribPointer(attribIndex, v->m_attrib[i].components, v->m_attrib[i].type, GL_FALSE, 0, (GLvoid *)total_data_size);
        glEnableVertexAttribArray(attribIndex);
        total_data_size += v->m_attrib[i].components * sizeof(GLfloat) * header->num_vertices;
    }

    glBufferData(GL_ARRAY_BUFFER, total_data_size, raw_data, GL_STATIC_DRAW);

    if (header->num_indices) {
        glGenBuffers(1, &v->m_index_buffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, v->m_index_buffer);
        unsigned int element_size;
        switch (header->index_type) {
        case GL_UNSIGNED_SHORT:
            element_size = sizeof(GLushort);
            break;
        default:
            element_size = sizeof(GLuint);
            break;
        }
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, header->num_indices * element_size, data + total_data_size, GL_STATIC_DRAW);
    }

    glBindVertexArray(0);

    free(data) ;   //mem_leak

    return true;
}


void VBObject_render(VBObject *v,unsigned int frame_index, unsigned int instances)
{
    if (frame_index >= v->m_header.num_frames)
        return;

    glBindVertexArray(v->m_vao);
    if (instances) {
        if (v->m_header.num_indices)
            glDrawElementsInstanced(GL_TRIANGLES, v->m_frame[frame_index].count, GL_UNSIGNED_INT, (GLvoid *)(v->m_frame[frame_index].first * sizeof(GLuint)), instances);
        else
            glDrawArraysInstanced(GL_TRIANGLES, v->m_frame[frame_index].first, v->m_frame[frame_index].count, instances);
    } else {
        if (v->m_header.num_indices)
            glDrawElements(GL_TRIANGLES, v->m_frame[frame_index].count, GL_UNSIGNED_INT, (GLvoid *)(v->m_frame[frame_index].first * sizeof(GLuint)));
        else
            glDrawArrays(GL_TRIANGLES, v->m_frame[frame_index].first, v->m_frame[frame_index].count);
    }
    glBindVertexArray(0);
}

unsigned int GetVertexCount(  VBObject* VBObj,unsigned int frame )
{
    return frame < VBObj->m_header.num_frames ? VBObj->m_frame[frame].count : 0;
}

unsigned int GetAttributeCount(  VBObject* VBObj )
{
    return VBObj->m_header.num_attribs;
}

char * GetAttributeName(  VBObject* VBObj,unsigned int index)
{
    return index <  VBObj->m_header.num_attribs ?  VBObj->m_attrib[index].name : 0;
}

void BindVertexArray(   VBObject* VBObj)
{
    glBindVertexArray(VBObj->m_vao);
}

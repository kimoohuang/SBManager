/*
 * Author: Jianmeng Huang 
 * <jianmenghuang<AT>gmail.com>
 *
 * File: buffer.h
 * Create Date: 2016-11-08 14:34:35
 *
 */
#ifndef __BUFFER_H__
#define __BUFFER_H__

#define FRAMESIZE 4096
#define DEFBUFSIZE 1024
struct bFrame
{
    char field[FRAMESIZE];
};

bFrame buf[DEFBUFSIZE];

struct BCB
{
    int page_id;
    int frame_id;
    int latch;
    int count;
    int dirty;
    BCB * next;
};


#endif // buffer.h


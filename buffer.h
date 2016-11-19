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

#include<iostream>

#define FRAMESIZE 4096
#define DEFBUFSIZE 1024
#define MAXPAGES 50000

struct bFrame{
    char field[FRAMESIZE];
};

class BCB;

class LRUnode{
    public:
    LRUnode(LRUnode * pre, BCB * BCBbody, LRUnode * next);
    LRUnode * pre;
    BCB * BCBbody;
    LRUnode * next;
};

class BCB{
    public:
    BCB(int page_id, int frame_id, int dirty, BCB *next);
    void update(int page_id, int frame_id, int dirty, BCB * bcb);
    int page_id;
    int frame_id;
    //int latch;
    //int count;
    int dirty;
    BCB * next;
    LRUnode * link;
};



#endif // buffer.h


/*
 * Author: Jianmeng Huang 
 * <jianmenghuang<AT>gmail.com>
 *
 * File: buffer.cpp
 * Create Date: 2016-11-09 15:56:45
 *
 */

#include"buffer.h"

using namespace std;

BCB::BCB(int page_id, int frame_id, int dirty, BCB* next){
    this->page_id = page_id;
    this->frame_id = frame_id;
    this->dirty = dirty;
    this->next = next;
}


void BCB::update(int page_id, int frame_id, int dirty, BCB * bcb){
    this->page_id = page_id;
    this->frame_id = frame_id;
    this->dirty = dirty;
    this->next = bcb;
}

LRUnode::LRUnode(LRUnode * pre, BCB * BCBbody, LRUnode * next){
    this->pre = pre;
    this->BCBbody = BCBbody;
    this->next = next;
}



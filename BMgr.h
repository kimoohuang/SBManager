/*
 * Author: Jianmeng Huang 
 * <jianmenghuang<AT>gmail.com>
 *
 * File: BMgr.h
 * Create Date: 2016-11-08 15:26:23
 *
 */
#ifndef __BMGR_H__
#define __BMGR_H__
#include<iostream>
#include "buffer.h"

class BMgr
{
    public:
        int hitCount;
        int numIO;
        bFrame buf[DEFBUFSIZE];

        BMgr();
        // Interface Functions
        int fixPage(int page_id, int prot);
        void fixNewPage();
        int unfixPage(int page_id);
        void readPage(int page_id);
        void writePage(int page_id);
        
        // Internal Functions
        int numFreeFrames();
        int allocateNewFreeFrame(int page_id, int prot);
        BCB * selectVictim();
        BCB * getFramefromPageid(int page_id);
        //void removeBCB(BCB * ptr, int page_id);
        //void removeLRUEle(int frid);
        //void setDirty(int frame_id);
        //void unsetDirty(int Frame_id);
        //void writeDirtys();
        //void printFrame(int frame_id);


    private:
        // Hash Table
        int numofFreeFrames;
        int ftop[DEFBUFSIZE];
        BCB * ptof[DEFBUFSIZE];
        LRUnode * LRUheader;
        LRUnode * LRUtail;

        int hash(int page_id);
};


#endif // BMgr.h


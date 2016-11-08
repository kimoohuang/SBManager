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

#include "buffer.h"

class BMgr
{
    public:
        BMgr();
        // Interface Functions
        int FixPage(int page_id, int port);
        void FixNewPage();
        int UnfixPage(int page_id);
        int NumFreeFrames();
        
        // Internal Functions
        int SelectVictim();
        int Hash(int page_id);
        void RemoveBCB(BCB * ptr, int page_id);
        void RemoveLRUEle(int frid);
        void SetDirty(int frame_id);
        void UnsetDirty(int Frame_id);
        void WriteDirtys();
        void PrintFrame(int frame_id);

    private:
        // Hash Table
        int ftop[DEFBUFSIZE];
        BCB * ptof[DEFBUFSIZE];
};


#endif // BMgr.h


/*
 * Author: Jianmeng Huang 
 * <jianmenghuang<AT>gmail.com>
 *
 * File: DSMgr.h
 * Create Date: 2016-11-08 15:20:25
 *
 */
#ifndef __DSMGR_H__
#define __DSMGR_H__

#include "buffer.h"

class DSMgr{
    public:
        DSMgr();
        int openFile(const char* filename);
        int closeFile();
        bFrame readPage(int page_id);
        int writePage(int frame_id, bFrame frm);
        int seek(int offset, int pos);
        FILE * getFile();
        void incNumPages();
        int getNumPages();
        void setUse(int index, int use_bit);
        int getUse(int indes);
    private:
        FILE *curFile;
        int numPages;
        int pages[MAXPAGES];
};

#endif // DSMgr.h


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
        int OpenFile(string filename);
        int CloseFile();
        bFrame ReadPage(int page_id);
        int WritePage(int frame_id, bFrame frm);
        int Seek(int offset, int pos);
        FILE * getFile();
        void IncNumPages();
        int GetNumPages();
        void SetUse(int index, int use_bit);
        int GetUse(int indes);
    private:
        FILE *curFile;
        int numPages;
        int pages[MAXPAGES];
};

#endif // DSMgr.h


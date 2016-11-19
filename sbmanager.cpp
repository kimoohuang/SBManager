/*
 * Author: Jianmeng Huang 
 * <jianmenghuang<AT>gmail.com>
 *
 * File: sbmanager.cpp
 * Create Date: 2016-11-17 20:51:30
 *
 */
#include<stdio.h>

#include"BMgr.h"

using namespace std;

int main(int argv, char * argc[]){
    int page_id,  prot;
    BMgr bm;
    FILE* fp=fopen("data-5w-50w-zipf.txt","rt"); 
    if(!fp){
        return 1;
    }
    
    for(int i=0; i < 500000 ; ++i){
        fscanf(fp,"%d,%d",&prot,&page_id); 
        if(prot == 0){
            //cout << prot << page_id << endl;
            bm.readPage(page_id);
        }else{
            //cout << prot << page_id << endl;
            bm.writePage(page_id);
        }
    }//for

    cout << "Hit: "<< bm.hitCount << endl;
    cout << "Hit Ratio: " << bm.hitCount/500000.0 * 100 << "%"<< endl;
    cout << "I/O: "<< bm.numIO << endl;
}//main





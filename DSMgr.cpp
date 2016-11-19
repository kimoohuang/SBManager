#include"DSMgr.h"

using namespace std;

DSMgr::DSMgr(){
    openFile("data.dbf");
}

int DSMgr::openFile(const char *){

}

int DSMgr::closeFile(){

}

bFrame DSMgr:: readPage(int page_id){
}

int DSMgr::writePage(int frame_id, bFrame frm){
}

int DSMgr::seek(int offset, int pos){
}

FILE * DSMgr::getFile(){
    
}

void DSMgr::incNumPages(){
}

int DSMgr::getNumPages(){
}

void DSMgr::setUse(int index, int use_bit){
}

int DSMgr::getUse(int indes){
}


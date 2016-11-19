#include "BMgr.h"

using namespace std;


BMgr::BMgr(){
    numofFreeFrames = DEFBUFSIZE;
    hitCount = 0;
    numIO = 0;
    LRUheader = new LRUnode(NULL, NULL, NULL);
    LRUtail = NULL;

    for(int i = 0; i < DEFBUFSIZE; ++i){
        ftop[i] = -1;
        ptof[i] = NULL;
    }
}

void BMgr::readPage(int page_id){
    fixPage(page_id, 0);
}

void BMgr::writePage(int page_id){
    fixPage(page_id, 1);
}


int BMgr::fixPage(int page_id, int prot){
    BCB * t_frame = getFramefromPageid(page_id); 
    if(t_frame){ // hit in the buff
        hitCount ++;
        //cout << "hit" << endl;

        LRUnode * L_node = t_frame->link;
        LRUnode * pre = L_node->pre;
        LRUnode * nxt= L_node->next;
        if(LRUtail == L_node){
            //if(nxt){
            //    LRUtail = nxt;
                //can not be
            //}else
                LRUtail = pre;
        }
        L_node->next = LRUheader->next;
        LRUheader->next = L_node; 
        pre->next = nxt;
        if(nxt)
            nxt->pre = pre;
        if(t_frame->dirty){
            numIO++;
            //write from buffer to disk
            t_frame->dirty = 0;
        }


        if(prot)
            t_frame->dirty = 1;
        return t_frame->frame_id;
    }else{ // does not hit
        numIO++;
        if(numFreeFrames()){
            //cout << numFreeFrames() << endl;
            return allocateNewFreeFrame(page_id, prot);
        }else{ //select a victim and replace it
            t_frame = selectVictim();
            //
            // !!! if dirty, the frame should be written back to page
            //
            //delete from BCB list
            //
            BCB * temp = ptof[hash(t_frame->page_id)];
            if(t_frame == temp){
                ptof[hash(t_frame->page_id)] = t_frame->next;
            }else{
                while(temp->next != t_frame){
                    temp = temp->next;
                }
                temp->next = t_frame->next;
            }
            
            //
            //update new BCB list
            t_frame->page_id = page_id;
            t_frame->dirty = prot;
            ftop[t_frame->frame_id] = page_id;
            
            t_frame->next = ptof[hash(page_id)];
            ptof[hash(page_id)] = t_frame;
        }
    }
}

BCB* BMgr::selectVictim(){
    if(LRUtail==NULL)
        cout << "null" <<endl;
    return LRUtail->BCBbody;
}

int BMgr::numFreeFrames(){
    return numofFreeFrames;
}

int BMgr::allocateNewFreeFrame(int page_id, int prot){
    numofFreeFrames--;
    for(int i = 0; i < DEFBUFSIZE; ++i){
        if(ftop[i] == -1){
            BCB * f_temp = new BCB(page_id, i, prot, NULL);

            //update LRU list
            LRUnode * next = LRUheader->next;
            LRUnode * l_temp = new LRUnode(LRUheader, f_temp, next);
            LRUheader->next = l_temp;
            if(next)
                next->pre = l_temp;
            f_temp->link = l_temp;
            if(LRUtail == NULL){
                LRUtail = l_temp;
            }

            //update BCB table
            ftop[i] = page_id;
            f_temp->next = ptof[hash(page_id)]; //store the previous frame which shares the same hash value.
            ptof[hash(page_id)] = f_temp;
            return i;
        }
    }
}

int BMgr::hash(int page_id){
    return (page_id)%DEFBUFSIZE;
}

BCB* BMgr::getFramefromPageid(int page_id){
    BCB * t_frame = ptof[hash(page_id)];
    while(t_frame){
        if(t_frame->page_id != page_id){
            t_frame = t_frame->next;
        }else
            return t_frame;
    }
    return NULL;
}



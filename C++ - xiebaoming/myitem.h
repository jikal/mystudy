#ifndef _MYITEM_H
#define _MYITEM_H

class myitem
{
public:
    myitem();
    unsigned char* getItem();
    int currentItem_endPos(unsigned char *currentItem, unsigned char end);
    unsigned char* itemChange(unsigned char *currentItem);
};

#endif

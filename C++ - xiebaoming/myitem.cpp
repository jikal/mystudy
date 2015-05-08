#include "myitem.h"
#include <QtGlobal>
#include <time.h>

//9 items array
unsigned char item1[4*4] =
{
1,1,1,0,
1,0,1,0,
1,1,1,0,
0,0,1,0
};
unsigned char item2[4*4] =
{
0,0,0,0,
1,1,1,0,
0,1,0,0,
0,1,0,0
};
unsigned char item3[4*4] =
{
0,0,0,0,
1,0,1,0,
1,1,1,0,
0,0,1,0
};
unsigned char item4[4*4] =
{
0,0,1,1,
0,0,0,1,
0,0,1,1,
0,0,0,1
};
unsigned char item5[4*4] =
{
0,0,0,0,
0,0,1,0,
0,0,0,0,
0,0,0,0
};
unsigned char item6[4*4] =
{
0,0,0,0,
0,0,0,0,
0,1,1,0,
0,0,0,0
};
unsigned char item7[4*4] =
{
1,0,1,0,
1,1,1,0,
0,0,0,0,
0,0,0,0
};
unsigned char item8[4*4] =
{
0,0,0,0,
0,1,1,0,
0,1,0,0,
0,0,0,0
};
unsigned char item9[4*4] =
{
0,0,1,0,
0,0,1,0,
0,0,1,0,
0,0,1,0
};

myitem::myitem()
{
    qsrand(time(0));//select random//产生随机数种子
}

//随机产生方块
unsigned char* myitem::getItem()
{
    unsigned char *currentItem=NULL;
    switch(qrand()%9)
    {
        case 0 :
            currentItem = item1;
            break;
        case 1 :
            currentItem = item2;
            break;
        case 2 :
            currentItem = item3;
            break;
        case 3 :
            currentItem = item4;
            break;
        case 4 :
            currentItem = item5;
            break;
        case 5 :
            currentItem = item6;
            break;
        case 6 :
            currentItem = item7;
            break;
        case 7 :
            currentItem = item8;
            break;
        case 8 :
            currentItem = item9;
            break;
    }
    return currentItem;
}

//方块在4*4的矩形中的位置
int myitem::currentItem_endPos(unsigned char *currentItem, unsigned char end)
{
    int k = 0;
    switch(end)
    {
        case 'd' ://方块所占的4*4矩形中的最大行数
            {
                for(int row=3; row>=0; row--)
                {
                    for(int col=0; col<4; col++)
                    {
                        if(*(currentItem + row*4 + col) || k ==1)
                        {
                            return row;
                        }
                    }
                }
            }
        case 'r' ://方块所占的4*4矩形中的最右列数
            {
                for(int col=3; col>=0; col--)
                {
                    for(int row=0; row<4; row++)
                    {
                        if(*(currentItem + row*4 + col) || k ==1)
                        {
                            return col;
                        }
                    }
                }
            }
        case 'l' ://方块所占的4*4矩形中的最左列数
            {
                for(int col=0; col<4; col++)
                {
                    for(int row=0; row<4; row++)
                    {
                        if(*(currentItem + row*4 + col) || k ==1)
                        {
                            return col;
                        }
                    }
                }
            }
        default:
            {
                return 0;
            }
    }
}

//改变方块的形状
unsigned char* myitem::itemChange(unsigned char *currentItem)
{
    unsigned char* tempItem = new unsigned char[4*4];

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            *(tempItem + (3 - j)*4 + i) = *(currentItem + i*4 + j);//逆时针转90度
        }
    }

    return tempItem;
}

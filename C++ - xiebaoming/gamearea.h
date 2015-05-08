#ifndef _GAMEAREA_H
#define _GAMEAREA_H

#include <QtGui/QFrame>
#include "myitem.h"
#include <QPainter>
#include <QColor>
#include <QTimer>

namespace gameArea {
    class gamearea;
}

class gamearea : public QFrame//有框架的窗口部件的基类
{
    Q_OBJECT

public:
    gamearea(QWidget *parent = 0);//constructor function without Timmer
    //gamearea(int speed, QWidget *parent = 0);//constructor function with Timmer
    ~gamearea();

public:
    //core functions
    void init_gameArea(int X, int Y, int frame_width, int frame_height,\
                       int width, int height, int boxStep, int start_x, int start_y);//初始化游戏界面
    void moveOneStep();//方块向下移动一步
    bool isMoveEnd();//方块是否移动到底或者和其它的方块重叠
    bool isGame_Over();//是否游戏结束
    void init_Game();//初始化游戏
    void gameStart();//开始游戏
    void nextItem();//复制地图，清行并计算分数
    int getFullRowNum();//获取已经全部占满的行数
    void do_MoveNext();//更新方块成功移动一步之后的游戏地图
    void draw_gameArea();//画游戏地图

    //set color functions
    void setGameAreaColor(QColor color=Qt::white);//设置游戏地图颜色
    void setBoxBrushColor(QColor color=Qt::green);//设置方块颜色
    void setBoxPenColor(QColor color=Qt::black);//设置方块边框颜色
    void set_draw_box_picture(bool Bool=false);//设置is_draw_box_picture为Bool//
    void setBoxPicture(QString fileName);//设置boxPicture为fileName//

    //other functions
    void setKey_Down_Move_oneStep(bool Bool = false);//按向下键一下，方块是否下移一格，或移动到底//没有用到？？？
    void setDrawGrid(bool Bool = true);//地图是否画网格
    void setDrawNextItem(bool Bool =true);//是否给出下一个方块的提示
    void setbox(int row, int col);//add item//添加方块//没有被使用？？？
    int getscore(){return this->score;}//获取游戏的分数
    void setscore(int i){this->score=i;}//设置游戏的分数
    int getmovespeed(){return this->moveSpeed;}//获得方块移动速度
    void setmovespeed(int i){this->moveSpeed=i;}//设置方块移动速度

private:
    void init_Map(unsigned char *initMap, int row, int col);//初始化游戏地图，设置数组为0
    void paintEvent(QPaintEvent *);//重画游戏地图区域事件//没有用到？？？
    void keyPressEvent(QKeyEvent *);//键盘事件
    void draw_Grid();//画地图网格
    void currentItem_to_currentMap();//标定正在下落的方块，其各小方块的地图中的位置为1
    void copy_Map(unsigned char *theMap, unsigned char *toMap, int row,int col);//复制游戏地图
    void draw_currentMap();//画游戏地图中的方块
    bool isMoveLeft();//方块是否移动到最左边或者和其它的方块重叠
    bool isMoveRight();//方块是否移动到最右边或者和其它的方块重叠
    void draw_nextItem();//提示下一个方块
    void do_itemChange();//方块改变形状的处理过程
    void clearRow();//清行并计算分数

private:
    int gameArea_width;//游戏地图宽度
    int gameArea_height;//游戏地图高度
    int map_row;//行数
    int map_col;//列数
    int startX;//方块位置的横坐标
    int startY;//方块位置的纵坐标
    int step;//网格单位大小
    int init_startX;//方块开始时的横坐标
    int init_startY;//方块开始时的纵坐标
    unsigned char *currentMap;//当前游戏地图
    unsigned char *copyMap;//保存游戏地图

    QPixmap *pix_gameArea;//具体游戏地图
    myitem *myItem;//方块
    unsigned char *currentItem;//当前方块
    unsigned char *theNextItem;//下一个方块
    bool isFirstItem;//是否是第一个方块
    bool isGameOver;//游戏是否结束
    int fullRowNum;//全部被占满的行数
    QColor gameAreaColor;//游戏地图颜色
    QColor boxPenColor;//方块边框颜色
    QColor boxBrushColor;//方块颜色

    bool isKey_Down_Move_OneStep;//按向下键一下，方块是否下移一格，或移动到底

    bool isDrawGrid;//是否画网格
    bool isDrawNextItem;//是否出现下一个方块

    int theAngle;//没用到？？？
    int gameArea_X;//
    int gameArea_Y;//
    int pix_X;//游戏地图横坐标
    int pix_Y;//游戏地图纵坐标

    bool is_draw_box_picture;//
    QString boxPicture;//

    int moveSpeed;//方块下落速度
    int score;//游戏得分
/*
    QTimer *moveTimer;//
private slots:
    void moveTimer_upDate();//
*/
};

#endif

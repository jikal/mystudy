#include "gamearea.h"
#include <QKeyEvent>
#include <QSound>
#include <QMessageBox>
#include "input.h"

gamearea::gamearea(QWidget *parent) :
    QFrame(parent)
{
    this->init_gameArea(6, 6, 430, 430, 200, 400, 20, 60, 0);//游戏界面大小
    this->init_Game();//初始化游戏
}
/*
gamearea::gamearea(int speed, QWidget *parent) :
    QFrame(parent)
{
    this->init_gameArea(6, 6, 430, 430, 200, 400, 20, 60, 0);
    this->init_Game();
    this->moveSpeed = speed;//设置方块移动速度
    this->gameStart();//开始游戏
}
*/
gamearea::~gamearea()
{

}

//方块向下移动一步
void gamearea::moveOneStep()
{
     startY += step;
}

//方块成功移动一步之后，重新画游戏地图
void gamearea::do_MoveNext()
{
    this->currentItem_to_currentMap();//标定地图中正在下落的方块
    this->draw_gameArea();//画游戏地图
}

//复制地图，清行并计算分数
void gamearea::nextItem()
{
    copy_Map(currentMap, copyMap, map_row, map_col);//复制地图，*copyMap 等于 *currentMap
    this->clearRow();//清行并计算分数
}

//是否游戏结束
bool gamearea::isGame_Over()
{
    if(this->isGameOver)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//获取已经全部占满的行数//没有用到？？？
int gamearea::getFullRowNum()
{
    return fullRowNum;
}

//设置游戏地图颜色
void gamearea::setGameAreaColor(QColor color)
{
    gameAreaColor = color;
}

//设置方块颜色
void gamearea::setBoxBrushColor(QColor color)
{
    boxBrushColor = color;
}

//设置方块边框颜色
void gamearea::setBoxPenColor(QColor color)
{
    boxPenColor = color;
}

//设置is_draw_box_picture为Bool//
void gamearea::set_draw_box_picture(bool Bool)
{
    this->is_draw_box_picture = Bool;//
}

//设置boxPicture为fileName//
void gamearea::setBoxPicture(QString fileName)
{
    this->boxPicture = fileName;//
}

//按向下键一下，方块是否下移一格，或移动到底//没有用到？？？
void gamearea::setKey_Down_Move_oneStep(bool Bool)
{
    this->isKey_Down_Move_OneStep = Bool;
}

//地图是否画网格
void gamearea::setDrawGrid(bool Bool)
{
    isDrawGrid = Bool;
}

//是否给出下一个方块的提示
void gamearea::setDrawNextItem(bool Bool)
{
    isDrawNextItem = Bool;//
}

//add item//添加方块//没有被使用？？？
void gamearea::setbox(int row,int col)
{
    *(copyMap + row*map_col + col) = 1;//
}

//初始化游戏界面
void gamearea::init_gameArea(int X, int Y, int frame_width, int frame_height,\
                                int width, int height, int boxStep, int start_x, int start_y)
{
    this->gameArea_width = width;//游戏地图宽度
    this->gameArea_height = height;//游戏地图高度
    this->step = boxStep;//网格单位大小
    this->init_startX = start_x;//4*4矩形开始时的横坐标
    this->init_startY = start_y;//4*4矩形开始时的纵坐标
    this->map_row = gameArea_height / step;//行数
    this->map_col = gameArea_width / step;//列数

    //初始化界面大小和位置
    this->resize(frame_width, frame_height);
    this->move(X, Y);

    pix_gameArea = new QPixmap(this->gameArea_width, this->gameArea_height);//游戏地图区域

    this->isKey_Down_Move_OneStep = true;//向下键一次下落一下

    this->isDrawGrid = true;//画网格
    this->isDrawNextItem = true;//画下一个方块
    this->is_draw_box_picture = false;//？？？

    this->gameAreaColor = Qt::black;//游戏地图颜色
    this->boxBrushColor = Qt::green;//方块颜色
    this->boxPenColor = Qt::red;//方块边框颜色

    this->theAngle = 0;//没用到？？？
    this->gameArea_X = 0;//没用到？？？
    this->gameArea_Y = 0;//没用到？？？
    this->pix_X = 10;//游戏地图所在游戏界面位置横坐标
    this->pix_Y = 10;//游戏地图所在游戏界面位置纵坐标

    myItem = new myitem();//方块

    this->currentMap = new unsigned char[map_row*map_col];//游戏地图，数组[20, 10]
    this->copyMap = new unsigned char[map_row*map_col];//currentMap备份
}

//初始化游戏
void gamearea::init_Game()
{
    this->init_Map(currentMap, map_row, map_col);//初始化*currentMap，数组全为0
    this->init_Map(copyMap, map_row, map_col);//初始化*copyMap，数组全为0

    this->currentItem = this->currentMap;//初始化*currentItem指针
    this->theNextItem = this->currentMap;//初始化*theNextItem指针

    isFirstItem = true;
    isGameOver = false;
    fullRowNum = 0;

    this->draw_gameArea();//绘制游戏地图
    this->score = 0;
}

//开始游戏
void gamearea::gameStart()
{
    this->startX = this->init_startX;//地图中4*4矩形所在位置横坐标
    this->startY = this->init_startY;//地图中4*4矩形所在位置纵坐标
    fullRowNum = 0;//与172行是否重复？？？
    if(isFirstItem)//出现的第一个方块
    {
        this->currentItem = myItem->getItem();//随即产生方块
        isFirstItem = false;
    }
    else
    {
        this->currentItem = this->theNextItem;
    }
    this->theNextItem = myItem->getItem();
    this->currentItem_to_currentMap();//标定地图中正在下落的方块
    this->draw_gameArea();//绘制游戏地图
}

//初始化游戏地图，设置数组为0
void gamearea::init_Map(unsigned char *initMap, int row, int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            *(initMap + i*col + j) = 0;
        }
    }
}

//画游戏地图
void gamearea::draw_gameArea()
{
    this->pix_gameArea->fill(gameAreaColor);//地图颜色
    if(this->isDrawGrid)
    {
        draw_Grid();
    }
    draw_currentMap();//画游戏地图中的方块
    update();//QWidget::update，更新窗口部件，重新绘制
}

//画地图网格
void gamearea::draw_Grid()
{
    QPainter painter(this->pix_gameArea);//游戏地图
    painter.setPen(Qt::DotLine);//Qt::DotLine，枚举类型，边线画成几个像素间隔的连续的点的形式
    painter.setPen(Qt::blue);
    for(int i=0; i<map_row; i++)
    {
        painter.drawLine(QPoint(0, i*step), QPoint(this->gameArea_width, i*step));//画行线
    }
    for(int j=0; j<map_col; j++)
    {
        painter.drawLine(QPoint(j*step, 0), QPoint(j*step, this->gameArea_height));//画列线
    }
}

//画游戏地图中的方块
void gamearea::draw_currentMap()
{
    QPainter painter(this->pix_gameArea);//游戏地图
    painter.setPen(this->boxPenColor);//方块边框颜色
    painter.setBrush(this->boxBrushColor);//方块颜色
    for(int i=0; i<map_row; i++)//在地图网格中绘制方块
    {
        for(int j=0; j<map_col; j++)
        {
            if(*(currentMap + i*map_col + j) == 1)
            {
                if(this->is_draw_box_picture)//
                {
                    QPixmap pix;
                    pix.load(this->boxPicture);
                    painter.drawPixmap(j*step, i*step, step, step, pix);
                }
                painter.drawRect(j*step, i*step, step, step);//绘制左上角在(j*step, i*step)并且宽和高都为step的矩形
            }
        }
    }
}

//标定正在下落的方块，其各小方块的地图中的位置为1
void gamearea::currentItem_to_currentMap()
{
    copy_Map(copyMap, currentMap, map_row, map_col);//复制地图，*currentMap 等于 *copyMap
    int m_row = startY/step;//地图中4*4矩形位置的行数
    int m_col = startX/step;//地图中4*4矩形位置的列数
    for(int i=m_row; i<m_row + 4; i++)
    {
        for(int j=m_col; j<m_col + 4; j++)
        {
            *(currentMap + i*map_col + j) |= *(currentItem + (i - m_row)*4 + (j - m_col));//有1为1，全0为0
        }
    }
}

//复制游戏地图
void gamearea::copy_Map(unsigned char *theMap, unsigned char *toMap, int row, int col)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            *(toMap + i*col + j) = *(theMap + i*col + j);//*toMap 等于 *theMap
        }
    }
}

//提示下一个方块
void gamearea::draw_nextItem()
{
    QPainter painter(this);//游戏界面区域
    painter.drawRect(gameArea_width + 20, 10, 4*step, 4*step);//4*4的矩形提示区域
    painter.setBrush(this->boxBrushColor);//提示方块的颜色
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(*(theNextItem + i*4 + j) == 1)
            {
                if(this->is_draw_box_picture)//
                {
                    QPixmap pix;
                    pix.load(this->boxPicture);
                    painter.drawPixmap(gameArea_width + 20 + j*step, 10 + i*step, step, step, pix);
                }
                painter.drawRect(gameArea_width + 20 + j*step, 10 + i*step, step, step);//绘制小正方块
            }
        }
    }
}

//重画游戏地图区域事件//没有用到？？？
void gamearea::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(pix_X, pix_Y), *pix_gameArea);//游戏地图区域
    if(this->isDrawNextItem)
    {
        draw_nextItem();
    }
}

//键盘事件
void gamearea::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
        case Qt::Key_Left ://按向左的方向键
            {
                startX = startX - step;
                if(isMoveLeft())
                {
                    startX = startX + step;
                }
                else
                {
                    currentItem_to_currentMap();//标定地图中正在下落的方块
                    this->draw_gameArea();//绘制游戏地图
                }
                break;
            }
        case Qt::Key_Right ://按向右的方向键
            {
                startX = startX + step;
                if(isMoveRight())
                {
                    startX = startX - step;
                }
                else
                {
                    currentItem_to_currentMap();//标定地图中正在下落的方块
                    this->draw_gameArea();//绘制游戏地图
                }
                break;
            }
        case Qt::Key_Up ://按向上的方向键
            {
                do_itemChange();
                currentItem_to_currentMap();//标定地图中正在下落的方块
                this->draw_gameArea();//绘制游戏地图
                break;
            }
        case Qt::Key_Down ://按向下的方向键
            {
                if(this->isKey_Down_Move_OneStep)//按一次下落一下
                {
                    startY += step;
                    if(this->isMoveEnd())
                    {
                        startY -= step;
                    }
                    else
                    {
                        currentItem_to_currentMap();//标定地图中正在下落的方块
                        this->draw_gameArea();//绘制游戏地图
                        /*
                        if(isPlaySound_moveDown)
                        {
                            playSound(sound_moveDown);
                        }
                        */
                    }
                }
                else//按一次下落到底部
                {
                    int i = 0;
                    while(!this->isMoveEnd())
                    {
                        startY += step;
                        i++;
                    }
                    startY -= step;
                    if(i > 0)
                    {
                        currentItem_to_currentMap();//标定地图中正在下落的方块
                        this->draw_gameArea();//绘制游戏地图
                    }
                }
                break;
            }
        default://按其他键
            {
                QFrame::keyPressEvent(event);
            }
    }
}

//方块是否移动到底或者和其它的方块重叠
bool gamearea::isMoveEnd()
{
    int item_endRow = myItem->currentItem_endPos(currentItem, 'd');//方块所占的4*4矩形中的最大行数

    int itemRow = startY/step;//地图中4*4矩形所在位置的行号
    int itemCol = startX/step;//地图中4*4矩形所在位置的列号

    if(itemRow + item_endRow >= map_row)
    {
        return true;
    }

    for(int i = item_endRow; i >= 0; i--)//判断方块与地图中其他的方块是否重叠
    {
        for(int j = 3; j >= 0; j--)
        {
            //如果方块下落一格，左移一格，右移一格，或者改变形状之后，4*4矩形内各个小方块所在的地图中的位置，
            //在对方块进行操作之前，地图中相应位置就已经有小方块存在了，则方块不能进行上述相关的操作。
            if(*(copyMap + (itemRow + i)*map_col + itemCol + j) && *(currentItem + i*4 + j) == 1)
            {
                if(startX == init_startX && startY <= 20)//如果方块刚出现就与其他的重叠，则游戏结束
                {
                    isGameOver = true;
                }
                return true;
            }
        }
    }

    return false;
}

//方块是否移动到最左边或者和其它的方块重叠
bool gamearea::isMoveLeft()
{
    int item_endLeft = myItem->currentItem_endPos(currentItem, 'l');//方块所占的4*4矩形中的最左列数
    int item_Col = startX/step;//地图中4*4矩形所在位置的列号
    if(item_Col + item_endLeft < 0)
    {
        return true;
    }
    if(isMoveEnd())
    {
        return true;
    }
    return false;
}

//方块是否移动到最右边或者和其它的方块重叠
bool gamearea::isMoveRight()
{
    int item_endRight = myItem->currentItem_endPos(currentItem, 'r');//方块所占的4*4矩形中的最右列数
    int item_Col = startX/step;//地图中4*4矩形所在位置的列号
    if(item_Col + item_endRight >= map_col)
    {
        return true;
    }
    if(isMoveEnd())
    {
        return true;
    }
    return false;
}

//方块改变形状的处理过程
void gamearea::do_itemChange()
{
    unsigned char *tempItem;
    tempItem = currentItem;//复制当前方块
    currentItem = myItem->itemChange(currentItem);//改变方块形状
    if(startX < 0)//如果变形后超过左边范围，则将其放在最左边
    {
        startX = 0;
    }
    if((startX + 4*step) > gameArea_width)//如果变形后超过右边范围，则将其放在最右边
    {
        startX = gameArea_width - 4*step;
    }
    if(isMoveEnd())//如果变形后与其他的方块重叠，则取消改变方块的形状
    {
        currentItem = tempItem;
    }
}

//清行并计算分数
void gamearea::clearRow()
{
    int temp1 = 1;
    int clearOneTime = 0;//用于计算分数

    for(int i = map_row - 1; i > 0; i--)//自下而上
    {
        for(int j = 0; j < map_col; j++)
        {
            temp1 = *(copyMap + i*map_col + j) && temp1;
        }

        if(temp1)//temp1仍等于1，则意味着是一个满行
        {
            fullRowNum++;
            for(int row = i; row > 0; row--)//令当前行与上一行相同
            {
                for(int col = 0; col < map_col; col++)
                {
                    *(copyMap + row*map_col + col) = *(copyMap + (row - 1)*map_col + col);
                }
            }
            i = i + 1;
            clearOneTime ++;//用fullRowNum可否？？？
        }
        temp1 = 1;
    }

    if(clearOneTime == 1)//计算分数
    {
        score += 10;
    }
    else if(clearOneTime == 2)
    {
        score += 30;
    }
    else if(clearOneTime == 3)
    {
        score += 60;
    }
    else if(clearOneTime == 4)
    {
        score += 100;
    }
}

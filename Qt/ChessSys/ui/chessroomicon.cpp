#include "chessroomicon.h"
#include <QPainter>

const QString ChessRoomIcon::ImageFileDir = "../skin/";
const QString ChessRoomIcon::ImageFileName[] = {
    "Free.png", "Schedule.png", "Busy.png", "Suspend.png"
};

int ChessRoomIcon::setStatus(ChessRoomState status){

    _index = status - 1;
    int size = sizeof(ImageFileName)/sizeof(ImageFileName[0]);
    if(_index < 0 || _index >= size){
        return -1;
    }
    update();
    return 0;
}

ChessRoomIcon::ChessRoomIcon(QWidget *parent) : QWidget(parent)
{

}

void ChessRoomIcon::paintEvent(QPaintEvent *event){

    QPainter p(this);

//    p.drawPixmap(0, 0, 300, 300 , QPixmap("../skin/Suspend.png"), 0, 0, width(), height());

    p.drawPixmap(rect() , QPixmap(ImageFileDir + ImageFileName[_index]));
}

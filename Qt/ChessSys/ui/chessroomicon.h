#ifndef CHESSROOMICON_H
#define CHESSROOMICON_H

#include <QWidget>
#include "chess_sys_user.h"
#include <QString>

class ChessRoomIcon : public QWidget
{
    Q_OBJECT
public:


    explicit ChessRoomIcon(QWidget *parent = 0);

    int setStatus(ChessRoomState status);

protected:


    virtual void paintEvent(QPaintEvent *event);

public:
    static const QString ImageFileDir;
    static const QString ImageFileName[];

protected:
    int _index = 0;

signals:

public slots:
};

#endif // CHESSROOMICON_H

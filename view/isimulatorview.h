#ifndef ISIMULATORVIEW_H
#define ISIMULATORVIEW_H

#include "../common/board.h"
#include <QObject>

class ISimulatorView : public QObject
{
    Q_OBJECT
public:
    ISimulatorView();
    virtual ~ISimulatorView() {}
    virtual void showBoard(const Board& board) = 0;
public slots:
    virtual void show() = 0;
};

#endif // ISIMULATORVIEW_H

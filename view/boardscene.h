#ifndef BOARD_H
#define BOARD_H

#include <QGraphicsScene>

class BoardScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit BoardScene();

    void updateBoardSize(int size);

protected:

signals:

public slots:

private:
    int borderSize;

};

#endif // BOARD_H

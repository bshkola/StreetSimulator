#include "boardscene.h"
#include "boardcell.h"
#include "truckcarcell.h"
#include <iostream>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QWidget>
#include "../controller/blockingqueue.h"
#include "../common/events/streetfieldaddedevent.h"
#include "../common/events/streetfieldremovedevent.h"

namespace Ui {
    BoardScene::BoardScene() : QGraphicsScene()
    {
        boardSizeInPixels = 300;
        movingItem_ = NULL;
    }

    void BoardScene::updateBoardSize(int size) {
        this->clear();
        this->boardSize = size;
        QPen noPen(Qt::NoPen);
        QBrush noBrush(Qt::NoBrush);

        this->addRect(0, 0, boardSizeInPixels, boardSizeInPixels, noPen, noBrush);
        shiftSize = std::min(width(), height()) / size;


        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                BoardCell* boardCell = new BoardCell(0, 0, shiftSize, shiftSize);
                boardCell->setCoordinates(i, j);
                boardCell->setPos(i * shiftSize, j * shiftSize);
                this->addItem(boardCell);
            }
        }

        TruckCarCell* truckCarCell = new TruckCarCell(0, 0, shiftSize, shiftSize);
        this->addItem(truckCarCell);
        truckCarCell->setPos(QPointF(boardSizeInPixels, 0) + truckCarCell->boundingRect().center());
        truckCarCell->setFlag(QGraphicsItem::ItemIsMovable);

    }

    void BoardScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
        QGraphicsItem *item = this->itemAt(event->scenePos(), QTransform());
        if (item) {
            if(item->flags().testFlag(QGraphicsItem::ItemIsMovable))
            {
                std::cout << "Mouse Pressed on Movable Item" << std::endl;
                movingItem_ = item;
            }

            if (event->button() == Qt::LeftButton) {
                ((BoardCell*)item)->setChecked(true);
                BlockingEventQueue::getInstance().push(new StreetFieldAddedEvent(((BoardCell*)item)->getCoordinates()));
            } else {
                ((BoardCell*)item)->setChecked(false);
                BlockingEventQueue::getInstance().push(new StreetFieldRemovedEvent(((BoardCell*)item)->getCoordinates()));
            }
            item->update();
        }
    }

    void BoardScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
        if (movingItem_ && movingItem_->flags().testFlag(QGraphicsItem::ItemIsMovable)) {
            if (isInsideScene(event->scenePos())) {
                movingItem_->setPos(event->scenePos() - movingItem_->boundingRect().center());
                std::cout << "inside" << std::endl;
            }/* else {
                movingItem_->setPos(QPointF(boardSizeInPixels, 0) + movingItem_->boundingRect().center());
                std::cout << "outside" << std::endl;
            }*/
        }
        std::cout << "event" << std::endl;
    }

    void BoardScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
        if (movingItem_ && movingItem_->flags().testFlag(QGraphicsItem::ItemIsMovable)) {
            //QPointF pos = movingItem_->pos();

            if (isInsideBoard(event->scenePos())) {
                int endX = (event->scenePos().x()) / shiftSize;
                int endY = (event->scenePos().y()) / shiftSize;
                std::cout << "x >> " << event->scenePos().x() << " y >> " << event->scenePos().y() << std::endl;
                std::cout << "x >> " << endX << " y >> " << endY << std::endl;
                movingItem_->setPos(endX * shiftSize, endY * shiftSize);
                std::cout << "x >> " << movingItem_->pos().x() << " y >> " << movingItem_->pos().y() << std::endl;
                std::cout << "shift >> " << shiftSize << std::endl;
            } else {
                movingItem_->setPos(QPointF(boardSizeInPixels, 0) + movingItem_->boundingRect().center());
            }

            movingItem_ = NULL;
        }
    }

    bool BoardScene::isInsideBoard(const QPointF& pos) {
        if (pos.x() >= 0 && pos.x() < boardSizeInPixels && pos.y() >= 0 && pos.y() < boardSizeInPixels) {
            return true;
        }
        return false;
    }

    bool BoardScene::isInsideScene(const QPointF& pos) {
        if (pos.x() >= 0 && pos.x() < boardSizeInPixels + 1.5 * shiftSize &&
                pos.y() >= 0 && pos.y() < boardSizeInPixels) {
            return true;
        }
        return false;
    }
}

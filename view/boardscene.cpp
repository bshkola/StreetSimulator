#include "boardscene.h"
#include "boardcell.h"
#include "truckcaritem.h"
#include "passengercaritem.h"
#include <iostream>
#include <vector>
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
        activeMenuItem_ = NULL;
    }

    void BoardScene::updateBoardSize(int size) {
        this->clear();
        this->boardSize = size;
        QPen noPen(Qt::NoPen);
        QBrush noBrush(Qt::NoBrush);

        this->addRect(0, 0, boardSizeInPixels + 50, boardSizeInPixels, noPen, noBrush); // change 50 to a variable
        shiftSize = std::min(width(), height()) / size;

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                BoardCell* boardCell = new BoardCell(0, 0, shiftSize, shiftSize);
                boardCell->setCoordinates(i, j);
                boardCell->setPos(i * shiftSize, j * shiftSize);
                this->addItem(boardCell);
            }
        }

        std::vector<IMovableItem*> menuItems;
        menuItems.push_back(new TruckCarItem(QRectF(shiftSize / 4, shiftSize / 4, shiftSize / 2, shiftSize / 2)));
        menuItems.push_back(new PassengerCarItem(QRectF(shiftSize / 4, shiftSize / 4, shiftSize / 2, shiftSize / 2)));

        foreach(IMovableItem* availableItem, menuItems) {
            this->addItem(availableItem);
            availableItem->setPos(QPointF(boardSizeInPixels, shiftSize * availableItem->getItemIndex()) + availableItem->boundingRect().center());
            availableItem->setFlag(QGraphicsItem::ItemIsMovable);
        }

        /*IMovableItem* truckCarItem = new TruckCarItem(0, 0, shiftSize, shiftSize);
        this->addItem(truckCarItem);
        truckCarItem->setPos(QPointF(boardSizeInPixels, 0) + truckCarItem->boundingRect().center());
        truckCarItem->setFlag(QGraphicsItem::ItemIsMovable);

        truckCarItem = new TruckCarItem(0, 0, shiftSize, shiftSize);
        this->addItem(truckCarItem);
        truckCarItem->setPos(QPointF(boardSizeInPixels, 0) + truckCarItem->boundingRect().center());
        truckCarItem->setFlag(QGraphicsItem::ItemIsMovable);*/
    }

    void BoardScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
        QGraphicsItem *item = this->itemAt(event->scenePos(), QTransform());
        if (item) {
            if(item->flags().testFlag(QGraphicsItem::ItemIsMovable))
            {
                activeMenuItem_ = (IMovableItem*)item;
            } else {
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
    }

    void BoardScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
        if (activeMenuItem_ && activeMenuItem_->flags().testFlag(QGraphicsItem::ItemIsMovable)) {
            if (isInsideScene(event->scenePos())) {
                activeMenuItem_->setPos(event->scenePos() - activeMenuItem_->boundingRect().center());
            }/* else {
                movingItem_->setPos(QPointF(boardSizeInPixels, 0) + movingItem_->boundingRect().center());
            }*/
        }
    }

    void BoardScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
        if (activeMenuItem_ && activeMenuItem_->flags().testFlag(QGraphicsItem::ItemIsMovable)) {
            if (isInsideBoard(event->scenePos())) {
                int endX = (event->scenePos().x()) / shiftSize;
                int endY = (event->scenePos().y()) / shiftSize;
                activeMenuItem_->setPos(endX * shiftSize, endY * shiftSize);

                if (!activeMenuItem_->isOnBoard()) {
                    IMovableItem* menuItem = activeMenuItem_->clone();// new TruckCarItem(0, 0, shiftSize, shiftSize);
                    this->addItem(menuItem);
                    menuItem->setPos(QPointF(boardSizeInPixels, shiftSize * menuItem->getItemIndex()) + menuItem->boundingRect().center());
                    menuItem->setFlag(QGraphicsItem::ItemIsMovable);
                }

                activeMenuItem_->setCoordinates(endX, endY);
            } else {
                if (activeMenuItem_->isOnBoard()) {
                    removeItem(activeMenuItem_);
                } else {
                    activeMenuItem_->setPos(QPointF(boardSizeInPixels, shiftSize * activeMenuItem_->getItemIndex()) + activeMenuItem_->boundingRect().center());
                }
            }
            activeMenuItem_ = NULL;
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

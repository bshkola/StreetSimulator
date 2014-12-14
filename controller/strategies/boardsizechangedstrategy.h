#ifndef BOARDSIZECHANGEDSTRATEGY_H
#define BOARDSIZECHANGEDSTRATEGY_H

#include "istrategy.h"

class BoardSizeChangedStrategy : public IStrategy
{
public:
    BoardSizeChangedStrategy(IModel* model, IView* view);
    void perform(IEvent* event);

private:
    IModel* model_;
    IView* view_;
};

#endif // BOARDSIZECHANGEDSTRATEGY_H

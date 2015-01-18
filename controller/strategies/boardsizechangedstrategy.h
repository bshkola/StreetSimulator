#ifndef BOARDSIZECHANGEDSTRATEGY_H
#define BOARDSIZECHANGEDSTRATEGY_H

#include "istrategy.h"

class BoardSizeChangedStrategy : public IStrategy
{
public:
    BoardSizeChangedStrategy(std::shared_ptr<IModel> model, IView* view);
    void perform(IEvent* event);
    virtual ~BoardSizeChangedStrategy();

private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // BOARDSIZECHANGEDSTRATEGY_H

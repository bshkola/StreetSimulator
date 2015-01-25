//Author: Bogdan Shkola
//Strategy handling board size changing
#ifndef BOARDSIZECHANGEDSTRATEGY_H
#define BOARDSIZECHANGEDSTRATEGY_H

#include "istrategy.h"

class BoardSizeChangedStrategy : public IStrategy
{
public:
    BoardSizeChangedStrategy(std::shared_ptr<IModel> model, IView* view);
    virtual ~BoardSizeChangedStrategy();

    //Inherited method
    void perform(std::shared_ptr<IEvent> event);
private:
    std::shared_ptr<IModel> model_;
    IView* view_;
};

#endif // BOARDSIZECHANGEDSTRATEGY_H

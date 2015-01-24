//Author: Bogdan Shkola
//Representing interface of the main window of application.

#ifndef IVIEW_H
#define IVIEW_H

#include "../common/board.h"
#include "../common/cameraoptions.h"

class IView
{
public:
    IView();
    virtual void show() = 0;
    virtual void showBoard(const Board& board) = 0;
    virtual void setCameraOptions(const CameraOptions& cameraOptions) = 0;
    virtual ~IView() {}
};

#endif // IVIEW_H

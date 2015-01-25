//Author: Bogdan Shkola
//Representing interface of the main window of application.
#ifndef IVIEW_H
#define IVIEW_H

#include "../common/board.h"
#include "isimulatorview.h"
#include "../common/cameraoptions.h"

class IView
{
public:
    IView() {}
    virtual ~IView() {}
    //Dsiplating the window
    virtual void show() = 0;
    //Displaying the board graphics scene
    virtual void showBoard(const Board& board) = 0;
    //Sets camera options in the form of the view
    virtual void setCameraOptions(const CameraOptions& cameraOptions) = 0;
    //Displays simulation window
    virtual void showSimulationWindow() = 0;
    //Displays information message on the window
    virtual void showMessageSignal(std::string message) = 0;
};

#endif // IVIEW_H

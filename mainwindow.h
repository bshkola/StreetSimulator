#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateButtons();

protected:

private:
    Ui::MainWindow *ui;

    QVector<QPushButton*> buttons;

//    QPushButton* sizeButton;
//    QPushButton* streetsButton;
//    QPushButton* removeStreetsButton;
//    QPushButton* movableObjectButton;
//    QPushButton* cameraButton;
};

#endif // MAINWINDOW_H

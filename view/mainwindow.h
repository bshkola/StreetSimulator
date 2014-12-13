#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsScene>
#include "iview.h"
#include "boardscene.h"


namespace Ui {
    class MainWindow;
    class BoardScene;
}

class MainWindow : public QMainWindow, public IView
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void show();
    void resizeEvent(QResizeEvent *event);
    void closeEvent(QCloseEvent *event);
    void showBoard(const Board& board);
    virtual ~MainWindow();

public slots:
    void updateButtons();
    void updateBoardSize();

protected:

private:
    Ui::MainWindow *ui;
    Ui::BoardScene* boardScene;

    QVector<QPushButton*> buttons;

};

#endif // MAINWINDOW_H

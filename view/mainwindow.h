#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsScene>

namespace Ui {
    class MainWindow;
    class BoardScene;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void resizeEvent(QResizeEvent *event);
    ~MainWindow();

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

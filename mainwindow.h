#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "managerwpisow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT     

public:
    MainWindow(ManagerWpisow* manager, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void odswiezListe();
    void on_addWpisButton_clicked();

private:
    Ui::MainWindow *ui;
    ManagerWpisow* m_managerWpisow;
};
#endif // MAINWINDOW_H

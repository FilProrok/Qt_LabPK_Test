#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "managerwpisow.h"
#include "wpis.h"

MainWindow::MainWindow(ManagerWpisow* managerWpisow, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_managerWpisow(managerWpisow)
{
    ui->setupUi(this);
    this->setFixedSize(800, 600);

    connect(m_managerWpisow, &ManagerWpisow::daneZmienione, this, &MainWindow::odswiezListe);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addWpisButton_clicked()
{
    QString content= ui->wpisInput->toPlainText();
    QDateTime creationDate = ui->dateTimeInput->dateTime();
    Wpis *wpis = new Wpis();
    wpis->setContent(content);
    wpis->setCreationDate(creationDate);
    m_managerWpisow->dodajWpis(*wpis);
}

void MainWindow::odswiezListe(){

    // sortowanie
    m_managerWpisow->sortujListeWpisow();

    ui->WidokListyWpisow->clear();
    for(int i = 0; i < m_managerWpisow->getWpisy().size(); i++){

        if( i > 0){
            ui->WidokListyWpisow->append("------------------------------------------------------------------------------------");
        }

        Wpis wpis = m_managerWpisow->getWpisy()[i];

        QString sformatowanaData = QString("<b>%1</b>").arg(wpis.getCreationDate().toString());

        ui->WidokListyWpisow->append(sformatowanaData);
        ui->WidokListyWpisow->append(wpis.getContent());
    }
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "card.h"
#include <QTime>
#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif
MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_start_clicked()
{
	Card *card = new Card;
	card->show();
	this->close();
}

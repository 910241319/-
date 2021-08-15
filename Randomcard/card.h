#ifndef CARD_H
#define CARD_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include "cardimage.h"
#include "allbody.h"
#include "action.h"
#include "Database.h"
#pragma comment(lib,"Database.lib")
//#include "Database.h"
namespace Ui {
	class Card;
}

class Card : public QWidget
{
	Q_OBJECT

public:
	explicit Card(QWidget *parent = 0);
	~Card();

	void loadImg(int num, int pic, int actnum, int wea);
	void deleteWID();
	void showtext();
    void loadduoImg(int num[20],int pic[20],int actnum,int weapo[20]);
	private slots:
	void on_danchou_clicked();
    void Card::closeEvent(QCloseEvent *event)
    {
        all->close();
        this->close();
    }
	void on_shilian_clicked();
public slots:
    void showww();
private:
	CardImage* image[20];
	Ui::Card *ui;
	void random(int count);
	int suijifanwei;
	int ssr = 0;
	int sr = 0;
	int r = 0;
	int allcount = 0;
	double avg = 0;
	Allbody* all = new Allbody;
	Action* act = new Action;
	Database *db = new Database;
};

#endif // CARD_H

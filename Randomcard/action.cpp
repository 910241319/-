#include "action.h"
#include "ui_action.h"
#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif
Action::Action(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Action)
{
	ui->setupUi(this);
	countnumber = 0;
	actnum = 0;
}

Action::~Action()
{
	delete ui;
	delete movie;
}

void Action::loadaction(int num)
{
	if (num == 2)
	{
		actnum = 2;
        movie = new QMovie("F:/qtmode/Randomcard/video/kin.gif");
		ui->label->setMovie(movie);
		movie->start();
		emit(movie->frameCount());
		connect(movie, &QMovie::frameChanged, this, &Action::stopgif);
	}
	else if (num == 1)
	{
		actnum = 1;
		movie = new QMovie("F:/qtmode/Randomcard/video/pur.gif");
		ui->label->setMovie(movie);
		movie->start();
		emit(movie->frameCount());
		connect(movie, &QMovie::frameChanged, this, &Action::stopgif);
	}
	else if (num == 0)
	{
		actnum = 0;
		movie = new QMovie("F:/qtmode/Randomcard/video/white.gif");
		ui->label->setMovie(movie);
		movie->start();
		emit(movie->frameCount());
		connect(movie, &QMovie::frameChanged, this, &Action::stopgif);
	}
}

void Action::stopgif()
{
	if (actnum == 0)
	{
		if (movie->currentFrameNumber() < movie->frameCount())
			countnumber++;
		if (countnumber == 60)
		{
			movie->stop();
			countnumber = 0;
            this->destroy(true,true);
		}
	}

	if (actnum == 1)
	{
		if (movie->currentFrameNumber() < movie->frameCount())
			countnumber++;
		if (countnumber == 60)
		{
			movie->stop();
			countnumber = 0;
            this->destroy(true,true);
		}
	}

	if (actnum == 2)
	{
		if (movie->currentFrameNumber() == movie->frameCount() - 1)
		{
			movie->stop();
			countnumber = 0;
            this->destroy(true,true);
		}
	}
}

void Action::showpic()
{
    QPixmap pixmap("image/youla.png");
    this->setAutoFillBackground(true);
    QPalette bgPalette = this->palette();
    bgPalette.setBrush(QPalette::Background, QBrush(pixmap.scaled(this->size(), Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(bgPalette);
    this->setAutoFillBackground(true);
}

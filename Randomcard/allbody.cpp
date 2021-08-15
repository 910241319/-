#include "allbody.h"
#include "ui_allbody.h"
#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif
Allbody::Allbody(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Allbody)
{
	ui->setupUi(this);
    ui->destroyy->setIconSize(ui->destroyy->size());
    QIcon icon;
     icon.addFile("icon/ccc.png");
     ui->destroyy->setIcon(icon);
//    QPixmap icon1(tr("icon/ccc.png"));
//    ui->destroyy->setIcon(icon1.scaled(ui->close->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
     //ui->close->setFixedSize(icon1.size());
    this -> setWindowFlags(Qt::FramelessWindowHint);
	count = 0;
	num = 0;
    picnum = 0;
    countnumber=0;
}

Allbody::~Allbody()
{
	delete ui;
}

void Allbody::loadimage(QString path)
{
	QPixmap pixmap(path);
	this->setAutoFillBackground(true);
	QPalette bgPalette = this->palette();
    bgPalette.setBrush(QPalette::Background, QBrush(pixmap.scaled(this->size(), Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
	this->setPalette(bgPalette);
    this->setAutoFillBackground(true);
}

void Allbody::loadduo(QString path[20])
{
    picnum = 0;
    for(int i=1;i<10;i++)
    pathss[i] = path[i];
    QPixmap pixmap(path[0]);
    this->setAutoFillBackground(true);
    QPalette bgPalette = this->palette();
    bgPalette.setBrush(QPalette::Background, QBrush(pixmap.scaled(this->size(), Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));
    this->setPalette(bgPalette);
    this->setAutoFillBackground(true);
    //picnum++;
}

void Allbody::loadaction(int num)
{
    countnumber=0;
    qDebug()<<picnum;
    ui->label->show();
    if (num == 2)
    {
        actnum = 2;
        movie = new QMovie("video/jin.gif");
        ui->label->setMovie(movie);
        movie->start();
        emit(movie->frameCount());
        connect(movie, &QMovie::frameChanged, this, &Allbody::stopgif);
    }
    else if (num == 1)
    {
        actnum = 1;
        movie = new QMovie("video/zi.gif");
        ui->label->setMovie(movie);
        movie->start();
        emit(movie->frameCount());
        connect(movie, &QMovie::frameChanged, this, &Allbody::stopgif);
    }
    else if (num == 0)
    {
        actnum = 0;
        movie = new QMovie("video/bai.gif");
        ui->label->setMovie(movie);
        movie->start();
        emit(movie->frameCount());
        connect(movie, &QMovie::frameChanged, this, &Allbody::stopgif);
    }
}

void Allbody::getcount(int cou)
{
	count = cou;
}

void Allbody::on_close_clicked()
{
    qDebug()<<picnum<<"start";
    if(picnum >= 1&&picnum<10&&count==10)
    {
    QString path=pathss[picnum];
    QPixmap pixmap(path);
    this->setAutoFillBackground(true);
    QPalette bgPalette = this->palette();
    bgPalette.setBrush(QPalette::Background, QBrush(pixmap.scaled(this->size(), Qt::IgnoreAspectRatio)));
    this->setPalette(bgPalette);
    this->setAutoFillBackground(true);
    picnum++;
    }
    else if(picnum == 1&&count==1 || picnum == 10)
    {
        count = 0;
        num = 0;
        picnum = 0;
        countnumber=0;
        this->close();
    }
    else if(picnum==0)
    {
        movie->blockSignals(true);
        ui->label->hide();
        picnum++;
    }
}

void Allbody::stopgif()
{
    //qDebug()<<countnumber;
    if (actnum == 0)
    {
        if (movie->currentFrameNumber() < movie->frameCount())
            countnumber++;
        if (countnumber == 59)
        {
            movie->stop();
            countnumber = 0;
            picnum =1;
            ui->label->hide();

        }
    }

    if (actnum == 1)
    {
        if (movie->currentFrameNumber() < movie->frameCount())
            countnumber++;
        if (countnumber == 59)
        {
            movie->stop();
            countnumber = 0;
            picnum =1;
            ui->label->hide();

        }
    }

    if (actnum == 2)
    {
        if (movie->currentFrameNumber() == movie->frameCount() - 1)
        {
            movie->stop();
            countnumber = 0;
            picnum =1;
            ui->label->hide();

        }
    }
}

void Allbody::on_destroyy_clicked()
{
    count = 0;
    num = 0;
    picnum = 0;
    countnumber=0;
    movie->blockSignals(true);
    this->close();
}

#include "card.h"
#include "ui_card.h"
#include <QTime>
#include <QDebug>
#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif
Card::Card(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Card)
{
	ui->setupUi(this);
	showtext();
	image[9] = new CardImage;
	image[8] = new CardImage;
	image[7] = new CardImage;
	image[6] = new CardImage;
	image[5] = new CardImage;
	image[4] = new CardImage;
	image[3] = new CardImage;
	image[2] = new CardImage;
	image[1] = new CardImage;
	image[0] = new CardImage;
	db->InitAdo();
}

Card::~Card()
{
	delete ui;
	for (int i = 0; i < 10; i++)
		delete image[i];
	delete db;
}

void Card::on_danchou_clicked()
{
	deleteWID();
	image[9] = new CardImage;
	image[8] = new CardImage;
	image[7] = new CardImage;
	image[6] = new CardImage;
	image[5] = new CardImage;
	image[4] = new CardImage;
	image[3] = new CardImage;
	image[2] = new CardImage;
	image[1] = new CardImage;
	image[0] = new CardImage;
	random(1);
	showtext();
}

void Card::on_shilian_clicked()
{
	deleteWID();
	image[9] = new CardImage;
	image[8] = new CardImage;
	image[7] = new CardImage;
	image[6] = new CardImage;
	image[5] = new CardImage;
	image[4] = new CardImage;
	image[3] = new CardImage;
	image[2] = new CardImage;
	image[1] = new CardImage;
	image[0] = new CardImage;
	random(10);
    showtext();
}

void Card::showww()
{
    qDebug()<<"123456789";
}

void Card::random(int count)
{

	QTime time;
	time = QTime::currentTime();
	qsrand(time.msec() + time.second() * 1000);
	int num = qrand() % 1000;
	//当玩家进行单抽时
	if (count == 1)
	{
		//进行随机
		//int num = rand() % 1000;
		//一百八十发大保底
		if (allcount == 179)
		{
			int pic = rand() % 17;
			loadImg(5, pic, 2, 0);
			ssr++;
		}
		else if (allcount % 9 == 0 && allcount != 0)
		{
			int num2 = rand() % 1000;
			if (num2 >= 993 && num2 <= 999)
			{
				int pic = rand() % 17;
				loadImg(5, pic, 2, 0);
				ssr++;
			}
			else
			{
				int pic = rand() % 1000;
				if (pic >= 0 && pic <= 399)
				{
					int kk = qrand() % 16;
                    loadImg(4, kk, 1, 1);
				}
				else
				{
					int kk = qrand() % 19 + 16;
					loadImg(4, kk, 1, 0);
				}
				sr++;
			}
		}
		else
		{
			if (num >= 0 && num <= 943)
			{
				int pic = qrand() % 13;
                //qDebug() << pic << "pic";
				loadImg(3, pic, 0, 1);
				r++;
			}
			else if (num >= 943 && num <= 993)
			{
				int pic = qrand() % 1000;
				if (pic >= 0 && pic <= 399)
				{
					int kk = qrand() % 16;
                    loadImg(4, kk, 1, 1);
				}
				else
				{
					int kk = qrand() % 19 + 16;
					loadImg(4, kk, 1, 0);
				}
				sr++;
			}
			else if (num >= 994 && num <= 999)
			{
				int pic = qrand() % 17;
				//qDebug() << pic << "pic";
				loadImg(5, pic, 2, 0);
				ssr++;
			}
		}
        //connect(act,SIGNAL(destroyed(QObject*)),this,SLOT(showww()));
        all->show();
        //act->show();
        //connect(act,&Allbody::destroyed,act,&Action::show);
        //act->show();
		allcount++;
		ui->gridLayout_2->addWidget(image[0], 0, 0, Qt::AlignHCenter);
	}
	//当玩家进行十连抽时
	else
	{
        int picnum[20];
        int pics[20];
        int actionmovie;
        int weapon[20];
		for (int i = 0; i < count; i++)
		{
			all->loadimage("F:/qtmode/Randomcard/red.jpg");
			all->getcount(count);
			all->show();
			if (allcount == 89)
			{
                int pic = qrand() % 17;
                picnum[i] = 5;
                pics[i] = pic;
                actionmovie = 2;
                weapon[i] = 0;
                //loadImg(5, pic, 2, 0);
				ssr++;
			}
			else
			{
				if (i == 9)
				{
					int num2 = qrand() % 1000;
					if (num2 >= 993 && num2 <= 999)
					{
						int pic = qrand() % 17;
                        picnum[i] = 5;
                        pics[i] = pic;
                        actionmovie = 2;
                        weapon[i] = 0;
                        //loadImg(5, pic, 2, 0);
						ssr++;
					}
					else
					{
						int pic = qrand() % 1000;
						if (pic >= 0 && pic <= 399)
						{
							int kk = qrand() % 16;
                            picnum[i] = 4;
                            pics[i] = kk;
                            if(actionmovie!=2)
                            actionmovie = 1;
                            weapon[i] = 1;
                            //loadImg(4, kk, 1, 0);
						}
						else
						{
							int kk = qrand() % 19 + 16;
                            picnum[i] = 4;
                            pics[i] = kk;
                            if(actionmovie!=2)
                            actionmovie = 1;
                            weapon[i] = 0;
						}
						sr++;
					}
				}
				else
				{
					//int num = rand() % 1000;

					if (num >= 0 && num <= 943)
					{
						int pic = qrand() % 13;
                        picnum[i] = 3;
                        pics[i] = pic;
                        if(actionmovie!=2)
                        actionmovie = 0;
                        weapon[i] = 1;
						r++;
					}
					else if (num >= 943 && num <= 993)
					{
						int pic = qrand() % 1000;
						if (pic >= 0 && pic <= 399)
						{
							int kk = qrand() % 16;
                            picnum[i] = 4;
                            pics[i] = kk;
                            if(actionmovie!=2)
                            actionmovie = 1;
                            weapon[i] = 1;
						}
						else
						{
							int kk = qrand() % 19 + 16;
                            picnum[i] = 4;
                            pics[i] = kk;
                            if(actionmovie!=2)
                            actionmovie = 1;
                            weapon[i] = 0;
						}
						sr++;
					}
					else if (num >= 994 && num <= 999)
					{
						int pic = qrand() % 17;
                        picnum[i] = 5;
                        pics[i] = pic;
                        actionmovie = 2;
                        weapon[i] = 0;
						ssr++;
					}
				}
			}
			allcount++;
		}
        loadduoImg(picnum,pics,actionmovie,weapon);
        ui->gridLayout_2->addWidget(image[0], 0, 0);
		ui->gridLayout_2->addWidget(image[1], 0, 1);
		ui->gridLayout_2->addWidget(image[2], 0, 2);
		ui->gridLayout_2->addWidget(image[3], 0, 3);
		ui->gridLayout_2->addWidget(image[4], 0, 4);
		ui->gridLayout_2->addWidget(image[5], 1, 0);
		ui->gridLayout_2->addWidget(image[6], 1, 1);
		ui->gridLayout_2->addWidget(image[7], 1, 2);
		ui->gridLayout_2->addWidget(image[8], 1, 3);
		ui->gridLayout_2->addWidget(image[9], 1, 4);
	}
}

void Card::loadImg(int num, int pic, int actnum, int wea)
{
	if (actnum == 2)
        all->loadaction(2);
	else if (actnum == 1)
        all->loadaction(1);
	else
        all->loadaction(0);
    all->getcount(1);
	QString path;
	QString path2;
	Database::path pp;
    qDebug()<<pic<<num<<wea;
	pp = db->getPath(pic, num, wea);
	path2 = pp.iconpath;
	path = pp.imgpath;
    //qDebug() << path2 << path;
    qDebug()<<path<<"path";
    qDebug()<<path2<<"path2";
	all->loadimage(path);
	image[0]->loadimage(path2);
}

void Card::deleteWID()
{
	for (int i = 0; i < 10; i++)
		delete image[i];
}

void Card::showtext()
{
	ui->textBrowser_2->clear();
	avg = (double)ssr / allcount;
	ui->textBrowser_2->append("已抽到");
	ui->textBrowser_2->append(QString("总计:%1").arg(allcount));
	ui->textBrowser_2->append(QString("五星数量:%1").arg(ssr));
	ui->textBrowser_2->append(QString("四星数量:%1").arg(sr));
	ui->textBrowser_2->append(QString("三星数量:%1").arg(r));
	//    ui->textBrowser_2->append(QString("R:%1").arg(b));
	//    ui->textBrowser_2->append(QString("N:%1").arg(white));
    ui->textBrowser_2->append(QString("五星概率:%1").arg(avg));
}

void Card::loadduoImg(int num[], int pic[], int actnum,int weapo[20])
{
    if (actnum == 2)
        all->loadaction(2);
    else if (actnum == 1)
        all->loadaction(1);
    else
        all->loadaction(0);
    all->getcount(10);
    QString path[20];
    QString path2[20];
    Database::path pp;
    for(int i=0;i<10;i++)
    {
    pp = db->getPath(pic[i], num[i], weapo[i]);
    path2[i] = pp.iconpath;
    path[i] = pp.imgpath;
    qDebug()<<path[i]<<"path";
    qDebug()<<path2[i]<<"path2";
    image[i]->loadimage(path2[i]);
    }
    all->loadduo(path);
}

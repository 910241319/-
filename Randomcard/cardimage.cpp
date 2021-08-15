#include "cardimage.h"
#include "ui_cardimage.h"
#if _MSC_VER >= 1600  
#pragma execution_character_set("utf-8")  
#endif
CardImage::CardImage(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CardImage)
{
	ui->setupUi(this);
}

CardImage::~CardImage()
{
	delete ui;
}

void CardImage::loadimage(QString path)
{
	QImage *img = new QImage; //新建一个image对象
	img->load(path); //将图像资源载入对象img，注意路径，可点进图片右键复制路径
	*img = img->scaled(200, 200, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
	ui->label->setPixmap(QPixmap::fromImage(*img));
}

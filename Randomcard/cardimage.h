#ifndef CARDIMAGE_H
#define CARDIMAGE_H

#include <QWidget>

namespace Ui {
class CardImage;
}

class CardImage : public QWidget
{
    Q_OBJECT

public:
    explicit CardImage(QWidget *parent = 0);
    ~CardImage();
    void loadimage(QString path);
private:
    Ui::CardImage *ui;
};

#endif // CARDIMAGE_H

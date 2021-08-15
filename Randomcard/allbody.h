#ifndef ALLBODY_H
#define ALLBODY_H

#include <QWidget>
#include <QMessageBox>
#include <QMouseEvent>
#include <QDebug>
#include <QPalette>
#include <QScreen>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <QMovie>
#include <QIcon>
namespace Ui {
class Allbody;
}

class Allbody : public QWidget
{
    Q_OBJECT

public:
    explicit Allbody(QWidget *parent = 0);
    ~Allbody();
    void loadimage(QString path);
    void loadduo(QString path[20]);
    void loadaction(int num);
    void getcount(int cou);
private slots:
    void on_close_clicked();
private slots:
    void stopgif();
    void on_destroyy_clicked();

private:
    Ui::Allbody *ui;
    int count;
    int num;
    QString pathss[20];
    int picnum;
    QMovie *movie;
    QTimer timer;
    int countnumber;
    int actnum;
};

#endif // ALLBODY_H

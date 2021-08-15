#ifndef ACTION_H
#define ACTION_H

#include <QWidget>
#include <QMovie>
#include <QMouseEvent>
#include <QTime>
#include <QTimer>
#include <QDebug>
namespace Ui {
class Action;
}

class Action : public QWidget
{
    Q_OBJECT

public:
    explicit Action(QWidget *parent = 0);
    ~Action();
    void loadaction(int num);
    void showpic();
private slots:
    void stopgif();
private:
    Ui::Action *ui;
    QMovie *movie;
    QTimer timer;
    int countnumber;
    int actnum;
};

#endif // ACTION_H

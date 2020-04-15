#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QPixmap>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);

    explicit MyPushButton(QPixmap normalImg,
                          QPixmap pressImg,
                          QWidget *parent = nullptr);

    explicit MyPushButton(QString normalImgPath,
                          QString pressImgPath,
                          QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

private:
    //按钮正常情况和按下情况的两张图片
    QPixmap normalImg_;
    QPixmap pressImg_;
    //两张图片的宽高差的绝对值的二分之一
    int x_;
    int y_;

signals:

};

#endif // MYPUSHBUTTON_H

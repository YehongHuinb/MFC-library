#include "mypushbutton.h"
#include "mybuttongroup.h"

MyPushButton::MyPushButton(QWidget *parent):
    QPushButton(parent)
{

}

MyPushButton::MyPushButton(QPixmap normalImg, QPixmap pressImg, QWidget *parent):
    QPushButton(parent), normalImg_(normalImg), pressImg_(pressImg)
{
    x_ = abs(normalImg_.width() - pressImg_.width()) / 2;
    y_ = abs(normalImg_.height() - pressImg_.height()) / 2;
    setFixedSize(normalImg_.width(), normalImg_.height());
    setIcon(normalImg_);
    setIconSize(QSize(normalImg_.width(), normalImg_.height()));
    setStyleSheet("QPushButton{border:0px;}");
}

MyPushButton::MyPushButton(QString normalImgPath, QString pressImgPath, QWidget *parent) :
    QPushButton(parent), normalImg_(QPixmap(normalImgPath)), pressImg_(QPixmap(pressImgPath))
{
    MyPushButton(normalImg_, pressImg_, parent);
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if( MyButtonGroup::hasClicked )
    {
        return;
    }
    if( !pressImg_.isNull() )
    {
        move(this->x()+x_, this->y()+y_);
        setFixedSize(pressImg_.width(), pressImg_.height());
        setIcon(pressImg_);
        setIconSize(QSize(pressImg_.width(), pressImg_.height()));
        setStyleSheet("QPushButton{border:0px;}");
    }
    return QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if( MyButtonGroup::hasClicked )
    {
        return;
    }
    if( !normalImg_.isNull() )
    {
        move(this->x()-x_, this->y()-y_);
        setFixedSize(normalImg_.width(), normalImg_.height());
        setIcon(normalImg_);
        setIconSize(QSize(normalImg_.width(), normalImg_.height()));
        setStyleSheet("QPushButton{border:0px;}");
    }
    return QPushButton::mouseReleaseEvent(e);
}

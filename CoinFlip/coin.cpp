#include "coin.h"

Coin::Coin(QWidget *parent) : MyPushButton(parent)
{
}

Coin::Coin(QPixmap butImg, QWidget *parent):
    MyPushButton(parent), butImg_(butImg)
{
    setFixedSize( butImg_.width(), butImg_.height() );
    setStyleSheet("QPushButton{border:0px;}");
    setIcon(butImg_);
    setIconSize(QSize(butImg_.width(),butImg_.height()));

    goldToSilver = new QTimer(this);
    silverToGold = new QTimer(this);
    isGold_ = true;
    pixNum_ = 1;

    connect(goldToSilver, &QTimer::timeout, this, [=](){
        if( pixNum_ < 8 )
        {
            QString str = QString(":/res/Coin000%1.png").arg(++pixNum_);
            butImg_.load(str);
            setIcon(butImg_);
            setIconSize(QSize(butImg_.width(), butImg_.height()));
        }
        else
        {
            goldToSilver->stop();
        }
    });

    connect(silverToGold, &QTimer::timeout, this, [=](){

        if( pixNum_ > 1 )
        {
            QString str = QString(":/res/Coin000%1.png").arg(--pixNum_);
            butImg_.load(str);
            setIcon(butImg_);
            setIconSize(QSize(butImg_.width(), butImg_.height()));
        }
        else
        {
            silverToGold->stop();
        }

    });
}

Coin::Coin(QString butImgPath, QWidget *parent):
    MyPushButton(parent), butImg_(QPixmap(butImgPath))
{
    Coin( butImg_, parent );
}

Coin::Coin(QPixmap nor, QPixmap pre, QWidget *parent):
    MyPushButton(nor, pre, parent), butImg_(nor)
{
    goldToSilver = new QTimer(this);
    silverToGold = new QTimer(this);
    isGold_ = true;
    pixNum_ = 1;

    connect(goldToSilver, &QTimer::timeout, this, [=](){
        if( pixNum_ < 8 )
        {
            QString str = QString(":/res/Coin000%1.png").arg(++pixNum_);
            butImg_.load(str);
            setIcon(butImg_);
            setIconSize(QSize(butImg_.width(), butImg_.height()));
        }
        else
        {
            goldToSilver->stop();
        }
    });

    connect(silverToGold, &QTimer::timeout, this, [=](){

        if( pixNum_ > 1 )
        {
            QString str = QString(":/res/Coin000%1.png").arg(--pixNum_);
            butImg_.load(str);
            setIcon(butImg_);
            setIconSize(QSize(butImg_.width(), butImg_.height()));
        }
        else
        {
            silverToGold->stop();
        }
    });
}

void Coin::changeFlag()
{
    if( isGold_ )
    {
        goldToSilver->start(30);
    }
    else
    {
        silverToGold->start(30);
    }
    isGold_ = !isGold_;
}

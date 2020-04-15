#ifndef COIN_H
#define COIN_H

#include "mypushbutton.h"
#include <QTimer>
#include <QDebug>

class Coin : public MyPushButton
{
    Q_OBJECT
public:
    explicit Coin(QWidget *parent = nullptr);
    explicit Coin(QPixmap butImg, QWidget *parent = nullptr);
    explicit Coin(QString butImgPath, QWidget *parent = nullptr);
    explicit Coin(QPixmap nor, QPixmap pre, QWidget *parent = nullptr);

    void changeFlag();
    QTimer *goldToSilver;
    QTimer *silverToGold;
    bool isGold_;

private:
    QPixmap butImg_;
    int pixNum_;

signals:

};

#endif // COIN_H

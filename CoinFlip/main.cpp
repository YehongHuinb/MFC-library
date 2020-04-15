#include "mainscene.h"
#include "mypushbutton.h"
#include "mybuttongroup.h"
#include "coin.h"
#include <QApplication>
#include <QTimer>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //用于按钮的两张图片
    QPixmap pix;
    QPixmap pressPix;

    //开始界面
    MainSence *startSence = new MainSence();
    startSence->setWindowTitle("翻金币");

    //开始界面的start按钮
    pix.load(":/res/MenuSceneStartButton.png");
    pressPix = pix.scaled(pix.width()*0.95, pix.height()*0.95);
    MyPushButton *startBtn = new MyPushButton(pix, pressPix, startSence);
    startBtn->move(startSence->width()*0.5-startBtn->width()*0.5,
                   startSence->height() *0.7);

    //游戏界面，金币的背景标签
    QWidget *coinBg = new QWidget(startSence);
    coinBg->move(57, 200);
    coinBg->setFixedSize(230, 400);
    coinBg->hide();
    MyButtonGroup *coins = new MyButtonGroup(coinBg);
    //创建金币的背景图片
    pix = QPixmap(":/res/Coin0001.png");
    pressPix = pix.scaled(pix.width()*0.95, pix.height()*0.95);
    for(int i = 0 ; i < 4;i++)
    {
        for(int j = 0 ; j < 4; j++)
        {
            //绘制背景图片
            QLabel* label = new QLabel;
            label->setGeometry(0,0,50,50);
            label->setPixmap(QPixmap(":/res/BoardNode(1).png"));
            label->setParent(coinBg);
            label->move(i*50, j*50);

            Coin *coin = new Coin(pix, label);
            coin->setFixedSize(50, 50);
            coins->addButton(coin, i*4+j);
            QObject::connect(coin, &QPushButton::clicked, coinBg, [=](){
                MyButtonGroup::hasClicked = true;
                QTimer::singleShot(300, coins, [=](){
                    coin->changeFlag();
                    MyButtonGroup::hasClicked = false;
                });

            });
        }
    }

    //选关界面的选关按钮
    QWidget *levels = new QWidget(startSence);
    levels->move(25, 130);
    levels->setFixedSize(270, 340);
    levels->hide();
    MyButtonGroup *menuBtns = new MyButtonGroup(levels);
    //游戏界面的显示关卡标签
    QLabel *level = new QLabel(startSence);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(18);
    font.setBold(true);
    level->setFont(font);
    //设置大小和位置
    level->setGeometry(QRect(30, startSence->height() - 50,200, 50));
    level->hide();
    //创建关卡按钮
    pix.load(":/res/LevelIcon.png");
    pressPix = pix.scaled(pix.width()*0.95, pix.height()*0.95);
    for(int i = 0 ; i < 20;i++)
    {
        MyPushButton * menuBtn = new MyPushButton(pix, pressPix, levels);
        menuBtn->move((i%4)*70 , (i/4)*70);
        menuBtns->addButton(menuBtn, i+1);
        //用label 显示按钮上的数字
        QLabel * label = new QLabel; label->setParent(menuBtn);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        //设置居中
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        QObject::connect(menuBtn, &QPushButton::clicked, levels, [=](){
            //qDebug() << menuBtns->id(menuBtn);
            QTimer::singleShot(300, levels, [=](){
                levels->hide();
                startSence->setIsGame(true);
                startSence->setWindowTitle("游戏");
                QString str = QString("Level: %1").arg(menuBtns->id(menuBtn));
                level->setText(str);
                level->show();
                coinBg->show();
            });
        });
    }

    //选关界面的back按钮
    pix.load(":/res/BackButton.png");
    pressPix.load(":/res/BackButtonSelected.png");
    MyPushButton *backBtn = new MyPushButton(pix, pressPix, startSence);
    backBtn->move(startSence->width()-backBtn->width(),startSence->height()-backBtn->height());
    backBtn->hide();
    //back 按钮在选关界面的作用
    QObject::connect(backBtn, &QPushButton::clicked, startSence, [=](){
        MyButtonGroup::hasClicked = true;
        QTimer::singleShot(300, startSence, [=](){
            if( !startSence->getIsGame() )
            {
                startBtn->show();
                backBtn->hide();
                levels->hide();
                startSence->setWindowTitle("翻金币");
            }
            else
            {
                coinBg->hide();
                levels->show();
                startSence->setIsGame(false);
                startSence->setWindowTitle("选关");
            }
            MyButtonGroup::hasClicked = false;
            level->hide();
        });
    });

    //start 按钮在开始界面的作用
    QObject::connect(startBtn, &QPushButton::clicked, startSence, [=](){
        MyButtonGroup::hasClicked = true;
        QTimer::singleShot(300, startSence, [=](){
           startBtn->hide();
           backBtn->show();
           levels->show();
           startSence->setWindowTitle("选关");
           MyButtonGroup::hasClicked = false;
        });
    });

    startSence->show();
    return a.exec();
}

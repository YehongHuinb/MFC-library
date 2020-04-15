#include "mainscene.h"
#include "ui_mainscene.h"
#include <QPainter>

MainSence::MainSence(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainSence)
{
    ui->setupUi(this);

    isGame_ = false;
    setFixedSize(320, 588);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    connect(ui->actionQuit, &QAction::triggered, this, &QWidget::close);
}

MainSence::~MainSence()
{
    delete ui;
}

void MainSence::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;

    //加载背景图片
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0, 0, width(), height(), pix);
    //加载标题图片
    pix.load(":/res/Title.png");
    //缩放标题图片
    //pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap( 10,30,pix.width(),pix.height(),pix);
}

void MainSence::setIsGame(bool b)
{
    isGame_ = b;
}

bool MainSence::getIsGame()
{
    return isGame_;
}


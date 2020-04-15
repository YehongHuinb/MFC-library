#ifndef MAINSENCE_H
#define MAINSENCE_H

#include <QLabel>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainSence; }
QT_END_NAMESPACE

class MainSence : public QMainWindow
{
    Q_OBJECT

public:
    MainSence(QWidget *parent = nullptr);
    ~MainSence();

    void paintEvent(QPaintEvent *);
    void setIsGame(bool b);
    bool getIsGame();

private:
    Ui::MainSence *ui;
    bool isGame_;
};
#endif // MAINSENCE_H

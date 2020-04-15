#ifndef MYBUTTONGROUP_H
#define MYBUTTONGROUP_H

#include "mypushbutton.h"
#include <QButtonGroup>

class MyButtonGroup : public QButtonGroup
{
    Q_OBJECT
public:
    explicit MyButtonGroup(QWidget *parent = nullptr);
    void mousePressEvent(QMouseEvent *e);

    static bool hasClicked;

private:


signals:

};

#endif // MYBUTTONGROUP_H

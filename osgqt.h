#ifndef OSGQT_H
#define OSGQT_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class osgqt; }
QT_END_NAMESPACE

class osgqt : public QWidget
{
    Q_OBJECT

public:
    osgqt(QWidget *parent = nullptr);
    ~osgqt();

private:
    Ui::osgqt *ui;
};
#endif // OSGQT_H

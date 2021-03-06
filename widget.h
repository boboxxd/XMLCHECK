#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QDir>
#include<QFileDialog>
#include<qDebug>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    ~Widget();
public:

    QFileInfoList list; //保存的是路径下的文件列表；
    int index;          //保存的是文件在列表中的序号；

public slots:
    int onopenBtn();
    int onopenpathBtn();
    int onbeforeBtn();
    int onnextBtn();
    int onsendBtn();

private:
    Ui::Widget *ui;

};

#endif // WIDGET_H

#include "showview.h"

ShowView::ShowView(QWidget *parent) : QLabel(parent)
{
    num=1.0;
    this->setMouseTracking(true);
}


void ShowView::wheelEvent(QWheelEvent * event)
{
    if(event->delta() > 0){

       on_ZoomIn_clicked(); //放大
    }else{

       on_ZoomOut_clicked();//缩小
    }
}

void ShowView ::on_ZoomIn_clicked()

{
    num=num+0.1;
    qDebug()<<num;
}

void ShowView ::on_ZoomOut_clicked()
{
        num=num-0.1;
        if(num<0.1)
            num=0.1;
    qDebug()<<num;
}

void ShowView ::paintEvent(QPaintEvent * event)
{

   QLabel::paintEvent(event);
   QPainter pp(this);
   pix.load(imagename);
   pp.drawPixmap(0,0,pix);


}

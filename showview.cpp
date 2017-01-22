#include "showview.h"


ShowView::ShowView(QWidget *parent) : QLabel(parent)
{
    num=1.0;
    painter.begin(&image);
    //设置字体的类型，大小，加粗，斜体
    QFont font("Arial",40,QFont::Bold,false);
    //设置画笔颜色为红色
    painter.setPen(QColor(Qt::red));
    //添加字体
    painter.setFont(font);
    setAlignment(Qt::AlignCenter);
    //this->setMouseTracking(true);
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
if(startflag==true)
{
   image.load(imagename);
   fileInfo.setFile(xmlname);
       if(!fileInfo.isFile())
       {
           //让字体水平居中
           painter.drawText(0,0,1080,300,Qt::AlignHCenter,"警告：该图找不到相应的XML文件");
           result = QPixmap::fromImage(image).scaled(1080, 720).scaled(1080*num,720*num, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//放缩图片，以固定大小显示
           //在Label控件上显示图片
           setPixmap(result);
       }

   handlexml(QPixmap::fromImage(image),xmlname);
   //放缩图片，以固定大小显示
   result = pix.scaled(1280, 720).scaled(1280*0.9,720*0.9, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
   //在Label控件上显示图片
   setPixmap(result);
}

   startflag=false;
}

void ShowView ::handlexml(QPixmap image,QString xmlname)
{

        MyXML xml(xmlname.toStdString().data());
        for(int i=0;i<xml.m_count;i++)
        {
            xml.MydrawRect( image, xml.m_object[i].m_name, xml.m_object[i].m_start, xml.m_object[i].m_end);
        }
        pix=image;
}

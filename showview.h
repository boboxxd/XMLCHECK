#ifndef SHOWVIEW_H
#define SHOWVIEW_H

#include <Qlabel>
#include<QMouseEvent>
#include<QPaintDevice>
#include<QPainter>
#include<QPaintEngine>
#include<QFileDialog>
#include<QFileInfo>
#include<QDebug>
#include<QMessageBox>
#include"myxml.h"

class ShowView : public QLabel
{
    Q_OBJECT
public:
    explicit ShowView(QWidget *parent = 0);
    void wheelEvent(QWheelEvent * event);
    void paintEvent(QPaintEvent * event);

   void handlexml(QPixmap image,QString xmlname);

    int mainshow(QString filename);
    QPixmap pix;
    QImage image;
    QPixmap result;
    QFileInfo fileInfo;
   QPainter painter;
bool startflag=NULL;
    bool isPressed;     //鼠标是否按下
    qreal num; //缩放比例
    QString imagename;
    QString xmlname;
signals:

public slots:
    void on_ZoomIn_clicked();
    void on_ZoomOut_clicked();
};

#endif // SHOWVIEW_H

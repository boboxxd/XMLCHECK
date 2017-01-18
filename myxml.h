#ifndef MYXML_H
#define MYXML_H
#include<QPoint>
#include <QtXml>
#include<QFile>
#include<QDebug>
#include<QPaintDevice>
#include<QPainter>
#include<QPaintEngine>
//#include "myxml_global.h"

struct MyRect
{
    QString name;
    QPoint start;
    QPoint end;
    int width;
    int height;
};

class INFO
{
public:
    QString m_author;
    QString m_date;
public:
    INFO()
    {
        m_author.clear();
        m_date.clear();
    }
};

class OBJECT
{
public:
    QString m_name;
    QPoint  m_start;
    QPoint  m_end;
public:
    OBJECT()
    {
        m_name.clear();
        m_start.setX(0);
        m_start.setY(0);
        m_end.setX(0);
        m_end.setY(0);
    }
};


class MyXML
{
public:
    int m_count=0;//object total number
    INFO m_info;
    OBJECT m_object[100];
public:
    MyXML();
    MyXML(const char *filename);
    int readxml(const char *filename);//return the Object number
    int writexml(const char * filename);
    void MydrawRect(QPixmap& image, QString name,QPoint start,QPoint end);
};

#endif // MYXML_H





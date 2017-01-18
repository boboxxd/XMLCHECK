#include "myxml.h"


MyXML::MyXML()
{

}

MyXML::MyXML(const char *filename)
{
    readxml(filename);
}



int MyXML::readxml(const char *filename)//return the Object number
{
    int count=0;
    QDomDocument doc;
    QFile in(filename);
    doc.setContent(&in);
    QDomElement root = doc.documentElement();
    QDomNode node = root.firstChild();
    QString name="o";

   while(name !=NULL)
   {
    name=node.toElement().tagName();
//-----------------------------------------------------------------------------------------------------------------------------------------
    if(name =="info")
    {
        int no=node.childNodes().count();
        for(int i=0;i<no;i++)
     {
         if(node.childNodes().at(i).toElement().tagName() =="author")
         {
             m_info.m_author=node.childNodes().at(0).toElement().text();
        }
         if(node.childNodes().at(i).toElement().tagName() =="date")
         {
             m_info.m_date=node.childNodes().at(1).toElement().text();
         }
     }
        qDebug()<<m_info.m_author;
        qDebug()<<m_info.m_date;
    }
//-------------------------------------------------------------------------------------------------------------------------------------";
    if(name == "object")
    {

   int no=node.childNodes().count();
   for(int i=0;i<no;i++)
{
    if(node.childNodes().at(i).toElement().tagName() =="name")

        m_object[count].m_name=node.childNodes().at(0).toElement().text();

    if(node.childNodes().at(i).toElement().tagName() =="bndbox")
    {
        m_object[count].m_start.setX(node.childNodes().at(i).childNodes().at(0).toElement().text().toInt());
        m_object[count].m_start.setY(node.childNodes().at(i).childNodes().at(1).toElement().text().toInt());
        m_object[count].m_end.setX(node.childNodes().at(i).childNodes().at(2).toElement().text().toInt());
        m_object[count].m_end.setY(node.childNodes().at(i).childNodes().at(3).toElement().text().toInt());
    }
}
    count++;
    int temp=count;
    qDebug()<<m_object[temp-1].m_name;
    qDebug()<<m_object[temp-1].m_start;
    qDebug()<<m_object[temp-1].m_end;
    }
 //------------------------------------------------------------------------------------------------------------------------------------------------
    node = node.nextSibling();
}
   m_count=count;
   return count;
}


int MyXML::writexml(const char * filename)
{
    return 0;
}


void MyXML::MydrawRect(QPixmap& image, QString name,QPoint start,QPoint end)
{
    QFont font("Arial",25,QFont::Bold,true);
    QPainter pen(&image);
    pen.setPen(QPen(Qt::red, 4));
    pen.setFont(font);
    int width=end.x()-start.x();
    int height=end.y()-start.y();
    pen.drawRect(start.x(),start.y(),width,height);
    pen.drawText(start.x(),start.y(),name);
}

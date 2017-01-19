#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->openbtn,SIGNAL(clicked(bool)),this,SLOT(onopenBtn()));
    connect(ui->openpathbtn,SIGNAL(clicked(bool)),this,SLOT(onopenpathBtn()));
    connect(ui->beforebtn,SIGNAL(clicked(bool)),this,SLOT(onbeforeBtn()));
    connect(ui->nextbtn,SIGNAL(clicked(bool)),this,SLOT(onnextBtn()));
    connect(ui->sendbtn,SIGNAL(clicked(bool)),this,SLOT(onsendBtn()));

}

Widget::~Widget()
{
    delete ui;
}

int Widget::onopenBtn()
{
    QString filename= QFileDialog::getOpenFileName(this,tr("Open File"),\
                                                    NULL,\
                                                    "Images (*.jpeg *.jpg)",\
                                                    0);
    if(!filename.isNull())
    {
    QFileInfo fileInfo(filename);
    QDir dir(fileInfo.absolutePath());
    QStringList filters;
    filters << "*.jpg" << "*.jpeg" ;
    dir.setNameFilters(filters);
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setSorting(QDir::Name);
    list = dir.entryInfoList();
    index=list.indexOf(fileInfo);//获取文件在目录下的序号
    fileInfo = list.at(index);
    imagename=fileInfo.absoluteFilePath();
    qDebug()<<index<<imagename;
    ui->label->setText(imagename);
    ui->showlabel->imagename=imagename;


    }
    return 0;
}

int Widget::onopenpathBtn()
{
    index=0;
    QString temp=QFileDialog::getExistingDirectory ();
    if(!temp.isNull())
    {
    QDir dir(temp);
    QStringList filters;
    filters << "*.jpg" << "*.jpeg"  ;
    dir.setNameFilters(filters);
    dir.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    dir.setSorting(QDir::Name);
    list = dir.entryInfoList();
    QFileInfo fileInfo;
    fileInfo = list.at(index);
    imagename=fileInfo.absoluteFilePath();
    qDebug()<<index<<imagename;
    ui->label->setText(imagename);
ui->showlabel->imagename=imagename;
    }
    return 0;
}

int Widget::onbeforeBtn()
{
    index--;
   if(index<0)
   {
    index++;
   }
    QFileInfo fileInfo = list.at(index);
    imagename=fileInfo.absoluteFilePath();
    qDebug()<<index<<imagename;
    ui->label->setText(imagename);
    ui->showlabel->imagename=imagename;
    ui->showlabel->update();
    return 0;
}

int Widget::onnextBtn()
{
    index++;
   if(index>=list.count())
   {
    index--;
   }
    QFileInfo fileInfo = list.at(index);
    imagename=fileInfo.absoluteFilePath();
    qDebug()<<index<<imagename;
    ui->label->setText(imagename);
    ui->showlabel->imagename=imagename;
    ui->showlabel->update();
    return 0;
}

int Widget::onsendBtn()
{

    return 0;
}




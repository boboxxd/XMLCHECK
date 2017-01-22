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
    mfileInfo=fileInfo;
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
    xmlname=fileInfo.absolutePath()+"/"+fileInfo.baseName()+".xml";
    qDebug()<<index<<imagename;
    qDebug()<<index<<xmlname;
    ui->label->setText(imagename);
    ui->showlabel->imagename=imagename;
    ui->showlabel->xmlname=xmlname;
ui->showlabel->startflag=true;


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
    mfileInfo=fileInfo;
    imagename=fileInfo.absoluteFilePath();
    xmlname=fileInfo.absolutePath()+"/"+fileInfo.baseName()+".xml";
    qDebug()<<index<<imagename;
    qDebug()<<index<<xmlname;
    ui->label->setText(imagename);
    ui->showlabel->imagename=imagename;
    ui->showlabel->xmlname=xmlname;
    }
    ui->showlabel->startflag=true;
    return 0;
}

int Widget::onbeforeBtn()
{
    if(!ui->showlabel->imagename.isNull())
    {

    index--;
   if(index<0)
   {
    index++;
   }
    QFileInfo fileInfo = list.at(index);
     mfileInfo=fileInfo;
    imagename=fileInfo.absoluteFilePath();
    xmlname=fileInfo.absolutePath()+"/"+fileInfo.baseName()+".xml";
    qDebug()<<index<<imagename;
    qDebug()<<index<<xmlname;
    ui->label->setText(imagename);
    ui->showlabel->imagename=imagename;
    ui->showlabel->xmlname=xmlname;

    ui->showlabel->startflag=true;
    ui->showlabel->update();

    }
    return 0;
}

int Widget::onnextBtn()
{
    if(!ui->showlabel->imagename.isNull())
    {

     ui->showlabel->startflag=true;
    index++;
   if(index>=list.count())
   {
    index--;
   }
    QFileInfo fileInfo = list.at(index);
    mfileInfo=fileInfo;
    imagename=fileInfo.absoluteFilePath();
    xmlname=fileInfo.absolutePath()+"/"+fileInfo.baseName()+".xml";
    qDebug()<<index<<imagename;
    qDebug()<<index<<xmlname;
    ui->label->setText(imagename);
    ui->showlabel->imagename=imagename;
    ui->showlabel->xmlname=xmlname;
    ui->showlabel->startflag=true;
    ui->showlabel->update();

    }
    return 0;
}

int Widget::onsendBtn()
{
    ui->showlabel->startflag=true;
    QDir dir(mfileInfo.absolutePath()+"/error/");
        if(!dir.exists())
        {
           bool ok = dir.mkdir(mfileInfo.absolutePath()+"/error/");//只创建一级子目录，即必须保证上级目录存在
        }
    bool re1,re2;
    re1=QFile::copy(imagename,mfileInfo.absolutePath()+"/error/"+mfileInfo.baseName()+".jpg");
    re2=QFile::copy(xmlname,mfileInfo.absolutePath()+"/error/"+mfileInfo.baseName()+".xml");
    if(re1&re2)
    {
        ui->label->setText(imagename+"    send successful!");
    }
    else
    {
        ui->label->setText(imagename+"    send failed!");
    }
    return 0;
}





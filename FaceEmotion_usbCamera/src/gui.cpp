#include "gui.h"
#include <iostream>

using namespace std;
extern int img_width;  
extern int img_height;

Gui::Gui()
{
    QFont font20;
    font20.setPointSize(15);
    font20.setBold(true);
    base_layout=new QHBoxLayout;
    display_center=new QWidget;
    display_center->setStyleSheet("background:rgb(100,100,100);");
    control_layout=new QVBoxLayout;
    display_center->setLayout(control_layout);
    display_center->setFixedWidth(img_width);
    display_face=new QLabel;
    display_face->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    display_face->setFixedHeight(img_height);
    display_face->setStyleSheet("background:rgb(200,200,200);");
    display_emoji=new QLabel();
    display_emoji->setFont(font20);
    display_emoji->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(170, 160,200);border-radius:20px;");
    display_emoji->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    display_emoji->setMaximumHeight(100);
    display_msg=new QLabel("");
    display_msg->setFont(font20);
    display_msg->setStyleSheet("color: rgb(255, 255, 255);background-color: rgb(170, 160,200);border-radius:20px;");
    display_msg->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    display_msg->setMaximumHeight(100);
    control_layout->addWidget(display_face);
    control_layout->addWidget(display_emoji);
    control_layout->addWidget(display_msg);
    this->setLayout(base_layout);
    base_layout->addWidget(display_center);
    this->resize(1920,1080);
    hint=new QWidget();
    hint->setFont(font20);
    hint_label=new QLabel(hint);
    hint_label->resize(500,500);
    hint_label->setText("");
    hint->setStyleSheet("color:red;background:rgb(255,255,255);");
    hint_label->setAlignment(Qt::AlignCenter);
    sound=new QProcess();
}

Gui::~Gui()
{

}

void Gui::resizeEvent(QResizeEvent *re)
{

}

void Gui::showImage(QImage &img)
{
    display_face->setPixmap(QPixmap::fromImage(img));
}

void Gui::showEmotion(int &emotion_index)
{
    //std::cout<<"emotion_index:"<<emotion_index<<std::endl;
    switch(emotion_index)
    {
      case 0:
      case 1:
      case 2:
      case 4:
      case 5:
      {
         sound->start("ffplay",QStringList()<<"-autoexit"<<"-nodisp"<<"notify.wav");
         display_emoji->setPixmap(QPixmap("emoji/unhappy.png"));
         display_msg->setText("Don't be sad,come and pet me!");
         break;
      }
      case 3:
      {
         sound->start("ffplay",QStringList()<<"-autoexit"<<"-nodisp"<<"notify.wav");
         display_emoji->setPixmap(QPixmap("emoji/happy.png"));
         display_msg->setText("You're happy,so I'm happy too!");
         break;
      }
      case 6:
      {
         display_msg->setText("");
         display_emoji->setPixmap(QPixmap());
         break;
      }
      case 7:
      {
         sound->start("ffplay",QStringList()<<"-autoexit"<<"-nodisp"<<"notify.wav");
         display_emoji->setPixmap(QPixmap(""));
         display_msg->setText("Take a break!");
         break;
      }
    }
}

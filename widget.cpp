#include "widget.h"
#include "ui_widget.h"

#include <iostream>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    estado = false;
    ui->setupUi(this);
    setWindowTitle("Programación Orientada a Objetos");

    this->angle1 = new QSlider(Qt::Horizontal, this);
    connect(angle1, SIGNAL (sliderReleased()),this, SLOT (angle1_changed()));

    this->angle2 = new QSlider(Qt::Horizontal, this);
    connect(angle2, SIGNAL (sliderReleased()),this, SLOT (angle2_changed()));

    this->angle3 = new QSlider(Qt::Horizontal, this);
    connect(angle3, SIGNAL (sliderReleased()),this, SLOT (angle3_changed()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::getRender(BaseRobot *render){
    this->br = render;
}

void Widget::on_ACTIVAR_clicked(){
    ui->estado->setText("ENCENDIDO");
    this->estado=true;
    this->br->turnON();
}

void Widget::on_DESACTIVAR_clicked(){
    ui->estado->setText("APAGADO");
    this->estado=false;
}

void Widget::angle1_changed(){
    std::cout << this->angle1->value() << std::endl;
}

void Widget::angle2_changed(){
    std::cout << this->angle2->value() << std::endl;
}

void Widget::angle3_changed(){
    std::cout << this->angle3->value() << std::endl;
}

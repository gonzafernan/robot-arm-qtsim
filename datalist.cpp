#include "datalist.h"

DataList::DataList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataList)
{
    ui->setupUi(this);
    setWindowTitle("Data");
}

DataList::~DataList(){
    delete ui;
}

void DataList::on_AceptarC_clicked(){
    this->hide();
}

void DataList::on_CancelarC_clicked(){
    this->hide();
}

void DataList::on_angle1_valueChanged(int arg1){
    this->br->externalGdl1(arg1);
}


void DataList::on_angle2_valueChanged(int arg1){
    this->br->externalGdl2(arg1);
}

void DataList::on_angle3_valueChanged(int arg1){
    this->br->externalGdl3(arg1);
}

void DataList::on_v1_valueChanged(double arg1){
    this->br->externalV1(arg1);
}

void DataList::on_v2_valueChanged(double arg1){
    this->br->externalV2(arg1);
}

void DataList::on_v3_valueChanged(double arg1){
    this->br->externalV3(arg1);
}

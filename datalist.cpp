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
    this->br->externalV1(ui->v1->value());
    this->br->externalV2(ui->v2->value());
    this->br->externalV3(ui->v3->value());
    this->br->externalGdl1(ui->angle1->value());
    this->br->externalGdl2(ui->angle2->value());
    this->br->externalGdl3(ui->angle3->value());
    this->hide();
}

void DataList::on_CancelarC_clicked(){
    this->hide();
}

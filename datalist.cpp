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

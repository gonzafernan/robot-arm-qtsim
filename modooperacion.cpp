#include "modooperacion.h"
#include "ui_modooperacion.h"

ModoOperacion::ModoOperacion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ModoOperacion){
    ui->setupUi(this);
    setWindowTitle("Modo de operación");
}

ModoOperacion::~ModoOperacion(){
    delete ui;
}

void ModoOperacion::on_Archivo_clicked(){
    FileManager *file_manager = new FileManager();
    file_manager->show();
}

void ModoOperacion::on_pushButton_clicked(){
    this->hide();
}

void ModoOperacion::on_gdl1_valueChanged(int value){
    this->br->externalGdl1(value);
}

void ModoOperacion::on_gdl2_valueChanged(int value){
    this->br->externalGdl2(value);
}

void ModoOperacion::on_gdl3_valueChanged(int value){
    this->br->externalGdl3(value);
}

void ModoOperacion::on_homing_clicked(){
    this->br->turnON();
}

void ModoOperacion::on_v1_valueChanged(int value){
    this->br->externalV1(static_cast<double>(value/10));
}

void ModoOperacion::on_v2_valueChanged(int value){
    this->br->externalV2(static_cast<double>(value/10));
}

void ModoOperacion::on_v3_valueChanged(int value){
    this->br->externalV3(static_cast<double>(value/10));
}

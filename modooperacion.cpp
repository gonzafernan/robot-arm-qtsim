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

void ModoOperacion::on_execute_clicked(){
    QString comando;
    comando = ui->textEdit->toPlainText();
    //ui->textEdit->setPlainText(comando);
    ui->textEdit->clear();
    this->br->interpreteComando(comando.toStdString());
}

void ModoOperacion::on_gdl1_sliderReleased(){
    this->br->externalGdl1(ui->gdl1->value());
}

void ModoOperacion::on_gdl2_sliderReleased(){
    this->br->externalGdl2(ui->gdl2->value());
}

void ModoOperacion::on_gdl3_sliderReleased(){
    this->br->externalGdl3(ui->gdl3->value());
}

void ModoOperacion::on_v1_sliderReleased(){
    this->br->externalV1(ui->v1->value());
}

void ModoOperacion::on_v2_sliderReleased(){
    this->br->externalV2(ui->v2->value());
}

void ModoOperacion::on_v3_sliderReleased(){
    this->br->externalV3(ui->v3->value());
}

void ModoOperacion::setLastProgram(QString direc){
    this->lastProgram = direc;
}

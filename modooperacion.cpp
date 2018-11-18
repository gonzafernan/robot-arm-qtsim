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

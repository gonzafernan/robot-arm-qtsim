#include "filemanager.h"

FileManager::FileManager(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FileManager){
    ui->setupUi(this);
}

FileManager::~FileManager(){
    delete ui;
}

void FileManager::on_action_Open_File_triggered(){
    QString fileName = QFileDialog::getOpenFileName(
                this,
                "Text Editor Open File",
                "home/",
                "Texts Files (*.txt);;All Files(*.*)");
    if (!fileName.isEmpty()){
        QFile file(fileName);
        if (file.open(QFile::ReadOnly)){
            ui->textEdit->setPlainText(file.readAll());
            ui->textEdit_2->setPlainText(fileName);
            this->Direcc = fileName;
        } else {
            QMessageBox::warning(
                        this,
                        "Text Editor",
                        tr("Cannot read File %1. \nError: %2")
                        .arg(fileName)
                        .arg(file.errorString()));
        }
    }
}

void FileManager::on_AceptarF_clicked(){
    QString fileName = this->Direcc;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(nullptr, "error", file.errorString());
    }
    QTextStream in(&file);
    this->program = in.readAll();
    this->br->loadProgram(this->Direcc);
    this->hide();
}

void FileManager::on_CancelarF_clicked(){
    this->hide();
}

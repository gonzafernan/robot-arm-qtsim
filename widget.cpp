#include "widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    estado = false;
    ui->setupUi(this);
    setWindowTitle("Programación Orientada a Objetos");

    // Reporte de estado de la máquina
    timer = new QTimer(this);
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(report()));
    timer->start(1000);
}

Widget::~Widget(){
    delete ui;
}

void Widget::on_ACTIVAR_clicked(){
    ui->estado->setText("ENCENDIDO");
    this->estado=true;
    this->br->turnON();
}

void Widget::on_DESACTIVAR_clicked(){
    ui->estado->setText("APAGADO");
    this->estado=false;
    this->br->turnOFF();
}

void Widget::on_selectMode_clicked(){
    ModoOperacion *mode = new ModoOperacion();
    mode->setData(this->br);
    mode->show();
    std::cout << "Select mode" << std::endl;
}

void Widget::on_Archivos_clicked(){
    FileManager *file_manager = new FileManager();
    file_manager->setData(this->br);
    file_manager->show();
    std::cout << "Select file" << std::endl;
}

void Widget::on_EXIT_clicked(){
    this->hide();
}

void Widget::on_Data_clicked(){
    DataList *data = new DataList();
    data->setData(this->br);
    data->show();
    std::cout << "List data" << std::endl;
}

void Widget::report(){
    ui->report->setPlainText(this->br->toQString());
}

void Widget::on_askEstado_clicked(){
    QString data;
    QString estado;
    data += ("Estado del robot: " + this->br->getEstado() + "\n");
    data += ("Tarea configurada en efector final: " + this->br->get_efTarea() + "\n");
    data += ("Duración: " + this->br->get_efDuracion() + "\n");
    this->ui->estadoInfo->setPlainText(data);
}

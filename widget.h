#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSlider>
#include <iostream>

#include "ui_widget.h"

#include "baserobot.h"
#include "modooperacion.h"
#include "filemanager.h"
#include "datalist.h"
#include "conjuntointerfaz.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget, public ConjuntoInterfaz {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void on_ACTIVAR_clicked();
    void on_DESACTIVAR_clicked();

private slots:
    void on_gdl1_valueChanged(int value);
    void on_gdl2_valueChanged(int value);
    void on_gdl3_valueChanged(int value);

    void on_selectMode_clicked();

    void on_Archivos_clicked();

    void on_EXIT_clicked();

    void on_Data_clicked();

private:
    Ui::Widget *ui;
    bool estado;
};

#endif // WIDGET_H

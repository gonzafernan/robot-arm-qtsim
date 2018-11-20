#ifndef MODOOPERACION_H
#define MODOOPERACION_H

#include <QWidget>

#include "filemanager.h"
#include "conjuntointerfaz.h"

namespace Ui {
    class ModoOperacion;
}

class ModoOperacion : public QWidget, public ConjuntoInterfaz {

    Q_OBJECT

    public:
        explicit ModoOperacion(QWidget *parent = nullptr);
        ~ModoOperacion();

    public slots:
        void on_Archivo_clicked();
        void on_pushButton_clicked();

private slots:
        void on_gdl1_valueChanged(int value);

        void on_gdl2_valueChanged(int value);

        void on_gdl3_valueChanged(int value);

        void on_homing_clicked();

        void on_v1_valueChanged(int value);

        void on_v2_valueChanged(int value);

        void on_v3_valueChanged(int value);

        void on_execute_clicked();

private:
        Ui::ModoOperacion *ui;
};

#endif // MODOOPERACION_H

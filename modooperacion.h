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
        void on_execute_clicked();

        void on_gdl1_sliderReleased();
        void on_gdl2_sliderReleased();
        void on_gdl3_sliderReleased();

        void on_v1_sliderReleased();
        void on_v2_sliderReleased();
        void on_v3_sliderReleased();

        void on_homing_clicked();

        void on_pushButton_3_clicked();

private:
        Ui::ModoOperacion *ui;
        FileManager *file_manager;


};

#endif // MODOOPERACION_H

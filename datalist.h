#ifndef DATALIST_H
#define DATALIST_H

#include <QWidget>

#include "ui_datalist.h"
#include "conjuntointerfaz.h"

namespace Ui {
    class DataList;
}

class DataList : public QWidget, public ConjuntoInterfaz {

    Q_OBJECT

    public:
        explicit DataList(QWidget *parent = nullptr);
        ~DataList();

    private slots:
        void on_AceptarC_clicked();
        void on_CancelarC_clicked();

        void on_angle1_valueChanged(int arg1);
        void on_angle2_valueChanged(int arg1);
        void on_angle3_valueChanged(int arg1);

        void on_v1_valueChanged(double arg1);
        void on_v2_valueChanged(double arg1);
        void on_v3_valueChanged(double arg1);

    private:
        Ui::DataList *ui;
};

#endif // DATALIST_H

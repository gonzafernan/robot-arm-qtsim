#ifndef DATALIST_H
#define DATALIST_H

#include <QWidget>

#include "ui_datalist.h"

namespace Ui {
    class DataList;
}

class DataList : public QWidget {

    Q_OBJECT

    public:
        explicit DataList(QWidget *parent = nullptr);
        ~DataList();

    private slots:
        void on_AceptarC_clicked();
        void on_CancelarC_clicked();

    private:
        Ui::DataList *ui;
};

#endif // DATALIST_H

#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSlider>

#include "baserobot.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void getRender(BaseRobot *render);

public slots:
    void on_ACTIVAR_clicked();
    void on_DESACTIVAR_clicked();

private slots:
    void on_gdl1_valueChanged(int value);
    void on_gdl2_valueChanged(int value);
    void on_gdl3_valueChanged(int value);

private:
    Ui::Widget *ui;
    bool estado;

    BaseRobot *br;
};

#endif // WIDGET_H

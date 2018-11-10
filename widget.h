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
    void angle1_changed();
    void angle2_changed();
    void angle3_changed();

private:
    Ui::Widget *ui;
    bool estado;

    BaseRobot *br;

    QSlider *angle1;
    QSlider *angle2;
    QSlider *angle3;
};

#endif // WIDGET_H

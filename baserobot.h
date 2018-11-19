#ifndef BASEROBOT_H
#define BASEROBOT_H

#include <QObject>

#include <QtCore/QObject>

#include <Qt3DCore/QEntity>
#include <Qt3DCore/qentity.h>
#include <Qt3DRender/qcamera.h>
#include <Qt3DRender/qcameralens.h>

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtGui/QScreen>

#include <Qt3DInput/QInputAspect>

#include <Qt3DRender/qpointlight.h>

#include <Qt3DCore/qtransform.h>

#include <Qt3DExtras/qforwardrenderer.h>

#include <Qt3DExtras/qt3dwindow.h>
#include <Qt3DExtras/qorbitcameracontroller.h>

#include <QParallelAnimationGroup>

#include <QSound>

#include <iostream>

#include "m_function.h"
#include "elemento.h"

#define PIEZA3_LONG 7.3

class BaseRobot : public QObject {

    public:
        BaseRobot();
        ~BaseRobot();
        Qt3DCore::QEntity *init();

        void turnON();
        void turnOFF();

        void gdl1Changed(int value);
        void gdl2Changed(int value);
        void gdl3Changed(int value);

        void externalGdl1(int value);
        void externalGdl2(int value);
        void externalGdl3(int value);

        void externalV1(double value);
        void externalV2(double value);
        void externalV3(double value);

    public slots:
        void endReceiver();

    private:
        Elemento *p1;
        Elemento *p2;
        Elemento *p3;
        Elemento *p4;
        Elemento *ef;

        QParallelAnimationGroup *currentAnimation = nullptr;

        enum estado{INACTIVE, ACTIVE, RUNNING} estado = INACTIVE;
};

#endif // BASEROBOT_H

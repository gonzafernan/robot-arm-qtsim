#ifndef BASEROBOT_H
#define BASEROBOT_H

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

#include "elemento.h"

class BaseRobot {
    public:
        BaseRobot();
        virtual ~BaseRobot();
        Qt3DCore::QEntity *init();

        void turnON();

    private:
        Elemento *p1;
        Elemento *p2;
        Elemento *p3;
        Elemento *p4;
        Elemento *ef;
};

#endif // BASEROBOT_H

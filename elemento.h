#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <QUrl>
#include <QtCore/QObject>
#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>
#include <Qt3DRender/QMesh>
#include <Qt3DExtras/QPhongMaterial>

#include <QPropertyAnimation>

#include "controller.h"

class Elemento : public QObject {

    Q_OBJECT

    public:
        Elemento();
        explicit Elemento(Qt3DCore::QEntity *rootEntity, QUrl url);
        ~Elemento();

        QPropertyAnimation *animate(int start, int end, int duration); // Analizar grados de inicio y final como float
        // Duración en milisegundos!

        void setAxis(QVector3D naxis);
        QVector3D getAxis();
        void setPoint(QVector3D npoint);
        QVector3D getPoint();

        int getAngle();
        int getPrevious_angle();
        void setAngle(int value);
        void setPrevious_angle(int value);

        float getCurrentAngle();

        Controller *controller;

    private:
        Qt3DCore::QEntity *m_rootEntity;

        Qt3DCore::QEntity *entity;
        Qt3DRender::QMesh *mesh;
        Qt3DCore::QTransform *transform;
        Qt3DExtras::QPhongMaterial *material;
        QPropertyAnimation *animation;

        void update(Qt3DCore::QEntity *root_entity);

        int angle = 0;
        int previous_angle = 0;
};

#endif // SCENEMODIFIER_H

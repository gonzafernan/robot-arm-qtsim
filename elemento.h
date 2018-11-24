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
#include "m_function.h"

class Elemento : public QObject {

    Q_OBJECT

    public:
        Elemento();
        explicit Elemento(Qt3DCore::QEntity *rootEntity, QUrl url);
        ~Elemento();

        QPropertyAnimation *animate(int start, int end, int duration, int n); // Analizar grados de inicio y final como float
        // Duración en milisegundos!

        void setAxis(int n, QVector3D naxis);
        QVector3D getAxis(int n);
        void setPoint(int n, QVector3D npoint);
        QVector3D getPoint(int n);

        int getAngle(int n);
        int getPrevious_angle(int n);
        void setAngle(int n, int value);

        float getCurrentAngle(int n);

        double getVel();
        void setVel(double value);

        int getDuration();

        Controller *cont[3];

    private:
        Qt3DCore::QEntity *m_rootEntity;

        Qt3DCore::QEntity *entity;
        Qt3DRender::QMesh *mesh;
        Qt3DCore::QTransform *transform;
        Qt3DExtras::QPhongMaterial *material;
        QPropertyAnimation *animation;

        void update(Qt3DCore::QEntity *root_entity);

        int angle[3] = {0, 0, 0};
        int previous_angle[3] = {0, 0, 0};

        QVector3D axis[3] = {QVector3D(0, 0, 0), QVector3D(0, 0, 0), QVector3D(0, 0, 0)};
        QVector3D previous_axis[3] = {QVector3D(0, 0, 0), QVector3D(0, 0, 0), QVector3D(0, 0, 0)};

        QVector3D point[3] = {QVector3D(0, 0, 0), QVector3D(0, 0, 0), QVector3D(0, 0, 0)};
        QVector3D previous_point[3] = {QVector3D(0, 0, 0), QVector3D(0, 0, 0), QVector3D(0, 0, 0)};

        // Atributos asociados a la animación
        double vel = 0;
        int duration = 0;
};

#endif // SCENEMODIFIER_H

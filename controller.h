#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QMatrix4x4>
#include <Qt3DCore/qtransform.h>
#include <QTransform>

#include <Qt3DCore/qentity.h>
#include <Qt3DRender/QMesh>
#include <Qt3DExtras/QPhongMaterial>
#include <QPropertyAnimation>

#include <iostream>

QT_BEGIN_NAMESPACE

namespace Qt3DCore {
    class QTransform;
}

class Controller : public QObject {

    Q_OBJECT
    Q_PROPERTY(Qt3DCore::QTransform* target READ target WRITE setTarget NOTIFY targetChanged)
    Q_PROPERTY(float angle READ angle WRITE setAngle NOTIFY angleChanged)

    public:
        Controller();
        Controller(QObject *parent = nullptr);

        void setTarget(Qt3DCore::QTransform *target);
        Qt3DCore::QTransform *target() const;

        void setAngle(float angle);

        float angle() const;

        void setAxis(QVector3D naxis);
        void setPoint(QVector3D npoint);

        QVector3D getAxis();
        QVector3D getPoint();

    signals:
        void targetChanged();
        void angleChanged();

    protected:
        void updateMatrix();

    private:
        Qt3DCore::QTransform *m_target;
        QMatrix4x4 m_matrix;
        float m_angle;

        // Parámetros del sistema de referencia para la rotación
        QVector3D axis;
        QVector3D point;
};

QT_END_NAMESPACE

#endif // CONTROLLER_H

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

        /*
         * Sobrecarga de métodos debido a un determinado error,
         * analizar más adelante el motivo de ésto.
         */
        void setAngle(float angle);
        void setAngle(int n, float angle);

        float angle() const;
        float angle(int n);

        void setAxis(QVector3D naxis);
        void setAxis(int n, QVector3D naxis);
        void setPoint(QVector3D npoint);
        void setPoint(int n, QVector3D npoint);

        QVector3D getAxis();
        QVector3D getAxis(int n);
        QVector3D getPoint();
        QVector3D getPoint(int n);

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

        float previousAngle[3];
        QVector3D previousAxis[3];
        QVector3D previousPoint[3];
};

QT_END_NAMESPACE

#endif // CONTROLLER_H

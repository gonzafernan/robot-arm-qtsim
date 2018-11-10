#ifndef PIEZA_H
#define PIEZA_H

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

class Pieza : public QObject {

    Q_OBJECT
    Q_PROPERTY(Qt3DCore::QTransform* target READ target WRITE setTarget NOTIFY targetChanged)
    Q_PROPERTY(float angle READ angle WRITE setAngle NOTIFY angleChanged)

    public:
        Pieza();
        Pieza(QObject *parent = nullptr);

        void setTarget(Qt3DCore::QTransform *target);
        Qt3DCore::QTransform *target() const;

        void setAngle(float angle);
        float angle() const;

        Qt3DCore::QEntity *entity;
        Qt3DRender::QMesh *mesh;
        Qt3DCore::QTransform *transform;
        Qt3DExtras::QPhongMaterial *material;
        QPropertyAnimation *animation;

        void update(Qt3DCore::QEntity *root_entity);

    signals:
        void targetChanged();
        void angleChanged();

    protected:
        void updateMatrix();

    private:
        Qt3DCore::QTransform *m_target;
        QMatrix4x4 m_matrix;
        float m_angle;
        QObject *rotateQML;

};

QT_END_NAMESPACE

#endif // PIEZA_H

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

        Qt3DCore::QEntity *entity;
        Qt3DRender::QMesh *mesh;
        Qt3DCore::QTransform *transform;
        Qt3DExtras::QPhongMaterial *material;
        QPropertyAnimation *animation;
        Controller *controller;

    private:
        Qt3DCore::QEntity *m_rootEntity;
};

#endif // SCENEMODIFIER_H

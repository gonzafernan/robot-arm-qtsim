#ifndef SCENEMODIFIER_H
#define SCENEMODIFIER_H

#include <QUrl>
#include <QtCore/QObject>
#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>
#include <Qt3DRender/QMesh>
#include <Qt3DExtras/QPhongMaterial>

#include <QPropertyAnimation>

#include "pieza.h"

class SceneModifier : public QObject {

    Q_OBJECT

    public:
        SceneModifier();
        explicit SceneModifier(Qt3DCore::QEntity *rootEntity);
        ~SceneModifier();

    private:
        Qt3DCore::QEntity *m_rootEntity;

        Qt3DCore::QEntity *m_pieza1Entity;
        Qt3DCore::QEntity *m_pieza2Entity;
        Qt3DCore::QEntity *m_pieza3Entity;
        Qt3DCore::QEntity *m_pieza4Entity;
        Qt3DCore::QEntity *m_pieza5Entity;

        Pieza *p1;
        Pieza *p2;
        Pieza *p3;
        Pieza *p4;
        Pieza *p5;
};

#endif // SCENEMODIFIER_H

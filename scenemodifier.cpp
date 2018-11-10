#include "scenemodifier.h"

SceneModifier::SceneModifier(Qt3DCore::QEntity *rootEntity)
    : m_rootEntity(rootEntity){

    //-------------------------------------------------------------------------
    // INTENTANDO HACER ALGO DIFERENTE
    /*
    this->p1 = new Pieza(this->p1->transform);
    this->p2 = new Pieza(this->p1->transform);
    this->p3 = new Pieza(this->p1->transform);
    this->p4 = new Pieza(this->p1->transform);
    this->p5 = new Pieza(this->p1->transform);

    this->p1->mesh->setSource(QUrl(QStringLiteral("qrc:/assets/pieza1.obj")));
    this->p2->mesh->setSource(QUrl(QStringLiteral("qrc:/assets/pieza2.obj")));
    this->p3->mesh->setSource(QUrl(QStringLiteral("qrc:/assets/pieza3.obj")));
    this->p4->mesh->setSource(QUrl(QStringLiteral("qrc:/assets/pieza4.obj")));
    this->p5->mesh->setSource(QUrl(QStringLiteral("qrc:/assets/pieza5.obj")));

    this->p1->update(m_rootEntity);
    this->p2->update(m_rootEntity);
    this->p3->update(m_rootEntity);
    this->p4->update(m_rootEntity);
    this->p5->update(m_rootEntity);
    */

    //-------------------------------------------------------------------------

    // Robot mesh data
    // PIEZA 1
    Qt3DRender::QMesh *pieza1_mesh = new Qt3DRender::QMesh();
        pieza1_mesh->setSource(QUrl(QStringLiteral("qrc:/assets/pieza1.obj")));
    // PIEZA 2
    Qt3DRender::QMesh *pieza2_mesh = new Qt3DRender::QMesh();
        pieza2_mesh->setSource(QUrl(QStringLiteral("qrc:/assets/pieza2.obj")));
    // PIEZA 3
    Qt3DRender::QMesh *pieza3_mesh = new Qt3DRender::QMesh();
        pieza3_mesh->setSource(QUrl(QStringLiteral("qrc:/assets/pieza3.obj")));
    // PIEZA 4
    Qt3DRender::QMesh *pieza4_mesh = new Qt3DRender::QMesh();
        pieza4_mesh->setSource(QUrl(QStringLiteral("qrc:/assets/pieza4.obj")));
    // PIEZA 5
    Qt3DRender::QMesh *pieza5_mesh = new Qt3DRender::QMesh();
        pieza5_mesh->setSource(QUrl(QStringLiteral("qrc:/assets/pieza5.obj")));

    // Robot mesh transform
    float global_scale = 1.0f;
    float global_positionX = 0.0f;
    float global_positionY = -10.0f;
    float global_positionZ = 0.0f;
    // PIEZA 1
    Qt3DCore::QTransform *pieza1_transform = new Qt3DCore::QTransform();
    pieza1_transform->setScale(global_scale);
    pieza1_transform->setTranslation(QVector3D(global_positionX, global_positionY, global_positionZ));
    // PIEZA 2
    Qt3DCore::QTransform *pieza2_transform = new Qt3DCore::QTransform();
    pieza2_transform->setScale(global_scale);
    pieza2_transform->setTranslation(QVector3D(global_positionX, global_positionY, global_positionZ));
    // PIEZA 3
    Qt3DCore::QTransform *pieza3_transform = new Qt3DCore::QTransform();
    pieza3_transform->setScale(global_scale);
    pieza3_transform->setTranslation(QVector3D(global_positionX, global_positionY, global_positionZ));
    // PIEZA 4
    Qt3DCore::QTransform *pieza4_transform = new Qt3DCore::QTransform();
    pieza4_transform->setScale(global_scale);
    pieza4_transform->setTranslation(QVector3D(global_positionX, global_positionY, global_positionZ));
    // PIEZA 5
    Qt3DCore::QTransform *pieza5_transform = new Qt3DCore::QTransform();
    pieza5_transform->setScale(global_scale);
    pieza5_transform->setTranslation(QVector3D(global_positionX, global_positionY, global_positionZ));

    // Robot material
    // PIEZA 1
    Qt3DExtras::QPhongMaterial *pieza1_material = new Qt3DExtras::QPhongMaterial();
    pieza1_material->setDiffuse(QColor(QRgb(0xa69929)));
    // PIEZA 2
    Qt3DExtras::QPhongMaterial *pieza2_material = new Qt3DExtras::QPhongMaterial();
    pieza2_material->setDiffuse(QColor(QRgb(0xa69929)));
    // PIEZA 3
    Qt3DExtras::QPhongMaterial *pieza3_material = new Qt3DExtras::QPhongMaterial();
    pieza3_material->setDiffuse(QColor(QRgb(0xa69929)));
    // PIEZA 4
    Qt3DExtras::QPhongMaterial *pieza4_material = new Qt3DExtras::QPhongMaterial();
    pieza4_material->setDiffuse(QColor(QRgb(0xa69929)));
    // PIEZA 5
    Qt3DExtras::QPhongMaterial *pieza5_material = new Qt3DExtras::QPhongMaterial();
    pieza5_material->setDiffuse(QColor(QRgb(0xa69929)));

    // Robot animation
    // PIEZA 1
    Pieza *pieza1_controller = new Pieza(pieza1_transform);
    pieza1_controller->setTarget(pieza1_transform);

    QPropertyAnimation *pieza1_animation = new QPropertyAnimation(pieza1_transform);
    pieza1_animation->setTargetObject(pieza1_controller);
    pieza1_animation->setPropertyName("angle");
    pieza1_animation->setStartValue(QVariant::fromValue(0));
    pieza1_animation->setEndValue(QVariant::fromValue(360));
    pieza1_animation->setDuration(10000);
    pieza1_animation->setLoopCount(-1);
    pieza1_animation->start();


    // PIEZA 2

    // PIEZA 3

    // PIEZA 4

    // PIEZA 5

    // Robot
    // PIEZA 1
    m_pieza1Entity = new Qt3DCore::QEntity(m_rootEntity);
    m_pieza1Entity->addComponent(pieza1_mesh);
    m_pieza1Entity->addComponent(pieza1_material);
    m_pieza1Entity->addComponent(pieza1_transform);
    // PIEZA 2
    m_pieza2Entity = new Qt3DCore::QEntity(m_rootEntity);
    m_pieza2Entity->addComponent(pieza2_mesh);
    m_pieza2Entity->addComponent(pieza2_material);
    m_pieza2Entity->addComponent(pieza2_transform);
    // PIEZA 3
    m_pieza3Entity = new Qt3DCore::QEntity(m_rootEntity);
    m_pieza3Entity->addComponent(pieza3_mesh);
    m_pieza3Entity->addComponent(pieza3_material);
    m_pieza3Entity->addComponent(pieza3_transform);
    // PIEZA 4
    m_pieza4Entity = new Qt3DCore::QEntity(m_rootEntity);
    m_pieza4Entity->addComponent(pieza4_mesh);
    m_pieza4Entity->addComponent(pieza4_material);
    m_pieza4Entity->addComponent(pieza4_transform);
    // PIEZA 5
    m_pieza5Entity = new Qt3DCore::QEntity(m_rootEntity);
    m_pieza5Entity->addComponent(pieza5_mesh);
    m_pieza5Entity->addComponent(pieza5_material);
    m_pieza5Entity->addComponent(pieza5_transform);

}

SceneModifier::~SceneModifier(){
}

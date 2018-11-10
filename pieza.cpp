#include "pieza.h"

QT_BEGIN_NAMESPACE

Pieza::Pieza(){
}

void Pieza::update(Qt3DCore::QEntity *root_entity){
    this->entity = new Qt3DCore::QEntity(root_entity);
    this->entity->addComponent(this->mesh);
    this->entity->addComponent(this->material);
    this->entity->addComponent(this->transform);
}

Pieza::Pieza(QObject *parent) : QObject(parent)
  , m_target(nullptr)
  , m_matrix()
  , m_angle(0.0f){

    this->mesh = new Qt3DRender::QMesh();

    this->transform = new Qt3DCore::QTransform();
    this->transform->setScale(1.0f);
    this->transform->setTranslation(QVector3D(0.0f, 0.0f, 0.0f));

    this->material = new Qt3DExtras::QPhongMaterial();
    this->material->setDiffuse(QColor(QRgb(0xa69929)));
}

void Pieza::setTarget(Qt3DCore::QTransform *target){
    if (m_target != target){
        m_target = target;
        emit targetChanged();
    }
}

Qt3DCore::QTransform *Pieza::target() const {
    return m_target;
}

void Pieza::setAngle(float angle){
    if (!qFuzzyCompare(angle, m_angle)){
        m_angle = angle;
        updateMatrix();
        emit angleChanged();
    }
}

float Pieza::angle() const {
    return m_angle;
}

void Pieza::updateMatrix(){
    float global_positionX = 0.65f;
    //float global_positionY = -10.0f;
    float global_positionZ = 0.01f;
    m_matrix.setToIdentity();
    m_matrix.translate(global_positionX, -10.0f, global_positionZ);
    m_matrix.rotate(m_angle, QVector3D(0.0f, 1.0f, 0.0f));
    m_matrix.translate(-global_positionX, 0.0f, -global_positionZ);
    m_target->setMatrix(m_matrix);
}

QT_END_NAMESPACE

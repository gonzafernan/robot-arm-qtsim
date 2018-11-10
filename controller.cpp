#include "controller.h"

QT_BEGIN_NAMESPACE

Controller::Controller() : QObject() {
}


Controller::Controller(QObject *parent) : QObject(parent)
  , m_target(nullptr)
  , m_matrix()
  , m_angle(0.0f){
}

void Controller::setTarget(Qt3DCore::QTransform *target){
    if (m_target != target){
        m_target = target;
        emit targetChanged();
    }
}

Qt3DCore::QTransform *Controller::target() const {
    return m_target;
}

void Controller::setAngle(float angle){
    if (!qFuzzyCompare(angle, m_angle)){
        m_angle = angle;
        updateMatrix();
        emit angleChanged();
    }
}

float Controller::angle() const {
    return m_angle;
}

void Controller::updateMatrix(){
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

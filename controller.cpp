#include "controller.h"

QT_BEGIN_NAMESPACE

Controller::Controller() : QObject() {
}

Controller::Controller(QObject *parent) : QObject(parent)
  , m_target(nullptr)
  , m_matrix()
  , m_angle(0.0f){
    this->axis = QVector3D(0.0f, 1.0f, 0.0f);
    this->point = QVector3D(0.0f, 0.0f, 0.0f);
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
    m_target->setMatrix(this->target()->rotateAround(QVector3D(0, 0, 0), 90, QVector3D(0, 1, 0)));
    m_target->setMatrix(this->target()->rotateAround(QVector3D(0, 0, 0), 90, QVector3D(0, 1, 0)) * this->target()->rotateAround(this->point, this->m_angle, this->axis));
}

void Controller::setAxis(QVector3D naxis){
    this->axis = naxis;
}

void Controller::setPoint(QVector3D npoint){
    this->point = npoint;
}

QVector3D Controller::getAxis(){
    return this->axis;
}

QVector3D Controller::getPoint(){
    return this->point;
}

QT_END_NAMESPACE

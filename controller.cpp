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

/*
 * Creo que encontré la solución al problema de las rotaciones,
 * hay que premultiplicar por lo cambios previos las matrices 4x4
 */

void Controller::updateMatrix(){
    QMatrix4x4 aux;
    aux.setToIdentity();
    if (this->n != 0){
        aux = this->target()->rotateAround(this->_Point[0], this->_Angle[0], this->_Axis[0])*aux;
    } //else {
    //    aux = this->target()->rotateAround(this->prevPoint[0], this->prevAngle[0], this->prevAxis[0])*aux;
    //}
    if (this->n != 1){
        aux = this->target()->rotateAround(this->_Point[1], this->_Angle[1], this->_Axis[1])*aux;
    } //else {
    //    aux = this->target()->rotateAround(this->prevPoint[1], this->prevAngle[1], this->prevAxis[1])*aux;
    //}
    if (this->n != 2){
        aux = this->target()->rotateAround(this->_Point[2], this->_Angle[2], this->_Axis[2])*aux;
    } //else {
    //    aux = this->target()->rotateAround(this->prevPoint[2], this->prevAngle[2], this->prevAxis[2])*aux;
    //}
    m_target->setMatrix(this->target()->rotateAround(this->point, this->m_angle, this->axis)*aux);
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

#include "baserobot.h"
#include "elemento.h"

#include <iostream>

BaseRobot::BaseRobot(){

}

BaseRobot::~BaseRobot(){

}

Qt3DCore::QEntity *BaseRobot::init(){
    // Root entity
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();
    // Montaje de la escena
    this->p1 = new Elemento(rootEntity, QUrl(QStringLiteral("qrc:/assets/pieza1.obj")));

    this->p2 = new Elemento(rootEntity, QUrl(QStringLiteral("qrc:/assets/pieza2.obj")));
    this->p2->setPoint(QVector3D(0.65f, 0.0f, 0.1f));

    this->p3 = new Elemento(rootEntity, QUrl(QStringLiteral("qrc:/assets/pieza3.obj")));
    this->p3->setPoint(QVector3D(0.65f, 0.0f, 0.1f));

    this->p4 = new Elemento(rootEntity, QUrl(QStringLiteral("qrc:/assets/pieza4.obj")));
    this->p4->setPoint(QVector3D(0.65f, 0.0f, 0.1f));

    this->ef = new Elemento(rootEntity, QUrl(QStringLiteral("qrc:/assets/pieza5.obj")));
    this->ef->setPoint(QVector3D(0.65f, 0.0f, 0.1f));

    return rootEntity;
}

void BaseRobot::turnON(){
    std::cout << "ON" << std::endl;
    this->p2->animate(0, 180, 3000);
    this->p3->animate(0, 180, 3000);
    this->p4->animate(0, 180, 3000);
    this->ef->animate(0, 180, 3000);
}

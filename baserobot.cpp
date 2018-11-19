#include "baserobot.h"
#include "elemento.h"

BaseRobot::BaseRobot() : QObject (){
}

BaseRobot::~BaseRobot(){
}

Qt3DCore::QEntity *BaseRobot::init(){
    // Root entity
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();
    // Montaje de la escena
    this->p1 = new Elemento(rootEntity, QUrl(QStringLiteral("qrc:/assets/pieza1.obj")));
    this->p1->setVel(0.1);

    this->p2 = new Elemento(rootEntity, QUrl(QStringLiteral("qrc:/assets/pieza2.obj")));
    this->p2->setPoint(QVector3D(0.65f, 0.0f, 0.1f));
    this->p2->setVel(0.1);

    this->p3 = new Elemento(rootEntity, QUrl(QStringLiteral("qrc:/assets/pieza3.obj")));
    this->p3->setPoint(QVector3D(0.65f, 0.0f, 0.1f));
    this->p3->setVel(0.1);

    this->p4 = new Elemento(rootEntity, QUrl(QStringLiteral("qrc:/assets/pieza4.obj")));
    this->p4->setPoint(QVector3D(0.65f, 0.0f, 0.1f));
    this->p4->setVel(0.1);

    this->ef = new Elemento(rootEntity, QUrl(QStringLiteral("qrc:/assets/pieza5.obj")));
    this->ef->setPoint(QVector3D(0.65f, 0.0f, 0.1f));
    this->ef->setVel(0.1);

    return rootEntity;
}

void BaseRobot::turnON(){
    std::cout << "ON" << std::endl;
    this->estado = ACTIVE;
    // ROTACIÓN DEL PRIMER GRADO DE LIBERTAD
    QParallelAnimationGroup *homing = new QParallelAnimationGroup;
    //QObject::connect(homing, SIGNAL(finished()), this, SLOT(animationFlag()));
    gdl1Changed(90);

    homing->addAnimation(this->p2->animate(this->p2->getPrevious_angle(), this->p2->getAngle(), this->p2->getDuration()));
    homing->addAnimation(this->p3->animate(this->p3->getPrevious_angle(), this->p3->getAngle(), this->p3->getDuration()));
    homing->addAnimation(this->p4->animate(this->p4->getPrevious_angle(), this->p4->getAngle(), this->p4->getDuration()));
    homing->addAnimation(this->ef->animate(this->ef->getPrevious_angle(), this->ef->getAngle(), this->ef->getDuration()));

    gdl3Changed(90);
    homing->addAnimation(this->p4->animate(this->p4->getPrevious_angle(), this->p4->getAngle(), this->p4->getDuration()));
    homing->addAnimation(this->ef->animate(this->ef->getPrevious_angle(), this->ef->getAngle(), this->ef->getDuration()));
    /*
    // ROTACION DEL SEGUNDO GRADO DE LIBERTAD
    float auxX = m_sin(this->p2->controller->angle());
    float auxY = 0.0f;
    float auxZ = m_cos(this->p2->controller->angle());
    this->p3->setAxis(QVector3D(auxX, auxY, auxZ));
    auxX = this->p1->getPoint().x() + 2.35 * m_cos(this->p2->getAngle());
    auxY = this->p1->getPoint().y() - 0.9;
    auxZ = this->p1->getPoint().z() - 0.1 - 2.35 * m_sin(this->p2->getAngle());
    this->p3->setPoint(QVector3D(auxX, auxY, auxZ));
    //this->p3->setPoint(QVector3D(this->))
    this->p3->setPrevious_angle(this->p3->getAngle());
    this->p3->setAngle(this->p3->getPrevious_angle() + 180);
    this->p3->animate(this->p3->getPrevious_angle(), this->p3->getAngle(), 3000);
    */
    // Alarma
    QSound::play(QStringLiteral("qrc:/assets/sound.wav"));
    this->currentAnimation = homing;
    connect(homing, &QParallelAnimationGroup::finished, this, &BaseRobot::endReceiver);
    homing->start();
    this->estado = RUNNING;
}

void BaseRobot::turnOFF(){
    this->currentAnimation->stop();
    this->estado = INACTIVE;
}

void BaseRobot::gdl1Changed(int value){
    std::cout << "GDL1: " << value << std::endl;

    this->p2->setAxis(QVector3D(0, 1, 0));
    this->p3->setAxis(QVector3D(0, 1, 0));
    this->p4->setAxis(QVector3D(0, 1, 0));
    this->ef->setAxis(QVector3D(0, 1, 0));

    this->p2->setPoint(QVector3D(0.65f, 0.0f, 0.1f));
    this->p3->setPoint(QVector3D(0.65f, 0.0f, 0.1f));
    this->p4->setPoint(QVector3D(0.65f, 0.0f, 0.1f));
    this->ef->setPoint(QVector3D(0.65f, 0.0f, 0.1f));

    this->p2->setPrevious_angle(this->p1->getAngle());
    this->p3->setPrevious_angle(this->p1->getAngle());
    this->p4->setPrevious_angle(this->p1->getAngle());
    this->ef->setPrevious_angle(this->p1->getAngle());

    this->p2->setAngle(value);
    this->p3->setAngle(value);
    this->p4->setAngle(value);
    this->ef->setAngle(value);
}

void BaseRobot::gdl2Changed(int value){
    std::cout << "GDL2: " << value << std::endl;
}

void BaseRobot::gdl3Changed(int value){
    std::cout << "GDL3: " << value << std::endl;
    // El casteo de las siguientes lineas debe corregirse
    double aux = - PIEZA3_LONG * m_sin(this->p3->getAngle());
    float auxX = static_cast<float>(this->p1->getPoint().x()) + 2.0f * static_cast<float>(m_cos(this->p2->getAngle()));
    float auxY = static_cast<float>(this->p1->getPoint().y()) + static_cast<float>(PIEZA3_LONG * m_cos(this->p3->getAngle())) + 10.0f - 1.0f;
    float auxZ = static_cast<float>(this->p1->getPoint().z()) - 0.1f - 2.35f * static_cast<float>(m_sin(this->p2->getAngle()) - aux * m_sin(this->p2->getAngle()));

    this->p4->setAxis(QVector3D(static_cast<float>(m_sin(this->p2->getAngle())), 0, static_cast<float>(m_cos(this->p2->getAngle()))));
    this->p4->setPoint(QVector3D(auxX, auxY, auxZ));

    this->p4->setPrevious_angle(this->p4->getAngle());
    this->p4->setAngle(value);

    this->ef->setAxis(QVector3D(static_cast<float>(m_sin(this->p2->getAngle())), 0, static_cast<float>(m_cos(this->p2->getAngle()))));
    this->ef->setPoint(QVector3D(auxX, auxY, auxZ));

    this->ef->setPrevious_angle(this->ef->getAngle());
    this->ef->setAngle(value);
}

void BaseRobot::externalGdl1(int value){
    QParallelAnimationGroup *motion = new QParallelAnimationGroup;
    this->gdl1Changed(value);

    motion->addAnimation(this->p2->animate(this->p2->getPrevious_angle(), this->p2->getAngle(), this->p2->getDuration()));
    motion->addAnimation(this->p3->animate(this->p3->getPrevious_angle(), this->p3->getAngle(), this->p3->getDuration()));
    motion->addAnimation(this->p4->animate(this->p4->getPrevious_angle(), this->p4->getAngle(), this->p4->getDuration()));
    motion->addAnimation(this->ef->animate(this->ef->getPrevious_angle(), this->ef->getAngle(), this->ef->getDuration()));

    this->currentAnimation = motion;
    connect(motion, &QParallelAnimationGroup::finished, this, &BaseRobot::endReceiver);
    motion->start();
    this->estado = RUNNING;
}

void BaseRobot::externalGdl2(int value){
    std::cout << "CAN'T" << value << std::endl;
}

void BaseRobot::externalGdl3(int value){
    QParallelAnimationGroup *motion = new QParallelAnimationGroup;

    this->gdl3Changed(value);

    motion->addAnimation(this->p4->animate(this->p4->getPrevious_angle(), this->p4->getAngle(), this->p4->getDuration()));
    motion->addAnimation(this->ef->animate(this->ef->getPrevious_angle(), this->ef->getAngle(), this->ef->getDuration()));

    this->currentAnimation = motion;
    connect(motion, &QParallelAnimationGroup::finished, this, &BaseRobot::endReceiver);
    motion->start();
    this->estado = RUNNING;
}

void BaseRobot::externalV1(double value){
    std::cout << "V1: " << value/10 << std::endl;
    this->p2->setVel(value);
}

void BaseRobot::externalV2(double value){
    std::cout << "V2: " << value/10 << std::endl;
    this->p3->setVel(value);
}

void BaseRobot::externalV3(double value){
    std::cout << "V3: " << value/10 << std::endl;
    this->p4->setVel(value);
    this->ef->setVel(value);
}

void BaseRobot::endReceiver(){
    std::cout << "END" << std::endl;
    this->estado = ACTIVE;
}

#include "elemento.h"

Elemento::Elemento(Qt3DCore::QEntity *rootEntity, QUrl url)
    : m_rootEntity(rootEntity){

    this->mesh = new Qt3DRender::QMesh();
    this->mesh->setSource(url);

    float global_scale = 1.0f;
    float global_positionX = 0.0f;
    float global_positionY = -10.0f;
    float global_positionZ = 0.0f;

    this->transform = new Qt3DCore::QTransform();
    this->transform->setScale(global_scale);
    this->transform->setTranslation(QVector3D(global_positionX, global_positionY, global_positionZ));

    this->material = new Qt3DExtras::QPhongMaterial();
    this->material->setDiffuse(QColor(QRgb(0xa69929)));

    this->controller = new Controller(this->transform);
    this->controller->setTarget(this->transform);

    this->animation = new QPropertyAnimation(this->transform);
    this->animation->setTargetObject(this->controller);

    update(m_rootEntity);
}

Elemento::~Elemento(){
}

void Elemento::update(Qt3DCore::QEntity *root_entity){
    this->entity = new Qt3DCore::QEntity(root_entity);
    this->entity->addComponent(this->mesh);
    this->entity->addComponent(this->material);
    this->entity->addComponent(this->transform);
}

QPropertyAnimation *Elemento::animate(int start, int end, int duration){
    this->animation->setPropertyName("angle");
    this->animation->setStartValue(QVariant::fromValue(start));
    this->animation->setEndValue(QVariant::fromValue(end));
    this->animation->setDuration(duration);
    this->animation->setLoopCount(1);
    return this->animation;
}

void Elemento::setAxis(QVector3D naxis){
    this->controller->setAxis(naxis);
}

void Elemento::setPoint(QVector3D npoint){
    this->controller->setPoint(npoint);
}

QVector3D Elemento::getAxis(){
    return this->controller->getAxis();
}

QVector3D Elemento::getPoint(){
    return this->controller->getPoint();
}

int Elemento::getAngle(){
    return this->angle;
}

int Elemento::getPrevious_angle(){
    return this->previous_angle;
}

void Elemento::setAngle(int value){
    this->previous_angle = this->angle;
    this->angle = value;
    if (this->vel > 0){
        this->duration = static_cast<int>((this->angle - this->previous_angle)*1000*(M_PI/180)/this->vel);
    } else {
        this->duration = static_cast<int>(INFINITY);
    }
}

float Elemento::getCurrentAngle(){
    return this->controller->angle();
}

double Elemento::getVel(){
    return this->vel;
}

void Elemento::setVel(double value){
    this->vel = value;
}

int Elemento::getDuration(){
    return this->duration;
}

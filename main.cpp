#include <QGuiApplication>

#include "baserobot.h"
#include "widget.h"

int main(int argc, char **argv){
    QApplication app(argc, argv);

    BaseRobot *br = new BaseRobot();
    Qt3DCore::QEntity *scene = br->init();

    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));
    QWidget *container = QWidget::createWindowContainer(view);
    QSize screenSize = view->screen()->size();
    container->setMinimumSize(QSize(200, 100)); // Darle un mínimo
    container->setMaximumSize(screenSize);

    QWidget *widget = new QWidget;

    // Por ahora el Layout no hace falta, pero puede servir
    // cuando se una esto con la interfaz.

    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    //QVBoxLayout *vLayout = new QVBoxLayout();
    hLayout->addWidget(container, 1);
    //hLayout->addLayout(vLayout);

    widget->setWindowTitle(QStringLiteral("Mitsubishi RV-2AJ"));

    Qt3DInput::QInputAspect *input = new Qt3DInput::QInputAspect;
    view->registerAspect(input);

    // Camera
    Qt3DRender::QCamera *cameraEntity = view->camera();

    // REVISAR LA CONFIGURACION DE LA CAMARA!!
    cameraEntity->lens()->setPerspectiveProjection(75.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(0.0f, 0.0f, 20.0f));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));

    // REVISAR LA CONFIGURACION DE LA LUZ!!
    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(scene);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(1);
    lightEntity->addComponent(light);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(cameraEntity->position());
    lightEntity->addComponent(lightTransform);

    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(scene);
    camController->setLinearSpeed( 50.0f );
    camController->setLookSpeed( 180.0f );
    camController->setCamera(cameraEntity);

    // Set root object of the scene
    view->setRootEntity(scene);

    widget->show();
    widget->resize(1200, 800);

    Widget *w = new Widget();
    w->setData(br);
    w->show();


    return app.exec();
}

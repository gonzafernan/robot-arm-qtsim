#include "createscene.h"
#include "scenemodifier.h"

Qt3DCore::QEntity *createScene(){
    // Root entity
    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();
    // Montaje de la escena
    SceneModifier *modifier = new SceneModifier(rootEntity);

    return rootEntity;
}

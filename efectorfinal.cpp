#include "efectorfinal.h"

EfectorFinal::EfectorFinal(Qt3DCore::QEntity *rootEntity, QUrl url) : Elemento(rootEntity, url){
}

EfectorFinal::~EfectorFinal(){
}

void EfectorFinal::work(){
    for (int i=0; i<this->duration; i++){
        std::cout << this->tarea << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void EfectorFinal::setTarea(enum tarea tarea){
    this->tarea = tarea;
}

void EfectorFinal::setDuration(int value){
    this->duration = value;
}

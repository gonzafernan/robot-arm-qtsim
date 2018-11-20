#ifndef EFECTORFINAL_H
#define EFECTORFINAL_H

#include <chrono>
#include <thread>
#include <iostream>

#include "elemento.h"

enum tarea {PINTAR, SOSTENER, SOLTAR, ROTAR};

class EfectorFinal : public Elemento {
    public:
        explicit EfectorFinal(Qt3DCore::QEntity *rootEntity, QUrl url);
        virtual ~EfectorFinal();

        void work();

        QString getTarea();
        void setTarea(enum tarea tarea);
        int getDuracion();
        void setDuration(int value);

    private:
        enum tarea tarea = ROTAR;
        int duration = 0;

};

#endif // EFECTORFINAL_H

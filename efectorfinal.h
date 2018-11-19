#ifndef EFECTORFINAL_H
#define EFECTORFINAL_H

#include "elemento.h"

class EfectorFinal : public Elemento {
    public:
        explicit EfectorFinal(Qt3DCore::QEntity *rootEntity, QUrl url);
        virtual ~EfectorFinal();

};

#endif // EFECTORFINAL_H

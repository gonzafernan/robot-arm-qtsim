#ifndef EFECTORFINAL_H
#define EFECTORFINAL_H

#include "elemento.h"

class EfectorFinal : public Elemento {
    public:
        EfectorFinal();
        explicit EfectorFinal(Qt3DCore::QEntity *rootEntity, QUrl url);

};

#endif // EFECTORFINAL_H

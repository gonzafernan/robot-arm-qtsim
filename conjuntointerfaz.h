#ifndef CONJUNTOINTERFAZ_H
#define CONJUNTOINTERFAZ_H

#include "baserobot.h"

class ConjuntoInterfaz {
    public:
        ConjuntoInterfaz();
        virtual ~ConjuntoInterfaz();

        void setData(BaseRobot *data);

    protected:
        BaseRobot *br;
};

#endif // CONJUNTOINTERFAZ_H

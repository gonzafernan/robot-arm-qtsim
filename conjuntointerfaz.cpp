#include "conjuntointerfaz.h"

ConjuntoInterfaz::ConjuntoInterfaz(){
}

ConjuntoInterfaz::~ConjuntoInterfaz(){
}

void ConjuntoInterfaz::setData(BaseRobot *data){
    this->br = data;
}

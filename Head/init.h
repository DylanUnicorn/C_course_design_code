#ifndef _INIT_H_
#define _INIT_H_

#include "database.h"
void InitStructure(INSTRUMENT* pi, struct CONTROL* pcontrol, AIR* pair, PLAN* pplan,CAR* pcar);
void InitMileAge(INSTRUMENT* pi);

#endif
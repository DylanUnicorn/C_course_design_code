#ifndef _CARSITU_H_
#define _CARSITU_H_

#include "air.h"
#include "setting.h"
#include "public.h"

void car_page(int* page_index,AIR *pair,INSTRUMENT* pi,int* ischange);
void banshou_icon(int x, int y);
void gantanhao(int x, int y,int mycolor);
void back_icon(void);
void setting_page(int *page_index,AIR *pair, INSTRUMENT* pi, int* ischange);
void clock_page(int* page_index, AIR* pair, INSTRUMENT* pi, int* ischange);
void air_page(int* page_index, AIR* pair, INSTRUMENT* pi, int *ischange);
void light_setting_page(int* page_index, AIR* pair,INSTRUMENT* pi,int *ischange);
void RearviewMirror_setting_page(int* page_index, AIR* pair, INSTRUMENT* pi, int *ischange);
void VehicleLock_setting_page(int* page_index, AIR* pair, INSTRUMENT* pi, int *ischange);
void Wiper_setting_page(int* page_index, AIR* pair, INSTRUMENT* pi, int *ischange);


#endif // !_CARSITU_H_

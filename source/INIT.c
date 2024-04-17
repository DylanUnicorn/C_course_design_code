/*
	初始化各结构体还有仪表
*/

#include "init.h"
#include "public.h"

/*
		lineto(pi->RVmirror.positionx[0] = x - 18, pi->RVmirror.positiony[0]= y - 31 + 17 * alpha);
		lineto(pi->RVmirror.positionx[1] = x - 99, pi->RVmirror.positiony[1]=y - 31 + 41 * alpha);
		lineto(pi->RVmirror.positionx[2] = x - 111,pi->RVmirror.positiony[2]= y + 15 + 70 * alpha - 10 * alpha * alpha);
		lineto(pi->RVmirror.positionx[3] = x - 82, pi->RVmirror.positiony[3]= y + 48 + 35 * alpha);
		lineto(pi->RVmirror.positionx[4] = x - 10, pi->RVmirror.positiony[4] =y + 48 + 36*alpha -11*alpha*alpha);

*/
/*

	moveto(493, 189);  
	lineto(513,159);
	lineto(594, 159);
	lineto(607, 203);
	lineto(576, 239);
	lineto(505, 239);
	lineto(493, 215);

*/

void InitStructure(INSTRUMENT* pi, struct CONTROL* pcontrol,AIR* pair,PLAN* pplan, CAR* pcar)
{
	INSTRUMENT initinstr = { 0,0,200,25,{0},{0,{0},{0}},{{0}},
		{{RVxL - 18,RVxL - 99,RVxL - 111,RVxL - 82,RVxL - 10,RVxR + 20,RVxR + 101,RVxR + 114,RVxR + 83,RVxR + 12},
		{ RVyL - 31,RVyL - 31,RVyL + 15, RVyL + 48,RVyL + 48,RVyL - 30,RVyL - 30, RVyL + 14,RVyL + 50,RVyL + 50 },
		0,{0}},{0,{0},{0},{0}} ,{{0},0,0,{0}} };
	AIR initair = { {25,25,25},1,0,1,1,0,0 };
	PLAN plan = { 0,0,0,0,0,0 };
	CAR mycar = { 0,0,0,0,0,0,0 };
	struct CONTROL initcontrol = { 0,0,0 };
 
	*pcar = mycar;
	*pi = initinstr;
	*pcontrol = initcontrol;
	*pair = initair;
;	InitMileAge(pi);
}

void InitMileAge(INSTRUMENT* pi)
{
	//pi->mileage += pi->speed;
	pi->mileage = 0 ;
}
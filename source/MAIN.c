#include "public.h"
#include <weagraph.h>
#include <entern.h>
#include <carsitu.h>
#include "2Dmap.h"
#include "Navigation.h"
#include <init.h>

int main() 
{
	int gd = VGA, gm = VGAHI;
	int page_index = 2;
	int stage = 0;
	int x = 0, y = 0;
	int ischange=0;
	AIR air;
	INSTRUMENT instrument;
	PLAN plan;
	CAR car;
	struct CONTROL control;

	initgraph(&gd, &gm, "C:\\BORLANDC\\BGI");

	InitStructure( &instrument, &control, & air,&plan,&car);
	mouseinit();
	clrmous(MouseX, MouseY);

	while (1) 
	{
		switch(page_index) 
		{
			case 0:
				life_page(&page_index);
				break;
			case 1:
				weather_page(&page_index);
				break;
			case 2:
				car_page(&page_index, &air, &instrument,&ischange);
				break;
			case 3:
				stage = 1;
				break;
			case 4://¶ÓÓÑÐ´µÄ´úÂë
				page_index = music_page();
			case 5:
				twoDmap(&page_index);
				break;
			case 6:
				//page_index = game_page();
				;
			case 7:
				//page_index = movie_page();
				;
			case 8:
				//page_index = calendar_page();
				;
			case 9:
				//page_index = temcurve();
				;
		}
		if(stage == 1) 
		{
			break;
		}
	}
	
	return 0;
		
}
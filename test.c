#include<stdio.h>
#define inf 999


void floyd(unsigned(*P)[15], unsigned int(*D)[15]) //需要用点计算器计算
{
	int i, j, k;
	unsigned temp_P[15][15];
	unsigned temp_D[15][15] =
	{
		/*0, 1 ,2 ,3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 ,14 ,15*/
		{0,inf,54, inf, inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf},//0   //0
		{inf,0, inf,inf,234,inf,inf,288,inf,282,inf,inf,inf,inf,inf},//1		//1
		{54, inf,0 ,47,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf},//2		//2
		{inf,inf, 47, 0,144,114,230,inf, inf,inf,inf,inf,inf,inf,inf},//3		//3
		{inf,234,inf,144,0,98,214,184,inf,88,inf,inf,inf, inf, inf},//4		//4
		{inf,inf,inf,114,98, 0,184,inf,29,inf,inf,inf,inf,inf,inf},//5		//5
		{inf,inf,inf,230,214,184,0,inf,inf,inf,inf,inf,inf,inf,inf},//6		//6
		{inf,288,inf,inf,184,inf,inf,0,inf,inf,215,inf,229,inf,288},//7
		{inf,inf,inf,inf,inf,29,inf,inf, 0,inf,75,inf,inf,inf,inf},//8
		{inf,282,inf,inf,88,inf,inf,inf, inf,0,86,inf,inf,inf,inf},//9
		{inf,inf,inf,inf,inf,inf,inf,215,75, 86, 0,96,122,inf,181},//10
		{inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,96, 0,inf,inf,inf},//11
		{inf,inf,inf,inf,inf,inf,inf,229,inf,inf,122,inf,0,123,195},//12
		{inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,123,0,inf},//13
		{inf,inf,inf,inf,inf,inf,inf,288,inf,inf,181,inf,195,inf,0} //14			//14
	};

	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			temp_P[i][j] = j;
		}
	}



	for (i = 0; i < 15; i++)
	{
		for (j = 0; j < 15; j++)
		{
			D[i][j] = temp_D[i][j];
			P[i][j] = temp_P[i][j];
		}
	}



	for (k = 0; k < 15; k++)
	{
		for (i = 0; i < 15; i++)
		{
			for (j = 0; j < 15; j++)
			{
				if (D[i][j] > D[i][k] + D[k][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = P[i][k];
				}
			}
		}
	}
}

int main()
{
	int i, j;
	int now, temp, destination;
	unsigned P[15][15];
	unsigned D[15][15];
	floyd(P, D);

	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			printf("%d ", P[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < 15; i++) {
		for (j = 0; j < 15; j++) {
			printf("%d ", D[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	now = 4; destination = 6;

	printf("%d - ", now);

	while (now != destination)
	{

		temp = P[now][destination];
		//paint_line(now, temp);//这个划线函数要好好考究
		//*p_distance += getdistance(now, temp);
		printf("%d - ", temp);
		now = temp;
	}



	return 0;

}

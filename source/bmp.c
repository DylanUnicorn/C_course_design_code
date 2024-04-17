///////////////////////////////////////////
////bmp.c
///AUTHOR:Nie Dujun
////FUNCTION:��ͼ

#include"bmp.h"
#include"public.h"

/************************************************************
FUNCTION:putbmp
DESCRIPTION:��ͼ
INPUT:x, y, s ��ͼλ�ú��ļ�·��
OUTPUT:void
RETURN:int
************************************************************/
int putbmp(int x, int y, char* s)
{
    FILE* fp;
    long begin, w, h;
    unsigned char k;
    unsigned char color[256], r, g, b;
    unsigned int i, j, bit;
    if ((fp = fopen(s, "rb")) == NULL)
    {
        printf("not open");
        return 1;
    }
    fseek(fp, 10l, 0);
    fread(&begin, 4, 1, fp);
    fseek(fp, 18l, 0);
    fread(&w, 4, 1, fp);
    fread(&h, 4, 1, fp);
    fseek(fp, 28l, 0);
    fread(&bit, 2, 1, fp);
    if (bit != 8)
    {
        fclose(fp);
        printf("bit:%d,not 8", bit);
        return 2;
    }
    fseek(fp, 54l, 0);
    for (i = 0; i < 256; i++)
    {
        fread(&b, 1, 1, fp);
        fread(&g, 1, 1, fp);
        fread(&r, 1, 1, fp);
        if (r < 42)
        {

            color[i] = (b > 84) + 2 * (g > 84);
        }
        else if (r < 126)
        {
            color[i] = 8 + (b > 168) + 2 * (g > 168);
        }
        else if (r < 210)
        {
            color[i] = 4 + (b > 84) + 2 * (g > 60);
        }
        else
        {
            color[i] = 12 + (b > 168) + 2 * (g > 168);
        }

        fseek(fp, 1, 1);
    }
    for (i = 0; i < h; i++)
    {

        fseek(fp, begin + (w + 3) / 4 * i * 4, 0);

        for (j = 0; j < w; j++)
        {

            fread(&k, 1, 1, fp);
            putpixel(x + j, y + h - i - 1, color[k]);
        }
    }
    fclose(fp);
    return 0;
}


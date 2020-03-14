#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int load_pgm(const char *filename, int *w, int *h, unsigned char *buf)
{
  char header[3];
  int dummy, imagesize;
  int i;
  FILE *fp;

  fp = fopen(filename, "rb");
  if(fp == NULL)
  {
    fprintf(stderr, "Error: cannnot open file %s\n", filename);
    return 0;
  }
  //識別記号、画像サイズ、明るさを読み込み
  fscanf(fp, "%s\n%d %d\n%d\n", header, w, h, &dummy);
  imagesize = *w * *h;

  if(strcmp(header, "P2") == 0)
  {
    //アスキー形式の画像データ読み込みと出力
    for(i=0; i<(imagesize); i++)
    {
      fscanf(fp, "%d ", &buf[i]);
    }
  } else
  {
    //バイナリ形式の画像データ読み込みと出力
    for(i=0; i<(imagesize); i++)
    {
      fread(&buf[i], sizeof(unsigned char), 1, fp);
    }
  }

  if(buf[imagesize-1] != '\0')
  {
    return 1;
  } else
  {
    return 0;
  }
}

int save_pgm(const char *filename, int w, int h, unsigned char *buf)
{
  return 0;
}

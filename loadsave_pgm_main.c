#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loadsave_pgm.h"

#define MAX_IMAGE_SIZE 512

int main(int argc, char *argv[])
{
  int w, h, imagesize;
  unsigned char buf[MAX_IMAGE_SIZE*MAX_IMAGE_SIZE];
  char *filename;
  int i;

  //コマンドライン引数からファイル名を取り出す
  if(argc != 2)
  {
    printf("Usage: ./pgm_dump filename\n");
    return -1;
  }
  filename = argv[1];

 if(load_pgm(filename, &w, &h, buf) == 1){
   //画像サイズ出力
   printf("image size: %dx%d\n", w, h);
   imagesize = w*h;
   //画像データを出力
   for(i=0; i<(imagesize); i++)
   {
     printf("%d ", buf[i]);
   }
 } else
 {
   printf("Failed to load %s\n", filename);
 }

  return 0;
}

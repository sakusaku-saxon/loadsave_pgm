#ifndef __LOADSAVE_H__
#define __LOADSAVE_H__

int load_pgm(const char *filename, int *w, int *h, unsigned char *buf);

int save_pgm(const char *filename, int w, int h, unsigned char *buf);

#endif

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>

int *lis(int *numbox,int size);
int *makeinit(int *longest,int size,int p);
int *copypush(int *resulti,int *resultj,int size,int pushnum);
void print_lis(int *lis_result);

#endif

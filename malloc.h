/*
** 
**
** Made by VANHEMELRYCK nathan
** Login   <vanhem_n@etna-alternance.net>
**
** 
**
*/

#ifndef __MALLOC_H__
#define __MALLOC_H__
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define BSIZE sizeof(t_block)

typedef struct s_block_meta {
  size_t size;
  struct s_block_meta *next;
  struct s_block_meta *prev;
  int free;
  int magic; 
} t_block;



void      my_putchar(char c);
t_block *blockPtr(void *ptr);
t_block *smartRezize(t_block* block,size_t size);
t_block *requestSpace(size_t size);
t_block *findFreeBloc(t_block** last, size_t size);
void *malloc(size_t size);
void free(void *ptr);
void *realloc(void *ptr, size_t size);

#endif
#include "malloc.h"

static t_block *head_list = NULL;

/* Malloc */
void *malloc(size_t size) {
  t_block *block;
  if (size <= 0)
    return NULL;
  if (!head_list) {
    block = requestSpace(size);
    if (!block)
      return NULL;
  } else {
    t_block *last = head_list;
    block = findFreeBloc(&last, size);
    if (!block) {
      block = requestSpace(size);
      if (!block) 
        return NULL;
    } else {
      block->free = 0;
      block->magic = 6666;
    }
  }
  return(block + 1);
}

/* Free */
void free(void *ptr) {
  if (!ptr)
    return;

  t_block* block_ptr = blockPtr(ptr);
  block_ptr->free = 1;
  block_ptr->magic = 3333;
}

/* Realloc */
void *realloc(void *ptr, size_t size) {
  if (!ptr)
    return malloc(size);
  t_block* block_ptr = blockPtr(ptr);
  if (block_ptr->size >= size)
    return ptr;
  void *new_ptr;
  new_ptr = malloc(size);
  if (!new_ptr)
    return NULL;
  memcpy(new_ptr, ptr, block_ptr->size);
  free(ptr);
  return new_ptr;
}

/* Calloc */
void *calloc(size_t nelem, size_t elsize) {
  size_t size = nelem * elsize;
  void *ptr = malloc(size);
  memset(ptr, 0, size);
  return ptr;
}

/* Retourne le header (t_block) */
t_block *blockPtr(void *ptr) {
  return (t_block*)ptr - 1;
}

/* Trouver un bloc free pour reasigner */
t_block *findFreeBloc(t_block** last, size_t size) {
  t_block *current = head_list;
  while (current && !(current->free && current->size >= size)) {
    *last = current;
    current = current->next;
  }
  return smartRezize(current, size);
}

/* resize un bloc free si et seulement si apres ce rezize */
/* le nouveaux bloque est moins grand que le 1er (pour ne pas casser le trie de la liste) */
t_block *smartRezize(t_block* block,size_t size) {
  if (block && block->next){
    if (block->next->size > (block->size - size - BSIZE)) {
      size_t rest = block->size - size - BSIZE;
      block->size = size;
      t_block *excess;
      excess = (t_block *) (((char *) block) + size + BSIZE);
      excess->size = rest;
      excess->free = 1;
      excess->next = block->next;
      block->next = excess;
    }
  }
  return block;
}

/* cree un nouveaux bloque */
t_block *requestSpace(size_t size) {
  t_block *block;
  block = sbrk(0);
  void *request = sbrk(size + BSIZE);
  if (request == (void*) -1)
    return NULL;
  block->size = size;
  block->free = 0;
  block->magic = 1234;
  if (head_list) {
    t_block *last = head_list;
    while (last->next && last->size >= size)
      last = last->next;
    if (last == head_list) {
      block->next = last;
      head_list = block;
    } else if (last->next == NULL) {
      last->next = block;
      block->next = NULL;
    } else {
      block->next = last->next;
      last->next = block;
    }
  } else {
    block->next = NULL;
    head_list = block;
  }
  return block;
}
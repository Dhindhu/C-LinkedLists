// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

#include "list.h"

list_t *list_alloc() { 
  list_t *list = malloc(sizeof(list_t));
  return list; 
}

void list_free(list_t *l) {
  if (l == NULL){
    return;
  }
  node_t *cur = l->head;
  while (cur!=NULL){
    node_t *temp = cur;
    cur = cur->next;
    free(temp);
  }
}

void list_print(list_t *l) {
  node_t *cur = l->head;
  while (cur->next != NULL){
    printf("%d->", cur->value);
    cur = cur->next;
  }
  printf("%d\n", cur->value);
}

int list_length(list_t *l) { 
  if (l == NULL){
    return -1; 
  }
  node_t  *cur = l->head;
  int length = 0;
  while (cur != NULL){
    length += 1;
    cur = cur->next;
  }
  return length;
}

void list_add_to_back(list_t *l, elem value) {
  node_t *cur = l->head;
  if (cur == NULL){
    l->head = malloc(sizeof(node_t));
    l->head->value = value;
    return;
  }
  l->head = malloc(sizeof(node_t));
  l->head->value = value;
  l->head->next = cur;
}

void list_add_to_front(list_t *l, elem value) {
  node_t *cur = l->head;
  if (cur == NULL){
    l->head = malloc(sizeof(node_t));
    l->head->value = value;
    return;
  }
  while (cur->next != NULL){
    cur = cur->next;
  }
  cur->next = malloc(sizeof(node_t));
  cur->next->value = value;
}

void list_add_at_index(list_t *l, elem value, int index) {
  if (index == 0){
    node_t *cur = l->head;
    l->head = malloc(sizeof(node_t));
    l->head->value = value;
    l->head->next = cur;
    return;
  }
  if (l == NULL){
    return;
  }
  node_t *cur = l->head;
  int cur_indx = 1;
  while (cur_indx < index){
    cur = cur->next;
    cur_indx += 1;
  }
  if (cur_indx == index){
    node_t *temp = cur->next;
    node_t* new_node = malloc(sizeof(node_t));
    new_node->value = value;
    cur->next = new_node;
    new_node->next = temp;
  }
}

elem list_remove_from_back(list_t *l) { 
  if (l == NULL){
    return -1;
  }
  node_t *cur = l->head;
  node_t *nxt = cur->next;
  l->head = nxt;
  free(cur);
}

elem list_remove_from_front(list_t *l) { 
  if (l == NULL){
    return -1;
  }
  node_t *cur = l->head;
  while (cur->next->next != NULL){
    cur = cur->next;
  }
  cur->next = NULL;
  free(cur->next);
}

elem list_remove_at_index(list_t *l, int index) { 
  if (l == NULL){
    return -1;
  }
  
  node_t *cur = l->head;
  
  if (index == 0){
    node_t *nxt = cur->next;
    l->head = nxt;
    free(cur);
  }
  
  int cur_indx = 0;
  
  while (cur_indx+1 != index && cur->next != NULL){
    cur = cur->next;
    cur_indx += 1;
  }
  
  if (cur_indx+1 == index){
    node_t *temp = cur->next->next;
    node_t *nxt = cur->next;
    cur->next = temp;
    free(nxt);
  } 
}

bool list_is_in(list_t *l, elem value) { 
  if (l == NULL){
    return false;
  }
  node_t *cur = l->head;
  while (cur->value != value && cur->next != NULL){
    cur = cur->next;
  }
  if (cur->value == value){
    return true;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index) { 
  if (l == NULL){
    return -1;
  }
  node_t *cur = l->head;
  int cur_indx = 0;
  while (cur_indx < index){
    cur = cur->next;
    cur_indx += 1;
  }
  if (cur_indx == index){
    return cur->value;
    //printf("%d\n", cur->value);
  }
  return -1; }

int list_get_index_of(list_t *l, elem value) { 
   if (l == NULL){
     return -1;
   }
  node_t *cur = l->head;
  int cur_indx = 0;
  while (cur->value < value){
    cur = cur->next;
    cur_indx += 1;
  }
  if (cur->value == value && cur->next != NULL){
    return cur_indx;
    //printf("%d\n", cur_indx);
  }
  else{
    return -1; 
  }
}


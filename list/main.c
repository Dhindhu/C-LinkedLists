#include <stdio.h>

#include "list.h"


int main() {
  printf("Tests for linked list implementation\n");
  list_t *my_list = list_alloc();
  list_add_to_front(my_list, 9);
  list_add_to_front(my_list, 0);
  list_add_to_front(my_list, 5);
  list_add_to_front(my_list, 2);
  list_add_to_back(my_list, 4);
  list_add_to_back(my_list, 8);
  list_add_to_back(my_list, 1);
  list_print(my_list);
  list_add_at_index(my_list, 99, 2);
  list_remove_from_back(my_list);
  list_print(my_list);
  list_remove_from_front(my_list);
  list_print(my_list);
  printf("length of list is: %d \n", list_length(my_list));
  list_remove_at_index(my_list, 4);
  printf("New list is: \n");
  list_print(my_list);
  printf("Is number in linked list? %d \n", list_is_in(my_list, 4));
  printf("Get the element at index 2: %d \n", list_get_elem_at(my_list, 2));
  printf("Get the index of 0: %d \n", list_get_index_of(my_list, 0));
  list_free(my_list);
  list_print(my_list);
  return 0;
}

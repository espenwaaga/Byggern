#ifndef MENU_H
#define MENU_H
#include <stdio.h>

typedef struct{
  const char* title;
  const char* menu1;
  const char* menu2;
  const char* menu3;
} MENU;

typedef struct Node {
  MENU menu;
  struct Node* parent;
  struct Node* child1;
  struct Node* child2;
  struct Node* child3;
} Node;


Node newNode(MENU menu);
void initMenu(void);
void constructMenu(Node* currentNode);
void removeArrow(int line);
void checkJoystickDirection(void);

#endif

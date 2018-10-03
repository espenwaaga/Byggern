#include <avr/io.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include "F_CPU.h"
#include "util/delay.h"
#include "oled.h"
#include "joystick.h"
#include "menu.h"
#include "menu_names.h"

// ---- Joystick function ---- //
// JOY_pos getJoystickAnalogPos(void);
//
// SLIDER_pos getSliderAnalogPos(void);
//
// JOY_dir_t getJoystickDirection(int deadzone);

Node newNode(MENU menu){
  // Assign struct to Node
  Node node;
  node.menu = menu;

  // Parent and children
  node.parent = NULL;
  node.child1 = NULL;
  node.child2 = NULL;
  node.child3 = NULL;

  return(node);
}

char* bufferFromPROGMEM(char* menuString){
  char buffer[15];
  int i = 0;
  // Her legger vi til en '\0' fordi den ikke er inkludert i while løkken
	while( pgm_read_byte(&menuString[i]) != '\0'){
    buffer[i] = pgm_read_byte(&menuString[i]);
    i++;
  }
  buffer[i] = '\0';

  printf(buffer);
  char *pointer = &buffer[0];
  return pointer;
}

void initMenu(void){
  oled_init();
  oled_clearScreen();   // Clear screen, go to pos (0, 0)
  _delay_ms(500);
  // Making the Main Menu struct
  MENU MainMenu;

  // Main menu interface
  MainMenu.title = MM_title_string;
  MainMenu.menu1 = MM_menu1_string;
  MainMenu.menu2 = MM_menu2_string;
  MainMenu.menu3 = MM_menu3_string;


  // Sub Menus
  MENU PlayGame;
  MENU HighScores;
  MENU Settings;

  // Play Game interface
  PlayGame.title = (char*)&PG_title_string;
  PlayGame.menu1 = (char*)&PG_menu1_string;
  PlayGame.menu2 = (char*)&PG_menu2_string;
  PlayGame.menu3 = (char*)&PG_menu3_string;

  // High Scores interface
  HighScores.title = (char*)&HS_title_string;
  HighScores.menu1 = (char*)&HS_menu1_string;
  HighScores.menu2 = (char*)&HS_menu2_string;
  HighScores.menu3 = (char*)&HS_menu3_string;


  // Settings interface
  Settings.title = (char*)&SETTING_title_string;
  Settings.menu1 = (char*)&SETTING_menu1_string;
  Settings.menu2 = (char*)&SETTING_menu1_string;
  Settings.menu3 = (char*)&SETTING_menu1_string;

  // Initialize main menu
  Node mainMenuNode   = newNode(MainMenu);
  Node playGameNode   = newNode(PlayGame);
  Node highScoresNode = newNode(HighScores);
  Node settingsNode   = newNode(Settings);


  // Addressen til mainMenu.child1 blir satt til addressen settings
  mainMenuNode.child1 = &playGameNode;
  mainMenuNode.child2 = &highScoresNode;
  mainMenuNode.child3 = &settingsNode;

  playGameNode.parent = &mainMenuNode;
  settingsNode.parent = &mainMenuNode;

  // Making Main Menu
  oled_print(bufferFromPROGMEM(MainMenu.title));
  oled_pos(2,0);
  oled_print(bufferFromPROGMEM(MainMenu.menu1));
  oled_pos(3,0);
  oled_print(bufferFromPROGMEM(MainMenu.menu2));
  oled_pos(4,0);
  oled_print(bufferFromPROGMEM(MainMenu.menu3));
}
//
// void constructP


// for(int i = 0; i<9; i++){
//   buffer[i] = pgm_read_byte(&MM_title_string[i]);
// }
//
// printf(buffer);
//
// printf(bufferFromPROGMEM(MainMenu.title));

// char buffer[15];
// strcpy_P(buffer, MM_title_string);
// char *point = &buffer;
// oled_print(point);
// printf(PSTR(MM_title_string));
//oled_print((char*)PSTR(MM_title_string));

// oled_print((char*)pgm_read_word(&MM_menu1_string));






// printf(pgm_read_byte(&MM_title_string[0]));

// char *spointer = &MM_title_string;
// // oled_print(spointer);
// c = spointer;
// while(c[i] != '\0'){
//   oled_print_char(c[i]);
//   i++;
// }





// char mainMenu_title[] = "Main Menu";
// char *mmpointer = &mainMenu_title[0];
// char home[] = "Settings";
//
// char settings[] = "  Settings";
// char *settingPointer = &settings[0];
//
// char pointer[] = "->";
// char *ppointer = &pointer[0];
//
// oled_pos(0, 20);
// oled_print(mmpointer);
//
// oled_pos(2, 16);
// oled_print(settingPointer);
//
// oled_pos(2, 0);
// oled_print(ppointer);




// printf(pgm_read_byte(&MM_title_string[0]));

// char *spointer = &MM_title_string;
// // oled_print(spointer);
// c = spointer;
// while(c[i] != '\0'){
//   oled_print_char(c[i]);
//   i++;
// }





// char mainMenu_title[] = "Main Menu";
// char *mmpointer = &mainMenu_title[0];
// char home[] = "Settings";
//
// char settings[] = "  Settings";
// char *settingPointer = &settings[0];
//
// char pointer[] = "->";
// char *ppointer = &pointer[0];
//
// oled_pos(0, 20);
// oled_print(mmpointer);
//
// oled_pos(2, 16);
// oled_print(settingPointer);
//
// oled_pos(2, 0);
// oled_print(ppointer);

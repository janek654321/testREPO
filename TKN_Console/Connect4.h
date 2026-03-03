#ifndef CONNECT4_H
#define CONNECT4_H

#include "Engine.h"

extern Adafruit_ST7735 tft;
extern InputManager keys;

class Connect4 : public Game {
private:

  Color boardOutlineColor = LIGHTGREEN;
  Color player1Color = RED;
  Color player2Color = LIGHTBLUE;
  Color line4Color = YELLOW;

  bool dropToken = false;
  bool gameOver = false;
  bool blinkState = 0;
  int8_t xPos = 3, yPos = -1;
  uint8_t startPlayer = 1;
  uint8_t currentPlayer = startPlayer;
  uint8_t boardMatrix[8][7] = {};
  uint8_t tokenCounter[2] = {};
  uint8_t line4coord[2][4] = {};

  uint32_t dropTokenMillis = 0;
  const uint16_t dropTokenInterval = 50;
  uint32_t tokenBlinkMillis = 0;
  const uint16_t tokenBlinkInterval = 400;

  void drawScreen();
  void removeToken();
  void moveToken(int8_t xDir, int8_t yDir);
  bool scanLine(int8_t xStep, int8_t yStep);

public:
  void setup() override;
  void loop() override;
};


#endif
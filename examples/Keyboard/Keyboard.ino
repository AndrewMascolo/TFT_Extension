#include <UTFT.h>
#include <UTouch.h>
#include <TFT_Extension.h>
// Declare which fonts we will be using
extern uint8_t SmallFont[];

UTFT    myGLCD(CTE70, 38, 39, 40, 41);
UTouch  myTouch( 6, 5, 4, 3, 2);
TFT_Extension myTFT(&myGLCD, &myTouch);

char* msg;

void setup()
{
  Serial1.begin(9600); // default bluetooth baudrate.
  myGLCD.InitLCD(PORTRAIT);
  myGLCD.clrScr();
  myGLCD.setFont(SmallFont);
  myTouch.InitTouch(PORTRAIT);
  myTouch.setPrecision(PREC_MEDIUM);
  myTFT.ExtSetup();
  
  myGLCD.fillScr(0,0,0);

  myTFT.SetupMobileKB(0,150); //NEEDED TO WORK!
}

void loop()
{ 
  myTFT.ReceiveMsg(0,0,YELLOW); // X,Y(position on screen), Color
  msg = myTFT.Mobile_KeyBoard(BLUE);
  if(msg != NULL)
    myGLCD.print(msg,0,50);

}



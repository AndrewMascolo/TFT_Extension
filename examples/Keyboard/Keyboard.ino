#include <UTFT.h>
#include <UTouch.h>
#include <TFT_Extension.h>
// Declare which fonts we will be using
extern uint8_t SmallFont[];

//myGLCD(RS,WR,CS,RST,ALE,mode);
UTFT myGLCD(A1,A2,A0,A3,A5,ITDB32S);
//myTouch(TCLK,TCS,DIN,DOUT,IRQ);
UTouch  myTouch(13,10,11,12,A4);
TFT_Extension myTFT(&myGLCD, &myTouch, PORTRAIT);

char* msg;

void setup()
{
  Serial1.begin(9600); // default bluetooth baudrate.
  myGLCD.InitLCD(LANDSCAPE);
  myGLCD.clrScr();
  myGLCD.setFont(SmallFont);
  myTouch.InitTouch(LANDSCAPE);
  myTouch.setPrecision(PREC_LOW);
  myGLCD.fillScr(0,0,0);

  myTFT.SetupMobileKB(); //NEEDED TO WORK!
}

void loop()
{ 
  myTFT.ReceiveMsg(0,0,myTFT.ConvertRGB(YELLOW)); // X,Y(position on screen), Color
  msg = myTFT.Mobile_KeyBoard(myTFT.ConvertRGB(BLUE));
  if(msg != NULL)
    myGLCD.print(msg,0,50);

}



# include "iGraphics.h"

int delay=0,loadFlag=1,loadCmpltd=0,theatricalCmpltd=0,startPressed=0,startMenuCmpltd=0,newGamePressed=0,loadGamePressed=0,
	exitPressed=0,gameStart=0,egg1=0,egg2=0,egg3=0,egg4=0,egg5=0,ex1=0,ex2=0,ex3=0,ex4=0,ex5=0,ey=410,dwn1=0,dwn2=0,dwn3=0,dwn4=0,dwn5=0,
	hx=0,dx=5,nx=192,score=0,golden=0,green=0,bomb=0,level,gld,grn,red;

int levelDetect=0,henSpeed=0,range=5,fall=5,hen1Mirror=0,hen2Mirror=0,hen3Mirror=0,levelChange2=1, levelChange3=1, dontDraw=0, life,maxlife, newInit=0;


int pause=0,menu2newgame=0,menu2resume=0;

int hen2Flag=1,hen2mFlag=1,hen3Flag=1,hen3mFlag=1;

char Score[100];

/* 
	function iDraw() is called again and again by the system.	
*/



void iNewInitialize()
{
	egg1=0,egg2=0,egg3=0,egg4=0,egg5=0,ex1=0,ex2=0,ex3=0,ex4=0,ex5=0,ey=410,dwn1=0,dwn2=0,dwn3=0,dwn4=0,dwn5=0,
	hx=0,dx=5,nx=192,score=0,golden=0,green=0,bomb=0,levelDetect=0,henSpeed=0,range=5,fall=5,hen1Mirror=0,hen2Mirror=0,hen3Mirror=0,levelChange2=1, 
	levelChange3=1, dontDraw=0;

	life=10;menu2newgame=0,menu2resume=0,hen2Flag=1,hen2mFlag=1;

}

void iLoad()
{
	iSetColor(19,109,173);
	iFilledRectangle(0,0,512,650);
	if(loadFlag==1)
	{
		iShowBMP(96,175,"load 1.bmp");
		delay++;
	}

	if (delay==100) {loadFlag=2; delay=0;}

	if(loadFlag==2)
	{
		iShowBMP(96,175,"load 2.bmp");
		delay++;
	}

	if (delay==100) {loadFlag=3; delay=0;}

	if(loadFlag==3)
	{
		iShowBMP(96,175,"load 3.bmp");
		delay++;

		if(delay==25) {loadCmpltd=1; delay=0;}
	}

}

void iTheatrical()
{
	if (loadCmpltd==1)
	{
		iShowBMP(0,0,"theatrical.bmp");
		iShowBMP(206,40,"start button 1.bmp");
		if (startPressed==1) 
		{
			iShowBMP(206,40,"start button 2.bmp");
			delay++;

			if (delay==20) {theatricalCmpltd=1; delay=0;}
		}

	}
}

void iStartMenu()
{
	if (theatricalCmpltd==1)
	{
		iSetColor(19,109,173);
		iFilledRectangle(0,0,512,650);

		iShowBMP(0,0,"menu 1.bmp");
		if(newGamePressed==1) 
		{
			//iNewInitialize();
			iShowBMP(0,0,"newgame 1.bmp");
			delay++;

			if (delay==20) 
			{
				startMenuCmpltd=1;
				gameStart=1;
				delay=0;
			}
		}

		if(loadGamePressed==1) 
		{
			iShowBMP(67,287,"load game 2.bmp");
			startMenuCmpltd=1;
		}

		if(exitPressed==1) 
		{
			iShowBMP(67,171,"exit 2.bmp");
			//startMenuCmpltd=1;
		}

	}
}


void hen2()
{
	if (hen2Mirror==0)
	{
		if(hen2Flag==1)
		{
			iShowBMP(hx,410,"hen 2_a1.bmp");
			delay++;
		}

		if (delay==12) {hen2Flag=2; delay=0;}

		if(hen2Flag==2)
		{
			iShowBMP(hx,410,"hen 2_a2.bmp");
			delay++;
		}

		if (delay==12) {hen2Flag=3; delay=0;}

		if(hen2Flag==3)
		{
			iShowBMP(hx,410,"hen 2_a3.bmp");
			delay++;
		}

		if (delay==12) {hen2Flag=4; delay=0;}

		if(hen2Flag==4)
		{
			iShowBMP(hx,410,"hen 2_a4.bmp");
			delay++;
		}

		if (delay==12) {hen2Flag=5; delay=0;}

		if(hen2Flag==5)
		{
			iShowBMP(hx,410,"hen 2_a5.bmp");
			delay++;
		}

		if (delay==12) {hen2Flag=1; delay=0;}

		/*if(hen2Flag==6)
		{
			iShowBMP(hx,410,"hen 2_a6.bmp");
			delay++;
		}

		if (delay==10) {hen2Flag=1; delay=0;}*/

	}

	if (hen2Mirror==1)
	{
		if(hen2mFlag==1)
		{
			iShowBMP(hx,410,"hen 2_b1.bmp");
			delay++;
		}

		if (delay==12) {hen2mFlag=2; delay=0;}

		if(hen2mFlag==2)
		{
			iShowBMP(hx,410,"hen 2_b2.bmp");
			delay++;
		}

		if (delay==12) {hen2mFlag=3; delay=0;}

		if(hen2mFlag==3)
		{
			iShowBMP(hx,410,"hen 2_b3.bmp");
			delay++;
		}

		if (delay==12) {hen2mFlag=4; delay=0;}

		if(hen2mFlag==4)
		{
			iShowBMP(hx,410,"hen 2_b4.bmp");
			delay++;
		}

		if (delay==12) {hen2mFlag=5; delay=0;}

		if(hen2mFlag==5)
		{
			iShowBMP(hx,410,"hen 2_b5.bmp");
			delay++;
		}

		if (delay==12) {hen2mFlag=1; delay=0;}

		/*if(hen2mFlag==6)
		{
			iShowBMP(hx,410,"hen 2_b6.bmp");
			delay++;
		}

		if (delay==15) {hen2mFlag=1; delay=0;}*/

	}





}

void hen3()
{
	if (hen3Mirror==0)
	{
		if(hen3Flag==1)
		{
			iShowBMP(hx,410,"hen 3_a1.bmp");
			delay++;
		}

		if (delay==12) {hen3Flag=2; delay=0;}

		if(hen3Flag==2)
		{
			iShowBMP(hx,410,"hen 3_a2.bmp");
			delay++;
		}

		if (delay==12) {hen3Flag=3; delay=0;}

		if(hen3Flag==3)
		{
			iShowBMP(hx,410,"hen 3_a3.bmp");
			delay++;
		}

		if (delay==12) {hen3Flag=4; delay=0;}

		if(hen3Flag==4)
		{
			iShowBMP(hx,410,"hen 3_a4.bmp");
			delay++;
		}

		if (delay==12) {hen3Flag=5; delay=0;}

		if(hen3Flag==5)
		{
			iShowBMP(hx,410,"hen 3_a5.bmp");
			delay++;
		}

		if (delay==12) {hen3Flag=1; delay=0;}

		/*if(hen2Flag==6)
		{
			iShowBMP(hx,410,"hen 2_a6.bmp");
			delay++;
		}

		if (delay==10) {hen2Flag=1; delay=0;}*/

	}

	if (hen3Mirror==1)
	{
		if(hen3mFlag==1)
		{
			iShowBMP(hx,410,"hen 3_b1.bmp");
			delay++;
		}

		if (delay==12) {hen3mFlag=2; delay=0;}

		if(hen3mFlag==2)
		{
			iShowBMP(hx,410,"hen 3_b2.bmp");
			delay++;
		}

		if (delay==12) {hen3mFlag=3; delay=0;}

		if(hen3mFlag==3)
		{
			iShowBMP(hx,410,"hen 3_b3.bmp");
			delay++;
		}

		if (delay==12) {hen3mFlag=4; delay=0;}

		if(hen3mFlag==4)
		{
			iShowBMP(hx,410,"hen 3_b4.bmp");
			delay++;
		}

		if (delay==12) {hen3mFlag=5; delay=0;}

		if(hen3mFlag==5)
		{
			iShowBMP(hx,410,"hen 3_b5.bmp");
			delay++;
		}

		if (delay==12) {hen3mFlag=1; delay=0;}

		/*if(hen2mFlag==6)
		{
			iShowBMP(hx,410,"hen 2_b6.bmp");
			delay++;
		}

		if (delay==15) {hen2mFlag=1; delay=0;}*/

	}





}

void iEgg()
{
		if (egg1==0)
		{
			ex1=rand()%512;
			ex1=ex1-ex1%dx;
			if (ex1<8) ex1=ex1+10;
		}

		if (egg2==0)
		{
			ex2=rand()%512;
			ex2=ex2-ex2%dx;
			if (ex2<8) ex2=ex2+10;
		}

		if (egg3==0)
		{
			ex3=rand()%512;
			ex3=ex3-ex3%dx;
			if (ex3<8) ex3=ex3+10;
		}

		if (egg4==0)
		{
			ex4=rand()%512;
			ex4=ex4-ex4%dx;
			if (ex4<8) ex4=ex4+10;
		}

		if (egg5==0)
		{
			ex5=rand()%512;
			ex5=ex5-ex5%dx;
			if (ex5<8) ex5=ex5+10;
		}

}

void iEggFall()
{
		if(egg1==1)
		{
			dwn1=dwn1+fall;
			if(nx>=ex1-84 && nx<=ex1-26 && dwn1==380) {score=score+15; printf("Score & life : %d %d\n",score,life);}
			else if (dwn1>=380) life--;
			if(dwn1==380) {dwn1=0; egg1=0;}
		}

		if (egg2==1)
		{
			dwn2=dwn2+fall;
			if(nx>=ex2-84 && nx<=ex2-26 && dwn2==380) {score=score+15; printf("Score & life : %d %d\n",score,life);}
			else if (dwn2>=380) life--;
			if(dwn2==380) {dwn2=0; egg2=0;}
		}

		if (egg3==1)
		{
			dwn3=dwn3+fall;
			if(nx>=ex3-84 && nx<=ex3-26 && dwn3==380) {if (life<maxlife) life++; printf("Score & life : %d %d\n",score,life);}
			if(dwn3==380) {dwn3=0; egg3=0;}
		}

		if (egg4==1)
		{
			dwn4=dwn4+fall;
			if(nx>=ex4-84 && nx<=ex4-26 && dwn4==380) {score=score+50; printf("Score & life : %d %d\n",score,life);}
			if(dwn4==380) {dwn4=0; egg4=0;}
		}

		if (egg5==1)
		{
			dwn5=dwn5+fall;
			if(nx>=ex5-84 && nx<=ex5-26 && dwn5==380) {score=score-50; printf("Score & life : %d %d\n",score,life);}
			if(dwn5==380) {dwn5=0; egg5=0;}
		}

		if (score>levelDetect) {levelDetect=score;}
}

void iHenMove()
{
	if (gameStart==1)
	{
		if (newInit==0) { iNewInitialize(); newInit=1;}
		iEgg();

		
		hx=hx+dx;
		if(hx>420 || hx<0) dx=-dx;

		if (level==1)
		{
			if (hx>420) hen1Mirror=1;
			else if (hx<0) hen1Mirror=0;
		}

		if (level==2)
		{
			if (hx>420) hen2Mirror=1;
			else if (hx<0) hen2Mirror=0;

		}

		if (level==3)
		{
			if (hx>420) hen3Mirror=1;
			else if (hx<0) hen3Mirror=0;

		}




		if (abs(hx+45-ex1)<=range) egg1=1;
		if(abs(hx+45-ex2)<=range) egg2=1;
		if(abs(hx+45-ex3)<=range) 
		{
			if (golden==gld) {egg3=1; golden=0;}
			else golden++;
		}

		if(abs(hx+45-ex4)<=range) 
		{
			if (green==grn) {egg4=1; green=0;}
			else green++;
		}

		if(abs(hx+45-ex5)<=range) 
		{
			if (bomb==red) {egg5=1; bomb=0;}
			else bomb++;
		}

		iEggFall();

	}

}


void iPause()
{
	iPauseTimer(0);

	iSetColor(19,109,173);
	iFilledRectangle(0,0,512,650);
	iShowBMP(0,69,"menu 2.bmp");

	if (menu2newgame==1) 
	{
		iShowBMP(0,69,"menu2newgame.bmp");
		delay++;

		if (delay==30) {gameStart=1; delay=0; newInit=0; pause=0;}
	}

	if (menu2resume==1) 
	{
		iShowBMP(0,69,"menu2resume.bmp");
		delay++;

		if (delay==30) {gameStart=1; delay=0; menu2resume=0,pause=0;}

	}


}

void ToString(int n)
{
    char str[100];
    int i;
	int temp;

	if(n == 0) {str[0] = '0'; str[1] = '\0';}
	
	else if(n > 0)
	{
		for(i = 0, temp = n; temp != 0; temp /= 10) 
		{
			str[i++] = (temp%10) + '0';
		}

		str[i] = '\0';
		reverse(str, str+i);
	}
	
	else if(n < 0)
	{
		for(i = 0, temp = n * (-1); temp != 0; temp /= 10)
		{
			str[i++] = (temp%10) + '0';
		}

		str[i] = '-';
		str[i+1] = '\0';
		reverse(str, str+(i+1));
	}
	
	strcpy(Score, str);
}


void iGame()
{
	if(gameStart==1)
	{
		iResumeTimer(0);
		if (levelDetect<100) level=1;
		else if(levelDetect>=100 && levelDetect<500) level=2;
		else level=3;

		if(level==1)
		{
			maxlife=10;
			iShowBMP(0,0,"back 1.bmp");
			iShowBMP(nx,0,"nest 1.bmp");
			gld=10;
			grn=8;
			red=5;

			if (hen1Mirror==0) iShowBMP(hx,410,"hen 1(a).bmp");
			else iShowBMP(hx,410,"hen 1(b).bmp");
			
		}

		else if(level==2)
		{
		
			if (levelChange2==1)
			{
				dontDraw=1;
				iShowBMP(0,0,"level1passed.bmp");
				delay++;
				iPauseTimer(0);
				if (delay==100) {levelChange2=0; delay=0; dontDraw=0; hx=0; dwn1=dwn2=dwn3=dwn4=dwn5=0; life=life+3; iResumeTimer(0);}
			}


			if (levelChange2==0) 
			{
				iShowBMP(0,0,"back 2.bmp"); 
				iShowBMP(nx,0,"nest 1.bmp"); 

				hen2();
				
			}


			
			maxlife=13;
			gld=15;
			grn=10;
			red=4;
			if (henSpeed==0) {dx=7; range=6; henSpeed=1;}

		}

		else if (level==3)
		{
			if (levelChange3==1)
			{
				dontDraw=1;
				iShowBMP(0,0,"level2passed.bmp");
				delay++;
				iPauseTimer(0);
				if (delay==100) {levelChange3=0; delay=0; dontDraw=0; hx=0; dwn1=dwn2=dwn3=dwn4=dwn5=0; life=life+2; iResumeTimer(0);}
			}


			if (levelChange3==0) 
			{
				iShowBMP(0,0,"back 3.bmp"); 
				iShowBMP(nx,0,"nest 1.bmp"); 

				hen3();

			}

			maxlife=15;
			gld=25;
			grn=15;
			red=3;
			if (henSpeed==1) {dx=8; range=6; henSpeed=0;}

		}

		
		if (dontDraw!=1)
		{
			if (egg1==1) {iSetColor(255,255,255); iFilledEllipse(ex1,ey-dwn1,8,12);}
			if (egg2==1) {iSetColor(255,255,255); iFilledEllipse(ex2,ey-dwn2,8,12);}
			if (egg3==1) {iSetColor(255,255,0); iFilledEllipse(ex3,ey-dwn3,8,12);}
			if(egg4==1) {iSetColor(181,230,29); iFilledEllipse(ex4,ey-dwn4,8,12);}
			//if(egg5==1) {iSetColor(181,230,29); iFilledEllipse(ex5,ey-dwn5,8,12);}
			if (egg5==1) iShowBMP(ex5,ey-dwn5,"bomb.bmp");


			iShowBMP(335,610,"score.bmp");
			ToString(score);
			iSetColor(255,255,0);
			iText(450, 621, Score, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		
	}
}

void iDraw()
{
	//place your drawing codes here
	//iClear();
	if(loadCmpltd==0) iLoad();
	else if(theatricalCmpltd==0) iTheatrical();
	else if(startMenuCmpltd==0) iStartMenu();
	else if(gameStart==1)
	{
		
		iGame();
	}

	else if (pause==1) iPause();

	
}



/* 
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/




void iMouseMove(int mx, int my)
{
	//place your codes here
	printf("%d %d\n",mx,my);

}
 



/* 
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/



void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
		
		
		if(theatricalCmpltd==0)
		{
			if ((mx>=206 && mx<=306)&&(my>=40 && my<=68))
				startPressed=1;
		}

		if(theatricalCmpltd==1 && startMenuCmpltd==0)
		{
			if((mx>=10 && mx<=215)&&(my>=525 && my<=590)) newGamePressed=1;
			if((mx>=295 && mx<=500)&&(my>=425 && my<=450 )) loadGamePressed=1;
			if((mx>=170 && mx<=375)&&(my>=20 && my<=85 )) exitPressed=1;
		}

		/*if (pause==1)
		{
			if ((mx>=72 && mx<=438)&&(my>=466 && my<=542)) menu2newgame=1;
			if ((mx>=72 && mx<=438)&&(my>=376 && my<=452)) menu2resume=1;

		}*/



		

		

	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here	
		
	}
}




/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.	
*/



void iKeyboard(unsigned char key)
{
	if(key == 'q')
	{
		exit(0);
	}
	//place your codes for other keys here

	if (key=='p') {gameStart=0; pause=1;}
	if(key=='r') iResumeTimer(0);
}




/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use 
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6, 
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12, 
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP, 
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT 
*/



void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);	
	}
	//place your codes for other keys here

	if (key==GLUT_KEY_LEFT) nx=nx-15; if(nx<=0) nx=1; 
	if (key==GLUT_KEY_RIGHT) nx=nx+15; if(nx>=404) nx=403; 
}






int main()
{
	//place your own initialization codes here. 
	
	iSetTimer(30,iHenMove);
	//iSetTimer(50,iEgg);
	//iSetTimer(1,iEggFall);


	iInitialize(512,650, "eggy peggy");

	return 0;
}	
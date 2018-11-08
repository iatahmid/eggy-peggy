#include "iGraphics.h"

int delay=0,loadFlag=1,loadCmpltd=0,theatricalCmpltd=0,startPressed=0,startMenuCmpltd=0,newGamePressed=0,loadGamePressed=0,
	exitPressed=0, hofPressed=0, creditPressed=0, instructionPressed=0, gameStart=0,egg1=0,egg2=0,egg3=0,egg4=0,egg5=0,
	ex1=0,ex2=0,ex3=0,ex4=0,ex5=0,ey=410,dwn1=0,dwn2=0,dwn3=0,dwn4=0,dwn5=0,
	hx=0,dx=5,nx=192,score=0,golden=0,green=0,bomb=0,level,gld,grn,red;

int pauseGamePressed=0, pauseResumePressed=0, pauseSavePressed=0, pauseMenuPressed=0, saveGame=0, slotSelect=0,
	slot1=0, slot2=0, slot3=0, slotSelectLG=0, LGslot=0, LGslot1=0, LGslot2=0, LGslot3=0, OKpressed=0,cancelPressed=0,
	gameOver=0, congratsShow=0, nameInput=0, textboxVisited=0, hofShow=0, thanksShow=0, creditShow=0, instructionShow=0;

int textbox=0,len=0,warning=0,clicked=0,flagEgg=0, fileWarning = 0;

int breakdelay,pausedelay,thanksdelay,gameoverdelay,canceldelay,okdelay,congratsdelay;

int newgamedelay,loadgamedelay;

char Score[100];
char saveFile[15];
char tempString[10];
char cheat[10];

int levelDetect=0,henSpeed=0,range=5,fall=5,hen1Mirror=0,hen2Mirror=0,hen3Mirror=0,levelChange2=1,
	levelChange3=1, dontDraw=0,life=10,maxlife,newInit=0;

int hen2Flag=1,hen2mFlag=1,hen3Flag=1,hen3mFlag=1;

/*
	function iDraw() is called again and again by the system.
*/

void iNewInitialize()
{
	egg1=0,egg2=0,egg3=0,egg4=0,egg5=0,ex1=0,ex2=0,ex3=0,ex4=0,ex5=0,ey=410,dwn1=0,dwn2=0,dwn3=0,dwn4=0,dwn5=0,
	hx=0,dx=5,nx=192,score=0,golden=0,green=0,bomb=0;

	levelDetect=0,henSpeed=0,range=5,fall=5,hen1Mirror=0,hen2Mirror=0,hen3Mirror=0,levelChange2=1,
	levelChange3=1, dontDraw=0;

	life=10,hen2Flag=1,hen2mFlag=1,hen3Flag=1,hen3mFlag=1;

	flagEgg=0;
	fileWarning = 0;

	gameOver=0;

	breakdelay=pausedelay=thanksdelay=gameoverdelay=canceldelay=okdelay=congratsdelay=0;
	newgamedelay=0;
	loadgamedelay=0;

	slotSelectLG=0;
}

struct game
{
    int slNo, score;
    char name[15];
} hof[15];

bool comp(game a, game b)
{
    if(a.score > b.score) return true;
    else return false;
}

struct arr1
{
	char savedFile[10];
	int score, life, level;
} save[5];


void FileToStructureSG()
{
	FILE *fp;

	if((fp = fopen("saved game.txt", "r")) == NULL)
	{
		fp = fopen("saved game.txt", "w");
		fprintf(fp, "EMPTY 0 0 0\nEMPTY 0 0 0\nEMPTY 0 0 0\n");
		fclose(fp);
	}


	FILE *fload;

	fload = fopen("saved game.txt", "r");

	for(int i = 0; i < 3; i++)
	{
		fscanf(fload,"%s %d %d %d", save[i].savedFile, &save[i].score, &save[i].life, &save[i].level);
	}

	fclose(fload);
}

void StructureToFileSG()
{
	FILE *fsave;

	fsave = fopen("saved game.txt", "w");
	for(int i = 0; i < 3; i++)
	{
		fprintf(fsave, "%s %d %d %d\n", save[i].savedFile, save[i].score, save[i].life, save[i].level);
	}
	fclose(fsave);
}

void FileToStructureHOF()
{
	FILE *fp;

	if((fp = fopen("hall of fame.txt", "r")) == NULL)
	{
		fp = fopen("hall of fame.txt", "w");
		for(int i = 0; i < 11; i++)
			fprintf(fp, "%d EMPTY 0\n", i + 1);
		fclose(fp);
	}


	FILE *fload;

	fload = fopen("hall of fame.txt", "r");
	for(int i = 0; i < 11; i++)
		fscanf(fload, "%d %s %d", &hof[i].slNo, hof[i].name, &hof[i].score);

	fclose(fload);
}

void StructureToFileHOF()
{
	FILE *fsave;

	fsave = fopen("hall of fame.txt", "w");
	for(int i = 0; i < 11; i++)
		fprintf(fsave, "%d %s %d\n", i + 1, hof[i].name, hof[i].score);
	fclose(fsave);
}

void ToString(int n, char strOutput[])
{
    char str[100];
    int i;
	int temp;

	if(n == 0) {str[0] = '0'; str[1] = '\0';}

	else if(n > 0)
	{
		for(i = 0, temp = n; temp != 0; temp /= 10)
			str[i++] = (temp%10) + '0';

		str[i] = '\0';
		reverse(str, str+i);
	}

	else if(n < 0)
	{
		for(i = 0, temp = n * (-1); temp != 0; temp /= 10)
			str[i++] = (temp%10) + '0';
		str[i] = '-';
		str[i+1] = '\0';
		reverse(str, str+(i+1));
	}

	strcpy(strOutput, str);
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

	if (delay==50) {loadFlag=2; delay=0;}

	if(loadFlag==2)
	{
		iShowBMP(96,175,"load 2.bmp");
		delay++;
	}

	if (delay==50) {loadFlag=3; delay=0;}

	if(loadFlag==3)
	{
		iShowBMP(96,175,"load 3.bmp");
		delay++;

		if(delay==50) {loadCmpltd=1; delay=0;}
	}

}

void iTheatrical()
{
	if (loadCmpltd == 1)
	{
		iShowBMP(0, 0, "theatrical.bmp");
		iShowBMP(206, 40, "start button 1.bmp");

		if (startPressed == 1)
		{
			iShowBMP(206, 40, "start button 2.bmp");
			delay++;

			if (delay == 15)
			{
				theatricalCmpltd = 1;
				delay = 0;
			}
		}
	}
}

void iStartMenu()
{
	if (theatricalCmpltd==1)
	{
		iNewInitialize();
		iSetColor(19,109,173);
		iFilledRectangle(0,0,512,650);

		iShowBMP(0,0,"menu.bmp");
		if(newGamePressed==1)
		{
			iShowBMP(0,0,"menu new.bmp");
			delay++;

			if (delay==10)
			{
				newGamePressed=0;
				startMenuCmpltd=1;
				gameStart=1;
				delay=0;
			}
		}

		if(loadGamePressed==1)
		{
			iShowBMP(0,0,"menu load.bmp");
			delay++;

			if (delay==10)
			{
				loadGamePressed=0;
				slotSelectLG=1;
				startMenuCmpltd=1;
				//gameStart=1;
				delay=0;
				printf("slotSelectLG:%d",slotSelectLG);
			}
		}

		if(hofPressed == 1)
		{
			iShowBMP(0,0,"menu hof.bmp");

			delay++;
			if(delay==10)
			{
				hofPressed=0;
				startMenuCmpltd=1;
				hofShow=1;
				delay=0;
			}
		}

		if(creditPressed == 1)
		{
			iShowBMP(0,0,"menu credit.bmp");

			delay++;
			if(delay == 10)
			{
				creditPressed=0;
				delay=0;
				startMenuCmpltd=1;
				creditShow=1;
			}
		}

		if(instructionPressed == 1)
		{
			iShowBMP(0, 0, "menu ins.bmp");

			delay++;
			if(delay == 10)
			{
				instructionPressed = 0;
				delay = 0;
				startMenuCmpltd = 1;
				instructionShow = 1;
			}
		}

		if(exitPressed==1)
		{
			iShowBMP(0,0,"menu exit.bmp");

			delay++;
			if(delay==10)
			{
				exitPressed=0;
				delay=0;
				startMenuCmpltd=1;
				thanksShow=1;
			}
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
			if(nx>=ex1-84 && nx<=ex1-26 && dwn1==380) {score=score+10; printf("Score & life & Bomb: %d %d %d\n",score,life,bomb);}
			else if (dwn1>=380) {flagEgg = ex1; life--;}
			if(dwn1==380) {dwn1=0; egg1=0;}
		}

		if (egg2==1)
		{
			dwn2=dwn2+fall;
			if(nx>=ex2-84 && nx<=ex2-26 && dwn2==380) {score=score+10; printf("Score & life & Bomb: %d %d %d\n",score,life,bomb);}
			else if (dwn2>=380) {flagEgg = ex2; life--;}
			if(dwn2==380) {dwn2=0; egg2=0;}
		}

		if (egg3==1)
		{
			dwn3=dwn3+fall;
			if(nx>=ex3-84 && nx<=ex3-26 && dwn3==380) {if (life<maxlife) life++; printf("Score & life & Bomb: %d %d %d\n",score,life,bomb);}
			if(dwn3==380) {dwn3=0; egg3=0;}
		}

		if (egg4==1)
		{
			dwn4=dwn4+fall;
			if(nx>=ex4-84 && nx<=ex4-26 && dwn4==380) {score=score+25; printf("Score & life & Bomb: %d %d %d\n",score,life,bomb);}
			if(dwn4==380) {dwn4=0; egg4=0;}
		}

		if (egg5==1)
		{
			printf("bomb created\n");
			dwn5=dwn5+fall;
			if(nx>=ex5-84 && nx<=ex5-26 && dwn5==380) {score=score-15; printf("Score & life & Bomb: %d %d %d\n",score,life,bomb);}
			if(dwn5==380) {dwn5=0; egg5=0;}
		}

		if (score>levelDetect) {levelDetect=score;}
}

void iHenMove()
{
	if (gameStart==1)
	{
		//if (newInit==0) { iNewInitialize(); newInit=1;}
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

void showLife(int life)
{
	if(life == 15) iShowBMP(10, 549, "life 15.bmp");
	else if(life == 14) iShowBMP(10, 549, "life 14.bmp");
	else if(life == 13) iShowBMP(10, 549, "life 13.bmp");
	else if(life == 12) iShowBMP(10, 549, "life 12.bmp");
	else if(life == 11) iShowBMP(10, 549, "life 11.bmp");
	else if(life == 10) iShowBMP(10, 549, "life 10.bmp");
	else if(life == 9) iShowBMP(10, 549, "life 9.bmp");
	else if(life == 8) iShowBMP(10, 549, "life 8.bmp");
	else if(life == 7) iShowBMP(10, 549, "life 7.bmp");
	else if(life == 6) iShowBMP(10, 549, "life 6.bmp");
	else if(life == 5) iShowBMP(10, 549, "life 5.bmp");
	else if(life == 4) iShowBMP(10, 549, "life 4.bmp");
	else if(life == 3) iShowBMP(10, 549, "life 3.bmp");
	else if(life == 2) iShowBMP(10, 549, "life 2.bmp");
	else if(life == 1) iShowBMP(10, 549, "life 1.bmp");
}

void iGame()
{
	if(life <= 0)
	{
		gameOver=1;
		gameStart=0;
		//iShowBMP(0,0,"enter your name 1.bmp");
	}

	if(gameStart==1)
	{
		iResumeTimer(0);
		//if (newInit==0 ) { iNewInitialize(); newInit=1;}
		if (levelDetect<50) level=1;
		else if(levelDetect>=50 && levelDetect<1000) level=2;
		else level=3;

		if(level==1)
		{
			maxlife=10;
			iShowBMP(0,0,"back 1.bmp");
			iShowBMP(nx,0,"nest 1.bmp");
			gld=10;
			grn=8;
			red=10;

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
				if (delay==100)
				{
					levelChange2=0; delay=0; dontDraw=0;
					dx=7; range=6; hx=0; dwn1=dwn2=dwn3=dwn4=dwn5=0; life=life+3;
					maxlife=13; gld=15; grn=10; red=6; bomb=0; flagEgg=0;

					iResumeTimer(0);
				}
			}


			if (levelChange2==0)
			{
				iShowBMP(0,0,"back 2.bmp");
				iShowBMP(nx,0,"nest 1.bmp");

				hen2();

			}

		}

		else if (level==3)
		{
			if (levelChange3==1)
			{
				dontDraw=1;
				iShowBMP(0,0,"level2passed.bmp");
				delay++;
				iPauseTimer(0);
				if (delay==100)
				{
					levelChange3=0; delay=0; dontDraw=0;
					dx=8; range=6;
					maxlife=15; gld=25; grn=15; red=3; bomb = 0;
					hx=0; dwn1=dwn2=dwn3=dwn4=dwn5=0; life=life+2;
					flagEgg=0;

					iResumeTimer(0);
				}
			}

			if (levelChange3==0)
			{
				iShowBMP(0,0,"back 3.bmp");
				iShowBMP(nx,0,"nest 1.bmp");

				hen3();
			}

		}


		if (dontDraw!=1)
		{
			if (egg1==1) {iSetColor(255,255,255); iFilledEllipse(ex1,ey-dwn1,8,12);}
			if (egg2==1) {iSetColor(255,255,255); iFilledEllipse(ex2,ey-dwn2,8,12);}
			if (egg3==1) {iSetColor(255,255,0); iFilledEllipse(ex3,ey-dwn3,8,12);}
			if (egg4==1) {iSetColor(181,230,29); iFilledEllipse(ex4,ey-dwn4,8,12);}
			if (egg5==1) iShowBMP(ex5,ey-dwn5,"bomb.bmp");

			showLife(life);

			if(level == 1) iShowBMP(340,610,"level 1.bmp");
			else if(level == 2) iShowBMP(340,610,"level 2.bmp");
			else if(level == 3) iShowBMP(340,610,"level 3.bmp");

			if(flagEgg != 0)
			{
				iShowBMP(flagEgg-30, 5, "egg break.bmp");

				breakdelay++;

				if(breakdelay == 5)
				{
					flagEgg = 0;
					breakdelay = 0;
				}
			}

			iShowBMP(335,574,"score.bmp");
			ToString(score,Score);
			iSetColor(255,255,128);
			iText(450, 585, Score, GLUT_BITMAP_TIMES_ROMAN_24);
		}
	}
}


void gamePaused()
{
	iPauseTimer(0);
	//if(pauseGamePressed == 1)
	iShowBMP(0,0,"pause menu back 1.bmp");

	iShowBMP(151,433,"resume 1.bmp");
	iShowBMP(151,367,"save game 1.bmp");
	iShowBMP(151,301,"main menu 1.bmp");

	if(pauseResumePressed==1)
	{
		iShowBMP(151,433,"resume 2.bmp");

		pausedelay++;
		if(pausedelay==10) {pauseGamePressed=0; pauseResumePressed=0; gameStart=1; pausedelay=0; printf("baaaal");}
	}
	else if(pauseSavePressed==1)
	{
		iShowBMP(151,367,"save game 2.bmp");

		pausedelay++;
		if(pausedelay==10)
		{
			//saveGame=1;
			slotSelect=1;
			fileWarning = 0;
			pauseGamePressed=0;
			pauseSavePressed=0;
			pausedelay=0;
		}
	}

	else if(pauseMenuPressed==1)
	{
		iShowBMP(151,301,"main menu 2.bmp");

		pausedelay++;
		if(pausedelay==10)
		{
			iShowBMP(0,0,"pause menu back 1.bmp");

			pauseMenuPressed=0;
			pauseGamePressed=0;
			startMenuCmpltd=0;
			newInit=0;
			pausedelay=0;
		}
	}
}


void slotSelectWindowSG()
{
	iShowBMP(0,0,"save game list.bmp");

	if(fileWarning == 0)
	{
		FileToStructureSG();
		fileWarning = 1;
	}

	iSetColor(196,233,242);
	iText(195,406,save[0].savedFile, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(195,336,save[1].savedFile, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(195,267,save[2].savedFile, GLUT_BITMAP_TIMES_ROMAN_24);

	if(slot1==1 || slot2==1 || slot3==1)
	{
		slotSelect=0;
		saveGame=1;
	}
}

void saveGameWindow()
{
	iShowBMP(0,0,"save window 1.bmp");

	if(textbox == 1)
	{
		iShowBMP(0,0,"save window.bmp");
		iSetColor(227,208,117);
		iText(126,298,saveFile,GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if(warning == 1)
	{
		iSetColor(181,230,29);
		iText(95,206,"Sorry mate! No SPACE allowed!",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(85,180,"You can use underscore(_) instead.",GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if(cancelPressed==1)
	{
		iShowBMP(0,0,"save window 3.bmp");

		canceldelay++;
		if(canceldelay==5)
		{
			slot1=0;
			slot2=0;
			slot3=0;

			for (int i = 0; i < len; i++)
					saveFile[i] = 0;
			len = 0;

			warning=0;
			textbox=0;
			pauseGamePressed=1;
			saveGame=0;
			cancelPressed=0;
			canceldelay=0;
		}
	}

	if(OKpressed==1)
	{
		if(len == 0) OKpressed=0;

		else
		{
			iShowBMP(0,0,"save window 2.bmp");

			okdelay++;
			if(okdelay==5)
			{
				if(slot1==1)
				{
					strcpy(save[0].savedFile, saveFile);
					save[0].score = score;
					save[0].life = life;
					save[0].level = level;
				}
				else if(slot2==1)
				{
					strcpy(save[1].savedFile, saveFile);
					save[1].score = score;
					save[1].life = life;
					save[1].level = level;
				}
				else if(slot3==1)
				{
					strcpy(save[2].savedFile, saveFile);
					save[2].score = score;
					save[2].life = life;
					save[2].level = level;
				}

				StructureToFileSG();

				slot1=0;
				slot2=0;
				slot3=0;

				for (int i = 0; i < len; i++)
					saveFile[i] = 0;
				len = 0;

				warning=0;
				textbox = 0;
				pauseGamePressed=1;
				saveGame=0;
				OKpressed=0;
				okdelay=0;
			}
		}
	}
}

void slotSelectWindowLG()
{
	iShowBMP(0,0,"save game list.bmp");

	if(fileWarning == 0)
	{
		FileToStructureSG();
		fileWarning = 1;
	}

	iSetColor(196,233,242);
	iText(195,406,save[0].savedFile, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(195,336,save[1].savedFile, GLUT_BITMAP_TIMES_ROMAN_24);
	iText(195,267,save[2].savedFile, GLUT_BITMAP_TIMES_ROMAN_24);

	/*if(LGslot1==1)
	{
		score = save[0].score;
		life = save[0].life;
		level = save[0].level;
	}

	if(LGslot2==1)
	{
		score = save[1].score;
		life = save[1].life;
		level = save[1].level;
	}

	if(LGslot3==1)
	{
		score = save[2].score;
		life = save[2].life;
		level = save[2].level;
	}*/

	if (LGslot != 0)
	{
		score = save[LGslot - 1].score;
		life = save[LGslot - 1].life;
		level = save[LGslot - 1].level;

		if (level==2) levelChange2=0;
		else if (level==3) levelChange3=0;

		gameStart=1;
		slotSelectLG=0;
		LGslot = 0;
	}

	//LGslot1=0;
	//LGslot2=0;
	//LGslot3=0;
}

void gameOverWindow()
{
	iShowBMP(0,0,"game over 1.bmp");

	FileToStructureHOF();
	sort(hof, hof+11, comp);

	if(hof[9].score < score)
	{
		hof[10].score = score;

		gameoverdelay++;
		if(gameoverdelay == 100)
		{
			gameoverdelay=0;
			gameOver=0;
			congratsShow=1;

			//sort(hof, hof+11, comp);
		}
	}

	else
	{
		gameoverdelay++;

		if(gameoverdelay == 100)
		{
			gameoverdelay = 0;
			gameOver = 0;
			startMenuCmpltd = 0;
		}
	}
}

void showCongrats()
{
	iShowBMP(0,0,"congrats.bmp");

	congratsdelay++;
	if(congratsdelay == 150)
	{
		congratsdelay=0;
		congratsShow=0;
		nameInput=1;
	}
}

void nameForFame()
{
	iShowBMP(0,0,"name for fame 1.bmp");

	if(textbox == 1)
	{
		iShowBMP(0,0,"name for fame 2.bmp");
		iSetColor(255,231,89);
		iText(200,555,saveFile,GLUT_BITMAP_TIMES_ROMAN_24);
		strcpy(hof[10].name, saveFile);
		textboxVisited = 1;
	}

	if(warning == 1)
	{
		iSetColor(0,0,94);
		iText(176,508,"Sorry mate! No SPACE allowed!",GLUT_BITMAP_TIMES_ROMAN_24);
		iText(188,488,"You can use underscore(_) instead.",GLUT_BITMAP_HELVETICA_18);
	}

	if(textbox == 0 && textboxVisited == 1)
	{
		sort(hof, hof+11, comp);
		StructureToFileHOF();

		warning = 0;
		fileWarning = 0;
		nameInput = 0;
		textboxVisited = 0;
		hofShow = 1;
	}
}

void hallOfFameWindow()
{
	if(fileWarning == 0)
	{
		FileToStructureHOF();
		fileWarning = 1;
	}

	iShowBMP(0,0,"hof.bmp");

	iSetColor(255, 255, 128);
	iText(120,450,"Serial",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(220,450,"NAME",GLUT_BITMAP_TIMES_ROMAN_24);
	iText(320,450,"SCORE",GLUT_BITMAP_TIMES_ROMAN_24);



	iSetColor(236, 0, 0);
	ToString(hof[0].slNo, tempString);
	iText(120,400,tempString,GLUT_BITMAP_HELVETICA_18);
	iText(220,400,hof[0].name,GLUT_BITMAP_HELVETICA_18);
	ToString(hof[0].score, tempString);
	iText(320,400,tempString,GLUT_BITMAP_TIMES_ROMAN_24);



	iSetColor(0, 100, 100);
	for(int i = 1, h = 370; i < 10; i++, h -= 30)
	{
		hof[i].slNo = i + 1;
		ToString(hof[i].slNo, tempString);
		iText(120,h,tempString,GLUT_BITMAP_HELVETICA_18);
	}


	for(int i = 1, h = 370; i < 10; i++, h -= 30)
		iText(220,h,hof[i].name,GLUT_BITMAP_HELVETICA_18);


	for(int i = 1, h = 370; i < 10; i++, h -= 30)
	{
		ToString(hof[i].score, tempString);
		iText(320,h,tempString,GLUT_BITMAP_TIMES_ROMAN_24);
	}

	if(clicked == 1)
	{
		hofShow = 0;
		clicked = 0;
		startMenuCmpltd = 0;
	}
}

void showThanks()
{
	iShowBMP(0,0,"thanks.bmp");

	thanksdelay++;
	if(thanksdelay==250)
	{
		thanksdelay=0;
		exit(0);
	}
}

void showCredits()
{
	if(delay < 200)
	{
		iShowBMP(0,0,"credits.bmp");
	}

	delay++;

	if(delay >= 200 && delay < 400)
	{
		iShowBMP(0,0,"saifur sir.bmp");
	}


	if(delay == 400)
	{
		creditShow = 0;
		delay = 0;
		startMenuCmpltd=0;
	}
}

void showInstruction()
{
	iShowBMP(0, 0, "instruction.bmp");

	if(clicked == 1)
	{
		instructionShow = 0;
		clicked = 0;
		startMenuCmpltd = 0;
	}
}

void iDraw()
{
	//place your drawing codes here
	//iClear();

	if(loadCmpltd==0) iLoad();
	else if(theatricalCmpltd==0) iTheatrical();
	else if(startMenuCmpltd==0) iStartMenu();
	else if(slotSelectLG==1) slotSelectWindowLG();
	else if(gameStart==1) iGame();
	else if(pauseGamePressed == 1) gamePaused();
	else if(slotSelect == 1) slotSelectWindowSG();
	else if(saveGame == 1) saveGameWindow();
	else if(gameOver == 1) gameOverWindow();
	else if(congratsShow == 1) showCongrats();
	else if(nameInput == 1) nameForFame();
	else if(hofShow == 1) hallOfFameWindow();
	else if(thanksShow == 1) showThanks();
	else if(creditShow == 1) showCredits();
	else if(instructionShow == 1) showInstruction();
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

		else if(theatricalCmpltd==1 && startMenuCmpltd==0)

		{
			if((mx>=10 && mx<=215)&&(my>=525 && my<=590)) newGamePressed=1;
			if((mx>=295 && mx<=500)&&(my>=425 && my<=490 )) loadGamePressed=1;
			if((mx>=8 && mx<=215)&&(my>=332 && my<=398 )) instructionPressed=1;
			if((mx>=300 && mx<=500)&&(my>=230 && my<=295)) hofPressed=1;
			if((mx>=5 && mx<=210)&&(my>=145 && my<=210 )) creditPressed=1;
			if((mx>=170 && mx<=375)&&(my>=20 && my<=85 )) exitPressed=1;
		}

		else if(slotSelectLG==1)
		{
			if((mx >= 136 && mx <= 362) && (my >= 386 && my <= 445)) LGslot=1;
			if((mx >= 136 && mx <= 362) && (my >= 316 && my <= 375)) LGslot=2;
			if((mx >= 136 && mx <= 362) && (my >= 247 && my <= 306)) LGslot=3;
		}

		else if(pauseGamePressed==1)
		{
			if((mx >= 151 && mx <= 351) && (my >= 433 && my <= 477)) pauseResumePressed = 1;
			if((mx >= 151 && mx <= 351) && (my >= 367 && my <= 411)) pauseSavePressed = 1;
			if((mx >= 151 && mx <= 351) && (my >= 301 && my <= 345)) pauseMenuPressed = 1;
			//{pauseGamePressed=0; gameStart=1; iResumeTimer(0);}
		}

		else if(slotSelect==1)
		{
			if((mx >= 136 && mx <= 362) && (my >= 386 && my <= 445)) slot1=1;
			if((mx >= 136 && mx <= 362) && (my >= 316 && my <= 375)) slot2=1;
			if((mx >= 136 && mx <= 362) && (my >= 247 && my <= 306)) slot3=1;
		}

		else if(saveGame==1)
		{
			if((mx >= 122 && mx <= 392) && (my >= 290 && my <= 320)) textbox=1;
			if((mx >= 105 && mx <= 253) && (my >= 240 && my <= 277)) OKpressed=1;
			if((mx >= 259 && mx <= 407) && (my >= 240 && my <= 277)) cancelPressed=1;
		}

		else if(nameInput == 1)
		{
			if((mx >= 195 && mx <= 473) && (my >= 550 && my <= 578)) textbox=1;
		}

		else if(hofShow == 1)
		{
			if((mx >= 90 && mx <= 430) && (my >= 70 && my <= 105)) clicked = 1;
		}

		else if(instructionShow == 1)
		{
			if((mx >= 90 && mx <= 423) && (my >= 20 && my <= 57)) clicked = 1;
		}
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
	if (textbox == 1)
	{
		if (nameInput == 1 && key == '\r')
		{
			textbox = 0;

			for (int i = 0; i < len; i++)
				saveFile[i] = 0;
			len = 0;
		}

		if(key == '\b' && len > 0)
		{
			len--;
			saveFile[len] = '\0';
		}

		else if(key == 32) //SPACE pressed
		{
			if(saveGame == 1 || nameInput == 1)
			{
				warning = 1;
			}
		}

		else if(len < 10)
		{
			saveFile[len] = key;
			len++;
		}
	}

	if (key==27) //Esc Pressed
	{
		pauseGamePressed=1;
		gameStart=0;

	}

	if(gameStart==1)
	{
		if (key=='x')
		{
			iPauseTimer(0);
			gets(cheat);
			if (strcmp(cheat,"batman")==0)
			{
				life=maxlife;
				iResumeTimer(0);
			}

			else if(strcmp(cheat,"joker")==0)
			{
				score=score+100;
				iResumeTimer(0);
			}
		}
	}

	if(key == 'q')
	{
		theatricalCmpltd=1;
		startMenuCmpltd=1;
		gameStart=0;
		gameOver=0;
		congratsShow=0;
		nameInput=0;
		hofShow=0;
		thanksShow=1;
	}
	//place your codes for other keys here
	//if(key=='r') {pauseGamePressed=0; gameStart=1; iResumeTimer(0);}
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

	iInitialize(512,650, "eggy peggy");

	//iSetTimer(50,iHenMove);

	return 0;
}

//============================================================================
// Name        : 1.cpp
// Author      : Zoro
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <conio.h>
using namespace std;

bool gameOver;
const int width =20;
const int height =20;
int x,y,fruitX,fruitY,score=0;
int tailX[100],tailY[100],nTails;

enum direction{
	stop=0,l,r,up,down
};
direction dir;
void setUp(){
gameOver=false;
dir=stop;

x=width/2;

y=width/2;

fruitX=rand()%width;
fruitY=rand()%height;
score=0;



}

void draw(){
	system("clear");

	for(int i=0;i<width;i++)cout<<'#';
	cout<<endl;

	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){

			if(j==0||j==width-1)cout<<"#";
			else if(i==y&&j==x)cout<<"O";
			else if(i==fruitY && j==fruitX)cout<<"F";
			else {
				bool print=false;
				for(int snake=0;snake<nTails;snake++){
					if(i==tailY[snake]&&j==tailX[snake]){
						cout<<'o';
						print =true;
					}
				}if(!print)cout<<" ";
			}

		}
		cout<<endl;
	}

	for(int i=0;i<width;i++)cout<<'#';
		cout<<endl;
cout<<"Score: "<<score<<endl;

}
void input(){
if(_kbhit()){
	switch(getch()){
	case 'a':
		dir=l;
		break;
	case 's':
		dir=down;
		break;
	case 'w':
		dir=up;
		break;
	case 'd':
		dir=r;
		break;

	case 'x':
		gameOver=true;
		break;


	}

}



}

void logic(){
	int prevX=tailX[0];
	int prevY=tailY[0];


	tailX[0]=x;
	tailY[0]=y;

	int prev2X,prev2Y;
	for(int i=1;i<nTails;i++){
		prev2X=tailX[i];
		prev2Y=tailY[i];

		tailX[i]=prevX;
		tailY[i]=prevY;

		prevX=prev2X;
		prevY=prev2Y;
	}



switch (dir){
case l:
	x--;
	break;
case r :
x++;
break;

case up :
	y--;
	break;
case down:
	y++;
	break;

default :
	break;


}



if(x<0||x>width||y<0||y>height)gameOver=true;

for(int i=0;i<nTails;i++){
	if(x==tailX[i]&&y==tailY[i])gameOver=true;
}

if(x==fruitX&&y==fruitY)
	{
	score+=10;

fruitX=rand()%width;
fruitY=rand()%height;
if(fruitX<=0||fruitY<=0){
	fruitX=rand()%width;
	fruitY=rand()%height;
}
nTails++;
	}
}








int main() {

	setUp();

	while(!gameOver){
		draw();
		input();
		logic();
		usleep(200000);
	}
cout<<"GAME OVER YOUR FINAL SCORE IS : "<<score<<endl;

	return 0;
}

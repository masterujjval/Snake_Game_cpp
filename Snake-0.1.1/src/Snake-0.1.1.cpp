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
	system("clear");//change it to "cls" if you are using windows.

	for(int i=0;i<width;i++)cout<<'#';
	cout<<endl;

	for(int i=0;i<height;i++){
		for(int j=0;j<width;j++){

			if(j==0||j==width-1)cout<<"#";
			else if(i==y&&j==x)cout<<"O"; //x and y initialising the position of the snake
			else if(i==fruitY && j==fruitX)cout<<"F";
			else {
			
				bool print=false;
				for(int snake=0;snake<nTails;snake++){
					if(i==tailY[snake]&&j==tailX[snake]){ //adding size to snake if it eats the fruit
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
if(_kbhit()){ //_kbhit is a method of conio.h library it returns if the key on keyboard is pressed or not
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
	int prevX=tailX[0];   //keeping track of the previous 'o' added to snake
	int prevY=tailY[0];    //keeping track of the previous 'o' added to snake 


	tailX[0]=x;
	tailY[0]=y;

	int prev2X,prev2Y; //taking these two variables to swap elements and to keep track of the previous 'o'
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
	if(x==tailX[i]&&y==tailY[i])gameOver=true; //if snake touch its tail gameover
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
nTails++; //this defines the size or node that will be added to snake
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

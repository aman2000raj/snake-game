#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
const int hight = 25;
const int width = 45;
bool gameover;
int x,y,ntail=0;
int fruitX, fruitY, score;
int tailX[100],tailY[100];
enum Direction{ LEFT , RIGHT , UP , DOWN , STOP=0 };
Direction dir;
void setup(){
	srand(time(NULL));
	dir = STOP;
	x = width/2;
	y = hight/2;
	fruitX = rand()%width-1;
	fruitY = rand()%hight-1;
	score = 0;
	gameover = false;
}
void draw(){
	Sleep(10);
	system("cls");
	cout << "score : "<< score << endl;
	for(int i=0; i<=hight;i++){
		for(int j=0; j<=width; j++){
			if((i == 0 || j == 0) || (j == width || i == hight)){
				cout << "X";
			}
			else if(x == j && y ==i){
				cout << "@";
			}
			else if(fruitX == j && fruitY == i){
				cout << "Q";
			}
			else{
				bool display = false;
				for(int k=0; k<ntail; k++){
				//	bool display = false;
					if(tailX[k] == j && tailY[k] == i){
						cout << "O";
						display = true;
					}
				//	if(!display){
				//		cout << " ";
					}
				if(!display){
					cout << " ";
				}	 
			//	cout <<" ";
			}
		}
		cout << endl;
	}
}
void input(){
	if(_kbhit()){
		switch(_getch()){
			case 'a':
				if(dir != RIGHT){
					dir = LEFT;
			}
				break;
			case 'w':
				if(dir != DOWN){
					dir = UP;
			}
				break;
			case 'd':
				if(dir != LEFT){
					dir = RIGHT;
			}
				break;
			case 's':
				if(dir != UP){
					dir = DOWN;
			}
				break;
			case'x':
			//	dir = STOP;
				gameover = true;
				break;
		}
	}
}
void logic(){
	for(int i=ntail-1; i>0; i--){
		tailX[i]=tailX[i-1];
		tailY[i]=tailY[i-1];
		//if(x == tailX[i] && tailY[i]){
		//	gameover = true;
		//}
	}
	tailX[0]=x;
	tailY[0]=y;
	switch(dir){
		case LEFT:
		//	if(dir == RIGHT){
		//		break;
		//	}
		//	else{
				x--;
				break;
		//	}
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		case RIGHT:
			x++;
			break;
		default:
			break;
	}
	if(x >= width || x <= 0 || y >= hight || y <=0){
		gameover=true;
	}
	if(x == fruitX && y == fruitY){
		score += 10;
		fruitX = rand()%width-1;
		fruitY = rand()%hight-1;
		ntail++;
	}
	for(int k=0; k<ntail; k++){
		if(x == tailX[k] && y == tailY[k]){
			gameover = true;
		}
	}

}
int main(){
	setup();
	while(!gameover){
		draw();
		input();
		logic();
		Sleep(20);
	}
	system("cls");
	cout << "sorry " << endl << "Game Over! " << endl << 
		    "your score is : " << score << endl; 
	system("pause");
	return 0;
}

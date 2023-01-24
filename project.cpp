#include <bits/stdc++.h>
using namespace std;
char board[7][7] = {
					{' ', ' ', ' ',' ', ' ', ' ', ' '}, // 1
					{' ', ' ', ' ',' ', ' ', ' ', ' '}, // 2
					{' ', ' ', ' ',' ', ' ', ' ', ' '},  //3
					{' ', ' ', ' ',' ', ' ', ' ', ' '}, // 4
					{' ', ' ', ' ',' ', ' ', ' ', ' '}, // 5
					{' ', ' ', ' ',' ', ' ', ' ', ' '},  //6
					{' ', ' ', ' ',' ', ' ', ' ', ' '}}; //7
char xy[7] = { 'a', 'b', 'c', 'd' , 'e', 'f', 'g'};
string currentPlayer = "AI";
char AI_P = 'A';
char AI_R = 'R';
char HUMAN_R = 'R';
char HUMAN_P = 'P';
char H_P = 'H'; 
int loop_ai,turn=0,tr=0;
char chr_move_x,chr_move_x2,chr_remove_x;
int x_chr,x_chr2,x_chr3,move_x, move_y, move_y2,move_x2,remove_x,remove_y,remove_x2, remove_y2;
void displayBoard() {
	cout << "     1    2    3    4    5    6    7\n";
	cout << "  -------------------------------------\n";
	char abc[7] = { 'a', 'b', 'c', 'd' , 'e', 'f', 'g'};
	for (int i = 0; i < 7; i++) {  //left
		for (int j = 0; j < 7; j ++) {  //right
			if (j == 0)
				cout << abc[i] << " || " << board[i][j] << " ";
			else
				cout << "|| " << board[i][j] << " ";
		}
		cout << "||\n";
		cout << "  -------------------------------------\n";
	}
}
void a_g(int pl){//print choosed remove move cells/convert int to char/conver int to char,checks out of range/
	int x,x2,y,y2,donothing;
	if(move_x==0){x=0;}if(move_x2==1){x2=0;} if(remove_x ==1){y=0;}if(remove_x2 ==0){y2=0;}
	if(move_x==1){x=1;}if(move_x2==2){x2=1;} if(remove_x ==2){y=1;}if(remove_x2 ==1){y2=1;}
	if(move_x==2){x=2;}if(move_x2==3){x2=2;} if(remove_x ==3){y=2;}if(remove_x2 ==2){y2=2;}
	if(move_x==3){x=3;}if(move_x2==4){x2=3;} if(remove_x ==4){y=3;}if(remove_x2 ==3){y2=3;}
	if(move_x==4){x=4;}if(move_x2==5){x2=4;} if(remove_x ==5){y=4;}if(remove_x2 ==4){y2=4;}
	if(move_x==5){x=5;}if(move_x2==6){x2=5;} if(remove_x ==6){y=5;}if(remove_x2 ==5){y2=5;}
	if(move_x==6){x=6;}if(move_x2==7){x2=6;} if(remove_x ==7){y=6;}if(remove_x2 ==6){y2=6;}

	if(pl==0){cout<<"AI: "<<"Turn: "<<turn<<" Muve:"<< xy[x]<<move_y+1<<" Remuve: "<<xy[y2]<<remove_y2+1<<endl;  }
	
	if(pl==1){cout<<"Player1: "<<"Turn: "<<turn<<" Muve: "<<xy[x]<<move_y<<" Remuve: "<<xy[y]<<remove_y<<endl;}
	if(pl==11){cout<<"Player1: "<<"Turn: "<<turn<<" Muve: "<<xy[x2]<<move_y2<<" Remuve: "<<xy[y]<<remove_y<<endl;}
	if(pl==4){
	if(chr_move_x=='a'){x_chr=1;} if(chr_move_x2=='a'){x_chr3=1;}                         
	if(chr_move_x=='b'){x_chr=2;} if(chr_move_x2=='b'){x_chr3=2;}                             
	if(chr_move_x=='c'){x_chr=3;} if(chr_move_x2=='c'){x_chr3=3;}                           
	if(chr_move_x=='d'){x_chr=4;}if(chr_move_x2=='d'){x_chr3=4;}                               
	if(chr_move_x=='e'){x_chr=5;} if(chr_move_x2=='e'){x_chr3=5;}                               
	if(chr_move_x=='f'){x_chr=6;} if(chr_move_x2=='f'){x_chr3=6;}                              
	if(chr_move_x=='g'){x_chr=7;}if (chr_move_x2=='g'){x_chr3=7;}                              
	else{move_x=20;move_x2=20;}
	move_x=x_chr;move_x2=x_chr3;	
	if(chr_remove_x=='a'){x_chr2=1;} 
	if(chr_remove_x=='b'){x_chr2=2;} 
	if(chr_remove_x=='c'){x_chr2=3;} 
	if(chr_remove_x=='d'){x_chr2=4;} 
	if(chr_remove_x=='e'){x_chr2=5;}
	if(chr_remove_x=='f'){x_chr2=6;} 
	if(chr_remove_x=='g'){x_chr2=7;}  
	else{remove_x=20;}
	remove_x=x_chr2;
	}
	
}		
void print_r(){//print removable cells with control 
//updating cells on the removable cells board
if (board[move_x2 - 1][move_y2 - 1] == ' ' ){board[move_x2 - 1][move_y2 - 1] = HUMAN_P;}	
if (board[remove_x - 1][remove_y - 1] == ' '){board[remove_x - 1][remove_y - 1] = HUMAN_R;}
//if (board[move_x - 1][move_y - 1] == ' ' ){board[move_x - 1][move_y - 1] = AI_P;}	
//if (board[remove_x2 - 1][remove_y2 - 1] == ' '){board[remove_x2 - 1][remove_y2 - 1] = AI_R;}
	cout<<endl<<endl<< "Removable Cells: " << endl;
		for(int i = 0;i < 7;i++){
			for(int j =0;j < 7;j++){
				if(board[i][j] == ' '){
					cout<< xy[i] << (j+1)<< " ";
				}
			}
			cout << endl;
		}
		
	
		//if not in range go again
	
	cout << endl;
}
void print_move2(){//print movable cells but no control
	cout << "Cells to move:"<<endl;
    for(int i = 0;i < 3;i++){
        if((board[move_x2 - 1][move_y2+i]) == ' ' ){
			cout<< xy[move_x2-1] << (move_y2+i) << " ";
        }
    }
    cout << endl;
    for(int i = 0;i < 3;i++){
        if((board[move_x2][move_y2+i])== ' '){
			cout<< xy[move_x2] << (move_y2+i) << " ";
	}
    }
    cout << endl;
    for(int i = 0;i < 3;i++){
        if((board[move_x2+1][move_y2+i] )== ' '){	
			cout<< xy[move_x2+1] << (move_y2+i) << " ";
        }
    }
	cout << endl;

		static bool onced = [](){
		board[move_x2][move_y2]= ' ',' ';
		return true;
		}();

	
}
void check_win(){
	
	
	
}
void humanTurn() { //Player move remove input,out of range control
	int p;
	print_move2();
	board[move_x2-1][move_y2-1]= ' ',' ';
	cout << "\nPlayer "<< tr <<" Turn:";
	up:cout << "\nEnter your position(P): \n\tRow(P) : ";
		cin >> chr_move_x2;p=4;
		a_g(p);
		cout << "\tCol(P) : ";
		cin >> move_y2;
		if (board[move_x2 - 1][move_y2 - 1] == ' '){board[move_x2 - 1][move_y2 - 1] = HUMAN_P;}
		print_r();
		static bool onced2 = [](){
		board[move_x][move_y]= ' ',' ';
		return true;
		}();
		re:cout << "\nEnter your position(R): \n\tRow(R) : ";
		cin >> chr_remove_x; p=4;
		turn++;a_g(p);
		cout << "\tCol(R) : ";
		cin >>remove_y;
	if (move_x2 > 8 || move_y2> 8 || remove_x > 8 || remove_y > 8) {
		cout << "\nOut of Bounds!! Please try enter again ";
		goto up;
	}	
		if (board[remove_x - 1][remove_y - 1] == ' '){
			board[move_x2 - 1][move_y2 - 1] = HUMAN_P;
			board[remove_x - 1][remove_y - 1] = HUMAN_R;
			currentPlayer = "AI";int pl=0;
		
	}
	else{
		cout<<endl<<"Invalid Move......Try different move";
		board[move_x2-1][move_y2-1]= ' ',' ';
		goto up;
	}
	
}

int aiMinimax(int depth, bool isMaximizing, char player) { //minimax function,ai move and remove
	//add win state here 
	if (isMaximizing) {
		int best_score = -99999;
		int score;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if ((board[i][j] == ' ')){
					if(loop_ai==1){
						board[i][j] = AI_P;
						score = aiMinimax(depth + 1, false, HUMAN_P);
					}
					if(loop_ai==2){
					board[i][j] = AI_R;
					score = aiMinimax(depth + 1, false, HUMAN_R);
				}
				board[i][j] = ' ';
				best_score = max(best_score, score);
			}
			}
		}
		return best_score;	
	}
	else {
		int best_score = INT_MAX;
		int score;
		for (int i = 0; i < 3; i ++) {
			for (int j = 0; j < 3; j ++) {
				if ((board[i][j] == ' ')) {
					if(loop_ai==1){
						board[i][j] = AI_P;
						score = aiMinimax(depth + 1, false, HUMAN_P);
					}
					if(loop_ai==2){
					board[i][j] = AI_R;
					score = aiMinimax(depth + 1, false, HUMAN_R);
				}	
			board[i][j] = ' ';
			best_score = min(best_score, score);
			}
			}	
		}
		return best_score;
	}
/*
function minimax(board, depth, isMaximizingPlayer):

    if current board state is a terminal state :
        return value of the board
    
    if isMaximizingPlayer :
        bestVal = -INFINITY 
        for each move in board :
            value = minimax(board, depth+1, false)
            bestVal = max( bestVal, value) 
        return bestVal

    else :
        bestVal = +INFINITY 
        for each move in board :
            value = minimax(board, depth+1, true)
            bestVal = min( bestVal, value) 
        return bestVal 
*/
}

/*
function isMovesLeft(board):
    for each cell in board:
        if current cell is empty:
            return true
    return false
*///corresponds to ailoop and ailoop2

void ailoop(){  //ai move function 'A'
board[move_x][move_y]= ' ',' '; //can delete previos Ai move step but stucks in same cell 
	loop_ai=1;
	int score = 0;
	int best = -99999999;
	if(move_x<3){ //if(remove_x<3){
		for (int i = 0; i < 3; i ++) {
			for (int j = 0; j < 7; j ++) {
			if (board[move_x+i][move_y+1+j] == ' ' ) {//more strict movement
				board[move_x+i][move_y+1+j] = AI_P;
				score = aiMinimax(0, false, AI_P);
				board[move_x+i][move_y+1+j] = ' ';
				if (score > best) {
					best = score;
					move_x= move_x+i;
					move_y= move_y+1+j;
				}
			}				
		}
	}
	/*for (int i = 0; i < 3; i ++) {
		for (int j = 7; j > 0; j --) {
		if (board[move_x+i][move_y+1+j] == ' ' ) {//more random movements
			board[move_x+i][move_y+1+j] = AI_P;
			score = aiMinimax(0, false, AI_P);
			board[move_x+i][move_y+1+j] = ' ';
			if (score > best) {
				best = score;
				move_x= move_x+i;
				move_y= move_y+1+j;
			}
		}				
		}
	}*/
	
	}
	
	if(move_x>3){//if(remove_x>3){
	
	for (int i = 3; i < 7; i ++) {
		for (int j = 0; j < 7; j ++) {
		if (board[move_x+i][move_y+1+j] == ' ' ) {
			board[move_x+i][move_y+1+j] = AI_P;
			score = aiMinimax(0, false, AI_P);
			board[move_x+i][move_y+1+j] = ' ';
			if (score > best) {
				best = score;
				move_x= move_x+i;
				move_y= move_y+1+j;
			}
		}				
	}
	}
	
/*	for (int i = 3; i < 7; i ++) {
		for (int j = 7; j > 0; j --) {
		if (board[move_x+i][move_y+1+j] == ' ' ) {
			board[move_x+i][move_y+1+j] = AI_P;
			score = aiMinimax(0, false, AI_P);
			board[move_x+i][move_y+1+j] = ' ';
			if (score > best) {
				best = score;
				move_x= move_x+i;
				move_y= move_y+1+j;
			}
		}				
	}
	}*/
	
	
	}
		
	board[move_x][move_y] = AI_P;  
}
void ailoop2(){ //ai remove function 'R'
	loop_ai=2;
	int score = 0;
	int best = -99999999;
	if(move_x2>3){ // second half of desk
	for (int i = 7; i >3; i --) {//y
		for (int j = 0; j < 3; j ++) {//x
		if (board[move_x2][move_y2-1+j] == ' ' ) {//higher cells
			board[move_x2][move_y2-1+j] = AI_R;
			score = aiMinimax(0, false, AI_R);
			board[move_x2][move_y2-1+j] = ' ';
			if (score > best) {
				best = score;
				remove_x2 = move_x2;
				remove_y2= move_y2-1+j;
			}
		}				
	}
	}	
	for (int i = 7; i >3; i --) {//y
		for (int j = 0; j < 3; j ++) {//x
		if (board[move_x2-2][move_y2-1+j] == ' ' ) {//lower cells
					board[move_x2-2][move_y2-1+j] = AI_R;
					score = aiMinimax(i, false, AI_R);
					board[move_x2-2][move_y2-1+j] = ' ';
					if (score > best) {
						best = score;
						remove_x2 = move_x2-2;
						remove_y2= move_y2-1+j;
					}
		}
	}}
	for (int i = 7; i >3; i --) {  //y
		for (int j = 0; j < 3; j ++) {//x
			if (board[move_x2-1][move_y2-2+j] == ' ' ) { //middle/left cells 
				board[move_x2-1][move_y2-2+j] = AI_R;
				score = aiMinimax(0, false, AI_R);
				board[move_x2-1][move_y2-2+j] = ' ';
				if (score > best) {
					best = score;
					remove_x2 = move_x2-1;
					remove_y2= move_y2-2+j;
				}
			}
		}
	}	
	for (int i = 7; i >3; i --) {  //y
		for (int j = 0; j < 3; j ++) {//x
			if (board[move_x2-1][move_y2-1+j] == ' ' ) {//middle/right cells 
				board[move_x2-1][move_y2-1+j] = AI_R;
				score = aiMinimax(0, false, AI_R);
				board[move_x2-1][move_y2-1+j] = ' ';
				if (score > best) {
					best = score;
					remove_x2 = move_x2-1;
					remove_y2= move_y2-1+j;
				}
			}				
		}
		}
	}
	if(move_x2<3){ // first half of desk
	
	for (int i = 0; i <3; i ++) { //higher cells //y
		for (int j = 0; j< 3; j ++) {//x
		if (board[move_x2][move_y2-1+j] == ' ' ) {
				board[move_x2][move_y2-1+j] = AI_R;
				score = aiMinimax(0, false, AI_R);
				board[move_x2][move_y2-1+j] = ' ';
				if (score > best) {
					best = score;
					remove_x2 = move_x2;
					remove_y2= move_y2-1+j;
				}
			}				
		}
	}		
	for (int i = 7; i >3; i --) {//lower cells //y
		for (int j = 0; j < 3; j ++) {//x
			if (board[move_x2-2][move_y2-1+j] == ' ' ) {
				board[move_x2-2][move_y2-1+j] = AI_R;
				score = aiMinimax(i, false, AI_R);
				board[move_x2-2][move_y2-1+j] = ' ';
				if (score > best) {
					best = score;
					remove_x2 = move_x2-2;
					remove_y2= move_y2-1+j;
				}
			}
		}
	}	
	for (int i = 7; i >3; i --) {  //middle/left cells  //y
		for (int j = 0; j < 3; j ++) {//x
			if (board[move_x2-1][move_y2-2+j] == ' ' ) {
				board[move_x2-1][move_y2-2+j] = AI_R;
				score = aiMinimax(0, false, AI_R);
				board[move_x2-1][move_y2-2+j] = ' ';
				if (score > best) {
					best = score;
					remove_x2 = move_x2-1;
					remove_y2= move_y2-2+j;
				}
		}				
	}
	}		
	for (int i = 7; i >3; i --) {  //middle/right cells  //y
		for (int j = 0; j < 3; j ++) {//x
			if (board[move_x2-1][move_y2-1+j] == ' ' ) {
				board[move_x2-1][move_y2-1+j] = AI_R;
				score = aiMinimax(0, false, AI_R);
				board[move_x2-1][move_y2-1+j] = ' ';
				if (score > best) {
					best = score;
					remove_x2 = move_x2-1;
					remove_y2= move_y2-1+j;
				}
			}				
		}
	}
	}
	board[remove_x2][remove_y2] = AI_R;  
	}
void AI_H(){ //human and ai decisions here
	while (true) {
		tr=1;
		move_x=0;
		move_y=3;
		board[move_x][move_y] = 'A';
		move_x2=7-1;
		move_y2=4-1;
		board[move_x2][move_y2] = 'P';
		displayBoard();
		up:humanTurn();
		int pr=11;a_g(pr);
		cout << "\n AI's Turn...\n\n";
		turn++;
		//board[move_x][move_y]= ' ',' ';
		ailoop(); //a
		ailoop2(); //r
		int pl2=0;a_g(pl2);
		static bool onced2 = [](){
		board[0][3]= ' ',' ';
		return true;
		}();

		displayBoard();
		currentPlayer = "HUMAN";
		goto up; 
	}
	
}
int main() { // TERMINAL MENU
	int choice;
	cout<<"-------------------------Board Game-----------------------------------------------------";
	up:cout<<endl<<"SELECT : 1->AI&Human 0->Exit: ";
	cin>>choice;
	if(choice == 1){AI_H();}
	
	if(choice == 0 ){cout<<endl<<"Exiting...  "<<endl;exit(0);}
	
	else {cout<<endl<<"Try again!...   "<<endl;goto up;}
	
}
/*
	A --> ai's move symbol
	R --> ai's remove symbol
	P --> player's move symbol
	R --> player's remove symbol
*/
//TERMINAL BASED AI PROJECT


/*
move Pllayer          ✔
remove Player         ✔
remove of prev step P ✔
print movable cells   ✘ 
print removable cells ✔
move in range         ✘      control it via if       ✘
remove from all       ✔      desk control it via if ✔

move ai              ✔
remove ai            ✔
remove of prev stepA ✘
ai move action       ✘  ailoop1
ai remove action     ✔  ailoop2

win state            ✘
*/
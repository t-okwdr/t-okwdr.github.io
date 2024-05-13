/*
10 - project - video game(s)
Author: Taya
Date: Feb 29, 2024
Create a video game from the following list (marks will be given based on difficulty level of coding)

Bonuses: 
Color (All games)
Message boxes (minesweeper, and SOS)
Recursive AI (Checkers) - It was not fun
two extra fully complete games (one hard, one medium)
clickable menus and game (minesweeper)
*/
#include <iostream> 	// include library for input and output
#include <math.h>		// include library for math functions
#include <windows.h>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>		// include library for changing text modes
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <thread>
#include <fstream>		// include library for reading and writing files
using namespace std;	// Makes life slightly easier


void Center_text(string text);		//Declares a string function to output any text in the center of the screen

//Checkers Functions
void checkers(int gamemode);
char reverse_char(char board[8][8],int x, int y);
int generate_moves(char board[8][8], char color);
void create_checkers(char board[8][8]);
bool checkers_move_from_check(string move, char board[8][8], char color);
int checkers_move_to_check(string move, char board[8][8], char color, int x1, int y1);
int negamax(char board[8][8], int depth, int color);
int multimax(char board[8][8], int depth, int color, string move_from);
void save_game(char board[8][8], int turn, int capture, int red_cpu, int black_cpu);
int load_settings(int option);
char load_board(int x, int y);
/* test game (Checkers)
A6 B5 A6 B5 B5 A4 B5 A4 B7 A6 B7 A6 A8 B7 A8 B7 E6 F5 E6 D5 F5 D3 F7 D5 A4 C2 E8 G6 F7 E6 A4 C2 E8 G6 A6 B5 A6 B5 B5 A4 B5 A4 A4 C2 A4 C2 G8 E6 C6 B5 C2 D1 B7 C6 C6 B5 H7 G6 D1 C2 E6 F5 B5 D3 D7 F5 C2 A4 F5 G4 A4 C6 G8 H7 H7 G6 H7 G6 C6 B5 G6 F5 B5 D3 C8 B7 B7 A6 B7 A6 D5 E4 C6 E4 C2 D7 E6 C2 D1 G6 H5 B5 C4 E6 G4 A6 C4 D3 C2 D1 C2 C2 B1 C2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A6 B5 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 C4 B3 C8 B7 B3 C2 B7 A6 C2 B1 A2 B3 A2 B3 H5 G4 B1 C2 B5 C4 C2 D1 C4 D3 B3 A4 D3 C2 A4 C6 B3 A4 D1 C2 C2 B1 C2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 A6 B5 B1 C2 B1 A2 C6 B5 A4 B3 C2 B3 A2 B1 B3 A2 B1 A2 B5 C6 A2 B1 C6 D7 B3 A4 A2 B1 A4 B3 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 B3 C4 B1 C2 C4 D5 C2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 D7 C6 D5 C4 C6 B5 B5 A4 B5 C6 A2 B3 C6 D7 B3 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B3 A4 B3 B3 C2 B3 C2 C2 D1 A2 B1 D1 C2 B1 A2 C2 B1 A2 B1 D7 C6 C2 D1 C6 B5 B1 A2 B1 A2 D1 C2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B5 A6 B1 A2 A6 B5 A2 B1 B5 A6 C4 D3 A6 B7 D3 E2 B7 C6 E2 G4 B1 C2 G4 H5 C2 D3 H5 G6 D3 E4 B1 A2 E4 D5 G6 F5 D5 B3 C2 B1 B3 C2 A2 B3 C2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 B3 C2 A2 B1 C2 B1 B1 A2 A2 B3 A2 B3 B1 C2 B3 C2 C2 D1 C2 D1 B3 A2 D1 C2 A2 B1 C2 B1 B1 A2 B1 A2 D1 C2 A2 B1 A2 B1 B1 C2 B1 A2 C2 D1 A2 B3 D1 C2 B3 A4 C2 B3 A4 B3 B3 A4 C2 D3 A4 B3 B3 A4 B3 A2 D3 C2 A2 B1 C2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 C2 A2 B3 C2 D1 B3 C2 D1 C2 C2 B1 C2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B1 B1 A2 B1 A2 A2 B1 A2 B3 B1 C2 B3 C2 C2 D1 A4 B5 D1 E2 B5 C6 E2 G4 C2 B3 G4 F5 B3 D5
*/

//Minesweeper Functions
struct name_time		//Define a structure for the combining the name and score for the leaderboard
{
	int time;			//Declares an int for the users score
	string name;		//Declares a string for the users name on the leaderboard
};
vector<vector <char>> temp_vis;
vector <name_time> easy(1);		//Declares a global vector of the structure type for holding a leaderboard score
vector <name_time> medium(1);		//Declares a global vector of the structure type for holding a leaderboard score
vector <name_time> hard(1);		//Declares a global vector of the structure type for holding a leaderboard score
int depth=0;
int seconds;
bool stop=false;
bool first=true;
bool operator<(const name_time&lhs, const name_time&rhs);			//Declares a bool function with two parameters that helps sorting the leaderboard values
void minesweeper();
void open_spots(char fake_vis[][50], int fake_board[][50], int rows, int cols, int x, int y);
void timer(int cols);
void mine_counter(int mines);
void create_minesweeper(char fake_vis[][50], int fake_board[][50], int rows, int cols, int mines);
string unicode_num(int num);
string ascii_num(int num, int row);
void show_score_minesweeper();			//Declares a void function with no parameters for showing the leaderboard
void add_score_minesweeper(int time, int difficulty);		//Declares a void functions with an int parameter for adding a score to the leaderboard
VOID ErrorExit(LPCSTR);
HANDLE hStdin;
DWORD fdwSaveOldMode;
//Event type
#define event_type irInBuf[i].EventType
//Keyboard
#define ker irInBuf[i].Event.KeyEvent
#define key ker.wVirtualKeyCode
#define key_pressed ker.bKeyDown
//Mouse
#define mer irInBuf[i].Event.MouseEvent
#define mouse_event mer.dwEventFlags
#define mouse_state mer.dwButtonState
#define left_click FROM_LEFT_1ST_BUTTON_PRESSED
#define middle_click FROM_LEFT_3RD_BUTTON_PRESSED
#define right_click RIGHTMOST_BUTTON_PRESSED
#define MouseX mer.dwMousePosition.X
#define MouseY mer.dwMousePosition.Y

//SOS Functions
struct name_points		//Define a structure for the combining the name and points for the leaderboard (SOS)
{
	double points;			//Declares an double for the users points
	string name;		//Declares a string for the users name on the leaderboard
};
vector <name_points> beginner(1);		//Declares a global vector of the structure type for holding a leaderboard score (SOS)
vector <name_points> intermediate(1);		//Declares a global vector of the structure type for holding a leaderboard score (SOS)
vector <name_points> expert(1);		//Declares a global vector of the structure type for holding a leaderboard score (SOS)
int sidebars=0;		//Declares a global int for enabling extra sidebars and initializes it to 0
double p1_points,p2_points;		//Declares two doubles for each players points
int total_points;		//Declares a int for the tootal amount of points in a game
int color[50][50];		//Declares a 2D int array for which player colored a piece		
bool operator<(const name_points&lhs, const name_points&rhs);			//Declares a bool function with two parameters that helps sorting the leaderboard values
void SOS();		//Declares a void function for SOS
void create_SOS(char fake_board[][50], int rows, int cols, int turn);		//Declares a void function for creating the SOS board with parameters for the board and size
bool points(char fake_board[][50], int rows, int cols, int turn);	//Declares a bool function for counting points with parameters for the board, size and turn
string to_move(int x, int y, char letter);		//Declares a string function to convert the AI's board position and letter into a string
bool spot_check(string spot, int rows, int cols);		//declares a bool function to check if a move is legal
void show_score_SOS();			//Declares a void function with no parameters for showing the leaderboard
void add_score_SOS(double score, int difficulty);		//Declares a void functions with a double parameter and difficulty for adding a score to the leaderboard


int main(){
	int menu_choice;
	int game_choice;
	int rules_choice;
	SetConsoleOutputCP(CP_UTF8);		//Sets the console mode to U8 (allows unicode & emojis)
	srand(time(0));			//Initializes the randomization seed 
	do{
		game_choice=0;
		rules_choice=0;
		Center_text("   _____  _                  _                                 _____   ____    _____ \n");
		Center_text("  / ____|| |                | |                               / ____| / __ \\  / ____|\n");
		Center_text(" | |     | |__    ___   ___ | | __ ___  _ __  ___            | (___  | |  | || (___  \n");
		Center_text(" | |     | '_ \\  / _ \\ / __|| |/ // _ \\| '__|/ __|            \\___ \\ | |  | | \\___ \\ \n");
		Center_text(" | |____ | | | ||  __/| (__ |   <|  __/| |   \\__ \\  _         ____) || |__| | ____) |\n");
		Center_text("  \\_____||_| |_| \\___| \\___||_|\\_\\\\___||_|   |___/ ( )       |_____/  \\____/ |_____/ \n");
		Center_text("                                    ___            |/                                \n");
		Center_text("                                   ( _ )                                             \n");
		Center_text("                                   / _ \\/\\                                           \n");
		Center_text("    __  __  _                     | (_>  <                                           \n");
		Center_text("   |  \\/  |(_)                     \\___/\\/                                           \n");
		Center_text("   | \\  / | _  _ __    ___  ___ __      __ ___   ___  _ __    ___  _ __              \n");
		Center_text("   | |\\/| || || '_ \\  / _ \\/ __|\\ \\ /\\ / // _ \\ / _ \\| '_ \\  / _ \\| '__|             \n");
		Center_text("   | |  | || || | | ||  __/\\__ \\ \\ V  V /|  __/|  __/| |_) ||  __/| |                \n");
		Center_text("   |_|  |_||_||_| |_| \\___||___/  \\_/\\_/  \\___| \\___|| .__/  \\___||_|                \n");
		Center_text("                                                     | |                             \n");
		Center_text("                                                     |_|                             \n");
		
		cout<<"\n\nWhat would you like to do (Enter 1, 2, etc.): ";		//Tells the user what they can do
		cout<<"\n\tPlay Checkers -------- 1";			//Outputs the option of removing a contact
		cout<<"\n\tPlay Minesweeper ----- 2";			//Outputs the option of removing a contact
		cout<<"\n\tPlay SOS ------------- 3";			//Outputs the option of searching for a contact
		cout<<"\n\tQuit ----------------- 4\n";			//Outputs the option of editing a contact
		cin>>menu_choice;
		while (menu_choice<1 or menu_choice>4){
			cout<<"Invalid Input! Retry.\n";			//Tells the user that the input was wrong
			cout<<"What would you like to do (Enter 1, 2, etc.): ";		//Tells the user what they can do
			cin>>menu_choice;		//Prompts the user to input
		}
		cout<<flush;
		system("CLS"); 
		if (menu_choice==1){
			do{
				Center_text("  ,----..    ,---,                              ,-.                                 \n");
				Center_text(" /   /   \\ ,--.' |                          ,--/ /|                                 \n");
				Center_text("|   :     :|  |  :                        ,--. :/ |             __  ,-.             \n");
				Center_text(".   |  ;. /:  :  :                        :  : ' /            ,' ,'/ /|  .--.--.    \n");
				Center_text(".   ; /--` :  |  |,--.   ,---.     ,---.  |  '  /      ,---.  '  | |' | /  /    '   \n");
				Center_text(";   | ;    |  :  '   |  /     \\   /     \\ '  |  :     /     \\ |  |   ,'|  :  /`./   \n");
				Center_text("|   : |    |  |   /' : /    /  | /    / ' |  |   \\   /    /  |'  :  /  |  :  ;_     \n");
				Center_text(".   | '___ '  :  | | |.    ' / |.    ' /  '  : |. \\ .    ' / ||  | '    \\  \\    `.  \n");
				Center_text("'   ; : .'||  |  ' | :'   ;   /|'   ; :__ |  | ' \\ \\'   ;   /|;  : |     `----.   \\ \n");
				Center_text("'   | '/  :|  :  :_:,''   |  / |'   | '.'|'  : |--' '   |  / ||  , ;    /  /`--'  / \n");
				Center_text("|   :    / |  | ,'    |   :    ||   :    :;  |,'    |   :    | ---'    '--'.     /  \n");
				Center_text(" \\   \\ .'  `--''       \\   \\  /  \\   \\  / '--'       \\   \\  /            `--'---'   \n");
				Center_text("  `---`                 `----'    `----'              `----'                        \n");
				cout<<"\n\nHow do you want to play (Enter 1, 2, etc.): ";		//Tells the user what they can do
				cout<<"\n\tHuman vs Human ---------------- 1";			//Outputs the option of removing a contact
				cout<<"\n\tHuman vs CPU (You first) ------ 2";			//Outputs the option of searching for a contact
				cout<<"\n\tHuman vs CPU (CPU first) ------ 3";			//Outputs the option of editing a contact
				cout<<"\n\tCPU vs CPU -------------------- 4";			//Outputs the option of editing a contact
				cout<<"\n\tInstructions ------------------ 5";			//Outputs the option of editing a contact
				cout<<"\n\tBack to main menu ------------- 6\n";			//Outputs the option of showing all of the contacts
				cin>>game_choice;
				while (game_choice<1 or game_choice>6){
					cout<<"Invalid Input! Retry.\n";			//Tells the user that the input was wrong
					cout<<"How do you want to play (Enter 1, 2, etc.): ";		//Tells the user what they can do
					cin>>game_choice;		//Prompts the user to input
				}
				if (game_choice==1){
					checkers(1);	
				}
				else if (game_choice==2){
					checkers(2);
				}
				else if (game_choice==3){
					checkers(3);
				}
				else if (game_choice==4){
					checkers(4);
				}
				else if (game_choice==5){
					cout<<flush;			//Flushes the output stream
					system ("CLS");			//Clear the screen
				
					//Rules
					cout<<"                   __  __                   __            ____   __             \n";				//Rules Title Card ASCII Art
					cout<<"                  / / / /____  _      __   / /_ ____     / __ \\ / /____ _ __  __\n";			//More Rules Title Card ASCII Art
					cout<<"                 / /_/ // __ \\| | /| / /  / __// __ \\   / /_/ // // __ `// / / /\n";			//More Rules Title Card ASCII Art
					cout<<"                / __  // /_/ /| |/ |/ /  / /_ / /_/ /  / ____// // /_/ // /_/ / \n";				//More Rules Title Card ASCII Art
					cout<<"               /_/ /_/ \\____/ |__/|__/   \\__/ \\____/  /_/    /_/ \\__,_/ \\__, /  \n";		//More Rules Title Card ASCII Art
					cout<<"                                                                       /____/   ";				//More Rules Title Card ASCII Art
					cout<<"\n-----------------------------------------------------------------------------------------------\n";		//Line of Separation
					
					cout<<"Object of the Game:\n";				//Rules of Blackjack
					cout<<"\tA player wins once all of their opponent's pieces are captured. They can also win if their piece has no moves available.\n";				//Rules of Blackjack
					
					cout<<"\nThe Play:\n";				//Rules of Blackjack
					cout<<"\tThe Black player starts by moving one of the first row pieces.";
					cout<<"\n\tThe red player does the same and the turns alternate.\n";
					
					cout<<"\nSingles:\n";				//Rules of Blackjack
					cout<<"\tCan only be moved forward, diagonally, one spot, for normal moves.";
					cout<<"\n\tCan \"capture\" an opposing piece if they are adjacent to that piece and there is an empty space directly behind it.";
					cout<<"\n\tIt will jump over that piece, land, and the opponent's jumped piece will be removed from the board.";
					cout<<"\n\tCan capture multiple opponent pieces if they are adjacent to the first piece and there's a spot open directly behind it.\n";
	
					cout<<"\nKings:\n";
					cout<<"\tSingles Get promoted to a king when they reach the opponent's back row.";
					cout<<"\n\tKings can move diagonally and capture in any direction.\n";
	
					cout<<"\nRules:\n";				//Rules of Blackjack
					cout<<"\tPlayers must move a checker during their turn. No passing.";
					cout<<"\n\tPlay is always diagonal in direction, on the darker spaces.";
					cout<<"\n\tOnly kings can move in either direction (forward and backward). Single checkers may only move forward.";
					cout<<"\n\tYou may only capture an opponent's piece if you are adjacent (diagonally) to it and the spot directly behind it is open.";
					cout<<"\n\tYou MUST capture if a capture move is available. This includes additional captures in a multi-capture move.";
					cout<<"\n\tIf multiple captures are available, you may choose which one.\n";
					
					cout<<"\nExtra:\n";				//Rules of Blackjack
					cout<<"\tEnter save to save the game for later.";
					cout<<"\n\tEnter load during a different game to load a saved game.";
					cout<<"\n\tEnter \"quit\" to quit a game.\n\n";
					system ("PAUSE");		//Pause the program until the user presses a key
					
					cout<<flush; 		//flushes the output stream
					system ("CLS");		//Clear the screen
					
					//Strategy
					cout<<"                  _____  __                __                     \n";				//Strategy Title Card ASCII Art
					cout<<"                 / ___/ / /_ _____ ____ _ / /_ ___   ____ _ __  __\n";				//More Strategy Title Card ASCII Art
					cout<<"                 \\__ \\ / __// ___// __ `// __// _ \\ / __ `// / / /\n";				//More Strategy Title Card ASCII Art
					cout<<"                ___/ // /_ / /   / /_/ // /_ /  __// /_/ // /_/ / \n";				//More Strategy Title Card ASCII Art
					cout<<"               /____/ \\__//_/    \\__,_/ \\__/ \\___/ \\__, / \\__, /  \n";				//More Strategy Title Card ASCII Art
					cout<<"                                                  /____/ /____/   ";				//More Strategy Title Card ASCII Art
					cout<<"\n---------------------------------------------------------------------------------\n";		//Line of separation
					
					cout<<"Control the Center:\n";
					cout<<"\tOccupy the center by moving your pieces into it.";
					cout<<"\n\tJump toward the center when you have the option of jumping more than one way.";
					cout<<"\n\tThe central squares are more critical to control than the edges.";
					cout<<"\n\tAll the squares are important, and a well-placed piece on the side of the board is beneficial.";
					cout<<"\n\tIf you have a choice between moving or jumping to the side or to the center, go toward the center.\n";
					
					cout<<"\nProtect Your King Row:\n";
					cout<<"\tGetting the first king is a huge advantage among less-skilled players.";
					cout<<"\n\tIf you don't move your back four pieces, that leaves you 8 pieces to fight up possibly 10 or 12.";
					cout<<"\n\tThis could easily leave you on the wrong side of some exchanges.";
					cout<<"\n\tThe general strategy used by experts is to advance two of the four back pieces.";
					cout<<"\n\tThis gives you an attacking force of 10 while leaving the 2nd and 4th back row pieces to slow down any Kinging attempts.";
					cout<<"\n\tLeave those two as long as you reasonably can and bring the other two into your attack.\n";
					
					cout<<"\nKeep a Strong Formation:\n";
					cout<<"\tPieces grouped together tend to be stronger than ones that are separated.";
					cout<<"\n\tAdvance your pieces collectively, using the ones behind to support the ones in front.";
					cout<<"\n\tA solid mass of pieces isn't as vulnerable to double or triple jumping attacks.";
					cout<<"\n\tAmateurs often exchange pieces randomly just to simplify the game. ";
					cout<<"\n\tWhen this happens, you'll find that your superior formation leaves you in a stronger position.\n\n";
					system("PAUSE");
				}
				cout<<flush;
				system("CLS");
			} while (game_choice!=6);
		}
		else if (menu_choice==2){
			minesweeper();
		}
		else if (menu_choice==3){
			cout<<flush;
			system("CLS"); 
			SOS();
		}
		else{
		    cout<<flush;		//flushes the output stream
			system ("CLS");		//clears the screen
			cout<<"   ______                   __ __                  __\n";		//Goodbye Title Card ASCII Art
			cout<<"  / ____/____   ____   ____/ // /_   __  __ ___   / /\n";		//Goodbye Title Card ASCII Art
			cout<<" / / __ / __ \\ / __ \\ / __  // __ \\ / / / // _ \\ / / \n";	//Goodbye Title Card ASCII Art
			cout<<"/ /_/ // /_/ // /_/ // /_/ // /_/ // /_/ //  __//_/  \n";		//Goodbye Title Card ASCII Art
			cout<<"\\____/ \\____/ \\____/ \\__,_//_.___/ \\__, / \\___/(_)   \n";	//Goodbye Title Card ASCII Art
			cout<<"                                  /____/             \n";			//Goodbye Title Card ASCII Art
			break;		//breaks out of the do-while loop
		}
		if (menu_choice!=3 and menu_choice!=2 and game_choice!=6){
			system("PAUSE");
		}
		cout<<flush;
		system("CLS"); 
	} while (menu_choice!=4);
	return 0;	// Ends the program
}
	
void Center_text(string text){		//Defines a function for outputting text to the center of the screen
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get the console handle.
	PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO(); // Create a pointer to the Screen Info pointing to a temporal screen info.
	GetConsoleScreenBufferInfo(hConsole, lpScreenInfo); // Saves the console screen info into the lpScreenInfo pointer.
	COORD NewSBSize = lpScreenInfo->dwSize; // Gets the size of the screen
	NewSBSize.X+=0;		//Increases the screen size by 4		
	if (NewSBSize.X > text.size() and (NewSBSize.X-text.size())>0) {
	    int newpos = ((NewSBSize.X - text.size()) / 2); // Calculate the number of spaces to center the specific text.
	    for (int i = 0; i < newpos; i++) cout << " "; // Prints the spaces
	}
	cout<<text;		//Outputs the text
}
	
	
//Checkers	

int negamax(char board[8][8], int depth, int color){
	int total=0;
	int val;
	int spot_value;
	char og_board[8][8];
	vector<vector <string>> legal_spots(5);
	vector <int> move_count;
	int moves[8];
	string move_from;
	string move_to;
	int x1,y1,x2,y2;
	int best_move;
	int move;
	char char_color;
	bool attack=false;
	vector <string> attack_moves;
    int best = -2147483647;
	
	if (color==1){
		char_color='B';
		copy(&board[0][0], &board[8][8],&og_board[0][0]);
		for (int i=0;i<8;i++){
			for (int k=0;k<8;k++){
				board[i][k]=reverse_char(og_board,i,k);
			}
		}
	}
	else{
		char_color='R';
		copy(&board[0][0], &board[8][8],&og_board[0][0]);
		for (int i=0;i<8;i++){
			for (int k=0;k<8;k++){
				board[i][k]=reverse_char(og_board,i,k);
			}
		}
	}
	
    if (depth<=0){
    	for (int i=0;i<8;i++){
    		for (int j=0;j<8;j++){
    			if (i==0 or i==7 or j==0 or j==7){
    				spot_value=4;
				}
				else if (i==1 or i==6 or j==1 or j==6){
					spot_value=3;
				}
				else if (i==2 or i==5 or j==2 or j==5){
					spot_value=2;
				}
				else if (i==3 or i==4 or j==3 or j==4){
					spot_value=1;
				}
    			if (board[i][j]=='b'){
    				total+=1*spot_value;
				}
				else if (board[i][j]=='B'){
    				total+=2*spot_value;
				}
				else if (board[i][j]=='r'){
    				total-=1*spot_value;
				}
				else if (board[i][j]=='R'){
    				total-=2*spot_value;
				}
			}
		}
//		cout<<"total: "<<total*color<<endl;
        return total*color;
	}

//    GenerateLegalMoves();
	cout.setstate(ios_base::failbit);
	for (int i=0;i<8;i++){
		for (int k=0;k<8;k++){
			if (board[i][k]==tolower(char_color) or board[i][k]==char_color){
				legal_spots[0].push_back(char(k+1+64)+to_string(i+1));
					
			}
		}
	}
	legal_spots.resize(5);
	for (int i=0;i<5;i++){
	    legal_spots[i].resize(legal_spots[0].size());
	}
	move_count.resize(legal_spots[0].size(),1);
	for (int i=0;i<legal_spots[0].size();i++){
//		cout<<i<<" ";
		y1=(legal_spots[0][i].at(0)-64)-1;
		x1=(legal_spots[0][i].at(1)-'0')-1;	
		moves[0]=checkers_move_to_check(char(y1-1+1+64)+to_string(x1-1+1),board,char_color,x1,y1);
		if (moves[0]!=-1){
			legal_spots[move_count[i]][i]=char(y1-1+1+64)+to_string(x1-1+1);
			move_count[i]++;
		}
		moves[1]=checkers_move_to_check(char(y1+1+1+64)+to_string(x1-1+1),board,char_color,x1,y1);
		if (moves[1]!=-1){
			legal_spots[move_count[i]][i]=char(y1+1+1+64)+to_string(x1-1+1);
			move_count[i]++;
		}
		moves[2]=checkers_move_to_check(char(y1-1+1+64)+to_string(x1+1+1),board,char_color,x1,y1);
		if (moves[2]!=-1){
			legal_spots[move_count[i]][i]=char(y1-1+1+64)+to_string(x1+1+1);
			move_count[i]++;
		}
		moves[3]=checkers_move_to_check(char(y1+1+1+64)+to_string(x1+1+1),board,char_color,x1,y1);
		if (moves[3]!=-1){
			legal_spots[move_count[i]][i]=char(y1+1+1+64)+to_string(x1+1+1);
			move_count[i]++;
		}
		moves[4]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),board,char_color,x1,y1);
		if (moves[4]!=-1){
			legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1-2+1)+"-";
			move_count[i]++;
		}
		moves[5]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),board,char_color,x1,y1);
		if (moves[5]!=-1){
			legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1-2+1)+"-";
			move_count[i]++;
		}
		moves[6]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),board,char_color,x1,y1);
		if (moves[6]!=-1){
			legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1+2+1)+"-";
			move_count[i]++;
		}
		moves[7]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),board,char_color,x1,y1);
		if (moves[7]!=-1){
			legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1+2+1)+"-";
			move_count[i]++;
		}
	}
	for (int i=0;i<legal_spots[0].size();i++){
		for (int k=1;k<move_count[i];k++){
			if (legal_spots[k][i].back()=='-'){
				move_count.clear();
				attack_moves.push_back(legal_spots[0][i]);
//				break;
			}
		}	
	}
	if (attack_moves.empty()!=true){
		cout<<"hi\n";
		legal_spots.clear();
		legal_spots.resize(5);
		for (int i=0;i<attack_moves.size();i++){
			legal_spots[0].push_back(attack_moves[i]);
		}
		legal_spots.resize(5);
		for (int i=0;i<5;i++){
		    legal_spots[i].resize(legal_spots[0].size());
		}
		move_count.resize(legal_spots[0].size(),1);
		for (int i=0;i<legal_spots[0].size();i++){
			y1=(legal_spots[0][i].at(0)-64)-1;
			x1=(legal_spots[0][i].at(1)-'0')-1;	
			moves[0]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),board,char_color,x1,y1);
			if (moves[0]>0){
				legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1-2+1);
				move_count[i]++;
			}
			moves[1]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),board,char_color,x1,y1);
			if (moves[1]>0){
				legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1-2+1);
				move_count[i]++;
			}
			moves[2]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),board,char_color,x1,y1);
			if (moves[2]>0){
				legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1+2+1);
				move_count[i]++;
			}
			moves[3]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),board,char_color,x1,y1);
			if (moves[3]>0){
				legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1+2+1);
				move_count[i]++;
			}
		}
		for (int i=0;i<legal_spots[0].size();i++){
			for (int j=0;j<move_count[i]-1;j++){
				if (legal_spots[i][j].back()=='-'){
					legal_spots[i][j].pop_back();
				}
			}
		}
	}
	cout.clear();
	
//    while (MovesLeft()) {
    for (int i=0;i<legal_spots[0].size();i++) {
    	for (int j=1;j<move_count[i];j++){
    		attack=false;
//			cout<<i<<" "<<j<<"--\n";
//			cout<<"depth: "<<depth<<endl;
    		copy(&board[0][0], &board[8][8],&og_board[0][0]);
    		move_from=legal_spots[0][i];
			y1=(move_from.at(0)-64)-1;
			x1=(move_from.at(1)-'0')-1;	
    		move_from=legal_spots[j][i];
    		cout.setstate(ios_base::failbit);
			move=checkers_move_to_check(move_from,board,char_color,x1,y1);
			cout.clear();
			y2=(move_from.at(0)-64)-1;
			x2=(move_from.at(1)-'0')-1;
//	        MakeNextMove();
			if (move>0){
				board[(move%10)-1][(move/10)-1]=' ';
			}
			board[x2][y2]=board[x1][y1];
			board[x1][y1]=' ';
			for (int i=0;i<8;i++){
				if (board[0][i]==tolower(char_color)){
					board[0][i]=char_color;
				}
			}
			if (attack_moves.empty()!=true){
				cout.setstate(ios_base::failbit);
				moves[0]=checkers_move_to_check(char(y2-2+1+64)+to_string(x2-2+1),board,char_color,x2,y2);
				moves[1]=checkers_move_to_check(char(y2+2+1+64)+to_string(x2-2+1),board,char_color,x2,y2);
				moves[2]=checkers_move_to_check(char(y2-2+1+64)+to_string(x2+2+1),board,char_color,x2,y2);
				moves[3]=checkers_move_to_check(char(y2+2+1+64)+to_string(x2+2+1),board,char_color,x2,y2);
				cout.clear();
				if (moves[0]>0 or moves[1]>0 or moves[2]>0 or moves[3]>0){
					attack=true;		
				}
			}
			if (attack==true){
				val = multimax(board,depth,color,move_from);
			}
			else{
	        	val = -negamax(board,depth-1,-color); // Note the minus sign here.
			}
//	        cout<<"depth: "<<depth<<"  val: "<<val<<"  best: "<<best<<endl;
//	        UnmakeMove();
	    	copy(&og_board[0][0], &og_board[8][8],&board[0][0]);
			if (val > best){
	        	best_move=((y1+1)*1000)+((x1+1)*100)+((y2+1)*10)+x2+1;
//				cout<<"best move: "<<best_move<<endl<<char(y1+1+64)<<to_string(x1+1)<<" "<<char(y2+1+64)<<to_string(x2+1)<<"  depth: "<<depth<<"  best val: "<<best<<endl;
			} 	
	        best=max(best,val);
		}
    }
//    cout<<"hi\n";
//	best_move=((y1+1)*1000)+((x1+1)*100)+((y2+1)*10)+x1+1;
//	cout<<"best move: "<<best_move<<endl;
    return best_move;
}

int multimax(char board[8][8], int depth, int color, string move_from){
	int total=0;
	int val;
	int spot_value;
	char og_board[8][8];
	vector<vector <string>> legal_spots(5);
	vector <int> move_count;
	int moves[4];
	string move_to;
	int x1,y1,x2,y2;
	int best_move;
	int move;
	char char_color;
	vector <string> attack_moves;
    int best = -2147483647;
	
	if (color==1){
		char_color='B';
		copy(&board[0][0], &board[8][8],&og_board[0][0]);
		for (int i=0;i<8;i++){
			for (int k=0;k<8;k++){
				board[i][k]=reverse_char(og_board,i,k);
			}
		}
	}
	else{
		char_color='R';
		copy(&board[0][0], &board[8][8],&og_board[0][0]);
		for (int i=0;i<8;i++){
			for (int k=0;k<8;k++){
				board[i][k]=reverse_char(og_board,i,k);
			}
		}
	}
	
    if (depth<=0){
    	for (int i=0;i<8;i++){
    		for (int j=0;j<8;j++){
    			if (i==0 or i==7 or j==0 or j==7){
    				spot_value=4;
				}
				else if (i==1 or i==6 or j==1 or j==6){
					spot_value=3;
				}
				else if (i==2 or i==5 or j==2 or j==5){
					spot_value=2;
				}
				else if (i==3 or i==4 or j==3 or j==4){
					spot_value=1;
				}
    			if (board[i][j]=='b'){
    				total+=1*spot_value;
				}
				else if (board[i][j]=='B'){
    				total+=2*spot_value;
				}
				else if (board[i][j]=='r'){
    				total-=1*spot_value;
				}
				else if (board[i][j]=='R'){
    				total-=2*spot_value;
				}
			}
		}
//		cout<<"total: "<<total*color<<endl;
        return total*color;
	}
	
//    GenerateLegalMoves();
	cout.setstate(ios_base::failbit);
	legal_spots[0].push_back(move_from);
	legal_spots.resize(5);
	for (int i=1;i<5;i++){
		legal_spots[i].resize(1);
	}
	legal_spots[0].resize(1);
	move_count.resize(1,1);
	y1=(move_from.at(0)-64)-1;
	x1=(move_from.at(1)-'0')-1;	
	
	moves[0]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),board,char_color,x1,y1);
	if (moves[0]!=-1){
		legal_spots[move_count[0]][0]=char(y1-2+1+64)+to_string(x1-2+1)+"-";
		move_count[0]++;
	}
	moves[1]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),board,char_color,x1,y1);
	if (moves[1]!=-1){
		legal_spots[move_count[0]][0]=char(y1+2+1+64)+to_string(x1-2+1)+'-';
		move_count[0]++;
	}
	moves[2]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),board,char_color,x1,y1);
	if (moves[2]!=-1){
		legal_spots[move_count[0]][0]=char(y1-2+1+64)+to_string(x1+2+1)+"-";
		move_count[0]++;
	}
	moves[3]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),board,char_color,x1,y1);
	if (moves[3]!=-1){
		legal_spots[move_count[0]][0]=char(y1+2+1+64)+to_string(x1+2+1)+"-";
		move_count[0]++;
	}
	

	for (int k=1;k<move_count[0];k++){
		if (legal_spots[k][0].back()=='-'){
			move_count.clear();
			attack_moves.push_back(legal_spots[0][0]);
//			break;
		}
	}
	cout.clear();
	
//    while (MovesLeft()) {
//cout<<move_count[0];
	for (int j=1;j<move_count[0];j++){
//    	cout<<"hi\n";
		copy(&board[0][0], &board[8][8],&og_board[0][0]);
		if (attack_moves.empty()!=true){
//			cout<<0<<" "<<j<<"--";
			move_from=legal_spots[0][0];
			y1=(move_from.at(0)-64)-1;
			x1=(move_from.at(1)-'0')-1;	
			move_from=legal_spots[j][0];
			cout.setstate(ios_base::failbit);
			move=checkers_move_to_check(move_from,board,char_color,x1,y1);
			cout.clear();
			y2=(move_from.at(0)-64)-1;
			x2=(move_from.at(1)-'0')-1;
	//	    MakeNextMove();
			if (move>0){
				board[(move%10)-1][(move/10)-1]=' ';
			}
			board[x2][y2]=board[x1][y1];
			board[x1][y1]=' ';
			for (int i=0;i<8;i++){
				if (board[0][i]==tolower(char_color)){
					board[0][i]=char_color;
				}
			}
	        val = multimax(board,depth,color,move_from);
		}
		else{	
			val = negamax(board,depth,color); // Note the minus sign here.	
			y1=(val/1000)-1;
			x1=((val/100)%10)-1;	
			move_from=char(((val/10)%10)+64)+to_string(val%10);
			cout.setstate(ios_base::failbit);
			move=checkers_move_to_check(move_from,board,char_color,x1,y1);
			cout.clear();
			y2=(move_from.at(0)-64)-1;
			x2=(move_from.at(1)-'0')-1;
	//	    MakeNextMove();
			if (move>0){
				board[(move%10)-1][(move/10)-1]=' ';
			}
			board[x2][y2]=board[x1][y1];
			board[x1][y1]=' ';
			for (int i=0;i<8;i++){
				if (board[0][i]==tolower(char_color)){
					board[0][i]=char_color;
				}
			}
//			cout<<"nega: ";
		}
//    	cout<<"hi\n";
//	    cout<<"depth: "<<depth<<"  val: "<<val<<"  best: "<<best<<endl;
//	        UnmakeMove();
    	copy(&og_board[0][0], &og_board[8][8],&board[0][0]);
		if (val > best){
        	best_move=((y2+1)*10)+x2+1;
//        	cout<<endl<<x1<<"+"<<y1<<"->"<<x2<<"+"<<y2<<endl<<"from: "<<move_from<<endl;
//			cout<<"best move: "<<best_move<<endl<<char(y1+1+64)<<to_string(x1+1)<<" "<<char(y2+1+64)<<to_string(x2+1)<<"  depth: "<<depth<<"  best val: "<<best<<endl;
		} 	
        best=max(best,val);
	}
//    cout<<"hi\n";
//	best_move=((y2+1)*10)+x2+1;
//        	cout<<endl<<x1<<"+"<<y1<<"->"<<x2<<"+"<<y2<<endl<<"from: "<<move_from<<endl;
//	cout<<"\nbest move: "<<best_move<<endl;
    return best_move;
}

void checkers(int gamemode){				// starts the program
	bool red_player;
	bool black_player;
	int save=0;
	int load=0;
	string move_from;
	string move_to;
	int move,move2,move3,move4;
	int x1,y1,x2,y2;
	string all_moves="";
	int capture_count=0;
	bool black_win=false;
	bool red_win=false;
	char og_board[8][8];
	char pieces[8][8]={
		{' ','r',' ','r',' ','r',' ','r'},
		{'r',' ','r',' ','r',' ','r',' '},
		{' ','r',' ','r',' ','r',' ','r'},
		{' ',' ',' ',' ',' ',' ',' ',' '},
		{' ',' ',' ',' ',' ',' ',' ',' '},
		{'b',' ','b',' ','b',' ','b',' '},	
		{' ','b',' ','b',' ','b',' ','b'},
		{'b',' ','b',' ','b',' ','b',' '}
	};
//	char pieces[8][8]={
//		{' ','r',' ','B',' ',' ',' ',' '},
//		{'b',' ',' ',' ',' ',' ','r',' '},
//		{' ',' ',' ',' ',' ',' ',' ',' '},
//		{' ',' ',' ',' ',' ',' ',' ',' '},
//		{' ',' ',' ',' ',' ',' ',' ','b'},
//		{' ',' ',' ',' ',' ',' ','b',' '},	
//		{' ',' ',' ',' ',' ',' ',' ',' '},
//		{'b',' ','b',' ',' ',' ','b',' '}
//	}; 
	//AI STUFF
	int red_level=0;
	int black_level=0;
	char cpu_check;
	vector<vector <string>> legal_spots(5);
	vector <int> move_count;
	int moves[8];
	int rand_move;
	int black_rand=4;
	int red_rand=4;
	bool attack=false;
	vector <string> attack_moves;
	
	cout<<flush;
	system("CLS");
	do{
		cpu_check='Y';
		if (gamemode==1){
			red_player=true;
			black_player=true;
		}
		else if (gamemode==2){
			red_player=false;
			cout<<"What CPU difficulty do you want (Enter 1, 2, etc.): ";		//Tells the user what they can do
			cout<<"\n\tEasy -------- 1";			//Outputs the option of removing a contact
			cout<<"\n\tMedium ------ 2";			//Outputs the option of removing a contact
			cout<<"\n\tHard -------- 3\n";			//Outputs the option of editing a contact
			cin>>red_level;
			while (red_level<1 or red_level>3){
				cout<<"Invalid Input! Retry.\n";			//Tells the user that the input was wrong
				cout<<"What CPU difficulty do you want (Enter 1, 2, etc.): ";		//Tells the user what they can do
				cin>>red_level;		//Prompts the user to input
			}
			black_player=true;
		}
		else if (gamemode==3){
			red_player=true;
			black_player=false;
			cout<<"What CPU difficulty do you want (Enter 1, 2, etc.): ";		//Tells the user what they can do
			cout<<"\n\tEasy -------- 1";			//Outputs the option of removing a contact
			cout<<"\n\tMedium ------ 2";			//Outputs the option of removing a contact
			cout<<"\n\tHard -------- 3\n";			//Outputs the option of editing a contact
			cin>>black_level;
			while (black_level<1 or black_level>3){
				cout<<"Invalid Input! Retry.\n";			//Tells the user that the input was wrong
				cout<<"What CPU difficulty do you want (Enter 1, 2, etc.): ";		//Tells the user what they can do
				cin>>black_level;		//Prompts the user to input
			}
		}
		else{
			red_player=false;
			cout<<"What CPU difficulty do you want for Red (Enter 1, 2, etc.): ";		//Tells the user what they can do
			cout<<"\n\tEasy -------- 1";			//Outputs the option of removing a contact
			cout<<"\n\tMedium ------ 2";			//Outputs the option of removing a contact
			cout<<"\n\tHard -------- 3\n";			//Outputs the option of editing a contact
			cin>>red_level;
			while (red_level<1 or red_level>3){
				cout<<"Invalid Input! Retry.\n";			//Tells the user that the input was wrong
				cout<<"What CPU difficulty do you want (Enter 1, 2, etc.): ";		//Tells the user what they can do
				cin>>red_level;		//Prompts the user to input
			}
			
			black_player=false;
			cout<<"What CPU difficulty do you want for Black (Enter 1, 2, etc.): ";		//Tells the user what they can do
			cout<<"\n\tEasy -------- 1";			//Outputs the option of removing a contact
			cout<<"\n\tMedium ------ 2";			//Outputs the option of removing a contact
			cout<<"\n\tHard -------- 3\n";			//Outputs the option of editing a contact
			cin>>black_level;
			while (black_level<1 or black_level>3){
				cout<<"Invalid Input! Retry.\n";			//Tells the user that the input was wrong
				cout<<"What CPU difficulty do you want (Enter 1, 2, etc.): ";		//Tells the user what they can do
				cin>>black_level;		//Prompts the user to input
			}
		}
		if (black_level==3 and red_level==3){
			cout<<endl<<"WARNING! A level 3 bot match will ALWAYS TIE. It will end up in a situation where both CPUs repeat the same move.\n";
			cout<<"\nAre you sure that you want to continue (Y or N): ";
			cin>>cpu_check;
			while (toupper(cpu_check)!='N' and toupper(cpu_check)!='Y'){
				cout<<"Invalid Input! Retry\n";
				cout<<"\nAre you sure that you want to continue (Y or N): ";
				cin>>cpu_check;
			}
			if (toupper(cpu_check)=='N'){
				cout<<flush;
				system("CLS");
			}
		}
	} while (toupper(cpu_check)=='N');
	
	for (int j=0;j>-1;j++){
		for (int i=0;i<8;i++){
			for (int k=0;k<8;k++){
				if (pieces[i][k]=='r' or pieces[i][k]=='R'){
					i=8;
					break;
				}
				else if (k==7 and i==7){
					j=-2;
				}
			}
		}
		for (int i=0;i<8;i++){
			for (int k=0;k<8;k++){
				if (pieces[i][k]=='b' or pieces[i][k]=='B'){
					i=8;
					break;
				}
				else if (k==7 and i==7){
					j=-3;
				}
			}
		}	
		if (j>0){
			copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
			for (int i=0;i<8;i++){
				for (int k=0;k<8;k++){
					pieces[i][k]=reverse_char(og_board,i,k);
				}
			}
		}
		create_checkers(pieces);
		if (black_win==true){
			cout<<"BLACK WINS!\n";
			break;
			
		}
		else if (red_win==true){
			cout<<"RED WINS!\n";
			break;
		}
		else if (capture_count==60){
			cout<<"DRAW!\n";
			break;
		}
		if (j%2==0){
			if (black_player==true){
				if (red_player==false){	
					cout<<"YOUR TURN (BLACK)\n";
				}
				else{
					cout<<"BLACK TURN\n";
				}
				while (j>-1){
					cout.setstate(ios_base::failbit);
					if (generate_moves(pieces,'B')==0){
						j=-3;
						cout.clear();
						break;
					}
					cout.clear();
					cout<<"Enter the location of the piece you want to move (Ex. A7): ";
					cin>>move_from;
					if (move_from=="quit"){
						j=-2;
						break;
					}
					if (move_from=="save"){
						save_game(pieces, j%2, capture_count, red_level, black_level);
						save=1;
						cout<<"Game Saved!\n";
						cout.setstate(ios_base::failbit);
					}
					if (move_from=="load" and save==0){
						ifstream saved;			//Create a file object for reading
			    		saved.open("Checkers_save.txt");		//attempt to open the saved_game file 
					    if (saved){		//If the file opens
							j=(load_settings(1))+1;
							capture_count=(load_settings(2));
							black_level=(load_settings(3));
							if (black_level>0){
								black_player==false;
							}
							red_level=(load_settings(4));
							if (red_level>0){
								red_player==false;
							}
							for (int i=1;i<=8;i++){
								for (int k=1;k<=8;k++){
									pieces[i-1][k-1]=load_board(i,k);
								}
						    }
						    copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
							for (int i=0;i<8;i++){
								for (int k=0;k<8;k++){
									pieces[i][k]=reverse_char(og_board,i,k);
								}
							}
							load=1;
						    break;
						}
						else{
							cout<<"There is no saved game!\n";
						}
			    		saved.close();		//closes the file object (just in case)
					}
					move_from.at(0)=toupper(move_from.at(0));
					while (checkers_move_from_check(move_from,pieces,'B')==false){
						cout.clear();
						cout<<"Enter the location of the piece you want to move: ";
						cin>>move_from;
						if (move_from=="quit"){
							j=-2;
							break;
						}
						if (move_from=="save"){
							save_game(pieces, j%2, capture_count, red_level, black_level);
							save=1;
							cout<<"Game Saved!\n";
							continue;
						}
						if (move_from=="load" and save==0){
							ifstream saved;			//Create a file object for reading
				    		saved.open("Checkers_save.txt");		//attempt to open the saved_game file 
						    if (saved){		//If the file opens
								j=(load_settings(1))+1;
								capture_count=(load_settings(2));
								black_level=(load_settings(3));
								if (black_level>0){
									black_player==false;
								}
								red_level=(load_settings(4));
								if (red_level>0){
									red_player==false;
								}
								for (int i=1;i<=8;i++){
									for (int k=1;k<=8;k++){
										pieces[i-1][k-1]=load_board(i,k);
									}
							    }
							    copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
								for (int i=0;i<8;i++){
									for (int k=0;k<8;k++){
										pieces[i][k]=reverse_char(og_board,i,k);
									}
								}
								load=1;
							    break;
							}
							else{
								cout<<"There is no saved game!\n";
							}
				    		saved.close();		//closes the file object (just in case)
						}
						move_from.at(0)=toupper(move_from.at(0));
					}
					if (move_from=="quit"){
						j=-2;
						break;
					}
					if (move_from=="load" and save==0){
						break;
					}
					y1=(move_from.at(0)-64)-1;
					x1=(move_from.at(1)-'0')-1;
					
					all_moves+=move_from;
					all_moves+=" ";
					
					do{
						cout<<"Enter the location you want to move to (or 00 to reselect): ";
						cin>>move_to;
						if (move_to=="00"){
							break;
						}
						if (move_to=="quit"){
							j=-2;
							break;
						}
						if (move_to=="save"){
							save_game(pieces, j%2, capture_count, red_level, black_level);
							save=1;
							cout<<"Game Saved!\n";
							continue;
						}
						if (move_to=="load" and save==0){
							ifstream saved;			//Create a file object for reading
				    		saved.open("Checkers_save.txt");		//attempt to open the saved_game file 
						    if (saved){		//If the file opens
								j=(load_settings(1))+1;
								capture_count=(load_settings(2));
								black_level=(load_settings(3));
								if (black_level>0){
									black_player==false;
								}
								red_level=(load_settings(4));
								if (red_level>0){
									red_player==false;
								}
								for (int i=1;i<=8;i++){
									for (int k=1;k<=8;k++){
										pieces[i-1][k-1]=load_board(i,k);
									}
							    }
							    copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
								for (int i=0;i<8;i++){
									for (int k=0;k<8;k++){
										pieces[i][k]=reverse_char(og_board,i,k);
									}
								}
								load=1;
							    break;
							}
							else{
								cout<<"There is no saved game!\n";
							}
				    		saved.close();		//closes the file object (just in case)
						}
						move_to.at(0)=toupper(move_to.at(0));
						move=checkers_move_to_check(move_to,pieces,'B',x1,y1);
						while (move==-1){
							cout<<"Enter the location you want to move to (or 00 to reselect): ";
							cin>>move_to;
							if (move_to=="00"){
								break;
							}
							if (move_to=="save"){
								save_game(pieces, j%2, capture_count, red_level, black_level);
								save=1;
								cout<<"Game Saved!\n";
								continue;
							}	
							if (move_to=="load" and save==0){
								ifstream saved;			//Create a file object for reading
					    		saved.open("Checkers_save.txt");		//attempt to open the saved_game file 
							    if (saved){		//If the file opens
									j=(load_settings(1))+1;
									capture_count=(load_settings(2));
									black_level=(load_settings(3));
									if (black_level>0){
										black_player==false;
									}
									red_level=(load_settings(4));
									if (red_level>0){
										red_player==false;
									}
									for (int i=1;i<=8;i++){
										for (int k=1;k<=8;k++){
											pieces[i-1][k-1]=load_board(i,k);
										}
								    }
								    copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
									for (int i=0;i<8;i++){
										for (int k=0;k<8;k++){
											pieces[i][k]=reverse_char(og_board,i,k);
										}
									}
									load=1;
								    break;
								}
								else{
									cout<<"There is no saved game!\n";
								}
					    		saved.close();		//closes the file object (just in case)
							}
							move_to.at(0)=toupper(move_to.at(0));
							move=checkers_move_to_check(move_to,pieces,'B',x1,y1);
						}
						if (move_to=="00"){
							break;
						}
						if (move_to=="load" and save==0){
							break;
						}
						y2=(move_to.at(0)-64)-1;
						x2=(move_to.at(1)-'0')-1;
						if (move>0){
							pieces[(move%10)-1][(move/10)-1]=' ';
							capture_count=0;
						}
						else{
							capture_count++;
						}
						
						all_moves+=move_to;
						all_moves+=" ";
						pieces[x2][y2]=pieces[x1][y1];
						pieces[x1][y1]=' ';
						
						for (int i=0;i<8;i++){
							if (pieces[0][i]=='b'){
								pieces[0][i]='B';
							}
						}
						if (move<=0){
							break;
						}
						move_from=move_to;
						y1=(move_from.at(0)-64)-1;
						x1=(move_from.at(1)-'0')-1;	
						
						cout.setstate(ios_base::failbit);
						move=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),pieces,'B',x1,y1);
						move2=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),pieces,'B',x1,y1);
						move3=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),pieces,'B',x1,y1);
						move4=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),pieces,'B',x1,y1);
						cout.clear();
//						cout<<move<<" "<<move2<<" "<<move3<<" "<<move4;
						if (move>0 or move2>0 or move3>0 or move4>0){
							system("PAUSE");
							cout<<flush;
							system("CLS");
							create_checkers(pieces);
							cout<<"STILL BLACK TURN\n";
						}
					} while (move>0 or move2>0 or move3>0 or move4>0);
					
					if (move_to=="00"){
						continue;
					}
					if (move_to=="load" and save==0){
						break;
					}
					break;
				}
				
			}
			else{
				cout<<"COMPUTER'S TURN (BLACK)\n";
				legal_spots.clear(); 
				attack_moves.clear();
				legal_spots.resize(5); 
				move_count.clear();
				while (j>-1){	
					for (int i=0;i<8;i++){
						for (int k=0;k<8;k++){
							if (pieces[i][k]=='b' or pieces[i][k]=='B'){
								legal_spots[0].push_back(char(k+1+64)+to_string(i+1));
//								cout<<legal_spots[0][legal_spots[0].size()-1]<<" ";
									
							}
						}
					}
//					cout<<endl;
					legal_spots.resize(5);
					for (int i=0;i<5;i++){
					    legal_spots[i].resize(legal_spots[0].size());
					}
//					cout<<legal_spots[0].size();
					move_count.resize(legal_spots[0].size(),1);
					cout.setstate(ios_base::failbit);
					for (int i=0;i<legal_spots[0].size();i++){
						y1=(legal_spots[0][i].at(0)-64)-1;
						x1=(legal_spots[0][i].at(1)-'0')-1;	
						moves[0]=checkers_move_to_check(char(y1-1+1+64)+to_string(x1-1+1),pieces,'B',x1,y1);
						if (moves[0]!=-1){
							legal_spots[move_count[i]][i]=char(y1-1+1+64)+to_string(x1-1+1);
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[1]=checkers_move_to_check(char(y1+1+1+64)+to_string(x1-1+1),pieces,'B',x1,y1);
						if (moves[1]!=-1){
							legal_spots[move_count[i]][i]=char(y1+1+1+64)+to_string(x1-1+1);
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[2]=checkers_move_to_check(char(y1-1+1+64)+to_string(x1+1+1),pieces,'B',x1,y1);
						if (moves[2]!=-1){
							legal_spots[move_count[i]][i]=char(y1-1+1+64)+to_string(x1+1+1);
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[3]=checkers_move_to_check(char(y1+1+1+64)+to_string(x1+1+1),pieces,'B',x1,y1);
						if (moves[3]!=-1){
							legal_spots[move_count[i]][i]=char(y1+1+1+64)+to_string(x1+1+1);
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[4]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),pieces,'B',x1,y1);
						if (moves[4]!=-1){
							legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1-2+1)+"-";
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[5]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),pieces,'B',x1,y1);
						if (moves[5]!=-1){
							legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1-2+1)+"-";
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[6]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),pieces,'B',x1,y1);
						if (moves[6]!=-1){
							legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1+2+1)+"-";
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[7]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),pieces,'B',x1,y1);
						if (moves[7]!=-1){
							legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1+2+1)+"-";
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						cout.clear();
//						cout<<endl;
						cout.setstate(ios_base::failbit);
					}
						
					for (int i=1;i<5;i++){
						if (legal_spots[i].empty()!=true){
							break;
						}
						else if (i==4){
							j=-3;
						}
					}
					if (j==-3){
						break;
					}
					if (black_level==1){
						do{
							rand_move=rand()%legal_spots[0].size();
	//						rand_move=0;
							for (int i=0;i<legal_spots[0].size();i++){
								for (int k=1;k<move_count[i];k++){
									if (legal_spots[k][i].back()=='-'){
										attack_moves.push_back(legal_spots[0][i]);
										break;
									}
								}	
							}	
						} while (legal_spots[1][rand_move].empty() or legal_spots[0][rand_move].empty());
						move_from=legal_spots[0][rand_move];
						if (attack_moves.size()>0){
							move_from=attack_moves[rand()%attack_moves.size()];
							for (int i=0;i<legal_spots[0].size();i++){
								if (move_from==legal_spots[0][i]){
									rand_move=i;
									break;
								}
							}
						}
						all_moves+=move_from;
						all_moves+=" ";
						cout.clear();
						y1=(move_from.at(0)-64)-1;
						x1=(move_from.at(1)-'0')-1;
						move=1;
					}
					else if (black_level==2){
						black_rand=rand()%4;
						if (black_rand==0){		//BABY MODE (RANDOM)
							do{
								rand_move=rand()%legal_spots[0].size();
		//						rand_move=0;
								for (int i=0;i<legal_spots[0].size();i++){
									for (int k=1;k<move_count[i];k++){
										if (legal_spots[k][i].back()=='-'){
											attack_moves.push_back(legal_spots[0][i]);
											break;
										}
									}	
								}
							} while (legal_spots[1][rand_move].empty() or legal_spots[0][rand_move].empty());
							move_from=legal_spots[0][rand_move];
							if (attack_moves.size()>0){
								move_from=attack_moves[rand()%attack_moves.size()];
								for (int i=0;i<legal_spots[0].size();i++){
									if (move_from==legal_spots[0][i]){
										rand_move=i;
										break;
									}
								}
							}
							all_moves+=move_from;
							all_moves+=" ";
							cout.clear();
							y1=(move_from.at(0)-64)-1;
							x1=(move_from.at(1)-'0')-1;
							move=1;
						}
						else{		//Hard Mode (REAL AI)
							cout.clear();
							copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
							for (int i=0;i<8;i++){
								for (int k=0;k<8;k++){
									pieces[i][k]=reverse_char(og_board,i,k);
								}
							}
							move=negamax(pieces,3,1);
//							cout<<"max: "<<move<<"\n";
							move_from=(move/1000)+64;
							move_from+=to_string((move/100)%10);
							for (int i=0;i<legal_spots[0].size();i++){
								if (move_from==legal_spots[0][i]){
									rand_move=i;
									break;
								}
							}
							y1=(move_from.at(0)-64)-1;
							x1=(move_from.at(1)-'0')-1;
							all_moves+=move_from;
							all_moves+=" ";
							move_to=((move/10)%10)+64;
							move_to+=to_string(move%10);	
						}
					}
					else{		//Hard Mode (REAL AI)
						cout.clear();
						copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
						for (int i=0;i<8;i++){
							for (int k=0;k<8;k++){
								pieces[i][k]=reverse_char(og_board,i,k);
							}
						}
						move=negamax(pieces,5,1);
//						cout<<"max: "<<move<<"\n";
						move_from=(move/1000)+64;
						move_from+=to_string((move/100)%10);
						for (int i=0;i<legal_spots[0].size();i++){
							if (move_from==legal_spots[0][i]){
								rand_move=i;
								break;
							}
						}
						y1=(move_from.at(0)-64)-1;
						x1=(move_from.at(1)-'0')-1;
						all_moves+=move_from;
						all_moves+=" ";
						move_to=((move/10)%10)+64;
						move_to+=to_string(move%10);
					}
//					cout<<rand_move+1<<"=";
//					cout<<move_from<<" ";
					if (move==0){
						j=-3;
						all_moves.erase(all_moves.size()-4);
						break;
					}
					cout<<"MOVE: "<<move_from<<" to ";
					do{
						if (black_level==1 or black_rand==0){	
							move=(rand()%(move_count[rand_move]-1))+1;	
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move].back()=='-'){
									while (legal_spots[move][rand_move].back()!='-'){
										move=(rand()%(move_count[rand_move]-1))+1;
									}
									break;
								}
							}	
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move].back()=='-'){
									legal_spots[i][rand_move].pop_back();
								}
							}	
							move_to=legal_spots[move][rand_move];
						}
						else if (black_level==2){
							//BIG BOI
							if (attack==true){
								copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
								for (int i=0;i<8;i++){
									for (int k=0;k<8;k++){
										pieces[i][k]=reverse_char(og_board,i,k);
									}
								}
								move_to=to_string(multimax(pieces,3,1,move_from));
								move_to.at(0)=char(move_to.at(0)-'0'+64);
//								cout<<"to: "<<move_to<<endl;
							}
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move].back()=='-'){
									legal_spots[i][rand_move].pop_back();
								}
							}	
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move]==move_to){
									move=i;
									break;
								}
							}
						}
						else if (black_level==3){
							//BIG BOI
							if (attack==true){
								copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
								for (int i=0;i<8;i++){
									for (int k=0;k<8;k++){
										pieces[i][k]=reverse_char(og_board,i,k);
									}
								}
								move_to=to_string(multimax(pieces,5,1,move_from));
//								cout<<"to: "<<move_to<<endl;
								move_to.at(0)=char(move_to.at(0)-'0'+64);
								
							}
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move].back()=='-'){
									legal_spots[i][rand_move].pop_back();
								}
							}	
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move]==move_to){
									move=i;
									break;
								}
							}
						}
//						cout<<move<<"="<<move_to<<endl;
						cout<<move_to<<endl;
						cout.setstate(ios_base::failbit);
						move=checkers_move_to_check(move_to,pieces,'B',x1,y1);
						cout.clear();
						y2=(move_to.at(0)-64)-1;
						x2=(move_to.at(1)-'0')-1;
//						cout<<"move: "<<move<<endl;
//						cout<<"piece: "<<pieces[x2][y2]<<" "<<x2<<"="<<y2<<endl;
						if (move>0){
							pieces[(move%10)-1][(move/10)-1]=' ';
							capture_count=0;
						}
						else{
							capture_count++;
						}
						
						all_moves+=move_to;
						all_moves+=" ";
						pieces[x2][y2]=pieces[x1][y1];
						pieces[x1][y1]=' ';
						
						for (int i=0;i<8;i++){
							if (pieces[0][i]=='b'){
								pieces[0][i]='B';
							}
						}
						if (move<=0){
							break;
						}
						move_from=move_to;
						y1=(move_from.at(0)-64)-1;
						x1=(move_from.at(1)-'0')-1;	
						
						cout.setstate(ios_base::failbit);
						move=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),pieces,'B',x1,y1);
						move2=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),pieces,'B',x1,y1);
						move3=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),pieces,'B',x1,y1);
						move4=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),pieces,'B',x1,y1);
						cout.clear();
						if (move>0 or move2>0 or move3>0 or move4>0){
							system("PAUSE");
							cout<<flush;
							system("CLS");
							create_checkers(pieces);
							cout<<"STILL BLACK TURN\n";
							move_count[rand_move]=1;
							for (int i=1;i<5;i++){
								legal_spots[i][rand_move].clear();
							}
							if (move!=-1){
								legal_spots[move_count[rand_move]][rand_move]=char(y1-2+1+64)+to_string(x1-2+1)+"-";
								move_count[rand_move]++;
//								cout.clear();
//								cout<<legal_spots[move_count[rand_move]-1][rand_move]<<" ";	
//								cout.setstate(ios_base::failbit);
							}
							if (move2!=-1){
								legal_spots[move_count[rand_move]][rand_move]=char(y1+2+1+64)+to_string(x1-2+1)+"-";
								move_count[rand_move]++;
//								cout.clear();
//								cout<<legal_spots[move_count[rand_move]-1][rand_move]<<" ";	
//								cout.setstate(ios_base::failbit);
							}
							if (move3!=-1){
								legal_spots[move_count[rand_move]][rand_move]=char(y1-2+1+64)+to_string(x1+2+1)+"-";
								move_count[rand_move]++;
//								cout.clear();
//								cout<<legal_spots[move_count[rand_move]-1][rand_move]<<" ";	
//								cout.setstate(ios_base::failbit);
							}
							if (move4!=-1){
								legal_spots[move_count[rand_move]][rand_move]=char(y1+2+1+64)+to_string(x1+2+1)+"-";
								move_count[rand_move]++;
//								cout.clear();
//								cout<<legal_spots[move_count[rand_move]-1][rand_move]<<" ";	
//								cout.setstate(ios_base::failbit);
							}
							cout.clear();
							cout<<"MOVE: "<<move_from<<" to ";
							attack=true;
						}
					} while (move>0 or move2>0 or move3>0 or move4>0);	
					attack=false;
					break;
				}
				cout.clear();
			}
		}
		else{
			if (red_player==true){
				if (black_player==false){	
					cout<<"YOUR TURN (RED)\n";
				}
				else{
					cout<<"RED TURN\n";
				}
				while (j>-1){
					cout.setstate(ios_base::failbit);
					if (generate_moves(pieces,'R')==0){
						j=-2;
						cout.clear();
						break;
					}
					cout.clear();
					cout<<"Enter the location of the piece you want to move (Ex. A7): ";
					cin>>move_from;
					if (move_from=="quit"){
						j=-2;
						break;
					}
					if (move_from=="save"){
						save_game(pieces, j%2, capture_count, red_level, black_level);
						save=1;
						cout<<"Game Saved!\n";
						cout.setstate(ios_base::failbit);
					}
					if (move_from=="load" and save==0){
						ifstream saved;			//Create a file object for reading
			    		saved.open("Checkers_save.txt");		//attempt to open the saved_game file 
					    if (saved){		//If the file opens
							j=(load_settings(1))+1;
							capture_count=(load_settings(2));
							black_level=(load_settings(3));
							if (black_level>0){
								black_player==false;
							}
							red_level=(load_settings(4));
							if (red_level>0){
								red_player==false;
							}
							for (int i=1;i<=8;i++){
								for (int k=1;k<=8;k++){
									pieces[i-1][k-1]=load_board(i,k);
								}
						    }
						    copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
							for (int i=0;i<8;i++){
								for (int k=0;k<8;k++){
									pieces[i][k]=reverse_char(og_board,i,k);
								}
							}
							load=1;
						    break;
						}
						else{
							cout<<"There is no saved game!\n";
						}
			    		saved.close();		//closes the file object (just in case)
					}
					move_from.at(0)=toupper(move_from.at(0));
					while (checkers_move_from_check(move_from,pieces,'R')==false){
						cout.clear();
						cout<<"Enter the location of the piece you want to move: ";
						cin>>move_from;
						if (move_from=="quit"){
							j=-2;
							break;
						}
						if (move_from=="save"){
							save_game(pieces, j%2, capture_count, red_level, black_level);
							save=1;
							cout<<"Game Saved!\n";
							continue;
						}
						if (move_from=="load" and save==0){
							ifstream saved;			//Create a file object for reading
				    		saved.open("Checkers_save.txt");		//attempt to open the saved_game file 
						    if (saved){		//If the file opens
								j=(load_settings(1))+1;
								capture_count=(load_settings(2));
								black_level=(load_settings(3));
								if (black_level>0){
									black_player==false;
								}
								red_level=(load_settings(4));
								if (red_level>0){
									red_player==false;
								}
								for (int i=1;i<=8;i++){
									for (int k=1;k<=8;k++){
										pieces[i-1][k-1]=load_board(i,k);
									}
							    }
							    copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
								for (int i=0;i<8;i++){
									for (int k=0;k<8;k++){
										pieces[i][k]=reverse_char(og_board,i,k);
									}
								}
								load=1;
							    break;
							}
							else{
								cout<<"There is no saved game!\n";
							}
				    		saved.close();		//closes the file object (just in case)
						}
						move_from.at(0)=toupper(move_from.at(0));
					}
					if (move_from=="quit"){
						j=-2;
						break;
					}
					if (move_from=="load" and save==0){
						break;
					}
					y1=(move_from.at(0)-64)-1;
					x1=(move_from.at(1)-'0')-1;
					
					all_moves+=move_from;
					all_moves+=" ";
					
					do{
						cout<<"Enter the location you want to move to (or 00 to reselect): ";
						cin>>move_to;
						if (move_to=="00"){
							break;
						}
						if (move_to=="quit"){
							j=-2;
							break;
						}
						if (move_to=="save"){
							save_game(pieces, j%2, capture_count, red_level, black_level);
							save=1;
							cout<<"Game Saved!\n";
							continue;
						}
						if (move_to=="load" and save==0){
							ifstream saved;			//Create a file object for reading
				    		saved.open("Checkers_save.txt");		//attempt to open the saved_game file 
						    if (saved){		//If the file opens
								j=(load_settings(1))+1;
								capture_count=(load_settings(2));
								black_level=(load_settings(3));
								if (black_level>0){
									black_player==false;
								}
								red_level=(load_settings(4));
								if (red_level>0){
									red_player==false;
								}
								for (int i=1;i<=8;i++){
									for (int k=1;k<=8;k++){
										pieces[i-1][k-1]=load_board(i,k);
									}
							    }
							    copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
								for (int i=0;i<8;i++){
									for (int k=0;k<8;k++){
										pieces[i][k]=reverse_char(og_board,i,k);
									}
								}
								load=1;
							    break;
							}
							else{
								cout<<"There is no saved game!\n";
							}
				    		saved.close();		//closes the file object (just in case)
						}
						move_to.at(0)=toupper(move_to.at(0));
						move=checkers_move_to_check(move_to,pieces,'R',x1,y1);
						while (move==-1){
							cout<<"Enter the location you want to move to (or 00 to reselect): ";
							cin>>move_to;
							if (move_to=="00"){
								break;
							}
							if (move_to=="save"){
								save_game(pieces, j%2, capture_count, red_level, black_level);
								save=1;
								cout<<"Game Saved!\n";
								continue;
							}
							if (move_to=="load" and save==0){
								ifstream saved;			//Create a file object for reading
					    		saved.open("Checkers_save.txt");		//attempt to open the saved_game file 
							    if (saved){		//If the file opens
									j=(load_settings(1))+1;
									capture_count=(load_settings(2));
									black_level=(load_settings(3));
									if (black_level>0){
										black_player==false;
									}
									red_level=(load_settings(4));
									if (red_level>0){
										red_player==false;
									}
									for (int i=1;i<=8;i++){
										for (int k=1;k<=8;k++){
											pieces[i-1][k-1]=load_board(i,k);
										}
								    }
								    copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
									for (int i=0;i<8;i++){
										for (int k=0;k<8;k++){
											pieces[i][k]=reverse_char(og_board,i,k);
										}
									}
									load=1;
								    break;
								}
								else{
									cout<<"There is no saved game!\n";
								}
					    		saved.close();		//closes the file object (just in case)
							}
							move_to.at(0)=toupper(move_to.at(0));
							move=checkers_move_to_check(move_to,pieces,'R',x1,y1);
						}
						if (move_to=="00"){
							break;
						}
						if (move_to=="load" and save==0){
							break;
						}
						y2=(move_to.at(0)-64)-1;
						x2=(move_to.at(1)-'0')-1;
						if (move>0){
							pieces[(move%10)-1][(move/10)-1]=' ';
							capture_count=0;
						}
						else{
							capture_count++;
						}
						
						all_moves+=move_to;
						all_moves+=" ";
						pieces[x2][y2]=pieces[x1][y1];
						pieces[x1][y1]=' ';
						
						for (int i=0;i<8;i++){
							if (pieces[0][i]=='r'){
								pieces[0][i]='R';
							}
						}
						if (move<=0){
							break;
						}
						move_from=move_to;
						y1=(move_from.at(0)-64)-1;
						x1=(move_from.at(1)-'0')-1;	
						
						cout.setstate(ios_base::failbit);
						move=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),pieces,'R',x1,y1);
						move2=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),pieces,'R',x1,y1);
						move3=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),pieces,'R',x1,y1);
						move4=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),pieces,'R',x1,y1);
						cout.clear();
//						cout<<move<<" "<<move2<<" "<<move3<<" "<<move4;
						if (move>0 or move2>0 or move3>0 or move4>0){
							system("PAUSE");
							cout<<flush;
							system("CLS");
							create_checkers(pieces);
							cout<<"STILL RED TURN\n";
						}
					} while (move>0 or move2>0 or move3>0 or move4>0);
					
					if (move_to=="00"){
						continue;
					}
					if (move_to=="load" and save==0){
						break;
					}
					break;
				}
			}
			else{
				cout<<"COMPUTER'S TURN (RED)\n";
				legal_spots.clear(); 
				attack_moves.clear();
				legal_spots.resize(5); 
				move_count.clear();
				while (j>-1){	
					for (int i=0;i<8;i++){
						for (int k=0;k<8;k++){
							if (pieces[i][k]=='r' or pieces[i][k]=='R'){
								legal_spots[0].push_back(char(k+1+64)+to_string(i+1));
//								cout<<legal_spots[0][legal_spots[0].size()-1]<<" ";
									
							}
						}
					}
//					cout<<endl;
					legal_spots.resize(5);
					for (int i=0;i<5;i++){
					    legal_spots[i].resize(legal_spots[0].size());
					}
//					cout<<legal_spots[0].size();
					move_count.resize(legal_spots[0].size(),1);
					cout.setstate(ios_base::failbit);
					for (int i=0;i<legal_spots[0].size();i++){
						y1=(legal_spots[0][i].at(0)-64)-1;
						x1=(legal_spots[0][i].at(1)-'0')-1;	
						moves[0]=checkers_move_to_check(char(y1-1+1+64)+to_string(x1-1+1),pieces,'R',x1,y1);
						if (moves[0]!=-1){
							legal_spots[move_count[i]][i]=char(y1-1+1+64)+to_string(x1-1+1);
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[1]=checkers_move_to_check(char(y1+1+1+64)+to_string(x1-1+1),pieces,'R',x1,y1);
						if (moves[1]!=-1){
							legal_spots[move_count[i]][i]=char(y1+1+1+64)+to_string(x1-1+1);
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[2]=checkers_move_to_check(char(y1-1+1+64)+to_string(x1+1+1),pieces,'R',x1,y1);
						if (moves[2]!=-1){
							legal_spots[move_count[i]][i]=char(y1-1+1+64)+to_string(x1+1+1);
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[3]=checkers_move_to_check(char(y1+1+1+64)+to_string(x1+1+1),pieces,'R',x1,y1);
						if (moves[3]!=-1){
							legal_spots[move_count[i]][i]=char(y1+1+1+64)+to_string(x1+1+1);
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[4]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),pieces,'R',x1,y1);
						if (moves[4]!=-1){
							legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1-2+1)+"-";
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[5]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),pieces,'R',x1,y1);
						if (moves[5]!=-1){
							legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1-2+1)+"-";
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[6]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),pieces,'R',x1,y1);
						if (moves[6]!=-1){
							legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1+2+1)+"-";
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						moves[7]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),pieces,'R',x1,y1);
						if (moves[7]!=-1){
							legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1+2+1)+"-";
							move_count[i]++;
//							cout.clear();
//							cout<<legal_spots[move_count[i]-1][i]<<" ";	
//							cout.setstate(ios_base::failbit);
						}
						cout.clear();
//						cout<<endl;
						cout.setstate(ios_base::failbit);
					}
					for (int i=1;i<5;i++){
						if (legal_spots[i].empty()!=true){
							break;
						}
						else if (i==4){
							j=-2;
						}
					}
					if (j==-2){
						break;
					}
					if (red_level==1){
						do{
							rand_move=rand()%legal_spots[0].size();
	//						rand_move=0;
							for (int i=0;i<legal_spots[0].size();i++){
								for (int k=1;k<move_count[i];k++){
									if (legal_spots[k][i].back()=='-'){
										attack_moves.push_back(legal_spots[0][i]);
										break;
									}
								}	
							}
//							for (int i=1;i<move_count[rand_move];i++){
//								if (legal_spots[i][rand_move].back()=='-'){
//									legal_spots[i][rand_move].pop_back();
//								}
//							}	
						} while (legal_spots[1][rand_move].empty() or legal_spots[0][rand_move].empty());
						move_from=legal_spots[0][rand_move];
						if (attack_moves.size()>0){
							move_from=attack_moves[rand()%attack_moves.size()];
							for (int i=0;i<legal_spots[0].size();i++){
								if (move_from==legal_spots[0][i]){
									rand_move=i;
									break;
								}
							}
						}
						all_moves+=move_from;
						all_moves+=" ";
						cout.clear();
//						cout<<rand_move+1<<"=";
//						cout<<move_from;
	//					cout.setstate(ios_base::failbit);
						y1=(move_from.at(0)-64)-1;
						x1=(move_from.at(1)-'0')-1;
						move=1;
					}
					else if (red_level==2){
						red_rand=rand()%4;
						if (red_rand==0){		//BABY MODE (RANDOM)
							do{
								rand_move=rand()%legal_spots[0].size();
//								rand_move=0;
								for (int i=0;i<legal_spots[0].size();i++){
									for (int k=1;k<move_count[i];k++){
										if (legal_spots[k][i].back()=='-'){
											attack_moves.push_back(legal_spots[0][i]);
											break;
										}
									}	
								}
							} while (legal_spots[1][rand_move].empty() or legal_spots[0][rand_move].empty());
							move_from=legal_spots[0][rand_move];
							if (attack_moves.size()>0){
								move_from=attack_moves[rand()%attack_moves.size()];
								for (int i=0;i<legal_spots[0].size();i++){
									if (move_from==legal_spots[0][i]){
										rand_move=i;
										break;
									}
								}
							}
							all_moves+=move_from;
							all_moves+=" ";
							cout.clear();
		//					cout.setstate(ios_base::failbit);
							y1=(move_from.at(0)-64)-1;
							x1=(move_from.at(1)-'0')-1;
							move=1;
						}
						else{		//Hard Mode (REAL AI)
							cout.clear();
							copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
							for (int i=0;i<8;i++){
								for (int k=0;k<8;k++){
									pieces[i][k]=reverse_char(og_board,i,k);
								}
							}
							move=negamax(pieces,3,-1);
//							cout<<"max: "<<move<<"\n";
							move_from=(move/1000)+64;
							move_from+=to_string((move/100)%10);
							for (int i=0;i<legal_spots[0].size();i++){
								if (move_from==legal_spots[0][i]){
									rand_move=i;
									break;
								}
							}
							y1=(move_from.at(0)-64)-1;
							x1=(move_from.at(1)-'0')-1;
							all_moves+=move_from;
							all_moves+=" ";
							move_to=((move/10)%10)+64;
							move_to+=to_string(move%10);
						}
					}
					else{		//Hard Mode (REAL AI)
						cout.clear();
						copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
						for (int i=0;i<8;i++){
							for (int k=0;k<8;k++){
								pieces[i][k]=reverse_char(og_board,i,k);
							}
						}
//						cout<<all_moves<<endl;
						move=negamax(pieces,5,-1);
//						cout<<"hi";
//						cout<<"max: "<<move<<"\n";
						move_from=(move/1000)+64;
						move_from+=to_string((move/100)%10);
						for (int i=0;i<legal_spots[0].size();i++){
							if (move_from==legal_spots[0][i]){
								rand_move=i;
								break;
							}
						}
						y1=(move_from.at(0)-64)-1;
						x1=(move_from.at(1)-'0')-1;
						all_moves+=move_from;
						all_moves+=" ";
						move_to=((move/10)%10)+64;
						move_to+=to_string(move%10);
					}
//					cout<<rand_move+1<<"=";
					if (move==0){
						j=-2;
						all_moves.erase(all_moves.size()-4);
						break;
					}
					cout<<"MOVE: "<<move_from<<" to ";
					do{
						if (red_level==1 or red_rand==0){	
							move=(rand()%(move_count[rand_move]-1))+1;	
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move].back()=='-'){
									while (legal_spots[move][rand_move].back()!='-'){
										move=(rand()%(move_count[rand_move]-1))+1;
									}
									break;
								}
							}	
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move].back()=='-'){
									legal_spots[i][rand_move].pop_back();
								}
							}	
							move_to=legal_spots[move][rand_move];
						}
						else if (red_level==2){
							//BIG BOI
							if (attack==true){
								copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
								for (int i=0;i<8;i++){
									for (int k=0;k<8;k++){
										pieces[i][k]=reverse_char(og_board,i,k);
									}
								}
								move_to=to_string(multimax(pieces,3,-1,move_from));
								move_to.at(0)=char(move_to.at(0)-'0'+64);
//								cout<<"to: "<<move_to<<endl;
							}
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move].back()=='-'){
									legal_spots[i][rand_move].pop_back();
								}
							}	
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move]==move_to){
									move=i;
									break;
								}
							}
						}
						else if (red_level==3){
							//BIG BOI
							if (attack==true){
								copy(&pieces[0][0], &pieces[8][8],&og_board[0][0]);
								for (int i=0;i<8;i++){
									for (int k=0;k<8;k++){
										pieces[i][k]=reverse_char(og_board,i,k);
									}
								}
								move_to=to_string(multimax(pieces,5,-1,move_from));
								move_to.at(0)=char(move_to.at(0)-'0'+64);
//								cout<<"to: "<<move_to<<endl;
							}
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move].back()=='-'){
									legal_spots[i][rand_move].pop_back();
								}
							}	
							for (int i=1;i<move_count[rand_move];i++){
								if (legal_spots[i][rand_move]==move_to){
									move=i;
									break;
								}
							}
						}
//						cout<<move<<"="<<move_to<<endl;
						cout<<move_to<<endl;
						cout.setstate(ios_base::failbit);
						move=checkers_move_to_check(move_to,pieces,'R',x1,y1);
						cout.clear();
						y2=(move_to.at(0)-64)-1;
						x2=(move_to.at(1)-'0')-1;
//						cout<<"move: "<<move<<endl;
//						cout<<"piece: "<<pieces[x2][y2]<<" "<<x2<<"="<<y2<<endl;
						if (move>0){
							pieces[(move%10)-1][(move/10)-1]=' ';
							capture_count=0;
						}
						else{
							capture_count++;
						}
						
						all_moves+=move_to;
						all_moves+=" ";
						pieces[x2][y2]=pieces[x1][y1];
						pieces[x1][y1]=' ';
						
						for (int i=0;i<8;i++){
							if (pieces[0][i]=='r'){
								pieces[0][i]='R';
							}
						}
						if (move<=0){
							break;
						}
						move_from=move_to;
						y1=(move_from.at(0)-64)-1;
						x1=(move_from.at(1)-'0')-1;	
						
						cout.setstate(ios_base::failbit);
						move=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),pieces,'R',x1,y1);
						move2=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),pieces,'R',x1,y1);
						move3=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),pieces,'R',x1,y1);
						move4=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),pieces,'R',x1,y1);
						cout.clear();
						if (move>0 or move2>0 or move3>0 or move4>0){
							system("PAUSE");
							cout<<flush;
							system("CLS");
							create_checkers(pieces);
							cout<<"STILL RED TURN\n";
							move_count[rand_move]=1;
							for (int i=1;i<5;i++){
								legal_spots[i][rand_move].clear();
							}
							if (move!=-1){
								legal_spots[move_count[rand_move]][rand_move]=char(y1-2+1+64)+to_string(x1-2+1)+"-";
								move_count[rand_move]++;
//								cout.clear();
//								cout<<legal_spots[move_count[rand_move]-1][rand_move]<<" ";	
//								cout.setstate(ios_base::failbit);
							}
							if (move2!=-1){
								legal_spots[move_count[rand_move]][rand_move]=char(y1+2+1+64)+to_string(x1-2+1)+"-";
								move_count[rand_move]++;
//								cout.clear();
//								cout<<legal_spots[move_count[rand_move]-1][rand_move]<<" ";	
//								cout.setstate(ios_base::failbit);
							}
							if (move3!=-1){
								legal_spots[move_count[rand_move]][rand_move]=char(y1-2+1+64)+to_string(x1+2+1)+"-";
								move_count[rand_move]++;
//								cout.clear();
//								cout<<legal_spots[move_count[rand_move]-1][rand_move]<<" ";	
//								cout.setstate(ios_base::failbit);
							}
							if (move4!=-1){
								legal_spots[move_count[rand_move]][rand_move]=char(y1+2+1+64)+to_string(x1+2+1)+"-";
								move_count[rand_move]++;
//								cout.clear();
//								cout<<legal_spots[move_count[rand_move]-1][rand_move]<<" ";	
//								cout.setstate(ios_base::failbit);
							}
							cout.clear();
							cout<<"MOVE: "<<move_from<<" to ";
							attack=true;
						}
					} while (move>0 or move2>0 or move3>0 or move4>0);	
					attack=false;
					break;
				}
				cout.clear();
			}
		}
		system("PAUSE");
		if (j==-2){
			black_win=true;
			j=-1;
		}
		if (j==-3){
			red_win=true;
			j=0;
		}
	}
	if (load==0){
		cout<<"\nYou can recreate a game by pasting in these moves in Human v Human mode.";
		cout<<"\nAll moves: "<<all_moves<<endl;
	}
	system("PAUSE");
}

char reverse_char(char board[8][8],int x, int y){
	char r_char;
	r_char=board[7-x][7-y];
	return r_char;
}

void save_game(char board[8][8], int turn, int capture, int red_cpu, int black_cpu){
	fstream save;									//Create a file object for reading/writing
    save.open("Checkers_save.txt");					// attempt to open the highscore file
    if (!save){										//If the file does not open
        save.open("Checkers_save.txt", ios::out);		//Create and open a highscore file for writing
    }	
    save<<turn<<","<<capture<<","<<black_cpu<<","<<red_cpu<<endl;					//Write to the highscore file
    for (int j=0;j<8;j++){
    	for (int k=0;k<8;k++){
    		save<<board[j][k];
		}
		save<<endl;
	}
    save.close();
}

int load_settings(int option){
	string phrase;
	int comma1,comma2,comma3;
	
    ifstream file2("Checkers_save.txt");			//opens the highscore file for input
	file2>>phrase;		//Reads in a line from the spreadsheet
	file2.close();
	comma1=phrase.find(',');
	comma2=phrase.find(',', comma1+1);
	comma3=phrase.find(',', comma2+1);
	if (option==1){
		return (stoi(phrase.substr(0,comma1)));
	}
	else if (option==2){
		return stoi(phrase.substr(comma1+1,comma2));
	}
	else if (option==3){
		return stoi(phrase.substr(comma2+1,comma3));
	}
	else{
		return stoi(phrase.substr(comma3+1)); 
	}
}

char load_board(int x, int y){
	string phrase;
	
    ifstream file2("Checkers_save.txt");			//opens the highscore file for input
    for (int i=0;i<9;i++){		//Until the current row reaches the total row count
		getline(file2,phrase);		//Reads in a line from the spreadsheet
		if (phrase.at(0)=='0' or phrase.at(0)=='1'){
			continue;
		}
		else{		//If its not the first line
			if (x==i){
//					cout<<y-1;
				return phrase.at(y-1);
			}
		}
	}
	file2.close();
	
	if (x==7 and y==7){
		remove("Checkers_save.txt");		//Delete the highscore file
	}
}

int generate_moves(char board[8][8], char color){
	vector<vector <string>> legal_spots(5);
	vector <int> move_count;
	int moves[8];
	int x1,y1;
	
	legal_spots.resize(5); 
	for (int i=0;i<8;i++){
		for (int k=0;k<8;k++){
			if (toupper(board[i][k])==color){
				legal_spots[0].push_back(char(k+1+64)+to_string(i+1));
					
			}
		}
	}
	legal_spots.resize(5);
	for (int i=0;i<5;i++){
	    legal_spots[i].resize(legal_spots[0].size());
	}
	move_count.resize(legal_spots[0].size(),1);
	cout.setstate(ios_base::failbit);
	for (int i=0;i<legal_spots[0].size();i++){
		y1=(legal_spots[0][i].at(0)-64)-1;
		x1=(legal_spots[0][i].at(1)-'0')-1;	
		moves[0]=checkers_move_to_check(char(y1-1+1+64)+to_string(x1-1+1),board,color,x1,y1);
		if (moves[0]!=-1){
			legal_spots[move_count[i]][i]=char(y1-1+1+64)+to_string(x1-1+1);
			move_count[i]++;
			return 1;
		}
		moves[1]=checkers_move_to_check(char(y1+1+1+64)+to_string(x1-1+1),board,color,x1,y1);
		if (moves[1]!=-1){
			legal_spots[move_count[i]][i]=char(y1+1+1+64)+to_string(x1-1+1);
			move_count[i]++;
			return 1;
		}
		moves[2]=checkers_move_to_check(char(y1-1+1+64)+to_string(x1+1+1),board,color,x1,y1);
		if (moves[2]!=-1){
			legal_spots[move_count[i]][i]=char(y1-1+1+64)+to_string(x1+1+1);
			move_count[i]++;
			return 1;
		}
		moves[3]=checkers_move_to_check(char(y1+1+1+64)+to_string(x1+1+1),board,color,x1,y1);
		if (moves[3]!=-1){
			legal_spots[move_count[i]][i]=char(y1+1+1+64)+to_string(x1+1+1);
			move_count[i]++;
			return 1;
		}
		moves[4]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1-2+1),board,color,x1,y1);
		if (moves[4]!=-1){
			legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1-2+1)+"-";
			move_count[i]++;
			return 1;
		}
		moves[5]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1-2+1),board,color,x1,y1);
		if (moves[5]!=-1){
			legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1-2+1)+"-";
			move_count[i]++;
			return 1;
		}
		moves[6]=checkers_move_to_check(char(y1-2+1+64)+to_string(x1+2+1),board,color,x1,y1);
		if (moves[6]!=-1){
			legal_spots[move_count[i]][i]=char(y1-2+1+64)+to_string(x1+2+1)+"-";
			move_count[i]++;
			return 1;
		}
		moves[7]=checkers_move_to_check(char(y1+2+1+64)+to_string(x1+2+1),board,color,x1,y1);
		if (moves[7]!=-1){
			legal_spots[move_count[i]][i]=char(y1+2+1+64)+to_string(x1+2+1)+"-";
			move_count[i]++;
			return 1;
		}
	}
	
	return 0;
}

bool checkers_move_from_check(string move, char board[8][8], char color){
	int x,y;
	vector <string> attack_pieces;
	int move1,move2,move3,move4;
	bool attacker=false;
	
	if (move.length()!=2){
		cout<<"That is not a legal spot! Retry.\n";
		return false;
	}
	if (isalpha(move.at(0))==false){
		cout<<"That is not a legal spot! Retry.\n";
		return false;
	}
	if (isdigit(move.at(1))==false){
		cout<<"That is not a legal spot! Retry.\n";
		return false;
	}
	y=(move.at(0)-64)-1;
	x=(move.at(1)-'0')-1;
	if (y<0 or y>7 or x<0 or x>7){
		cout<<"That is not a legal spot! Retry.\n";
		return false;
	}
	if (color=='B'){
		if (board[x][y]!='b' and board[x][y]!='B'){
			cout<<"That is not a legal spot! Retry.\n";
			return false;
		}
	}
	else{
		if (board[x][y]!='r' and board[x][y]!='R'){
			cout<<"That is not a legal spot! Retry.\n";
			return false;
		}
	}
	cout.setstate(ios_base::failbit);
	for (int i=0;i<8;i++){
		for (int j=0;j<8;j++){
			if (toupper(board[i][j])==color){	
				move1=checkers_move_to_check(char(j-2+1+64)+to_string(i-2+1),board,color,i,j);
				move2=checkers_move_to_check(char(j+2+1+64)+to_string(i-2+1),board,color,i,j);
				move3=checkers_move_to_check(char(j-2+1+64)+to_string(i+2+1),board,color,i,j);
				move4=checkers_move_to_check(char(j+2+1+64)+to_string(i+2+1),board,color,i,j);
				if (move1>0 or move2>0 or move3>0 or move4>0){
					attack_pieces.push_back(char(j+1+64)+to_string(i+1));
//					cout<<attack_pieces[attack_pieces.size()-1]<<" "<<move1<<" "<<move2<<" "<<move3<<" "<<move4<<endl;
				}
			}
		}
	}
	cout.clear();
	if (attack_pieces.size()>0){
		for (int i=0;i<attack_pieces.size();i++){
			if (move==attack_pieces[i]){
				attacker=true;
				break;
			}
		}
		if (attacker==false){
			cout<<"You must attack if you can! Retry.\n";
			return false;
		}
	}
	
	return true;
}

int checkers_move_to_check(string move, char board[8][8], char color, int x1, int y1){
	int x2,y2;
	bool attack[5];
	for (int i=0;i<5;i++){
		attack[i]=false;
	}
	
	if (move.length()!=2){
		cout<<"That is not a legal spot! Retry.\n";
		return -1;
	}
	if (isalpha(move.at(0))==false){
		cout<<"That is not a legal spot! Retry.\n";
		return -1;
	}
	if (isdigit(move.at(1))==false){
		cout<<"That is not a legal spot! Retry.\n";
		return -1;
	}
	y2=(move.at(0)-64)-1;
	x2=(move.at(1)-'0')-1;
	if (board[x2][y2]!=' '){
		cout<<"You can't land on other pieces! Retry.\n";
		return -1;
	}
	
	if (y2<0 or y2>7 or x2<0 or x2>7){
		cout<<"That is not a legal spot! Retry.\n";
		return -1;
	}
	if (!(abs(x2-x1)==abs(y2-y1))){
		cout<<"You can only move diagonally! Retry.\n";
		return -1;
	}
	if (x2<=x1 and islower(board[x1][y1]!=false)){
		cout<<"You can only move diagonally forwards! Retry.\n";
		return -1;
	}
	if (isupper(board[x1][y1])!=false){		//BIG BOI		(Work on this after normal movement for smol boi)
		if (color=='B'){
			if ((board[x1-1][y1+1]=='r' or board[x1-1][y1+1]=='R') and board[x1-2][y1+2]==' '){
				if (x1-2>=0 and x1-2<8 and y1+2>=0 and y1+2<8){	
					attack[0]=true;
					attack[4]=true;
				}		//Up-Right
			}
			if ((board[x1-1][y1-1]=='r' or board[x1-1][y1-1]=='R') and board[x1-2][y1-2]==' '){
				if (x1-2>=0 and x1-2<8 and y1-2>=0 and y1-2<8){	
					attack[1]=true;
					attack[4]=true;
				}		//Up-Left
			}
			if ((board[x1+1][y1+1]=='r' or board[x1+1][y1+1]=='R') and board[x1+2][y1+2]==' '){
				if (x1+2>=0 and x1+2<8 and y1+2>=0 and y1+2<8){	
					attack[2]=true;
					attack[4]=true;	
				}		//Down-Right
			}
			if ((board[x1+1][y1-1]=='r' or board[x1+1][y1-1]=='R') and board[x1+2][y1-2]==' '){
				if (x1+2>=0 and x1+2<8 and y1-2>=0 and y1-2<8){	
					attack[3]=true;
					attack[4]=true;
				}		//Down-Left
			}	
		}
		if (color=='R'){
			if ((board[x1-1][y1+1]=='b' or board[x1-1][y1+1]=='B') and board[x1-2][y1+2]==' '){
				if (x1-2>=0 and x1-2<8 and y1+2>=0 and y1+2<8){		
					attack[0]=true;
					attack[4]=true;
				}		//Up-Right
			}
			if ((board[x1-1][y1-1]=='b' or board[x1-1][y1-1]=='B') and board[x1-2][y1-2]==' '){
				if (x1-2>=0 and x1-2<8 and y1-2>=0 and y1-2<8){	
					attack[1]=true;
					attack[4]=true;
				}		//Up-Left
			}
			if ((board[x1+1][y1+1]=='b' or board[x1+1][y1+1]=='B') and board[x1+2][y1+2]==' '){
				if (x1+2>=0 and x1+2<8 and y1+2>=0 and y1+2<8){	
					attack[2]=true;
					attack[4]=true;
				}		//Down-Right
			}
			if ((board[x1+1][y1-1]=='b' or board[x1+1][y1-1]=='B') and board[x1+2][y1-2]==' '){
				if (x1+2>=0 and x1+2<8 and y1-2>=0 and y1-2<8){		
					attack[3]=true;
					attack[4]=true;
				}		//Down-Left
			}	
		}
//		cout<<attack[0]<<" "<<attack[1]<<" "<<attack[2]<<" "<<attack[3]<<" "<<attack[4];
//		cout<<endl<<x1+2<<"="<<x2<<"&"<<y1-2<<"="<<y2<<endl<<x1+1<<"+"<<y1-1<<"=="<<board[x1+1][y1-1]<<endl;
		if (attack[4]==true){
			if (!((x2==x1+2 or x2==x1-2) and (y2==y1+2 or y2==y1-2))){
				cout<<"You must attack if you can! Retry.\n";
				return -1;
			}
			if (attack[0]==true and x1-2==x2 and y1+2==y2){	
//				cout<<" "<<(y1+1+1)*10+(x1-1+1);
				return (y1+2)*10+(x1);
			}
			if (attack[1]==true and x1-2==x2 and y1-2==y2){	
//				cout<<" "<<(y1-1+1)*10+(x1-1+1);
				return (y1)*10+(x1);
			}
			if (attack[2]==true and x1+2==x2 and y1+2==y2){	
//				cout<<" "<<(y1+1+1)*10+(x1+1+1);
				return (y1+2)*10+(x1+2);
			}
			if (attack[3]==true and x1+2==x2 and y1-2==y2){	
//				cout<<" "<<(y1-1+1)*10+(x1+1+1);
				return (y1)*10+(x1+2);
			}
			attack[4]=false;
//			cout<<"hi";
		}
		if (attack[4]==false){		//Normal Movement
			if ((x2!=x1+1 and x2!=x1-1) or (y2!=y1+1 and y2!=y1-1)){
				cout<<"You can only move diagonally! Retry.\n";
				return -1;
			}
		}
	}
	else{		//SMOL BOI
		if (color=='B'){
			if ((board[x1-1][y1+1]=='r' or board[x1-1][y1+1]=='R') and board[x1-2][y1+2]==' '){
				if (x1-2>=0 and x1-2<8 and y1+2>=0 and y1+2<8){	
					attack[0]=true;
					attack[4]=true;
				}		//Up-Right
			}
			if ((board[x1-1][y1-1]=='r' or board[x1-1][y1-1]=='R') and board[x1-2][y1-2]==' '){
				if (x1-2>=0 and x1-2<8 and y1-2>=0 and y1-2<8){	
					attack[1]=true;
					attack[4]=true;
				}		//Up-Left
			}	
		}
		if (color=='R'){
			if ((board[x1-1][y1+1]=='b' or board[x1-1][y1+1]=='B') and board[x1-2][y1+2]==' '){
				if (x1-2>=0 and x1-2<8 and y1+2>=0 and y1+2<8){		
					attack[0]=true;
					attack[4]=true;
				}		//Up-Right
			}
			if ((board[x1-1][y1-1]=='b' or board[x1-1][y1-1]=='B') and board[x1-2][y1-2]==' '){
				if (x1-2>=0 and x1-2<8 and y1-2>=0 and y1-2<8){	
					attack[1]=true;
					attack[4]=true;
				}		//Up-Left
			}	
		}
//		cout<<attack[4];
//		cout<<endl<<x1-2<<"="<<x2<<"&"<<y1-2<<"="<<y2<<endl<<x1-1<<"+"<<y1-1<<"=="<<board[x1-1][y1-1]<<endl;
		if (attack[4]==true){
			if (!((x2==x1+2 or x2==x1-2) and (y2==y1+2 or y2==y1-2))){
				cout<<"You must attack if you can! Retry.\n";
				return -1;
			}
			if (attack[0]==true and x1-2==x2 and y1+2==y2){	
//				cout<<" "<<(y1+1+1)*10+(x1-1+1);
				return (y1+2)*10+(x1);
			}
			if (attack[1]==true and x1-2==x2 and y1-2==y2){	
//				cout<<" "<<(y1-1+1)*10+(x1-1+1);
				return (y1)*10+(x1);
			}
			attack[4]=false;
//			cout<<"hi";
		}
		if (attack[4]==false){		//Normal Movement
			if (x2!=x1-1 or (y2!=y1+1 and y2!=y1-1)){
				cout<<"You can only move diagonally forwards! Retry.\n";
				return -1;
			}
		}
	}
	return 0;
}

void create_checkers(char board[8][8]){
	int row,col,color;
	wstring row_num;
	ostringstream hex_bg;
	string back, back2;
	int bg=0;
	int bg2=0;
	wchar_t piece;
	
	row_num=L"  \uFF10";
	
	cout<<flush;
	system("CLS");
	_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
	wcout<<L"\u2503     \u2595\u258F    \u2595\u258F    \u2595\u258F    \u2595\u258F    \u2595\u258F    \u2595\u258F    \u2595\u258F     \u2503\n";
	wcout<<L"\u2503  \uFF21 \u2595\u258F \uFF22 \u2595\u258F \uFF23 \u2595\u258F \uFF24 \u2595\u258F \uFF25 \u2595\u258F \uFF26 \u2595\u258F \uFF27 \u2595\u258F \uFF28  \u2503\n";
	wcout<<L"\u2503     \u2595\u258F    \u2595\u258F    \u2595\u258F    \u2595\u258F    \u2595\u258F    \u2595\u258F    \u2595\u258F     \u2503\n";
	_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
	
	while (bg==15 or bg==0){
		bg=rand()%16;
	}
	bg=7;
	hex_bg<<"0x"<<hex<<bg;
	back=hex_bg.str()+"0";
	hex_bg.str("");
	hex_bg.clear();
	
	while (bg2==bg or bg2==15 or bg2==0){
		bg2=rand()%16;
	}
	bg2=8;
	hex_bg<<"0x"<<hex<<bg2;
	back2=hex_bg.str()+"0";
	
	bg=stoi(back,nullptr,0);
	bg2=stoi(back2,nullptr,0);
	
	
	HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );                                  // h is your link to the console
	_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
	wcout<<L"\u250F";
	for (int i=0;i<48;i++){
		wcout<<L"\u2501";	
	}
	wcout<<L"\u2513";
	wcout<<L"\u2501\u2501\u2501\u2501\u2501\u2501";
	_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
	
	cout<<endl;
	for (int j=0;j<8;j++){
		for (int k=0;k<3;k++){
			
			SetConsoleTextAttribute( h, 7 | 0x00 );
			_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
			wcout<<L"\u2503";	
			_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
			
			for (int i=0;i<4;i++){
				if ((j<2 or j>5) and k==1){					
					if (j<2){
						color=15;
					}
					else{
						color=0;
					}
				}
				if (j%2==0){
					SetConsoleTextAttribute( h, color | bg );
					_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
					wcout<<L"      ";	
					_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
					SetConsoleTextAttribute( h, color | bg2 );
					_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
					wcout<<L"      ";	
					_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
				}
				else{
					SetConsoleTextAttribute( h, color | bg2 );
					_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
					wcout<<L"      ";	
					_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
					SetConsoleTextAttribute( h, color | bg );
					_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
					wcout<<L"      ";	
					_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
				}			
			}
			
			SetConsoleTextAttribute( h, 7 | 0x00 );
			_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
			wcout<<L"\u2503";
			if (k==1){
				row_num.back()++;
				wcout<<row_num;
			}
			if (k==2 and j<7){
				wcout<<L"\u2581\u2581\u2581\u2581\u2581\u2581";
			}
			_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
			cout<<endl;
		}
	}
	
	SetConsoleTextAttribute( h, 7 | 0x00 );
	
	_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
	wcout<<L"\u2517";
	for (int i=0;i<48;i++){
		wcout<<L"\u2501";	
	}
	wcout<<L"\u251B";
	wcout<<L"\u2501\u2501\u2501\u2501\u2501\u2501";
	_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
	
	
	for (int i=0;i<8;i++){
		for (int j=0;j<8;j++){
			if (board[i][j]=='r'){
				color=4;
				piece=L'\u26C2';
			}
			else if (board[i][j]=='R'){
				color=4;
				piece=L'\u26C3';
			}
			else if (board[i][j]=='b'){
				color=0;
				piece=L'\u26C2';
			}
			else if (board[i][j]=='B'){
				color=0;
				piece=L'\u26C3';
			}
			else{
				continue;
			}
			row=i+1;
			col=j+1;
			
			if (row%2==1){
				if (col%2==1){
					bg=stoi(back,nullptr,0);
				}
				else{
					bg=stoi(back2,nullptr,0);
				}
			}
			else{
				if (col%2==1){
					bg=stoi(back2,nullptr,0);
				}
				else{
					bg=stoi(back,nullptr,0);
				}
			}
			cout<<"\x1b[s";
			cout<<"\x1b[4;"<<((col-1)*6)+5<<"H\x1b["<<row*3-1<<"B\b";
				
			_setmode(_fileno(stdout), _O_U16TEXT);		//Sets text mode to unicode
			SetConsoleTextAttribute( h, color | bg );
			wcout<<piece;
			SetConsoleTextAttribute( h, 0 | 0x00 );
			_setmode(_fileno(stdout), _O_TEXT);		//Sets text mode back to normal
			
			cout<<"\x1b[u";
		}
	}
	

	cout<<endl;
}


//Minesweeper

void minesweeper(){    
	SetConsoleOutputCP(CP_UTF8);
	HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );
	srand(time(0));
	int rows,cols,mines,flags;
	string bomb="\U0001F4A3";
	string explode="\U0001F4A5";
	string flag="\U0001F6A9";
	string blank="\U0001F532";
	string emoji="\U0001F642";
    int menu_choice=0;
    int difficulty=0;
    int end_choice;
    bool restart;
    int lose;
    int colored=0;
    int prev_state;
    int prev_event;
    int colorX,colorY;
    int firstX,firstY;
    int temp_mines;
    string password;
    
	DWORD cNumRead, fdwMode,i;
    INPUT_RECORD irInBuf[128];
    
    fstream highscore;			//Create a file object for reading/writing
    highscore.open("highscores.csv");		// attempt to open the highscore file
    if (!highscore){		//If the file does not open
        highscore.open("highscores.csv", ios::out);		//Create and open a highscore file for writing
        highscore<<"Highscores"<<endl;		//Write to the highscore file
    }	
    highscore.close();		//close the highscore file
	

    hStdin = GetStdHandle(STD_INPUT_HANDLE);		// Get the standard input handle. 
    if (hStdin == INVALID_HANDLE_VALUE){
		ErrorExit("GetStdHandle");
    }
    if (!GetConsoleMode(hStdin, &fdwSaveOldMode)){		// Save the current input mode, to be restored on exit. 
    	ErrorExit("GetConsoleMode");
    }
	do{
	    fdwMode = ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;		// Enable the window and mouse input events. 
	    if (!SetConsoleMode(hStdin, fdwMode)){
			ErrorExit("SetConsoleMode");
		}
		menu_choice=0;
		seconds=0;
		end_choice=1;
		lose=1;
		difficulty=0;
		restart=true;
		firstX=-1;
		firstY=-1;
//		stop=false;
	    Center_text("    __  ________   ______________       __________________  __________ ");
		cout<<"\n";
		Center_text("   /  |/  /  _/ | / / ____/ ___/ |     / / ____/ ____/ __ \\/ ____/ __ \\");
		cout<<"\n";
		Center_text("  / /|_/ // //  |/ / __/  \\__ \\| | /| / / __/ / __/ / /_/ / __/ / /_/ /");
		cout<<"\n";
		Center_text(" / /  / // // /|  / /___ ___/ /| |/ |/ / /___/ /___/ ____/ /___/ _, _/ ");
		cout<<"\n";
		Center_text("/_/  /_/___/_/ |_/_____//____/ |__/|__/_____/_____/_/   /_____/_/ |_|  ");
		cout<<"\n\n\n\n";
		
		
		Center_text("   ___  __                __ __    __          ____       _ __ ");			//For all 7<y<13
		cout<<"\n";
		Center_text("  / _ \\/ /__ ___ __      / // /__ / /__       / __ \\__ __(_) /_");			//Play is 26<x<45
		cout<<"\n";
		Center_text(" / ___/ / _ `/ // /     / _  / -_) / _ \\     / /_/ / // / / __/");			//Help is 50<x<68
		cout<<"\n";
		Center_text("/_/  /_/\\_,_/\\_, /     /_//_/\\__/_/ .__/     \\___\\_\\_,_/_/\\__/ ");	//Quit is 73<x<91
		cout<<"\n";
		Center_text("            /___/                /_/                           ");
		cout<<"\n\n\n\n";
		
		
		Center_text("   __               __        __                    __");		//16<y<21
		cout<<"\n";
		Center_text("  / /  ___ ___ ____/ /__ ____/ /  ___  ___ ________/ /");		//32<x<87
		cout<<"\n";
		Center_text(" / /__/ -_) _ `/ _  / -_) __/ _ \\/ _ \\/ _ `/ __/ _  / ");
		cout<<"\n";
		Center_text("/____/\\__/\\_,_/\\_,_/\\__/_/ /_.__/\\___/\\_,_/_/  \\_,_/  ");
		cout<<"\n\n\n\e[1m\e[6m";
		Center_text("Click to select");
		cout<<"\n\n\e[0m";
		
		cout<<"\e[?25l";
		
	    // Loop to read and handle the next 500 input events. 	
		cout<<flush;
		while (menu_choice==0){
	        if (!ReadConsoleInput(hStdin,irInBuf,128,&cNumRead)){
	            ErrorExit("ReadConsoleInput");
	        }
	        for (i = 0; i < cNumRead; i++){
				if (event_type==MOUSE_EVENT){ // mouse input 
					if (mouse_event==0 and mouse_state == left_click and MouseY>7 and MouseY<13){
						if (MouseX>31 and MouseX<51){
				            menu_choice=1;
						}
						else if (MouseX>54 and MouseX<72){		
				            menu_choice=2;
						}
						else if (MouseX>76 and MouseX<95){		
				            menu_choice=3;
						}
			        }
					if (mouse_event==0 and mouse_state == left_click and MouseX>36 and MouseX<91 and MouseY>15 and MouseY<20){
						menu_choice=4;
					}
			        else if (mouse_event==1){
						if (MouseX>31 and MouseX<51 and MouseY>7 and MouseY<13){
							if (colored!=1){
								cout<<"\e[s\e[?25l\e[9;52H";
								cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
				        		cout<<"\e[30;103m   ___  __         ";			//For all 7<y<13
								
								cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
								cout<<"  / _ \\/ /__ ___ __";			//Play is 26<x<45
								
								cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
								cout<<" / ___/ / _ `/ // /";			//Help is 50<x<68
								
								cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
								cout<<"/_/  /_/\\_,_/\\_, / ";	//Quit is 73<x<91
								
								cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
								cout<<"            /___/  \e[0;0m";
								cout<<"\e[u";
								colored=1;
							}
						}
						else if (MouseX>54 and MouseX<72 and MouseY>7 and MouseY<13){	
							if (colored!=2){
								cout<<"\e[s\e[?25l\e[9;73H";
								cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
				        		cout<<"\e[30;103m   __ __    __   ";			//For all 7<y<13
								
								cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
								cout<<"  / // /__ / /__ ";			//Play is 26<x<45
								
								cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
								cout<<" / _  / -_) / _ \\";			//Help is 50<x<68
								
								cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
								cout<<"/_//_/\\__/_/ .__/";	//Quit is 73<x<91
								
								cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
								cout<<"          /_/    \e[0;0m";
								cout<<"\e[u";
								colored=2;
							}
						}
						else if (MouseX>76 and MouseX<95 and MouseY>7 and MouseY<13){		
							if (colored!=3){
								cout<<"\e[s\e[9;96H";
								cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
				        		cout<<"\e[30;103m  ____       _ __ ";			//For all 7<y<13
								
								cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
								cout<<" / __ \\__ __(_) /_";			//Play is 26<x<45
								
								cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
								cout<<"/ /_/ / // / / __/";			//Help is 50<x<68
								
								cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
								cout<<"\\___\\_\\_,_/_/\\__/ ";	//Quit is 73<x<91
								
								cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
								cout<<"                  \e[0;0m";
								cout<<"\e[u";
								colored=3;
							}
						}
						else if (MouseX>36 and MouseX<91 and MouseY>15 and MouseY<20){		
							if (colored!=4){
								cout<<"\e[s\e[17;92H";
								cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
				        		cout<<"\e[30;103m   __               __        __                    __";			//For all 7<y<13
								
								cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
								cout<<"  / /  ___ ___ ____/ /__ ____/ /  ___  ___ ________/ /";			//Help is 50<x<68
								
								cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
								cout<<" / /__/ -_) _ `/ _  / -_) __/ _ \\/ _ \\/ _ `/ __/ _  / ";	//Quit is 73<x<91
								
								cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
								cout<<"/____/\\__/\\_,_/\\_,_/\\__/_/ /_.__/\\___/\\_,_/_/  \\_,_/  \e[0;0m";
								cout<<"\e[u";
								colored=4;
							}
						}	
						else if (colored==1){
							cout<<"\e[s\e[9;1H\e[9;52H";
							cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
			        		cout<<"   ___  __         ";			//For all 7<y<13
							
							cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
							cout<<"  / _ \\/ /__ ___ __";			//Play is 26<x<45
							
							cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
							cout<<" / ___/ / _ `/ // /";			//Help is 50<x<68
							
							cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
							cout<<"/_/  /_/\\_,_/\\_, / ";	//Quit is 73<x<91
							
							cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
							cout<<"            /___/  ";
							cout<<"\e[u";
							colored=0;
						}
						else if (colored==2){
							cout<<"\e[s\e[9;1H\e[9;73H";
							cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
			        		cout<<"   __ __    __   ";			//For all 7<y<13
							
							cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
							cout<<"  / // /__ / /__ ";			//Play is 26<x<45
							
							cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
							cout<<" / _  / -_) / _ \\";			//Help is 50<x<68
							
							cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
							cout<<"/_//_/\\__/_/ .__/";	//Quit is 73<x<91
							
							cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
							cout<<"          /_/    ";
							cout<<"\e[u";
							colored=0;
						}
						else if (colored==3){
							cout<<"\e[s\e[9;1H\e[9;96H";
							cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
			        		cout<<"  ____       _ __ ";			//For all 7<y<13
							
							cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
							cout<<" / __ \\__ __(_) /_";			//Play is 26<x<45
							
							cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
							cout<<"/ /_/ / // / / __/";			//Help is 50<x<68
							
							cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
							cout<<"\\___\\_\\_,_/_/\\__/ ";	//Quit is 73<x<91
							
							cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
							cout<<"                  ";
							cout<<"\e[u";
							colored=0;
						}
						else if (colored==4){								
							cout<<"\e[s\e[18;1H\e[17;92H";
							cout<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
			        		cout<<"   __               __        __                    __";			//For all 7<y<13
							
							cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
							cout<<"  / /  ___ ___ ____/ /__ ____/ /  ___  ___ ________/ /";			//Help is 50<x<68
							
							cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
							cout<<" / /__/ -_) _ `/ _  / -_) __/ _ \\/ _ \\/ _ `/ __/ _  / ";	//Quit is 73<x<91
							
							cout<<"\e[1B\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
							cout<<"/____/\\__/\\_,_/\\_,_/\\__/_/ /_.__/\\___/\\_,_/_/  \\_,_/  ";
							cout<<"\e[u";
							colored=0;
						}
	//		        	cout<<"\tX: "<<MouseX<<"\tY: "<<MouseY<<"\tChar: "<<get_char(MouseX,MouseY)<<endl;
					}
	            }
	        }
	    }
	    cout<<flush;
	    system("CLS");
	    
	    fdwMode = ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;		// Enable the window and mouse input events. 
	    if (!SetConsoleMode(hStdin, fdwMode)){
	    	ErrorExit("SetConsoleMode");
		}
	        
	    if (menu_choice==1){
			Center_text("Difficulty");
			cout<<"\n\n\n";
			Center_text("Easy");
			cout<<"\n\n";
			Center_text("Medium");
			cout<<"\n\n";
			Center_text("Hard");
			cout<<"\n\n";
			Center_text("Custom");\
			cout<<"\n\n\e[1m\e[6m";
			Center_text("Press Escape to Return");
			cout<<"\e[0m";
			while (difficulty==0){
		        if (!ReadConsoleInput(hStdin,irInBuf,128,&cNumRead)){
		            ErrorExit("ReadConsoleInput");
		        }
		        for (i = 0; i < cNumRead; i++){
		        	if (event_type == KEY_EVENT){	 // keyboard input 
	                	if (!key_pressed and key==VK_ESCAPE){
							difficulty=-1;
							break;
						}
					}
					else if (event_type==MOUSE_EVENT){ // mouse input 
						if (mouse_event==0 and mouse_state == left_click){
							if (MouseX>61 and MouseX<66 and MouseY==3){
					            difficulty=1;
							}
							else if (MouseX>60 and MouseX<67 and MouseY==5){		
					            difficulty=2;
							}
							else if (MouseX>61 and MouseX<66 and MouseY==7){		
					            difficulty=3;
							}
							else if (MouseX>60 and MouseX<67 and MouseY==9){		
					            difficulty=4;
							}
				        } 
				        else if (mouse_event==1){
				        	if (MouseX>61 and MouseX<66 and MouseY==3){
				        		if (colored!=1){
					        		cout<<"\e[s\e[?25l\e[4;67H\b\b\b\b";
					        		cout<<"\e[30;103mEasy\e[0;0m\e[u";
									colored=1;
								}
							}
							else if (MouseX>60 and MouseX<67 and MouseY==5){
				        		if (colored!=2){
					        		cout<<"\e[s\e[?25l\e[6;68H\b\b\b\b\b\b";
					        		cout<<"\e[30;103mMedium\e[0;0m\e[u";
									colored=2;
								}
							}
							else if (MouseX>61 and MouseX<66 and MouseY==7){
				        		if (colored!=3){
					        		cout<<"\e[s\e[?25l\e[8;67H\b\b\b\b";
					        		cout<<"\e[30;103mHard\e[0;0m\e[u";
									colored=3;
								}
							}
							else if (MouseX>60 and MouseX<67 and MouseY==9){
				        		if (colored!=4){
					        		cout<<"\e[s\e[?25l\e[10;68H\b\b\b\b\b\b";
					        		cout<<"\e[30;103mCustom\e[0;0m\e[u";
									colored=4;
								}
							}
							else if (colored==1){
								cout<<"\e[s\e[?25l\e[4;67H\b\b\b\bEasy";
								colored=0;
							}
							else if (colored==2){
								cout<<"\e[s\e[?25l\e[6;68H\b\b\b\b\b\bMedium";
								colored=0;							
							}
							else if (colored==3){
								cout<<"\e[s\e[?25l\e[8;67H\b\b\b\bHard";
								colored=0;	
							}
							else if (colored==4){
								cout<<"\e[s\e[?25l\e[10;68H\b\b\b\b\b\bCustom";
								colored=0;	
							}
//				        	cout<<"\tX: "<<MouseX<<"\tY: "<<MouseY<<"\tChar: "<<get_char(MouseX,MouseY)<<endl;
						}
		            }
		        }
		    }
			
		    cout<<flush;
		    system("CLS");
		    
			if (difficulty==-1){
				continue;
			}
		    
		    if (difficulty==1){
		    	rows=9;
		    	cols=9;
		    	mines=10;
			}
			else if (difficulty==2){
		    	rows=16;
		    	cols=16;
		    	mines=40;
			}
			else if (difficulty==3){
		    	rows=16;
		    	cols=30;
		    	mines=99;
			}
			else{
				SetConsoleMode(hStdin, fdwSaveOldMode);
				cout<<"\e[?25h";
		    	cout<<"How many rows do you want: ";
				cin>>rows;
				while (rows<0 or rows>24){
					cout<<"Change the row count! Retry.\n";
			    	cout<<"How many rows do you want: ";
					cin>>rows;
				}
		    	cout<<"\nHow many columns do you want: ";
				cin>>cols;
				while (cols<8 or cols>30){
					cout<<"Change the column count! Retry.\n";
			    	cout<<"How many columns do you want: ";
					cin>>cols;
				}
		    	cout<<"\nHow many mines do you want: ";
				cin>>mines;
				while (mines<0 or mines>=rows*cols){
					cout<<"There must be less mines than squares! Retry.\n";
			    	cout<<"How many mines do you want: ";
					cin>>cols;
				}
				cout<<"\e[?251";
			}
			char visible[rows][cols];		//Y for on, N for off, F for flag (show flag emoji but not number, basically no)
			int board[rows][cols];			//init all to 0, 2 for loops that check all spaces around after first spot is picked, bomb is -1
			char fake_vis[rows][50];
			int fake_board[rows][50];
			while (restart==true){
				cout<<"\e[?251";
				seconds=0;
				lose=1;
				firstX=-1;
				restart=true;
				end_choice=1;
				firstY=-1;
				temp_vis.resize(rows);
				for (int i=0;i<rows;i++){
					temp_vis[i].resize(cols,'N'); 
				}
				fill( &visible[0][0], &visible[0][0] + sizeof(visible), 'N' );
				memset( &board[0][0], 0, sizeof(board) );
				for (int i=0;i<rows;i++){
					for (int j=0;j<cols;j++){
	//					board[i][j]=0;
					}
				}
				copy(&visible[0][0], &visible[0][0]+rows*cols,&fake_vis[0][0]);
				copy(&board[0][0], &board[0][0]+rows*cols,&fake_board[0][0]);
				
			    cout<<flush;
			    system("CLS");
			    colored=0;
				temp_mines=mines;
				flags=mines;
			    
			    create_minesweeper(fake_vis,fake_board,rows,cols,flags);
//				cout<<"\e[1A\e[2K\r";
			    
			    fdwMode = ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;		// Enable the window and mouse input events. 
			    if (!SetConsoleMode(hStdin, fdwMode)){
			    	ErrorExit("SetConsoleMode");
				}
				
				cout<<"\e[?251";
			    while (lose==1){
			        if (!ReadConsoleInput(hStdin,irInBuf,128,&cNumRead)){
			            ErrorExit("ReadConsoleInput");
			        }
			        for (i = 0; i < cNumRead; i++){
			        	if (event_type == KEY_EVENT){	 // keyboard input 
							if (!key_pressed){
			                	if (key==VK_ESCAPE){
									restart=false;
									end_choice=0;
									lose=0;
									break;
								}
//								else if (key==0x53){
//									fstream save;									//Create a file object for reading/writing
//								    save.open("save_game.txt");					// attempt to open the highscore file
//								    if (!save){										//If the file does not open
//								        save.open("save_game.txt", ios::out);		//Create and open a highscore file for writing
//								    }	
//							        save<<rows<<","<<cols<<","<<temp_mines<<","<<mines<<","<<flags<<","<<seconds<<endl;					//Write to the highscore file
//							        for (int j=0;j<rows;j++){
//							        	for (int k=0;k<cols-1;k++){
//							        		save<<board[j][k]<<",";
//										}
//										save<<board[j][cols-1];
//										save<<endl;
//									}
//							        for (int j=0;j<rows;j++){
//							        	for (int k=0;k<cols-1;k++){
//							        		save<<visible[j][k]<<",";
//										}
//										save<<visible[j][cols-1];
//										save<<endl;
//									}
//								    save.close();		
//								}
								else if (key==0x52){
									temp_vis.resize(rows);
									for (int i=0;i<rows;i++){
										temp_vis[i].resize(cols,'N');
									}
									copy(&visible[0][0], &visible[0][0]+rows*cols,&fake_vis[0][0]);
									copy(&board[0][0], &board[0][0]+rows*cols,&fake_board[0][0]);
									
								    cout<<flush;
								    system("CLS");
								    colored=0;
								    create_minesweeper(fake_vis,fake_board,rows,cols,flags);	 
								    fdwMode = ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;		// Enable the window and mouse input events. 
								    if (!SetConsoleMode(hStdin, fdwMode)){
								    	ErrorExit("SetConsoleMode");
									}
									
								}
							}
						}
						else if (event_type==MOUSE_EVENT){ // mouse input 
							if (mouse_event==0 and mouse_state==right_click){
								if (MouseX>0 and MouseX<(2*cols)+1 and MouseY>5 and MouseY<rows+6){
					        		MouseX++;
									if (MouseX%2==0){
										MouseX++;
									}
					        		MouseY++;
									cout<<"\e[s";
					        		if (visible[MouseY-7][(MouseX/2)-1]=='N'){
						        		cout<<"\e[s\e[?25l\e["<<MouseY<<";"<<MouseX<<"H\b";
										cout<<"\e[48;2;123;123;123m";
										cout<<"\e[38;2;189;189;189m";
										cout<<flag;
										cout<<"\e[0;0m\e[u";
										visible[MouseY-7][(MouseX/2)-1]='F';
										flags--;
										mine_counter(flags);
										if (board[MouseY-7][(MouseX/2)-1]==-1){
											mines--;
										}
										for (int i=0;i<rows;i++){
											for (int j=0;j<cols;j++){
												if (board[i][j]>=0 and visible[i][j]!='Y'){
													lose=1;
													break;
												}
												if (board[i][j]>=0 and visible[i][j]=='Y'){
													lose=2;
												}
											}
											if (lose==1){
												break;
											}
										}
										if (lose==2){
											break;
										}
									}
									else if (visible[MouseY-7][(MouseX/2)-1]=='F'){
						        		cout<<"\e[s\e[?25l\e["<<MouseY<<";"<<MouseX<<"H\b";
										cout<<"\e[48;2;123;123;123m";
										cout<<"\e[38;2;189;189;189m";
										cout<<blank;
										cout<<"\e[0;0m\e[u";
										visible[MouseY-7][(MouseX/2)-1]='N';
										flags++;
										mine_counter(flags);
										if (board[MouseY-7][(MouseX/2)-1]==-1){
											mines++;
										}
										for (int i=0;i<rows;i++){
											for (int j=0;j<cols;j++){
												if (board[i][j]>=0 and visible[i][j]!='Y'){
													lose=1;
													break;
												}
												if (board[i][j]>=0 and visible[i][j]=='Y'){
													lose=2;
												}
											}
											if (lose==1){
												break;
											}
										}
										if (lose==2){
											break;
										}
									}
									cout<<"\e[u";
								}
					        } 
					        else if (mouse_state==left_click){
					        	if (MouseX>cols-2 and MouseX<cols+3 and MouseY>0 and MouseY<4){
					        		if (colored==0){
						        		cout<<"\e[s\e[?25l\e[3;"<<cols+2<<"H\b";
						        		cout<<"\e[30;103m";
						        		cout<<emoji;
										cout<<"\e[0;0m\e[u";
										colored=1;
										colorX=cols+2;
										colorY=3;
									}	
								}
					        	if (MouseX>0 and MouseX<(2*cols)+1 and MouseY>5 and MouseY<rows+6){
					        		MouseX++;
									if (MouseX%2==0){
										MouseX++;
									}
					        		MouseY++;
					        		if (colored==1){
						        		cout<<"\e[s\e[?25l\e["<<colorY<<";"<<colorX<<"H\b";
										cout<<"\e[48;2;123;123;123m";
										cout<<"\e[38;2;189;189;189m";
						        		if (visible[colorY-7][(colorX/2)-1]=='N'){
											cout<<blank;
										}
										else if (visible[colorY-7][(colorX/2)-1]=='Y'){
											cout<<unicode_num(board[colorY-7][(colorX/2)-1]);
										}
										else{
											cout<<flag;
										}
										
										cout<<"\e[0;0m\e[u";
									}	
					        		if (visible[MouseY-7][(MouseX/2)-1]=='N'){
						        		cout<<"\e[s\e[?25l\e["<<MouseY<<";"<<MouseX<<"H\b";
						        		cout<<"\e[30;103m";
						        		if (visible[MouseY-7][(MouseX/2)-1]=='N'){
											cout<<blank;
										}
										else if (visible[MouseY-7][(MouseX/2)-1]=='Y'){
											cout<<unicode_num(board[MouseY-7][(MouseX/2)-1]);
										}
										else{
											cout<<flag;
										}
										cout<<"\e[3;"<<cols+2<<"H\b";
										cout<<"\e[48;2;123;123;123m";
										cout<<"\U0001F62E";
										
										cout<<"\e[0;0m\e[u";
										colored=1;
										colorX=MouseX;
										colorY=MouseY;
									}
								}
								
	//				        	cout<<"\tX: "<<MouseX<<"\tY: "<<MouseY<<"\tChar: "<<get_char(MouseX,MouseY)<<endl;
							}
							else{
								cout<<"\e[s\e[?25l\e["<<colorY<<";"<<colorX<<"H\b";
								cout<<"\e[48;2;123;123;123m";
								cout<<"\e[38;2;189;189;189m";
				        		if (visible[colorY-7][(colorX/2)-1]=='N'){
									cout<<blank;
								}
								else if (visible[colorY-7][(colorX/2)-1]=='Y'){
									cout<<unicode_num(board[colorY-7][(colorX/2)-1]);
								}
								else if (visible[colorY-7][(colorX/2)-1]=='F'){
									cout<<flag;
								}
								else{
									cout<<emoji;
								}	
				        		
								cout<<"\e[3;"<<cols+2<<"H\b";
								cout<<"\U0001F642";
								
								cout<<"\e[0;0m\e[u";
								colored=0;
							}
			           		if (mouse_state>0){	
								prev_state=mouse_state;
							}
							if (mouse_event>0){
								prev_event=mouse_event;
							}
							                                                   
							if (mouse_event==0 and mouse_state==0 and prev_state==left_click){
								if (MouseX>cols-2 and MouseX<cols+3 and MouseY>0 and MouseY<4){
									lose=3;
					        		break;
								}
								if (MouseX>0 and MouseX<(2*cols)+1 and MouseY>5 and MouseY<rows+6){
					        		MouseX++;
									if (MouseX%2==0){
										MouseX++;
									}
					        		MouseY++;
					        		if (visible[MouseY-7][(MouseX/2)-1]=='N'){
										visible[MouseY-7][(MouseX/2)-1]='Y';
						        		cout<<"\e[s\e[?25l\e["<<MouseY<<";"<<MouseX<<"H\b";
										cout<<"\e[48;2;123;123;123m";
										cout<<"\e[38;2;189;189;189m";
										cout<<unicode_num(board[MouseY-7][(MouseX/2)-1]);
										cout<<"\e[0;0m\e[u";
										
										//Lose Condition
										if (board[MouseY-7][(MouseX/2)-1]==-1){
											visible[MouseY-7][(MouseX/2)-1]='Y';
	//										board[MouseY-7][(MouseX/2)-1]=-2;
											cout<<"\e[s\e["<<MouseY<<";"<<MouseX<<"H\b";
											cout<<"\e[48;2;123;123;123m";
											cout<<"\e[38;2;189;189;189m";
											cout<<explode;
											cout<<"\e[0;0m\e[u";
											lose=0;
											break;
										}
										
										//Win Condition
										for (int i=0;i<rows;i++){
											for (int j=0;j<cols;j++){
												if (board[i][j]>=0 and visible[i][j]!='Y'){
													lose=1;
													break;
												}
												if (board[i][j]>=0 and visible[i][j]=='Y'){
													lose=2;
												}
											}
											if (lose==1){
												break;
											}
										}
										if (lose==2){
											break;
										}
										
										if (firstX==-1 and firstY==-1){
//											timer(cols);
											thread x(timer,cols);
											x.detach();
											cout<<"\e[0m";
											cout<<"\e[?251";
											x.~thread();
											firstX=(MouseX/2)-1;
											firstY=MouseY-7;
											
											while (temp_mines>0){
												MouseX=rand()%cols;
												MouseY=rand()%rows;
												
												if (board[MouseY][MouseX]!=-1 and visible[MouseY][MouseX]!='Y'){
													board[MouseY][MouseX]=-1;
													temp_mines--;
												}
											}
											temp_mines=mines;
											for (int x=0;x<rows;x++){
												for (int y=0;y<cols;y++){
													if (board[x][y]==-1){
														continue;
													}
													if (y>0){
														if (board[x][y-1]==-1){
															board[x][y]++;
														}
													}
													if (y>0 and x>0){
														if (board[x-1][y-1]==-1){
															board[x][y]++;
														}
													}
													if (x>0){
														if (board[x-1][y]==-1){
															board[x][y]++;
														}
													}
													if (y<cols-1 and x>0){
														if (board[x-1][y+1]==-1){
															board[x][y]++;
														}
													}
													if (y<cols-1){
														if (board[x][y+1]==-1){
															board[x][y]++;
														}
													}
													if (y<cols-1 and x<rows-1){
														if (board[x+1][y+1]==-1){
															board[x][y]++;
														}
													}
													if (x<rows-1){
														if (board[x+1][y]==-1){
															board[x][y]++;
														}
													}
													if (y>0 and x<rows-1){
														if (board[x+1][y-1]==-1){
															board[x][y]++;
														}
													}
												}
											}
											cout<<"\e[s\e[?25l\e["<<firstY+7<<";"<<((firstX+1)*2)+1<<"H\b";
											cout<<"\e[48;2;123;123;123m";
											cout<<"\e[38;2;189;189;189m";
											cout<<unicode_num(board[firstY][firstX]);
											cout<<"\e[0;0m\e[u";
//											cout<<"hi"<<board[firstY][firstX]<<" "<<firstX<<" "<<firstY;
											for (int i=0;i<rows;i++){
												for (int j=0;j<cols;j++){
													if (board[i][j]>=0 and visible[i][j]!='Y'){
														lose=0;
														break;
													}
													if (board[i][j]>=0 and visible[i][j]=='Y'){
														lose=2;
													}
												}
												if (lose==0){
													lose=1;
													break;
												}
											}
											if (lose==2){
//												cout<<"\e[s\e[?25l\e["<<colorY<<";"<<colorX<<"H\b";
//												cout<<"\e[48;2;123;123;123m";
//												cout<<"\e[38;2;189;189;189m";
//												cout<<unicode_num(board[colorY-7][(colorX/2)-1]);
//												cout<<"\e[0;0m\e[u";
												break;
											}
											colorY=firstY+7;
											colorX=((firstX+1)*2)+1;
											MouseY=colorY;
											MouseX=colorX;
//											cout<<"hi"<<board[MouseY-7][(MouseX/2)-1]<<" "<<colorX<<" "<<colorY<<"  "<<MouseX<<" "<<MouseY;
										}
//										cout<<"\e["<<rows+9<<";1H\e[0J";
										if (board[MouseY-7][(MouseX/2)-1]==0){
											copy(&visible[0][0], &visible[0][0]+rows*cols,&fake_vis[0][0]);
											copy(&board[0][0], &board[0][0]+rows*cols,&fake_board[0][0]);
//											cout<<"hi"<<board[MouseY-7][(MouseX/2)-1]<<" | "<<MouseX<<" "<<MouseY<<endl;
											temp_vis[MouseY-7][(MouseX/2)-1]='Y';
											depth=0;
											open_spots(fake_vis,fake_board,rows,cols,(MouseX/2)-1,MouseY-7);
//											cout<<endl;
											for (int i=0;i<rows;i++){
												for (int j=0;j<cols;j++){
//													cout<<temp_vis[i][j]<<board[i][j]<<" ";
													if (temp_vis[i][j]=='Y' and visible[i][j]=='N'){
//														cout<<j<<i<<" "<<board[j][i];
														visible[i][j]='Y';
														cout<<"\e[s\e[?25l\e["<<i+7<<";"<<((j+1)*2)+1<<"H\b";
														cout<<"\e[48;2;123;123;123m";
														cout<<"\e[38;2;189;189;189m";
														cout<<unicode_num(board[i][j]);
														cout<<"\e[0;0m\e[u";
													}
												}
//												cout<<endl;
											}	
											temp_vis.clear();
											temp_vis.resize(rows);
											for (int i=0;i<rows;i++){
												temp_vis[i].resize(cols,'N');
											}
//											system("PAUSE");
										}
									}
								}
							}
			            }
			        }
	//		        win == if all 0-8 are open
			    }
			    stop=true;
			    if (lose==3){
					usleep(100000);
					cout<<"\e[0;0m";
			    	continue;
				}
				if (end_choice==0){
					usleep(100000);
					cout<<"\e[0;0m";
			    	break;
				}
			    
			    
				cout<<"\e[s\e[3;"<<cols+2<<"H\b";
				cout<<"\e[48;2;123;123;123m";
				if (lose==0){	
	//				cout<<"\U0001F635";
					cout<<"\U0001F480";
					for (int i=0;i<rows;i++){
						for (int j=0;j<cols;j++){
							if (board[i][j]==-1 and visible[i][j]=='N'){
								cout<<"\e["<<i+7<<";"<<((j+1)*2)+1<<"H\b";
								cout<<"\e[48;2;123;123;123m";
								cout<<"\e[38;2;189;189;189m";
								cout<<bomb;
								cout<<"\e[0;0m";
								visible[i][j]='Y';
							}
							if (board[i][j]>=0 and visible[i][j]=='F'){
								cout<<"\e["<<i+7<<";"<<((j+1)*2)+1<<"H\b";
								cout<<"\e[48;2;123;123;123m";
								cout<<"\e[38;2;189;189;189m";
		//						cout<<board[i][j]<<" ";
								cout<<"\u274C";
								cout<<"\e[0;0m";
							}
						}
					}
				}
				else{
					cout<<"\U0001F60E";
					for (int i=0;i<rows;i++){
						for (int j=0;j<cols;j++){
							if (board[i][j]==-1 and visible[i][j]=='N'){
								cout<<"\e["<<i+7<<";"<<((j+1)*2)+1<<"H\b";
								cout<<"\e[48;2;123;123;123m";
								cout<<"\e[38;2;189;189;189m";
								cout<<flag;
								cout<<"\e[0;0m";
								visible[i][j]='Y';
							}
						}
					}
				}
				usleep(100000);
				cout<<"\e[0;0m\e[u";
//				cout<<"\e[1A\e[2K\r";
	//			system("PAUSE");
				mines=temp_mines;
				if (difficulty<4 and lose==2){
					cout<<"\e[0;0m\e["<<rows+8<<";1H";
					SetConsoleMode(hStdin, fdwSaveOldMode);
					if (MessageBox( NULL, TEXT( "Would you like to add your score to the Leaderboard?"), TEXT( "Minesweeper.exe"), MB_ICONQUESTION | MB_YESNO | MB_APPLMODAL )==6){	
						cout<<"\e[?25h";
						add_score_minesweeper(seconds, difficulty);		//Calls add_score to add the money on the leaderboard
					}
					cout<<"\e[?251";
					cout<<"\e["<<rows+8<<";1H\e[0J";
					fdwMode = ENABLE_MOUSE_INPUT | ENABLE_INSERT_MODE | ENABLE_EXTENDED_FLAGS;		// Enable the window and mouse input events. 
				    if (!SetConsoleMode(hStdin, fdwMode)){
				    	ErrorExit("SetConsoleMode");
					}
//					cout<<"\e[?251";
				}
				
				while (end_choice==1){
			        if (!ReadConsoleInput(hStdin,irInBuf,128,&cNumRead)){
			            ErrorExit("ReadConsoleInput");
			        }
			        for (i = 0; i < cNumRead; i++){
			        	if (event_type == KEY_EVENT){	 // keyboard input 
		                	if (!key_pressed and key==VK_ESCAPE){
								restart=false;
								end_choice=0;
								break;
							}
						}
						else if (event_type==MOUSE_EVENT){ // mouse input 
							if (mouse_state==left_click){
					        	if (MouseX>cols-2 and MouseX<cols+3 and MouseY>0 and MouseY<4){
					        		if (colored==0){
						        		cout<<"\e[s\e[?25l\e[3;"<<cols+2<<"H\b";
						        		cout<<"\e[30;103m";
						        		cout<<emoji;
										cout<<"\e[0;0m\e[u";
										colored=1;
									}	
								}
	//				        	cout<<"\tX: "<<MouseX<<"\tY: "<<MouseY<<"\tChar: "<<get_char(MouseX,MouseY)<<endl;
							}
							else if (colored==1){
				        		cout<<"\e[s\e[?25l\e[3;"<<cols+2<<"H\b";
								cout<<"\e[48;2;123;123;123m";
				        		cout<<emoji;
								cout<<"\e[0;0m\e[u";
								colored=0;
							}
			           		if (mouse_state>0){	
								prev_state=mouse_state;
							}
							if (mouse_event>0){
								prev_event=mouse_event;
							}
							
							if (mouse_event==0 and mouse_state==0 and prev_state==left_click){
								if (MouseX>cols-2 and MouseX<cols+3 and MouseY>0 and MouseY<4){
									end_choice=0;
					        		break;
								}
							}
			            }
			        }
			    }
			}
		}
	    else if (menu_choice==2){
			cout<<"                   __  __                   __            ____   __             \n";				//Rules Title Card ASCII Art
			cout<<"                  / / / /____  _      __   / /_ ____     / __ \\ / /____ _ __  __\n";			//More Rules Title Card ASCII Art
			cout<<"                 / /_/ // __ \\| | /| / /  / __// __ \\   / /_/ // // __ `// / / /\n";			//More Rules Title Card ASCII Art
			cout<<"                / __  // /_/ /| |/ |/ /  / /_ / /_/ /  / ____// // /_/ // /_/ / \n";				//More Rules Title Card ASCII Art
			cout<<"               /_/ /_/ \\____/ |__/|__/   \\__/ \\____/  /_/    /_/ \\__,_/ \\__, /  \n";		//More Rules Title Card ASCII Art
			cout<<"                                                                       /____/   ";				//More Rules Title Card ASCII Art
			cout<<"\n-----------------------------------------------------------------------------------------------\n";		//Line of Separation
			
			cout<<"Object of the Game:\n";				//Rules of Blackjack
			cout<<"\tMinesweeper is a game where mines are hidden in a grid of squares. If you click on a mine you lose the game!\n";				//Rules of Blackjack
			
			cout<<"\nThe Play:\n";				//Rules of Blackjack
			cout<<"\tThe first click is always safe. Open squares with a left click and put flags on mines with a right click.";
			cout<<"\n\tSafe squares have numbers telling you how many mines touch the square.";
			cout<<"\n\tWhen you open a square that does not touch any mines, it will be empty and open adjacent squares.";
			cout<<"\n\tYou can use the number clues to solve the game by opening all of the safe squares.";
			cout<<"\n\tWhen a number touches the same number of squares, those squares must be mines.\n";
			
			cout<<"\nWinning:\n";				//Rules of Blackjack
			cout<<"\tThe game ends when all safe squares have been opened.";
			cout<<"\n\tA counter shows the number of mines without flags, and a clock shows your time in seconds.\n";
			
			cout<<"\nExtra:\n";				//Rules of Blackjack
			cout<<"\tPress Escape to exit a game.";
			cout<<"\n\tPress R to refresh the screen, in the case of a visual error.";
			cout<<"\n\tPress the emoji to restart the game, even in the middle of one.";
			cout<<"\n\tThe leaderboard saves the best 3 times for each difficulty level.\n\n";
			system("PAUSE");
		}
	    else if (menu_choice==3){
			break;
		}
		else{
			show_score_minesweeper();			//Calls show_score() to display the top three scores
			system("PAUSE");
			if (!easy.empty() or !medium.empty() or !hard.empty()){
				if (MessageBox( NULL, TEXT( "Would you like to clear the leaderboard?"), TEXT( "Minesweeper.exe"), MB_ICONQUESTION | MB_YESNO | MB_APPLMODAL)==6){ 
					cout<<"\e[?25h\n";
					Center_text("Enter the password: ");		//Tells the user what to input
					cin>>password;			//Prompts the user to input
					if (password=="71737"){			//if the password is correct
						remove("highscores.csv");		//Delete the highscore file
						Center_text("Leaderboard Cleared.");		//Tells the user that the leaderboard was cleared
						cout<<"\n";
						
						fstream scores;									//Create a file object for reading/writing
					    scores.open("highscores.csv");					// attempt to open the highscore file
					    if (!scores){										//If the file does not open
					        scores.open("highscores.csv", ios::out);		//Create and open a highscore file for writing
					        scores<<"Highscores"<<endl;					//Write to the highscore file
					    }	
					    scores.close();									//close the highscore file
					}	
					else{
						Center_text("WRONG PASSWORD!");
						cout<<"\n";
					}
					cout<<"\e[?251";
				}
			}
		}
		cout<<"\e[0m";
	    cout<<flush;
	    system("CLS");
	} while (menu_choice!=0);
}

void open_spots(char fake_vis[][50], int fake_board[][50], int rows, int cols, int x, int y){
	char visible[rows][cols];		//Y for on, N for off, F for flag (show flag emoji but not number, basically no)
	int board[rows][cols];			//ini=t all to 0, 2 for loops that check all spaces around after first spot is picked, bomb is -1
	copy(&fake_vis[0][0], &fake_vis[0][0]+rows*cols,&visible[0][0]);
	copy(&fake_board[0][0], &fake_board[0][0]+rows*cols,&board[0][0]);
//	cout<<x<<y<<endl;
//	cout<<visible[y][x]<<" "<<board[y][x]<<endl;
	depth++;
	
	if (board[y][x]==0){
		if (y>0){
			if (board[y][x-1]>=0){
				y--;
				visible[y][x]='Y';
				if (board[y][x]==0 and temp_vis[y][x]=='N'){
					temp_vis[y][x]='Y';
					open_spots(fake_vis,fake_board,rows,cols,x,y);
				}
				temp_vis[y][x]='Y';
				y++;
			}
		}
		if (y>0 and x>0){
			if (board[y-1][x-1]>=0){
				x--;
				y--;
				visible[x][y]='Y';
				if (board[y][x]==0 and temp_vis[y][x]=='N'){
					temp_vis[y][x]='Y';
					open_spots(fake_vis,fake_board,rows,cols,x,y);
				}
				temp_vis[y][x]='Y';
				x++;
				y++;
			}
		}
		if (x>0){
			if (board[y][x-1]>=0){
				x--;
				visible[x][y]='Y';
				if (board[y][x]==0 and temp_vis[y][x]=='N'){
					temp_vis[y][x]='Y';
					open_spots(fake_vis,fake_board,rows,cols,x,y);
				}
				temp_vis[y][x]='Y';
				x++;
			}
		}
		if (y<rows-1 and x>0){
			if (board[y+1][x-1]>=0){
				x--;
				y++;
				visible[x][y]='Y';
				if (board[y][x]==0 and temp_vis[y][x]=='N'){
					temp_vis[y][x]='Y';
					open_spots(fake_vis,fake_board,rows,cols,x,y);
				}
				temp_vis[y][x]='Y';
				x++;
				y--;
			}
		}
		if (y<rows-1){
			if (board[y+1][x]>=0){
				y++;
				visible[x][y]='Y';
				if (board[y][x]==0 and temp_vis[y][x]=='N'){
					temp_vis[y][x]='Y';
					open_spots(fake_vis,fake_board,rows,cols,x,y);
				}
				temp_vis[y][x]='Y';
				y--;
			}
		}
		if (y<rows-1 and x<cols-1){
			if (board[y+1][x+1]>=0){
				x++;
				y++;
				visible[x][y]='Y';
				if (board[y][x]==0 and temp_vis[y][x]=='N'){
					temp_vis[y][x]='Y';
					open_spots(fake_vis,fake_board,rows,cols,x,y);
				}
				temp_vis[y][x]='Y';
				x--;
				y--;
			}
		}
		if (x<cols-1){
			if (board[y][x+1]>=0){
				x++;
				visible[x][y]='Y';
				if (board[y][x]==0 and temp_vis[y][x]=='N'){
					temp_vis[y][x]='Y';
					open_spots(fake_vis,fake_board,rows,cols,x,y);
				}
				temp_vis[y][x]='Y';
				x--;
			}
		}
		if (y>0 and x<cols-1){
			if (board[y-1][x+1]>=0){
				x++;
				y--;
				visible[x][y]='Y';
				if (board[y][x]==0 and temp_vis[y][x]=='N'){
					temp_vis[y][x]='Y';
					open_spots(fake_vis,fake_board,rows,cols,x,y);
				}
				temp_vis[y][x]='Y';
				x--;
				y++;
			}
		}
	}
	depth--;
//	cout<<"depth: "<<depth<<endl;
}

string unicode_num(int num){
	string unicode_num;
	
	switch(num){
		case 0:
//			unicode_num="\uFF10";
			unicode_num="  ";
			break;
		case 1:
			cout<<"\e[38;2;0;0;255m";
			unicode_num="\uFF11";
			break;
		case 2:
			cout<<"\e[38;2;0;123;0m";
			unicode_num="\uFF12";
			break;
		case 3:
			cout<<"\e[38;2;255;0;0m";
			unicode_num="\uFF13";
			break;
		case 4:
			cout<<"\e[38;2;0;0;123m";
			unicode_num="\uFF14";
			break;
		case 5:
			cout<<"\e[38;2;123;0;0m";
			unicode_num="\uFF15";
			break;
		case 6:
			cout<<"\e[38;2;0;123;123m";
			unicode_num="\uFF16";
			break;
		case 7:
			cout<<"\e[38;2;0;0;0m";
			unicode_num="\uFF17";
			break;
		case 8:
			cout<<"\e[38;2;123;123;123m";
			unicode_num="\uFF18";
			break;
		case -1:
			unicode_num="\U0001F4A3";
			break;
	}
	
	return unicode_num;
}

string ascii_num(int num, int row){
	string unicode_num;
    if (num==-1){
    	if (row==1){
			unicode_num="\u2800\u2800";
		}
		else if (row==2){
			unicode_num="\u257A\u2578";
		}
		else{
			unicode_num="\u2800\u2800";
		}
		return unicode_num;
	}
	 
	if (row==1){
		unicode_num="\u250f\u2513\u2800\u257b\u257A\u2513\u257a\u2513\u257B\u257B\u250F\u2578\u250F\u2578\u257A\u2513\u250f\u2513\u250F\u2513";
	}
	else if (row==2){
		unicode_num="\u2503\u2503\u2800\u2503\u250F\u251b\u257a\u252b\u2517\u252B\u2517\u2513\u2523\u2513\u2800\u2503\u2523\u252b\u2517\u252B";
	}
	else{
		unicode_num="\u2517\u251b\u2800\u2579\u2517\u2578\u257a\u251b\u2800\u2579\u257A\u251B\u2517\u251B\u2800\u2579\u2517\u251b\u257A\u251B";
	}
	if (num>0){
		unicode_num.erase(0,((num)*6));
	}
    unicode_num.erase(6);   
	return unicode_num;
}

void mine_counter(int mines){
	bool neg=false;
	
	if (mines<0){
		neg=true;
		mines*=-1;
	}
	if (mines<1000){
		cout<<"\e[s\e[38;2;255;0;0m\e[48;2;0;0;0m";
		cout<<"\e[2;8H\b\b\b\b\b\b";
		if (neg==true){
			cout<<ascii_num(-1,1);
		}
		else{
			cout<<ascii_num(mines/100,1);
		}
		cout<<ascii_num((mines/10)%10,1)<<ascii_num(mines%10,1);
		cout<<"\e[3;8H\b\b\b\b\b\b";
		if (neg==true){
			cout<<ascii_num(-1,2);
		}
		else{
			cout<<ascii_num(mines/100,2);
		}
		cout<<ascii_num((mines/10)%10,2)<<ascii_num(mines%10,2);
		cout<<"\e[4;8H\b\b\b\b\b\b";
		if (neg==true){
			cout<<ascii_num(-1,3);
		}
		else{
			cout<<ascii_num(mines/100,3);
		}
		cout<<ascii_num((mines/10)%10,3)<<ascii_num(mines%10,3);
		cout<<"\e[0m\e[u";
		
	}
}

void timer(int cols){
	int true_secs=0;
	stop=false;
	while(stop==false){
		if (seconds<1000){
			cout<<"\e[s\e[38;2;255;0;0m\e[48;2;0;0;0m";
			cout<<"\e[2;"<<(cols+1)*2<<"H\b\b\b\b\b\b";
			cout<<ascii_num(seconds/100,1)<<ascii_num((seconds/10)%10,1)<<ascii_num(seconds%10,1);
			cout<<"\e[3;"<<(cols+1)*2<<"H\b\b\b\b\b\b";
			cout<<ascii_num(seconds/100,2)<<ascii_num((seconds/10)%10,2)<<ascii_num(seconds%10,2);
			cout<<"\e[4;"<<(cols+1)*2<<"H\b\b\b\b\b\b";
			cout<<ascii_num(seconds/100,3)<<ascii_num((seconds/10)%10,3)<<ascii_num(seconds%10,3);
			cout<<"\e[0m\e[u";
		}
	
		if (first==false){
			sleep(1);
		}
		else{
			first=false;
			sleep(1);
		}
		
		if (seconds<999){
			seconds++;
		}
		else{
			true_secs++;
		}
		
	}
	seconds+=true_secs;
	
}

void create_minesweeper(char fake_vis[][50], int fake_board[][50], int rows, int cols, int mines){
	char visible[rows][cols];		//Y for on, N for off, F for flag (show flag emoji but not number, basically no)
	int board[rows][cols];			//ini=t all to 0, 2 for loops that check all spaces around after first spot is picked, bomb is -1
	string bomb="\U0001F4A3";
	string explode="\U0001F4A5";
	string flag="\U0001F6A9";
	string blank="\U0001F532";
	string emoji="\U0001F642";
	copy(&fake_vis[0][0], &fake_vis[0][0]+rows*cols,&visible[0][0]);
	copy(&fake_board[0][0], &fake_board[0][0]+rows*cols,&board[0][0]);
//	cout<<"\u250f\u2513 \u2800\u257b \u257A\u2513 \u257a\u2513 \u257B\u257B \u250F\u2578 \u250F\u2578 \u257A\u2513 \u250f\u2513 \u250F\u2513\n";
//	cout<<"\u2503\u2503 \u2800\u2503 \u250F\u251b \u257a\u252b \u2517\u252B \u2517\u2513 \u2523\u2513 \u2800\u2503 \u2523\u252b \u2517\u252B\n";
//	cout<<"\u2517\u251b \u2800\u2579 \u2517\u2578 \u257a\u251b \u2800\u2579 \u257A\u251B \u2517\u251B \u2800\u2579 \u2517\u251b \u257A\u251B\n";
//	stop=true;
	cout<<"\e[48;2;123;123;123m";
	cout<<"\e[48;2;123;123;123m";
	cout<<"\u259B";
	for (int i=0;i<cols*2;i++){
		cout<<"\u2580";
	}
	cout<<"\u259C\n";
	for (int i=0;i<3;i++){
		cout<<"\u258c";
		for (int j=0;j<cols;j++){
			if (cols==8 and j==(ceil(cols/2.0))-1){
				cout<<"\e[48;2;123;123;123m";
				cout<<"\e[38;2;189;189;189m";
				if (i==0){
					cout<<"\u250F\u2501\u2501\u2513";
				}
				else if (i==1){
					cout<<"\u2503"<<emoji<<"\u2503";	
				}
				else if (i==2){
					cout<<"\u2517\u2501\u2501\u251B";	
				}
				
				j+=1;
			}
			else if (cols!=8 and j==(ceil(cols/2.0))-2){
				cout<<"\e[48;2;123;123;123m";
				cout<<"\e[38;2;189;189;189m";
				if (cols%2==0){
					if (i==0){
						cout<<"  \u250F\u2501\u2501\u2513";
					}
					else if (i==1){
						cout<<"  \u2503"<<emoji<<"\u2503";	
					}
					else if (i==2){
						cout<<"  \u2517\u2501\u2501\u251B";	
					}
				}
				else{
					if (i==0){
						cout<<" \u250F\u2501\u2501\u2513 ";
					}
					else if (i==1){
						cout<<" \u2503"<<emoji<<"\u2503 ";	
					}
					else if (i==2){
						cout<<" \u2517\u2501\u2501\u251B ";	
					}
				}
				j+=2;
			}
			else if ((j>=0 and j<3) or (j>cols-4 and j<cols)){
				cout<<"\e[38;2;255;0;0m\e[48;2;0;0;0m";  
				if (j==0){
					cout<<ascii_num(mines/100,i+1);
				}
				else if (j==1){
					cout<<ascii_num((mines/10)%10,i+1);
				}
				else if (j==2){
					cout<<ascii_num(mines%10,i+1);
				}
				else if (j==cols-3){
					cout<<ascii_num(seconds/100,i+1);
				}
				else if (j==cols-2){
					cout<<ascii_num((seconds/10)%10,i+1);
				}
				else if (j==cols-1){
					cout<<ascii_num(seconds%10,i+1);
				}
				else{
					cout<<"  ";
				}
			}
			else{		
				cout<<"\e[48;2;123;123;123m";
				cout<<"\e[38;2;189;189;189m";
				if (j==(cols/2) and i==1){
					cout<<" ";	
				}
				else{
					cout<<"  ";	
				}
				
			}
		}
		cout<<"\e[48;2;123;123;123m";
		cout<<"\e[38;2;189;189;189m";
		cout<<"\u2590";
		cout<<endl;		
	}
	cout<<"\u2599";
	for (int i=0;i<cols*2;i++){
		cout<<"\u2584";
	}
	cout<<"\u259F\n";
	
	cout<<"\e[48;2;123;123;123m";
	cout<<"\e[38;2;189;189;189m\u259B";
	for (int i=0;i<cols*2;i++){
		cout<<"\u2580";
	}
	cout<<"\u259C\n";
	for (int i=0;i<rows;i++){
		cout<<"\u258c";
		for (int j=0;j<cols;j++){
			if (visible[i][j]=='N'){
				cout<<blank;
			}
			else if (visible[i][j]=='Y'){
				cout<<unicode_num(board[i][j]);
			}
			else{
				cout<<flag;
			}
		}
		cout<<"\e[38;2;189;189;189m\u2590";
		cout<<endl;
	}
	cout<<"\u2599";
	for (int i=0;i<cols*2;i++){
		cout<<"\u2584";
	}
	cout<<"\u259F\n";
	cout<<"\e[0m";
	cout<<"\e[?251";
	usleep(100000);
//	system("PAUSE");
}

bool operator<(const name_time&lhs, const name_time&rhs){			//defines the operator for the structure and makes it accept two arguments to make a comparison
    return lhs.time < rhs.time;				//returns the smaller of the two arguments
}

void add_score_minesweeper(int time, int difficulty){		//Defines a void function with an int paaramter for the players money
	string name;		//Declares a string for the users name
	cout<<"\nWhat is your name: ";		//Tells the user what to input
	cin>>name;			//Prompts the user to input
    ofstream highscore;		// Create an output filestream object
	highscore.open("highscores.csv", ios::app);    //Open the highscores.csv file to add data
    highscore<<difficulty<<","<<name<<","<<time<<endl;		// Send data to the stream
    highscore.close();			// Close the file
}

void show_score_minesweeper(){
	int total_rows=0;		//Declares an int for the total number of rows and initializes it to 0
	int curr_row=0;		//Declares an int for the current row and initializes it to 0
	int time;		//Declares an int for a time from the spreadsheet
	int difficulty;
	int easy_rows=0;
	int medium_rows=0;
	int hard_rows=0;
	string line;		//declares a string for a line in the spreadsheet
	string phrase;		//Declares a string for the two columns of a line combined from the spreadsheet
	string names;		//Declares a string for the name part of the line
	int comma_pos;		//Declares an int for the location of the comma that separates the columns
	ifstream file("highscores.csv");		//opens the highscore file for input
	while (getline(file, line)){		//while the its possible to read a line from the spreadsheet
		total_rows++;			//Increases the total row count by 1
		if (line.at(0)=='1'){
			easy_rows++;
		}
		else if (line.at(0)=='2'){
			medium_rows++;
		}
		else if (line.at(0)=='3'){
			hard_rows++;
		}
	}
	file.close();		//Closes the spreadsheet
	
	easy.resize(0);		//changes the size of the scores vector to the total rows
	medium.resize(0);		//changes the size of the scores vector to the total rows
	hard.resize(0);		//changes the size of the scores vector to the total rows
		
	ifstream file2("highscores.csv");			//opens the highscore file for input
	for (;curr_row<total_rows;curr_row++){		//Until the current row reaches the total row count
		file2>>phrase;		//Reads in a line from the spreadsheet
		if (phrase!="Highscores"){		//If its not the first line
			difficulty=phrase.at(0)-'0';
			phrase.erase(0,2);
			names=phrase;		//names is initializes to the line from the spreadsheet
			comma_pos=phrase.find_last_of(",");		//Finds the location of the final comma (in case one is in the name)
			phrase.erase(0, comma_pos+1);		//removes the name from the line
			names.erase(comma_pos);		//keeps only the name from the line
			time=stoi(phrase);		//convers the score into an int and saves it into score
			
			if (difficulty==1){
				easy.push_back({time,names});		//Puts the score and name into a value in the scores vector
			}
			else if (difficulty==2){
				medium.push_back({time,names});		//Puts the score and name into a value in the scores vector
			}
			else if (difficulty==3){
				hard.push_back({time,names});		//Puts the score and name into a value in the scores vector
			}
		}
	}     
	               
	stable_sort(easy.begin(),easy.end());		//Sorts the scores vector by score while keeping the names with them (lowest to highest)               
	stable_sort(medium.begin(),medium.end());		//Sorts the scores vector by score while keeping the names with them (lowest to highest)               
	stable_sort(hard.begin(),hard.end());		//Sorts the scores vector by score while keeping the names with them (lowest to highest)
	
	SetConsoleMode(hStdin, fdwSaveOldMode);
	
	Center_text("    __                   __          __                         __");
	cout<<"\n";
	Center_text("   / /   ___  ____ _____/ /__  _____/ /_  ____  ____ __________/ /");
	cout<<"\n";
	Center_text("  / /   / _ \\/ __ `/ __  / _ \\/ ___/ __ \\/ __ \\/ __ `/ ___/ __  / ");
	cout<<"\n";
	Center_text(" / /___/  __/ /_/ / /_/ /  __/ /  / /_/ / /_/ / /_/ / /  / /_/ /  ");
	cout<<"\n";
	Center_text("/_____/\\___/\\__,_/\\__,_/\\___/_/  /_.___/\\____/\\__,_/_/   \\__,_/   ");
	cout<<"\n\n";
	Center_text("----------------------------------------------------------------------------------------------------");			//Line of separation
	cout<<endl<<endl;
	if (total_rows==1){		//If there are no scores
		Center_text("Add Some Scores");			//tells the user that the leaderboard is blank
		cout<<endl<<endl;
		return;
	}	
	if (easy_rows>0){
		Center_text("Easy:");
		cout<<"\n";
		if (easy_rows>2){		//If there are more than three scores in the leaderboard
			for (int i=0;i<3;i++){			//From the last score to the third last (inclusive)
				Center_text("#"+to_string(i+1)+" - "+easy[i].name+": "+to_string(easy[i].time)+"s");		//Outputs the name and the score 
				cout<<"\n";
			}
		}
		else if (easy_rows<2){		//Otherwise if there are less that three scores
			for (int i=0;i<easy_rows;i++){		//From the last score to 0
				Center_text("#"+to_string(i+1)+" - "+easy[i].name+": "+to_string(easy[i].time)+"s");		//Outputs the name and the score 
				cout<<"\n";
			}
		}
	}	
	if (medium_rows>0){
		cout<<"\n";
		Center_text("Medium:");
		cout<<"\n";
		if (medium_rows>2){		//If there are more than three scores in the leaderboard
			for (int i=0;i<3;i++){			//From the last score to the third last (inclusive)
				Center_text("#"+to_string(i+1)+" - "+medium[i].name+": "+to_string(medium[i].time)+"s");		//Outputs the name and the score 
				cout<<"\n";
			}
		}
		else if (medium_rows<2){		//Otherwise if there are less that three scores
			for (int i=0;i<medium_rows;i++){		//From the last score to 0
				Center_text("#"+to_string(i+1)+" - "+medium[i].name+": "+to_string(medium[i].time)+"s");		//Outputs the name and the score 
				cout<<"\n";
			}
		}
	}	
	if (hard_rows>0){
		cout<<"\n";
		Center_text("Hard:");
		cout<<"\n";
		if (hard_rows>2){		//If there are more than three scores in the leaderboard
			for (int i=0;i<3;i++){			//From the last score to the third last (inclusive)
				Center_text("#"+to_string(i+1)+" - "+hard[i].name+": "+to_string(hard[i].time)+"s");		//Outputs the name and the score 
				cout<<"\n";
			}
		}
		else if (hard_rows<2){		//Otherwise if there are less that three scores
			for (int i=0;i<hard_rows;i++){		//From the last score to 0
				Center_text("#"+to_string(i+1)+" - "+hard[i].name+": "+to_string(hard[i].time)+"s");		//Outputs the name and the score 
				cout<<"\n";
			}
		}
	}
	
	file2.close();		//Closes the highscore file
}

VOID ErrorExit(LPCSTR lpszMessage){
    fprintf(stderr, "%s\n", lpszMessage);

    // Restore input mode on exit.

    SetConsoleMode(hStdin, fdwSaveOldMode);

    ExitProcess(0);
}


//SOS

void SOS(){    	//Defines the SOS function
	int rows,cols;		//Declares two ints for the board size
    int menu_choice=0;		//Declares an int for the main menu choice and initializes it to 0
    int game_choice=0;		//Declares an int for the gamemode choice and initializes it to 0
    int x,y;		//Declares two ints for the row and column of the spot chosen
    string spot;	//Declares a string for the spot the AI chose
    double score;		//Declares a double for the score of the winner
    char player_start;		//Declares a char for whether or not the user starts 
    bool full;		//Declares a bool for if the board is full or not
    char letter;		//declares a char for the letter that's being placed
    int rand_letter;		//Declares an int for the random letter generated by the AI
    int difficulty=0;		//Declares an int for the difficulty of the AI
	char fake_board[50][50];		//Declares a 2D char array for the fake board that gets passed to functions
	vector <string> moves;			//Declares a string vector for all possible non-random AI moves
	string ai_move;				//Declares a string for the AI's move
    string password;			//Declares a string for the password used to reset the leaderboard (71737)
    
    fstream highscore;			//Create a file object for reading/writing
    highscore.open("SOS_scores.csv");		// attempt to open the highscore file
    if (!highscore){		//If the file does not open
        highscore.open("SOS_scores.csv", ios::out);		//Create and open a highscore file for writing
        highscore<<"Highscores"<<endl;		//Write to the highscore file
    }	
    highscore.close();		//close the highscore file
	

	do{		//Do this
		p1_points=0.0;		//Initialize p1_points to 0
		p2_points=0.0;		//Initialize p2_points to 0
		score=0.0;			//Initializes the final score to 0
		full=false;		//Initializes the board full check to false
		total_points=0;		//Initializes the total number of points to 0
		difficulty=0;		//Initializes the games difficulty to 0
		moves.resize(0);		//Resizes the AI moves vector to 0, (emptying with the ability to push_back)
		memset( &color[0][0], 0, sizeof(color) );
	   

		Center_text("          _____                   _______                   _____          \n");			//Title ASCII art
		Center_text("         /\\    \\                 /::\\    \\                 /\\    \\         \n");		//More title ASCII art
		Center_text("        /::\\    \\               /::::\\    \\               /::\\    \\        \n");		//More title ASCII art
		Center_text("       /::::\\    \\             /::::::\\    \\             /::::\\    \\       \n");		//More title ASCII art
		Center_text("      /::::::\\    \\           /::::::::\\    \\           /::::::\\    \\      \n");		//More title ASCII art
		Center_text("     /:::/\\:::\\    \\         /:::/~~\\:::\\    \\         /:::/\\:::\\    \\     \n");		//More title ASCII art
		Center_text("    /:::/__\\:::\\    \\       /:::/    \\:::\\    \\       /:::/__\\:::\\    \\    \n");		//More title ASCII art
		Center_text("    \\:::\\   \\:::\\    \\     /:::/    / \\:::\\    \\      \\:::\\   \\:::\\    \\   \n");		//More title ASCII art
		Center_text("  ___\\:::\\   \\:::\\    \\   /:::/____/   \\:::\\____\\   ___\\:::\\   \\:::\\    \\  \n");		//More title ASCII art
		Center_text(" /\\   \\:::\\   \\:::\\    \\ |:::|    |     |:::|    | /\\   \\:::\\   \\:::\\    \\ \n");		//More title ASCII art
		Center_text("/::\\   \\:::\\   \\:::\\____\\|:::|____|     |:::|    |/::\\   \\:::\\   \\:::\\____\\\n");		//More title ASCII art
		Center_text("\\:::\\   \\:::\\   \\::/    / \\:::\\    \\   /:::/    / \\:::\\   \\:::\\   \\::/    /\n");		//More title ASCII art
		Center_text(" \\:::\\   \\:::\\   \\/____/   \\:::\\    \\ /:::/    /   \\:::\\   \\:::\\   \\/____/ \n");		//More title ASCII art
		Center_text("  \\:::\\   \\:::\\    \\        \\:::\\    /:::/    /     \\:::\\   \\:::\\    \\     \n");		//More title ASCII art
		Center_text("   \\:::\\   \\:::\\____\\        \\:::\\__/:::/    /       \\:::\\   \\:::\\____\\    \n");		//More title ASCII art
		Center_text("    \\:::\\  /:::/    /         \\::::::::/    /         \\:::\\  /:::/    /    \n");		//More title ASCII art
		Center_text("     \\:::\\/:::/    /           \\::::::/    /           \\:::\\/:::/    /     \n");		//More title ASCII art
		Center_text("      \\::::::/    /             \\::::/    /             \\::::::/    /      \n");		//More title ASCII art
		Center_text("       \\::::/    /               \\::/____/               \\::::/    /       \n");		//More title ASCII art
		Center_text("        \\::/    /                 ~~                      \\::/    /        \n");		//More title ASCII art
		Center_text("         \\/____/                                           \\/____/         \n");		//More title ASCII art
		Center_text("                                                                           \n");		//More title ASCII art
		
		cout<<"\nWhat would you like to do (Enter 1, 2, etc.): ";		//Tells the user what they can do
		cout<<"\n\tPlay the Game ------------ 1";			//Outputs the first menu choice	
		cout<<"\n\tHow to Play -------------- 2";			//Outputs the second menu choice
		cout<<"\n\tSee the Leaderboard ------ 3";			//Outputs the third menu choice
		cout<<"\n\tQuit --------------------- 4\n";		//Outputs the fourth menu choice
		cin>>menu_choice;			//Prompts the user to input
		while (menu_choice<1 or menu_choice>4){			//While the users input is out of range
			if (menu_choice!=5){		//If the input isn't 5 (out of range)
				cout<<"Invalid Input! Retry.\n";			//Tells the user that the input was wrong
			}
			else if (sidebars==0){		//If sidebars are disabled
				cout<<"Extra sidebars have been Enabled!\n";		//Outputs the change in sidebar modes
				sidebars=1;		//Turns on the extra sidebars
			}
			else{
				cout<<"Extra sidebars have been Disabled!\n";		//Outputs the change in sidebar modes
				sidebars=0;		//Turns off the extra sidebars
			}
			cout<<"What would you like to do (Enter 1, 2, etc.): ";		//Tells the user what they can do
			cin>>menu_choice;		//Prompts the user to input
		}   
	    if (menu_choice==2){		//If the user enters 2
		    cout<<flush;			//Flushes the output stream
			system("CLS");			//Clear the screen
		
			//Rules
			Center_text("    __  __                   __            ____   __             \n");				//Rules Title Card ASCII Art
			Center_text("   / / / /____  _      __   / /_ ____     / __ \\ / /____ _ __  __\n");			//More Rules Title Card ASCII Art
			Center_text("  / /_/ // __ \\| | /| / /  / __// __ \\   / /_/ // // __ `// / / /\n");			//More Rules Title Card ASCII Art
			Center_text(" / __  // /_/ /| |/ |/ /  / /_ / /_/ /  / ____// // /_/ // /_/ / \n");				//More Rules Title Card ASCII Art
			Center_text("/_/ /_/ \\____/ |__/|__/   \\__/ \\____/  /_/    /_/ \\__,_/ \\__, /  \n");		//More Rules Title Card ASCII Art
			Center_text("                                                        /____/   \n");				//More Rules Title Card ASCII Art
			Center_text("-----------------------------------------------------------------------------------------------\n");		//Line of Separation
			
			cout<<"\nObject of the Game:\n";				//Rules of SOS
			cout<<"\tCreate the straight sequence S-O-S between connected squares (either diagonally, horizontally, or vertically)\n";				//Rules of SOS
			cout<<"\tTry to create as many such sequences as you can\n";				//Rules of SOS
			
			cout<<"\nThe Play:\n";				//Rules of SOS
			cout<<"\tPlayers take turns to add either an \"S\" or an \"O\" to any open square\n";				//Rules of SOS
			cout<<"\tAlternate turns between players after each move\n";				//Rules of SOS
			cout<<"\tIf you create an SOS, take another turn\n";				//Rules of SOS
			cout<<"\tContinue to do so until no SOS can be created on their turn\n";				//Rules of SOS
		
			cout<<"\nWinning:\n";				//Rules of SOS
			cout<<"\tOnce the grid has been filled up, the winner is the player who made the most SOS's\n";				//Rules of SOS
			cout<<"\tIf the number of SOS's for each player is the same, then the game is a draw\n";				//Rules of SOS
			
			cout<<"\nExtra:\n";				//Rules of SOS
			cout<<"\tEnter 5 on the main menu to Enable or Disable Sidebars on the Right and Bottom\n";				//Rules of SOS
			cout<<"\tEnter 00 while playing a game to return to the main menu\n\n";				//Rules of SOS
			system("PAUSE");		//Pause the program until the user presses a key
		}
	    else if (menu_choice==3){		//If the user enters 3
			cout<<flush;		//Flushes the output stream
			system("CLS");		//Clears the screen
			show_score_SOS();			//Calls show_score() to display the top three scores (per difficulty)
			system("PAUSE");		//Pauses the program until the user presses a key
			if (!beginner.empty() or !intermediate.empty() or !expert.empty()){		//If any of the leaderboard aren't empty
				if (MessageBox( NULL, TEXT( "Would you like to clear the leaderboard?"), TEXT( "Minesweeper.exe"), MB_ICONQUESTION | MB_YESNO | MB_APPLMODAL)==6){		//Prompts the user with a message box and if yes
					cout<<"\e[1F\e[0J\n";		//Deletes the system pause line
					Center_text("Enter the password: ");		//Tells the user what to input
					cin>>password;			//Prompts the user to input
					if (password=="71737"){			//if the password is correct
						remove("SOS_scores.csv");		//Delete the highscore file
						Center_text("Leaderboard Cleared.\n");		//Tells the user that the leaderboard was cleared
						
						fstream scores;									//Create a file object for reading/writing
					    scores.open("SOS_scores.csv");					// attempt to open the highscore file
					    if (!scores){										//If the file does not open
					        scores.open("SOS_scores.csv", ios::out);		//Create and open a highscore file for writing
					        scores<<"Highscores"<<endl;					//Write to the highscore file
					    }	
					    scores.close();									//close the highscore file
					}	
					else{
						Center_text("WRONG PASSWORD!\n");			//Outputs that the password was wrong
					}
					system("PAUSE");		//Pause the program until the user presses a key		
				}
			}
		}
		else if (menu_choice==4){			//If the user enters 4
			break;		//breaks out of the do-while loop
		}
		else{			//If the user enters 1
	    	do{		//Do this
			    cout<<flush;		//Flushes the output stream
			    system("CLS");		//Clears the screen
		    	cout<<"How do you want to play (Enter 1, 2, etc.): ";		//Tells the user what they can do
				cout<<"\n\tSingleplayer ------------- 1";			//Outputs the first menu choice	
				cout<<"\n\tMultiplayer -------------- 2";			//Outputs the second menu choice
				cout<<"\n\tReturn to Main Menu ------ 3\n";			//Outputs the third menu choice
				cin>>game_choice;		//Prompts the user to input
				while (game_choice<1 or game_choice>3){			//While the users input is out of range
					cout<<"Invalid Input! Retry.\n";			//Tells the user that the input was wrong
					cout<<"How do you want to play (Enter 1, 2, etc.): ";		//Tells the user what they can do
					cin>>game_choice;		//Prompts the user to input
				}
			    if (game_choice==1){		//If the user enters 1
			    	cout<<flush;		//Flushes the output stream
			    	system("CLS");		//Clears the screen
					cout<<"What CPU difficulty do you want (Enter 1, 2, etc.): ";		//Tells the user what they can do
					cout<<"\n\tBeginner --------------- 1";			//Outputs the first menu choice	
					cout<<"\n\tIntermediate ----------- 2";			//Outputs the second menu choice
					cout<<"\n\tExpert ----------------- 3";			//Outputs the third menu choice
					cout<<"\n\tReselect Gamemode ------ 4\n";			//Outputs the third menu choice
					cin>>difficulty;		//Prompts the user to input
					while (difficulty<1 or difficulty>4){			//While the users input is out of range
						cout<<"Invalid Input! Retry.\n";			//Tells the user that the input was wrong
						cout<<"What CPU difficulty do you want (Enter 1, 2, etc.): ";		//Tells the user what they can do
						cin>>difficulty;		//Prompts the user to input
					}
					if (difficulty<4){		//If the user enters 1-3
						cout<<"\nWould you like to go first (Y or N): ";		//Tells the user what to enter
						cin>>player_start;		//Prompts the user to input	
						while (toupper(player_start)!='Y' and toupper(player_start)!='N'){		//While the input is incorrect
							cout<<"Invalid Input! Retry.\n";			//Tells the user that the input was wrong
							cout<<"Would you like to go first (Y or N): ";		//Tells the user what to input
							cin>>player_start;			//Prompts the user to input
						}
						player_start=toupper(player_start);		//Capitalizes the users choice
					}
				}
				else if (game_choice==2){	//If the user enters 2
					if (difficulty==4){		//If the menu had been reselected
						difficulty=0;		//Sets difficulty to 0
					}
				}
				else{		//If the user enters 3
					break;		//breaks out of the do-while loop
				}
			} while (difficulty==4);		//While the user enters 4 in singleplayer
			if (game_choice==3){		//If the user wants to return to the main menu	
			    cout<<flush;		//Flushes the output stream
			    system("CLS");		//Clears the screen
				continue;		//Skips the rest of the loop
			}
			
			cout<<"\nHow many rows do you want: ";		//Tells the user what they can do
			cin>>rows;		//Prompts the user to input
			while (rows<3 or rows>26){			//While the users input is out of range
				cout<<"Change the row count! Retry.\n";			//Tells the user that the input was wrong
				cout<<"How many rows do you want (Max 26): ";		//Tells the user what they can do
				cin>>rows;		//Prompts the user to input
			}
			cout<<"\nHow many columns do you want: ";		//Tells the user what they can do
			cin>>cols;		//Prompts the user to input
			while (cols<3 or cols>30){			//While the users input is out of range
				cout<<"Change the column count! Retry.\n";			//Tells the user that the input was wrong
				cout<<"How many columns do you want (Max 30): ";		//Tells the user what they can do
				cin>>cols;		//Prompts the user to input
			}
		
		    cout<<flush;		//Flushes the output stream
		    system("CLS");		//Clears the screen
			char board[rows][cols];			//Declares a 2D char array for the actual board
			fill( &board[0][0], &board[0][0] + sizeof(board), ' ' );		//Fills the board with spaces
			copy(&board[0][0], &board[0][0]+rows*cols,&fake_board[0][0]);		//Copies the real board into the fake copy
			
			for (int h=1;h>0;h++){		//Infinite for loop
				create_SOS(fake_board, rows, cols, h%2);		//Creates the game board
				cout<<endl;		//NewLine
				cout<<"\e[92mSCORE:\n\n";		//Outputs score in green
				cout<<"\e[94m";		//Changes color to blue
				if (difficulty==0){		//If it's a human v human game
					cout<<"Player 1: ";		//Outputs which player it is
				}
				else if (player_start=='Y'){		//If the user chose to go first
					cout<<"You: ";		//Outputs who is player 1
				}
				else if (player_start=='N'){		//If the user chose to go second
					cout<<"Computer: ";		//Outputs who is player 1
				}
				cout<<p1_points<<"    \e[91m";		//Outputs the players points and change color to red
				if (difficulty==0){			//If it's a human v human game
					cout<<"Player 2: ";	//Outputs which player it is
				}
				else if (player_start=='N'){		//If the user chose to go second
					cout<<"You: ";		//Outputs who is player 2
				}
				else if (player_start=='Y'){		//If the user chose to go first
					cout<<"Computer: ";		//Outputs who is player 2
				}
				cout<<p2_points<<"\e[0m\n\n";		//Outputs the players points and resets color
								
				for (int i=0;i<rows;i++){		//From 0 to the row count
					for (int j=0;j<cols;j++){		//From 0 to the column count
						if (board[i][j]==' '){		//If there is an empty spot
							full=false;		//Sets full to false
							break;		//Exits out of the inner for loop
						}
						else if (j==cols-1){		//If the last spot in the row is not a space
							full=true;		//sets full to true
						}
					}
					if (full==false){		//If there is an empty spot
						break;		//Exits out of the outer loop
					}
				}
				if (full==true){		//If all spots are filled
					break;		//Stops the game
				}
				if (h%2==1){		//Player 1
					if (player_start=='Y' or difficulty==0){		//Human P1
						if (difficulty==0){		//If the gamemode is multiplayer
							cout<<"PLAYER 1's TURN!\n";		//Outputs whose turn it is
						}
						else if (player_start=='Y'){		//If the player wants to start against an AI
							cout<<"YOUR TURN!\n";		//Outputs whose turn it is
						}
						cout<<"\nEnter the rows and column where you want to place (Ex. A2): ";		//Tells the user what to do
						cin>>spot;		//Prompts the user to input
						while (spot_check(spot,rows,cols)==false or board[toupper(spot.at(0))-65][(spot.at(1)-'0')-1]!=' '){		//While the input is wrong
							if (spot=="00"){		//If the user wants to quit
								break;		//Exits out of the while loop
							}
							cout.setstate(ios_base::failbit);		//Disables output
							if (spot_check(spot,rows,cols)==true and board[toupper(spot.at(0))-65][(spot.at(1)-'0')-1]!=' '){		//If the spot chosen isn't empty
								cout.clear();		//Enables output
								cout<<"You can only place on blank spots!";		//Tells the user what was wrong
							}
							cout.clear();		//Enables output
							cout<<" Retry.\n";		//Tells the user to reenter
							cout<<"Enter the rows and column where you want to place (Ex. A2): ";		//Tells the user what to enter
							cin>>spot;		//Prompts the user to input
						}
						if (spot=="00"){		//If the user wants to quit
							cout<<flush;		//Flushes the output stream
							cout<<"\e["<<(rows*2)+9+(sidebars*2)<<";1H\e[0J";	//Clears all lines under the game board
							break;		//Exits out of the for loop
						}
						x=(toupper(spot.at(0))-64)-1;		//Sets the x position to user's letter
						if (spot.length()==2){		//If the number is two digits
							y=(spot.at(1)-'0')-1;			//Sets the y position to the user's number
						}
						else{		//If the number is 3 digits
							y=stoi(spot.substr(1))-1;			//Sets the y position to the user's number
						}
						
						cout<<"\nWhat letter do you want to place (S or O): ";		//Tells the user what to enter
						cin>>letter;			//Prompts the user to input
						while (toupper(letter)!='S' and toupper(letter)!='O'){		//While the letter isn't S or O
							cout<<"Invalid Input! Retry.\n";		//Tells the user that the input was wrong
							cout<<"What letter do you want to place (S or O): ";		//Tells the user what to input
							cin>>letter;		//Prompts the user to input
						}
						letter=toupper(letter);		//Capitalizes the choice if it's lowercase
					}
					else{			//COMPUTER P1	
						cout<<"COMPUTER'S TURN (P1)\n";		//Outputs whose turn it is
						if (difficulty==1){		//If the user chose beginner
							do {		//Do this
								x=rand()%rows;		//Randomly generates a row in range
								y=rand()%cols;		//Randomly generates a column in range
							} while (board[x][y]!=' ');	//While the spot randomly selected isn't open
							rand_letter=rand()%2;		//Randomly generates a number 0 or 1
							if (rand_letter==0){		//If 0 was generated
								letter='O';		//Makes the computer's letter O
							}
							else{		//If 1 was generated
								letter='S';		//Makes the computer's letter S
							}
						}
						else if (difficulty==2){		//If the user chose intermediate (only blocking, no trying to win)
							for (int i=0;i<rows;i++){		//Horizontal search
								for (int j=0;j<cols-2;j++){		//From the leftmost to the 3rd rightmost column
									if (board[i][j]=='S' and board[i][j+1]==' ' and board[i][j+2]=='S'){		//If a middle spot is open
										moves.push_back(to_move(i,j+1,'S'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]==' ' and board[i][j+1]=='O' and board[i][j+2]=='S'){		//If the left spot is open
										moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]=='S' and board[i][j+1]=='O' and board[i][j+2]==' '){		//If the right spot is open
										moves.push_back(to_move(i,j+2,'O'));		//Adds the empty spot to the list of possible moves
									}
								}
							}
							for (int i=0;i<rows-2;i++){		//From the top to the 3rd bottom row
								for (int j=0;j<cols;j++){		//Vertical
									if (board[i][j]=='S' and board[i+1][j]==' ' and board[i+2][j]=='S'){		//If the middle spot is open
										moves.push_back(to_move(i+1,j,'S'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]==' ' and board[i+1][j]=='O' and board[i+2][j]=='S'){		//If the left spot is open
										moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]=='S' and board[i+1][j]=='O' and board[i+2][j]==' '){		//If the right spot is open
										moves.push_back(to_move(i+2,j,'O'));		//Adds the empty spot to the list of possible moves
									}
								}
								for (int j=0;j<cols-2;j++){		//Diagonal right
									if (board[i][j]=='S' and board[i+1][j+1]==' ' and board[i+2][j+2]=='S'){		//If the middle spot is open
										moves.push_back(to_move(i+1,j+1,'S'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]==' ' and board[i+1][j+1]=='O' and board[i+2][j+2]=='S'){		//If the left spot is open
										moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]=='S' and board[i+1][j+1]=='O' and board[i+2][j+2]==' '){		//If the right spot is open
										moves.push_back(to_move(i+2,j+2,'O'));		//Adds the empty spot to the list of possible moves
									}
								}
								for (int j=2;j<cols;j++){		//Diagonal left
									if (board[i][j]=='S' and board[i+1][j-1]==' ' and board[i+2][j-2]=='S'){		//If the middle spot is open
										moves.push_back(to_move(i+1,j-1,'S'));				//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]==' ' and board[i+1][j-1]=='O' and board[i+2][j-2]=='S'){		//If the left spot is open
										moves.push_back(to_move(i,j,'O'));			//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]=='S' and board[i+1][j-1]=='O' and board[i+2][j-2]==' '){		//If the right spot is open
										moves.push_back(to_move(i+2,j-2,'O'));		//Adds the empty spot to the list of possible moves
									}
								}
							}
							if (moves.empty()){		//If no win-blocking moves are available
								for (int i=0;i<rows;i++){		//Horizontal
									for (int j=0;j<cols-2;j++){		//From the leftmost to the 3rd rightmost column
										if (board[i][j]==' ' and board[i][j+1]==' ' and board[i][j+2]=='S'){		//If only the right spot isn't open
											moves.push_back(to_move(i,j+1,'S'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]==' ' and board[i][j+1]=='O' and board[i][j+2]==' '){		//If only the middle spot isn't open
											moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]=='S' and board[i][j+1]==' ' and board[i][j+2]==' '){		//If only the left spot isn't open
											moves.push_back(to_move(i,j+2,'O'));		//Adds the empty spot to the list of possible moves
										}
									}
								}
								for (int i=0;i<rows-2;i++){	
									for (int j=0;j<cols;j++){		//Vertical
										if (board[i][j]==' ' and board[i+1][j]==' ' and board[i+2][j]=='S'){		//If only the right spot isn't open
											moves.push_back(to_move(i+1,j,'S'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]==' ' and board[i+1][j]=='O' and board[i+2][j]==' '){		//If only the middle spot isn't open
											moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]=='S' and board[i+1][j]==' ' and board[i+2][j]==' '){		//If only the left spot isn't open
											moves.push_back(to_move(i+2,j,'O'));		//Adds the empty spot to the list of possible moves
										}
									}
									for (int j=0;j<cols-2;j++){		//Diagonal right
										if (board[i][j]==' ' and board[i+1][j+1]==' ' and board[i+2][j+2]=='S'){		//If only the right spot isn't open
											moves.push_back(to_move(i+1,j+1,'S'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]==' ' and board[i+1][j+1]=='O' and board[i+2][j+2]==' '){		//If only the middle spot isn't open
											moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]=='S' and board[i+1][j+1]==' ' and board[i+2][j+2]==' '){		//If only the left spot isn't open
											moves.push_back(to_move(i+2,j+2,'O'));		//Adds the empty spot to the list of possible moves
										}
									}
									for (int j=2;j<cols;j++){		//Diagonal left
										if (board[i][j]==' ' and board[i+1][j-1]==' ' and board[i+2][j-2]=='S'){		//If only the right spot isn't open
											moves.push_back(to_move(i+1,j-1,'S'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]==' ' and board[i+1][j-1]=='O' and board[i+2][j-2]==' '){		//If only the middle spot isn't open
											moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]=='S' and board[i+1][j-1]==' ' and board[i+2][j-2]==' '){		//If only the left spot isn't open
											moves.push_back(to_move(i+2,j-2,'O'));		//Adds the empty spot to the list of possible moves
										}
									}
								}
							}
							
							if (moves.empty()){		//If no blocking moves were found
								do {		//Do this
									x=rand()%rows;		//Randomly generates a row in range
									y=rand()%cols;		//Randomly generates a column in range
								} while (board[x][y]!=' ');	//While the spot randomly selected isn't open
								rand_letter=rand()%2;		//Randomly generates a number 0 or 1
								if (rand_letter==0){		//If 0 was generated
									letter='O';		//Makes the computer's letter O
								}
								else{		//If 1 was generated
									letter='S';		//Makes the computer's letter S
								}
							}
							else{		//If at least 1 blocking move was round
								do{		//Do this
									ai_move=moves[rand()%moves.size()];		//Sets the ai's move to a randomly generated move from the vector 
									x=(ai_move).at(0)-65;		//sets the x value to the first letter in the move selected
									y=((ai_move).at(1)-'0')-1;		//sets the x value to the number in the move selected
									letter=ai_move.at(2);		//sets the x value to the second letter in the move selected
								} while (board[x][y]!=' ');		//While the spot selected is not empty
							}
						}
						else if (difficulty==3){		//If the user selected expert
							for (int i=0;i<rows;i++){		//Horizontal
								for (int j=0;j<cols-2;j++){		//From the leftmost to the 3rd rightmost column
									if (board[i][j]=='S' and board[i][j+1]==' ' and board[i][j+2]=='S'){		//If only the middle spot is open
										moves.push_back(to_move(i,j+1,'O'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]==' ' and board[i][j+1]=='O' and board[i][j+2]=='S'){		//If only the left spot is open
										moves.push_back(to_move(i,j,'S'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]=='S' and board[i][j+1]=='O' and board[i][j+2]==' '){		//If only the right spot is open
										moves.push_back(to_move(i,j+2,'S'));		//Adds the empty spot to the list of possible moves
									}
								}
							}
							for (int i=0;i<rows-2;i++){		//From the top to the 3rd bottom row
								for (int j=0;j<cols;j++){		//Vertical
									if (board[i][j]=='S' and board[i+1][j]==' ' and board[i+2][j]=='S'){		//If only the middle spot is open	
										moves.push_back(to_move(i+1,j,'O'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]==' ' and board[i+1][j]=='O' and board[i+2][j]=='S'){		//If only the left spot is open
										moves.push_back(to_move(i,j,'S'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]=='S' and board[i+1][j]=='O' and board[i+2][j]==' '){		//If only the right spot is open
										moves.push_back(to_move(i+2,j,'S'));		//Adds the empty spot to the list of possible moves
									}
								}
								for (int j=0;j<cols-2;j++){		//Diagonal right
									if (board[i][j]=='S' and board[i+1][j+1]==' ' and board[i+2][j+2]=='S'){		//If only the middle spot is open
										moves.push_back(to_move(i+1,j+1,'O'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]==' ' and board[i+1][j+1]=='O' and board[i+2][j+2]=='S'){		//If only the left spot is open
										moves.push_back(to_move(i,j,'S'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]=='S' and board[i+1][j+1]=='O' and board[i+2][j+2]==' '){		//If only the right spot is open
										moves.push_back(to_move(i+2,j+2,'S'));		//Adds the empty spot to the list of possible moves
									}
								}
								for (int j=2;j<cols;j++){		//Diagonal left
									if (board[i][j]=='S' and board[i+1][j-1]==' ' and board[i+2][j-2]=='S'){		//If only the middle spot is open
										moves.push_back(to_move(i+1,j-1,'O'));		//Adds the empty spot to the list of possible moves
										letter='O';
									}
									else if (board[i][j]==' ' and board[i+1][j-1]=='O' and board[i+2][j-2]=='S'){		//If only the left spot is open
										moves.push_back(to_move(i,j,'S'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]=='S' and board[i+1][j-1]=='O' and board[i+2][j-2]==' '){		//If only the right spot is open
										moves.push_back(to_move(i+2,j-2,'S'));		//Adds the empty spot to the list of possible moves
									}
								}
							}
							if (moves.empty()){		//If no win-blocking moves are available
								for (int i=0;i<rows;i++){		//Horizontal
									for (int j=0;j<cols-2;j++){		//From the leftmost to the 3rd rightmost column
										if (board[i][j]==' ' and board[i][j+1]==' ' and board[i][j+2]=='S'){		//If only the right spot isn't open
											moves.push_back(to_move(i,j+1,'S'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]==' ' and board[i][j+1]=='O' and board[i][j+2]==' '){		//If only the middle spot isn't open
											moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]=='S' and board[i][j+1]==' ' and board[i][j+2]==' '){		//If only the left spot isn't open
											moves.push_back(to_move(i,j+2,'O'));		//Adds the empty spot to the list of possible moves
										}
									}
								}
								for (int i=0;i<rows-2;i++){	
									for (int j=0;j<cols;j++){		//Vertical
										if (board[i][j]==' ' and board[i+1][j]==' ' and board[i+2][j]=='S'){		//If only the right spot isn't open
											moves.push_back(to_move(i+1,j,'S'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]==' ' and board[i+1][j]=='O' and board[i+2][j]==' '){		//If only the middle spot isn't open
											moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]=='S' and board[i+1][j]==' ' and board[i+2][j]==' '){		//If only the left spot isn't open
											moves.push_back(to_move(i+2,j,'O'));		//Adds the empty spot to the list of possible moves
										}
									}
									for (int j=0;j<cols-2;j++){		//Diagonal right
										if (board[i][j]==' ' and board[i+1][j+1]==' ' and board[i+2][j+2]=='S'){		//If only the right spot isn't open
											moves.push_back(to_move(i+1,j+1,'S'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]==' ' and board[i+1][j+1]=='O' and board[i+2][j+2]==' '){		//If only the middle spot isn't open
											moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]=='S' and board[i+1][j+1]==' ' and board[i+2][j+2]==' '){		//If only the left spot isn't open
											moves.push_back(to_move(i+2,j+2,'O'));		//Adds the empty spot to the list of possible moves
										}
									}
									for (int j=2;j<cols;j++){		//Diagonal left
										if (board[i][j]==' ' and board[i+1][j-1]==' ' and board[i+2][j-2]=='S'){		//If only the right spot isn't open
											moves.push_back(to_move(i+1,j-1,'S'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]==' ' and board[i+1][j-1]=='O' and board[i+2][j-2]==' '){		//If only the middle spot isn't open
											moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]=='S' and board[i+1][j-1]==' ' and board[i+2][j-2]==' '){		//If only the left spot isn't open
											moves.push_back(to_move(i+2,j-2,'O'));		//Adds the empty spot to the list of possible moves
										}
									}
								}
							}
							
							if (moves.empty()){		//If no blocking moves were found
								do {		//Do this
									x=rand()%rows;		//Randomly generates a row in range
									y=rand()%cols;		//Randomly generates a column in range
								} while (board[x][y]!=' ');	//While the spot randomly selected isn't open
								rand_letter=rand()%2;		//Randomly generates a number 0 or 1
								if (rand_letter==0){		//If 0 was generated
									letter='O';		//Makes the computer's letter O
								}
								else{		//If 1 was generated
									letter='S';		//Makes the computer's letter S
								}
							}
							else{		//If at least 1 blocking move was round
								do{		//Do this
									ai_move=moves[rand()%moves.size()];		//Sets the ai's move to a randomly generated move from the vector 
									x=(ai_move).at(0)-65;		//sets the x value to the first letter in the move selected
									y=((ai_move).at(1)-'0')-1;		//sets the x value to the number in the move selected
									letter=ai_move.at(2);		//sets the x value to the second letter in the move selected
								} while (board[x][y]!=' ');		//While the spot selected is not empty
							}
						}
						cout<<"\nMOVE: "<<letter<<" at "<<char(x+65)<<y+1<<"\n";		//Outputs the AI's move		
						system("PAUSE");		//Waits for the user to press a button
					}
				}
				else{			//Player 2
					if (player_start=='N' or difficulty==0){		//Human P2
						if (difficulty==0){		//If the gamemode is multiplayer
							cout<<"PLAYER 2's TURN!\n";		//Outputs whose turn it is
						}
						else if (player_start=='N'){		//If the player wants to start against an AI
							cout<<"YOUR TURN!\n";		//Outputs whose turn it is
						}
						cout<<"\nEnter the rows and column where you want to place (Ex. A2): ";		//Tells the user what to do
						cin>>spot;		//Prompts the user to input
						while (spot_check(spot,rows,cols)==false or board[toupper(spot.at(0))-65][(spot.at(1)-'0')-1]!=' '){		//While the input is wrong
							if (spot=="00"){		//If the user wants to quit
								break;		//Exits out of the while loop
							}
							cout.setstate(ios_base::failbit);		//Disables output
							if (spot_check(spot,rows,cols)==true and board[toupper(spot.at(0))-65][(spot.at(1)-'0')-1]!=' '){		//If the spot chosen isn't empty
								cout.clear();		//Enables output
								cout<<"You can only place on blank spots!";		//Tells the user what was wrong
							}
							cout.clear();		//Enables output
							cout<<" Retry.\n";		//Tells the user to reenter
							cout<<"Enter the rows and column where you want to place (Ex. A2): ";		//Tells the user what to enter
							cin>>spot;		//Prompts the user to input
						}
						if (spot=="00"){		//If the user wants to quit
							cout<<flush;		//Flushes the output stream
							cout<<"\e["<<(rows*2)+9+(sidebars*2)<<";1H\e[0J";	//Clears all lines under the game board
							break;		//Exits out of the for loop
						}
						x=(toupper(spot.at(0))-64)-1;		//Sets the x position to user's letter
						if (spot.length()==2){		//If the number is two digits
							y=(spot.at(1)-'0')-1;			//Sets the y position to the user's number
						}
						else{		//If the number is 3 digits
							y=stoi(spot.substr(1))-1;			//Sets the y position to the user's number
						}
						
						cout<<"\nWhat letter do you want to place (S or O): ";		//Tells the user what to enter
						cin>>letter;			//Prompts the user to input
						while (toupper(letter)!='S' and toupper(letter)!='O'){		//While the letter isn't S or O
							cout<<"Invalid Input! Retry.\n";		//Tells the user that the input was wrong
							cout<<"What letter do you want to place (S or O): ";		//Tells the user what to input
							cin>>letter;		//Prompts the user to input
						}
						letter=toupper(letter);		//Capitalizes the choice if it's lowercase
					}
					else{			//COMPUTER P2
						cout<<"COMPUTER'S TURN (P2)\n";		//Outputs whose turn it is
						if (difficulty==1){		//If the user chose beginner
							do {		//Do this
								x=rand()%rows;		//Randomly generates a row in range
								y=rand()%cols;		//Randomly generates a column in range
							} while (board[x][y]!=' ');	//While the spot randomly selected isn't open
							rand_letter=rand()%2;		//Randomly generates a number 0 or 1
							if (rand_letter==0){		//If 0 was generated
								letter='O';		//Makes the computer's letter O
							}
							else{		//If 1 was generated
								letter='S';		//Makes the computer's letter S
							}
						}
						else if (difficulty==2){		//If the user chose intermediate (only blocking, no trying to win)
							for (int i=0;i<rows;i++){		//Horizontal search
								for (int j=0;j<cols-2;j++){		//From the leftmost to the 3rd rightmost column
									if (board[i][j]=='S' and board[i][j+1]==' ' and board[i][j+2]=='S'){		//If a middle spot is open
										moves.push_back(to_move(i,j+1,'S'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]==' ' and board[i][j+1]=='O' and board[i][j+2]=='S'){		//If the left spot is open
										moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]=='S' and board[i][j+1]=='O' and board[i][j+2]==' '){		//If the right spot is open
										moves.push_back(to_move(i,j+2,'O'));		//Adds the empty spot to the list of possible moves
									}
								}
							}
							for (int i=0;i<rows-2;i++){		//From the top to the 3rd bottom row
								for (int j=0;j<cols;j++){		//Vertical
									if (board[i][j]=='S' and board[i+1][j]==' ' and board[i+2][j]=='S'){		//If the middle spot is open
										moves.push_back(to_move(i+1,j,'S'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]==' ' and board[i+1][j]=='O' and board[i+2][j]=='S'){		//If the left spot is open
										moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]=='S' and board[i+1][j]=='O' and board[i+2][j]==' '){		//If the right spot is open
										moves.push_back(to_move(i+2,j,'O'));		//Adds the empty spot to the list of possible moves
									}
								}
								for (int j=0;j<cols-2;j++){		//Diagonal right
									if (board[i][j]=='S' and board[i+1][j+1]==' ' and board[i+2][j+2]=='S'){		//If the middle spot is open
										moves.push_back(to_move(i+1,j+1,'S'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]==' ' and board[i+1][j+1]=='O' and board[i+2][j+2]=='S'){		//If the left spot is open
										moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]=='S' and board[i+1][j+1]=='O' and board[i+2][j+2]==' '){		//If the right spot is open
										moves.push_back(to_move(i+2,j+2,'O'));		//Adds the empty spot to the list of possible moves
									}
								}
								for (int j=2;j<cols;j++){		//Diagonal left
									if (board[i][j]=='S' and board[i+1][j-1]==' ' and board[i+2][j-2]=='S'){		//If the middle spot is open
										moves.push_back(to_move(i+1,j-1,'S'));				//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]==' ' and board[i+1][j-1]=='O' and board[i+2][j-2]=='S'){		//If the left spot is open
										moves.push_back(to_move(i,j,'O'));			//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]=='S' and board[i+1][j-1]=='O' and board[i+2][j-2]==' '){		//If the right spot is open
										moves.push_back(to_move(i+2,j-2,'O'));		//Adds the empty spot to the list of possible moves
									}
								}
							}
							if (moves.empty()){		//If no win-blocking moves are available
								for (int i=0;i<rows;i++){		//Horizontal
									for (int j=0;j<cols-2;j++){		//From the leftmost to the 3rd rightmost column
										if (board[i][j]==' ' and board[i][j+1]==' ' and board[i][j+2]=='S'){		//If only the right spot isn't open
											moves.push_back(to_move(i,j+1,'S'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]==' ' and board[i][j+1]=='O' and board[i][j+2]==' '){		//If only the middle spot isn't open
											moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]=='S' and board[i][j+1]==' ' and board[i][j+2]==' '){		//If only the left spot isn't open
											moves.push_back(to_move(i,j+2,'O'));		//Adds the empty spot to the list of possible moves
										}
									}
								}
								for (int i=0;i<rows-2;i++){	
									for (int j=0;j<cols;j++){		//Vertical
										if (board[i][j]==' ' and board[i+1][j]==' ' and board[i+2][j]=='S'){		//If only the right spot isn't open
											moves.push_back(to_move(i+1,j,'S'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]==' ' and board[i+1][j]=='O' and board[i+2][j]==' '){		//If only the middle spot isn't open
											moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]=='S' and board[i+1][j]==' ' and board[i+2][j]==' '){		//If only the left spot isn't open
											moves.push_back(to_move(i+2,j,'O'));		//Adds the empty spot to the list of possible moves
										}
									}
									for (int j=0;j<cols-2;j++){		//Diagonal right
										if (board[i][j]==' ' and board[i+1][j+1]==' ' and board[i+2][j+2]=='S'){		//If only the right spot isn't open
											moves.push_back(to_move(i+1,j+1,'S'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]==' ' and board[i+1][j+1]=='O' and board[i+2][j+2]==' '){		//If only the middle spot isn't open
											moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]=='S' and board[i+1][j+1]==' ' and board[i+2][j+2]==' '){		//If only the left spot isn't open
											moves.push_back(to_move(i+2,j+2,'O'));		//Adds the empty spot to the list of possible moves
										}
									}
									for (int j=2;j<cols;j++){		//Diagonal left
										if (board[i][j]==' ' and board[i+1][j-1]==' ' and board[i+2][j-2]=='S'){		//If only the right spot isn't open
											moves.push_back(to_move(i+1,j-1,'S'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]==' ' and board[i+1][j-1]=='O' and board[i+2][j-2]==' '){		//If only the middle spot isn't open
											moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]=='S' and board[i+1][j-1]==' ' and board[i+2][j-2]==' '){		//If only the left spot isn't open
											moves.push_back(to_move(i+2,j-2,'O'));		//Adds the empty spot to the list of possible moves
										}
									}
								}
							}
							
							if (moves.empty()){		//If no blocking moves were found
								do {		//Do this
									x=rand()%rows;		//Randomly generates a row in range
									y=rand()%cols;		//Randomly generates a column in range
								} while (board[x][y]!=' ');	//While the spot randomly selected isn't open
								rand_letter=rand()%2;		//Randomly generates a number 0 or 1
								if (rand_letter==0){		//If 0 was generated
									letter='O';		//Makes the computer's letter O
								}
								else{		//If 1 was generated
									letter='S';		//Makes the computer's letter S
								}
							}
							else{		//If at least 1 blocking move was round
								do{		//Do this
									ai_move=moves[rand()%moves.size()];		//Sets the ai's move to a randomly generated move from the vector 
									x=(ai_move).at(0)-65;		//sets the x value to the first letter in the move selected
									y=((ai_move).at(1)-'0')-1;		//sets the x value to the number in the move selected
									letter=ai_move.at(2);		//sets the x value to the second letter in the move selected
								} while (board[x][y]!=' ');		//While the spot selected is not empty
							}
						}
						else if (difficulty==3){		//If the user selected expert
							for (int i=0;i<rows;i++){		//Horizontal
								for (int j=0;j<cols-2;j++){		//From the leftmost to the 3rd rightmost column
									if (board[i][j]=='S' and board[i][j+1]==' ' and board[i][j+2]=='S'){		//If only the middle spot is open
										moves.push_back(to_move(i,j+1,'O'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]==' ' and board[i][j+1]=='O' and board[i][j+2]=='S'){		//If only the left spot is open
										moves.push_back(to_move(i,j,'S'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]=='S' and board[i][j+1]=='O' and board[i][j+2]==' '){		//If only the right spot is open
										moves.push_back(to_move(i,j+2,'S'));		//Adds the empty spot to the list of possible moves
									}
								}
							}
							for (int i=0;i<rows-2;i++){		//From the top to the 3rd bottom row
								for (int j=0;j<cols;j++){		//Vertical
									if (board[i][j]=='S' and board[i+1][j]==' ' and board[i+2][j]=='S'){		//If only the middle spot is open	
										moves.push_back(to_move(i+1,j,'O'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]==' ' and board[i+1][j]=='O' and board[i+2][j]=='S'){		//If only the left spot is open
										moves.push_back(to_move(i,j,'S'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]=='S' and board[i+1][j]=='O' and board[i+2][j]==' '){		//If only the right spot is open
										moves.push_back(to_move(i+2,j,'S'));		//Adds the empty spot to the list of possible moves
									}
								}
								for (int j=0;j<cols-2;j++){		//Diagonal right
									if (board[i][j]=='S' and board[i+1][j+1]==' ' and board[i+2][j+2]=='S'){		//If only the middle spot is open
										moves.push_back(to_move(i+1,j+1,'O'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]==' ' and board[i+1][j+1]=='O' and board[i+2][j+2]=='S'){		//If only the left spot is open
										moves.push_back(to_move(i,j,'S'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]=='S' and board[i+1][j+1]=='O' and board[i+2][j+2]==' '){		//If only the right spot is open
										moves.push_back(to_move(i+2,j+2,'S'));		//Adds the empty spot to the list of possible moves
									}
								}
								for (int j=2;j<cols;j++){		//Diagonal left
									if (board[i][j]=='S' and board[i+1][j-1]==' ' and board[i+2][j-2]=='S'){		//If only the middle spot is open
										moves.push_back(to_move(i+1,j-1,'O'));		//Adds the empty spot to the list of possible moves
										letter='O';
									}
									else if (board[i][j]==' ' and board[i+1][j-1]=='O' and board[i+2][j-2]=='S'){		//If only the left spot is open
										moves.push_back(to_move(i,j,'S'));		//Adds the empty spot to the list of possible moves
									}
									else if (board[i][j]=='S' and board[i+1][j-1]=='O' and board[i+2][j-2]==' '){		//If only the right spot is open
										moves.push_back(to_move(i+2,j-2,'S'));		//Adds the empty spot to the list of possible moves
									}
								}
							}
							if (moves.empty()){		//If no win-blocking moves are available
								for (int i=0;i<rows;i++){		//Horizontal
									for (int j=0;j<cols-2;j++){		//From the leftmost to the 3rd rightmost column
										if (board[i][j]==' ' and board[i][j+1]==' ' and board[i][j+2]=='S'){		//If only the right spot isn't open
											moves.push_back(to_move(i,j+1,'S'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]==' ' and board[i][j+1]=='O' and board[i][j+2]==' '){		//If only the middle spot isn't open
											moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]=='S' and board[i][j+1]==' ' and board[i][j+2]==' '){		//If only the left spot isn't open
											moves.push_back(to_move(i,j+2,'O'));		//Adds the empty spot to the list of possible moves
										}
									}
								}
								for (int i=0;i<rows-2;i++){	
									for (int j=0;j<cols;j++){		//Vertical
										if (board[i][j]==' ' and board[i+1][j]==' ' and board[i+2][j]=='S'){		//If only the right spot isn't open
											moves.push_back(to_move(i+1,j,'S'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]==' ' and board[i+1][j]=='O' and board[i+2][j]==' '){		//If only the middle spot isn't open
											moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]=='S' and board[i+1][j]==' ' and board[i+2][j]==' '){		//If only the left spot isn't open
											moves.push_back(to_move(i+2,j,'O'));		//Adds the empty spot to the list of possible moves
										}
									}
									for (int j=0;j<cols-2;j++){		//Diagonal right
										if (board[i][j]==' ' and board[i+1][j+1]==' ' and board[i+2][j+2]=='S'){		//If only the right spot isn't open
											moves.push_back(to_move(i+1,j+1,'S'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]==' ' and board[i+1][j+1]=='O' and board[i+2][j+2]==' '){		//If only the middle spot isn't open
											moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]=='S' and board[i+1][j+1]==' ' and board[i+2][j+2]==' '){		//If only the left spot isn't open
											moves.push_back(to_move(i+2,j+2,'O'));		//Adds the empty spot to the list of possible moves
										}
									}
									for (int j=2;j<cols;j++){		//Diagonal left
										if (board[i][j]==' ' and board[i+1][j-1]==' ' and board[i+2][j-2]=='S'){		//If only the right spot isn't open
											moves.push_back(to_move(i+1,j-1,'S'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]==' ' and board[i+1][j-1]=='O' and board[i+2][j-2]==' '){		//If only the middle spot isn't open
											moves.push_back(to_move(i,j,'O'));		//Adds the empty spot to the list of possible moves
										}
										else if (board[i][j]=='S' and board[i+1][j-1]==' ' and board[i+2][j-2]==' '){		//If only the left spot isn't open
											moves.push_back(to_move(i+2,j-2,'O'));		//Adds the empty spot to the list of possible moves
										}
									}
								}
							}
							
							if (moves.empty()){		//If no blocking moves were found
								do {		//Do this
									x=rand()%rows;		//Randomly generates a row in range
									y=rand()%cols;		//Randomly generates a column in range
								} while (board[x][y]!=' ');	//While the spot randomly selected isn't open
								rand_letter=rand()%2;		//Randomly generates a number 0 or 1
								if (rand_letter==0){		//If 0 was generated
									letter='O';		//Makes the computer's letter O
								}
								else{		//If 1 was generated
									letter='S';		//Makes the computer's letter S
								}
							}
							else{		//If at least 1 blocking move was found
								do{		//Do this
									ai_move=moves[rand()%moves.size()];		//Sets the ai's move to a randomly generated move from the vector 
									x=(ai_move).at(0)-65;		//sets the x value to the first letter in the move selected
									y=((ai_move).at(1)-'0')-1;		//sets the x value to the number in the move selected
									letter=ai_move.at(2);		//sets the x value to the second letter in the move selected
								} while (board[x][y]!=' ');		//While the spot selected is not empty
							}
						}
						cout<<"\nMOVE: "<<letter<<" at "<<char(x+65)<<y+1<<"\n";		//Outputs the AI's move		
						system("PAUSE");		//Waits for the user to press a button
					}
				}
				board[x][y]=letter;		//Sets the position selected to the letter selected
				color[x][y]=h%2;		//Sets the color to the current player's turn
				moves.resize(0);		//Clears (without actually clearing) the AI moves vector
				copy(&board[0][0], &board[0][0]+rows*cols,&fake_board[0][0]);		//Copies the board values into the fake board
				
				cout<<flush;		//Flushes the output stream
				system("CLS"); 		//Clears the screen
				
				if (points(fake_board, rows, cols, h%2)==true){		//If the player scores a point
					h--;		//Decreases h to make the same player play again
				}
			
			}
			cout<<"\e[1m";		//Sets the text mode to bold
			if (p1_points>p2_points){		//If player 1 wins
				cout<<"\e[94m";		//Changes the text to blue
				if (difficulty==0){		//If it's a human vs human game
					cout<<"\nPLAYER 1 WINS!\n";		//Outputs who wins
				}
				else if (player_start=='Y'){		//If the player chose to go first
					cout<<"\nYOU WIN!\n";		//Outputs who wins
				}
				else if (player_start=='N'){		//If the player chose to go second
					cout<<"\nYOU LOSE!\n";		//Outputs who wins
				}
			}
			else if (p2_points>p1_points){		//If player 2 wins
				cout<<"\e[91m";		//Sets the text color to red
				if (difficulty==0){		//If it's a human vs human game
					cout<<"\nPLAYER 2 WINS!\n";		//Outputs who wins
				}
				else if (player_start=='Y'){		//If the player chose to go first
					cout<<"\nYOU LOSE!\n";		//Outputs who wins
				}
				else if (player_start=='N'){		//If the player chose to go second
					cout<<"\nYOU WIN!\n";		//Outputs who wins
				}
			}
			else{		//If it's a tie game
				cout<<"\e[92m";		//Changes the text color to green
				cout<<"\nTIE GAME!\n";		//Outputs that the game is a tie
			}
			cout<<"\n\n\e[0m";		//NewLines and resets text color
			
			if (difficulty>0){		//If the gamemode is singleplayer
				if (player_start=='Y'){		//If the player started
					score=p1_points/p2_points;		//Setss the score to player1/player2 points (to keep it fair among board sizes)
					if (p2_points==0){		//If division by 0 occurs
						score=p1_points*1.5;		//Sets the score to the winning score * 1.5
					}
				}
				else{		//If the player didn't start
					score=p2_points/p1_points;		//Sets the score to player2/player1 points (to keep it fair among board sizes)
					if (p1_points==0){		//If division by 0 occurs
						score=p2_points*1.5;		//Sets the score to the winning score * 1.5
					}
				}
				if (MessageBox( NULL, TEXT( "Would you like to add your score to the Leaderboard?"), TEXT( "SOS.exe"), MB_ICONQUESTION | MB_YESNO | MB_APPLMODAL )==6){		//Prompts the user with a message box
					add_score_SOS(score, difficulty);		//Calls add_score to add the score on the leaderboard
				}
			}
			system("PAUSE");		//Pauses the program until a key is pressed
		}
	    cout<<flush;		//Flushes the output stream
	    system("CLS");		//Clears the screen
	} while (menu_choice!=0);		//While the 0 is not selected on the menu
}

string to_move(int x, int y, char letter){		//Defines a string function to convert a move and letter to a string
	string spot;		//Declares a string for the spot being created
	spot=char(x+65)+to_string(y+1)+letter;		//Sets it to the x (converted to letter), y (converted to string number), and letter
	return spot;		//Returns the spot as a string
}

bool spot_check(string spot, int rows, int cols){		//Defines a bool function for checking if a spot is legal
	if (spot.length()!=2 and spot.length()!=3){		//If the length isn't correct
		cout<<"Enter a letter, then a number!";		//Tells the user what is incorrect
		return false;		//Ends the function
	}
	if (isalpha(spot.at(0))==false){		//If the first character isn't a letter
		cout<<"The first character should be a letter!";		//Tells the user what is incorrect
		return false;		//Ends the function
	}
	if (isdigit(spot.at(1))==false){		//If the second character isn't a number
		cout<<"The second character should be a number!";		//Tells the user what is incorrect
		return false;		//Ends the function
	}
	if (spot.length()==3 and isdigit(spot.at(2))==false){		//If the third character isn't a number
		cout<<"The third character should be a number!";		//Tells the user what is incorrect
		return false;		//Ends the function
	}
	if (toupper(spot.at(0))-64<1 or toupper(spot.at(0))-64>rows){		//If the letter is out of range
		cout<<"The letter should be between A and "<<char(rows+64)<<"!";		//Tells the user what is incorrect
		return false;		//Ends the function
	}
	if (spot.length()==2 and (spot.at(1)-'0'<1 or spot.at(1)-'0'>cols)){		//If the length is 2 and the number is out of range
		cout<<"The number should be between 1 and "<<cols<<"!";		//Tells the user what is incorrect
		return false;		//Ends the function
	}
	if (spot.length()==3 and (stoi(spot.substr(1))<1 or stoi(spot.substr(1))>cols)){		//If the length is 3 and the number is out of range
		cout<<"The number should be between 1 and "<<cols<<"!";		//Tells the user what is incorrect
		return false;		//Ends the function
	}
	
	return true;		//Ends the function, but good
}

bool points(char fake_board[][50], int rows, int cols, int turn){		//Defines a function for calculating the points
	int curr_points=0;		//Declares an int for the current number of points
	char board[rows][cols];		//Declares a 2D char array for the board
	copy(&fake_board[0][0], &fake_board[0][0]+rows*cols,&board[0][0]);		//Copies the fake board into the real one
	
	for (int i=0;i<rows;i++){		//Horizontal
		for (int j=0;j<cols-2;j++){			//From the leftmost column to the 3rd rightmost
			if (board[i][j]=='S' and board[i][j+1]=='O' and board[i][j+2]=='S'){		//If there is an SOS
				curr_points++;		//Increases the number of points by 1
			}
		}
	}
	for (int i=0;i<rows-2;i++){			//From the top to the 3rd bottom row
		for (int j=0;j<cols;j++){		//Vertical
			if (board[i][j]=='S' and board[i+1][j]=='O' and board[i+2][j]=='S'){		//If there is an SOS
				curr_points++;		//Increases the number of points by 1
			}
		}
		for (int j=0;j<cols-2;j++){		//Diagonal right
			if (board[i][j]=='S' and board[i+1][j+1]=='O' and board[i+2][j+2]=='S'){		//If there is an SOS
				curr_points++;		//Increases the number of points by 1
			}
		}
		for (int j=2;j<cols;j++){		//Diagonal left
			if (board[i][j]=='S' and board[i+1][j-1]=='O' and board[i+2][j-2]=='S'){		//If there is an SOS
				curr_points++;		//Increases the number of points by 1
			}
		}
	}
	
	if (curr_points>total_points){		//If more SOS's were found than the number of points
		if (turn==1){		//If it's player 1's turn
			p1_points+=(curr_points-total_points);		//Adds the amount of new points to P1 points
		}
		else{		//If it's player 2's turn
			p2_points+=(curr_points-total_points);		//Adds the amount of new points to P1 points
		}
		total_points=curr_points;		//Resets the total amount of points to the new number of SOS's found
		return true;		//Returns that points were added (true)
	}
	return false;		//Returns that no points were added (false)
}

void create_SOS(char fake_board[][50], int rows, int cols, int turn){		//Defines a function for creating the board
	char board[rows][cols];		//Declares a 2D char array for the board
	copy(&fake_board[0][0], &fake_board[0][0]+rows*cols,&board[0][0]);		//Copies the fake board into the real one
	
	cout<<"   \u2577";		//Outputs the first vertical line
	for (int i=0;i<cols;i++){		//For each column
		cout<<"   \u2577";		//Outputs another vertical line
	}
	cout<<"\n   \u2502";		//Outputs a longer vertical line
	for (int i=0;i<cols;i++){		//For each column
		if (i+1<10){		//If the number is 1 digit
			cout<<" ";		//Outputs a space
		}
		cout<<i+1;		//Outputs the number
		cout<<" \u2502";		//Outputs the longer line
	}
	cout<<"\n\u2500\u2500\u2500";	//Outputs three thin horizontal lines
	cout<<"\u2546";		//outputs the connecting corner line
	for (int i=0;i<cols-1;i++){		//For each column (-1)
		cout<<"\u2501\u2501\u2501\u2548";		//Outputs three horizontal lines and a connecting edge line
	}
	
	if (sidebars==0){		//If sidebars are disabled
		cout<<"\u2501\u2501\u2501\u252A\n";		//Outputs three horizontal lines and a corner
	}
	else{		//If sidebars are enabled
		cout<<"\u2501\u2501\u2501\u2545\u2500\u2500\u2500\n";		//Outputs three horizontal lines, a corner line (with more lines) and three more horizontal lines
	}
	
	for (int i=0;i<rows;i++){		//For each row
		cout<<" "<<char(i+65)<<" ";		//Outputs the letter for the row
		for (int j=0;j<cols;j++){		//For each column
			cout<<"\u2503 ";		//Outputs a thick vertial line
			if (board[i][j]==' '){		//If the character in the board is a space
				cout<<"\e[0m";		//Resets the color
			}
			else if (color[i][j]==1){		//If it's player 1's piece
				cout<<"\e[94m";		//Changes the text color to blue
			}
			else{		//If it's player 2's piece
				cout<<"\e[91m";		//Changes the text color to red
			}
			cout<<board[i][j]<<"\e[0m ";		//Outputs the board piece and resets the color
		}
		cout<<"\u2503";		//Outputs a vertical line
		if (sidebars==1){		//If sidebard are enabled
			cout<<" "<<char(i+65)<<" ";			//Outputs another letter on the right
		}
		cout<<"\n\u2500\u2500\u2500";		//Outputs three horizontal lines
		if (i<rows-1){		//If the current row isn't the last
			cout<<"\u254A";		//Outputs the left edge piece
			for (int j=0;j<cols-1;j++){		//For each column
				cout<<"\u2501\u2501\u2501\u254B";		//Outputs three horizontal lines and the center line (+ looking thing)
			}
			if (sidebars==0){	//If sidebars are disabled	
				cout<<"\u2501\u2501\u2501\u252B\n";		//Outputs three horizontal lines and an edge line
			}	
			else{	//If sidebars are enabled
				cout<<"\u2501\u2501\u2501\u2549\u2500\u2500\u2500\n";		//Outputs three horizontal lines, a 4-way edge line and three thin horizontal lines
			}
			
		}
	}
	
	if (sidebars==0){		//If sidebars are disabled
		cout<<"\u253A";		//Outputs a corner line
		for (int i=0;i<cols-1;i++){			//For each column (-1)
			cout<<"\u2501\u2501\u2501\u253B";		//Outputs three horizontal lines and a bottom edge line
		}
		cout<<"\u2501\u2501\u2501\u251B\n";		//Outputs three horizontal lines and a corner line
	}
	else{		//If sidebars are enabled
		cout<<"\u2544";		//Outputs a 4 way corner line
		for (int i=0;i<cols-1;i++){		//For each column (-1)
			cout<<"\u2501\u2501\u2501\u2547";		//Outputs three horizontal lines and a 4 way edge line
		}
		cout<<"\u2501\u2501\u2501\u2543\u2500\u2500\u2500\n";		//Outputs three horizontal line, a 4 way corner line and three thin horizontal lines
		cout<<"   \u2502";		//Outputs a vertical line
		for (int i=0;i<cols;i++){		//For each column
			if (i+1<10){		//If the number is 1 digit
				cout<<" ";		//Outputs a space
			}
			cout<<i+1;		//Outputs the number
			cout<<" \u2502";		//Outputs the longer vertical line
		}
		cout<<"\n   \u2575";		//Outputs the short vertical line
		for (int i=0;i<cols;i++){		//For each column
			cout<<"   \u2575";		//Output the short vertical line
		}
		cout<<"\n";		//NewLine
	}
	
}

bool operator<(const name_points&lhs, const name_points&rhs){			//defines the operator for the structure and makes it accept two arguments to make a comparison
    return lhs.points < rhs.points;				//returns the smaller of the two arguments
}

void add_score_SOS(double score, int difficulty){		//Defines a void function with an int paaramter for the players money
	string name;		//Declares a string for the users name
	cout<<"\nWhat is your name: ";		//Tells the user what to input
	cin>>name;			//Prompts the user to input
	while (name.find(" ")==true or name.length()==0){		//If there is a space in the name
		cout<<"No spaces! Retry.\n";		//Tells the user what was wrong
		cout<<"What is your name: ";		//Tells the user what to input
		cin>>name;			//Prompts the user to input
	}
    ofstream highscore;		// Create an output filestream object
	highscore.open("SOS_scores.csv", ios::app);    //Open the SOS_scores.csv file to add data
    highscore<<difficulty<<","<<name<<","<<score<<endl;		// Send data to the stream
    highscore.close();			// Close the file
}

void show_score_SOS(){
	int total_rows=0;		//Declares an int for the total number of rows and initializes it to 0
	int curr_row=0;		//Declares an int for the current row and initializes it to 0
	double points;		//Declares an int for a points from the spreadsheet
	int difficulty;		//Declares an int for the difficulty of a score
	int beginner_rows=0;		//Declares an int for the number of rows for beginner difficulty
	int intermediate_rows=0;		//Declares an int for the number of rows for intermediate difficulty
	int expert_rows=0;			//Declares an int for the number of rows for expert difficulty
	string line;		//declares a string for a line in the spreadsheet
	string phrase;		//Declares a string for the two columns of a line combined from the spreadsheet
	string names;		//Declares a string for the name part of the line
	int comma_pos;		//Declares an int for the location of the comma that separates the columns
	ifstream file("SOS_scores.csv");		//opens the highscore file for input
	while (getline(file, line)){		//while the its possible to read a line from the spreadsheet
		total_rows++;			//Increases the total row count by 1
		if (line.at(0)=='1'){		//If the difficulty is beginner
			beginner_rows++;		//Increases the beginner rows by 1
		}
		else if (line.at(0)=='2'){		//If the difficulty is intermediate
			intermediate_rows++;		//Increases the intermediate rows by 1
		}
		else if (line.at(0)=='3'){		//If the difficulty is expert
			expert_rows++;		//Increases the expert rows by 1
		}
	}
	file.close();		//Closes the spreadsheet
	
	beginner.resize(0);		//changes the size of the scores vector to the total rows
	intermediate.resize(0);		//changes the size of the scores vector to the total rows
	expert.resize(0);		//changes the size of the scores vector to the total rows
		
	ifstream file2("SOS_scores.csv");			//opens the highscore file for input
	for (;curr_row<total_rows;curr_row++){		//Until the current row reaches the total row count
		file2>>phrase;		//Reads in a line from the spreadsheet
		if (phrase!="Highscores"){		//If its not the first line
			difficulty=phrase.at(0)-'0';		//Sets the difficulty to the first number from the file
			phrase.erase(0,2);		//Removes the difficulty number and first comma
			names=phrase;		//names is initializes to the line from the spreadsheet
			comma_pos=phrase.find_last_of(",");		//Finds the location of the final comma (in case one is in the name)
			phrase.erase(0, comma_pos+1);		//removes the name from the line
			names.erase(comma_pos);		//keeps only the name from the line
			points=stod(phrase);		//convers the score into an double and saves it into points
			
			if (difficulty==1){
				beginner.push_back({points,names});		//Puts the score and name into a value in the beginner vector
			}
			else if (difficulty==2){
				intermediate.push_back({points,names});		//Puts the score and name into a value in the intermediate vector
			}
			else if (difficulty==3){
				expert.push_back({points,names});		//Puts the score and name into a value in the expert vector
			}
		}
	}     
	               
	stable_sort(beginner.begin(),beginner.end());		//Sorts the scores vector by points while keeping the names with them (lowest to highest)               
	stable_sort(intermediate.begin(),intermediate.end());		//Sorts the scores vector by points while keeping the names with them (lowest to highest)               
	stable_sort(expert.begin(),expert.end());		//Sorts the scores vector by points while keeping the names with them (lowest to highest)
	
	
	Center_text("    __                   __          __                         __\n");		//Leaderboard ASCII art
	Center_text("   / /   ___  ____ _____/ /__  _____/ /_  ____  ____ __________/ /\n");		//More Leaderboard ASCII art
	Center_text("  / /   / _ \\/ __ `/ __  / _ \\/ ___/ __ \\/ __ \\/ __ `/ ___/ __  / \n");		//More Leaderboard ASCII art
	Center_text(" / /___/  __/ /_/ / /_/ /  __/ /  / /_/ / /_/ / /_/ / /  / /_/ /  \n");		//More Leaderboard ASCII art
	Center_text("/_____/\\___/\\__,_/\\__,_/\\___/_/  /_.___/\\____/\\__,_/_/   \\__,_/   \n");		//More Leaderboard ASCII art
	cout<<"\n";		//NewLine
	Center_text("----------------------------------------------------------------------------------------------------\n");			//Line of separation
	cout<<endl;		//NewLine
	if (total_rows==1){		//If there are no scores
		Center_text("Add Some Scores");			//tells the user that the leaderboard is blank
		cout<<endl<<endl;		//NewLine x2
		return;		//Ends the function
	}	
	if (beginner_rows>0){		//If there are some beginner scores
		Center_text("Beginner:");		//Outputs the beginner score title card
		cout<<"\n";		//NewLine
		if (beginner_rows>2){		//If there are more than three scores in the leaderboard
			for (int i=0;i<3;i++){			//From the first score to the third
				Center_text("#"+to_string(i+1)+" - "+beginner[i].name+": "+to_string(beginner[i].points).substr(0, to_string(beginner[i].points).find(".")+3));		//Outputs the name and the score 
				cout<<"\n";		//NewLine
			}
		}
		else if (beginner_rows<2){		//Otherwise if there are less that three scores
			for (int i=0;i<beginner_rows;i++){		//From the first score to how many rows there are
				Center_text("#"+to_string(i+1)+" - "+beginner[i].name+": "+to_string(beginner[i].points).substr(0, to_string(beginner[i].points).find(".")+3));		//Outputs the name and the score 
				cout<<"\n";		//NewLine
			}
		}
	}	
	if (intermediate_rows>0){		//If there are some intermediate scores
		cout<<"\n";		//NewLine
		Center_text("Intermediate:");		//Outputs the intermediate score title card
		cout<<"\n";		//NewLine
		if (intermediate_rows>2){		//If there are more than three scores in the leaderboard
			for (int i=0;i<3;i++){			//From the first score to the third
				Center_text("#"+to_string(i+1)+" - "+intermediate[i].name+": "+to_string(intermediate[i].points).substr(0, to_string(intermediate[i].points).find(".")+3));		//Outputs the name and the score 
				cout<<"\n";		//NewLine
			}
		}
		else if (intermediate_rows<2){		//Otherwise if there are less that three scores
			for (int i=0;i<intermediate_rows;i++){		//From the first score to how many rows there are
				Center_text("#"+to_string(i+1)+" - "+intermediate[i].name+": "+to_string(intermediate[i].points).substr(0, to_string(intermediate[i].points).find(".")+3));		//Outputs the name and the score 
				cout<<"\n";		//NewLine
			}
		}
	}	
	if (expert_rows>0){		//If there are some expert scores
		cout<<"\n";		//NewLine
		Center_text("Expert:");		//Outputs the expert score title card
		cout<<"\n";		//NewLine
		if (expert_rows>2){		//If there are more than three scores in the leaderboard
			for (int i=0;i<3;i++){			//From the first score to the third
				Center_text("#"+to_string(i+1)+" - "+expert[i].name+": "+to_string(expert[i].points).substr(0, to_string(expert[i].points).find(".")+3));		//Outputs the name and the score 
				cout<<"\n";		//NewLine
			}
		}
		else if (expert_rows<2){		//Otherwise if there are less that three scores
			for (int i=0;i<expert_rows;i++){		//From the first score to how many rows there are
				Center_text("#"+to_string(i+1)+" - "+expert[i].name+": "+to_string(expert[i].points).substr(0, to_string(expert[i].points).find(".")+3));		//Outputs the name and the score 
				cout<<"\n";		//NewLine
			}
		}
	}
	
	file2.close();		//Closes the highscore file
}


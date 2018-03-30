// project.cpp
// Final Project for CSE-20311 fall 2017
// Two-player, user controlled spaceship fighter game
// For more info, see "readme" file
// Seth Cattanach, December 2017

#include <iostream>
#include "gfx.h"
#include <unistd.h>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

#include "ship.h"

int main(){
	int xWindow=1200, yWindow=650;
	char c;

	// open window and create/place ship objects
	gfx_open(xWindow, yWindow, "Final Project: Fighter Ship Game");
	Ship ship1(xWindow/4, yWindow/2);
	Ship ship2(3*xWindow/4, yWindow/2);

	// wait for spacebar to be pressed to begin & give instructions
	gfx_text(xWindow/2, yWindow-50, "PRESS SPACE TO BEGIN");
	gfx_text(xWindow/3, 75, "INSTRUCTIONS: Player 1 uses 'a' and 'd' to turn");
	gfx_text(xWindow/3, 100, "and 's' to shoot");
	gfx_text(xWindow/3, 125, "Player 2 uses 'j' and 'k' to turn and 'k' to shoot");
	gfx_text(xWindow/3, 150, "You have 5 lives. Each time you get hit, ");
	gfx_text(xWindow/3, 175, "you lose a life and your ship speeds up. Good luck!");
	gfx_text(10, 20, "Player 1 lives: 5");
	gfx_text(10, 40, "Player 2 lives: 5");
	gfx_line(0, 50, xWindow, 50);
	while(c!=32){
		c = gfx_wait();
		if(c=='q') return 1;
	}
	gfx_clear();
	ship1.drawShip(xWindow, yWindow);
	ship2.drawShip(xWindow, yWindow);

	// enter animation loop (begin playing game)
	while(true){
		if(gfx_event_waiting()==1){
			c = gfx_wait();
			if(c=='q') break;
			else if(c=='a') ship1.changeTheta(-.2);
			else if(c=='d')	ship1.changeTheta(.2);
			else if(c=='j') ship2.changeTheta(-.2);
			else if(c=='l') ship2.changeTheta(.2);
			else if(c=='s'){
				ship1.fireGun();
				ship2.resetHit();
			}
			else if(c=='k'){
				ship2.fireGun();
				ship1.resetHit();
			}
		}

		gfx_clear();
		gfx_line(0, 50, xWindow, 50);


		// display ship lives (update in "real time")
		gfx_text(10, 20, "Player 1 lives: ");
		gfx_text(105, 20, (to_string((int)ship1.getLives()).c_str()));
		gfx_text(10, 40, "Player 2 lives: ");
		gfx_text(105, 40, (to_string((int)ship2.getLives()).c_str()));

		// if either play has 0 lives, game is over!
		if(ship1.getLives()==0){
			gfx_text(xWindow/2, yWindow-50, "Game is over! Player 2 WINS!");
			break;
		}
		if(ship2.getLives()==0){
			gfx_text(xWindow/2, yWindow-50, "Game is over! Player 1 WINS!");
			break;
		}

		ship1.drawShip(xWindow, yWindow);
		ship2.drawShip(xWindow, yWindow);
		if(ship1.getIsFired()) ship1.moveCircle();
		if(ship2.getIsFired()) ship2.moveCircle();
		// if ship1 hits ship2, subtract one life from ship 2 lives
		if(ship2.getCenterX() + 15 > ship1.getCX() && ship2.getCenterX() - 15 < ship1.getCX()){
			if(ship2.getCenterY()-15<ship1.getCY() && ship2.getCenterY()+15>ship1.getCY()){
				ship2.decreaseLife();
				cout << '\a' << endl;
			}
		}
		// if ship2 hits ship 1, subtract one life from ship 1 lives
		if(ship1.getCenterX()+15>ship2.getCX()&&ship1.getCenterX()-15<ship2.getCX()){
			if(ship1.getCenterY()-15<ship2.getCY() && ship1.getCenterY()+15>ship2.getCY()){
				ship1.decreaseLife();
				cout << '\a' << endl;
			}
		}

		// pause to show animation (15 msec)
		usleep(15000);
	} // end of while loop
	
	// "end of game" screen while loop
	while(c!='q'){
		gfx_text(xWindow/2, yWindow-25, "Press 'q' to quit");
		c = gfx_wait();
	}
	return 0;
}

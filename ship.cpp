// ship.cpp
// implementation of Ship class
// used in Final Project
// CSE-20311 fall 2017
// Seth Cattanach

#include <iostream>
#include "gfx.h"
#include <unistd.h>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;

#include "ship.h"

// default constructor (create and place in middle of board
Ship::Ship(){
	xPos = 600;
	yPos = 400;
	theta = 0;
	circleX = xPos;
	circleY = yPos;
	ct = theta;
	isFired = false;
	isHit = false;
	lives = 5;
	drawShip(200+xPos, 400);
}

// constructor with parameters (x and y position of the ship object)
Ship::Ship(float x, float y){
	xPos = x;
	yPos = y;
	theta = 0;
	circleX = xPos;
	circleY = yPos;
	ct = theta;
	isFired = false;
	isHit = false;
	lives = 5;
	drawShip(200+xPos, 400);
}

// destructor
Ship::~Ship(){
}

// set method for theta
void Ship::changeTheta(float dt){
	theta += dt;
}

float Ship::getX() {return xPos;}
float Ship::getY() {return yPos;}
int Ship::getCX() {return circleX;}
int Ship::getCY() {return circleY;}
float Ship::getLives() {return lives;}
int Ship::getCenterX() {return centerX;}
int Ship::getCenterY() {return centerY;}

void Ship::advanceShip(){
	if(lives==0) return;
	xPos += (5/lives)*cos(theta);
	yPos += (5/lives)*sin(theta);
}

void Ship::fireGun(){
	circleX = xPos;
	circleY = yPos;
	ct = theta;
	circleX++;
	circleY++;
	isFired = true;
}

void Ship::decreaseLife(){
	if(!isHit) lives--;
	isHit = true;
}

bool Ship::getIsFired() {return isFired;}

void Ship::resetHit() {isHit = false;}

void Ship::moveCircle(){
	circleX += 10*cos(ct);
	circleY += 10*sin(ct);
	gfx_circle(circleX, circleY, 2);
}

void Ship::drawShip(int xMax, int yMax){
	advanceShip();
	// prevent ship from going off the screen
	if(xPos<30) xPos = 30;
	if(yPos<80) yPos = 80;
	if(xPos>xMax-30) xPos = xMax - 30;
	if(yPos>yMax-30) yPos = yMax - 30;
	float tipX = xPos + 60*cos(theta);
	float tipY = yPos + 60*sin(theta);
	float midX = xPos + 20*cos(theta);
	float midY = yPos + 20*sin(theta);
	float upX = xPos + 8*cos(theta+1.57);
	float upY = yPos + 8*sin(theta+1.57);
	float downX = xPos - 8*cos(theta+1.57);
	float downY = yPos - 8*sin(theta+1.57);
	// set "centerX and centerY" positions to be the targets for the guns
	centerX = midX;
	centerY = midY;

	// draw lines & enclosing circle
	gfx_line(tipX, tipY, upX, upY);
	gfx_line(tipX, tipY, downX, downY);
	gfx_line(midX, midY, upX, upY);
	gfx_line(midX, midY, downX, downY);
	int centerX = .5*(xPos+tipX);
	int centerY = .5*(yPos+tipY);
	gfx_circle(midX, midY, 10);
}




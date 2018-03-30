// ship.h
// Header file for Ship class
// CSE-20311 Fall 2017 Final Project
// Seth Cattanach

class Ship{
	public:
		Ship();
		Ship(float, float);
		~Ship();
		void changeTheta(float);
		float getX();
		float getY();
		int getCX();
		int getCY();
		int getCenterX();
		int getCenterY();
		float getLives();
		bool getIsFired();
		void resetHit();
		void decreaseLife();
		void fireGun();
		void moveCircle();
		void advanceShip();
		void drawShip(int, int);
	private:
		float xPos, yPos;
		float theta, ct; // theta is for the ship, ct is for the circle ("bullet")
		int circleX, circleY;
		bool isFired, isHit;
		float lives;
		int centerX, centerY;
};

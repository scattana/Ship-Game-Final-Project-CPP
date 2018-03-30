Seth Cattanach
CSE-20311 Fall 2017
Final Project
Readme file
------------------------------

*I worked on this project by myself*

--------------------------------------------
*** Opening and Running the Source Code***
--------------------------------------------

This project uses a custom GFX (graphics) library. The object files for 
this library are included in order to compile the project, but the 
library itself is not. This project requires a version of X11 display 
server. On Windows, Xming can be downloaded for free on XP or later OS.

To run this project, make sure that X11 forwarding is ENABLED in your 
terminal or SSH client. In PuTTY, for example, before opening a new 
session, go to "Connection --> SSH --> X11" and check the box that says 
"Enable X11 forwarding". If this option does not appear, your X11 server 
was likely not installed correcty, or your SSH client doesn't support 
X11 forwarding.

** On Windows: using PuTTY, enable X11 forwarding by going to 
"Connection --> SSH --> X11" and selecting "Enable X11 Forwarding". In 
the box "X display location" enter "localhost:0"

(make sure Xming is correctly installed first. If it has not been 
installed, go to "sourceforge.net" and install Xming for your OS)

** On Linux: locate and modify your SSH configuration file, typically 
located at "/etc/ssh/sshd_config". Make sure your file contains the 
lines "X11Forwarding yes" and "X11UseForwarding yes" (if these lines are 
not present, add them. If they are commented out, uncomment them). 
Lastly, restart your SSH client by running "service ssdh restart" in the 
command line.

** On Mac: download "Quartz" or a similar X11 server client. After 
installation, open your terminal and type "ssh -X [user]@[host]" where 
"user" is your username on the specified host machine ("host").


------------------------------
*** Rules and Instructions ***
------------------------------

This project is a two-player ship game, in which each player controls a ship and 
tries to eliminate his or her opponent by firing its gun at the opponent's ship. Each 
ship initially has 5 lives. The target on each ship is noted by a WHITE CIRCLE in the middle of 
the ship; if the enemy ship hits this target on the opponent's ship, the opponent loses one life.

Player 1 controls his/her ship by using 'a' and 'd' to steer, and 's' to fire.
Player 2 controls his/her ship by using 'j' and 'l' to steer, and 'k' to fire.

Both ships will always move forward on their own, and their speed is inversely proportional to 
the number of lives remaining (i.e. each time a player's ship is hit, it speeds up).

Each player can only fire one shell at a time (to prevent players from shooting constantly). The 
shells are represented by small white circles. When the FIRE key is hit (either 's' or 'k'), a 
shell will fire from the ship's current position and continue in the direction of the ship's 
movement at the time it was fired until the FIRE key is hit again.

When a player reaches 0 lives, he or she loses and the game is over.

At any point, either player can select 'q' to quit the game. 

To begin the game, run the executable ("project") and press SPACE when both players are ready.


------------------------------
*** Program Implementation ***
------------------------------

The program uses a "Ship" class to handle most of the internal calculations; including ship 
positions, bullet positions, direction of travel for both the bullets and the ships, etc.

The Ship class has public methods that change the ship's movement (speed and direction) based on 
inputs from the main driver and "get" methods that are used in the main driver to determine, for 
example, if a ship has been hit or if a ship is on the screen.

As described above, the algorithm for determining a ship's position calculates both speed and 
angle of movement. During gameplay, if a player hits one of the steering keys (a/d or j/l), the 
"theta" value for that ship object will be incremented in either direction. The ship's future 
position is then calculated using polar coordinates, and a "drawShip" method is used to redraw 
the ship at its future position. The ship's movement speed also changes based on the number of 
lives remaining; if a ship is hit, the "speed coefficient" will increase (since this coefficient 
is divided by the number of lives remaining) and the ship's future position will be slightly 
greater in each future iteration.

The main driver has several loops to control gameflow: upon running the program, the players 
enter the "pregame" phase, which simply displays instructions, initializes two Ship objects, and 
waits for the SPACEBAR to be pressed. The players then enter the second phase, active gameplay, 
which continues until one player has 0 lives. During this phase, the gfx_event_waiting method is
used to check if an input has been given; if so, it executes the proper command (such as turning 
the ship). When one player runs out of lives, the program enters the "postgame" phase, which 
displays the winner and erases the ship objects from the screen. At that point, either user can 
exit by pressing 'q' (the 'q' option can be used during any phase of the program and in each 
case, simply exits the program).


Thanks for a great semester! Have fun testing the game.

Seth Cattanach, Dec. 2017






Author:白茗云

Date: May, 2, 2021



Description
------------
project 2: Gomoku



Platform information
---------------------
Microsoft Visual C++ Community 2019, OS: Win10, 86-bit



Compilation Guide
------------------
1. File name "Makefile" is for compilation.
2. Set working directory to "game" and enter "make" to create an execution file named "game".
3. Open another terminal and enter "startxwin".
4. Execute /bin/pulseaudio.exe in Cygwin download folder by administrator. //You don't have to do this if you don't use QSound
5. Go back to original terminal and enter "export DISPLAY=:0.0".
6. Enter "./game x" in original terminal, x = 1, 2, 3 for different levels. //Your execution options may not be as same as this, replace it by yours (e.g. ./game)

Library Link Guide
------------------------
1. Open file path : F44076160\game\dataset\SDL2-2.0.14\VisualC.html , and this is a read me file for how to link the library to the compiler.


Basic requirements
------------------
1. Show Chess and Board on the screen ------------------ done
2. Compete with computer ----------------------------------- done
3. The size of board is 15 x 15 ------------------------------ done
4. Black Chess played first ---------------------------------- done
5. Play one chess per turn ----------------------------------- done
6. Win if 5 chess connected ---------------------------------- done
7. If more than 5 chess connected, contunue the game-- done
8. If no chess can win until the board is out of space, 
the game ended in a tie --------------------------------------- done
9. Use keyboard arrow key to play the chess -------------- done


Bonus
------
none
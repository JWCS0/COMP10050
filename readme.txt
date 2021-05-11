1
Initialise Board
    8 * 8 array                                     X
    fill each element with empty struct             X
    place pieces in centre 4 elements               X

2
Print Board
    Loop through board and print
        E: empty                                    X
        B: black                                    X
        W: white                                    X

----------How you decided to implement the board, the players, the disks. . .
I decided to implement the board as a 10 by 10 array, with each element containing a structure that defines whether that grid position is black, white, empty or the end of board. The 8 by 8 area in the centre is the "true play area". 'Black' and 'white' represent the two player's pieces while 'blank' represents an uncaptured space.'End of board' is the border of the board which is a core part of the capturing function.
The players are represented as structs, in which each have the score, name of player and piece colour.

----------How you decided to implement the game logic
After each turn, there is a variable which contains the current player that flips to the other player.

When checking if a move is valid the following algorithm is used:
    Check linearly in each of the 8 ordinal directions for opposite piece
        if opposite color found, keep going in that direction
            if same color found in that "line"      = invalid capturing line
            if end of board reached                 = invalid capturing line
            if blank space at end                   = valid capturing line
            ^ If there is at least one valid capturing line, the move/position is valid

To check if there are moves available for the player in a turn the above algorithm is used on each 'blank' square at the beginning of the player's turn. 

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

3
Make a move
    Check linearly in each of the 8 ordinal directions for opposite piece
        if opposite color found, keep going in direction
            if same color found in that "line" = invalid capturing line
            if end of board reached = invalid capturing line
            if blank space at end = valid capturing line
            ^ If there is at least one valid capturing line, the move/position is valid

4
Find valid moves
    Loop through each empty square and check if it neighbours a square with the opposite piece


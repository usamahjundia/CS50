/**
 * fifteen.c
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

//DEFINES A CONSTANT CALLED EMPTY TO PUT THE EMPTY SPACE IN AS A PLACEHOLDER, CONSTANT IS CHOSEN
// AS SINCE THE MAX ELEMENT OF THE BOARD DUE TO LIMITATIONS IS 81
// (I COULDVE USED -1 BUT I WAS SLEEPY WHEN IM ON THE PLANNING PHASE SO YEAH)
const int EMPTY = 0;
// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE *file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }
    
    

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = get_int();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    /**
    * The usual stuffs, fillin the matrix (or 2d array, whatever people call it)
    * in reverse by substracting a certain constant
    * defined as max Element with a certain combination of the
    * i and j index value of the array which is more or less the 
    * order of the array from top left to bottom right
    */
    int maxElement = d*d;
    int i,j;
    for(i=0;i<d;i++){
        for(j=0;j<d;j++){
            board[i][j] = maxElement - (j + i * d + 1);
        }
    }
    //after fillin, handles the case where the dimension is even,
    // no need for any fancy swap function here
    if(d%2==0){
        board[d-1][d-3]=1;
        board[d-1][d-2]=2;
    }
    //Fills the last bottom right corner with the empty spot
    board[d-1][d-1] = EMPTY;
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    int i,j;
    for(i=0;i<d;i++){
        for(j=0;j<d;j++){
            if(board[i][j] != EMPTY){
                /**
                 * handles some spacing for aesthetic purposes,
                 * also handles printing the EMPTY Tile,
                 * pretty straightforward and nothing fancy
                 */
                if(board[i][j] <10){
                    printf(" %d ",board[i][j]);
                    }else{
                    printf("%d ",board[i][j]);
                    }
            }else{
                printf("   ");
            }
        }
        printf("\n");
    }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{   
    /**
     * 
     * defines some elements to keep track of the empty array,
     * yadda yadda yadda..
     * initialized with -1 because the coordinates of an element will never be a 
     * negative value :D
     * 
     * the algo is basically taking the coordinate of the EMPTY tile
     * (it was the input tile before, not so much different though)
     * and then checking with certain conditions whether or not
     * it is adjacent to the input tile...
     * 
     */
    int emptyX = -1,emptyY = -1;
    int maxIndex = d-1;
    int i,j;
    //finding nemo starts here
    for(i=0;i<d;i++){
        for(j=0;j<d;j++){
            if(EMPTY == board[i][j]){
                emptyX = i;
                emptyY=j;
                break;
            }
            if(emptyX != -1 && emptyY != -1) break;
        }
    }
    //debugging purpose
    //printf("EMpty coords : %d, %d",emptyX,emptyY);
    
    //we found nemo, the following codes checks if the input tile is nearby or not and handles the rest ~
    if(emptyX > 0 && board[emptyX-1][emptyY] == tile){ 
        board[emptyX-1][emptyY] = EMPTY;
        board[emptyX][emptyY] = tile;
        
        return true;
        
    }
    if(emptyY > 0 && board[emptyX][emptyY-1] == tile) {
        board[emptyX][emptyY-1] = EMPTY;
        board[emptyX][emptyY] = tile;
        
        return true;
        
    }
    if(emptyX < maxIndex && board[emptyX+1][emptyY] == tile) {
        board[emptyX+1][emptyY] = EMPTY;
        board[emptyX][emptyY] = tile;
        
        return true;
        
    }
    if(emptyY < maxIndex && board[emptyX][emptyY+1] == tile) {
        board[emptyX][emptyY+1] = EMPTY;
        board[emptyX][emptyY] = tile;
        
        return true;
        
    }
    //debug purposes
    //printf("this Executes \n");
    
    //this triggers when the tile is nowhere near
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 * 
 * This one gave me a headache, mainly because i forget to read some lines in the specification,
 * and i used 999 as the EMPTY constant instead of 0,
 * 
 * this basically works by checing if the EMPTY is not on the very last  index of the matrix, and then
 * assigning a certain integer value  called currentElem to
 * compare with the "current" value that is being iterated, it is defined as a very
 * negative number to deal with the first element so that the very first element 
 * is guaranteed to be the first actual value of currentElem.
 * 
 * the algo then uses the comparation to decide whether or not the board is sorted completely
 * 
 * 
 * the problem was since EMPTY is now zero, when the board is in order, the last currentElement
 * will always be bigger than zero. the way i deal with this is to check if the current index of i and j
 * is the maxIndex or not. This works because when the loop reaches the last index, IT IS GUARANTEED
 * to be the EMPTY tile, and the board is ALREADY SORTED, which is already handled by the original algorithm
 * when EMPTY was still 999 and not 0
 */
bool won(void)
{   
    int currentElem = -99;
    int i,j,maxIndex = d-1;
    for(i=0;i<d;i++){
        for(j=0;j<d;j++){
            if(i == maxIndex && j== maxIndex) return true;
            if((i != maxIndex)&&(j!= maxIndex)&&(board[i][j] == EMPTY)) return false;
            if(currentElem >= board[i][j]){
               return false; 
            }else{
                currentElem = board[i][j];
               // printf("Curr")
            }
        }
    }
    return true;
}

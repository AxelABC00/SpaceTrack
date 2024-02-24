#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void numberGuessingGame();
void diceGame();

int main() {
    // Seed the random number generator
    srand(time(0));
    int a = 1;
    while (a){
        // Print a welcome message
        printf("*****Welcome to Space Track Platform******\n");
        printf("1. Play the Number Guessing Game\n");
        printf("2. Play the Dice Game\n");
        printf("3. Exit\n");

        // Prompt the user to choose an option
        printf("\nChoose what to do (1,2,3): ");
        int choice;
        scanf("%d", &choice);

        // Handle the user's choice
        switch (choice) {
            case 1:
                numberGuessingGame();
                continue;
            case 2:
                diceGame();
                continue;
            case 3:
                printf("Goodbye!\n");
                a = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }
    }
}

// Define the number guessing game function
    void numberGuessingGame(){
        printf("\n*****Welcome to Number Guessing Game******\n");

        // Generate a random number between 1 and 100
        int number = rand() % 100 + 1;

        // Keep track of the number of guesses and questions
        int guesses = 0;
        int questions = 0;

        // Keep asking for guesses or questions until the number is guessed or
        // the maximum number of guesses is reached
        while (1) {
            printf("Make guess or Ask a question (Input M or A): ");
            char input;
            scanf(" %c", &input);

            if (input == 'M') {
                // Handle a guess here
            } else if (input == 'A') {
                // Handle a question here
            } else {
                printf("\nInvalid input. Please try again.\n");
            }


        if (input == 'M') {
            // Prompt the user for a guess
            printf("Make your best guess for the number between 1-100: ");
            int guess;
            scanf("%d", &guess);

            // Check if the guess is correct
            if (guess == number) {
                printf("Congratulations!! You guessed the number correctly!!!!\n");
                printf("You have made %d guesses, you asked %d questions.\n", guesses, questions);
                printf("**********************************************\n");
                return;
            }

            // Update the number of guesses
            guesses++;

            // Check if the maximum number of guesses has been reached
            if (guesses == 10) {
                printf("Sorry, you have reached the maximum number of guesses.\n");
                printf("The correct number was %d.\n", number);
                printf("**********************************************\n");
                return;
            }

            // Print a message indicating if the guess was higher or lower than the number
            if (guess > number) {
                printf("It is lower than the number.\n");
            } else {
                printf("It is higher than the number.\n");
            }
        } else if (input == 'A') {
            printf("Questions to ask:\n");
            printf("1. Is it even or odd?\n");
            printf("2. Is it >50?\n");
            printf("Choose question: ");
            int question;
            scanf("%d", &question);

            // Handle the question
            if (question == 1) {
                if (number % 2 == 0) {
                    printf("Number is even\n");
                } else {
                    printf("Number is odd\n");
                }
            } else if (question == 2) {
                if (number > 50) {
                    printf("Number is >50\n");
                } else {
                    printf("Number is not >50\n");
                }
            } else {
                printf("Invalid question. Please try again.\n");
            }

            // Update the number of questions
            questions++;

            // Check if the maximum number of questions has been reached
            if (questions == 5) {
                printf("Sorry, you have reached the maximum number of questions.\n");
                printf("You have made %d guesses, you asked %d questions.\n", guesses, questions);
                printf("The correct number was %d.\n", number);
                printf("**********************************************\n");
                return;
            }
            // Print the number of guesses and questions made so far
            printf("You have made %d guesses, you asked %d questions.\n", guesses, questions);
        }
    }
}

void diceGame()
{
    int maxThrows = 3; // maximum number of throws allowed in a game
    int extraThrows = 0; // initialize extraThrows variable
    int player1Score = 0; // initialize player1's score to 0
    int player2Score = 0; // initialize player2's score to 0
    int throwCounter = 0; // initialize throw counter to 0
    printf("Game starts\n"); // print "Game starts" to the console
    throwCounter++; // increment the throw counter

    // seed the random number generator with the current time
    srand((unsigned)time(NULL));
    //game loop
    //game loop
    while (1)
    {
        throwCounter++;

        // break out of the loop if the number of throws exceeds the maximum
        if (throwCounter > maxThrows + extraThrows)
        {
            break;
        }
        int dice1 = rand() % 6 + 1; // roll dice1
        int dice2 = rand() % 6 + 1; // roll dice2
        int diceSum = dice1 + dice2; // calculate the sum of the dice rolls
        int diceDiff = abs(dice1 - dice2); // calculate the absolute difference between the dice rolls

        printf("Throw the dice for player 1: %d %d\n", dice1, dice2);

        //if dice difference is 4, player1 doesn't get any points
        if (diceDiff == 4)
        {
            printf("Player 1 doesn't get any points this time\n");
        }
        else
        {
            player1Score += diceSum / 2; // add half the dice sum to player1's score
        }

        // gets to throw again
        if (diceSum > 8)
        {
            printf("Player 1 gets to throw again\n");
            continue;
        }

        // if player1 rolled 3-3 or 6-6, player1 gets to throw 3 times consecutively
        if (dice1 == dice2 && (dice1 == 3 || dice1 == 6))
        {
            int consecutiveThrows = 3; // player1 gets 3 consecutive throws
            while (consecutiveThrows > 0)
            {
                throwCounter++;
                dice1 = rand() % 6 + 1; // roll dice1
                dice2 = rand() % 6 + 1; // roll dice2
                diceSum = dice1 + dice2; // calculate the sum of the dice rolls
                diceDiff = abs(dice1 - dice2); // calculate the absolute difference between the dice rolls

                printf("Throw the dice for player 1: %d %d\n", dice1, dice2);

                //if dice difference is 4, player1 doesn't get any points
                if (diceDiff == 4)
                {
                    printf("Player 1 doesn't get any points this time\n");
                }
                else if (dice1 != 3 || dice2 != 3) // only count dice values that are not 3-3 as points
                {
                    player1Score += diceSum / 2; // add half the dice sum to player1's score
                }
                consecutiveThrows--; // decrement the number of consecutive throws remaining
            }
        }

        //same for player 2
        dice1 = rand() % 6 + 1; // roll dice1 for player 2
        dice2 = rand() % 6 + 1; // roll dice2 for player 2
        diceSum = dice1 + dice2; // calculate the sum of the dice rolls for player 2
        diceDiff = abs(dice1 - dice2); // calculate the absolute difference between the dice rolls for player 2

        printf("Throw the dice for player 2: %d %d\n", dice1, dice2);

        if (diceDiff == 4)
        {
            printf("Player 2 doesn't get any points this time\n");
        }
        else
        {
            player2Score += diceSum / 2; // add half the dice sum to player2's score
        }

        //if the dice sum is greater than 8, player2 gets to throw again
        if (diceSum > 8)
        {
            printf("Player 2 gets to throw again\n");
            continue;
        }

        // if player2 rolled 3-3 or 6-6, player2 gets to throw 3 times consecutively
        if (dice1 == dice2 && (dice1 == 3 || dice1 == 6))
        {
            int consecutiveThrows = 3; // player2 gets 3 consecutive throws
            while (consecutiveThrows > 0)
            {
                throwCounter++;
                dice1 = rand() % 6 + 1; // roll dice1
                dice2 = rand() % 6 + 1; // roll dice2
                diceSum = dice1 + dice2; // calculate the sum of the dice rolls
                diceDiff = abs(dice1 - dice2); // calculate the absolute difference between the dice rolls

                printf("Throw the dice for player 2: %d %d\n", dice1, dice2);

                //if dice difference is 4, player2 doesn't get any points
                if (diceDiff == 4)
                {
                    printf("Player 2 doesn't get any points this time\n");
                }
                else if (dice1 != 3 || dice2 != 3) // only count dice values that are not 3-3 as points
                {
                    // only count dice values that are not 3-3 as points
                    player2Score += diceSum / 2; // add half the dice sum to player2's score
                }
                consecutiveThrows--; // decrement the number of consecutive throws remaining
            }
        }

        //game ends if player1's dice sum is twice player2's dice sum in consecutive throws
        if (player1Score >= 2 * player2Score && player1Score - player2Score >= 2 * (diceSum / 2))
        {
            printf("Player 1: %d points\n", player1Score);
            printf("Player 2: %d points\n", player2Score);
            printf("Total of %d throws were performed\n", throwCounter);
            printf("Winner is: Player 1\n");
            break;
        }
        else if (player2Score >= 2 * player1Score && player2Score - player1Score >= 2 * (diceSum / 2))
        {
            printf("Player 1: %d points\n", player1Score);
            printf("Player 2: %d points\n", player2Score);
            printf("Total of %d throws were performed\n", throwCounter);
            printf("Winner is: Player 2\n");
            break;
        }




    }}

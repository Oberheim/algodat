#include <stdio.h>
static int minPoints;

int main(void) {
    printf("\nGoal: 109 points\n");
    int current_points = 1, coins = 0;
    minPoints = 100000000;

    insert_coin(5, current_points,0);
    insert_coin(10, current_points,0);

    printf("Final: %d coins\n", minPoints);
}

int insert_coin(int coin, int current_points, int coins) {

    if(current_points == 83) {                             //Final score reached
        if(minPoints > coins) {                             //Check if best score
            minPoints = coins;
        }
        return coins;
    } else if (current_points > 83) {                      //Kills the method
        return 0;
    }

    if(coin == 5) {                                         //Inserts 5 öre
        insert_coin(5,current_points + 4,coins +5);
        insert_coin(10,current_points + 4, coins +5);
    }
    if(coin == 10) {                                        //Inserts 10 öre
        insert_coin(5,current_points * 3, coins + 10);
        insert_coin(10,current_points * 3, coins + 10);
    }
}

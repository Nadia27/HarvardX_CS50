// Cash: calculates the minimum number of coins required to give a user change.
// Nadia Abby
// Problem Set 1
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{

    float money_owed;
    int num_of_coins_used = 0;

    // Ask user how much change is owed
    do
    {
        money_owed = get_float("How much change is owed? ");
    } while (money_owed < 0);

    // Convert dollars to cents
    if (money_owed > 0)
    {
        money_owed = money_owed * 100;
        money_owed = roundf(money_owed);
    }

    for (int i = money_owed; i > 0; i++)
    {
        while (money_owed >= 25)
        {
            money_owed = money_owed - 25;
            num_of_coins_used++;
        }
        while (money_owed >= 10 && money_owed < 25)
        {
            money_owed = money_owed - 10;
            num_of_coins_used++;
        }
        while (money_owed >= 5 && money_owed < 10)
        {
            money_owed = money_owed - 5;
            num_of_coins_used++;
        }
        while (money_owed >= 1 && money_owed < 5)
        {
            money_owed = money_owed - 1;
            num_of_coins_used++;
        }
        break;
    }

    printf("%i"
           "\n",
           num_of_coins_used);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int timeRequiredToBuy(int* tickets, int ticketsSize, int k){
    int i = 0;
    int j = 0;
    int count = 0;
    while(i < ticketsSize){
        if(tickets[i] == 0){
            i++;
            continue;
        }
        if(tickets[i] > 0){
            tickets[i] = tickets[i] - 1;
            count++;
            if(count == k){
                break;
            }
        }
    }
}
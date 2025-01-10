
#include "voyants.h"

int run = 0;

static entrees* io;
int shmid;
void voyants_set_charge(led ledstate)
{
    io = acces_memoire(&shmid);
    voyants_blink_charge();
}

void voyants_set_dispo(led ledstate)
{
    io = acces_memoire(&shmid);
    io->led_dispo = OFF;

}
void voyants_blink_charge()
{ 
    if(!run){
        for(int i  = 0; i < 8 ; i++){

            io -> led_charge = VERT;
            usleep(500000);
            io -> led_charge = OFF;
            usleep(500000);
        }
        run = 1;  
    }
}
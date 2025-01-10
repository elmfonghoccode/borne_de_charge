#include "lecteurcarte.h"
#include "voyants.h"


static entrees* io;
extern int shmid;

void lecteurcarte_initialiser()
{
    // Initialiser la communication avec le lecteur de carte
    initialisations_ports();
}

// lecture et l'interaction avec les cartes
void lecteurcarte_lire_carte()
{
    int numero_carte = 0;

    // Acces memoires partagees
    io = acces_memoire(&shmid);

    // verifier inserer la carte
    attente_insertion_carte();

    if(carte_inseree())
    {
        numero_carte = lecture_numero_carte();
        printf("numero lu : %d\n", numero_carte);

        //authentification du client 
        if(baseclients_authentifier(numero_carte) != 0){
            printf("Client authentifie\n");
            voyants_set_charge(VERT);
        }

        else{
            printf("Client non authentifie\n");
            voyants_set_charge(ROUGE);
        }

        // bouton charge
        if (io->bouton_charge)
        {
            voyants_set_dispo(OFF);

            if (io->led_dispo == OFF && io->led_charge == OFF) {
                generateur_save_charger();
                printf("Charge en cours...\n");
            }
        }
        attente_retrait_carte();
        printf("Carte retiree\n");
    }
    else {
        printf("Aucune carte inseree\n");
    }
    
}
        


 
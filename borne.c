#include <stdio.h>
#include <memoire_borne.h>
#include <donnees_borne.h>

#include "lecteurcarte.h"
#include "generateur_save.h"
#include "voyants.h"
#include "base_clients.h"


int main()
{
    lecteurcarte_initialiser();

    int num = 0;
    
    while(1){
        printf("INTERFACE ADMIN : \n");
        printf("1. Ajouter un client\n");
        printf("2. Charger véhicule\n");
        printf("3. Reprendre véhicule\n");
        printf("4. Voir la liste des clients\n");
        printf("Choisissez une option (1-4) : ");
        scanf("%d", &num);

        switch(num){
            case 1:
                base_clients_ajouter();
                break;
            case 2:
                while (1) {
                    lecteurcarte_lire_carte();
                }
                break;
            case 3:
                reprise_vehicule();  // Arreter la charge et permettre le retrait du vehicule
                break;
            case 4:
                afficher_liste_clients();
                break;
            default:
                printf("Option invalide! Veuillez reessayer.\n");
                break;
        }
    }

}


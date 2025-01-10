
#include "base_clients.h"

int baseclients_authentifier(int numero_carte)
{
    FILE *file = fopen("baseclients.txt", "r");

    if(file == NULL){
        fprintf(stderr, "Erreur\n");
        return 0;
    }
    
    int client = 0;
    while(fscanf(file, "%d", &client) == 1) // Lire jusqu'a la fin du fichier
    {
        if(client == numero_carte){         // numero trouve
            fclose(file);  
            return 1;
        }
    }

    fclose(file);
    return 0;   // numero non trouve
}

void base_clients_ajouter(){

    int numero_carte = 0;

    // Demande d'un numero de carte a l'utilisateur
    printf("Entrer le numero de la carte : ... \n");
    if(scanf("%d", &numero_carte) != 1)
    {
        fprintf(stderr, "Erreur: numero invalide.\n");
        return;
    }

    // Verifier l'ouverture du fichier en mode ajout

    FILE* file = fopen("baseclients.txt", "a");
    if(file == NULL){
        fprintf(stderr, "Erreur\n");
        return 0;
    }
    
    fprintf(file, "%d", numero_carte); // Ajouter le numéro avec un saut de ligne
    printf("Client ajoute succes\n");
    
}

void afficher_liste_clients()
{
    FILE *file = fopen("baseclients.txt", "r");
    int client;

    if(file == NULL){
        printf("Erreur: Impossible d'ouvrir le fichier des clients.\n");
        return;
    }

    printf("Liste des clients enregistres :\n");
    while(fscanf(file, "%d", &client) != EOF) {
        printf("Numero de carte : %d\n", client);
    }

    fclose(file);
}
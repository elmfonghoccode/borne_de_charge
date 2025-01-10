#ifndef BASECLIENTS_H
#define BASECLIENTS_H
#include <lcarte.h>
#include <stdio.h>
#include <memoire_borne.h>
#include <donnees_borne.h>

// authentification d'un client via numero de carte
int baseclients_authentifier(int numero_carte);

// ajout d'un client dans la base
void base_clients_ajouter();

// la liste de clients
void afficher_liste_clients();

#endif // BASECLIENTS_H
#ifndef GENERATEUR_SAVE_H
#define GENERATEUR_SAVE_H
#include <lcarte.h>
#include <memoire_borne.h>
#include <donnees_borne.h>
#include <mem_sh.h>
#include <donnees.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include "voyants.h"

_Bool  generateur_save_charger();
int generateur_save_generer_tension();
void reprise_vehicule();



#endif // GENERATEUR_SAVE
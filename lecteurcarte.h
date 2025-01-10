#ifndef LECTEURCARTE_H
#define LECTEURCARTE_H
#include <lcarte.h>
#include <stdio.h>
#include <memoire_borne.h>
#include <donnees_borne.h>
#include <mem_sh.h>
#include <donnees.h>
#include <unistd.h>
#include "voyants.h"
#include "base_clients.h"
#include "generateur_save.h"

void lecteurcarte_initialiser();
void lecteurcarte_lire_carte();

#endif // LECTEURCARTE_H

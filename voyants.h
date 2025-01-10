#ifndef VOYANTS_H
#define VOYANTS_H
#include <lcarte.h>
#include <stdio.h>
#include <memoire_borne.h>
#include <donnees_borne.h>
#include <mem_sh.h>
#include <donnees.h>
#include <unistd.h>

void voyants_set_charge(led ledstate);
void voyants_set_dispo(led ledstate);
void voyants_blink_charge();

#endif // VOYANTS_H

#include "generateur_save.h"

static entrees* io;
extern int shmid;

_Bool generateur_save_charger()
{
    // Acces a la memoire partagee
    io = acces_memoire(&shmid);

    if(io == NULL){
        fprintf(stderr, "Erreur d'acces a la memoire partagee\n");
        return false;
    }

    // Deverrouiller la trappe et allumer le voyant corresspondant
    io -> led_charge = ROUGE;
    io -> led_trappe = VERT;
    printf("Trappe deverouillé\n");

    // Generer un signal PWM DC pour commencer la charge
    io -> gene_pwm = DC;
    printf("pwm : %d\n", io ->gene_pwm);
    printf("gene u : %d\n", io ->gene_u);
    sleep(2);
    

    if(io -> gene_u == 9)
    {
        io -> led_prise = VERT;
        io -> led_trappe = ROUGE;
    }
    else {
        io -> led_trappe = OFF;
    }

    while (1) {
        // Vérifie si bouton STOP a été activé
        if (io->bouton_stop == 1) {
            printf("Arrêt demandé\n");
            io->bouton_stop = 0; // Réinitialiser le bouton
            io->gene_pwm = STOP; // Arrêter le signal PWM
            io->led_charge = OFF; // Éteindre les voyants
            return true;
        }
    }
}


int generateur_save_generer_tension(){
    // Acces a la memoire partagee
    io = acces_memoire(&shmid);

    // Generer tension
    int tension = 12;
    io -> gene_pwm = DC;
    return ten;

}

void reprise_vehicule() 
{
    // Acces a la memoire partagee
    io = acces_memoire(&shmid);
    
    // Fermer l'etat de charge, mettre les ports en mode veille
    io->led_charge = OFF;          
    io->led_prise = OFF;           
    io->led_trappe = OFF;          

    // Changez PWM sur STOP lorsque la charge est terminee
    io->gene_pwm = STOP;           
    io->gene_u = 0;                

    io->led_trappe = OFF;          

    // verifier appuyer button_stop
    if (io->bouton_stop) 
    {
        io->contacteur_AC = 0;      //deverrouiller la charge
        printf("Systeme arrete le processus de recharge.\n");
    }

    if (io->bouton_stop == 1)
    {
        io->led_dispo = VERT;       
        printf("Processus de reprise terminé.\n");
    }
}
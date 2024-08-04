#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include <time.h>

void print_in_red(const char *text) {
    printf("\033[1;31m%s\033[0m", text);
}

void print_in_green(const char *text) {
    printf("\033[1;32m%s\033[0m", text);
}

int ComparaisonCaratere(const char *caracteres, const char *mdp) {
    for (int i = 0; i < strlen(mdp); i++) {
        if (strchr(caracteres, mdp[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

unsigned long long puissance(int base, int exponentiel){
    unsigned long long resultat = 1;
    for(int i = 0; i < exponentiel; i++){
        resultat *= base ;
    }
    return resultat;
}

void estimer_temps_crackage(const char *mdp){
    char numero[] = "1234567890";
    char lettre_min[] = "azertyuiopqsdfghjklmwxcvbn";
    char lettre_maj[] = "AZERTYUIOPQSDFGHJKLMWXCVBN";
    char caractere_special[] = "!@#$%^&*()";
    int taille_min = 8;

    int taille_mdp = strlen(mdp);
    int taille_ensemble = 0;
    unsigned long long nombre_de_combinaisons;
    double essais_par_seconde = 1e9;
    double temps_secondes;
    int annees, jours, heures, minutes, secondes;

    if (ComparaisonCaratere(lettre_min, mdp)) {
        taille_ensemble += 26;
    }
    if (ComparaisonCaratere(lettre_maj, mdp)) {
        taille_ensemble += 26;
    }
    if (ComparaisonCaratere(numero, mdp)) {
        taille_ensemble += 10;
    }
    if (ComparaisonCaratere(caractere_special, mdp)) {
        taille_ensemble += 10;  // Ajuster selon les caractères spéciaux utilisés
    }

    // Calculer le nombre de combinaisons possibles
    nombre_de_combinaisons = puissance(taille_ensemble, taille_mdp);

    // Calculer le temps de crackage en secondes
    temps_secondes = nombre_de_combinaisons / essais_par_seconde;

    // Convertir le temps en années, jours, heures, minutes et secondes
    annees = (int)(temps_secondes / (365 * 24 * 3600));
    temps_secondes = fmod(temps_secondes, (365 * 24 * 3600));
    jours = (int)(temps_secondes / (24 * 3600));
    temps_secondes = fmod(temps_secondes, (24 * 3600));
    heures = (int)(temps_secondes / 3600);
    temps_secondes = fmod(temps_secondes, 3600);
    minutes = (int)(temps_secondes / 60);
    secondes = (int)fmod(temps_secondes, 60);

    // Afficher les résultats
    printf("Temps estimé pour cracker le mot de passe : %d années, %d jours, %d heures, %d minutes, %d secondes.\n",
           annees, jours, heures, minutes, secondes);
}

void ComparaisonCritères(const char* mdp){
    char numero[] = "1234567890";
    char lettre_min[] = "azertyuiopqsdfghjklmwxcvbn";
    char lettre_maj[] = "AZERTYUIOPQSDFGHJKLMWXCVBN";
    char caractere_special[] = "!@#$%^&*()";
    int taille_min = 8;

    if (ComparaisonCaratere(caractere_special, mdp) == 1) {            
        print_in_green("Le mot de passe contient un caractère spécial.\n");
    } else {
        print_in_red("Le mot de passe ne contient pas de caractère spécial.\n");
    }
    if (ComparaisonCaratere(numero, mdp) == 1) {
        print_in_green("Le mot de passe contient un chiffre.\n");
    } else {
        print_in_red("Le mot de passe ne contient pas de chiffre.\n");
    }
    if (ComparaisonCaratere(lettre_min, mdp) == 1) {
        print_in_green("Le mot de passe contient une lettre minuscule.\n");
    } else {
        print_in_red("Le mot de passe ne contient pas de lettre minuscule.\n");
    }
    if (ComparaisonCaratere(lettre_maj, mdp) == 1) {
        print_in_green("Le mot de passe contient une lettre majuscule.\n");
    } else {
        print_in_red("Le mot de passe ne contient pas de lettre majuscule.\n");
    }
    if (strlen(mdp) >= taille_min) {
        print_in_green("Le mot de passe est suffisamment long.\n");
    } else {
        print_in_red("Le mot de passe n'est pas suffisamment long.\n");
    }
};

void GenerationMotDePasse(const int taille){
    
    char mdp[taille + 1]; // +1 pour le caractère nul de fin de chaîne
    mdp[0] = '\0'; // Initialiser la chaîne de caractères vide

    char numero[] = "1234567890";
    char lettre_min[] = "azertyuiopqsdfghjklmwxcvbn";
    char lettre_maj[] = "AZERTYUIOPQSDFGHJKLMWXCVBN";
    char caractere_special[] = "!@#$%^&*()";

    // Tableau de pointeurs vers les différentes catégories de caractères
    char *tableau_caracteristique_mdp[] = {numero, lettre_min, lettre_maj, caractere_special};
    

    // +1 pour compter le cractère de fin de ligne
    for(int i = 0; i <= taille+1; i++){
        
        int random_index_tableau = rand() % 4;
        int random_index_caractere = rand() % strlen(tableau_caracteristique_mdp[random_index_tableau]);
        char caractere = tableau_caracteristique_mdp[random_index_tableau][random_index_caractere];
       
       char str[2] = {caractere, '\0'}; // Convertir le caractère en chaîne de caractères
       strcat(mdp, str);
    
    }
    printf("%s\n", mdp); 


}

int main() {
    char reponse[256];
    int resultat = 0;
    char mdp[256];

    while (resultat == 0) {
        printf("Sélectionner l'option voulue : \n- Option 1 : Générer un mot de passe \n- Option 2 : Tester les critères d'un mot de passe \n- Option 3 : Tester la durée de crack d'un mot de passe \n Votre Réponse : ");
        fgets(reponse, sizeof(reponse), stdin);
        
        // Enlever le caractère de nouvelle ligne à la fin de la chaîne
        reponse[strcspn(reponse, "\n")] = 0;
    
        if (strcasecmp(reponse, "Option 1") == 0) {
            printf("Génération du mdp :\n");

            srand(time(NULL));

            GenerationMotDePasse(8);


        } else if (strcasecmp(reponse, "Option 2") == 0) {
            printf("Teste des critères : \n");
            
            printf("Quel est le mot de passe : ");
            scanf("%s", mdp);

            ComparaisonCritères(mdp);
            
        }
        else if (strcasecmp(reponse, "Option 3") == 0) {
            printf("Quel est votre mot de passe : ");
            scanf("%s", mdp);
            estimer_temps_crackage(mdp);
        } 
        resultat = 1;
    }

    return 0;
}

    /*


        
        printf("Voulez-vous recommencer : ");
        scanf("%s", &reponse);
        if (strcasecmp(reponse, "oui") == 0) {
            resultat = 0;
        }
        else {
            resultat = 1;
            break;
        }*/
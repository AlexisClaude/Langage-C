# Explication de mon code sur les mots de passe

## Intégration des préprocesseurs :

Les préprocesseurs sont des outils qui permettent de manipuler le code source avant la compilation. Ces directives sont utilisées pour effectuer différentes actions, telles que l'inclusion de fichiers, la définition de constantes, la condition de compilation et la suppression de code.

```c
#include <stdio.h> 
```
Cela permet d'afficher du texte à l'aide de la commande `printf()`.

```c
#include <string.h>
```
Cela permet de manipuler des chaînes de caractères avec des fonctions comme `strlen()`, `strcpy()`, `strcat()`, etc.

```c
#include <stdlib.h>
```
Cela permet d'utiliser des fonctions utilitaires générales comme `malloc()`, `free()`, `atoi()`, etc.

```c
#include <strings.h>
```
Cela permet d'utiliser des fonctions de manipulation de chaînes spécifiques comme `strcasecmp()`.

# Fonction d'affichage en vert ou rouge :

```c
void print_in_red(const char *text) {
    printf("\033[1;31m%s\033[0m", text);
}

void print_in_green(const char *text) {
    printf("\033[1;32m%s\033[0m", text);
}
````
- `void` indique que cette fonction ne retourne aucune valeur.

- `const char *text` est un paramètre de la fonction. 
    - `const` signifie que la chaîne de caractères pointée par text ne sera pas modifiée par la fonction. 
    - `char *` est un pointeur vers une chaîne de caractères. Cela permet de modifier directement la chaîne de caractères d'origine sans la copier.

- `printf("\033[1;31m%s\033[0m", text);` :
    - `printf` est une fonction standard de la bibliothèque stdio.h qui permet d’afficher du texte à l’écran.
    - `\033[1;31m%s\033[0m` est une chaîne de format qui utilise des séquences d’échappement ANSI pour colorer le texte en rouge. 
        
    Voici en détail comment l'utiliser : 
### Structure de base

La structure de base pour colorer du texte en utilisant les séquences d’échappement ANSI est :

```c
\033[<style>;<couleur>m<texte>\033[0m
```

- `\033[` : Commence la séquence d’échappement.
- `<style>` : Définit le style du texte (comme gras).
- `;<couleur>` : Définit la couleur du texte.
- `m` : Marque la fin de la séquence d’échappement pour les paramètres de style et de couleur.
- `<texte>` : Le texte à afficher avec les styles et couleurs spécifiés.
- `\033[0m` : Réinitialise le style et la couleur à leurs valeurs par défaut.

### Paramètres de style :

- `0` : Réinitialiser / Normal.
- `1` : Gras.
- `4` : Souligné.
- `5` : Clignotant.
- `7` : Inverse (inverse les couleurs de fond et de texte).
- `8` : Caché.

### Paramètres de couleur :

#### Couleurs du texte :
- `30` : Noir
- `31` : Rouge
- `32` : Vert
- `33` : Jaune
- `34` : Bleu
- `35` : Magenta
- `36` : Cyan
- `37` : Blanc

#### Couleurs de fond (optionnel, préfixé par `4`) :
- `40` : Fond Noir
- `41` : Fond Rouge
- `42` : Fond Vert
- `43` : Fond Jaune
- `44` : Fond Bleu
- `45` : Fond Magenta
- `46` : Fond Cyan
- `47` : Fond Blanc

### Exemple :

Pour afficher un texte en bleu souligné dans le terminal :

```c
    printf("\033[4;34m%s\033[0m", text);
```

Dans cet exemple :
- `\033[4;34m` commence la séquence d’échappement pour le texte en bleu souligné (`4` pour souligné, `34` pour bleu).
- `%s` est le texte à colorer.
- `\033[0m` réinitialise la couleur et le style du texte à la couleur par défaut.
    - `text` est la chaîne de caractères passée à la fonction et qui sera affichée en rouge.

## Fonction de comparaison de caractères

```c
int ComparaisonCaratere(const char *caracteres, const char *mdp) {
    for (int i = 0; i < strlen(mdp); i++) {
        if (strchr(caracteres, mdp[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}
```

Cette fonction vérifie si une chaîne de caractères `mdp` contient au moins un caractère parmi ceux spécifiés dans `caracteres`.

- `int ComparaisonCaratere(const char *caracteres, const char *mdp)` :
  - `int` indique que cette fonction retourne un entier.
  - `ComparaisonCaratere` est le nom de la fonction.
  - `const char *caracteres` et `const char *mdp` sont des pointeurs vers des chaînes de caractères constantes.

- `for (int i = 0; i < strlen(mdp); i++)` :
  - Cette boucle `for` parcourt chaque caractère de la chaîne `mdp`.
  - `strlen(mdp)` retourne la longueur de la chaîne `mdp`.

- `if (strchr(caracteres, mdp[i]) != NULL)` :
  - `strchr(caracteres, mdp[i])` recherche le caractère `mdp[i]` dans la chaîne `caracteres`.
  - Si le caractère est trouvé, `strchr` retourne un pointeur vers le caractère trouvé, sinon, elle retourne `NULL`.
  - Si le caractère est trouvé, la fonction retourne `1`.

- `return 0` :
  - Si aucun des caractères de `mdp` n'est trouvé dans `caracteres`, la fonction retourne `0`.

# Fonction de calcul de puissance

```c
unsigned long long puissance(int base, int exponentiel) {
    unsigned long long resultat = 1;
    for (int i = 0; i < exponentiel; i++) {
        resultat *= base;
    }
    return resultat;
}
```

Cette fonction calcule la puissance d'un nombre entier `base` élevé à l'exposant `exponentiel`.

- `unsigned long long puissance(int base, int exponentiel)` :
  - `unsigned long long` indique que cette fonction retourne un entier non signé de 64 bits.
  - `puissance` est le nom de la fonction.
  - `int base` et `int exponentiel` sont des paramètres entiers.

- `unsigned long long resultat = 1` :
  - Initialise la variable `resultat` à 1. Cette variable contiendra le résultat de la puissance.

- `for (int i = 0; i < exponentiel; i++)` :
  - Cette boucle `for` s'exécute `exponentiel` fois.

- `resultat *= base` :
  - Multiplie `resultat` par `base` à chaque itération de la boucle.

- `return resultat` :
  - Retourne le résultat de la puissance.

# Fonction d'estimation du temps de crackage

```c
void estimer_temps_crackage(const char *mdp) {
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
        taille_ensemble += 10;
    }

    nombre_de_combinaisons = puissance(taille_ensemble, taille_mdp);

    temps_secondes = nombre_de_combinaisons / essais_par_seconde;

    annees = (int)(temps_secondes / (365 * 24 * 3600));
    temps_secondes = fmod(temps_secondes, (365 * 24 * 3600));
    jours = (int)(temps_secondes / (24 * 3600));
    temps_secondes = fmod(temps_secondes, (24 * 3600));
    heures = (int)(temps_secondes / 3600);
    temps_secondes = fmod(temps_secondes, 3600);
    minutes = (int)(temps_secondes / 60);
    secondes = (int)fmod(temps_secondes, 60);

    printf("Temps estimé pour cracker le mot de passe : %d années, %d jours, %d heures, %d minutes, %d secondes.\n",
           annees, jours, heures, minutes, secondes);
}
```

Cette fonction estime le temps nécessaire pour cracker un mot de passe en fonction des caractères qu'il contient.

- `const char *mdp` : Le mot de passe à analyser.
- `char numero[] = "1234567890"` : Caractères numériques.
- `char lettre_min[] = "azertyuiopqsdfghjklmwxcvbn"` : Lettres minuscules.
- `char lettre_maj[] = "AZERTYUIOPQSDFGHJKLMWXCVBN"` : Lettres majuscules.
- `char caractere_special[] = "!@#$%^&*()"` : Caractères spéciaux.
- `int taille_min = 8` : Longueur minimale du mot de passe.

- `int taille_mdp = strlen(mdp)` : Longueur du mot de passe.
- `int taille_ensemble = 0` : Taille de l'ensemble des caractères utilisés dans le mot de passe.
- `unsigned long long nombre_de_combinaisons` : Nombre de combinaisons possibles.
- `double essais_par_seconde = 1e9` : Nombre d'essais par seconde.
- `double temps_secondes` : Temps estimé en secondes.
- `int annees, jours, heures, minutes, secondes` : Temps estimé en années, jours, heures, minutes et secondes.

- `if (ComparaisonCaratere(lettre_min, mdp))` :
  - Si le mot de passe contient des lettres minuscules, ajoute 26 à `taille_ensemble`.

- `if (ComparaisonCaratere(lettre_maj, mdp))` :
  - Si le mot de passe contient des lettres majuscules, ajoute 26 à `taille_ensemble`.

- `if (ComparaisonCaratere(numero, mdp))` :
  - Si le mot de passe contient des chiffres, ajoute 10 à `taille_ensemble`.

- `if (ComparaisonCaratere(caractere_special, mdp))` :
  - Si le mot de passe contient des caractères spéciaux, ajoute 10 à `taille_ensemble`.

- `nombre_de_combinaisons = puissance(taille_ensemble, taille
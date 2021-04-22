#ifndef CONSTANTE_H
#define CONSTANTE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T_AUTEUR 50
#define T_TITRE 100
#define FILIVRES "livres.data"

typedef enum menu Menu;
enum menu {
	CHARGER_FICHIER = 1,
	AJOUTER_LIVRES,
	SUPPRIMER_LIVRE,
	AFFICHER_LIVRES,
	SAUVEGARDER_LIVRES,
	QUITTER
};

typedef enum message Message;
enum message {
	AJOUT_EFFECTUE,
	ERREUR_MEMOIRE,
	LIVRE_EXISTANT,
	LIVRE_INEXISTANT,
	SUPPRESSION_EFFECTUEE,
	ERREUR_FICHIER,
	SAUVEGARDE_LIVRES,
	CHARGEMENT_FICHIER
};
#endif // !CONSTANTE.H



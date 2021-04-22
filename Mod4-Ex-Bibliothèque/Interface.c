#include "Constante.h"
#include "Biblio.h"

void fonctionnalites(void) {
	ChainonLivre* pD�butLivres = NULL;
	Livre livre;
	Message message;
	Menu choixLu;

	choixLu = choixMenu();
	while (choixLu != QUITTER) {
		switch (choixLu) {
		case CHARGER_FICHIER:
			message = chargerFichier(&pD�butLivres);
			afficherMessage(message);
			break;
		case AJOUTER_LIVRES:
			livre = livreLu();
			while (strcmp(livre.auteur, "") != 0) {
				message = ajouterLivre(livre, &pD�butLivres);
				afficherMessage(message);
				livre = livreLu();
			}
			break;
		case SUPPRIMER_LIVRE:
			livre = livreLu();
			message = supprimerLivre(livre, &pD�butLivres);
			afficherMessage(message);
			break;
		case AFFICHER_LIVRES:
			afficherLivres(pD�butLivres);
			break;
		case SAUVEGARDER_LIVRES:
			message = sauvegarderLivres(pD�butLivres);
			afficherMessage(message);
			libererListe(&pD�butLivres);
			break;
		}
		choixLu = choixMenu();
	}
}

Menu choixMenu(void) {
	Menu choix;
	printf("1. Charger le fichier des livres dans la LC\n");
	printf("2. Ajouter des livres\n");
	printf("3. Supprimer un livre\n");
	printf("4. Afficher les livres de la LC\n");
	printf("5. Sauvegarder les livres dans le fichier\n");
	printf("6. Quitter\n");
	do {
		printf("Votre choix : ");
		scanf_s("%d", &choix);
	} while (choix < CHARGER_FICHIER || choix > QUITTER);
	getchar();
	return choix;
}

void afficherLivres(ChainonLivre* pDebutLivres) {
	ChainonLivre* pLivre;
	pLivre = pDebutLivres;
	if (pLivre == NULL)
		puts("Aucun livre\n");
	while (pLivre != NULL) {
		char auteur[T_AUTEUR];
		strcpy_s(auteur, T_AUTEUR, pLivre->livre.auteur);
		printf("Auteur : %s\n", auteur);
		while (pLivre != NULL && strcmp(auteur, pLivre->livre.auteur) == 0) {
			printf("\t%10d\t%s\n", pLivre->livre.code, pLivre->livre.titre);
			pLivre = pLivre->pLivreSuiv;
		}
	}
}

Livre livreLu(void) {
	Livre livre;
	printf("Auteur : ");
	gets_s(livre.auteur, T_AUTEUR);
	if (strcmp(livre.auteur, "") != 0) {
		printf("Code ISBN : ");
		scanf_s("%d", &livre.code);
		getchar();
		printf("Titre : ");
		gets_s(livre.titre, T_TITRE);
	}
	return livre;
}

void afficherMessage(Message message) {
	switch (message) {
	case AJOUT_EFFECTUE: puts("Le livre est ajoute !");
		break;
	case ERREUR_MEMOIRE: puts("Plus de place memoire !");
		break;
	case LIVRE_EXISTANT: puts("Le livre existe deja !");
		break;
	case LIVRE_INEXISTANT: puts("Le livre n'existe pas !");
		break;
	case SUPPRESSION_EFFECTUEE: puts("Le livre est supprime !");
		break;
	case ERREUR_FICHIER: puts("Probleme d'ouverture fichier !");
		break;
	case SAUVEGARDE_LIVRES: puts("Les livres sont sauvegardes dans le fichier !");
		break;
	case CHARGEMENT_FICHIER: puts("Les livres sont charges dans la liste !");
		break;
	}
}
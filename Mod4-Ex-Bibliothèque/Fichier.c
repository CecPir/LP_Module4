#include "Constante.h"
#include "Biblio.h"

Message sauvegarderLivres(ChainonLivre* pDebutLivres) {
	ChainonLivre* pLivre;
	FILE* pFiLivres;
	fopen_s(&pFiLivres, FILIVRES, "wb");
	if (pFiLivres == NULL)
		return ERREUR_FICHIER;
	pLivre = pDebutLivres;
	while (pLivre != NULL) {
		fwrite(&(pLivre->livre), sizeof(Livre), 1, pFiLivres);
		pLivre = pLivre->pLivreSuiv;
	}
	fclose(pFiLivres);
	return SAUVEGARDE_LIVRES;
}

Message chargerFichier(ChainonLivre** pDebutLivres) {

	Message message = 0;
	Livre livreLu;
	FILE* pFiLivres;
	fopen_s(&pFiLivres, FILIVRES, "rb");
	if (pFiLivres == NULL)
		return ERREUR_FICHIER;
	fread_s(&livreLu, sizeof(livreLu), sizeof(livreLu), 1, pFiLivres);
	while (!feof(pFiLivres) && message != ERREUR_MEMOIRE) {
		message = ajouterLivre(livreLu, pDebutLivres);
		fread_s(&livreLu, sizeof(livreLu), sizeof(livreLu), 1, pFiLivres);
	}
	fclose(pFiLivres);
	return message == ERREUR_MEMOIRE ? message : CHARGEMENT_FICHIER;
}
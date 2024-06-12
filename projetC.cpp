#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NB_MATIERES 4

struct date_t {
	int jr;
	int mois;
	int an;
};

struct Personne {
	char nom[10];
	int age;
	float notes[NB_MATIERES];
	struct date_t date;
	int annee;
	int semestre;
	char numu[10];
	char sexe;
	float moyenne;
};

char matieres1_sem1[NB_MATIERES][20] = {"maths", "algo", "anglais", "architecture"};
char matieres1_sem2[NB_MATIERES][20] = {"c++", "maths", "algo", "electronique num"};
char matieres2_sem1[NB_MATIERES][20] = {"C#", "Algo", "francais", "statistiques"};
char matieres2_sem2[NB_MATIERES][20] = {"economie", "droit", "marketing", "gestion"};
char matieres3_sem1[NB_MATIERES][20] = {"Java", "informatique", "francais", "statistiques"};
char matieres3_sem2[NB_MATIERES][20] = {"Python", "droit", "culture", "bureautique"};
char matieres4_sem1[NB_MATIERES][20] = {"c++", "html", "francais", "statistiques"};
char matieres4_sem2[NB_MATIERES][20] = {"ALgo", "Java script", "marketing", "gestion"};
char matieres5_sem1[NB_MATIERES][20] = {"c++", "html", "francais", "statistiques"};
char matieres5_sem2[NB_MATIERES][20] = {"java", "Algo", "Maths", "gestion"};

void menu_principal()
{
	printf("Menu Principal : \n 1-gerer les etudiants \n 2-gerer les notes \n "
	       "3-Gerer les fichiers \n 4-Quitter \n Votre Choix : ");
}

void menu()
{
	printf("1-Premiere annee\n2-Deuxieme annee\n3-troisiemme annee\n4-quatriemme "
	       "annee\n5-cinqiemme annee\n6-quitter \n Votre choix :");
}

void sous_menu_annee()
{
	printf("Sous-menu annee\n 1- Premier semestre \n 2- Deuxieme semestre\n 3- "
	       "Quitter \n Votre choix :");
}

void menu_gerer_etudiants()
{
	printf("MENU gerer les etudiants \n 1-Ajouter \n 2-Supprimer \n 3-Lister \n "
	       "4-modifier \n 5-quitter\n Votre Choix : ");
}

void menu_gerer_notes()
{
	printf("MENU gerer les notes \n 1-Premiere annee \n 2-Deuxieme annee \n "
	       "3-troisiemme annee \n 4-quatriemme annee\n -5cinqiemme annee\n6- "
	       "quitter \n Votre Choix : ");
}

int rechercher(struct Personne *t, char k[10], int taille)
{
	for (int i = 0; i < taille; i++) {
		if (strcmp(t[i].numu, k) == 0) {
			return i;
		}
	}
	return -1;
}

int numu_existe(char numu[], const struct Personne *t, int taille)
{
	for (int i = 0; i < taille; i++) {
		if (strcmp(t[i].numu, numu) == 0) {
			return 1;
		}
	}
	return 0;
}

int calculer_moyenne(struct Personne *t, int index)
{
	float somme = 0;

	for (int i = 0; i < NB_MATIERES; i++) {
		somme += t[index].notes[i];
	}
	return t[index].moyenne = somme / NB_MATIERES;
}

void ajouter(struct Personne *&t, int &taille, int annee, int semestre)
{
	if (taille == 0) {
		t = (Personne *)malloc(sizeof(Personne));
		printf("Veuillez saisir un nom : ");
		scanf("%s", t[taille].nom);
		printf("Veuillez saisir un age : ");
		scanf("%d", &t[taille].age);

		do {

			printf("donner le jour de naissance : ");
			scanf("%d", &t[taille].date.jr);
		} while (t[taille].date.jr < 0 || t[taille].date.jr > 31);

		do {

			printf("donner le mois de naissance : ");
			scanf("%d", &t[taille].date.mois);
		} while (t[taille].date.mois < 0 || t[taille].date.mois > 12);

		do {

			printf("donner l'année de naissance : ");
			scanf("%d", &t[taille].date.an);
		} while (t[taille].date.an > 2024);

		do {

			printf("donner le sexe de l'etudiant : ");
			scanf(" %c", &t[taille].sexe);
		} while ((t[taille].sexe != 'H') && (t[taille].sexe != 'F'));

		do {
			printf("donnez le numu du eleve :");
			scanf("%s", t[taille].numu);

			if (numu_existe(t[taille].numu, t, taille)) {
				printf("Ce numu existe déjà. Veuillez entrer un numu unique.\n");
			}
		} while (numu_existe(t[taille].numu, t, taille));

		/* Initialisation des notes à 0 */
		for (int i = 0; i < NB_MATIERES; i++) {
			t[taille].notes[i] = 0;
		}
		calculer_moyenne(t, taille - 1);
		t[taille].annee = annee;
		t[taille].semestre = semestre;
		taille++;

	} else {
		realloc(t, sizeof(Personne) * (taille + 1));
		printf("Veuillez saisir un nom : ");
		scanf("%s", t[taille].nom);
		printf("Veuillez saisir un age : ");
		scanf("%d", &t[taille].age);

		do {
			printf("donner le jour de naissance : ");
			scanf("%d", &t[taille].date.jr);
		} while (t[taille].date.jr < 0 || t[taille].date.jr > 31);

		do {
			printf("donner le mois de naissance : ");
			scanf("%d", &t[taille].date.mois);
		} while (t[taille].date.mois < 0 || t[taille].date.mois > 12);

		do {
			printf("donner l'année de naissance : ");
			scanf("%d", &t[taille].date.an);
		} while (t[taille].date.an > 2024);

		do {
			printf("donner le sexe de l'etudiant : ");
			scanf(" %c", &t[taille].sexe);
		} while ((t[taille].sexe != 'H') && (t[taille].sexe != 'F'));

		do {
			printf("donnez le numu du eleve : ");
			scanf("%s", t[taille].numu);

			if (numu_existe(t[taille].numu, t, taille)) {
				printf("Ce numu existe déjà. Veuillez entrer un numu unique.\n");
			}
		} while (numu_existe(t[taille].numu, t, taille));

		/* Initialisation des notes à 0 */
		for (int i = 0; i < NB_MATIERES; i++) {
			t[taille].notes[i] = 0;
		}
		calculer_moyenne(t, taille - 1);
		t[taille].annee = annee;
		t[taille].semestre = semestre;
		taille++;
	}
}

void lister(struct Personne *t, int taille, int annee, int semestre, char matieres[NB_MATIERES][20])
{
	for (int i = 0; i < taille; i++) {
		/* Filtrer les étudiants par année et semestre */
		if (t[i].annee == annee &&
		    t[i].semestre == semestre) { 
			printf("Nom: %s | Age: %d | Date de naissance : %d/%d/%d | numu : %s  | "
			       "SEXE : %c\n",
			       t[i].nom, t[i].age, t[i].date.jr, t[i].date.mois, t[i].date.an,
			       t[i].numu, t[i].sexe);
			for (int j = 0; j < NB_MATIERES; j++) {
				printf("Note de %s est : %.2f\n", matieres[j], t[i].notes[j]);
			}

			/* Calculer la moyenne avant de l'afficher */
			calculer_moyenne(t, i);
			printf("Moyenne : %.2f\n\n", t[i].moyenne);
		}
	}
}

void supprimer(Personne *&t, int &taille)
{
	char k[10];
	int pos;

	if (taille == 0) {
		printf("le Tableau est Vide");
	} else if (taille == 1) {
		printf("Veuillez saisir le num de l'etudiant a supprimer : ");
		scanf("%s", k);
		if (strcmp(k, t[0].numu) == 0) {
			free(t);
			taille = 0;
		}
	} else {
		printf("Veuillez saisir le le numu de l'etudiant  a supprimer : ");
		scanf("%s", k);

		pos = rechercher(t, k, taille);
		if (pos != -1) {
			for (int i = pos; i < taille - 1; i++) {
				t[i] = t[i + 1];
			}
			taille--;
			realloc(t, sizeof(Personne) * taille);
			printf("l'eleve a ete supprimé avec succes !");
		}
	}
}

void modifier(Personne *t, int taille)                     //Vous n'avez pas besoin d'utiliser *&t car t lui-même est déjà un pointeur, et *t vous permet d'accéder à la valeur pointée par ce pointeur.
{
	char k[10];
	int pos;

	if (taille == 0) {
		printf("le Tableau est Vide");
	}

	else {
		printf("Veuillez saisir le le numu de l'etudiant  a modifier : ");
		scanf("%s", k);

		pos = rechercher(t, k, taille);
		if (pos != -1) {
			printf("Veuillez saisir le nouveau nom : ");
			scanf("%s", t[pos].nom);
			printf("Veuillez saisir le nouveau age : ");
			scanf("%d", &t[pos].age);
			printf("donner le bouveau jour de naissance : ");
			scanf("%d", &t[pos].date.jr);

			printf("donner le nouveau mois de naissance : ");
			scanf("%d", &t[pos].date.mois);

			printf("donner la nouvelle année de naissance : ");
			scanf("%d", &t[pos].date.an);
			do {
				printf("donner le nouveau sexe de l'etudiant : ");
				scanf(" %c", &t[pos].sexe);
			} while ((t[pos].sexe != 'H') && (t[pos].sexe != 'F'));
		}
	}
}

void modifier_notes(struct Personne *t, int taille, char matieres[NB_MATIERES][20], int annee,
		    int semestre)
{
	char k[10];
	int index;

	printf("Entrez le numu de l'etudiant pour lequel vous souhaitez gerer les notes : ");
	scanf("%s", k);

	index = rechercher(t, k, taille);

	if (index == -1) {
		printf("Etudiant non trouve.\n");
		return;
	}

	/* Vérifier si l'étudiant est dans la bonne année et semestre */
	if (t[index].annee != annee || t[index].semestre != semestre) {
		printf("Cet etudiant n'est pas dans ce semestre.\n");
		return;
	}

	printf("Entrez les notes pour l'etudiant (e) %s :\n", t[index].nom);
	for (int i = 0; i < NB_MATIERES; i++) {
		printf("Entrez la note pour %s : ", matieres[i]);
		scanf("%f", &t[index].notes[i]);
	}

	printf("Les notes pour l'etudiant %s ont ete mises a jour.\n", t[index].nom);
	calculer_moyenne(t, index);
}

void gerer_etudiants_annee(struct Personne *&t, int &taille, int annee, int semestre,
			   char matieres[NB_MATIERES][20])
{
	int choix;

	do {
		menu_gerer_etudiants();
		scanf("%d", &choix);
		switch (choix) {
		case 1:
			ajouter(t, taille, annee, semestre);
			break;
		case 2:
			supprimer(t, taille);
			break;
		case 3:
			lister(t, taille, annee, semestre, matieres);
			break;
		case 4:
			modifier(t, taille);
			break;
		case 5:
			printf("Au revoir !");
			break;
		default:
			printf("Choix invalide. Veuillez choisir a nouveau.\n");
			break;
		}
		getch();
		system("cls");
	} while (choix != 5);
}

void gerer_notes_annee(struct Personne *t, int taille, char matieres[NB_MATIERES][20], int annee,
		       int semestre)
{
	switch (semestre) {
	case 1:
		printf("Gérer les notes pour le premier semestre de l'annee %d\n", annee);
		modifier_notes(t, taille, matieres, annee, semestre);
		break;
	case 2:
		printf("Gérer les notes pour le deuxième semestre de l'annee %d\n", annee);
		modifier_notes(t, taille, matieres, annee, semestre);
		break;
	case 3:
		printf("Au revoir !");
		break;
	default:
		printf("Choix invalide. Veuillez choisir a nouveau.\n");
		break;
	}
}

void gerer_notes(struct Personne *t1, int taille1, struct Personne *t2, int taille2,
		 struct Personne *t3, int taille3, struct Personne *t4, int taille4,
		 struct Personne *t5, int taille5)
{
	int choix_annee, choix_semestre;

	menu_gerer_notes();
	scanf("%d", &choix_annee);
	switch (choix_annee) {
	case 1:
		sous_menu_annee();
		scanf("%d", &choix_semestre);
		if (choix_semestre == 1) {
			gerer_notes_annee(t1, taille1, matieres1_sem1, 1, choix_semestre);
		} else if (choix_semestre == 2) {
			gerer_notes_annee(t1, taille1, matieres1_sem2, 1, choix_semestre);
		}
		break;
	case 2:
		sous_menu_annee();
		scanf("%d", &choix_semestre);
		if (choix_semestre == 1) {
			gerer_notes_annee(t2, taille2, matieres2_sem1, 2, choix_semestre);
		} else if (choix_semestre == 2) {
			gerer_notes_annee(t2, taille2, matieres2_sem2, 2, choix_semestre);
		}
		break;
	case 3:
		sous_menu_annee();
		scanf("%d", &choix_semestre);
		if (choix_semestre == 1) {
			gerer_notes_annee(t3, taille3, matieres3_sem1, 3, choix_semestre);
		} else if (choix_semestre == 2) {
			gerer_notes_annee(t3, taille3, matieres3_sem2, 3, choix_semestre);
		}
		break;
	case 4:
		sous_menu_annee();
		scanf("%d", &choix_semestre);
		if (choix_semestre == 1) {
			gerer_notes_annee(t4, taille4, matieres4_sem1, 4, choix_semestre);
		} else if (choix_semestre == 2) {
			gerer_notes_annee(t4, taille4, matieres4_sem2, 4, choix_semestre);
		}
		break;
	case 5:
		sous_menu_annee();
		scanf("%d", &choix_semestre);
		if (choix_semestre == 1) {
			gerer_notes_annee(t5, taille5, matieres5_sem1, 5, choix_semestre);
		} else if (choix_semestre == 2) {
			gerer_notes_annee(t5, taille5, matieres3_sem2, 5, choix_semestre);
		}
		break;
	case 6:
		printf("Au revoir !");
		break;
	default:
		printf("Choix invalide. Veuillez choisir a nouveau.\n");
		break;
	}
}

void gerer_etudiants(struct Personne *&t1, int &taille1, struct Personne *&t2, int &taille2,
		     struct Personne *&t3, int &taille3, struct Personne *&t4, int &taille4,
		     struct Personne *&t5, int &taille5)
{
	int choix_annee, choix_semestre;

	menu();
	scanf("%d", &choix_annee);
	switch (choix_annee) {
	case 1:
		sous_menu_annee();
		scanf("%d", &choix_semestre);
		if (choix_semestre == 1) {
			gerer_etudiants_annee(t1, taille1, 1, choix_semestre, matieres1_sem1);
		} else if (choix_semestre == 2) {
			gerer_etudiants_annee(t1, taille1, 1, choix_semestre, matieres1_sem2);
		}
		break;
	case 2:
		sous_menu_annee();
		scanf("%d", &choix_semestre);
		if (choix_semestre == 1) {
			gerer_etudiants_annee(t2, taille2, 2, choix_semestre, matieres2_sem1);
		} else if (choix_semestre == 2) {
			gerer_etudiants_annee(t2, taille2, 2, choix_semestre, matieres2_sem2);
		}
		break;
	case 3:
		sous_menu_annee();
		scanf("%d", &choix_semestre);
		if (choix_semestre == 1) {
			gerer_etudiants_annee(t3, taille3, 3, choix_semestre, matieres3_sem1);
		} else if (choix_semestre == 2) {
			gerer_etudiants_annee(t3, taille3, 3, choix_semestre, matieres3_sem2);
		}
		break;
	case 4:
		sous_menu_annee();
		scanf("%d", &choix_semestre);
		if (choix_semestre == 1) {
			gerer_etudiants_annee(t4, taille4, 4, choix_semestre, matieres4_sem1);
		} else if (choix_semestre == 2) {
			gerer_etudiants_annee(t4, taille4, 4, choix_semestre, matieres4_sem2);
		}
		break;
	case 5:
		sous_menu_annee();
		scanf("%d", &choix_semestre);
		if (choix_semestre == 1) {
			gerer_etudiants_annee(t5, taille5, 5, choix_semestre, matieres5_sem1);
		} else if (choix_semestre == 2) {
			gerer_etudiants_annee(t5, taille5, 5, choix_semestre, matieres5_sem2);
		}
		break;
	case 6:
		printf("au revoir !");
		break;
	default:
		printf("Choix invalide. Veuillez choisir a nouveau.\n");
		break;
	}
}

void sauvegarder_donnees(struct Personne *t, int taille, int annee, int semestre)
{
	char nom_fichier[20];
	FILE *fichier;

	sprintf(nom_fichier, "annee%d_semestre%d.txt", annee, semestre);
	fichier = fopen(nom_fichier, "a");

	if (fichier == NULL) {
		printf("Erreur lors de l'ouverture du fichier.\n");
		return;
	}

	for (int i = 0; i < taille; i++) {
		fprintf(fichier, "%s %d %d %d %d %c %s %.2f %.2f %.2f %.2f %d %d\n", t[i].nom,
			t[i].age, t[i].date.jr, t[i].date.mois, t[i].date.an, t[i].sexe, t[i].numu,
			t[i].notes[0], t[i].notes[1], t[i].notes[2], t[i].notes[3], t[i].annee,
			t[i].semestre);
	}

	fclose(fichier);
}

int charger_donnees(struct Personne *t, int taille, int annee, int semestre)
{
	char nom_fichier[20];
	FILE *fichier;
	int i = 0;

	sprintf(nom_fichier, "annee%d_semestre%d.txt", annee, semestre);
	fichier = fopen(nom_fichier, "r");

	if (fichier == NULL) {
		printf("Erreur lors de l'ouverture du fichier pour l'année %d et le "
		       "semestre %d.\n",
		       annee, semestre);
		return taille;
	}

	printf("Données chargées depuis le fichier %s :\n", nom_fichier);
	while (fscanf(fichier, "%s %d %d %d %d %c %s %f %f %f %f %d %d\n", t[i].nom, &t[i].age,
		      &t[i].date.jr, &t[i].date.mois, &t[i].date.an, &t[i].sexe, t[i].numu,
		      &t[i].notes[0], &t[i].notes[1], &t[i].notes[2], &t[i].notes[3], &t[i].annee,
		      &t[i].semestre) == 13) {
		printf("Nom: %s, Age: %d, Date: %d/%d/%d, Sexe: %c, NumU: %s, Notes: %.2f "
		       "%.2f %.2f %.2f, Année: %d, Semestre: %d\n",
		       t[i].nom, t[i].age, t[i].date.jr, t[i].date.mois, t[i].date.an, t[i].sexe,
		       t[i].numu, t[i].notes[0], t[i].notes[1], t[i].notes[2], t[i].notes[3],
		       t[i].annee, t[i].semestre);
		i++;
	}

	fclose(fichier);
	return i; /* Retourner le nombre d'éléments lus */
}

int main()
{
	int choix;
	int choix_sauvegarde;
	struct Personne *t1 = NULL; /* Liste pour la premiere annee */
	int taille1 = 0;
	struct Personne *t2 = NULL; /* Liste pour la deuxieme annee */
	int taille2 = 0;
	struct Personne *t3 = NULL; /* Liste pour la deuxieme annee */
	int taille3 = 0;
	struct Personne *t4 = NULL; /* Liste pour la deuxieme annee */
	int taille4 = 0;
	struct Personne *t5 = NULL; /* Liste pour la deuxieme annee */
	int taille5 = 0;

	do {
		printf(" ********* BONJOUR ! *************\n\n");
		printf("  BIENVENUE DANS CLASSVAULT , Votre plateforme securisee pour gerer "
		       "les donnees académiques de maniere efficace et transparente !\n\n ");
		printf(" Explorez notre menu principal et choisissez ce qui vous intéresse "
		       "le plus !\n\n");
		menu_principal();
		scanf("%d", &choix);

		switch (choix) {
		case 1:
			gerer_etudiants(t1, taille1, t2, taille2, t3, taille3, t4, taille4, t5,
					taille5);
			break;
		case 2:
			gerer_notes(t1, taille1, t2, taille2, t3, taille3, t4, taille4, t5,
				    taille5);
			break;

		case 3:
			printf("1- Sauvegarder les données\n");
			printf("2- Charger les données\n");
			printf("3- Quitter\n");
			printf("Votre choix : ");
			scanf("%d", &choix_sauvegarde);

			switch (choix_sauvegarde) {
			case 1:
				printf("Sauvegarde des données...\n");
				sauvegarder_donnees(t1, taille1, 1,
						    1); /* Première année, premier semestre */
				sauvegarder_donnees(t1, taille1, 1,
						    2); /* Première année, deuxième semestre */
				sauvegarder_donnees(t2, taille2, 2,
						    1); /* Deuxième année, premier semestre */
				sauvegarder_donnees(t2, taille2, 2,
						    2); /* Deuxième année, deuxième semestre */
				
				sauvegarder_donnees(t3, taille3, 3,
						    1); /* Troisième année, premier semestre */
				sauvegarder_donnees(t3, taille3, 3,
						    2); /* Troisième année, deuxième semestre */
				sauvegarder_donnees(t4, taille4, 4,
						    1); /* Quatrième année, premier semestre */
				sauvegarder_donnees(t4, taille4, 4,
						    2); /* Quatrième année, deuxième semestre */
				sauvegarder_donnees(t5, taille5, 5,
						    1); /* Cinquième année, premier semestre */
				sauvegarder_donnees(t5, taille5, 5,
						    2); /* Cinquième année, deuxième semestre */
				printf("Données sauvegardées avec succès.\n");
				break;
			case 2:
				printf("Choisissez l'année (1-5) : ");
				int annee;
				scanf("%d", &annee);
				printf("Choisissez le semestre (1-2) : ");
				int semestre;
				scanf("%d", &semestre);
				switch (annee) {
				case 1:
					taille1 = charger_donnees(t1, taille1, annee, semestre);
					break;
				case 2:
					taille2 = charger_donnees(t2, taille2, annee, semestre);
					break;
				case 3:
					taille3 = charger_donnees(t3, taille3, annee, semestre);
					break;
				case 4:
					taille4 = charger_donnees(t4, taille4, annee, semestre);
					break;
				case 5:
					taille5 = charger_donnees(t5, taille5, annee, semestre);
					break;
				default:
					printf("Année invalide. Veuillez choisir à nouveau.\n");
					break;
				}
				break;

			case 3:
				printf("Au revoir !\n");
				break;
				getch();
				system("cls");
			}
			break;

		case 4:
			printf("Au revoir !\n");
			break;
		}
		getch();
		system("cls");
	} while (choix != 5);

	/* Liberer la memoire allouee */
	free(t1);
	free(t2);
	free(t3);
	free(t4);
	free(t5);

	return 0;
}


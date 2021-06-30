#ifndef MENUASSETS_H
#define MENUASSETS_H

void drawBanner()
{
	printf("   _____      _            _       _        _              \n");
	printf("  / ____|    | |          | |     | |      (_)             \n");
	printf(" | |     __ _| | ___ _   _| | __ _| |_ _ __ _  ___ ___     \n");
	printf(" | |    / _` | |/ __| | | | |/ _` | __| '__| |/ __/ _ \\    \n");
	printf(" | |___| (_| | | (__| |_| | | (_| | |_| |  | | (_|  __/    \n");
	printf("  \\_____\\__,_|_|\\___|\\__,_|_|\\__,_|\\__|_|  |_|\\___\\___|    \n");
	printf(" |  __ \\    | |                           (_)     | |      \n");
	printf(" | |__) |__ | |_   _ _ __   ___  _ __ ___  _  __ _| | ___  \n");
	printf(" |  ___/ _ \\| | | | | '_ \\ / _ \\| '_ ` _ \\| |/ _` | |/ _ \\ \n");
	printf(" | |  | (_) | | |_| | | | | (_) | | | | | | | (_| | |  __/ \n");
	printf(" |_|   \\___/|_|\\__, |_| |_|\\___/|_| |_| |_|_|\\__,_|_|\\___| \n");
	printf("                __/ |                                      \n");
	printf("               |___/                                       \n");



}

void drawSeparator()
{
	printf("\n\n*******************************************************************\n\n");
}

void drawChoices(int sous_choix)
{
	printf("\n\nChoisissez une option :\n\n");

	switch(sous_choix)
	{
		case 0:
			printf("1- Entrer des polynômes\n2- Afficher des polynômes\n3- Somme\n4- Produit\n5- Valeur pour X\n6- Dérivée\n7- Dérivée de la somme\n8- Dérivée du produit\n\n9- Quitter\n\n");
			break;
			
		case 1:
			printf("1- Entrer à la main\n2- Lire fichier texte\n3- Charger polynômes par défaut\n\n9- Retour\n\n");
			break;

		case 11:
			printf("1- Entrer polynôme 1\n2- Entrer polynôme 2\n\n9- Retour\n\n");
			break;

		case 12:
			printf("Le polynôme doit être écrit dans le fichier de la façon suivante :\n\n");
			printf("(-) <COEF> X<DEGRÉ> +/- <COEF> X +/- <COEF>\n\nRespecter espaces et majuscules!\n\n");
			printf("1- Entrer polynôme 1\n2- Entrer polynôme 2\n\n9- Retour\n\n");
			break;

		case 2:
			printf("1- Afficher les polynômes dans le terminal\n2- Ecrire les polynômes dans un fichier texte\n\n9- Retour\n\n");
			break;

		case 20:
			printf("1- Afficher polynôme 1\n2- Afficher polynôme 2\n3- Afficher dernier résultat\n\n9- Retour\n\n");
			break;
		case 5:
			printf("1- Image classique\n2- Méthode de Horner\n\n9- Retour\n\n");
			break;
		case 51:
			printf("1- Image du polynôme 1\n2- Image du polynôme 2\n\n9- Retour\n\n");
			break;
	}
}

long int getOption()
{
	char line[64];
	char * ptr;
	printf("-> ");
	fflush(stdin);
	scanf(" %s", &line);
	fflush(stdin);
	return strtol(line, &ptr, 10);
}

#endif
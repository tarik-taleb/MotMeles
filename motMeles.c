#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <MLV/MLV_all.h>
#define N 20
#define TAILLE_CASE 30
#define MAJ 0 /*MACRO POUR CHANGER LE COMPORTEMENT DE L'AFFICHAGE 1=MAJUSCULE ET 0=MINUSCULE*/
#define M 5
 
/*STRUCTURE*/

typedef struct point
{
	int x;
	int y;
}Point;


typedef struct droite
{
	Point p1;
	Point p2;
}Droite;

/*--------------------------------------------------------------------------------------------------------------------*/

/*FONCTION DE SAISIE DES POINT DE CLICK DE LA SOURIS*/

void saisiePoint(Point *p)
{
	MLV_wait_mouse(&p->x,&p->y);
	MLV_actualise_window();
	MLV_draw_point(p->x,p->y, MLV_COLOR_WHITE );
	MLV_actualise_window();
}

/*--------------------------------------------------------------------------------------------------------------------

/*FONCTION QUI CONSTRUIT UNE DROITE*/

int construireDroite(Point a, Point b ,Droite *d)
{
	if (a.x==b.x && a.y==b.y)
	{
		printf("ERREUR\n");
		return 2;
	}
	else
	{
		d->p1.x =a.x;
		d->p1.y =a.y;
		d->p2.x =b.x;
		d->p2.y =b.y;
	return 1;
	}
}

/*--------------------------------------------------------------------------------------------------------------------*/

/*FONCTION QUI DESSINE UNE DROITE*/

void dessineDroite(Droite d)
{
	MLV_draw_line( d.p1.x,d.p1.y,d.p2.x,d.p2.y, MLV_COLOR_BLACK );
	MLV_actualise_window();
}

/*--------------------------------------------------------------------------------------------------------------------*/
/*FONCTION QUI AFFICHE LE TABLEAU */

void affichage(char tableau[][N],int taille)
{
	int i;
	int j;/*compteur qui nous aide a parcourir le tableau*/
	for (i = 0; i < taille; ++i)
	{
		printf("%5d",i );
	}
	printf("\n");
	for (i = 0; i < taille; ++i)
	{
		if (i<10)
		{
		printf(" %d",i );
		}
		else if (i>=10)
		{
		printf("%d",i );
		}
		
		for (j = 0; j < taille; ++j)
		{
			if (tableau[i][j]=='\0')
			{	
				tableau[i][j]=' ';
				printf(" [%c] ",tableau[i][j]);
			}
			else
			{
				printf(" [%c] ",tableau[i][j]);
			}
		}
		printf("\n");
		printf("\n");
	}
}

/*--------------------------------------------------------------------------------------------------------------------*/
void affichage2(int tableau[][N],int taille)
{
	int i;
	int j;/*compteur qui nous aide a parcourir le tableau*/
	for (i = 0; i < taille; ++i)
	{
		printf("%5d",i );
	}
	printf("\n");
	for (i = 0; i < taille; ++i)
	{
		if (i<10)
		{
		printf(" %d",i );
		}
		else if (i>=10)
		{
		printf("%d",i );
		}
		
		for (j = 0; j < taille; ++j)
		{
			if (tableau[i][j]=='\0')
			{	
				tableau[i][j]=' ';
				printf(" [%d] ",tableau[i][j]);
			}
			else
			{
				printf(" [%d] ",tableau[i][j]);
			}
		}
		printf("\n");
		printf("\n");
	}
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*FONCTION QUI INITIALISE LE TABLEAU*/
void initialisation(char tableau[][N],int taille)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < taille; ++i)
	{
		for (j = 0; j < taille; ++j)
		{
			tableau[i][j] = ' ';
		}
	}
}

/*--------------------------------------------------------------------------------------------------------------------*/
/*FONCTION QUI INITIALISE LE TABLEAU*/
void initialisation2(int tableau[][N],int taille)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < taille; ++i)
	{
		for (j = 0; j < taille; ++j)
		{
			tableau[i][j] = -1;
		}
	}
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*FONCTION DE TRANSFORMATION DU MOT EN MAJUSCULE*/

void majuscule(char tableau_tmp[],int taille_tmp )
{
	int i;
	for (i = 0; i <taille_tmp ; ++i)
	{
		tableau_tmp[i]=tableau_tmp[i]-32;
	}
}

/*--------------------------------------------------------------------------------------------------------------------*/
/*FONCTION DE SAISIE */

int saisie(void)
{
	int nombre;
	int  ret;
	ret = scanf ("%2d", &nombre);
	scanf ("%*[^\n]");/*permet de vider le tampon*/
	while(ret == 0 )
	{
		printf("ERREUR\n");
		printf("Votre choix est :");
		ret = scanf ("%2d", &nombre);
		scanf ("%*[^\n]");
	}
	return nombre;
}
/*--------------------------------------------------------------------------------------------------------------------*/
/* FONCTION DE SAISIE DU MOT */	

int verif_mot(char tableau_tmp[],int taille)
{
	int i = 0;

	for (i = 0; i < taille; ++i)
	{
		if (tableau_tmp[i] < 'a' || tableau_tmp[i] > 'z')
		{
			return 1;
		}
	}	
	return 0;
}

void saisie_mots(char tableau_tmp[],int taille)
{
	char val;
	do
	{
	printf("Veuillez saisir votre mot :");
	val=scanf(" %s",tableau_tmp);
	printf("%d\n", val);
	if (val==0){
	printf("ERREUR\n");
	}

	
	}while (strlen(tableau_tmp) > taille || strlen(tableau_tmp) <= 2 || (verif_mot(tableau_tmp,strlen(tableau_tmp)) == 1 ));
}
/*--------------------------------------------------------------------------------------------------------------------*/
/* FONCTION DE DIRECTION */

void direction_mot(int *direction)
{
	do
	{
		printf("\n");
		printf("Veuillez choisir une direction pour votre mot\n");
		printf("Liste des choix possible :\n");
		printf("0 pour une diagonal haut gauche .\n");
		printf("1 pour aller haut .\n");
		printf("2 pour une diagonal haut droite .\n");
		printf("3 pour aller a gauche .\n");
		printf("4 pour aller a droite .\n");
		printf("5 pour une diagonal bas gauche .\n");
		printf("6 pour aller en bas .\n");
		printf("7 pour une diagonal bas droite .\n");
		printf("Votre choix :");
		*direction = saisie();

	}while(*direction <= -1 || *direction >= 8);

}

/*--------------------------------------------------------------------------------------------------------------------*/
/* FONCTION QUI DONNE LA POSITION */

void choisir_position(int *x, int *y,int taille)
{	

	printf("Veuillez donner la position de votre premiere lettre :\n");
	do
	{
		printf("x = ");
		
		*x = saisie();
	}while(*x < 0 || *x > taille);
	
	do
	{
		printf("y = ");
		*y = saisie();

	}while(*y < 0 || *y > taille);
	
	
}
/*--------------------------------------------------------------------------------------------------------------------*/
/* FONCTION QUI PLACE LE MOT DANS LE TABLEAU */ 

void placement_mot(char tableau[][N],char tableau_tmp[],int taille,int direction,int x,int y)
{
	int i;


		if (direction == 0)
		{	
			for (i = 0; i < taille; ++i)
			{			
				tableau[x][y]=tableau_tmp[i];
				x=x-1;
				y=y-1;
			}
		}
		else if (direction == 1)
		{	
			for (i = 0; i < taille; ++i)
			{	
				tableau[x][y]=tableau_tmp[i];
				x=x-1;
			}
		}
		else if (direction == 2)
		{	
			for (i = 0; i < taille; ++i)
			{	
				tableau[x][y]=tableau_tmp[i];
				x=x-1;
				y=y+1;
			}
		}
		else if (direction == 3)
		{	
			for (i = 0; i < taille; ++i)
			{	
				tableau[x][y]=tableau_tmp[i];
				y=y-1;
			}
		}
		else if (direction == 4)
		{	
			for (i = 0; i < taille; ++i)
			{	
				tableau[x][y]=tableau_tmp[i];
				y=y+1;
			}
		}
		else if (direction == 5)
		{	
			for (i = 0; i < taille; ++i)
			{	
				tableau[x][y]=tableau_tmp[i];
				x=x+1;
				y=y-1;
					
			}
		}
		else if (direction == 6)
		{	
			for (i = 0; i < taille; ++i)
			{	
				tableau[x][y]=tableau_tmp[i];
				x=x+1;
			}
		}
		else if (direction == 7)
		{	
			for (i = 0; i < taille; ++i)
			{	
				tableau[x][y]=tableau_tmp[i];
				x=x+1;
				y=y+1;
			}
		}
}
/*--------------------------------------------------------------------------------------------------------------------*/
/* FONCTION QUI TEST LE MOT S'IL PEUT ENTRE DANS LE TABLEAU */ 
int test_mots(char tableau_tmp[],int taille,int direction,int x,int y)
{

	if (direction == 0)
	{
		if (x+1 < strlen(tableau_tmp) || y+1 < strlen(tableau_tmp))
		{
			return 0;
		}
		return 1;
	}

	else if (direction == 1)
	{
		if (x+1 < strlen(tableau_tmp))
		{
			return 0;
		}
		return 1;
	}
	else if (direction == 2)
	{

		if (x+1 < strlen(tableau_tmp ) || (taille-y+1) < strlen(tableau_tmp))
		{ 
			return 0;
		}
		return 1;
	}
	
	else if (direction == 3)
	{
		if (y+1 < strlen(tableau_tmp)) 
		{
			return 0;
		}
		return 1;
	}
	else if (direction == 4)
	{
		if ((taille-y+1) <= strlen(tableau_tmp))
		{
			return 0;
		}
		return 1;
	}
	
	else if (direction == 5)
	{
		printf("ok\n");
		if ((taille-x+1)<strlen(tableau_tmp) || (taille-y+1)<strlen(tableau_tmp))
		{
			return 0;
		}
		return 1;

	}
	else if (direction == 6)
	{
		if ((taille-x+1) <= strlen(tableau_tmp))
		{
			return 0;
		}
		return 1;
	}
	else if (direction == 7)
	{
		if ((taille-x+1)<strlen(tableau_tmp) || (taille-y+1)<strlen(tableau_tmp))
		{
			return 0;
		}
		return 1;
	}
	return 2;

}

/*--------------------------------------------------------------------------------------------------------------------*/
/* FONCTION QUI GENERE DES LETTRE DE FACON ALEATOIRE POUR COMPLETER LE TABLEAU  */ 

void aleatiore_lettre(char tableau_tmp[][N],int taille)
{
	const char lettre_maj[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	const char lettre_min[27]="abcdefghijklmnopqrstuvwxyz";

	int indice;
	int i;
	int j;
	for (i = 0; i <taille ; ++i)
	{
		for (j = 0; j <taille ; ++j)
		{
			if (tableau_tmp[i][j]==' ')
			{
				indice=rand()%26;
				if (MAJ == 1)
				{
					tableau_tmp[i][j]=lettre_maj[indice];
				}
				if (MAJ == 0)
				{
					tableau_tmp[i][j]=lettre_min[indice];
				}
			}		
		}
	}
} 
/*--------------------------------------------------------------------------------------------------------------------*/
/* FONCTION QUI TEST SI LE MOT N'ANNULE PAS UN MOT DEJA PRESENT */

int mots_valide(char tableau[][N],char tableau_tmp[],int taille_tmp,int x,int y,int direction)
{
	int i;
	int cpt=0;
	

	if (direction == 0)
	{
		for (i = 0; i < taille_tmp ; ++i)
		{
			if (tableau[x][y]==' ')
			{
				x=x-1;
				y=y-1;
				cpt=cpt+1;
			}	
			else
	 		{
				if (tableau[x][y]!=tableau_tmp[cpt])
				{
					return 0;
				}
			}			
		}
		return 1;
	}

	else if (direction == 1)
	{
		for (i = 0; i < taille_tmp ; ++i)
		{
			if (tableau[x][y]==' ')
			{
				x=x-1;
				cpt=cpt+1;
			}	
			else
	 		{
				if (tableau[x][y]!=tableau_tmp[cpt])
				{
					return 0;
				}
			}			
		}
		return 1;
	}

	else if (direction == 2)
	{
		for (i = 0; i < taille_tmp ; ++i)
		{
			if (tableau[x][y]==' ')
			{
				x=x-1;
				y=y+1;				
				cpt=cpt+1;
			}	
			else
	 		{
				if (tableau[x][y]!=tableau_tmp[cpt])
				{
					return 0;
				}
			}		
		}
		return 1;
	}

	else if (direction == 3)
	{
		for (i = 0; i < taille_tmp ; ++i)
		{
			if (tableau[x][y]==' ')
			{
				y=y-1;
				cpt=cpt+1;
			}	
			else
	 		{
				if (tableau[x][y]!=tableau_tmp[cpt])
				{
					return 0;
				}
			}		
		}
		return 1;
	}

	else if (direction == 4)
	{
		for (i = 0; i < taille_tmp ; ++i)
		{
			if (tableau[x][y]==' ')
			{
				y=y+1;
				cpt=cpt+1;
			}	
			else
	 		{
				if (tableau[x][y]!=tableau_tmp[cpt])
				{
					return 0;
				}
			}
		}
		return 1;
	}
	else if (direction == 5)
	{
		for (i = 0; i < taille_tmp ; ++i)
		{
			if (tableau[x][y]==' ')
			{
				x=x+1;
				y=y-1;
				cpt=cpt+1;
			}	
			else
	 		{
				if (tableau[x][y]!=tableau_tmp[cpt])
				{
					return 0;
				}
			}			
		}
		return 1;
	}

	else if (direction == 6)
	{
		for (i = 0; i < taille_tmp ; ++i)
		{
			if (tableau[x][y]==' ')
			{
				printf("ok\n");
				x=x+1;
				cpt=cpt+1;
			}	
			else				
	 		{
				if (tableau[x][y]!=tableau_tmp[cpt])
				{
					return 0;
				}
			}		
		}
		return 1;
	}

	else if (direction == 7)
	{
		for (i = 0; i < taille_tmp ; ++i)
		{
			if (tableau[x][y]==' ')
			{
				x=x+1;
				y=y+1;
				cpt=cpt+1;
			}	
			else 
	 		{
				if (tableau[x][y]!=tableau_tmp[cpt])
				{
					return 0;
				}
			}		
		}
		return 1;
	}
	return 0;
}

/*--------------------------------------------------------------------------------------------------------------------*/
/* FONCTION QUI REINITIALISE LE TABLEAU */

void reboot_tableau(char tableau[],int taille)
{
	int i;
	for (i = 0; i < taille; ++i)
	{
		tableau[i]=' ';
	}
}
/*--------------------------------------------------------------------------------------------------------------------*/
/* FONCTION QUI SAUVEGARDE LES MOTS DANS UN TABLEAU  */

void sauvegarde(char sauv[][N],char mots[],int taille)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < taille; ++i)
	{
		if (sauv[i][0] == ' ')
		{
			for (j = 0; j < strlen(mots); ++j)
			{
				sauv[i][j] = mots[j];
			}
			return ;
		}
		
	}
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*FONCTION QUI SELECTIONNE LE MOT A SUPPRIMER*/

void selection(char monde[][N],char mots[],int taille,int x_depart,int y_depart,int x_fin,int y_fin,int direction)
{
	int i = 0;

	if (direction == 0)
	{	
		for (i = 0; i < taille; ++i)
		{
			if (x_depart >= x_fin && y_depart >= y_fin)
			{
				mots[i] = monde[x_depart][y_depart];
				x_depart=x_depart-1;
				y_depart=y_depart-1;
			}						
		}
	}
	if (direction == 1)
	{	
		for (i = 0; i < taille; ++i)
		{	
			if (x_depart >= x_fin)
			{
				mots[i] = monde[x_depart][y_depart];
				x_depart=x_depart-1;
			}
		}
	}
	if (direction == 2)
	{	
		for (i = 0; i < taille; ++i)
		{	
			if (x_depart >= x_fin && y_depart <= y_fin)
			{
				mots[i] = monde[x_depart][y_depart];
				x_depart=x_depart-1;
				y_depart=y_depart+1;
			}
		}
	}
	if (direction == 3)
	{	
		for (i = 0; i < taille; ++i)
		{	
			if (y_depart >= y_fin)
			{
				mots[i] = monde[x_depart][y_depart];
				y_depart=y_depart-1;
			}
		}
	}
	if (direction == 4)
	{	
		for (i = 0; i < taille; ++i)
		{	
			if (y_depart <= y_fin)
			{
				mots[i] = monde[x_depart][y_depart];
				y_depart=y_depart+1;
			}
		}
	}
	if (direction == 5)
	{	
		for (i = 0; i < taille; ++i)
		{	
			if (x_depart <= x_fin && y_depart >= y_fin)
			{
				mots[i] = monde[x_depart][y_depart];
				x_depart=x_depart+1;
				y_depart=y_depart-1;
			}	
		}
	}
	if (direction == 6)
	{	
		for (i = 0; i < taille; ++i)
		{	
			if (x_depart <= x_fin)
			{
				mots[i] = monde[x_depart][y_depart];
				x_depart=x_depart+1;
			}
		}
	}
	if (direction == 7)
	{	
		for (i = 0; i < taille; ++i)
		{	
			if (x_depart <= x_fin && y_depart <= y_fin)
			{
				mots[i] = monde[x_depart][y_depart];
				x_depart=x_depart+1;
				y_depart=y_depart+1;
			}
		}
	}

}

/*--------------------------------------------------------------------------------------------------------------------*/
/*FONCTION QUI CHARGE LES LIGNES DU TABLEAU*/

void aff(char mot[],int taille)
{
	int i = 0;
	for (i = 0; i < taille; ++i)
	{
		printf("tab[%d] -> %c \n",i,mot[i] );
	}
	printf("\n");
}

int taille_tab(char *tableau_tmp)
{
	int i = 0;
	int cmp = 0;
	for (i = 0; i < strlen(tableau_tmp); ++i)
	{
		if (tableau_tmp[i] >= 'A' && tableau_tmp[i] <= 'Z')
		{
			cmp ++;
		}
	}
	return cmp;
}


void chargement_ligne(char sauvegarde[][N],char mots[],int taille,int indice)
{
	int i = 0;
	for (i = 0; i < taille; ++i)
	{
		mots[i] = sauvegarde[indice][i];
	}
}

char * allocation(int taille)
{
	char *tmp;

	tmp = (malloc(sizeof(char)*taille));

	if (tmp == NULL)
	{
		return 0;
	}
	int i = 0;

	for (i = 0; i < taille; ++i)
	{
		tmp[i] = '+';
	}
	return tmp;

}

void chargement(char tableau1[],char tableau2[],int taille)
{
	int i = 0 ;
	for (i = 0; i < taille; ++i)
	{
		tableau1[i] = tableau2[i];
	}
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*FONCTION QUI COMPARE DEUX CHAINE DE CARACTERE*/

int cmp(char chaine1[],char chaine2[])
{
	int i = 0;
	for (i = 0; i <strlen(chaine1) ; ++i)
	{
		if (chaine1[i] != chaine2[i])
		{
			return 1;
		}
	}
	return 0;
}

/*--------------------------------------------------------------------------------------------------------------------*/
/*FONCTION QUI COMPARER DEUX TABLEAU*/

int compare(char tableau1[],char tableau2[])
{
	int a = taille_tab(tableau1);
	int b = taille_tab(tableau2);
	int i = 0;
	char * tab;
	char * tab2; 
	printf("%d\n",a );
	printf("%d\n",a );
	tab = allocation(a);
	tab2 = allocation(a);
	chargement(tab,tableau1,a);
	chargement(tab2,tableau2,a);
	i = cmp(tab,tab2);
	return i;	
}

/*--------------------------------------------------------------------------------------------------------------------*/
/* FONCTION QUI TESTE SI LE MOTS A LE DROIT D'ETRE SUPPRIMER  */

int test_supprime(char sauvegarde[][N],char mots[],int taille,int nb_mot)
{
	int i = 0;
	int cmp;
	char * tableau_tmp = allocation(taille);
	
	for (i = 0; i < nb_mot; ++i)
	{
		chargement_ligne(sauvegarde,tableau_tmp,taille,i);
		aff(mots,strlen(mots));
		aff(tableau_tmp,strlen(tableau_tmp));
		cmp = compare(mots,tableau_tmp);
		if (cmp == 0)
		{
			free(tableau_tmp);
			return 1;
		}
		
	}
	free(tableau_tmp);
	return 0;
}
/*--------------------------------------------------------------------------------------------------------------------*/
/* FONCTION QUI TROUVE LA DIRECTION */

int trouve_direction(int x_depart ,int y_depart,int x_fin,int y_fin)
{
	if (x_depart < x_fin && y_depart == y_fin)
	{
		return 6;
	}
	if (x_depart > x_fin && y_depart == y_fin)
	{
		return 1;
	}
	if (x_depart == x_fin && y_depart < y_fin)
	{
		return 4;
	}
	if (x_depart == x_fin && y_depart > y_fin)
	{
		return 3;
	}
	if (x_depart < x_fin && y_depart < y_fin)
	{
		return 7;
	}
	if (x_depart > x_fin && y_depart > y_fin)
	{
		return 0;/*ok*/
	}
	if (x_depart < x_fin && y_depart > y_fin)
	{
		return 5;
	}
	if (x_depart > x_fin && y_depart < y_fin)
	{
		return 2;
	}
}

/*--------------------------------------------------------------------------------------------------------------------*/

void miniscule_mot(char tableau[][N],int direction,int x_depart,int y_depart,int x_fin,int y_fin)
{
	if (direction == 0)
	{	
		while(x_depart >= x_fin && y_depart >= y_fin)
		{
			tableau[x_depart][y_depart]= tableau[x_depart][y_depart] + 32;
			x_depart=x_depart-1;
			y_depart=y_depart-1;			
		}
		return;
	}
	if (direction == 1)
	{	
		while(x_depart >= x_fin)
		{
			tableau[x_depart][y_depart]= tableau[x_depart][y_depart] + 32 ;
			x_depart=x_depart-1;
		}
		return;
	}
	if (direction == 2)
	{	
		while(x_depart >= x_fin && y_depart <= y_fin)
		{
			tableau[x_depart][y_depart]= tableau[x_depart][y_depart] + 32;
			x_depart=x_depart-1;
			y_depart=y_depart+1;
		}
		return;
	}
	if (direction == 3)
	{	
		while(y_depart >= y_fin)
		{
			tableau[x_depart][y_depart]= tableau[x_depart][y_depart] + 32;
			y_depart=y_depart-1;
		}
		return;
	}
	if (direction == 4)
	{	
		while(y_depart <= y_fin)
		{
			tableau[x_depart][y_depart] = tableau[x_depart][y_depart] + 32;
			y_depart=y_depart+1;
		}
		return;
	}
	if (direction == 5)
	{	
		while(x_depart <= x_fin && y_depart >= y_fin)
		{
			tableau[x_depart][y_depart] = tableau[x_depart][y_depart] + 32;
			x_depart=x_depart+1;
			y_depart=y_depart-1;
		}
		return ;
	}
	if (direction == 6)
	{	
		while(x_depart <= x_fin)
		{
			tableau[x_depart][y_depart] = tableau[x_depart][y_depart] + 32;
			x_depart=x_depart+1;
		}
		return;
	}
	if (direction == 7)
	{	
		while(x_depart <= x_fin && y_depart <= y_fin)
		{
			tableau[x_depart][y_depart]= tableau[x_depart][y_depart] + 32 ;
			x_depart=x_depart+1;
			y_depart=y_depart+1;
		}
	}
}
/*--------------------------------------------------------------------------------------------------------------------*/
/*FONCTION QUI RENVOIE UNE COULEUR ALEATOIRE*/
MLV_Color fabrique_Couleur(int i ) 
{
	return MLV_rgba(255-i,i,0,255);
}

/*--------------------------------------------------------------------------------------------------------------------*/
/*FONCTION QUI REDESSINE LES CARRES TROUVES*/

void redessine_couleur(char monde[][N],int x_depart,int y_depart,int x_fin,int y_fin,int direction)
{
	char ta[2]={0};
	int i = 0;
	int x1 = 0;
	int y1 = 0;
	int couleur;

	x1 = x_depart * TAILLE_CASE;
	y1 = y_depart * TAILLE_CASE;
	couleur = rand()%256;
	if (direction == 0)
	{	
		while(y_depart >= y_fin && x_depart >= x_fin)
		{

			ta[0]=monde[x_depart][y_depart];
				MLV_draw_text_box(x1,y1,TAILLE_CASE,TAILLE_CASE,&(ta[0]),9,MLV_COLOR_BLACK, MLV_COLOR_BLACK,
							fabrique_Couleur(couleur),MLV_TEXT_LEFT,MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER ); 		
				MLV_actualise_window();

				x1=x1-TAILLE_CASE;	
				y1=y1-TAILLE_CASE;
				x_depart=x_depart-1;
				y_depart=y_depart-1;
						
		}
		return;
	}
	if (direction == 1)
	{	
		while(y_depart >= y_fin)
		{
			ta[0]=monde[y_depart][x_depart];
				MLV_draw_text_box(x1,y1,TAILLE_CASE,TAILLE_CASE,&(ta[0]),9,MLV_COLOR_BLACK, MLV_COLOR_BLACK,
							fabrique_Couleur(couleur),MLV_TEXT_LEFT,MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER ); 		
				MLV_actualise_window();
			y1=y1-TAILLE_CASE;	
			y_depart=y_depart-1;
		}
		return;
	}
	if (direction == 2)
	{	
		while(y_depart >= y_fin && x_depart <= x_fin)
		{
			ta[0]=monde[y_depart][x_depart];
				MLV_draw_text_box(x1,y1,TAILLE_CASE,TAILLE_CASE,&(ta[0]),9,MLV_COLOR_BLACK, MLV_COLOR_BLACK,
							fabrique_Couleur(couleur),MLV_TEXT_LEFT,MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER ); 
				MLV_actualise_window();		
			x1=x1+TAILLE_CASE;	
			y1=y1-TAILLE_CASE;
			x_depart=x_depart+1;
			y_depart=y_depart-1;
		}
		return;
	}
	if (direction == 3)
	{	
		while(x_depart >= x_fin)
		{
			ta[0]=monde[y_depart][x_depart];
				MLV_draw_text_box(x1,y1,TAILLE_CASE,TAILLE_CASE,&(ta[0]),9,MLV_COLOR_BLACK, MLV_COLOR_BLACK,
							fabrique_Couleur(couleur),MLV_TEXT_LEFT,MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER ); 			
				MLV_actualise_window();
			x1=x1-TAILLE_CASE;			
			x_depart=x_depart-1;
		}
		return;
	}
	if (direction == 4)
	{	
		while(x_depart <= x_fin)
		{
			printf("%d\n", x_depart);
			printf("%d\n", x_fin);
			ta[0]=monde[y_depart][x_depart];
				MLV_draw_text_box(x1,y1,TAILLE_CASE,TAILLE_CASE,&(ta[0]),9,MLV_COLOR_BLACK, MLV_COLOR_BLACK,
							fabrique_Couleur(couleur),MLV_TEXT_LEFT,MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER ); 
				MLV_actualise_window();			
			x1=x1+TAILLE_CASE;
			x_depart=x_depart+1;
			printf("ok\n");
		}
		return;
	}
	if (direction == 5)
	{	
		while(x_depart >= x_fin && y_depart <= y_fin)
		{
			ta[0]=monde[y_depart][x_depart];
				MLV_draw_text_box(x1,y1,TAILLE_CASE,TAILLE_CASE,&(ta[0]),9,MLV_COLOR_BLACK, MLV_COLOR_BLACK,
							fabrique_Couleur(couleur),MLV_TEXT_LEFT,MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER ); 
				MLV_actualise_window();		
			x1=x1-TAILLE_CASE;	
			y1=y1+TAILLE_CASE;			
			x_depart=x_depart-1;
			y_depart=y_depart+1;
		}
		return ;
	}
	if (direction == 6)
	{	
		while(y_depart <= y_fin)
		{
			ta[0]=monde[y_depart][x_depart];
				MLV_draw_text_box(x1,y1,TAILLE_CASE,TAILLE_CASE,&(ta[0]),9,MLV_COLOR_BLACK, MLV_COLOR_BLACK,
							fabrique_Couleur(couleur),MLV_TEXT_LEFT,MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER ); 	
				MLV_actualise_window();	
			y1=y1+TAILLE_CASE;				
			y_depart=y_depart+1;
		}
		return;
	}
	if (direction == 7)
	{	
		while(x_depart <= x_fin && y_depart <= y_fin)
		{
			ta[0]=monde[y_depart][x_depart];
				MLV_draw_text_box(x1,y1,TAILLE_CASE,TAILLE_CASE,&(ta[0]),9,MLV_COLOR_BLACK, MLV_COLOR_BLACK,
							fabrique_Couleur(couleur),MLV_TEXT_LEFT,MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER );
				MLV_actualise_window(); 		
			x1=x1+TAILLE_CASE;	
			y1=y1+TAILLE_CASE;
			x_depart=x_depart+1;
			y_depart=y_depart+1;
		}
		return;
	}

}

/*--------------------------------------------------------------------------------------------------------------------*/

/*FONCTION QUI SAUVEGARDE LA GRILLE DANS UN FICHIER*/
void sauvegarde_fichier(FILE * fichier,char grille[][N],int taille)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < taille; ++i)
	{
		for (j = 0; j < taille; ++j)
		{
			fprintf(fichier, "%c", grille[i][j]);
		}
		fprintf(fichier, "\n");		
	}
	return;
}

/*--------------------------------------------------------------------------------------------------------------------*/
/*FONCTION QUI CHARGE LA GRILLE DANS UN FICHIER*/
// ,char grille[][N],char sauvegarde[][N],int taille_grille,int nb_mot
void chargement_fichier(FILE * fichier)
{
	printf("ok\n");
	int c;
	while ((c=fgetc(fichier)) != EOF)
	{
	    printf("%c\n",c );
	}
}


/*--------------------------------------------------------------------------------------------------------------------*/
/*CORPS PRINCIPAL DU PROGRAMME */


int main(int argc, char const *argv[])
{
	if (argc == 1 || argc == 2)
	{
		printf("Veuillez mettre une option à votre éxuctable pour l'éxécuter :\n");
		printf("-a : affichage ASCII (exclu l’option suivante)\n");
		printf("-g : affichage graphique (exclu l’option précédente),\n");
		printf("-c : création d’une grille.\n");
		printf("Un nom de fichier sera egalement fourni, soit pour la sauvegarde, soit pour lire la grille.\n");
		printf("Petit exemple : ./motsMeles -ca nom_fichier_sauvegarde \n");
		printf("Le chargement du fichier pose probleme,donc il faut combiner l'option -c avec -a ou -g\n");
		printf("Exemle : -ca nom_fichier_sauvegarde ou -cg nom_fichier_sauvegarde \n");
		exit(EXIT_FAILURE);
	}
	int i = 0 ;
	FILE *fichier = NULL;
	int x;								/*position x du mot*/
	int y;								/*position y du mot*/
	int x_f;							/*position x fin du mot*/
	int y_f;							/*position y fin du mot*/
	char monde[N][N];					/*tableau pour le jeu*/
	char sauv[N][N];					/*tableau de sauvegarde des mots*/
	char mot[N];						/*tableau qui sauvegarde temporairement les mots a inscrire dans le tableau*/
	int enreg[N][N];					/*tableau qui enregistre les informations du mot*/
	int direction = 0;					/*direction du mot*/
	int taille = 0;						/*taille de grille du jeu*/
	int cpt_nbmot=1;					/*compte le nombre de mot*/
	srandom(time(NULL));

	/*--------------------------------------------------------------------------------------------------------------------*/
	fichier = fopen(argv[2], "w+");
	if (strcmp(argv[1],"-ca") == 0 || strcmp(argv[1],"-cg") == 0)
	{
		if (fichier == NULL)
	    {
	    	printf("Impossible d'ouvrir le fichier texte");
	    }
	    if (fichier != NULL)
	    {      
	   		printf("Premier partie du jeu remplissage de la grille\n");
			printf("\n");
			printf("\n");

			printf("Veuillez choisir la taille de votre grille : \n");
			printf("Largeur * hauteur =");
			taille=saisie();

			while(taille < 0 || taille > 21)
			{
				printf("ERREUR !!!!!\n");
				printf("Taille de grille négatif ou superieur à 21  :\n");
				printf("Veuillez choisir la taille de votre grille : \n");
				printf("Largeur * hauteur =");
				taille=saisie();
			}
			fprintf(fichier,"%d\n", taille);
			printf("Veuillez donner le nombre de mots à rentrer :");	
			cpt_nbmot = saisie();
			while (cpt_nbmot < 0 || cpt_nbmot > taille)
			{
				printf("ERREUR!!\n");
				printf("Veuillez donner le nombre de mots à rentrer :");	
				cpt_nbmot = saisie();
			}
			fprintf(fichier,"%d\n", cpt_nbmot);
			initialisation(monde,taille);
			initialisation(sauv,taille);
			initialisation2(enreg,taille);	
			affichage(monde,taille);

			while (i < cpt_nbmot)
			{
				direction_mot(&direction);
				choisir_position(&x, &y,taille);
				saisie_mots(mot,taille);
				
				majuscule(mot,strlen(mot) );
				while(test_mots(mot,taille,direction,x,y) == 0 || mots_valide(monde,mot,strlen(mot),x,y,direction) == 0)
				{		
					printf("ERREUR !!!!!\n");
					reboot_tableau(mot,taille);
					direction_mot(&direction);
					choisir_position(&x,&y,taille);
					saisie_mots(mot,taille);
					majuscule(mot,strlen(mot) );
					test_mots(mot,taille,direction,x,y);
					mots_valide(monde,mot,strlen(mot),x,y,direction);
				}
				sauvegarde(sauv,mot,taille);
				placement_mot(monde,mot,strlen(mot),direction,x,y);
				affichage(monde,taille);
				i++;		
			}

			aleatiore_lettre(monde,taille);
			printf("LE MONDE \n");
			affichage(monde,taille);
			printf("LA SAUVEGARDE\n");
			affichage(sauv,taille);
			sauvegarde_fichier(fichier,monde,taille);
			fprintf(fichier, "\n");	
			sauvegarde_fichier(fichier,sauv,taille);
			fclose(fichier); // On ferme le fichier qui a été ouvert
	    }
	}
	
	if (strcmp(argv[1],"-ca") == 0 )
	{
		fichier = fopen(argv[2], "a");
		
		if (fichier == NULL)
	    {
	    	printf("Impossible d'ouvrir le fichier texte");
	    }
	    if (fichier != NULL)
	    {   
	    	printf("%s\n",argv[2] );
			chargement_fichier(fichier);
			printf("DEBUT DU JEU\n");
			printf("\n");
			printf("\n");
			printf("\n");

			int x_depart = 0;
			int y_depart = 0;
			int x_fin = 0;
			int y_fin = 0;
			int direc = 0;
			int z = 0;
			char tab[taille];

			while(z < cpt_nbmot)
			{
				printf("Entrer coordonnée de debut : \n");
				do{
					printf("x_depart= ");
					x_depart = saisie();

				}while(x_depart < 0 || x_depart >=  taille);
				 
				do
				{
					printf("y_depart= ");
					y_depart = saisie();

				}while(y_depart < 0 || y_depart >= taille);
				 
				printf("Entrer coordonnée de fin : \n");
				do
				{
					printf("x_fin= ");
					x_fin = saisie();

				}while(x_fin < 0 || x_fin >= taille);
				
				do
				{
					printf("y_fin = ");
					y_fin = saisie();

				}while(y_fin< 0 || y_fin >= taille);
				reboot_tableau(tab,taille);
				direc = trouve_direction(x_depart,y_depart,x_fin,y_fin);
				printf("direction %d\n",direc );

				selection(monde,tab,taille,x_depart,y_depart,x_fin,y_fin,direc);

				if (test_supprime(sauv,tab,taille,cpt_nbmot) == 1)
				{
					miniscule_mot(monde,direction,x_depart,y_depart,x_fin,y_fin);
					affichage(monde,taille);
				}
				z++;
			}
		}
		fclose(fichier); // On ferme le fichier qui a été ouvert	
	}
	if (strcmp(argv[1],"-cg") == 0)
	{
		/*CREATION DE LA FENETRE*/
		int width =TAILLE_CASE*taille*2;
		int height = TAILLE_CASE*taille;
		int trouve = 0;
		int sens = 0;
		char tab_per[taille];
		char ta[2]={0};
		int a = 0;
		int b = 0;
		int x1 = 0;
		int y1 = 0;
		int valeur_x1=0; /*valeur pour le calcul de la hitbox pour l'interface graphique abcisse */
		int valeur_y1=0; /*valeur pour le calcul de la hitbox pour l'interface graphique ordonné */
		int valeur_x2=0; /*valeur pour le calcul de la hitbox pour l'interface graphique abcisse */
		int valeur_y2=0; /*valeur pour le calcul de la hitbox pour l'interface graphique ordonné */
		Point p1;
		Point p2;
		Droite d;

		MLV_create_window( "Mot", "mot",width, height);
		MLV_clear_window(MLV_COLOR_WHITE);
		MLV_actualise_window();

		/*CREATION DE LA GRILLE DE JEU*/
		/*GRILLE PRINCIPAL*/
		for (a = 0; a <taille ; ++a)
		{	
			for (b = 0; b <taille ; ++b)
			{
				ta[0]=monde[a][b];
				MLV_draw_text_box(x1,y1,TAILLE_CASE,TAILLE_CASE,&(ta[0]),9,MLV_COLOR_BLACK, MLV_COLOR_BLACK,
							MLV_COLOR_WHITE,MLV_TEXT_LEFT,MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER ); 		
				

				x1=x1+TAILLE_CASE;	
			}
			x1=0;
			y1=y1+TAILLE_CASE;
		}
		/*GRILLE DES MOTS A TROUVER*/
		a = 0;
		b = 0;
		x1 = TAILLE_CASE*taille;
		y1 = 0;

		for (a = 0; a <taille ; ++a)
		{	
			for (b = 0; b <taille ; ++b)
			{
				ta[0]=sauv[a][b];
				MLV_draw_text_box(x1,y1,TAILLE_CASE,TAILLE_CASE,&(ta[0]),9,MLV_COLOR_WHITE, MLV_COLOR_BLACK,
							MLV_COLOR_WHITE,MLV_TEXT_LEFT,MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER ); 		
				

				x1=x1+TAILLE_CASE;	
			}
			x1=TAILLE_CASE*taille;
			y1=y1+TAILLE_CASE;
		}
		MLV_actualise_window();

		while(trouve < cpt_nbmot)
		{
			saisiePoint(&p1);
			saisiePoint(&p2);
			valeur_x1= (p1.x)/TAILLE_CASE;
			valeur_y1= (p1.y)/TAILLE_CASE;
			valeur_x2= (p2.x)/TAILLE_CASE;
			valeur_y2= (p2.y)/TAILLE_CASE;
			sens = trouve_direction(valeur_y1,valeur_x1,valeur_y2,valeur_x2);
			printf("direction  = %d \n",trouve_direction(valeur_y1,valeur_x1,valeur_y2,valeur_x2));
			reboot_tableau(tab_per,taille);
			affichage(monde,taille);
			selection(monde,tab_per,taille,valeur_y1,valeur_x1,valeur_y2,valeur_x2,sens);
			printf("test = %d\n",test_supprime(sauv,tab_per,taille,cpt_nbmot));
			if (test_supprime(sauv,tab_per,taille,cpt_nbmot) == 1)
			{
				redessine_couleur(monde,valeur_x1,valeur_y1,valeur_x2,valeur_y2,sens);
				MLV_actualise_window();	
				trouve++;
			}
			
		}
		MLV_actualise_window();
		MLV_wait_seconds(100);
		MLV_free_window();
	}
	

	return 0;
}
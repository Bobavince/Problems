#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef MAP
#include <iostream>
using namespace std;
#endif

typedef struct Element
{
    struct Element * suivant;
    int valeur;
} Element;

typedef struct
{
    Element * debut; /* le début de la liste chaînée */
    Element * fin; /* le dernier élément de la liste */
} File;

void EnFile(File * file, int valeur);
int DeFile(File * file);
int EstVide(File file);
void Init(File * file);
void Destroy(File file);
void Afficher(File *file);

void error(void);

int main(void)
{
    int val;
    char lecture[100];
    File file;

    Init(&file);

    if (fscanf(stdin, "%99s", lecture) != 1)
        error();
    while (strcmp(lecture, "bye") != 0)
    {
        if (strcmp(lecture, "enfile") == 0)
        {
            if (fscanf(stdin, "%99s", lecture) != 1)
                error();
            val = atoi(lecture);
            EnFile(&file, val);
#ifdef MAP
            Afficher(&file);
#endif
        }
        else if (strcmp(lecture, "defile") == 0)
        {
            val = DeFile(&file);
            printf("%d\r\n", val);
#ifdef MAP
            Afficher(&file);
#endif
        }
        else if (strcmp(lecture, "estvide") == 0)
        {
            printf("%s\r\n", EstVide(file) ? "oui" : "non");
#ifdef MAP
            Afficher(&file);
#endif
        }

        if (fscanf(stdin, "%99s", lecture) != 1)
            error();
    }
    Destroy(file);
    return 0;
}

#ifdef MAP
void Afficher(File *file)
{
    cout << "==DEBUT AFFICHAGE==" << endl;
    //Si il y a quelques chose dedans
    if (file->debut != NULL && file->fin != NULL)
    {
        Element * courant = file->debut;

        while (courant != NULL)
        {
            printf("Valeur :");
            printf("%d\r\n", courant->valeur);
            courant = courant->suivant;
        }
    }
    else
    {
        printf("File Vide\r\n");
    }
    cout << "==FIN AFFICHAGE==" << endl;

}
#endif

void EnFile(File * file, int valeur)
/* cette procédure enfile valeur dans la file */
/*  - file est un pointeur sur la structure de données File et
 *    représente une file bien formée 
 *  - valeur est la valeur à insérer */
{
    // On alloue notre nouvel élément
    Element * nouveau = (Element *) malloc(sizeof (Element));

    //On lui attribut sa valeurs
    nouveau->valeur = valeur;

    //Si la file est vide
    if (file->fin == NULL && file->debut == NULL)
    {
        nouveau->suivant = NULL;
        file->debut = nouveau;
        file->fin = nouveau;
    }
    else
    { // il y a au moins un élément.
        nouveau->suivant = file->debut;
        file->debut = nouveau;
    }

    /* insérer le code ici */
}

int DeFile(File * file)
/* cette fonction défile la valeur et la renvoie */
/*  - file est un pointeur sur la structure de données File et
 *    représente une file bien formée 
 *  - si la file est vide la valeur 0 est renvoyée */
{
    int valeur = 0;

    //Si il y a au moins un élément
    if (file->debut != NULL && file->fin != NULL)
    {
        //On récupère la valeur de l'élement "fin"
        valeur = file->fin->valeur;
        //On le stocke cet élément dans un temporaire
        Element * TMP = file->fin;

        //Si cet élément était le dernier
        if (file->debut == file->fin)
        {
            //Si c'est la dernière case, on met tout à NULL
            file->debut = NULL;
            file->fin = NULL;
        }
        else //il y a au moins 2 cases
        {
            //On trouve l'avant dernier : 
            Element * courant = file->debut;

            while (courant->suivant->suivant != NULL)
            {
#ifdef MAP
                cout << "Courant : " << courant->valeur << endl;
                cout << "le suivant de courant : " << courant->suivant->valeur << endl;
                cout << "le suivant de suivant de courant  : " << courant->suivant->suivant->valeur << endl;
#endif
                courant = courant->suivant;
            }
#ifdef MAP
            cout << "L'avant dernier élément a donc pour valeur :" << courant->valeur << endl;
#endif
            //Sinon, on dit que la nouvelle fin est l'avant dernier:
            file->fin = courant;
            file->fin->suivant = NULL;
#ifdef MAP
            cout << "L'avant dernier élément a donc pour valeur :" << courant->valeur << endl;
#endif
        }

        //On vide la mémoire de l'élément qu'on a retiré.
        free(TMP);
    }

    return valeur;
    /* insérer le code ici */
}

int EstVide(File file)
/* cette fonction indique si la file est vide */
/*  - file est de type File et représente une file bien formée
 *  - la valeur renvoyée vaut 1 si la file est vide, 0 sinon */
{
    int estVide = 0;

    if (file.debut == NULL && file.fin == NULL)
    {
        estVide = 1;
    }

    return estVide;
    /* insérer le code ici */
}

void Init(File * file)
{
    file->debut = NULL;
    file->fin = NULL;
}

void Destroy(File file)
{
    Element * courant = file.debut;
    Element * suivant;
    while (courant != NULL)
    {
        suivant = courant->suivant;
        free(courant);
        courant = suivant;
    }
}

void error(void)
{
    printf("input error\r\n");
    exit(0);
}

//
//void EnFile(File * file, int valeur)
///* cette procédure enfile valeur dans la file */
///*  - file est un pointeur sur la structure de données File et
// *    représente une file bien formée 
// *  - valeur est la valeur à insérer */
//{
//    // On alloue notre nouvel élément
//    Element * nouveau = (Element *) malloc(sizeof (Element));
//
//    //On lui attribut ses valeurs
//    nouveau->valeur = valeur;
//    nouveau->suivant = file->debut;
//
//    // On dit que c'est désormais le début de la file.
//    file->debut = nouveau;
//
//    //Si c'est la seule case
//    if (file->fin == NULL)
//    {
//        //On dit également que c'est la fin de la file.
//        file->fin = nouveau;
//    }
//    /* insérer le code ici */
//}
//
//int DeFile(File * file)
///* cette fonction défile la valeur et la renvoie */
///*  - file est un pointeur sur la structure de données File et
// *    représente une file bien formée 
// *  - si la file est vide la valeur 0 est renvoyée */
//{
//    int valeur = 0;
//
//    //Si il y a au moins un élément
//    if (file->debut != NULL && file->fin != NULL)
//    {
//        //On récupère la valeur de l'élement "début"
//        valeur = file->debut->valeur;
//        //On le stocke cet élément dans un temporaire
//        Element * TMP = file->debut;
//
//        //Si cet élément était le dernier
//        if (file->debut == file->fin)
//        {
//            //Si c'est la dernière case, on met tout à NULL
//            file->debut = NULL;
//            file->fin = NULL;
//        }
//        else
//        {
//            //Sinon, on dit que le nouveau début est son suivant
//            file->debut = file->debut->suivant;
//        }
//
//        //On vide la mémoire de l'élément qu'on a retiré.
//        free(TMP);
//    }
//
//    return valeur;
//    /* insérer le code ici */
//}
//
//int EstVide(File file)
///* cette fonction indique si la file est vide */
///*  - file est de type File et représente une file bien formée
// *  - la valeur renvoyée vaut 1 si la file est vide, 0 sinon */
//{
//    int estVide = 0;
//
//    if (file.debut == NULL && file.fin == NULL)
//    {
//        estVide = 1;
//    }
//
//    return estVide;
//    /* insérer le code ici */
//}
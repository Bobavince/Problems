/* 
 * File:   main.cpp
 * Author: zettanux
 *
 * Created on 26 novembre 2016, 11:17
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
static void AjouterListe(int valeur, int tableau[], int tailleTableau);
static void AffichageListe(int valeurs[], int taille);

int main()
{
    int nbCases;
    cin >> nbCases;
#ifdef MAP
    cout << "Il y aura " << nbCases << " valeurs " << endl;
#endif
    //On pose un tableau de cette taille
    double liste[nbCases];

    //variables pour trouver le max
    double valTMP = 0;
    int maxTMP = 0;
    int max = 0;

    for (int i = 0; i < nbCases; i++)
    {
        //on récupère la valeur
        cin >> liste[i];
#ifdef MAP
        cout << "On ajoute : " << liste[i] << endl;
#endif
        //On met la première valeur dans le TMP
        if (i == 0)
        {
            valTMP = liste[0];
        }
#ifdef MAP
        cout << "VALTMP vaut actuellement : " << valTMP << endl;
#endif
        // si la valeur entrée est contiguë avec la précédente
        if (liste[i] == valTMP)
        {
            // TMP est donc présente +1 fois.
            maxTMP++;
#ifdef MAP
            cout << "La valeur : " << liste[i] << " est égale à " << valTMP << " MaxTMP vaut donc " << maxTMP << endl;
#endif
        }
        else //Valeur pas contiguë
        {
            //On pose une nouvelle valeur TMP
            valTMP = liste[i];
#ifdef MAP
            cout << "La valeur : " << liste[i] << " est la nouvelle valTMP" << endl;
#endif
            //On range le maxTMP dans le max global, si il est plus grand
            if (maxTMP > max)
            {
                max = maxTMP;
#ifdef MAP
                cout << "le max global est mainteant : " << max << endl;
#endif
            }

            // le max TMP est de 1 (on vient de croiser la nouvelle valeur)
            maxTMP = 1;
        }
        //Si c'était le dernier tour 
        if (i == nbCases - 1)
        {
            if (maxTMP > max)
            {
                max = maxTMP;
#ifdef MAP
                cout << "le max global est mainteant : " << max << endl;
#endif
            }
        }
        //AjouterListe(liste[i], listeTrie, i + 1);
    }

    printf("%d\r\n", max);
    //cout << max << "\r\n";
    return 0;
}

/*
int main()
{
    int nbCases;
    cin >> nbCases;

    int liste[nbCases];
    int listeTrie[nbCases];

    for (int i = 0; i < nbCases; i++)
    {
        cin >> liste[i];
        //AjouterListe(liste[i], listeTrie, i + 1);
    }

    int valTMP = liste[0];
    int maxTMP = 0;
    int max = 0;

    for (int i = 1; i < nbCases; i++)
    {
        if (liste[i] == valTMP)
        {
            maxTMP++;
        }
        else
        {
            valTMP = liste[i];
            if (maxTMP > max)
            {
                max = maxTMP;
            }
            maxTMP = 1;
        }
    }
        printf("%d", max);
    //cout << max << "\r\n";
    return 0;
}


static void AjouterListe(int valeur, int tableau[], int tailleTableau)
{
    bool decalage = false;
    int TMPINT = 0, TMPINT2 = 0;

    for (int i = 0; i < tailleTableau; i++)
    {
#ifdef MAP
        cout << "Boucle N° : " << i << endl;
#endif
        if (decalage)
        {
#ifdef MAP
            cout << "Décaler : " << TMPINT << " à la place de " << tableau[i] << endl;
#endif
            //Idem avec les scores
            TMPINT2 = tableau[i];
            tableau[i] = TMPINT;
            TMPINT = TMPINT2;
        }
        else if (valeur < tableau[i])
        {
#ifdef MAP
            cout << "On a trouvé où insérer : " << valeur << " à la place de " << tableau[i] << endl;
#endif
            decalage = true;
            //On garde la valeur qui était dans le tableau, et on insère notre valeur
            TMPINT = tableau[i];
            tableau[i] = valeur;

        }
        else if (i == tailleTableau)
        {
#ifdef MAP
            cout << "On insère à la fin : " << valeur << " à la place N° " << i << endl;
#endif
            //Idem avec les scores
            tableau[i] = valeur;
        }
    }

#ifdef MAP
    AffichageListe(tableau, tailleTableau);
#endif
}

static void AffichageListe(int valeurs[], int taille)
{
    cout << "== AFFICHAGE ==" << endl;
    //Affichage de la liste
    for (int i = 0; i < taille; i++)
    {
        cout << " Element N°" << i << " : " << valeurs[i] << endl;
    }
    cout << "== FIN AFFICHAGE ==" << endl;
}
 * 
 * */
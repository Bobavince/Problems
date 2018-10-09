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
    const int nbCasesHistogramme = 21;
    int nbCases;
    cin >> nbCases;

    //Stocke les valeurs entrées
    double liste[nbCases];
    //Stocke l'histogramme
    int listeHistogramme[nbCasesHistogramme];

    //Remise à 0 du tableau
    for (int i = 0; i < nbCasesHistogramme; i++)
    {
        listeHistogramme[i] = 0;
    }

    //récupération des entrées
    for (int i = 0; i < nbCases; i++)
    {
        //On récupère la valeur
        cin >> liste[i];
        
        //Si elle est correcte
        if (liste[i] >= 0 && liste[i] <= 20)
        {
            //On voit où on la met, par cast.
            int numCase = (int) (liste[i]);
#ifdef MAP
            cout << "Case N° : " << (int) (liste[i]) << " de valeur actuelle " << listeHistogramme[(int) (liste[i])] << endl;
#endif
            //On la met dans l'histogramme
            listeHistogramme[numCase]++;
        }
    }

    for (int i = 0; i < nbCasesHistogramme; i++)
    {
        //printf("%f\r\n", listeHistogramme[i]);
        cout << listeHistogramme[i] << "\r\n" ;
    }
    //AffichageListe(listeCorrecte, nbCasesTotale);
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
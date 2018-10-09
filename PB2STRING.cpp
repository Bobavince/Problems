#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#define MAX_TEXT_LENGTH 2048+1

static int isInside(string liste[], string aChercher, int tailleListe);
static void AffichageListe(string liste[], int valeurs[], int taille);
static void AjouterListe(string liste[], int valeurs[], string aPlacer, int tailleListe);

int main()
{
    string text;

    cin >> text;

    int nbCasesPrises = 0;
    string liste[512];
    int valeurs[512];

    string TMPstring;
    int tmpInt = 0;

    for (int nPos = 0; nPos < text.size()/4+1; nPos++)
    {
#ifdef MAP
    cout << "on coupe à partir de : " << 4 * nPos<< endl;
#endif
        TMPstring = text.substr(4 * nPos, 3);
#ifdef MAP
    cout << "on a  : " << TMPstring << endl;
#endif
        //-1 si elle n'est pas dedans, sinon, l'indice de la case où il est.
        tmpInt = isInside(liste, TMPstring, nbCasesPrises);

        if (tmpInt ==-1)
        {
            //La chaine est pas encore dedans, on l'ajoute.
            AjouterListe(liste, valeurs, TMPstring, nbCasesPrises);
            nbCasesPrises++;
        }
        else
        {
            valeurs[tmpInt]++;
        }
    }
    
    int max = 0;
    for (int i = 0; i < nbCasesPrises; i++)
    {
        if (valeurs[i] > max)
        {
            max = valeurs[i];
        }
    }

    cout << max << "\r\n";

    for (int i = 0; i < nbCasesPrises; i++)
    {
        if (valeurs[i] == max)
        {
            cout << liste[i] << "\r\n";
        }
    }
    return 0;
}

static int isInside(string liste[], string aChercher, int tailleListe)
{
#ifdef MAP
    cout << "== Appel de ISINSIDE ==" << endl;
#endif
    for (int i = 0; i < tailleListe; i++)
    {
#ifdef MAP
        cout << "on compare " << liste[i] << " avec : " << aChercher << " en tentative : " << i << endl;
#endif
        if (liste[i] == aChercher)
        {
#ifdef MAP
            cout << "Oui : " << liste[i] << " égale à" << aChercher << endl;
#endif
            //Pour aller plus vite si besoin, on peut renvoyer directement le résultat.
#ifdef MAP
            cout << "FIN de ISINSIDE, renvoi : " << i << endl;
#endif
            return i;
        }
    }
    return -1;
}

static void AffichageListe(char* liste[], int valeurs[], int taille)
{
    cout << "== AFFICHAGE ==" << endl;
    //Affichage de la liste
    for (int i = 0; i < taille; i++)
    {
        cout << " Element N°" << i << " : " << liste[i] << endl;
        cout << " valeur associée : " << valeurs[i] << endl;
    }
    cout << "== FIN AFFICHAGE ==" << endl;
}

static void AjouterListe(string liste[], int valeurs[], string aPlacer, int tailleListe)
{
    bool doitDecaler = false;

    string TMP;
    string TMP2;

    int TMPINT;
    int TMPINT2;

#ifdef MAP
    cout << "== Début ajouter liste == " << endl;
    cout << "La liste fait " << tailleListe << endl;
#endif
    for (int i = 0; i < tailleListe + 1; i++)
    {
#ifdef MAP
        cout << "tour N°" << i << endl;
#endif
        if (doitDecaler)
        {
#ifdef MAP
            cout << "Décaler : " << TMP << " à la place de " << liste[i] << endl;
#endif
            TMP2 = liste[i];
            liste[i] = TMP;
            TMP = TMP2;
            //Idem avec les scores
            TMPINT2 = valeurs[i];
            valeurs[i] = TMPINT;
            TMPINT = TMPINT2;

        }
        else if (liste[i] > aPlacer)
        {
#ifdef MAP
            cout << "On a trouvé où insérer : " << aPlacer << " à la place de " << liste[i] << endl;
#endif
            TMP = liste[i];
            liste[i] = aPlacer;
            doitDecaler = true;
            //Idem avec les scores
            TMPINT = valeurs[i];
            valeurs[i] = 1;

        }
        else if (i == tailleListe)
        {
#ifdef MAP
            cout << "On insère à la fin : " << aPlacer << " à la place N° " << i << endl;
#endif
            liste[i] = aPlacer;
            //Idem avec les scores
            valeurs[i] = 1;
        }
    }
}
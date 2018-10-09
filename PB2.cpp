#include <iostream>
using namespace std;
#include <stdio.h>
#include <string.h>
#define MAX_TEXT_LENGTH 2048+1

static int isInside(string liste[], string aChercher, int tailleListe);
static int isInside(char* liste[], char* aChercher, int tailleListe);
static void AffichageListe(char* liste[], int valeurs[], int taille);
static void AjouterListe(char* liste[], int valeurs[], char* aPlacer, int tailleListe);

int main()
{
    char text[MAX_TEXT_LENGTH];

    cin >> text;

    int nbCasesPrises = 0;
    char* liste[512];
    int valeurs[512];

    char TMPstring [4];
    int tmpInt = 0;

    for (int nPos = 0; nPos < MAX_TEXT_LENGTH; nPos++)
    {
        if (text[nPos] == '-' || text[nPos] == '\0')
        {
            //On stocke la chaine courante
            for (int j = 0; j < 3; j++)
            {
                TMPstring[j] = text[nPos - 3 + j];
            }
            TMPstring[3] = '\0';
#ifdef MAP
            cout << " chaine courante : " << TMPstring << endl;
#endif

            tmpInt = isInside(liste, TMPstring, nbCasesPrises);

            if (tmpInt == -1)
            {
                //La chaine est pas encore dedans, on l'ajoute.
                AjouterListe(liste, valeurs, TMPstring, nbCasesPrises);
                nbCasesPrises++;
            }
            else
            {
                //Elle est déjà dedans, on l'incrémente : 
                valeurs[tmpInt]++;
#ifdef MAP
                cout << "Incrémenté à : " << valeurs[tmpInt] << endl;
#endif
            }
#ifdef MAP
            AffichageListe(liste, valeurs, nbCasesPrises);
#endif
        }

        if (text[nPos] == '\0') //end of the text
        {
            break;
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

static int isInside(char* liste[], char* aChercher, int tailleListe)
{
    int answer = -1;
#ifdef MAP
    cout << "== Appel de ISINSIDE ==" << endl;
#endif
    for (int i = 0; i < tailleListe; i++)
    {
#ifdef MAP
        cout << "on compare " << liste[i] << " avec : " << aChercher << " en tentative : " << i << endl;
        cout << "Resultat du strcmp : " << strcmp(liste[i], aChercher) << endl;
#endif

        if (!strcmp(liste[i], aChercher))
        {
#ifdef MAP
            cout << "Oui : " << liste[i] << " égale à" << aChercher << endl;
#endif
            (answer == -1) ? answer = 0 : answer++;

            //Pour aller plus vite si besoin, on peut renvoyer directement le résultat.
#ifdef MAP
            cout << "FIN de ISINSIDE, renvoi : " << i << endl;
#endif
            return i;
        }
    }
#ifdef MAP
    cout << "== FIN de ISINSIDE, renvoi : " << answer << " ==" << endl;
#endif
    return answer;
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

static void AjouterListe(char* liste[], int valeurs[], char* aPlacer, int tailleListe)
{
    bool doitDecaler = false;

    char TMP[3 + 1];
    char TMP2[3 + 1];

    int TMPINT;
    int TMPINT2;

    liste[tailleListe] = new char[3 + 1];
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
            strcpy(TMP2, liste[i]);
            strcpy(liste[i], TMP);
            strcpy(TMP, TMP2);
            //Idem avec les scores
            TMPINT2 = valeurs[i];
            valeurs[i] = TMPINT;
            TMPINT = TMPINT2;

        }
        else if (strcmp(liste[i], aPlacer) > 0)
        {
#ifdef MAP
            cout << "On a trouvé où insérer : " << aPlacer << " à la place de " << liste[i] << endl;
#endif
            strcpy(TMP, liste[i]);
            strcpy(liste[i], aPlacer);
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
            strcpy(liste[i], aPlacer);
            //Idem avec les scores
            valeurs[i] = 1;
        }
    }
}
/*
static int isInside(string liste[], string aChercher, int tailleListe)
{
    int answer = 0;
    for (int i = 0; i < tailleListe; i++)
    {
        if (liste[i] == aChercher)
        {
            answer++;
            //Pour aller plus vite si besoin, on peut renvoyer directement le résultat.
            return answer;
        }
    }

    return answer;
}

static int[] getCode(string chaine){
    
    return;
}
 
 // AVEC DES STRINGS ? 
 
 int main()
{
    char text[MAX_TEXT_LENGTH];
    string textInput;

    cin >> textInput;
    
    int nbCasesPrises = 0;
    //char* liste[512];
    string liste[512];
    int valeurs[512];

    string tmp;
    int tmpInt = 0;

    int nbPosPrec = 0;
    for (int nPos = 0; nPos < MAX_TEXT_LENGTH; nPos++)
    {
        if (textInput[nPos] == '-')
        {
            //On récupère la chaine courante
            tmp = textInput.substr(nbPosPrec, 3);
            tmpInt = isInside(liste, tmp, nbCasesPrises);
            
            cout << " chaine courante : " <<  tmp << endl;
                    
            if (tmpInt == 0)
            {
                //La chaine est pas encore dedans, on l'ajoute.
                liste[nbCasesPrises] = tmp;
                valeurs[nbCasesPrises]++;
                nbCasesPrises++;
            }
            else
            {
                //Elle est déjà dedans, on l'incrémente : 
                valeurs[nbCasesPrises]++;
            }
            //On prépare le tour suivant : 
            nbPosPrec = nPos;
        }

        if (text[nPos] == '\0') //end of the text
        {
            break;
        }
    }

    int max;
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
    /*
    //votre code ...
    // ...
    int nFreq = 10;
    char mot[] = "ABA";

    cout << nFreq << "\r\n";
    cout << mot << "\r\n";
return 0;
}


 */
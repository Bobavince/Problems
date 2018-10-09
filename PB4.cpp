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

int main()
{
    char* mot1 = new char[257];
    char* mot2 = new char[257];
    bool crible[257];

    cin >> mot1;
    cin >> mot2;

    int longueurMot1 = strlen(mot1);
#ifdef MAP
    cout << " Chaine 1 : " << mot1 << endl;
    cout << " Chaine 2 : " << mot2 << endl;
    cout << " Longueur 1 : " << longueurMot1 << endl;
    cout << " Longueur 1 : " << strlen(mot2) << endl;
#endif
    bool isAnagrama = true;

    if (longueurMot1 == strlen(mot2))
    {
        for (int i = 0; i < longueurMot1; i++)
        {
#ifdef MAP
            cout << " == Nouvelle lettre du mot 1 == " << endl;
            cout << " On considère la lettre du mot1 : " << mot1[i] << endl;
#endif
            for (int j = 0; j < longueurMot1; j++)
            {
#ifdef MAP
                cout << " On considère la lettre du mot2 : " << mot2[j] << endl;
                cout << " Le crible a pour statut : " << crible[j] << endl;
#endif
                if (mot1[i] == mot2[j] && crible[j] == false)
                {
                    crible[j] = true;
#ifdef MAP
                    cout << " On a criblé la case du " << mot2[j] << " N° " << j << endl;
                    cout << " ==== Affichage du crible actuel : ====" << endl;
                    for (int k = 0; k < longueurMot1; k++)
                    {
                        cout << "lettre " << mot2[k] << " statut " << crible[k] << endl;
                    }
#endif
                    break;
                }
            }
        }

        for (int j = 0; j < longueurMot1; j++)
        {
            if (crible[j] == false)
            {
                isAnagrama = false;
            }
        }
    }
    else
    {
        isAnagrama = false;
    }



    delete(mot1);
    delete(mot2);

    cout << (isAnagrama ? "YES" : "NO") << "\n";
    return 0;
}
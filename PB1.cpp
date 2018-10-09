/* 
 * File:   main.cpp
 * Author: zettanux
 *
 * Created on 26 novembre 2016, 11:17
 */

#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int nMeasures = 0, nbNegatives = 0;
    long double sum = 0;
    cin >> nMeasures;

    for (int nPos = 0; nPos < nMeasures; nPos++)
    {
        float fValue = 0;
        cin >> fValue;
        if (fValue <= 0)
        {
            nbNegatives++;
            sum += fValue;

            //cout.precision(10);
            //cout << "Valeur ajoutée : " << fValue << " pour " << sum << endl;
        }
    }

    if (nbNegatives == 0)
    {
        cout << "-" << "\r\n";

    }
    else
    {
        float fAverage = sum / nbNegatives;
        printf("%f", fAverage); // affiche 8 décimales
        cout << "\r\n";
        //cout.precision(150);
        //cout << fAverage << "\r\n";
    }

    return 0;
}
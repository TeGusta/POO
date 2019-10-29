// Proiect POO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//h2 - risk of death due to other causes
//S2 - probability of surviving death due to other causes 
//S1 - probability of surviving death due to breast cancer
//a - baseline age
//teta - number of years between the baseline age and the predicted age
//F - ?
//ro[i][t] - proportion of women of age t that are in risk group i
//h1_1 - age specific breast cancer composit incidnte
//h1 - baseline age specific hazard of developing breast cancer
//r[i][t] - relative risk of the i-th group compared to the baseline group

int main()
{
	double e = 2.71828182846;
	double P,h1,teta,delta,S1,S2,r;
	int a;
	double F[12] = { 0.5788413, 0.72949880, 0.5788413, 1.0, 1.0, 1.0, 0.5788413, 0.74397137, 0.5788413, 1.0, 1.0, 1.0 };
	for (int i = 0;i < 2;i++)
	{
		for (int j = 0;j < 6;j++)
		{
			printf("%.7f ", F[i * 6 + j]);
		}
		cout << endl;
	}
	cout << endl;

	double h1_1[84] = { 1.0E-5 , 0.00002696 , 2.00E-5 , 1.22E-5 , 0.00002696 , 2.00E-5 , 7.6E-5 , 0.00011295 , 7.10E-5 , 7.41E-5 , 0.00011295 , 7.10E-5 , 26.6E-5 , 0.00031094 , 19.70E-5 , 22.97E-5 , 0.00031094 , 19.70E-5 , 66.1E-5 , 0.00067639 , 43.80E-5 , 56.49E-5 , 0.00067639 , 43.80E-5 , 126.5E-5 , 0.00119444 , 81.10E-5 , 116.45E-5 , 0.00119444 , 81.10E-5 , 186.6E-5 , 0.00187394 , 130.70E-5 , 195.25E-5 , 0.00187394 , 130.70E-5 , 221.1E-5 , 0.00241504 , 157.40E-5 ,261.54E-5 , 0.00241504 , 157.40E-5  , 272.1E-5 , 0.00291112 , 185.70E-5 , 302.79E-5 , 0.00291112 , 185.70E-5 , 334.8E-5 , 0.00310127 , 215.10E-5 , 367.57E-5 , 0.00310127 , 215.10E-5 , 392.3E-5 , 0.0036656 , 251.20E-5 , 420.29E-5 , 0.0036656 , 251.20E-5 , 417.8E-5 , 0.00393132 , 284.60E-5 , 473.08E-5 , 0.00393132 , 284.60E-5 , 443.9E-5 , 0.00408951 , 275.70E-5 , 494.25E-5 , 0.00408951 , 275.70E-5 , 442.1E-5 , 0.00396793 , 252.30E-5 , 479.76E-5 , 0.00396793 , 252.30E-5 , 410.9E-5 , 0.00363712 , 203.90E-5 , 401.06E-5 , 0.00363712 , 203.90E-5 };
	for (int i = 0;i < 14;i++)
	{
		for (int j = 0;j < 6;j++)
		{
			printf("%.8f ", h1_1[i * 6 + j]);
		}
		cout << endl;
	}
	cout << endl;

	double h2[84] = { 49.3E-5 , 0.00074354 , 43.7E-5 , 44.12E-5 , 0.00074354 , 43.7E-5 , 53.1E-5 , 0.00101698 , 53.3E-5 , 52.54E-5 , 0.00101698 , 53.3E-5 , 62.5E-5 , 0.00145937 , 70.0E-5 , 67.46E-5 , 0.00145937 , 70.0E-5 , 82.5E-5 , 0.00215933 , 89.7E-5 , 90.92E-5 , 0.00215933 , 89.7E-5 , 130.7E-5 , 0.00315077 , 116.3E-5 , 125.34E-5 , 0.00315077 , 116.3E-5 , 218.1E-5 , 0.00448779 , 170.2E-5 , 195.70E-5 , 0.00448779 , 170.2E-5 , 365.5E-5 , 0.00632281 , 264.6E-5 , 329.84E-5 , 0.00632281 , 264.6E-5 , 585.2E-5 , 0.00963037 , 421.6E-5 , 546.22E-5 , 0.00963037 , 421.6E-5 , 943.9E-5 , 0.01471818 , 696.0E-5 , 910.35E-5 , 0.01471818 , 696.0E-5 , 1502.8E-5 , 0.02116304 , 1086.7E-5 , 1418.54E-5 , 0.02116304 , 1086.7E-5 , 2383.9E-5 , 0.03266035 , 1685.8E-5 , 2259.35E-5 , 0.03266035 , 1685.8E-5 , 3883.2E-5 , 0.04564087 , 2515.6E-5 , 3611.46E-5, 0.04564087 , 2515.6E-5 , 6682.8E-5 , 0.06835185 , 4186.6E-5 , 6136.26E-5 , 0.06835185 , 4186.6E-5 , 14490.8E-5 , 0.13271262 , 8947.6E-5 , 14206.63E-5 , 0.13271262 , 8947.6E-5 };
	for (int i = 0;i < 14;i++)
	{
		for (int j = 0;j < 6;j++)
		{
			printf("%.8f ", h2[i * 6 + j]);
		}
		cout << endl;
	}
	cout << endl;

	/*cout << "Introduceti varsta pacientului (>35): ";
	//cin >> a;
	for (int j = a;j <= a + teta;j++)
	{
		P = ((h1[j] * r[j]) / (h1[j] * r[j] + h2[j])) * ((S1[teta[j - 1]]) / (S1[a])) * ((S2[teta[j - 1]]) / (S2[a])) * (1 - e ^ ((-1) * (delta[j] * (h1[j] * r[j] + h2[j]))));
	}*/
}


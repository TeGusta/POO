// Proiect POO.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <fstream>
using namespace std;

fstream fs("indici.txt");
ifstream fin("indici.txt");
ofstream fout("risc.txt");

class IndiceRisk
{
	double t[15];
	double h2[14][12];
	double h1_1[14][12];
	double beta[8][12];
	double beta2[8];
	double h[14];
	double rlan[14] = { 0.0 };
	double rf[2] = { 0.0 };
	double rf2[2][13] = { 0.0 };
	double sumb[216] = { 0.0 };
	double sumbb[216] = { 0.0 };
	double abs[216] = { 0.0 };

public:
	IndiceRisk()
	{
		/* Age Categories */

		t[0] = 20.0;
		t[1] = 25.0;
		t[2] = 30.0;
		t[3] = 35.0;
		t[4] = 40.0;
		t[5] = 45.0;
		t[6] = 50.0;
		t[7] = 55.0;
		t[8] = 60.0;
		t[9] = 65.0;
		t[10] = 70.0;
		t[11] = 75.0;
		t[12] = 80.0;
		t[13] = 85.0;
		t[14] = 90.0;


		h2[0][0] = 49.3 * 0.00001;       // [20:25) race = white, other 
		h2[1][0] = 53.1 * 0.00001;       // [25:30) race = white, other  
		h2[2][0] = 62.5 * 0.00001;       // [30:35) race = white, other
		h2[3][0] = 82.5 * 0.00001;       // [35:40) race = white, other
		h2[4][0] = 130.7 * 0.00001;      // [40:45) race = white, other
		h2[5][0] = 218.1 * 0.00001;      // [45:50) race = white, other
		h2[6][0] = 365.5 * 0.00001;      // [50:55) race = white, other
		h2[7][0] = 585.2 * 0.00001;      // [55:60) race = white, other
		h2[8][0] = 943.9 * 0.00001;      // [60:65) race = white, other
		h2[9][0] = 1502.8 * 0.00001;     // [65:70) race = white, other
		h2[10][0] = 2383.9 * 0.00001;    // [70:75) race  = white, other
		h2[11][0] = 3883.2 * 0.00001;    // [75:80) race = white, other
		h2[12][0] = 6682.8 * 0.00001;    // [80:85) race = white, other
		h2[13][0] = 14490.8 * 0.00001;   // [85:90) race = white, other

		h2[0][1] = 0.00074354;    //  [20, 25) race = African American
		h2[1][1] = 0.00101698;    //  [24, 30) race = African American
		h2[2][1] = 0.00145937;    //  [30, 35) race = African American
		h2[3][1] = 0.00215933;    //  [34, 40) race = African American
		h2[4][1] = 0.00315077;    //  [40, 45) race = African American
		h2[5][1] = 0.00448779;    //  [44, 50) race = African American
		h2[6][1] = 0.00632281;    //  [50, 55) race = African American
		h2[7][1] = 0.00963037;    //  [54, 60) race = African American
		h2[8][1] = 0.01471818;    //  [60, 65) race = African American
		h2[9][1] = 0.02116304;    //  [64, 70) race = African American
		h2[10][1] = 0.03266035;   //  [70, 75) race = African American
		h2[11][1] = 0.04564087;   //  [74, 80) race = African American
		h2[12][1] = 0.06835185;   //  [80, 84) race = African American
		h2[13][1] = 0.13271262;   //  [84, 90) race = African American

		h2[0][2] = 43.7 * 0.00001;      // [20:25) race = hispanic    
		h2[1][2] = 53.3 * 0.00001;      // [25:30) race = hispanic     
		h2[2][2] = 70.0 * 0.00001;      // [30:35) race = hispanic
		h2[3][2] = 89.7 * 0.00001;      // [35:40) race = hispanic
		h2[4][2] = 116.3 * 0.00001;     // [40:45) race = hispanic
		h2[5][2] = 170.2 * 0.00001;     // [45:50) race = hispanic
		h2[6][2] = 264.6 * 0.00001;     // [50:55) race = hispanic
		h2[7][2] = 421.6 * 0.00001;     // [55:60) race = hispanic
		h2[8][2] = 696.0 * 0.00001;     // [60:65) race = hispanic
		h2[9][2] = 1086.7 * 0.00001;    // [65:70) race = hispanic
		h2[10][2] = 1685.8 * 0.00001;   // [70:75) race = hispanic
		h2[11][2] = 2515.6 * 0.00001;   // [75:80) race = hispanic
		h2[12][2] = 4186.6 * 0.00001;   // [80:85) race = hispanic
		h2[13][2] = 8947.6 * 0.00001;   // [85:90) race = hispanic
			
		h2[0][3] = 44.12 * 0.00001;        // [20,25) race=white,other 
		h2[1][3] = 52.54 * 0.00001;        // [24,30) race=white,other
		h2[2][3] = 67.46 * 0.00001;        // [30,35) race=white,other
		h2[3][3] = 90.92 * 0.00001;        // [34,40) race=white,other
		h2[4][3] = 125.34 * 0.00001;       // [40,45) race=white,other
		h2[5][3] = 195.70 * 0.00001;       // [44,50) race=white,other
		h2[6][3] = 329.84 * 0.00001;       // [50,55) race=white,other
		h2[7][3] = 546.22 * 0.00001;       // [54,60) race=white,other
		h2[8][3] = 910.35 * 0.00001;       // [60,65) race=white,other
		h2[9][3] = 1418.54 * 0.00001;      // [64,70) race=white,other
		h2[10][3] = 2259.35 * 0.00001;     // [70,75) race=white,other
		h2[11][3] = 3611.46 * 0.00001;     // [74,80) race=white,other
		h2[12][3] = 6136.26 * 0.00001;     // [80,84) race=white,other
		h2[13][3] = 14206.63 * 0.00001;    // [84,90) race=white,other

		h2[0][4] = 0.00074354;    // [20, 25) race = African American        
		h2[1][4] = 0.00101698;    // [24, 30) race = African American
		h2[2][4] = 0.00145937;    // [30, 35) race = African American
		h2[3][4] = 0.00215933;    // [34, 40) race = African American
		h2[4][4] = 0.00315077;    // [40, 45) race = African American
		h2[5][4] = 0.00448779;    // [44, 50) race = African American
		h2[6][4] = 0.00632281;    // [50, 55) race = African American
		h2[7][4] = 0.00963037;    // [54, 60) race = African American
		h2[8][4] = 0.01471818;    // [60, 65) race = African American
		h2[9][4] = 0.02116304;    // [64, 70) race = African American
		h2[10][4] = 0.03266035;   // [70, 75) race = African American
		h2[11][4] = 0.04564087;   // [74, 80) race = African American
		h2[12][4] = 0.06835185;   // [80, 84) race = African American
		h2[13][4] = 0.13271262;   // [84, 90) race = African American

		h2[0][5] = 43.7 * 0.00001;      // [20:25) race = hispanic        
		h2[1][5] = 53.3 * 0.00001;      // [25:30) race = hispanic
		h2[2][5] = 70.0 * 0.00001;      // [30:35) race = hispanic
		h2[3][5] = 89.7 * 0.00001;      // [35:40) race = hispanic
		h2[4][5] = 116.3 * 0.00001;     // [40:45) race = hispanic
		h2[5][5] = 170.2 * 0.00001;     // [45:50) race = hispanic
		h2[6][5] = 264.6 * 0.00001;     // [50:55) race = hispanic
		h2[7][5] = 421.6 * 0.00001;     // [55:60) race = hispanic
		h2[8][5] = 696.0 * 0.00001;     // [60:65) race = hispanic
		h2[9][5] = 1086.7 * 0.00001;    // [65:70) race = hispanic
		h2[10][5] = 1685.8 * 0.00001;   // [70:75) race = hispanic
		h2[11][5] = 2515.6 * 0.00001;   // [75:80) race = hispanic
		h2[12][5] = 4186.6 * 0.00001;   // [80:85) race = hispanic
		h2[13][5] = 8947.6 * 0.00001;   // [85:90) race = hispanic




		h1_1[0][0] = 1.0 * 0.00001;         // [20:25) race = white, other       
		h1_1[1][0] = 7.6 * 0.00001;         // [25:30) race = white, other       
		h1_1[2][0] = 26.6 * 0.00001;        // [30:35) race = white, other
		h1_1[3][0] = 66.1 * 0.00001;        // [35:40) race = white, other
		h1_1[4][0] = 126.5 * 0.00001;       // [40:45) race = white, other
		h1_1[5][0] = 186.6 * 0.00001;       // [45:50) race = white, other
		h1_1[6][0] = 221.1 * 0.00001;       // [50:55) race = white, other
		h1_1[7][0] = 272.1 * 0.00001;       // [55:60) race = white, other
		h1_1[8][0] = 334.8 * 0.00001;       // [60:65) race = white, other
		h1_1[9][0] = 392.3 * 0.00001;       // [65:70) race = white, other
		h1_1[10][0] = 417.8 * 0.00001;      // [70:75) race = white, other
		h1_1[11][0] = 443.9 * 0.00001;      // [75:80) race = white, other
		h1_1[12][0] = 442.1 * 0.00001;      // [80:85) race = white, other
		h1_1[13][0] = 410.9 * 0.00001;      // [85:90) race = white, other
			
		h1_1[0][1] = 0.00002696;     // [20:25) race=African American    
		h1_1[1][1] = 0.00011295;     // [25:30) race=African American
		h1_1[2][1] = 0.00031094;     // [30:35) race=African American
		h1_1[3][1] = 0.00067639;     // [35:40) race=African American
		h1_1[4][1] = 0.00119444;     // [40:45) race=African American
		h1_1[5][1] = 0.00187394;     // [45:50) race=African American
		h1_1[6][1] = 0.00241504;     // [50:55) race=African American
		h1_1[7][1] = 0.00291112;     // [55:60) race=African American
		h1_1[8][1] = 0.00310127;     // [60:65) race=African American
		h1_1[9][1] = 0.00366560;     // [65:70) race=African American
		h1_1[10][1] = 0.00393132;    // [70:75) race=African American
		h1_1[11][1] = 0.00408951;    // [75:80) race=African American
		h1_1[12][1] = 0.00396793;    // [80:85) race=African American
		h1_1[13][1] = 0.00363712;    // [85:90) race=African American

		h1_1[0][2] = 2.00 * 0.00001;       //[20:25) race = hispanic        
		h1_1[1][2] = 7.10 * 0.00001;       //[25:30) race = hispanic        
		h1_1[2][2] = 19.70 * 0.00001;      //[30:35) race = hispanic
		h1_1[3][2] = 43.80 * 0.00001;      //[35:40) race = hispanic
		h1_1[4][2] = 81.10 * 0.00001;      //[40:45) race = hispanic
		h1_1[5][2] = 130.70 * 0.00001;     //[45:50) race = hispanic
		h1_1[6][2] = 157.40 * 0.00001;     //[50:55) race = hispanic
		h1_1[7][2] = 185.70 * 0.00001;     //[55:60) race = hispanic
		h1_1[8][2] = 215.10 * 0.00001;     //[60:65) race = hispanic
		h1_1[9][2] = 251.20 * 0.00001;     //[65:70) race = hispanic
		h1_1[10][2] = 284.60 * 0.00001;    //[70:75) race = hispanic
		h1_1[11][2] = 275.70 * 0.00001;    //[75:80) race = hispanic
		h1_1[12][2] = 252.30 * 0.00001;    //[80:85) race = hispanic
		h1_1[13][2] = 203.90 * 0.00001;    //[85:90) race = hispanic

		h1_1[0][3] = 1.22 * 0.00001;	  //[20:25) race = white, other        
		h1_1[1][3] = 7.41 * 0.00001;	  //[25:30) race = white, other
		h1_1[2][3] = 22.97 * 0.00001;	  //[30:35) race = white, other
		h1_1[3][3] = 56.49 * 0.00001;	  //[35:40) race = white, other
		h1_1[4][3] = 116.45 * 0.00001;	  //[40:45) race = white, other
		h1_1[5][3] = 195.25 * 0.00001;	  //[45:50) race = white, other
		h1_1[6][3] = 261.54 * 0.00001;	  //[50:55) race = white, other
		h1_1[7][3] = 302.79 * 0.00001;	  //[55:60) race = white, other
		h1_1[8][3] = 367.57 * 0.00001;	  //[60:65) race = white, other
		h1_1[9][3] = 420.29 * 0.00001;	  //[65:70) race = white, other
		h1_1[10][3] = 473.08 * 0.00001;	  //[70:75) race = white, other
		h1_1[11][3] = 494.25 * 0.00001;	  //[75:80) race = white, other
		h1_1[12][3] = 479.76 * 0.00001;	  //[80:85) race = white, other
		h1_1[13][3] = 401.06 * 0.00001;	  //[85:90) race = white, other

		h1_1[0][4] = 0.00002696;     //[20:25) race = African American    
		h1_1[1][4] = 0.00011295;     //[25:30) race = African American
		h1_1[2][4] = 0.00031094;     //[30:35) race = African American
		h1_1[3][4] = 0.00067639;     //[35:40) race = African American
		h1_1[4][4] = 0.00119444;     //[40:45) race = African American
		h1_1[5][4] = 0.00187394;     //[45:50) race = African American
		h1_1[6][4] = 0.00241504;     //[50:55) race = African American
		h1_1[7][4] = 0.00291112;     //[55:60) race = African American
		h1_1[8][4] = 0.00310127;     //[60:65) race = African American
		h1_1[9][4] = 0.00366560;     //[65:70) race = African American
		h1_1[10][4] = 0.00393132;    //[70:75) race = African American
		h1_1[11][4] = 0.00408951;    //[75:80) race = African American
		h1_1[12][4] = 0.00396793;    //[80:85) race = African American
		h1_1[13][4] = 0.00363712;    //[85:90) race = African American

		h1_1[0][5] = 2.00 * 0.00001;     //[20:25) race = hispanic        
		h1_1[1][5] = 7.10 * 0.00001;     //[25:30) race = hispanic
		h1_1[2][5] = 19.70 * 0.00001;    //[30:35) race = hispanic
		h1_1[3][5] = 43.80 * 0.00001;    //[35:40) race = hispanic
		h1_1[4][5] = 81.10 * 0.00001;    //[40:45) race = hispanic
		h1_1[5][5] = 130.70 * 0.00001;   //[45:50) race = hispanic
		h1_1[6][5] = 157.40 * 0.00001;   //[50:55) race = hispanic
		h1_1[7][5] = 185.70 * 0.00001;   //[55:60) race = hispanic
		h1_1[8][5] = 215.10 * 0.00001;   //[60:65) race = hispanic
		h1_1[9][5] = 251.20 * 0.00001;   //[65:70) race = hispanic
		h1_1[10][5] = 284.60 * 0.00001;  //[70:75) race = hispanic
		h1_1[11][5] = 275.70 * 0.00001;  //[75:80) race = hispanic
		h1_1[12][5] = 252.30 * 0.00001;  //[80:85) race = hispanic
		h1_1[13][5] = 203.90 * 0.00001;  //[85:90) race = hispanic


			// White & Other women logistic regression coefficients - GAIL model (BCDDP) //

		beta[0][0] = -0.7494824600;		 //intercept        
		beta[1][0] = 0.0108080720;		 //age >= 50 indicator
		beta[2][0] = 0.0940103059;		 //age  menarchy
		beta[3][0] = 0.5292641686;       //of breast biopsy
		beta[4][0] = 0.2186262218;       //age 1st live birth
		beta[5][0] = 0.9583027845;       //1st degree relatives with breast ca
		beta[6][0] = -0.2880424830;      //breast biopsy * age >= 50 indicator
		beta[7][0] = -0.1908113865;      //age 1st live birth *  1st degree rel

			// African American women  logistic regression coefficients - CARE model //

		beta[0][1] = -0.3457169653;		//intercept        
		beta[1][1] = 0.0334703319;		//age >= 50 indicator set ? to 0 in PGM
		beta[2][1] = 0.2672530336;		//age menarchy
		beta[3][1] = 0.1822121131;		//of breast biopsy
		beta[4][1] = 0.0000000000;		//age 1st live birth
		beta[5][1] = 0.4757242578;      //1st degree relatives with breast ca
		beta[6][1] = -0.1119411682;     //breast biopsy * age >= 50 indicator
		beta[7][1] = 0.0000000000;		//age 1st live birth *  1st degree rel

			// Hispanic women   logistic regression coefficients - GAIL model (BCDDP) //

		beta[0][2] = -0.7494824600;		//intercept        
		beta[1][2] = 0.0108080720;		//age >= 50 indicator
		beta[2][2] = 0.0940103059;		//age menarchy
		beta[3][2] = 0.5292641686;      //of breast biopsy
		beta[4][2] = 0.2186262218;		//age 1st live birth
		beta[5][2] = 0.9583027845;      //1st degree relatives with breast ca
		beta[6][2] = -0.2880424830;     //breast biopsy * age >= 50 indicator
		beta[7][2] = -0.1908113865;		//age 1st live birth *  1st degree rel

		for (int i = 6; i <= 11; i++)
		{
			beta[0][i] = 0.00000000000000;  //intercept
			beta[1][i] = 0.00000000000000;  //age >= 50 indicator
			beta[2][i] = 0.07499257592975;  //age menarchy
			beta[3][i] = 0.55263612260619;  //of breast biopsy
			beta[4][i] = 0.27638268294593;  //age 1st live birth
			beta[5][i] = 0.79185633720481;  //1st degree relatives with breast ca
			beta[6][i] = 0.00000000000000;  //breast biopsy * age >=50 indicator
			beta[7][i] = 0.00000000000000;  //age 1st live birth * 1st degree rel
		}

		rf2[0][0] = 0.5788413;   // age < 50, race = white, other        1 / 12 / 99
		rf2[1][0] = 0.5788413;  // age >= 50, race = white, other

		rf2[0][1] = 0.72949880;  // age < 50, race = African American    12 / 19 / 2007 based on david pee's input
		rf2[1][1] = 0.74397137;  // age >= 50, race = African American

		rf2[0][2] = 0.5788413;   // age < 50, race = hispanic             5 / 12 / 2000
		rf2[1][2] = 0.5788413;   // age >= 50, race = hispanic

		rf2[0][3] = 1.0;     // age < 50, race = white avg woman                11 / 21
		rf2[1][3] = 1.0;     // age >= 50, race = white avg woman

		rf2[0][4] = 1.0;     // age < 50, race = AfricanAmerican avg woman              11 / 21
		rf2[1][4] = 1.0;     // age >= 50, race = AfricanAmerican avg woman

		rf2[0][5] = 1.0;     // age < 50, race = hispanic avg woman             5 / 12
		rf2[1][5] = 1.0;     // age >= 50, race = hispanic avg woman

		for (int i = 6; i <= 11; i++)
		{
			rf2[0][i] = 0.47519806426735;  // age < 50, avg woman
			rf2[1][i] = 0.50316401683903;  // age >=50, avg woman
		}

		rf2[0][12] = 1.0;  // age < 50, race = hispanic avg woman        5 / 12
		rf2[1][12] = 1.0;  // age >= 50, race = hispanic avg woman


		 //*** SEER18 incidence 1998:02 - chinese  Jan052010;

		h1_1[0][6] = 0.000004059636;
		h1_1[1][6] = 0.000045944465;
		h1_1[2][6] = 0.000188279352;
		h1_1[3][6] = 0.000492930493;
		h1_1[4][6] = 0.000913603501;
		h1_1[5][6] = 0.001471537353;
		h1_1[6][6] = 0.001421275482;
		h1_1[7][6] = 0.001970946494;
		h1_1[8][6] = 0.001674745804;
		h1_1[9][6] = 0.001821581075;
		h1_1[10][6] = 0.001834477198;
		h1_1[11][6] = 0.001919911972;
		h1_1[12][6] = 0.002233371071;
		h1_1[13][6] = 0.002247315779;


		//*** NCHS mortality 1998:02,    chinese  Jan052010;

		h2[0][6] = 0.000210649076;
		h2[1][6] = 0.000192644865;
		h2[2][6] = 0.000244435215;
		h2[3][6] = 0.000317895949;
		h2[4][6] = 0.000473261994;
		h2[5][6] = 0.000800271380;
		h2[6][6] = 0.001217480226;
		h2[7][6] = 0.002099836508;
		h2[8][6] = 0.003436889186;
		h2[9][6] = 0.006097405623;
		h2[10][6] = 0.010664526765;
		h2[11][6] = 0.020148678452;
		h2[12][6] = 0.037990796590;
		h2[13][6] = 0.098333900733;


		//*** SEER18 incidence 1998:02 - japanese  Jan052010;

		h1_1[0][7] = 0.000000000001;
		h1_1[1][7] = 0.000099483924;
		h1_1[2][7] = 0.000287041681;
		h1_1[3][7] = 0.000545285759;
		h1_1[4][7] = 0.001152211095;
		h1_1[5][7] = 0.001859245108;
		h1_1[6][7] = 0.002606291272;
		h1_1[7][7] = 0.003221751682;
		h1_1[8][7] = 0.004006961859;
		h1_1[9][7] = 0.003521715275;
		h1_1[10][7] = 0.003593038294;
		h1_1[11][7] = 0.003589303081;
		h1_1[12][7] = 0.003538507159;
		h1_1[13][7] = 0.002051572909;

		//*** NCHS mortality 1998:02,    japanese  Jan052010;

		h2[0][7] = 0.000173593803;
		h2[1][7] = 0.000295805882;
		h2[2][7] = 0.000228322534;
		h2[3][7] = 0.000363242389;
		h2[4][7] = 0.000590633044;
		h2[5][7] = 0.001086079485;
		h2[6][7] = 0.001859999966;
		h2[7][7] = 0.003216600974;
		h2[8][7] = 0.004719402141;
		h2[9][7] = 0.008535331402;
		h2[10][7] = 0.012433511681;
		h2[11][7] = 0.020230197885;
		h2[12][7] = 0.037725498348;
		h2[13][7] = 0.106149118663;


		//*** SEER18 incidence 1998:02 - filipino  Jan052010;

		h1_1[0][8] = 0.000007500161;
		h1_1[1][8] = 0.000081073945;
		h1_1[2][8] = 0.000227492565;
		h1_1[3][8] = 0.000549786433;
		h1_1[4][8] = 0.001129400541;
		h1_1[5][8] = 0.001813873795;
		h1_1[6][8] = 0.002223665639;
		h1_1[7][8] = 0.002680309266;
		h1_1[8][8] = 0.002891219230;
		h1_1[9][8] = 0.002534421279;
		h1_1[10][8] = 0.002457159409;
		h1_1[11][8] = 0.002286616920;
		h1_1[12][8] = 0.001814802825;
		h1_1[13][8] = 0.001750879130;


		//*** NCHS mortality 1998:02,    filipino  Jan052010;

		h2[0][8] = 0.000229120979;
		h2[1][8] = 0.000262988494;
		h2[2][8] = 0.000314844090;
		h2[3][8] = 0.000394471908;
		h2[4][8] = 0.000647622610;
		h2[5][8] = 0.001170202327;
		h2[6][8] = 0.001809380379;
		h2[7][8] = 0.002614170568;
		h2[8][8] = 0.004483330681;
		h2[9][8] = 0.007393665092;
		h2[10][8] = 0.012233059675;
		h2[11][8] = 0.021127058106;
		h2[12][8] = 0.037936954809;
		h2[13][8] = 0.085138518334;



		//*** SEER18 incidence 1998:02 - hawaiian  Jan052010;

		h1_1[0][9] = 0.000045080582;
		h1_1[1][9] = 0.000098570724;
		h1_1[2][9] = 0.000339970860;
		h1_1[3][9] = 0.000852591429;
		h1_1[4][9] = 0.001668562761;
		h1_1[5][9] = 0.002552703284;
		h1_1[6][9] = 0.003321774046;
		h1_1[7][9] = 0.005373001776;
		h1_1[8][9] = 0.005237808549;
		h1_1[9][9] = 0.005581732512;
		h1_1[10][9] = 0.005677419355;
		h1_1[11][9] = 0.006513409962;
		h1_1[12][9] = 0.003889457523;
		h1_1[13][9] = 0.002949061662;


		//*** NCHS mortality 1998:02,    hawaiian  Jan052010;

		h2[0][9] = 0.000563507269;
		h2[1][9] = 0.000369640217;
		h2[2][9] = 0.001019912579;
		h2[3][9] = 0.001234013911;
		h2[4][9] = 0.002098344078;
		h2[5][9] = 0.002982934175;
		h2[6][9] = 0.005402445702;
		h2[7][9] = 0.009591474245;
		h2[8][9] = 0.016315472607;
		h2[9][9] = 0.020152229069;
		h2[10][9] = 0.027354838710;
		h2[11][9] = 0.050446998723;
		h2[12][9] = 0.072262026612;
		h2[13][9] = 0.145844504021;


		//*** SEER18 incidence 1998:02 - other pacific islander  Jan052010;

		h1_1[0][10] = 0.000000000001;
		h1_1[1][10] = 0.000071525212;
		h1_1[2][10] = 0.000288799028;
		h1_1[3][10] = 0.000602250698;
		h1_1[4][10] = 0.000755579402;
		h1_1[5][10] = 0.000766406354;
		h1_1[6][10] = 0.001893124938;
		h1_1[7][10] = 0.002365580107;
		h1_1[8][10] = 0.002843933070;
		h1_1[9][10] = 0.002920921732;
		h1_1[10][10] = 0.002330395655;
		h1_1[11][10] = 0.002036291235;
		h1_1[12][10] = 0.001482683983;
		h1_1[13][10] = 0.001012248203;


		//*** NCHS mortality 1998:02,    other pacific islander  Jan052010;

		h2[0][10] = 0.000465500812;
		h2[1][10] = 0.000600466920;
		h2[2][10] = 0.000851057138;
		h2[3][10] = 0.001478265376;
		h2[4][10] = 0.001931486788;
		h2[5][10] = 0.003866623959;
		h2[6][10] = 0.004924932309;
		h2[7][10] = 0.008177071806;
		h2[8][10] = 0.008638202890;
		h2[9][10] = 0.018974658371;
		h2[10][10] = 0.029257567105;
		h2[11][10] = 0.038408980974;
		h2[12][10] = 0.052869579345;
		h2[13][10] = 0.074745721133;



		//*** SEER18 incidence 1998:02 - other asian  Jan052010;

		h1_1[0][11] = 0.000012355409;
		h1_1[1][11] = 0.000059526456;
		h1_1[2][11] = 0.000184320831;
		h1_1[3][11] = 0.000454677273;
		h1_1[4][11] = 0.000791265338;
		h1_1[5][11] = 0.001048462801;
		h1_1[6][11] = 0.001372467817;
		h1_1[7][11] = 0.001495473711;
		h1_1[8][11] = 0.001646746198;
		h1_1[9][11] = 0.001478363563;
		h1_1[10][11] = 0.001216010125;
		h1_1[11][11] = 0.001067663700;
		h1_1[12][11] = 0.001376104012;
		h1_1[13][11] = 0.000661576644;


		//*** NCHS mortality 1998:02,    other asian Jan052010;

		h2[0][11] = 0.000212632332;
		h2[1][11] = 0.000242170741;
		h2[2][11] = 0.000301552711;
		h2[3][11] = 0.000369053354;
		h2[4][11] = 0.000543002943;
		h2[5][11] = 0.000893862331;
		h2[6][11] = 0.001515172239;
		h2[7][11] = 0.002574669551;
		h2[8][11] = 0.004324370426;
		h2[9][11] = 0.007419621918;
		h2[10][11] = 0.013251765130;
		h2[11][11] = 0.022291427490;
		h2[12][11] = 0.041746550635;
		h2[13][11] = 0.087485802065;

	}

	double RiskVariables(int RiskIndex, int CurrentAge, int ProjectionAge, int MenarcheAge, int FirstLiveBirthAge, int FirstDegRelatives, int EverHadBiopsy = 99, int NumberOfBiopsy = 99, int Hyperplasia = 99, int race = 1)
	{
		/* EverHadBiopsy=99    # 99: unknown, 1: yes, 0: no
           NumberOfBiopsy=99   # 0: no, 1: One, or unknown but have had biopsy, 2: more than one
           Hyperplasia=99      # 1: yes, 0: no, 99: Unknown or never had biopsy */

		int ageindicator = 0;
		if (CurrentAge >= 50)
		{
			ageindicator = 1;
		}

		if (EverHadBiopsy == 99)
		{
			EverHadBiopsy = 0;
		}

		if (EverHadBiopsy == 0 || EverHadBiopsy == 99)
		{
			NumberOfBiopsy = 0;
			Hyperplasia = 99;
		}

		if (EverHadBiopsy == 1 && (NumberOfBiopsy == 99 || NumberOfBiopsy == 0))
		{
			NumberOfBiopsy = 1;
		}

		if (NumberOfBiopsy > 1 && NumberOfBiopsy <= 30)
		{
			NumberOfBiopsy = 2;
		}

		else
		{
			NumberOfBiopsy = 0;
		}

		double RealHyp = 1.0; //Zero Biopsy or Unknown
		if (Hyperplasia == 1)
		{
			RealHyp = 1.82; //Yes to Hyperplasia
		}

		else if (Hyperplasia == 0)
		{
			RealHyp = 0.93; //No to Hyperplasia but yes to Biopsy
		}

		if (FirstDegRelatives == 0 || FirstDegRelatives == 99)
		{
			FirstDegRelatives = 0;
		}

		else if (FirstDegRelatives >= 2 && FirstDegRelatives <= 31 && race < 7)
		{
			FirstDegRelatives = 2;
		}

		else if (FirstDegRelatives >= 2 && race >= 7)
		{
			FirstDegRelatives = 1;
		}

		int NewLiveBirth = 0;
		if (FirstLiveBirthAge == 0)
		{
			NewLiveBirth = 2;
		}

		else if (FirstLiveBirthAge > 0)
		{
			if (FirstLiveBirthAge < 20 || FirstLiveBirthAge == 99)
			{
				NewLiveBirth = 0;
			}
			else if (FirstLiveBirthAge >= 20 && FirstLiveBirthAge < 25)
			{
				return CalculateRisk(RiskIndex, CurrentAge, ProjectionAge, ageindicator, NumberOfBiopsy, MenarcheAge, FirstLiveBirthAge, EverHadBiopsy, FirstDegRelatives, Hyperplasia, RealHyp, race);
			}
		}

	}

	double CalculateRisk(int RiskIndex, int CurrentAge, int ProjectionAge, int AgeIndicator, int NumberOfBiopsy, int MenarcheAge, int FirstLiveBirthAge, int EverHadBiopsy, int FirstDegRlatives, int ihyp, double rhyp, int irace)
	{
		double retval = 0.0;
		int i = 0;
		int j = 0;
		int k = 0;
		//int n = 0;
		double r = 0.0;
		int ni = 0;
		double ti = 0.0;
		int ns = 0;
		double ts = 0.0;
		double abss = 0.0;
		int incr = 0;
		int ilev = 0;
		double r8iTox2[216][9] = { 0.0 };
		int n = 216;

		ti = double(CurrentAge);
		ts = double(ProjectionAge);

		for (int i = 0; i < 8; i++)
		{
			beta2[i] = beta[i][irace - 1];
		}

		if (irace == 2)
		{
			if (MenarcheAge == 2)
			{
				MenarcheAge = 1;
				FirstLiveBirthAge = 0;
			}
		}

		for (int i = 1; i < 16; i++)
		{
			if (ti < t[i - 1])
			{
				ni = i - 1;
				break;
			}
		}

		for (int i = 1; i < 16; i++)
		{
			if (ts <= t[i - 1])
			{
				ns = i - 1;
				break;
			}
		}

		incr = 0;
		if (RiskIndex == 2 && irace < 7)
		{
			incr = 3;
		}

		/* select race specific */

		int cindx = incr + irace - 1;

		for (int i = 0; i < 14; i++)
		{
			h[i] = h2[i][cindx];
			rlan[i] = h1_1[i][cindx];
		}

		rf[0] = rf2[0][incr + irace - 1];
		rf[1] = rf2[1][incr + irace - 1];

		if (RiskIndex == 2 && irace >= 7)
		{
			rf[0] = rf2[0][12];
			rf[1] = rf2[1][12];
		}

		if (RiskIndex >= 2 && irace < 7)
		{
			MenarcheAge = 0;
			NumberOfBiopsy = 0;
			FirstDegRlatives = 0;
			FirstLiveBirthAge = 0;
			rhyp = 1.0;
		}

		ilev = AgeIndicator * 108 + MenarcheAge * 36 + NumberOfBiopsy * 12 + FirstLiveBirthAge * 3 + FirstDegRlatives + 1;

	   /* covariate */
	   /* range of 1 */
	   /* AgeIndicator: age ge 50 ind  
							 0=[20, 50) */
	   /*                    1=[50, 85) */
	   /* MenarcheAge: age menarchy   
							 0=[14, 39] U 99 (unknown) */
	   /*                    1=[12, 14) */
	   /*                    2=[ 7, 12) */
	   /* NumberOfBiopsy: # biopsy       
							 0=0 or (99 and ever had biopsy=99 */
	   /*                    1=1 or (99 and ever had biopsy=1 y */
	   /*                    2=[ 2, 30] */
	   /* FirstLiveBirthAge: age 1st live  
							 0=<20, 99 (unknown) */
	   /*                    1=[20, 25) */
	   /*                    2=[25, 30) U 0 */
	   /*                    3=[30, 55] */
	   /* FirstDegRelatives: 1st degree rel 
							 0=0, 99 (unknown) */
	   /*                    1=1 */
	   /*                    2=[2, 31] */
	   /* **  Correspondence between exposure level and covariate factors X */
	   /* **  in the logistic model */
	   /* **  i-to-X correspondence */
	   /* index in r8i */

		for (k = 0; k < 216; ++k)
		{
			/* col1: intercept o */
			r8iTox2[k][0] = 1.0;
		}

		for (k = 0; k < 108; ++k)
		{
			/* col2: indicator for age */
			r8iTox2[k][1] = 0.0;
			r8iTox2[108 + k][1] = 1.0;
		}
		for (j = 1; j <= 2; ++j)
		{
			/* col3: age menarchy cate */
			for (k = 1; k <= 36; ++k)
			{
				r8iTox2[(j - 1) * 108 + k - 1][2] = 0.0;
				r8iTox2[(j - 1) * 108 + 36 + k - 1][2] = 1.0;
				r8iTox2[(j - 1) * 108 + 72 + k - 1][2] = 2.0;
			}
		}
		for (j = 1; j <= 6; ++j)
		{
			/* col4: # biopsy cate */
			for (k = 1; k <= 12; ++k)
			{
				r8iTox2[(j - 1) * 36 + k - 1][3] = 0.0;
				r8iTox2[(j - 1) * 36 + 12 + k - 1][3] = 1.0;
				r8iTox2[(j - 1) * 36 + 24 + k - 1][3] = 2.0;
			}
		}
		for (j = 1; j <= 18; ++j)
		{
			/* col5: age 1st live birt */
			for (k = 1; k <= 3; ++k)
			{
				r8iTox2[(j - 1) * 12 + k - 1][4] = 0.0;
				r8iTox2[(j - 1) * 12 + 3 + k - 1][4] = 1.0;
				r8iTox2[(j - 1) * 12 + 6 + k - 1][4] = 2.0;
				r8iTox2[(j - 1) * 12 + 9 + k - 1][4] = 3.0;
			}
		}
		for (j = 1; j <= 72; ++j)
		{
			/* col6: # 1st degree re */
			r8iTox2[(j - 1) * 3 + 1 - 1][5] = 0.0;
			r8iTox2[(j - 1) * 3 + 2 - 1][5] = 1.0;
			r8iTox2[(j - 1) * 3 + 3 - 1][5] = 2.0;
		}
		for (i = 0; i < 216; ++i)
		{
			/* col8: age 1st live*# r */
			/* col7: age*#biop intera */
			r8iTox2[i][6] = r8iTox2[i][1] * r8iTox2[i][3];
			r8iTox2[i][7] = r8iTox2[i][4] * r8iTox2[i][5];
		}
		for (i = 0; i < 216; ++i)
		{
			//HACK r8iTox2[i + 1727] = 1.0;
			r8iTox2[i][8] = 1.0;
		}


		/* **  Computation of breast cancer risk */
		/* **  sum(bi*Xi) for all covariate patterns */
		for (i = 0; i < 216; ++i)
		{
			/* ln relative risk from BCDDP */
			sumb[i] = 0.0;
			for (j = 0; j < 8; ++j)
			{
				sumb[i] += beta2[j] * r8iTox2[i][j];
			}
		}
		for (i = 1; i <= 108; ++i)
		{
			/* eliminate int */
			sumbb[i - 1] = sumb[i - 1] - beta2[0];
		}
		for (i = 109; i <= 216; ++i)
		{
			/* eliminate intercept */
			sumbb[i - 1] = sumb[i - 1] - beta2[0] - beta2[1];
		}
		for (j = 1; j <= 6; ++j)
		{
			/* age specific baseline hazard */
			rlan[j - 1] *= rf[0];
		}
		for (j = 7; j <= 14; ++j)
		{
			/* age specific baseline hazard a */
			rlan[j - 1] *= rf[1];
		}
		i = ilev;
		sumbb[i - 1] += log(rhyp);
		if (i <= 108)
		{
			sumbb[i + 107] += log(rhyp);
		}
		if (ts <= t[ni])
		{
			/* same 5 year age risk in */
			/* age & projection age wi */

			abs[i - 1] = 1.0 - exp((-1)*(rlan[ni - 1] * exp(sumbb[i - 1]) + h[ni - 1]) * (ts - ti));
			abs[i - 1] = abs[i - 1] * rlan[ni - 1] * exp(sumbb[i - 1]) / (rlan[ni - 1] * exp(sumbb[i - 1]) + h[ni - 1]);
		}
		else 
		{
			/* 5 year age risk interval */
			/* calculate risk from */
			/* 1st age interval */
			/* age & projection age not i */

			
			
			abs[i - 1] = 1.0 - exp(-(rlan[ni - 1] * exp(sumbb[i - 1]) + h[ni - 1]) * (t[ni] - ti));
			abs[i - 1] = abs[i - 1] * rlan[ni - 1] * exp(sumbb[i - 1]) / (rlan[ni - 1] * exp(sumbb[i - 1]) + h[ni - 1]);

			if (ns - ni > 0)
			{
				if ((double)(ProjectionAge) > 50.0 && (double)(CurrentAge) < 50.0)
				{
					r = 1.0 - exp(-(rlan[ns - 1] * exp(sumbb[i + 107]) + h[ns - 1]) * (ts - t[ns - 1]));
					r = r * rlan[ns - 1] * exp(sumbb[i + 107]) / (rlan[ns - 1] * exp(sumbb[i + 107]) + h[ns - 1]);
					r *= exp(-(rlan[ni - 1] * exp(sumbb[i - 1]) + h[ni - 1]) * (t[ni] - ti));


					if (ns - ni > 1)
					{
						MenarcheAge = ns - 1;
						for (int j = ni + 1; j < MenarcheAge + 1; ++j)
						{
							if (t[j - 1] >= 50.0)
							{
								r *= exp(-(rlan[j - 1] * exp(sumbb[i + 107]) * h[j - 1]) * (t[j] - t[j - 1]));
							}
							else
							{
								r *= exp(-(rlan[j - 1] * exp(sumbb[i - 1]) + h[j - 1]) * (t[j] - t[j - 1]));
							}
						}
					}
					abs[i - 1] += r;
				}
				else
				{
					/* calculate risk from */
					/* last age interval */
					/* ages do not stradle */

					r = 1.0 - exp(-(rlan[ns - 1] * exp(sumbb[i - 1]) + h[ns - 1]) * (ts - t[ns - 1]));
					r = r * rlan[ns - 1] * exp(sumbb[i - 1]) / (rlan[ns - 1] * exp(sumbb[i - 1]) + h[ns - 1]);
					r *= exp(-(rlan[ni - 1] * exp(sumbb[i - 1]) + h[ni - 1]) * (t[ni] - ti));

					if (ns - ni > 1)
					{
						MenarcheAge = ns - 1;
						for (int j = ni + 1;j < MenarcheAge + 1;j++)
						{
							r *= exp(-(rlan[j - 1] * exp(sumbb[i - 1]) + h[j - 1]) * (t[j] - t[j - 1]));
						}
					}
					abs[i - 1] += r;
				}
			}

			if (ns - ni > 1)
			{
				if ((double)(ProjectionAge) > 50.0 && (double)(CurrentAge) < 50.0)
				{
					/* calculate risk from */
					/* intervening age int */

					MenarcheAge = ns - 1;
					for (int k = ni + 1;k < MenarcheAge + 1;++k)
					{
						if (t[k - 1] >= 50)
						{
							r = 1.0 - exp(-(rlan[k - 1] * exp(sumbb[1 + 107]) + h[k - 1]) * (t[k] - t[k - 1]));
							r = r * rlan[k - 1] * exp(sumbb[i + 107]) / (rlan[k - 1] * exp(sumbb[i + 107]) + h[k - 1]);
						}
						else
						{
							r = 1.0 - exp(-(rlan[k - 1] * exp(sumbb[i - 1]) + h[k - 1]) * (t[k] - t[k - 1]));
							r = r * rlan[k - 1] * exp(sumbb[i - 1]) / (rlan[k - 1] * exp(sumbb[i - 1]) + h[k - 1]);
						}

						r *= exp(-(rlan[ni - 1] * exp(sumbb[i - 1]) + h[ni - 1]) * (t[ni] - ti));
						NumberOfBiopsy = k - 1;

						for (int j = ni + 1; j < NumberOfBiopsy + 1;j++)
						{
							if (t[j - 1] >= 50.0)
							{
								r *= exp(-(rlan[j - 1] * exp(sumbb[i - 1]) + h[j - 1]) * (t[j] - t[j - 1]));
							}
							else
							{
								r *= exp(-(rlan[j - 1] * exp(sumbb[i - 1]) + h[j - 1]) * (t[j] - t[j - 1]));
							}
						}
						abs[i - 1] += r;
					}
				}

				else
				{
					/* calculate risk from */
					/* intervening age int */
					MenarcheAge = ns - 1;
					for (k = ni + 1; k <= MenarcheAge; ++k)
					{
						r = 1.0 - exp(-(rlan[k - 1] * exp(sumbb[i - 1]) + h[k - 1]) * (t[k] - t[k - 1]));
						r = r * rlan[k - 1] * exp(sumbb[i - 1]) / (rlan[k - 1] * exp(sumbb[i - 1]) + h[k - 1]);
						r *= exp(-(rlan[ni - 1] * exp(sumbb[i - 1]) + h[ni - 1]) * (t[ni] - ti));
						NumberOfBiopsy = k - 1;
						for (j = ni + 1; j <= NumberOfBiopsy; ++j)
						{
							r *= exp(-(rlan[j - 1] * exp(sumbb[i - 1]) + h[j - 1]) * (t[j] - t[j - 1]));
						}
						abs[i - 1] += r;
					}
				}
			}
		}
		abss = abs[i - 1] * 1000.0;

		//HACK CHECK THIS
		if (abss - (int)(abss) >= .5f)
		{
			//abss = d_int(abss) + 1.0 ;
			abss = (int)(abss)+1.0;
		}
		else
		{
			abss = (int)(abss);
		}
		abss /= 10.0;
		retval = abs[i - 1];
		return retval;
	}
};

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
		 IndiceRisk a;
		 int riskInd = 1;
		 int CurrentAge = 45;
		 int ProjectionAge = 50;
		 int AgeIndicator = 0;
		 int NumberOfBiopsy = 2;
		 int MenarcheAge = 2;
		 int FirstLiveBirthAge = 0;
		 int EverHaveBiopsy = 1;
		 int FirstDegRelatives = 0;
		 int HyperPlasia = 1;
		 double RHyperPlasia = 1.82;
		 int irace = 1;

		 while (!fs.eof()) {
			 if (fs.get() == ',') {
				 fs.seekp((fs.tellp() - static_cast<std::streampos>(1)));
				 fs.put('.');
				 fs.seekp(fs.tellp());
			 }
		 }

		 fin >> riskInd;
		 fin >> CurrentAge;
		 fin >> ProjectionAge;
		 fin >> AgeIndicator;
		 fin >> NumberOfBiopsy;
		 fin >> MenarcheAge;
		 fin >> FirstLiveBirthAge;
		 fin >> EverHaveBiopsy;
		 fin >> FirstDegRelatives;
		 fin >> HyperPlasia;
		 fin >> RHyperPlasia;
		 fin >> irace;

		 cout << riskInd << endl;
		 cout << CurrentAge << endl;
		 cout << ProjectionAge << endl;
		 cout << AgeIndicator << endl;
		 cout << NumberOfBiopsy << endl;
		 cout << MenarcheAge << endl;
		 cout << FirstLiveBirthAge << endl;
		 cout << EverHaveBiopsy << endl;
		 cout << FirstDegRelatives << endl;
		 cout << HyperPlasia << endl;
		 cout << RHyperPlasia << endl;
		 cout << irace << endl;

		 double risc = a.CalculateRisk(riskInd, // riskIndex int[1 = Abs, 2 = Ave]
			 CurrentAge, // CurrentAge int[t1]
			 ProjectionAge, // ProjectionAge int[t2]
			 AgeIndicator, // AgeIndicator int[i0]
			 NumberOfBiopsy, // NumberOfBiopsy int[i2]
			 MenarcheAge, // MenarcheAge int[i1]
			 FirstLiveBirthAge, // FirstLiveBirthAge int[i3]
			 EverHaveBiopsy, // EverHaveBiopsy int[iever]
			 FirstDegRelatives, // FirstDegRelatives int[i4]
			 HyperPlasia, // int[ihyp]  HyperPlasia
			 RHyperPlasia, // double[rhyp]  RHyperPlasia
			 irace  // irace int[race]
		 );

		 risc = risc * 100;

		 cout << risc << "%";
		 fout << risc;
		 
		 system("pause");

		 return 0;
	
 }
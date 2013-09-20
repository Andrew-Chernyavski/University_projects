package com.example.reversi;

public class Hard2Bot extends Bot {
	int choose (int[][] mas, int numPl) {
		if (valid(0,0,numPl,mas))
			return 11;
		if (valid(0,7,numPl,mas))
			return 18;
		if (valid(7,0,numPl,mas))
			return 81;
		if (valid(7,7,numPl,mas))
			return 88;
		int maxCoord = 0;
		int max = -100;
		int numOfMax = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++) {
				int guarProfit = 128;
				if (valid(i,j,numPl,mas)) {//for every cell
					int guarProfit0 = 0;
					int[][] locMas = new int[8][8];
					copyMas(mas, locMas);
					int locNumPl = numPl;
					guarProfit0 += doStep(i,j,locNumPl,locMas);//wee've done (i,j) move
					
					if (valid(0,0,-locNumPl,locMas))
						guarProfit0 -= 20;
					if (valid(0,7,-locNumPl,locMas))
						guarProfit0 -= 20;
					if (valid(7,0,-locNumPl,locMas))
						guarProfit0 -= 20;
					if (valid(7,7,-locNumPl,locMas))
						guarProfit0 -= 20;
					
					int num1 = 0;
					for (int i1 = 0; i1 < 8; i1++)
						for (int j1 = 0; j1 < 8; j1++) {
							if (valid(i1,j1,locNumPl, locMas)) {
								num1++;
								int guarProfit1 = guarProfit0;
								int[][]locMas1 = new int[8][8];
								copyMas(locMas, locMas1);
								int locNumPl1 = -1 * locNumPl;
								guarProfit1 -= doStep(i1,j1,locNumPl1,locMas1);
								
								
								int num2 = 0;
								for (int i2 = 0; i2 < 8; i2++)
										for (int j2 = 0; j2 < 8; j2++) {
											if (valid(i2,j2,locNumPl, locMas)) {
												num2++;
												int guarProfit2 = guarProfit1;
												int[][]locMas2 = new int[8][8];
												copyMas(locMas1, locMas2);
												int locNumPl2 = locNumPl;
												guarProfit2 += doStep(i2,j2,locNumPl2,locMas2);
												
												
												if (guarProfit2 < guarProfit)
													guarProfit = guarProfit2;
//												int num3 = 0;
//												for (int i3 = 0; i3 < 8; i3++)
//														for (int j3 = 0; j3 < 8; j3++) {
//															if (valid(i3,j3,locNumPl2, locMas2)) {
//																num3++;
//																int guarProfit3 = guarProfit2;
//																int[][]locMas3 = new int[8][8];
//																copyMas(locMas2, locMas3);
//																int locNumPl3 = -1 *locNumPl;
//																guarProfit3 -= doStep(i3,j3,locNumPl3,locMas3);
//																
//																if (guarProfit3 < guarProfit)
//																	guarProfit = guarProfit3;
//															}
//														}
//												if (num3 == 0) {
//													guarProfit = 50;
//												}
											}
										}
								if (num2 == 0) {
									guarProfit = -100;
								}
								}
						}
					if (num1 == 0) {
						guarProfit = 100;
					}
				}
				if (guarProfit < 128) {
					if (guarProfit >= max) {
						if (guarProfit > max) {
							max = guarProfit;
							numOfMax = 1;
							maxCoord = coordToNum(i,j);
						}
						else {
							int r = generateRandom(++numOfMax);
							if ( r == (numOfMax - 1))
								maxCoord = coordToNum(i,j);
						}
					}
				}
			}
		return maxCoord;
	}
	
	
	int coverLn (int i, int j, int numPl, int iv, int jv, int[][] mas) {
		int sum = 0;
		while (((i + iv) > -1) && ((i + iv) < 8) && ((j + jv) > -1) && ((j + jv) < 8) && (mas[i+iv][j+jv] == (-1)*numPl)) {
			mas[i][j] = numPl;//just in massive
			sum++;
			i += iv;
			j += jv;
		}
		return sum;
	}
	
	int doStep (int i, int j, int numPl, int[][] mas) {
		int sum = 0;
		int iv = -1;
		for (int jv = -1; jv <= 1; jv++) {
			if (itLn (i, j, numPl, iv, jv, mas))
				sum += coverLn(i, j, numPl, iv, jv, mas);
		}
		iv = 0;
		for (int jv = -1; jv <= 1; jv += 2) {
			if (itLn (i, j, numPl, iv, jv, mas))
				sum += coverLn(i, j, numPl, iv, jv, mas);
		}
		iv = 1;
		for (int jv = -1; jv <= 1; jv++) {
			if (itLn (i, j, numPl, iv, jv, mas))
				sum += coverLn(i, j, numPl, iv, jv, mas);
		}
		return sum;
	}
	
	boolean itLn (int i, int j, int numPl, int iv, int jv, int[][] mas) {
		int a = 0;
		while (((i + iv) > -1) && ((i + iv) < 8) && ((j + jv) > -1) && ((j + jv) < 8) && (mas[i+iv][j+jv] == (-1)*numPl)) {
			i += iv;
			j += jv;
			a++;
		}
		if (((i + iv) > -1) && ((i + iv) < 8) && ((j + jv) > -1) && ((j + jv) < 8) && (mas[i+iv][j+jv] == numPl) && (a > 0))
			return true;
		else
			return false;
	}
}

package com.example.reversi;

public class MediumBot extends Bot {
	int choose (int[][] mas, int numPl) {
		int i = -1;
		int j = -1;
		
		int masProf[][] = new int[8][8];//mas of profit
		for (int a = 0; a < 8; a++)
			for (int b = 0; b < 8; b++)
				masProf[a][b] = 0;
		
		int masCop[][] = new int[8][8];
		copyMas(mas,masCop);
		
		int numOfMax = 0;//number of max
		int max = 0;
		int maxCoord = 0;//coordinates of max
		
		for (int a = 0; a < 8; a++)
			for (int b = 0; b < 8; b++)
				if (valid(a,b,numPl,mas))
					if (doStep(a,b,numPl,masCop) >= max) {
						if (doStep(a,b,numPl,masCop) == max) {//repeated max
							int r = generateRandom(++numOfMax);
							if ( r == (numOfMax - 1))
								maxCoord = coordToNum(a,b);
						}
						else {//it's a new max
							numOfMax = 1;
							max = doStep(a,b,numPl,masCop);
							maxCoord = coordToNum(a,b);
						}
					}
		return maxCoord;
	}
	
	int coverLn (int i, int j, int numPl, int iv, int jv, int[][] masCop) {
		int res = 0;
		while (((i + iv) > -1) && ((i + iv) < 8) && ((j + jv) > -1) && ((j + jv) < 8) && (masCop[i+iv][j+jv] == (-1)*numPl)) {
			res += 1;
			i += iv;
			j += jv;
		}
		return res;
	}
	
	int doStep (int i, int j, int numPl, int[][] masCop) {
		int res = 0;
		int iv = -1;
		for (int jv = -1; jv <= 1; jv++) {
			if (itLn (i, j, numPl, iv, jv, masCop))
				res += coverLn(i, j, numPl, iv, jv, masCop);
		}
		iv = 0;
		for (int jv = -1; jv <= 1; jv += 2) {
			if (itLn (i, j, numPl, iv, jv, masCop))
				res += coverLn(i, j, numPl, iv, jv, masCop);
		}
		iv = 1;
		for (int jv = -1; jv <= 1; jv++) {
			if (itLn (i, j, numPl, iv, jv, masCop))
				res += coverLn(i, j, numPl, iv, jv, masCop);
		}
		return res;
	}
	
}

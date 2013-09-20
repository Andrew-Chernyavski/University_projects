package com.example.reversi;
import java.util.Random;

import com.example.reversi.GameBoard2pl;

public abstract class Bot {
	abstract int choose(int[][] mas, int numPl);
	
	boolean[][] valids(int[][] mas, int numPl) {
		boolean[][] newMas = new boolean[8][8];	
		for (int i = 0; i < 7; i++)
			for (int j = 0; j < 7; j++) {
				if (valid(i,j,numPl, mas))
					newMas[i][j] = true;
				else
					newMas[i][j] = false;
			}
		return newMas;
	}
	
	boolean isNeighb (int i, int j, int numPl, int[][] mas) {
		boolean itIs = false;
		switch (i) {
		case 0:
			switch (j) {
			case 0:
				itIs = ((numPl * (-1) == mas[i+1][j]) || (numPl * (-1) == mas[i+1][j+1]) || (numPl * (-1) == mas[i][j+1]));
				break;
			case 7:
				itIs = ((numPl * (-1) == mas[i+1][j]) || (numPl * (-1) == mas[i+1][j-1]) || (numPl * (-1) == mas[i][j-1]));
				break;
			default:
				itIs = ((numPl * (-1) == mas[i][j+1]) || (numPl * (-1) == mas[i+1][j+1]) || (numPl * (-1) == mas[i+1][j]) || (numPl * (-1) == mas[i+1][j-1]) || (numPl * (-1) == mas[i][j-1]));
				break;
			}
			break;
		case 7:
			switch (j) {
			case 0:
				itIs = ((numPl * (-1) == mas[i-1][j]) || (numPl * (-1) == mas[i-1][j+1]) || (numPl * (-1) == mas[i][j+1]));
				break;
			case 7:
				itIs = ((numPl * (-1) == mas[i-1][j]) || (numPl * (-1) == mas[i][j-1]) || (numPl * (-1) == mas[i-1][j-1]));
				break;
			default:
				itIs = ((numPl * (-1) == mas[i-1][j]) || (numPl * (-1) == mas[i-1][j+1]) || (numPl * (-1) == mas[i][j+1]) || (numPl * (-1) == mas[i][j-1]) || (numPl * (-1) == mas[i-1][j-1]));
				break;
			}
			break;
		default:
			switch (j) {
			case 0:
				itIs = ((numPl * (-1) == mas[i-1][j]) || (numPl * (-1) == mas[i-1][j+1]) || (numPl * (-1) == mas[i][j+1]) || (numPl * (-1) == mas[i+1][j+1]) || (numPl * (-1) == mas[i+1][j]));
				break;
			case 7:
				itIs = ((numPl * (-1) == mas[i-1][j]) || (numPl * (-1) == mas[i+1][j]) || (numPl * (-1) == mas[i+1][j-1]) || (numPl * (-1) == mas[i][j-1]) || (numPl * (-1) == mas[i-1][j-1]));
				break;
			default:
				itIs = ((numPl * (-1) == mas[i-1][j]) || (numPl * (-1) == mas[i-1][j+1]) || (numPl * (-1) == mas[i][j+1]) || (numPl * (-1) == mas[i+1][j+1]) || (numPl * (-1) == mas[i+1][j]) || (numPl * (-1) == mas[i+1][j-1]) || (numPl * (-1) == mas[i][j-1]) || (numPl * (-1) == mas[i-1][j-1]));
				break;
			}
			break;
				
		}
		return itIs;
	}
	
	boolean isLn (int i, int j, int numPl, int[][] mas) {
		int iv = -1;
		for (int jv = -1; jv <= 1; jv++) {
			if (itLn (i, j, numPl, iv, jv, mas))
				return true;
		}
		iv = 0;
		for (int jv = -1; jv <= 1; jv += 2) {
			if (itLn (i, j, numPl, iv, jv, mas))
				return true;
		}
		iv = 1;
		for (int jv = -1; jv <= 1; jv++) {
			if (itLn (i, j, numPl, iv, jv, mas))
				return true;
		}
		return false;
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
	
	public boolean valid (int i, int j, int numPl, int[][] mas) {
		if (mas[i][j] != 0)
			return false;
		else if (!isNeighb(i,j,numPl, mas))
			return false;
		else if (!isLn(i,j,numPl,mas))
			return false;
		else return true;
	}
	
	static int getNewA(int range){
        Random random = new Random();
         int res = random.nextInt(range);
        return res;
    }
	
	static int generateRandom(int n) {
		Random random = new Random();
	return Math.abs(random.nextInt(n));
	}
	
	public int coordToNum (int i, int j) {
		return 10 * (i + 1) + j + 1;
	}
	
	public void copyMas (int[][] mas1, int[][] mas2) {
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				mas2[i][j] = mas1[i][j];
	}
}

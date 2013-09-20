package com.example.reversi;

import java.util.Random;

public class EasyBot extends Bot {
	int choose (int[][] mas, int numPl) {
		int i = -1;
		int j = -1;
		int a = 1;
		do {
		i = (int) generateRandom(8);
		j = (int) (7 - generateRandom(8));
		} while (!valid(i,j,numPl,mas));
		return coordToNum(i,j);
	}
}
package com.example.reversi;

import android.R.menu;
import android.app.Activity;
import android.content.Intent;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Button;

public class GameBoard2pl extends Activity implements OnClickListener {
	
	TextView player1bal;
	TextView player2bal;
	TextView player1move;
	TextView player2move;
	TextView textView1;
	TextView TextView01;
	
	ImageView imageView1;
	
	State st = new State();
	Bot bot1;
	Bot bot2;
	
	
	
	/*ImageView ImageView08;
	ImageView ImageView06;
	ImageView ImageView05;
	ImageView ImageView04;
	ImageView ImageView03;
	ImageView ImageView02;
	ImageView ImageView01;
	ImageView imageView3;
	
	
	ImageView ImageView15;
	ImageView ImageView14;
	ImageView ImageView13;
	ImageView ImageView12;
	ImageView ImageView11;
	ImageView ImageView10;
	ImageView ImageView09;
	ImageView ImageView07;
	
	
	ImageView ImageView23;
	ImageView ImageView22;
	ImageView ImageView21;
	ImageView ImageView20;
	ImageView ImageView19;
	ImageView ImageView18;
	ImageView ImageView17;
	ImageView ImageView16;
	
	ImageView imageView4;
	ImageView ImageView58;
	ImageView ImageView57;
	ImageView ImageView56;
	ImageView ImageView55;
	ImageView ImageView54;
	ImageView ImageView50;
	ImageView ImageView49;
	
	
	ImageView imageView5;
	ImageView ImageView61;
	ImageView ImageView60;
	ImageView ImageView59;
	ImageView ImageView53;
	ImageView ImageView52;
	ImageView ImageView51;
	ImageView ImageView48;
	
	
	ImageView ImageView31;
	ImageView ImageView30;
	ImageView ImageView29;
	ImageView ImageView28;
	ImageView ImageView27;
	ImageView ImageView26;
	ImageView ImageView25;
	ImageView ImageView24;
	
	
	ImageView ImageView39;
	ImageView ImageView38;
	ImageView ImageView37;
	ImageView ImageView36;
	ImageView ImageView35;
	ImageView ImageView34;
	ImageView ImageView33;
	ImageView ImageView32;
	
	
	ImageView ImageView0dp;
	ImageView ImageView47;
	ImageView ImageView46;
	ImageView ImageView45;
	ImageView ImageView44;
	ImageView ImageView43;
	ImageView ImageView42;
	ImageView ImageView41;*/
	
	ImageView[][] imMas = new ImageView[8][8];
	int[][] mas = new int[8][8];
    int numPl;
    int pl1bal;
    int pl2bal;
    int mis;
    ImageView imageView6;
    ImageView imageView7;
    boolean playerClick;
    boolean endGame;
		
	void initMas() {
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				mas[i][j] = 0;
		mas[3][3] = 1;
		mas[4][4] = 1;
		mas[3][4] = -1;
		mas[4][3] = -1;
	};
	
	@Override
	  protected void onCreate(Bundle savedInstanceState) {
	    super.onCreate(savedInstanceState);
	    setContentView(R.layout.board2pl);
	    endGame = false;
	    imMas[0][0] = (ImageView) findViewById(R.id.ImageView08);
	    imMas[0][1] = (ImageView) findViewById(R.id.ImageView06);
	    imMas[0][2] = (ImageView) findViewById(R.id.ImageView05);
	    imMas[0][3] = (ImageView) findViewById(R.id.ImageView04);
	    imMas[0][4] = (ImageView) findViewById(R.id.ImageView03);
	    imMas[0][5] = (ImageView) findViewById(R.id.ImageView02);
	    imMas[0][6] = (ImageView) findViewById(R.id.ImageView01);
	    imMas[0][7] = (ImageView) findViewById(R.id.imageView3);
	    
	    imMas[1][0] = (ImageView) findViewById(R.id.ImageView15);
	    imMas[1][1] = (ImageView) findViewById(R.id.ImageView14);
	    imMas[1][2] = (ImageView) findViewById(R.id.ImageView13);
	    imMas[1][3] = (ImageView) findViewById(R.id.ImageView12);
	    imMas[1][4] = (ImageView) findViewById(R.id.ImageView11);
	    imMas[1][5] = (ImageView) findViewById(R.id.ImageView10);
	    imMas[1][6] = (ImageView) findViewById(R.id.ImageView09);
	    imMas[1][7] = (ImageView) findViewById(R.id.ImageView07);
	    
	    imMas[2][0] = (ImageView) findViewById(R.id.ImageView23);
	    imMas[2][1] = (ImageView) findViewById(R.id.ImageView22);
	    imMas[2][2] = (ImageView) findViewById(R.id.ImageView21);
	    imMas[2][3] = (ImageView) findViewById(R.id.ImageView20);
	    imMas[2][4] = (ImageView) findViewById(R.id.ImageView19);
	    imMas[2][5] = (ImageView) findViewById(R.id.ImageView18);
	    imMas[2][6] = (ImageView) findViewById(R.id.ImageView17);
	    imMas[2][7] = (ImageView) findViewById(R.id.ImageView16);
	    
	    imMas[3][3] = (ImageView) findViewById(R.id.imageView4);
	    imMas[3][0] = (ImageView) findViewById(R.id.ImageView58);
	    imMas[3][1] = (ImageView) findViewById(R.id.ImageView57);
	    imMas[3][2] = (ImageView) findViewById(R.id.ImageView56);
	    imMas[3][4] = (ImageView) findViewById(R.id.ImageView55);
	    imMas[3][5] = (ImageView) findViewById(R.id.ImageView54);
	    imMas[3][6] = (ImageView) findViewById(R.id.ImageView50);
	    imMas[3][7] = (ImageView) findViewById(R.id.ImageView49);
	   
	    imMas[4][3] = (ImageView) findViewById(R.id.imageView5);
	    imMas[4][0] = (ImageView) findViewById(R.id.ImageView61);
	    imMas[4][1] = (ImageView) findViewById(R.id.ImageView60);
	    imMas[4][2] = (ImageView) findViewById(R.id.ImageView59);
	    imMas[4][5] = (ImageView) findViewById(R.id.ImageView53);
	    imMas[4][6] = (ImageView) findViewById(R.id.ImageView52);
	    imMas[4][7] = (ImageView) findViewById(R.id.ImageView51);
	    imMas[4][4] = (ImageView) findViewById(R.id.ImageView48);
	    
	    imMas[5][0] = (ImageView) findViewById(R.id.ImageView31);
	    imMas[5][1] = (ImageView) findViewById(R.id.ImageView30);
	    imMas[5][2] = (ImageView) findViewById(R.id.ImageView29);
	    imMas[5][3] = (ImageView) findViewById(R.id.ImageView28);
	    imMas[5][4] = (ImageView) findViewById(R.id.ImageView27);
	    imMas[5][5] = (ImageView) findViewById(R.id.ImageView26);
	    imMas[5][6] = (ImageView) findViewById(R.id.ImageView25);
	    imMas[5][7] = (ImageView) findViewById(R.id.ImageView24);
	    
	    imMas[6][0] = (ImageView) findViewById(R.id.ImageView39);
	    imMas[6][1] = (ImageView) findViewById(R.id.ImageView38);
	    imMas[6][2] = (ImageView) findViewById(R.id.ImageView37);
	    imMas[6][3] = (ImageView) findViewById(R.id.ImageView36);
	    imMas[6][4] = (ImageView) findViewById(R.id.ImageView35);
	    imMas[6][5] = (ImageView) findViewById(R.id.ImageView34);
	    imMas[6][6] = (ImageView) findViewById(R.id.ImageView33);
	    imMas[6][7] = (ImageView) findViewById(R.id.ImageView32);
	    
	    imMas[7][7] = (ImageView) findViewById(R.id.ImageView0dp);
	    imMas[7][0] = (ImageView) findViewById(R.id.ImageView47);
	    imMas[7][1] = (ImageView) findViewById(R.id.ImageView46);
	    imMas[7][2] = (ImageView) findViewById(R.id.ImageView45);
	    imMas[7][3] = (ImageView) findViewById(R.id.ImageView44);
	    imMas[7][4] = (ImageView) findViewById(R.id.ImageView43);
	    imMas[7][5] = (ImageView) findViewById(R.id.ImageView42);
	    imMas[7][6] = (ImageView) findViewById(R.id.ImageView41);
	    
	    for (int i = 0; i < 8; i++) {
	    	for (int j = 0; j < 8; j++) {
	    		imMas[i][j].setOnClickListener(this);
	    	}
	    }
	    
	    imageView6 = (ImageView) findViewById(R.id.imageView6);
	    imageView7 = (ImageView) findViewById(R.id.imageView7);
	    imageView6.setOnClickListener(this);
	    imageView7.setOnClickListener(this);
	    initMas();
	    player1move = (TextView) findViewById(R.id.player1move);
	    player2move = (TextView) findViewById(R.id.player2move);
	    textView1 = (TextView) findViewById(R.id.textView1);
	    TextView01 = (TextView) findViewById(R.id.TextView01);
	    
	    player1bal = (TextView) findViewById(R.id.player1bal);
	    player2bal = (TextView) findViewById(R.id.player2bal);
	    numPl = -1;
	    pl1bal = 2;
	    pl2bal = 2;
	    st.setPlayer1(getIntent().getExtras().getInt("player1"));
	    st.setPlayer2(getIntent().getExtras().getInt("player2"));
	    
	    switch (st.getPlayer1()) {
	    case 1:
	    	bot1 = new EasyBot();
    		textView1.setText("Easy");
    		break;
	    case 2:
	    	bot1 = new MediumBot();
    		textView1.setText("Medium");
    		break;
	    case 3:
	    	bot1 = new HardBot();
    		textView1.setText("Hard-1");
    		break;
	    case 4:
	    	bot1 = new Hard2Bot();
    		textView1.setText("Hard-2");
    		break;
	    }
	    
	    switch (st.getPlayer2()) {
	    case 1:
	    	bot2 = new EasyBot();
    		TextView01.setText("Easy");
    		break;
	    case 2:
	    	bot2 = new MediumBot();
    		TextView01.setText("Medium");
    		break;
	    case 3:
	    	bot2 = new HardBot();
    		TextView01.setText("Hard-1");
    		break;
	    case 4:
	    	bot2 = new Hard2Bot();
    		TextView01.setText("Hard-2");
    		break;
	    }
	    
	    /*clicked = true;
	    while (!endGame && !playerClick) {
	    	if (numPl == -1) {//black's move
	    	if (st.getPlayer1() == 0) {
	    		playerClick = true;
	    		clicked = false;
	    	}
	    	else//it's a bot
	    		move(bot1.choose(mas, numPl));
	    	}
	    	else {//white's move, numPl == 1
	    		if (st.getPlayer2() == 0) {
	    			playerClick = true;
	    			clicked = false;
	    		}
	    		else
	    			move(bot2.choose(mas, numPl));
	    		}
	    }*/
	    //TextView01.setText(Integer.toString(numPl));
	    if (st.getPlayer1() == 0)
	    	playerClick = true;
	    else {
	    	playerClick = false;
	    }
	    endGame = false;
    }
	
	
	boolean isNeighb (int i, int j, int numPl) {
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
	
	boolean isLn (int i, int j, int numPl) {
		int iv = -1;
		for (int jv = -1; jv <= 1; jv++) {
			if (itLn (i, j, numPl, iv, jv))
				return true;
		}
		iv = 0;
		for (int jv = -1; jv <= 1; jv += 2) {
			if (itLn (i, j, numPl, iv, jv))
				return true;
		}
		iv = 1;
		for (int jv = -1; jv <= 1; jv++) {
			if (itLn (i, j, numPl, iv, jv))
				return true;
		}
		return false;
	}
	
	boolean itLn (int i, int j, int numPl, int iv, int jv) {
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
	
	public boolean valid (int i, int j, int numPl) {
		if (mas[i][j] != 0)
			return false;
		else if (!isNeighb(i,j,numPl))
			return false;
		else if (!isLn(i,j,numPl))
			return false;
		else return true;
	}
	
	void setCh (int i, int j, int numPl) {
		ImageView imag = imMas[i][j];
		if (numPl == 1)
			imag.setImageDrawable(getResources().getDrawable(R.drawable.white));
		else
			imag.setImageDrawable(getResources().getDrawable(R.drawable.black));
		mas[i][j] = numPl;
	}
	
	void coverLn (int i, int j, int numPl, int iv, int jv) {
		while (((i + iv) > -1) && ((i + iv) < 8) && ((j + jv) > -1) && ((j + jv) < 8) && (mas[i+iv][j+jv] == (-1)*numPl)) {
			setCh (i+iv,j+jv,numPl);
			i += iv;
			j += jv;
		}
	}
	
	void doStep (int i, int j, int numPl) {
		int iv = -1;
		for (int jv = -1; jv <= 1; jv++) {
			if (itLn (i, j, numPl, iv, jv))
				coverLn(i, j, numPl, iv, jv);
		}
		iv = 0;
		for (int jv = -1; jv <= 1; jv += 2) {
			if (itLn (i, j, numPl, iv, jv))
				coverLn(i, j, numPl, iv, jv);
		}
		iv = 1;
		for (int jv = -1; jv <= 1; jv++) {
			if (itLn (i, j, numPl, iv, jv))
				coverLn(i, j, numPl, iv, jv);
		}
	}
	
	void refresh (int numPl) {
		if (numPl == 1) {
			player1move.setText(">");
			player2move.setText("");
		}
		else {
			player2move.setText(">");
			player1move.setText("");
		}
		
		pl1bal = 0;
		pl2bal = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++) {
				if (mas[i][j] == 1)
					pl2bal++;
				else if (mas[i][j] == -1)
					pl1bal++;
			}
		player1bal.setText(Integer.toString(pl1bal));
		player2bal.setText(Integer.toString(pl2bal));
	}
	
	public void move (int num) {
		//playerClick = true;
		int i = num / 10 - 1;
		int j = num % 10 - 1;
		if (valid(i,j,numPl)) {
			doStep (i,j,numPl);
			setCh (i,j,numPl);
			refresh (numPl);
			numPl *= -1;
			playerClick = false;
			if ((st.getPlayer1() == 0) && (numPl == -1))
				playerClick = true;
			if ((st.getPlayer2() == 0) && (numPl == 1))
				playerClick = true;	
			checkWin(numPl);
		}
	}
	
	public void checkWin (int numPl) {
		int a = 0;
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++) {
				if (valid (i,j,numPl))
					a++;
			}
		if (a == 0) {
			endGame = true;
			player1move.setText("!");
			player2move.setText("!");
			numPl *= -1;
			int b = 0;
			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++) {
					if (valid (i,j,numPl))
						b++;
				}
			}
			if (b > 0) {
				if (numPl == 1) {
					player1move.setText("!");
					player2move.setText(">");
				}
				else {
					player2move.setText("!");
					player1move.setText(">");
				}
			}
				else  {
					if (pl1bal > pl2bal) {
						TextView01.setText("Looser");
						textView1.setText("Winner");
					}
					else {
						TextView01.setText("Winner");
						textView1.setText("Looser");
					}
				}
		}
	}
	
	
	public void onClick(View v) {
		if (!endGame) {
			if (playerClick) {
	        switch (v.getId()) {
	        //row1
	        case R.id.ImageView06:
	        	move(12);
		          break;
	        case R.id.ImageView08:
	        	move(11);
		          break;
	        case R.id.ImageView05:
	        	move(13);
		          break;
	        case R.id.ImageView04:
	        	move(14);
		          break;
	        case R.id.ImageView03:
	        	move(15);
		          break;
	        case R.id.ImageView02:
	        	move(16);
		          break;
	        case R.id.ImageView01:
	        	move(17);
		          break;
	        case R.id.imageView3:
	        	move(18);
		          break;
		          
		    //row2
	        case R.id.ImageView15:
	        	move(21);
		          break;
	        case R.id.ImageView14:
	        	move(22);
		          break;
	        case R.id.ImageView13:
	        	move(23);
		          break;
	        case R.id.ImageView12:
	        	move(24);
		          break;
	        case R.id.ImageView11:
	        	move(25);
		          break;
	        case R.id.ImageView10:
	        	move(26);
		          break;
	        case R.id.ImageView09:
	        	move(27);
		          break;
	        case R.id.ImageView07:
	        	move(28);
		          break;
		          
		    //row3
	        case R.id.ImageView23:
	        	move(31);
		          break;
	        case R.id.ImageView22:
	        	move(32);
		          break;
	        case R.id.ImageView21:
	        	move(33);
		          break;
	        case R.id.ImageView20:
	        	move(34);
		          break;
	        case R.id.ImageView19:
	        	move(35);
		          break;
	        case R.id.ImageView18:
	        	move(36);
		          break;
	        case R.id.ImageView17:
	        	move(37);
		          break;
	        case R.id.ImageView16:
	        	move(38);
		          break;
		          
		    //row4
	        case R.id.ImageView58:
	        	move(41);
		          break;
	        case R.id.ImageView57:
	        	move(42);
		          break;
	        case R.id.ImageView56:
	        	move(43);
		          break;
	        case R.id.imageView4:
	        	move(44);
		          break;
	        case R.id.ImageView55:
	        	move(45);
		          break;
	        case R.id.ImageView54:
	        	move(46);
		          break;
	        case R.id.ImageView50:
	        	move(47);
		          break;
	        case R.id.ImageView49:
	        	move(48);
		          break;
		          
		    //row5
	        case R.id.ImageView61:
	        	move(51);
		          break;
	        case R.id.ImageView60:
	        	move(52);
		          break;
	        case R.id.ImageView59:
	        	move(53);
		          break;
	        case R.id.imageView5:
	        	move(54);
		          break;
	        case R.id.ImageView48:
	        	move(55);
		          break;
	        case R.id.ImageView53:
	        	move(56);
		          break;
	        case R.id.ImageView52:
	        	move(57);
		          break;
	        case R.id.ImageView51:
	        	move(58);
		          break;
		          
		    //row6
	        case R.id.ImageView31:
	        	move(61);
		          break;
	        case R.id.ImageView30:
	        	move(62);
		          break;
	        case R.id.ImageView29:
	        	move(63);
		          break;
	        case R.id.ImageView28:
	        	move(64);
		          break;
	        case R.id.ImageView27:
	        	move(65);
		          break;
	        case R.id.ImageView26:
	        	move(66);
		          break;
	        case R.id.ImageView25:
	        	move(67);
		          break;
	        case R.id.ImageView24:
	        	move(68);
		          break;
		          
		          
		    //row7
	        case R.id.ImageView39:
	        	move(71);
		          break;
	        case R.id.ImageView38:
	        	move(72);
		          break;
	        case R.id.ImageView37:
	        	move(73);
		          break;
	        case R.id.ImageView36:
	        	move(74);
		          break;
	        case R.id.ImageView35:
	        	move(75);
		          break;
	        case R.id.ImageView34:
	        	move(76);
		          break;
	        case R.id.ImageView33:
	        	move(77);
		          break;
	        case R.id.ImageView32:
	        	move(78);
		          break;
		          
		    //row8
	        case R.id.ImageView47:
	        	move(81);
		          break;
	        case R.id.ImageView46:
	        	move(82);
		          break;
	        case R.id.ImageView45:
	        	move(83);
		          break;
	        case R.id.ImageView44:
	        	move(84);
		          break;
	        case R.id.ImageView43:
	        	move(85);
		          break;
	        case R.id.ImageView42:
	        	move(86);
		          break;
	        case R.id.ImageView41:
	        	move(87);
		          break;
	        case R.id.ImageView0dp:
	        	move(88);
		          break;
	        }
	        //playerClick = false;
			}
			
		       else {
		        	switch (v.getId()) {
		        	case R.id.imageView6:
		        		if ((st.getPlayer1() > 0) && (numPl == -1))
		        			move(bot1.choose(mas, numPl));
		        		break;
		        	case R.id.imageView7:
		        		if ((st.getPlayer2() > 0) && (numPl == 1))
		        			move(bot2.choose(mas, numPl));
		        	break;
		        	}
		        }
		}
        //clicked = true;
		}
	
	
	public boolean onCreateOptionsMenu(Menu menu) {
	      // TODO Auto-generated method stub
	      
	      menu.add("Go to Main Menu");
	      
	      return super.onCreateOptionsMenu(menu);
	    }
	
	@Override
    public boolean onOptionsItemSelected(MenuItem item) {
      // TODO Auto-generated method stub
      if (item.getTitle() == "Go to Main Menu")
    	  finish();
      return super.onOptionsItemSelected(item);
    }

}

package com.example.reversi;

public class State {
	private int player1;
	private int player2;
	State() {
		player1 = 0;
		player2 = 0;
	}
	public void setPlayer1 (int num) {
		this.player1 = num;
	}
	public void setPlayer2 (int num) {
		this.player2 = num;
	}
	public int getPlayer1() {
		return this.player1;
	}
	public int getPlayer2() {
		return this.player2;
	}
}

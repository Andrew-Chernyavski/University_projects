package com.example.reversi;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.RadioButton;
import android.widget.TextView;

public class MainActivity extends Activity implements OnClickListener {
	
	Button singlePl;
	Button twoPl;
	Button exit;
	TextView tvOut;
	ImageView imageView1;
	RadioButton Player1;
	RadioButton Player2;
	RadioButton BotRandom1;
	RadioButton BotRandom2;
	RadioButton BotMed1;
	RadioButton BotMed2;
	RadioButton BotHard1;
	RadioButton BotHard2;
	RadioButton Bot2Hard1;
	RadioButton Bot2Hard2;
	
	OnClickListener radioListener;
	State st = new State();


	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);
		tvOut = (TextView) findViewById(R.id.tvOut);
	    twoPl = (Button) findViewById(R.id.twoPl);
	    twoPl.setOnClickListener(this);
	    exit = (Button) findViewById(R.id.exit);
	    exit.setOnClickListener(this);
	    //Player1 = (RadioButton) findViewById(R.id.RadioButton01);
	    //Player2 = (RadioButton) findViewById(R.id.RadioButton02);
	   // BotRandom1 = (RadioButton) findViewById(R.id.radio0);
	   // BotRandom2 = (RadioButton) findViewById(R.id.radio3);
	    //BotMed1 = (RadioButton) findViewById(R.id.radio1);
	    //BotMed2 = (RadioButton) findViewById(R.id.radio4);
	   // BotHard1 = (RadioButton) findViewById(R.id.radio2);
	    //BotHard2 = (RadioButton) findViewById(R.id.radio5);
	    
	    radioListener = new OnClickListener() {
	    	@Override
	    	public void onClick(View v) {
	    		// TODO Auto-generated method stub
	    		RadioButton rb = (RadioButton)v;
	    		switch (rb.getId()) {
	    		case R.id.RadioButton01:
	    			st.setPlayer1(0);
	    		    break;
	    		case R.id.RadioButton02:
	    			st.setPlayer2(0);
	    		    break;
	    		case R.id.radio0:
	    			st.setPlayer1(1);
	    		    break;
	    		case R.id.radio3:
	    			st.setPlayer2(1);
	    		    break;
	    		case R.id.radio1:
	    			st.setPlayer1(2);
	    		    break;
	    		case R.id.radio4:
	    			st.setPlayer2(2);
	    		    break;
	    		case R.id.radio2:
	    			st.setPlayer1(3);
	    		    break;
	    		case R.id.radio5:
	    			st.setPlayer2(3);
	    		    break;
	    		case R.id.radioButton1:
	    			st.setPlayer1(4);
	    		    break;
	    		case R.id.RadioButton03:
	    			st.setPlayer2(4);
	    		    break;
//
//	    		default:
//	    			tvOut.setText("they are not yet...");
//	    			break;
	    		}
	    	}
	    };
	    RadioButton radPl1 = (RadioButton)findViewById(R.id.RadioButton01);
	    radPl1.setOnClickListener(radioListener);

	    RadioButton radPl2 = (RadioButton)findViewById(R.id.RadioButton02);
	    radPl2.setOnClickListener(radioListener);

	    RadioButton radBRan1 = (RadioButton)findViewById(R.id.radio0);
	    radBRan1.setOnClickListener(radioListener);

	    RadioButton radBran2 = (RadioButton)findViewById(R.id.radio3);
	    radBran2.setOnClickListener(radioListener);
	    
	    RadioButton radBmed1 = (RadioButton)findViewById(R.id.radio1);
	    radBmed1.setOnClickListener(radioListener);
	    
	    RadioButton radBmed2 = (RadioButton)findViewById(R.id.radio4);
	    radBmed2.setOnClickListener(radioListener);
	    
	    RadioButton radBhard1 = (RadioButton)findViewById(R.id.radio2);
	    radBhard1.setOnClickListener(radioListener);
	    
	    RadioButton radBhard2 = (RadioButton)findViewById(R.id.radio5);
	    radBhard2.setOnClickListener(radioListener);
	    
	    RadioButton radB2hard1 = (RadioButton)findViewById(R.id.radioButton1);
	    radB2hard1.setOnClickListener(radioListener);
	    
	    RadioButton radB2hard2 = (RadioButton)findViewById(R.id.RadioButton03);
	    radB2hard2.setOnClickListener(radioListener);
	    
	    
	}
	    
	    @Override
	    public void onClick(View v) {
	        switch (v.getId()) {
	       case R.id.twoPl:
	        	Intent intent = new Intent(this, GameBoard2pl.class);
	        	intent.putExtra ("player1", st.getPlayer1());
	        	intent.putExtra ("player2", st.getPlayer2());
	            startActivity(intent);
		          break;
	        case R.id.exit:
	        	finish();
		          break;
	        default:
	        	tvOut.setText("What?");
	          break;
	        }
	      }


	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
}

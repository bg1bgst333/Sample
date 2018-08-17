package com.bgstation0.android.sample.recognitionlistener_;

import java.util.ArrayList;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.speech.RecognitionListener;
import android.speech.RecognizerIntent;
import android.speech.SpeechRecognizer;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity implements View.OnClickListener, RecognitionListener{

	// �����o�t�B�[���h�̒�`.
	SpeechRecognizer mSpeechRecognizer = null;	// mSpeechRecognizer��null�ŏ�����.
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // �{�^���Ƀ��X�i�[���Z�b�g.
        Button button1 = (Button)findViewById(R.id.button1);	// button1���擾.
        button1.setOnClickListener(this);	// this���Z�b�g.
        
        // SpeechRecognizer�̍쐬.
        mSpeechRecognizer = SpeechRecognizer.createSpeechRecognizer(this);	// mSpeechRecognizer���쐬.
        mSpeechRecognizer.setRecognitionListener(this);	// ���X�i�[�Ƃ���this���Z�b�g.
        
    }
    
    // �N���b�N���ꂽ��.
    @Override
    public void onClick(View v){
    	
    	// �C���e���g�쐬.
    	try{	// try�ň͂�.
    		Intent intent = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);	// Intent�̃R���X�g���N�^��RecognizerIntent.ACTION_RECOGNIZE_SPEECH��n����intent�쐬.
    		intent.putExtra(RecognizerIntent.EXTRA_LANGUAGE_MODEL, RecognizerIntent.LANGUAGE_MODEL_FREE_FORM);	// ���ꃂ�f���̓t���[�t�H�[��.
    		intent.putExtra(RecognizerIntent.EXTRA_CALLING_PACKAGE, getPackageName());	// �Ăяo���p�b�P�[�W��.
    		mSpeechRecognizer.startListening(intent);	// ���X�j���O�J�n.
    	}
    	catch (Exception ex){
    		Toast.makeText(this, "ex = " + ex.toString(), Toast.LENGTH_LONG).show();	// ex.toString()���o��.
    	}
    	
    }
    
    // �����F���̏���������.
    @Override
    public void onReadyForSpeech(Bundle params) {
    
    	// "onReadyForSpeech"�ƕ\��.
    	TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1���擾.
    	textview1.setText("onReadyForSpeech");
    	
    }
    
    // �����F���̓��͊J�n��.
    @Override
    public void onBeginningOfSpeech(){
    	
    	// "onBeginningOfSpeech"�ƕ\��.
    	TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1���擾.
    	textview1.setText("onBeginningOfSpeech");	// "onBeginningOfSpeech"���Z�b�g.
    	
    }
    
    // RMS�`�F���W.
    @Override
    public void onRmsChanged(float rmsdB) {
    	
    	// "onRmsChanged"�ƕ\��.
    	//TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1���擾.
    	//textview1.setText("onRmsChanged");	// "onRmsChanged"���Z�b�g.
    	
    }
    
    // �C�x���g������.
    @Override
    public void onEvent(int eventType, Bundle params) {
    	
    	// "onEvent"�ƕ\��.
    	TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1���擾.
    	textview1.setText("onEvent");	// "onEvent"���Z�b�g.
    	
    }
    
    //�@�o�b�t�@��M��.
    @Override
    public void onBufferReceived(byte[] buffer) {
        
    	// "onBufferReceived"�ƕ\��.
    	TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1���擾.
    	textview1.setText("onBufferReceived");	// "onBufferReceived"���Z�b�g.
    	
    }
    
    // �G���[������.
    @Override
    public void onError(int error) {
    	
    	// "onError"�ƕ\��.
    	TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1���擾.
    	textview1.setText("onError");	// "onError"���Z�b�g.
    	
    }
    
    // �����F���̌��ʎ�.
    @Override
    public void onResults(Bundle results) {
    	
    	// "onResults"�ƕ\��.
    	TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1���擾.
    	textview1.setText("onResults");	// "onResults"���Z�b�g.
    
    	// ArrayList<String>�ŕԂ��Ă���.
		ArrayList<String> aryListStrs = results.getStringArrayList(SpeechRecognizer.RESULTS_RECOGNITION);	// aryListStrs���擾.
		String result = "";	// result��""�ŏ�����.
		for (int i = 0; i < aryListStrs.size() - 1; i++){	// (�P��̌� - 1)��J��Ԃ�.
			result = result + aryListStrs.get(i);	// result��i�Ԗڂ�A��.
			result = result + " ";	// �X�y�[�X��A��.
		}
		result = result + aryListStrs.get(aryListStrs.size() - 1);	// �Ō�̗v�f��A��.
		EditText edittext1 = (EditText)findViewById(R.id.edittext1);
		edittext1.setText(result);	// edittext1.setText��result���Z�b�g.
		
    }
    
    // �������͂̏I����.
    @Override
    public void onEndOfSpeech() {
    	
    	// "onEndOfSpeech"�ƕ\��.
    	TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1���擾.
    	textview1.setText("onEndOfSpeech");	// "onEndOfSpeech"���Z�b�g.
    	
    }
    
    // �����I�ȔF�����ʎ�.
    @Override
    public void onPartialResults(Bundle partialResults) {
    	
    	// "onPartialResults"�ƕ\��.
    	TextView textview1 = (TextView)findViewById(R.id.textview1);	// textview1���擾.
    	textview1.setText("onPartialResults");	// "onPartialResults"���Z�b�g.
    	
    }
    
}
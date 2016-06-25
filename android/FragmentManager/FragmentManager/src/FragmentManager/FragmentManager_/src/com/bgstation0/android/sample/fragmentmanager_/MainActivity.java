package com.bgstation0.android.sample.fragmentmanager_;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        // FragmentManagerを取得.
        FragmentManager fragmentManager = getFragmentManager();	// getFragmentManagerでfragmentManagerを取得.
        // idが"fragment1"となるFragmentを取得.
        Fragment fragment1 = fragmentManager.findFragmentById(R.id.fragment1);	// fragmentManager.findFragmentByIdで"fragment1"なるidのFragmentを探して取得.
        if (fragment1 == null){	// nullなら.
        	Toast.makeText(this, "fragment1 is not exist!", Toast.LENGTH_LONG).show();	// "fragment1 is not exist!"と表示.
        }
        else{
        	Toast.makeText(this, "fragment1 is exist!", Toast.LENGTH_LONG).show();	// "fragment1 is exist!"と表示.
        }
        // idが"fragment2"となるFragmentを取得.
        Fragment fragment2 = fragmentManager.findFragmentById(R.id.fragment2);	// fragmentManager.findFragmentByIdで"fragment2"なるidのFragmentを探して取得.
        if (fragment2 == null){	// nullなら.
        	Toast.makeText(this, "fragment2 is not exist!", Toast.LENGTH_LONG).show();	// "fragment2 is not exist!"と表示.
        }
        else{
        	Toast.makeText(this, "fragment2 is exist!", Toast.LENGTH_LONG).show();	// "fragment2 is exist!"と表示.
        }
        // Fragmentとしては存在しないidをfindFragmentByIdしてみる.
        Fragment fragment3 = fragmentManager.findFragmentById(R.id.fragment1_textview);	// fragmentManager.findFragmentByIdで"fragment1_textview"というFragmentとしては存在しないidを指定してみる.
        if (fragment3 == null){	// nullなら.
        	Toast.makeText(this, "fragment3 is not exist!", Toast.LENGTH_LONG).show();	// "fragment3 is not exist!"と表示.
        }
        else{
        	Toast.makeText(this, "fragment3 is exist!", Toast.LENGTH_LONG).show();	// "fragment3 is exist!"と表示.
        }
    }
}
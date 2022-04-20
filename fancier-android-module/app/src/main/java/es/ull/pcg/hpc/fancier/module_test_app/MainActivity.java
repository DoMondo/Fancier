package es.ull.pcg.hpc.fancier.module_test_app;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;

import es.ull.pcg.hpc.fancier.Fancier;
import es.ull.pcg.hpc.fancier.image.RGBAImage;

public class MainActivity extends AppCompatActivity  {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Fancier.init(getCacheDir().getAbsolutePath());
        RGBAImage img = new RGBAImage(600, 400);
        Log.d("", "image is created");
    }

}
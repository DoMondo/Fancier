package es.ull.pcg.hpc.fancier.module_test_app;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;

import java.nio.ByteBuffer;

import es.ull.pcg.hpc.fancier.Fancier;
import es.ull.pcg.hpc.fancier.array.ByteArray;
import es.ull.pcg.hpc.fancier.image.RGBAImage;

public class MainActivity extends AppCompatActivity  {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Fancier.init(getCacheDir().getAbsolutePath());
        for (int i = 0; i < 10000; i ++) {
            ByteBuffer b = ByteBuffer.allocateDirect(1024 * 1024 * 10);
            ByteArray ba = new ByteArray(b);
            try {
                ba.close();
                ba.release();
                ba.finalize();
            } catch (Throwable throwable) {
                throwable.printStackTrace();
            }

        }
    }

}
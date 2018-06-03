package com.mobilegg.jnidemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        JNIUtil util = new JNIUtil();

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(util.stringFromJNI());

        String str = "catdog";
        util.testJString(str);

        int[] intArr = {1,2,3,4};
        util.testJIntArray(intArr);

        String[] strArr = {"abc", "123", "#$%"};
        util.testJObjectArray(strArr);

        Student student = new Student();
        student.age = 12;
        student.id = "100001";
        student.name = "Thomas";
        student.isBoy = true;
        util.testComplexObject(student);
    }
}

package com.lucasjoviniano.test;

import com.lucasjoviniano.main.Main;
import org.junit.jupiter.api.Test;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class MainTest {

    @Test
    void testMainMethod() {
        String userInput = "2 3\n500 700\n700 500 500\n2 2\n200 400\n200 1000\n3 4\n530 510 490\n480 470 50 310\n0 0\n";
        String expectedOutput = "N\nY\nN\n";

        ByteArrayInputStream inStream = new ByteArrayInputStream(userInput.getBytes());
        ByteArrayOutputStream outStream = new ByteArrayOutputStream();
        PrintStream print = new PrintStream(outStream);
        System.setIn(inStream);
        System.setOut(print);

        Main.main(null);

        assertEquals(expectedOutput, outStream.toString());
    }
}

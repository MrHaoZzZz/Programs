package cn.gtiit.isp.arithmetic_interpreter;

import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class ArithmeticInterpreterApplication {

    public static void main(String[] args) {

        Reader r = new Reader(
            "(define x 5)"
          + "(define y 307)"
          + "(print (+ (* x x) 1 (- y 7 200)))"
        );

        Interpreter i = new Interpreter();
        i.runProgram(r.readProgram());  // Should print 126
    }
}

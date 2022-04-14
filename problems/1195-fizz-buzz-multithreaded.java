// Solved 2022-04-14
// Runtime: 6 ms (84.47%)
// Memory Usage: 42.1 MB (83.55%)

import java.util.function.IntConsumer;
import java.util.function.IntPredicate;

class FizzBuzz {
    private int n;
    private int i;

    public FizzBuzz(int n) {
        this.n = n;
        this.i = 1;
    }

    private void run(IntPredicate test, IntConsumer print) throws InterruptedException {
        while (true) {
            while (i <= n && !test.test(i)) {
                wait();
            }
            if (i > n) {
                break;
            }
            print.accept(i);
            ++i;
            notifyAll();
        }
    }

    // printFizz.run() outputs "fizz".
    public synchronized void fizz(Runnable printFizz) throws InterruptedException {
        run(i -> i % 3 == 0 && i % 5 != 0, i -> printFizz.run());
    }

    // printBuzz.run() outputs "buzz".
    public synchronized void buzz(Runnable printBuzz) throws InterruptedException {
        run(i -> i % 3 != 0 && i % 5 == 0, i -> printBuzz.run());
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public synchronized void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        run(i -> i % 15 == 0, i -> printFizzBuzz.run());
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public synchronized void number(IntConsumer printNumber) throws InterruptedException {
        run(i -> i % 3 != 0 && i % 5 != 0, printNumber);
    }
}

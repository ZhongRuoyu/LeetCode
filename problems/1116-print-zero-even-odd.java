// Solved 2022-04-13
// Runtime: 5 ms (100.00%)
// Memory Usage: 41.3 MB (85.78%)

import java.util.concurrent.Semaphore;
import java.util.function.IntConsumer;

class ZeroEvenOdd {
    private int n;
    private final Semaphore semaphoreZero;
    private final Semaphore semaphoreEven;
    private final Semaphore semaphoreOdd;

    public ZeroEvenOdd(int n) {
        this.n = n;
        this.semaphoreZero = new Semaphore(1);
        this.semaphoreEven = new Semaphore(0);
        this.semaphoreOdd = new Semaphore(0);
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; ++i) {
            semaphoreZero.acquire();
            printNumber.accept(0);
            if (i % 2 == 0) {
                semaphoreEven.release();
            } else {
                semaphoreOdd.release();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i += 2) {
            semaphoreEven.acquire();
            printNumber.accept(i);
            semaphoreZero.release();
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i += 2) {
            semaphoreOdd.acquire();
            printNumber.accept(i);
            semaphoreZero.release();
        }
    }
}

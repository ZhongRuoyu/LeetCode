// Solved 2021-12-06
// Runtime: 9 ms (100.00%)
// Memory Usage: 38.4 MB (74.17%)

import java.util.concurrent.Semaphore;

class Foo {
    private final Semaphore runSecond;
    private final Semaphore runThird;

    public Foo() {
        this.runSecond = new Semaphore(0);
        this.runThird = new Semaphore(0);
    }

    public void first(Runnable printFirst) throws InterruptedException {
        // printFirst.run() outputs "first". Do not change or remove this line.
        printFirst.run();
        runSecond.release();
    }

    public void second(Runnable printSecond) throws InterruptedException {
        runSecond.acquire();
        // printSecond.run() outputs "second". Do not change or remove this
        // line.
        printSecond.run();
        runThird.release();
    }

    public void third(Runnable printThird) throws InterruptedException {
        runThird.acquire();
        // printThird.run() outputs "third". Do not change or remove this line.
        printThird.run();
    }
}

// Solved 2021-12-07
// Runtime: 11 ms (99.00%)
// Memory Usage: 40.3 MB (73.33%)

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Semaphore;
import java.util.concurrent.locks.Lock;
import java.util.concurrent.locks.ReentrantLock;

class DiningPhilosophers {
    private final Semaphore semaphore;
    private final List<Lock> mutex;

    public DiningPhilosophers() {
        this.semaphore = new Semaphore(4, true);
        this.mutex = new ArrayList<>();
        for (int i = 0; i < 5; ++i) {
            mutex.add(new ReentrantLock(true));
        }
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher, Runnable pickLeftFork,
        Runnable pickRightFork, Runnable eat, Runnable putLeftFork,
        Runnable putRightFork) throws InterruptedException {
        int leftFork = philosopher % 5;
        int rightFork = (philosopher + 4) % 5;

        semaphore.acquire();

        pickFork(leftFork, pickLeftFork);
        pickFork(rightFork, pickRightFork);

        eat.run();

        putFork(rightFork, putRightFork);
        putFork(leftFork, putLeftFork);

        semaphore.release();
    }

    private void pickFork(int fork, Runnable pick) {
        mutex.get(fork).lock();
        pick.run();
    }

    private void putFork(int fork, Runnable put) {
        put.run();
        mutex.get(fork).unlock();
    }
}

// Solved 2022-04-15
// Runtime: 20 ms (48.87%)
// Memory Usage: 6.6 MB (100.00%)

class FizzBuzz {
   private:
    int n;
    int i;
    mutex m;
    condition_variable cv;

   public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
    }

    void run(function<bool()> test, function<void()> print) {
        while (true) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [&] { return i > n || test(); });
            if (i > n) {
                break;
            }
            print();
            ++i;
            lock.unlock();
            cv.notify_all();
        }
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        run([&] { return i % 3 == 0 && i % 5 != 0; }, [&] { printFizz(); });
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        run([&] { return i % 3 != 0 && i % 5 == 0; }, [&] { printBuzz(); });
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        run([&] { return i % 15 == 0; }, [&] { printFizzBuzz(); });
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        run([&] { return i % 3 != 0 && i % 5 != 0; }, [&] { printNumber(i); });
    }
};

class ZeroEvenOdd {
private:
    int n;
    mutex m;
    condition_variable cv;
    int turn;
    int i; // to track nos upto n

public:
    ZeroEvenOdd(int n) {
        this -> n = n;
        this -> turn = 0;
        this -> i = 1;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(i <= n)
        {
            unique_lock<mutex> lock(m);
            while(turn != 0 && i <= n)
            {
                cv.wait(lock);
            }

            // checking for i's value:
            if(i > n) break;
            
            printNumber(0);
            turn = i % 2 == 0 ? 2 : 1; // if prev was odd and becoz of i++ value is even, then it should be now even turn
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        // 2 pe chalta he
        while(i <= n)
        {
            unique_lock<mutex> lock(m);
            while(turn != 2 && i <= n)
            {
                cv.wait(lock);
            }

            // checking for i's value:
            if(i > n) break;
            
            printNumber(i);
            turn = 0; // now next is zeros turn
            i++;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(i <= n)
        {
            unique_lock<mutex> lock(m);
            while(turn != 1 && i <= n)
            {
                cv.wait(lock);
            }

            // checking for i's value:
            if(i > n) break;
            
            printNumber(i);
            turn = 0; // now next is zeros turn
            i++;
            cv.notify_all();
        }
    }
};
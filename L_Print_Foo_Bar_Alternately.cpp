// we want to schedule two threads T1 and T2 in such a way that T1 executes first and then  T2 and then again T1 and T2 and so on: otherwise first T1 will n times and then T2's no will come

class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    bool turn;

public:
    FooBar(int n) {
        this->n = n;
        this -> turn = false;
    }

    // isko chalne ke liye false chaaiye:
    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++)
        {
            // lock lagay gaya to wait:
            unique_lock<mutex> lock(m);
            // waiting till turn is true
            while(turn == true)
            {
                cv.wait(lock);
            } 
        	printFoo();
            turn = true; // for other thread
            cv.notify_all();
        }
    }

    // isko chalne ke liye true chaaiye:
    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++)
        {
            unique_lock<mutex> lock(m);
            while(turn == false)
            {
                cv.wait(lock);
            }
        	printBar();
            turn = false;
            cv.notify_all();
        }
    }
};
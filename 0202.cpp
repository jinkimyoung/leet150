

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = getNext(n);
        while (slow != fast)
        {
            fast = getNext(getNext(fast));
            slow = getNext(slow);
        }
        return fast == 1;
    }

    int getNext(int n)
    {
        int out = 0;
        while (n > 0)
        {
            out += ((n%10) * (n%10));
            n = n / 10;
        }
        return out;
    }
};
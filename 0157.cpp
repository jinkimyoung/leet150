


class Solution {
public:
    int read(char *buf, int n) {
        char buffer[4];
        int left = n, nread;

        while (left > 0)
        {
            nread = read4(buffer);
            if (nread == 0) break;
            for (int i = 0; i < nread; i++)
                *(buf++) = buffer[i];
            left -= nread;
        }
        return n;      
    }
};

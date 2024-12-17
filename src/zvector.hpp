#include <stdio.h>

class Vec2 {
    public:
        int x, y;

        void init(int nx, int ny) {
            x = nx;
            x = ny;
        }
}

void add_vector(Vec2 vector, int x, int y);
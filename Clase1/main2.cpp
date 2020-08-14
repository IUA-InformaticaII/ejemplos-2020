#include <iostream>

using namespace std;

class vector2D {
private:
    int x;
    int y;
public:
    vector2D() {
        x = 0;
        y = 0;
    }

    vector2D(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    vector2D suma(vector2D b) {
        vector2D tmp;
        tmp.x = x + b.x;
        tmp.y = y + b.y;
        return tmp;
    }

    void print() {
        cout << "x: " << x << " y: " << y << endl;
    }

    bool operator==(const vector2D &rhs) const {
        return x == rhs.x &&
               y == rhs.y;
    }

    bool operator!=(const vector2D &rhs) const {
        return !(rhs == *this);
    }

    vector2D operator+(const vector2D &rhs) {
        return this->suma(rhs);
    }


};

int main() {
    vector2D aa;
    vector2D bb(10, 20);

    vector2D cc;

    aa.setX(5);
    aa.setY(-3);

    // cc = aa.suma(bb);
    cc = aa + bb;

    cout << "AA" << endl;
    aa.print();

    cout << "BB" << endl;
    bb.print();

    cout << "CC" << endl;
    cc.print();


    return 0;
}

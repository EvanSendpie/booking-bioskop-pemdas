#include <iostream>
using namespace std;

class harga
{
private:
    bool isWeekend;

public:
    harga(bool weekend) : isWeekend(weekend) {}
    int getHarga()
    {
        return (isWeekend ? 50000 : 35000);
    }
};
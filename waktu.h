#include <iostream>
using namespace std;

class waktu
{
private:
    int jam, menit;
    string hari;

public:
    void setWaktu(int j, int m, string h)
    {
        jam = j;
        menit = m;
        hari = h;
    }

    void getWaktu()
    {
        cout << hari << " pukul " << jam << ":" << menit << " WIB" << endl
             << endl;
    }

    int getMenit()
    {
        return menit;
    }

    int getJam()
    {
        return jam;
    }

    string getHari()
    {
        return hari;
    }
};
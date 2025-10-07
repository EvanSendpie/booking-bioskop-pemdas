#include <iostream>
using namespace std;

class kursi
{
private:
    int no_kursi;

public:
    void setKursi(int nk)
    {
        no_kursi = nk;
    }

    void getKursi()
    {
        cout << "Nomor Kursi: " << no_kursi << endl;
    }

    int get_noKursi()
    {
        return no_kursi;
    }
};
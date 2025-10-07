#include <iostream>
using namespace std;

class camilan
{
private:
    int kode_camilan;
    string nama_camilan;
    int harga_camilan;

public:
    void setCamilan(int kc, string nc, int hc)
    {
        nama_camilan = nc;
        kode_camilan = kc;
        harga_camilan = hc;
    }
    void getCamilan()
    {
        cout << "Kode: " << kode_camilan << " || " << nama_camilan << " || Harga: " << harga_camilan << endl;
    }
    string getNama_camilan()
    {
        return nama_camilan;
    }
    int getHarga_camilan()
    {
        return harga_camilan;
    }
    int getKode_camilan()
    {
        return kode_camilan;
    }

};
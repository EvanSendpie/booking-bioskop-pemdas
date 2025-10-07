//EVAN
#include <iostream>
using namespace std;

class film
{
private:
    int kode_film;
    string judul_film, durasi_film;

public:
    void setJudul_film(int kf, string jf, string df)
    {
        judul_film = jf;
        kode_film = kf;
        durasi_film = df;
    }
    void get_film()
    {
        cout << "Kode: " << kode_film << " || " << judul_film << endl
             << "Durasi: " << durasi_film << endl;
    }
    string getJudul_film()
    {
        return judul_film;
    }
    string getDurasi_film()
    {
        return durasi_film;
    }

};
#include <iostream>
#include "kursi.h"
#include "waktu.h"
#include "film.h"
#include "camilan.h"
#include "harga.h"
using namespace std;

class bayar {
private:
    int saldo;
public:
    void setSaldo(int sld) {
        saldo = sld;
    }
    int getSaldo() {
        return saldo;
    }
    void kurangiSaldo(int jumlah) {
        saldo -= jumlah;
    }
};

int main() {
    int pilihanFilm;
    int pilihanKursi;
    int pilihanCamilan;
    bayar uang;
    uang.setSaldo(100000);

    film mov[7];
    mov[0].setJudul_film(1, "Petualangan Tahu Telor 2", "02:00");
    mov[1].setJudul_film(2, "Avengers Endgame", "03:00");
    mov[2].setJudul_film(3, "The Shawshank Redemption", "02:22");
    mov[3].setJudul_film(4, "Jurassic Park", "02:07");
    mov[4].setJudul_film(5, "Eternal Sunshine of the Spotless Mind", "01:48");
    mov[5].setJudul_film(6, "The Godfather", "02:55");
    mov[6].setJudul_film(7, "How to Train Your Dragon", "01:38");

    waktu time[7];
    time[0].setWaktu(10, 30, "Senin");
    time[1].setWaktu(12, 30, "Minggu");
    time[2].setWaktu(14, 30, "Rabu");
    time[3].setWaktu(16, 52, "Kamis");
    time[4].setWaktu(19, 59, "Sabtu");
    time[5].setWaktu(20, 47, "Sabtu");
    time[6].setWaktu(11, 20, "Selasa");

    camilan snacks[10];
    snacks[0].setCamilan(1, "Popcorn", 35000);
    snacks[1].setCamilan(2, "Coca-cola", 20000);
    snacks[2].setCamilan(3, "French Fries", 18000);
    snacks[3].setCamilan(4, "Chicken Nugget", 25000);
    snacks[4].setCamilan(5, "Hot Dog", 25000);
    snacks[5].setCamilan(6, "Burger", 30000);
    snacks[6].setCamilan(7, "Aqua", 5000);
    snacks[7].setCamilan(8, "Ice Tea", 10000);
    snacks[8].setCamilan(9, "Lemon Tea", 15000);
    snacks[9].setCamilan(10, "Doughnut", 12000);

    kursi seats[50];
    for (int i = 0; i < 50; i++) {
        seats[i].setKursi(i + 1);
    }

    cout << "Selamat datang di Bioskop!" << endl
         << "Anda memiliki saldo sebesar Rp" << uang.getSaldo() << "!" << endl
         << "Berikut adalah daftar film dan waktu pemutarannya:" << endl << endl;
  

    for (int i = 0; i < 7; i++) {
        mov[i].get_film();
        time[i].getWaktu();
    }

    cout << "Silahkan pilih film untuk ditonton: ";
    cin >> pilihanFilm;

    while (pilihanFilm < 1 || pilihanFilm > 7) {
        cout << "Pilihan tidak valid, pilih film yang ada (1-6): ";
        cin >> pilihanFilm;
    }


    bool isWeekend = (time[pilihanFilm - 1].getHari() == "Sabtu" || time[pilihanFilm - 1].getHari() == "Minggu");
    harga hargaTiket(isWeekend);
    uang.kurangiSaldo(hargaTiket.getHarga());

    
    if (uang.getSaldo() >= 0) {
        cout << "Anda memilih film: " << mov[pilihanFilm - 1].getJudul_film() << endl;

        cout << endl << "\t\t\t\t\b\b L A Y A R" << endl;
        cout << "==========================================================================" << endl;
        int arrKursi[5][10] = {
            {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
            {31, 32, 33, 34, 35, 36, 37, 38, 39, 40},
            {41, 42, 43, 44, 45, 46, 47, 48, 49, 50}};
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 10; k++) {
                cout << arrKursi[j][k] << "\t";
            }
            cout << endl;
        }
        cout << "==========================================================================" << endl;

        cout << "\nSilahkan pilih nomor kursi (1-50): ";
        cin >> pilihanKursi;

        while (pilihanKursi < 1 || pilihanKursi > 50) {
            cout << "Pilihan tidak valid, pilih kursi yang ada (1-50): ";
            cin >> pilihanKursi;
        }

        cout << "Anda memilih kursi nomor: ";
        seats[pilihanKursi - 1].getKursi();
        cout << endl;

        cout << "Daftar camilan (masukkan 0 jika tidak membeli):" << endl;
        for (int i = 0; i < 10; i++) {
            snacks[i].getCamilan();
        }

        cout << endl
             << "Silahkan pilih camilan: ";
        cin >> pilihanCamilan;

        while (pilihanCamilan < 0 || pilihanCamilan > 10){
            cout << "Pilihan camilan tidak valid, silahkan pilih sesuai dengan yang ada pada list" << endl;
            cout << "Silahkan pilih camilan: ";
            cin >> pilihanCamilan;
        }

        string camilan_dipesan = "Tidak ada";
    
        if (pilihanCamilan != 0) {
            camilan_dipesan = snacks[pilihanCamilan - 1].getNama_camilan();
            uang.kurangiSaldo(snacks[pilihanCamilan - 1].getHarga_camilan());

            if (uang.getSaldo() >= 0) {
                cout << "Anda membeli: " << snacks[pilihanCamilan - 1].getNama_camilan() << endl;
            } else {
                cout << "Saldo Anda tidak mencukupi untuk membeli camilan." << endl;
                camilan_dipesan = "Tidak ada";
            }
        } else {
            cout << "Anda memilih untuk tidak membeli camilan." << endl;
        }

        cout << endl << "\t\t- Informasi Pembelian -" << endl;
        cout << "Film yang ditonton\t:" << mov[pilihanFilm - 1].getJudul_film() << " (Durasi: " << mov[pilihanFilm - 1].getDurasi_film() << ")" << endl;
        cout << "Nomor kursi\t\t:" << seats[pilihanKursi - 1].get_noKursi() << endl;
        cout << "Camilan yang dipesan\t:" << camilan_dipesan << endl;
        cout << "Saldo akhir Anda\t:Rp" << uang.getSaldo() << endl;
        cout << "\t\t- Selamat Menonton -";
    } else {
        cout << "Saldo Anda tidak mencukupi untuk membeli tiket film." << endl;
    }

    return 0;
}
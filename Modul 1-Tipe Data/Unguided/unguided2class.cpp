#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
private:
  string nama;
  string nim;
  float ipk;

public:
  // Setter dan getter untuk nim, nama, dan ipk
  void setnama(string nilai) {
    nama = nilai;
  }

  string getnama() const {
    return nama;
  }

  void setnim(string nilai) {
    nim = nilai;
  }

  string getnim() const {
    return nim;
  }

  void setIpk(float nilai) {
    ipk = nilai;
  }

  float getIpk() const {
    return ipk;
  }

  // Menampilkan detail mahasiswa
  void cetakInfo() {
    cout << "Nama: " << getnama() << endl;
    cout << "NIM: " << getnim() << endl;
    cout << "IPK: " << getIpk() << endl;  
  }
};

int main() 
{
    Mahasiswa mhs1;
    mhs1.setnama("Bagas Dribble");
    mhs1.setnim("12345678");
    mhs1.setIpk(3.6);
    cout << "Data Mahasiswa: \n";
    mhs1.cetakInfo();
    return 0;
}
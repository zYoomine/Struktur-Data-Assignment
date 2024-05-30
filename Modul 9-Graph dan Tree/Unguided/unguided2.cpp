// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// Deklarasi struct pohon yang nodenya berisi variabel data
struct Pohon {
    char data;
    Pohon *left, *right, *parent; // Deklarasi node left, right, dan parent
};
Pohon *root, *baru; // Deklarasi node root dan node baru

// Prosedur inisialisasi
void init() {
    root = NULL; // Menyatakan node root adalah NULL
}

// Fungsi isEmpty untuk memeriksa apakah tree kosong atau tidak
bool isEmpty() {
    return root == NULL;
}

// Prosedur buatNode untuk membuat node baru
Pohon* buatNode(char data) {
    if (isEmpty()) {
        root = new Pohon();
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\n Node " << data << " berhasil dibuat sebagai root."
             << endl;
    } else {
        cout << "\n Tree sudah ada!" << endl;
    }
    return root;
}

// Fungsi untuk membuat node child kiri
Pohon* insertLeft(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\n Node " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kiri " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Fungsi untuk membuat node child kanan
Pohon* insertRight(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\n Node " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            Pohon *baru = new Pohon();
            baru->data = data;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\n Node " << data << " berhasil ditambahkan ke child kanan " << baru->parent->data << endl;
            return baru;
        }
    }
}

// Prosedur untuk mengupdate nilai suatu node
void update(char data, Pohon* node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\n Node yang ingin diganti tidak ada!!" << endl;
        } else {
            char temp = node->data;
            node->data = data;
            cout << "\n Node " << temp << " berhasil diubah menjadi "
                 << data << endl;
        }
    }
}

// Prosedur untuk menunjuk suatu node
void retrieve(Pohon* node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\n Data node : " << node->data << endl;
        }
    }
}

// Prosedur untuk mencari suatu node kemudian menampilkan root, parent, sibling, dan child node tersebut
void find(Pohon* node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\n Node yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\n Data Node : " << node->data << endl;
            cout << " Root : " << root->data << endl;
            if (!node->parent)
                cout << " Parent : (tidak punya parent)" << endl;
            else
                cout << " Parent : " << node->parent->data << endl;
            if (node->parent != NULL && node->parent->left != node &&
                node->parent->right == node)
                cout << " Sibling : " << node->parent->left->data << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << " Sibling : " << node->parent->right->data << endl;
            else
                cout << " Sibling : (tidak punya sibling)" << endl;
            if (!node->left)
                cout << " Child kiri : (tidak punya child kiri)" << endl;
            else
                cout << " Child kiri : " << node->left->data << endl;
            if (!node->right)
                cout << " Child kanan : (tidak punya child kanan)" << endl;
            else
                cout << " Child kanan : " << node->right->data << endl;
        }
    }
}

// Prosedur untuk menghapus node tertentu
void deleteNode(Pohon* node) {
    if (isEmpty()) {
        cout << "\n Buat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\n Node yang ingin dihapus tidak ada!" << endl;
        } else {
            if (node->left == NULL && node->right == NULL) {
                cout << "\n Node " << node->data << " berhasil dihapus" << endl;
                delete node;
            } else if (node->left == NULL && node->right != NULL) {
                Pohon *temp = node->right;
                node->data = node->right->data;
                node->right = NULL;
                cout << "\n Node " << temp->data << " berhasil dihapus" << endl;
                delete temp;
            } else if (node->left != NULL && node->right == NULL) {
                Pohon *temp = node->left;
                node->data = node->left->data;
                node->left = NULL;
                cout << "\n Node " << temp->data << " berhasil dihapus" << endl;
                delete temp;
            } else {
                Pohon *temp = node->right;
                while (temp->left != NULL)
                    temp = temp->left;
                node->data = temp->data;
                deleteNode(temp);
                cout << "\n Node " << temp->data << " berhasil dihapus" << endl;
            }
        }
    }
}

// Prosedur untuk menampilkan node child dan descendant dari node yang diinputkan
void displayChildAndDescendant(Pohon* node) {
    if (node == NULL) {
        cout << "\n Node kosong!" << endl;
    } else {
        if (node->left != NULL) {
            cout << "\n Node child kiri: " << node->left->data;
            displayChildAndDescendant(node->left);
        }
        if (node->right != NULL) {
            cout << "\n Node child kanan: " << node->right->data;
            displayChildAndDescendant(node->right);
        }
    }
}

// Prosedur untuk menjalankan program secara interaktif
void menu() {
    int choice;
    char data;
    Pohon* node = NULL;
    do {
        cout << "\n -------------MENU TREE-------------" << endl;
        cout << " 1. Buat tree baru" << endl;
        cout << " 2. Tambah node baru ke kiri" << endl;
        cout << " 3. Tambah node baru ke kanan" << endl;
        cout << " 4. Ubah data node" << endl;
        cout << " 5. Tampilkan data node" << endl;
        cout << " 6. Cari node dan tampilkan detailnya" << endl;
        cout << " 7. Hapus node" << endl;
        cout << " 8. Tampilkan child dan descendant dari node" << endl;
        cout << " 9. Keluar" << endl;
        cout << " Pilih menu: ";
        cin >> choice;
        switch (choice) {
            case 1:
                if (isEmpty()) {
                    cout << "\n Buat tree baru!" << endl;
                    cout << " Masukkan data untuk root: ";
                    cin >> data;
                    root = buatNode(data);
                    node = root;
                } else {
                    cout << "\n Tree sudah ada!!" << endl;
                }
                break;
            case 2:
                cout << " Masukkan data untuk node baru: ";
                cin >> data;
                node = insertLeft(data, node);
                break;
            case 3:
                cout << " Masukkan data untuk node baru: ";
                cin >> data;
                node = insertRight(data, node);
                break;
            case 4:
                cout << " Masukkan data untuk node yang ingin diubah: ";
                cin >> data;
                update(data, node);
                break;
            case 5:
                retrieve(node);
                break;
            case 6:
                find(node);
                break;
            case 7:
                deleteNode(node);
                break;
            case 8:
                displayChildAndDescendant(node);
                break;
            case 9:
                cout << "\n Terima kasih telah menggunakan program ini!" << endl;
                break;
            default:
                cout << "\n Pilihan tidak valid!" << endl;
                break;
        }
    } while (choice != 9);
}

int main() {
    init();
    menu();
    return 0;
}
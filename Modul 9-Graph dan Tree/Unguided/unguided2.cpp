// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

// Deklarasi struct pohon yang nodenya berisi variabel data
struct Pohon {
    char data_2311102183;
    Pohon *left, *right, *parent; // deklarasi node left, right, dan parent
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
void buatNode(char data_2311102183) {
    if (isEmpty()) {
        root = new Pohon();
        root->data_2311102183 = data_2311102183;
        root->left = NULL;
        root->right = NULL;
        root->parent = NULL;
        cout << "\nNode " << data_2311102183 << " berhasil dibuat sebagai root."
            << endl;
    } else {
        cout << "\nTree sudah ada!" << endl;
    }
}

// Fungsi untuk membuat node child kiri
Pohon* insertLeft(char data_2311102183, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data_2311102183 << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            Pohon *baru = new Pohon();
            baru->data_2311102183 = data_2311102183;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data_2311102183 << " berhasil ditambahkan ke child kiri " << baru->parent->data_2311102183 << endl;
            return baru;
        }
    }
}

// Fungsi untuk membuat node child kanan
Pohon* insertRight(char data_2311102183, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data_2311102183 << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            Pohon *baru = new Pohon();
            baru->data_2311102183 = data_2311102183;
            baru->left = NULL;
            baru->right = NULL;
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data_2311102183 << " berhasil ditambahkan ke child kanan " << baru->parent->data_2311102183 << endl;
            return baru;
        }
    }
}

// Prosedur untuk mengupdate nilai suatu node
void update(char data_2311102183, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ingin diganti tidak ada!!" << endl;
        } else {
            char temp = node->data_2311102183;
            node->data_2311102183 = data_2311102183;
            cout << "\nNode " << temp << " berhasil diubah menjadi "
                << data_2311102183 << endl;
        }
    }
}

// Prosedur untuk menunjuk suatu node
void retrieve(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData node: " << node->data_2311102183 << endl;
        }
    }
}

// Prosedur untuk mencari suatu node kemudian menampilkan root, parent, sibling, dan child node tersebut
void find(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nData Node: " << node->data_2311102183 << endl;
            cout << "Root: " << root->data_2311102183 << endl;
            if (!node->parent)
                cout << "Parent: (tidak punya parent)" << endl;
            else
                cout << "Parent: " << node->parent->data_2311102183 << endl;
            if (node->parent != NULL && node->parent->left != node && node->parent->right == node)
                cout << "Sibling: " << node->parent->left->data_2311102183 << endl;
            else if (node->parent != NULL && node->parent->right != node && node->parent->left == node)
                cout << "Sibling: " << node->parent->right->data_2311102183 << endl;
            else
                cout << "Sibling: (tidak punya sibling)" << endl;
            if (!node->left)
                cout << "Child Kiri: (tidak punya Child kiri)" << endl;
            else
                cout << "Child Kiri: " << node->left->data_2311102183 << endl;
            if (!node->right)
                cout << "Child Kanan: (tidak punya Child kanan)" << endl;
            else
                cout << "Child Kanan: " << node->right->data_2311102183 << endl;
        }
    }
}

// Prosedur untuk menampilkan child dan descendant dari node
void showDescendants(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (!node) {
            cout << "\nNode yang ditunjuk tidak ada!" << endl;
        } else {
            cout << "\nNode: " << node->data_2311102183 << endl;
            cout << "Child Kiri: " << (node->left ? node->left->data_2311102183 : ' ') << endl;
            cout << "Child Kanan: " << (node->right ? node->right->data_2311102183 : ' ') << endl;
            
            cout << "Descendants: ";
            queue<Pohon*> q;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            while (!q.empty()) {
                Pohon *current = q.front();
                q.pop();
                cout << current->data_2311102183 << " ";
                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            cout << endl;
        }
    }
}

// Penelusuran (Traversal)
// Prosedur untuk menampilkan traversal secara pre order
void preOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            cout << " " << node->data_2311102183 << ", ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }
}

// Prosedur untuk menampilkan traversal secara in order
void inOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            inOrder(node->left);
            cout << " " << node->data_2311102183 << ", ";
            inOrder(node->right);
        }
    }
}

// Prosedur untuk menampilkan traversal secara post order
void postOrder(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << " " << node->data_2311102183 << ", ";
        }
    }
}

// Prosedur untuk menhapus sebuah node didalam tree
void deleteTree(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        if (node != NULL) {
            if (node != root) {
                node->parent->left = NULL;
                node->parent->right = NULL;
            }
            deleteTree(node->left);
            deleteTree(node->right);
            if (node == root) {
                delete root;
                root = NULL;
            } else {
                delete node;
            }
        }
    }
}

// Prosedur untuk menghapus sub tree
void deleteSub(Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
    } else {
        deleteTree(node->left);
        deleteTree(node->right);
        cout << "\nNode subtree " << node->data_2311102183 << " berhasil dihapus." << endl;
    }
}

// Prosedur untuk menghapus seluruh tree
void clear() {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
    } else {
        deleteTree(root);
        cout << "\nPohon berhasil dihapus." << endl;
    }
}

// Fungsi untuk memeriksa jumlah node (size) didalam tree
int size(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            return 1 + size(node->left) + size(node->right);
        }
    }
}

// Fungsi untuk memeriksa level atau aras (height) tree
int height(Pohon *node = root) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return 0;
    } else {
        if (!node) {
            return 0;
        } else {
            int heightKiri = height(node->left);
            int heightKanan = height(node->right);
            if (heightKiri >= heightKanan) {
                return heightKiri + 1;
            } else {
                return heightKanan + 1;
            }
        }
    }
}

// Prosedur untuk memeriksa karakteristik tree
void characteristic() {
    cout << "\nSize Tree: " << size() << endl;
    cout << "Height Tree: " << height() << endl;
    cout << "Average Node of Tree: " << size() / height() << endl;
}

// Fungsi untuk mencari node berdasarkan data
Pohon* findNode(char data_2311102183, Pohon *node = root) {
    if (node == NULL) return NULL;
    if (node->data_2311102183 == data_2311102183) return node;
    Pohon* foundNode = findNode(data_2311102183, node->left);
    if (foundNode == NULL) foundNode = findNode(data_2311102183, node->right);
    return foundNode;
}

int main() {
    int pilihan_2311102183; // Variabel untuk menyimpan pilihan menu
    char data, parentData;  // Variabel untuk menyimpan data node dan parent node
    Pohon *parentNode;      // Pointer ke node parent

    // Loop untuk menampilkan menu dan menerima input pilihan
    do {
        cout << "\tMenu\n";
        cout << "=========================================\n";
        cout << "1. Buat Root Node\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Update Node\n";
        cout << "5. Tunjuk Node\n";
        cout << "6. Cari Node\n";
        cout << "7. Tampilkan Child dan Descendant\n";
        cout << "8. Tampilkan PreOrder\n";
        cout << "9. Tampilkan InOrder\n";
        cout << "10. Tampilkan PostOrder\n";
        cout << "11. Hapus Sub Tree\n";
        cout << "12. Hapus Tree\n";
        cout << "13. Tampilkan Karakteristik Tree\n";
        cout << "14. Keluar\n";
        cout << "=========================================\n";
        cout << "Pilihan: ";
        cin >> pilihan_2311102183;

        // Switch case untuk menjalankan fungsi berdasarkan pilihan
        switch (pilihan_2311102183) {
            case 1:
                cout << "Masukkan data untuk root node: ";
                cin >> data;
                buatNode(data);
                break;
            case 2:
                cout << "Masukkan data untuk node baru: ";
                cin >> data;
                cout << "Masukkan data parent node: ";
                cin >> parentData;
                parentNode = findNode(parentData);
                insertLeft(data, parentNode);
                break;
            case 3:
                cout << "Masukkan data untuk node baru: ";
                cin >> data;
                cout << "Masukkan data parent node: ";
                cin >> parentData;
                parentNode = findNode(parentData);
                insertRight(data, parentNode);
                break;
            case 4:
                cout << "Masukkan data node yang ingin diupdate: ";
                cin >> data;
                cout << "Masukkan data baru: ";
                cin >> parentData;
                parentNode = findNode(data);
                update(parentData, parentNode);
                break;
            case 5:
                cout << "Masukkan data node yang ingin ditunjuk: ";
                cin >> data;
                parentNode = findNode(data);
                retrieve(parentNode);
                break;
            case 6:
                cout << "Masukkan data node yang ingin dicari: ";
                cin >> data;
                parentNode = findNode(data);
                find(parentNode);
                break;
            case 7:
                cout << "Masukkan data node yang ingin ditampilkan descendant-nya: ";
                cin >> data;
                parentNode = findNode(data);
                showDescendants(parentNode);
                break;
            case 8:
                cout << "PreOrder:\n";
                preOrder(root);
                cout << "\n";
                break;
            case 9:
                cout << "InOrder:\n";
                inOrder(root);
                cout << "\n";
                break;
            case 10:
                cout << "PostOrder:\n";
                postOrder(root);
                cout << "\n";
                break;
            case 11:
                cout << "Masukkan data node yang ingin dihapus subtree-nya: ";
                cin >> data;
                parentNode = findNode(data);
                deleteSub(parentNode);
                break;
            case 12:
                clear();
                break;
            case 13:
                characteristic();
                break;
            case 14:
                cout << "Keluar program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }
    } while (pilihan_2311102183 != 14);

    return 0;
}
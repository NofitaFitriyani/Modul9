#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct Pohon {
    char data;
    Pohon *left, *right, *parent;
};

Pohon *root;

void init() {
    root = NULL;
}

bool isEmpty() {
    return root == NULL;
}

Pohon *newPohon(char data) {
    Pohon *node = new Pohon();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void buatNode(char data) {
    if (isEmpty()) {
        root = newPohon(data);
        cout << "\nNode " << data << " berhasil dibuat menjadi root." << endl;
    } else {
        cout << "\nPohon sudah dibuat" << endl;
    }
}

Pohon *insertLeft(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->left != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kiri!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->left = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kiri " << node->data << endl;
            return baru;
        }
    }
}

Pohon *insertRight(char data, Pohon *node) {
    if (isEmpty()) {
        cout << "\nBuat tree terlebih dahulu!" << endl;
        return NULL;
    } else {
        if (node->right != NULL) {
            cout << "\nNode " << node->data << " sudah ada child kanan!" << endl;
            return NULL;
        } else {
            Pohon *baru = newPohon(data);
            baru->parent = node;
            node->right = baru;
            cout << "\nNode " << data << " berhasil ditambahkan ke child kanan " << node->data << endl;
            return baru;
        }
    }
}

void preOrder(Pohon *node) {
    if (node != NULL) {
        cout << " " << node->data << ", ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(Pohon *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << " " << node->data << ", ";
        inOrder(node->right);
    }
}

void postOrder(Pohon *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << " " << node->data << ", ";
    }
}

void displayChild(Pohon *node) {
    if (node != NULL) {
        cout << "Parent: " << node->data << endl;
        if (node->left != NULL) {
            cout << "Child Kiri: " << node->left->data << endl;
        } else {
            cout << "Child Kiri: (tidak punya child kiri)" << endl;
        }
        if (node->right != NULL) {
            cout << "Child Kanan: " << node->right->data << endl;
        } else {
            cout << "Child Kanan: (tidak punya child kanan)" << endl;
        }
    }
}

void displayDescendants(Pohon *node) {
    if (node != NULL) {
        cout << "Descendants of " << node->data << ": ";
        queue<Pohon *> q;
        q.push(node);
        q.pop();
        while (!q.empty()) {
            Pohon *temp = q.front();
            q.pop();
            if (temp->left != NULL) {
                cout << temp->left->data << " ";
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                cout << temp->right->data << " ";
                q.push(temp->right);
            }
        }
        cout << endl;
    }
}

Pohon *findNode(Pohon *node, char data) {
    if (node == NULL) return NULL;
    if (node->data == data) return node;
    Pohon *leftResult = findNode(node->left, data);
    if (leftResult != NULL) return leftResult;
    return findNode(node->right, data);
}

int main() {
    int choice;
    char data;
    init();

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Buat Node Root\n";
        cout << "2. Tambah Node Kiri\n";
        cout << "3. Tambah Node Kanan\n";
        cout << "4. Tampilkan PreOrder\n";
        cout << "5. Tampilkan InOrder\n";
        cout << "6. Tampilkan PostOrder\n";
        cout << "7. Tampilkan Child Node\n";
        cout << "8. Tampilkan Descendants Node\n";
        cout << "9. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Masukkan data untuk root: ";
                cin >> data;
                buatNode(data);
                break;
            case 2: {
                cout << "Masukkan data untuk node kiri: ";
                cin >> data;
                cout << "Masukkan data parent: ";
                char parentData;
                cin >> parentData;
                Pohon *parent = findNode(root, parentData);
                if (parent != NULL) {
                    insertLeft(data, parent);
                } else {
                    cout << "\nParent tidak ditemukan!" << endl;
                }
                break;
            }
            case 3: {
                cout << "Masukkan data untuk node kanan: ";
                cin >> data;
                cout << "Masukkan data parent: ";
                char parentData;
                cin >> parentData;
                Pohon *parent = findNode(root, parentData);
                if (parent != NULL) {
                    insertRight(data, parent);
                } else {
                    cout << "\nParent tidak ditemukan!" << endl;
                }
                break;
            }
            case 4:
                cout << "\nPreOrder: ";
                preOrder(root);
                cout << "\n";
                break;
            case 5:
                cout << "\nInOrder: ";
                inOrder(root);
                cout << "\n";
                break;
            case 6:
                cout << "\nPostOrder: ";
                postOrder(root);
                cout << "\n";
                break;
            case 7:
                cout << "Masukkan data node untuk menampilkan child: ";
                cin >> data;
                {
                    Pohon *node = findNode(root, data);
                    if (node != NULL) {
                        displayChild(node);
                    } else {
                        cout << "\nNode tidak ditemukan!" << endl;
                    }
                }
                break;
            case 8:
                cout << "Masukkan data node untuk menampilkan descendants: ";
                cin >> data;
                {
                    Pohon *node = findNode(root, data);
                    if (node != NULL) {
                        displayDescendants(node);
                    } else {
                        cout << "\nNode tidak ditemukan!" << endl;
                    }
                }
                break;
            case 9:
                return 0;
            default:
                cout << "Opsi tidak valid! Coba lagi." << endl;
        }
    }

    return 0;
}
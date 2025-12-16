#ifndef MLL_H_INCLUDED
#define MLL_H_INCLUDED
#include <iostream>
using namespace std;

// forward declaration
typedef struct elm_orangTua *adr_orangTua;
typedef struct elm_anak *adr_anak;
typedef struct elm_relation *adr_relation;

// struktur untuk list relasi
struct list_relation
{
    adr_relation first;
};

// struktur orang tua
struct infotype_orangTua
{
    string nama, jenis;
    int usia;
};

struct elm_orangTua
{
    infotype_orangTua info;
    adr_orangTua next;
    list_relation anak;
};

struct list_orangTua
{
    adr_orangTua first;
};

// struktur anak
struct infotype_anak
{
    string nama, jenis_kelamin;
    int usia;
};

struct elm_anak
{
    infotype_anak info;
    adr_anak next;
};

struct list_anak
{
    adr_anak first;
};

// struktur relasi
struct elm_relation
{
    adr_anak next_anak;
    adr_relation next;
};

// procedure inisiasi data keluarga
void InisiasiDataKeluarga(list_orangTua &L1, list_anak &L2);

// main menu
int showMainMenu();

// handler function
void handleInsertParent(list_orangTua &L);
void handleInsertChild(list_anak &L);
void handleDeleteParent(list_orangTua &L);
void handleFindParent(list_orangTua L);
void handleFindChild(list_anak L);
void handleShowAllParent(list_orangTua L);
void handleShowAllChild(list_anak L);
void handleCreateRelation(list_orangTua &L_ORTU, list_anak L_ANAK);
void handleDeleteRelation(list_orangTua &L_ORTU);
void handleShowAllParentAndChild(list_orangTua L_ORTU);
void handleFindChildOnParent(list_orangTua L_ORTU);
void handleCountChildOfParent(list_orangTua L_ORTU);

// --- FUNGSI/PROSEDUR UTAMA (PROTOTYPE) ---
// 1. Insert data parent dari depan
void insertFirstParent(list_orangTua &L, adr_orangTua P);
adr_orangTua createNewParent(infotype_orangTua info); // Fungsi pembantu untuk membuat node baru

// 2. Mencari data parent
adr_orangTua findParent(list_orangTua L, string namaParent);

// 3. Menghapus data parent beserta relasinya
// menggunakan deleteLast untuk list parent
void deleteParent(list_orangTua &L, string namaParent);

// 4. Menunjukkan semua data parent L1
void showAllParent(list_orangTua L);

// 5. Menambahkan data child dari belakang
void insertLastChild(list_anak &L, adr_anak C);
adr_anak createNewChild(infotype_anak info); // Fungsi pembantu untuk membuat node baru

// 6. Mencari data child
adr_anak findChild(list_anak L, string namaChild);

// 7. Menunjukkan semua data child L2
void showAllChild(list_anak L);

// 8. Menghubungkan data parent ke data child
adr_relation createNewRelation(adr_anak C); // C adalah pointer ke anak
void insertFirstRelation(list_relation &L, adr_relation R);

// 9. Menampilkan seluruh data parent beserta childnya
void showAllParentAndChild(list_orangTua L_Ortu);

// 10. Mencari data child pada parent tertentu
void printChildrenOfParent(list_orangTua L_ORTU, string namaParent);

// 11. Menghapus data child pada parent tertentu beserta relasinya
adr_relation findRelation(adr_orangTua P, string namaAnak);
void deleteRelation(list_orangTua &L_ORTU, adr_orangTua P, string namaAnak);
// Tambahan: Prosedur untuk menghapus Node Anak di L2 jika semua relasinya sudah dihapus
// adr_anak deleteChildNode(list_anak &L_Anak, string namaChild);

// 12. Menghitung jumlah data child dari parent tertentu
int countChildrenOfParent(list_orangTua L_ORTU, string namaParent);

#endif // MLL_H_INCLUDED

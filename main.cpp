#include <iostream>
#include "MLL.h"

using namespace std;

int main()
{
    list_orangTua L_ORTU;
    list_anak L_ANAK;

    // menginisasi list dengan seorang ayah, ibu, dan satu anak
    InisiasiDataKeluarga(L_ORTU, L_ANAK);

    int pilihanMenu;
    do
    {
        pilihanMenu = showMainMenu();

        switch (pilihanMenu)
        {
        case 1:
            // Panggil InsertFirstParent
            handleInsertParent(L_ORTU);
            break;
        case 2:
            // Panggil findParent
            handleFindParent(L_ORTU);
            break;
        case 3:
            // Panggil deleteParent
            handleDeleteParent(L_ORTU);
            break;
        case 4:
            // panggil showAllParent
            handleShowAllParent(L_ORTU);
            break;
        case 5:
            // Panggil insertLastChild
            handleInsertChild(L_ANAK);
            break;
        case 6:
            // Panggil findChild
            handleFindChild(L_ANAK);
            break;
        case 7:
            // Panggil showAllChild
            handleShowAllChild(L_ANAK);
            break;
        case 8:
            // Panggil HubungkanParentToChild
            handleCreateRelation(L_ORTU, L_ANAK);
            break;
        case 9:
            // Panggil deleteRelation
            handleDeleteRelation(L_ORTU);
            break;
        case 10:
            // Panggil ShowAllParentAndChild
            handleShowAllParentAndChild(L_ORTU);
            break;
        case 11:
            // Panggil findChildOnParent
            handleFindChildOnParent(L_ORTU);
            break;
        case 12:
            // Panggil countChildOfParent
            handleCountChildOfParent(L_ORTU);
            break;
        case 0:
            cout << "Terima kasih telah menggunakan program." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            break;
        }

        if (pilihanMenu != 0)
        {
            cout << "\nTekan ENTER untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }

    } while (pilihanMenu != 0);
    return 0;
}

#include "pro.cpp"

int tSutradara = 0;
int tFilm = 0;
int x, sut, fil;
string namas;
string namaf;

void menu(listParent &LSut, listChild &LFil) {
    int m;
    do {
        system("cls");
        cout << endl;
        cout << "          ---------SELAMAT DATANG DI---------" << endl;
        cout << "          |  ******* *       * ****  *      |" << endl;
        cout << "          |     *    **     ** *   * ***    |" << endl;
        cout << "          |     *    *  * *  * *   * *  *   |" << endl;
        cout << "          |     *    *   *   * ****  ***    |" << endl;
        cout << "          --------TUBES MOVIE DATABASE-------" << endl << endl;
        cout << "          SILAKAN PILIH MENU " << endl;
        cout << "          1. INPUT DATA" << endl;
        cout << "          2. HAPUS DATA" << endl;
        cout << "          3. TAMPILKAN DATA" << endl;
        cout << "          4. HUBUNGKAN DATA" << endl;
        cout << "          5. UBAH DATA" << endl;
        cout << "          0. KELUAR" << endl << endl;
        cout << "          Pilihan anda : ";
        cin >> m;
        switch(m){
            case 1 : {
                system("cls");
                int y;
                string z;
                cout << "Data yang ingin diinput :" << endl;
                cout << "1. Sutradara" << endl;
                cout << "2. Film"<< endl << endl;
                cout << "Pilihan anda : ";
                cin >> y ;
                switch(y){
                    case 1 :{
                        system("cls");
                        adrP P;
                        InfotypeParent x;
                        char namas[100];
                        cout << "Masukkan Nama Sutradara : ";
                        cin.ignore();
                        cin.getline(namas,100);
                        x.Nama = namas;
                        x.noSutradara = tSutradara + 1;
                        P = allocateSutradara(x);
                        insertLastSutradara(LSut, P);
                        tSutradara++;
                        break;
                    }
                    case 2 :{
                        system("cls");
                        adrC P;
                        InfotypeChild x;
                        char namaf[100];
                        cout << "Masukkan Judul Film : ";
                        cin.ignore();
                        cin.getline(namaf,100);
                        x.Judul = namaf;
                        x.noFilm = tFilm + 1;
                        P = allocateFilm(x);
                        insertLastFilm(LFil, P);
                        tFilm++;
                        break;
                    }
                }
                break;
            }
            case 2 :{
                system("cls");
                int x,y;
                outputSutradara(LSut);
                cout << "Data yang ingin dihapus :" << endl;
                cout << "1. Sutradara" << endl;
                cout << "2. Film" << endl << endl;
                cout << "Pilihan anda : ";
                cin >> y;
                switch (y){
                    case 1:{
                        system("cls");
                        if (!isEmptyParent(LSut)) {
                            cout << " Masukkan no Sutradara yang ingin dihapus : ";
                            cin >> x;
                            adrP P;
                            P = seqSearchSutradara(LSut, x);
                            if (P != NULL) {
                                deleteSutradara(LSut, P);
                                cout << " Sutradara berhasil dihapus" << endl;
                            } else {
                                cout << " Sutradara tidak ditemukan" << endl;
                            }
                        }
                    }
                    case 2 : {
                        system("cls");
                        if (!isEmptyChild(LFil)) {
                            cout << " Masukkan no Film yang ingin dihapus : ";
                            cin >> x;
                            adrC P;
                            P = seqSearchFilm(LFil, x);
                            if (P != NULL) {
                                deleteFilm(LFil, P);
                                cout << " Film berhasil dihapus" << endl;
                            } else {
                                cout << " Film tidak ditemukan" << endl;
                            }
                        }
                    }
                }
                break;
            }
            case 3:{
                system("cls");
                cout << "Data yang ingin dilihat :" << endl;
                cout<<"1. Sutradara"<<endl;
                cout<<"2. Film"<<endl;
                cout<<"3. Film berdasarkan Sutradara tertentu" << endl;
                cout<<"4. Film yang dibuat oleh 2 Sutradara" << endl;
                cout<<"5. Sutradara yang paling banyak membuat Film" << endl;
                cout<<"6. Asisten sutradara paling sedikit terlibat dalam projek film"<<endl;
                cout<<"Data yang ingin ditampilkan :"<<endl;
                cin>>x;
                switch (x) {
                case 1 : {
                    outputSutradara(LSut);
                    system("pause");
                    break;
                    }
                case 2 :{
                    outputFilm(LFil);
                    system("pause");
                    break;
                    }
                case 3 :{
                    if (isEmptyParent(LSut) || isEmptyChild(LFil)) {
                        cout << " Sutradara atau Film masih kosong" << endl;
                    } else {
                        int idp, idn;
                        cout << " Pilih Sutradara : " << endl;
                        outputSutradara(LSut);
                        cout << " Masukkan ID Sutradara : ";
                        cin >> idp;
                        outputFilmCari(LSut, idp);

                    }
                    system("pause");
                    break;
                }
                case 4 :{
                    outputFilm2Sut(LFil);
                    system("pause");
                    break;
                }
                case 5 :{
                    outputSutradaraBanyak(LSut);
                    system("pause");
                    break;
                }
                case 6 :{
                    outputAsis(LSut);
                    system("pause");
                    break;
                }
            }
            break;

            }
            case 4 :{
                system("cls");
                if (isEmptyParent(LSut)) {
                    cout << " Tidak ada data Sutradara " << endl;
                }
                if (isEmptyChild(LFil)) {
                    cout << " Tidak ada data Film" << endl;
                } else {
                    int noSut, noFil;
                    cout << " Pilih Sutradara : " << endl;
                    outputSutradara(LSut);
                    cout << " Masukkan No Sutradara : ";
                    cin >> noSut;
                    cout << " Pilih Film: " << endl;
                    outputFilm(LFil);
                    cout << " Masukkan No Film : ";
                    cin >> noFil;
                    createRelasi(LFil, LSut, noSut, noFil);
                }
                break;
            }
            case 5: {
                system("cls");
                cout << "Data yang ingin di ubah:" << endl;
                cout << "1. Sutradara" << endl;
                cout << "2. Film" << endl << endl;
                cout << "Pilihan anda : ";
                cin>>x;
                switch(x){
                    case 1: {
                        outputSutradara(LSut);
                        cout << " Masukkan No sutradara yang akan diubah :" << endl;
                        cin >> sut;
                        seqSearchSutradara(LSut,sut);
                        editsut(LSut);
                        break;
                    }
                    case 2:{
                        outputFilm(LFil);
                        cout << " Masukkan No film yang akan diubah:" << endl;
                        cin >> fil;
                        seqSearchFilm(LFil,fil);
                        editfil(LFil);
                    }
                }
                break;
            }
            case 0 : break;
            default : break;
        }
    } while(m != 0);
}
int main()
{

	listParent LSut;
	listChild LFil;

    newParentList(LSut);
    newChildList(LFil);

	menu(LSut, LFil);

    return 0;
}

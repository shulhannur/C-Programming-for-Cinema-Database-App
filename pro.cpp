#include "adt.h"

bool isEmptyParent(listParent L) {
	return (First(L) == NULL);
}
bool isEmptyChild(listChild L){
	return (First(L) == NULL);
}
bool isEmptyRelasi(listRelasi L){
	return (First(L) == NULL);
}
void newParentList(listParent &L) {
	First(L) = NULL;
}
void newChildList(listChild &L) {
	First(L) = NULL;
}
void createListRelasi(listRelasi &L) {
	First(L) = NULL;
}
adrP allocateSutradara(InfotypeParent x) {
    listRelasi R1;
	createListRelasi(R1);
	adrP P = new elmtParent;
	Info(P).noSutradara = x.noSutradara;
    Info(P).Nama = x.Nama;
	Info(P).Relasi = R1;
	Next(P) = NULL;
	Prev(P) = NULL;
	return P;
}
adrC allocateFilm(InfotypeChild x) {
	adrC P = new elmtChild;
	Info(P).Status = 0;
	Info(P).noFilm = x.noFilm;
	Info(P).Judul = x.Judul;
	Next(P) = NULL;
	Prev(P) = NULL;
	return P;
}
adrRelasi allocateRelasi(adrC x) {
	adrRelasi P = new elmtRelasi ;
	Film(P) = x;
	Prev(P) = NULL;
    Next(P) = NULL;
	return P;
}
void insertLastSutradara(listParent &L, adrP P) {
	if (!isEmptyParent(L)) {
		adrP Q = First(L);
		while (Next(Q) != NULL) {
            Q = Next(Q);
		}
		Next(Q) = P;
		Prev(P) = Q;
	} else {
		First(L) = P;
	}
}
void insertLastFilm(listChild &L, adrC P) {
	if (!isEmptyChild(L)) {
		adrC Q = First(L);
		while (Next(Q) != NULL) {
            Q = Next(Q);
		}
		Next(Q) = P;
		Prev(P) = Q;
	} else {
		First(L) = P;
	}
}
void createRelasi(listChild LFil, listParent LSut, int noSut, int noFil) {
    adrC Destination = seqSearchFilm(LFil, noFil);
    adrP Source = seqSearchSutradara(LSut, noSut);
    if (Source != NULL && Destination != NULL) {
        adrRelasi Pr = allocateRelasi(Destination);
        if(First(Info(Source).Relasi) == NULL) {
            First(Info(Source).Relasi) = Pr;
        }
        else {
            adrRelasi Q = First(Info(Source).Relasi);
            while (Next(Q) != NULL) {
                Q = Next(Q);
            }
            adrRelasi R = Pr;
            Next(Q) = R;
            Prev(R) = Q;
        }
        Info(Destination).Status = Info(Destination).Status + 1;
        if(Info(Destination).Status==1){
            Info(Destination).Utama=Info(Source).Nama;
            cout<<Info(Destination).Utama<<" sebagai sutradara utama"<<endl;
        }
        else {
            cout<<Info(Source).Nama<<" sebagai asisten"<<endl;
        }
        cout<<" DATA TERHUBUNG"<<endl;
        system("pause");
    } else {
        cout << " Nomor Sutradara atau Film tidak sesuai" << endl;
    }
}
void deleteSutradara(listParent &L, adrP &P) {
    adrRelasi R1 = First(Info(P).Relasi);
    while (R1 != NULL) {
        Info(Film(R1)).Status = Info(Film(R1)).Status - 1;
        R1 = Next(R1);
    }
    adrP Q, R;
    if (P != First(L)) {
        if (Next(P) != NULL) {
            if (Next(P) != NULL) {
                Q = Prev(P);
                R = Next(P);
                Prev(P) = NULL;
                Next(P) = NULL;
                Next(Q) = R;
                Prev(R) = Q;
            } else {
                Q = Prev(P);
                Prev(P) = NULL;
                Next(Q) = NULL;
            }
        } else {
            First(L) = NULL;
        }
    } else {
            Q = Next(P);
            Prev(Q) = NULL;
            First(L) = Q;
            Next(P) = NULL;
    }
}
void deleteFilm(listChild &L, adrC &P) {
    adrC Q, R;
    if (P != First(L)) {
        if (Next(P) != NULL) {
            Q = Prev(P);
            R = Next(P);
            Prev(P) = NULL;
            Next(P) = NULL;
            Next(Q) = R;
            Prev(R) = Q;
        } else {
            Q = Prev(P);
            Prev(P) = NULL;
            Next(Q) = NULL;
        }
    }else {
        if (Next(P) != NULL) {
            Q = Next(P);
            Prev(Q) = NULL;
            First(L) = Q;
            Next(P) = NULL;
        } else {
            First(L) = NULL;
        }
    }
}
adrP seqSearchSutradara(listParent L, int x) {
    adrP P = First(L);
    if (P != NULL) {
        while ((Next(P) != NULL) && (Info(P).noSutradara != x)) {
            P = Next(P);
        }
        if (Info(P).noSutradara != x) {
            return NULL;
        } else {
            return P;
        }
    } else {
        return P;
    }
}
adrC seqSearchFilm(listChild L, int x) {
    adrC P = First(L);
    if (P != NULL) {
        while ((Next(P) != NULL) && (Info(P).noFilm != x)) {
            P = Next(P);
        }
        if (Info(P).noFilm != x) {
            return NULL;
        } else {
            return P;
        }
    } else {
        return P;
    }
}
void outputSutradara(listParent L) {
	if (isEmptyParent(L)) {
		cout << " Data Sutradara Kosong" << endl;

	} else {
        adrP P = First(L);
        cout << endl;
        while (P != NULL) {
            cout << " No." << Info(P).noSutradara << " " << Info(P).Nama << endl;
            P = Next(P);
        }
    }
}
void outputFilm(listChild L) {
	if (isEmptyChild(L)) {
		cout << " Data Film Kosong" << endl;
	} else {
        adrC P = First(L);
        cout << endl;
        while (P != NULL) {
            cout << " No." << Info(P).noFilm << " " << Info(P).Judul << endl;
            P = Next(P);
        }
	}
}
void outputFilmCari(listParent LSut, int noSut) {
    adrP Source = seqSearchSutradara(LSut, noSut);
    adrRelasi P = First(Info(Source).Relasi);
    if (P == NULL) {
        cout << " Data Film dengan Sutradara tersebut kosong " << endl;
    } else {
        cout << endl;
        while (P != NULL) {
            cout << " No." << Info(Film(P)).noFilm << " " << Info(Film(P)).Judul << endl;
            P = Next(P);
        }
    }
}
void outputFilm2Sut(listChild LFil) {
    adrC P = First(LFil);
    int c = 0;
    while (P != NULL) {
        if (Info(P).Status == 2) {
            if (c == 0) cout << endl;
            cout << " No." << Info(P).noFilm << " " << Info(P).Judul << endl;
            c++;
        }
        P = Next(P);
    }
    if (c == 0) cout << " Data Film yang dibuat oleh 2 Sutradara kosong " << endl;
}
void outputSutradaraBanyak(listParent LSut) {
    if (!isEmptyParent(LSut)) {
        adrP P = First(LSut);
        adrP M;
        int f = 0;
        while (P != NULL) {
            adrRelasi Q = First(Info(P).Relasi);
            int x = 0;
            while (Q != NULL) {
                x++;
                Q = Next(Q);
            }
            if (x > f) {
                M = P;
                f = x;
            }
            P = Next(P);
        }
        if (f > 0) {
            cout << " Sutradara yang paling banyak terlibat dalam projek film adalah : " << Info(M).Nama << endl;
        } else {
            cout << " Data Sutradara dengan Film terbanyak kosong" << endl;
        }
    } else {
        cout << " Data Sutradara kosong" << endl;
    }
}
void outputAsis(listParent LSut){
    int x,y;
    x=0;
    y=0;
    adrP P = First(LSut);
    adrP M;
    while(P!= NULL){
        //cout<<"--- "<<Info(P).Nama<<" ----"<<endl;
        x=0;
            adrRelasi Q= First(Info(P).Relasi);
        while(Q!=NULL){
            adrC film = Film(Q);
            //cout<<"filmnya: "<<Info(film).Judul<<endl;
            if (Info(film).Utama!=Info(P).Nama)
                x++;
            //cout<<"x : "<<x<<endl;
            Q=Next(Q);
        }
        cout<<endl;
        //cout<<"posisi saat ini y: "<<y<<endl;
        //cout<<Info(P).Nama<<" punya "<<x<<" film"<<endl;
        //cout<<endl;
        if (x!=0 && ((y==0)||(x<y))){
            M=P;
            y=x;
        }
        P=Next(P);
    }
    //cout<<y<<" "<<Info(M).Nama<<endl;
    //if(y>0){
     cout<<"Asisten Sutradara paling sedikit terlibat : " << Info(M).Nama;
    //}
}
void editsut(listParent LSut){
        int x;
        string namas;
        adrP P  = seqSearchSutradara(LSut,x);
        if (P!=NULL){
            cout<<"Masukkan nama sutradara :";
            cin>>namas;
            Info(P).Nama=namas;
        }
}
void editfil(listChild LFil){
    int x;
    string namaf;
    adrC C = seqSearchFilm(LFil,x);
    if(C!=NULL){
            cout<<"Masukkan nama film :";
            cin>>namaf;
            Info(C).Judul=namaf;
        }
}

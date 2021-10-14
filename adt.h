#ifndef ADT_H_INCLUDED
#define ADT_H_INCLUDED

#include <iostream>
#include <cstdlib>

#define First(L) L.First
#define Info(P) P->Info
#define Next(P) P->Next
#define Prev(P) P->Prev
#define Film(P) P->Film

using namespace std;

typedef struct elmtRelasi *adrRelasi;
struct listRelasi {
    adrRelasi First;
};
typedef struct InfotypeParent {
    int noSutradara;
    listRelasi Relasi;
    string Nama;
};
typedef struct InfotypeChild {
    int noFilm, Status;
    string Judul, Utama;
};
typedef struct elmtParent *adrP;
typedef struct elmtChild *adrC;
struct elmtParent {
    InfotypeParent Info;
    adrP Next;
    adrP Prev;
};
struct elmtChild {
    InfotypeChild Info;
    adrC Next;
    adrC Prev;
};
struct elmtRelasi  {
    adrC Film;
    adrRelasi Next;
    adrRelasi Prev;
};
struct listParent {
    adrP First;
};
struct listChild {
    adrC First;
};

bool isEmptyParent(listParent L);
bool isEmptyChild(listChild L);
bool isEmptyRelasi(listRelasi L);
void newParentList(listParent &L);
void newChildList(listChild &L);
void createListRelasi(listRelasi &L);
adrP allocateSutradara(InfotypeParent x);
adrC allocateFilm(InfotypeChild x);
adrRelasi allocateRelasi(adrC x);
void insertLastSutradara(listParent &L, adrP P);
void insertLastFilm(listChild &L, adrC P);
void createRelasi(listChild LFil, listParent LSut, int noSut, int noFil);
void deleteSutradara(listParent &L, adrP &P);
void deleteFilm(listChild &L, adrC &P);
adrP seqSearchSutradara(listParent L, int x);
adrC seqSearchFilm(listChild L, int x);
void outputSutradara(listParent L);
void outputFilm(listChild L);
void outputFilmCari(listParent LSut, int noSut);
void outputFilm2Sut(listChild LFil);
void outputSutradaraBanyak(listParent LSut);
void outputAsis(listParent LSut);
void editsut(listParent LSut);
void editfil(listChild LFil);
#endif // ADT_H_INCLUDED

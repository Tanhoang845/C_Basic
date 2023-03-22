#ifndef FILE_DATA_TYPE
#define FILE_DATA_TYPE
enum { SUCCESS, FAIL };
typedef struct TSV
{
    char hoten[50];
    char sdt[20];
    char email[255];
    char zalo[25];
} SV;

// cau truc 1 con tro cua stack cai dat bang dslk don
typedef struct TStackSV
{
    SV data;
    struct TStackSV* next;
} STACKSV;

typedef struct SINHVIEN
{
    SV data;
    struct SINHVIEN* next; // con tro luu tru dia chi phan tu ke tiep
} lSV;
#endif
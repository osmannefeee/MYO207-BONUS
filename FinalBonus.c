//Osman Efe Güleç
//2420161037
//https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=yjahz8rBKd

#include <stdio.h>

void dizi_yazdir(int dizi[], int BOYUT) {
    int i;
    for (i = 0; i < BOYUT; i++) {
        printf("%3d", dizi[i]);
    }
    printf("\n");
}

void takas(int *ap, int *bp) {
    int gecici = *ap;
    *ap = *bp;
    *bp = gecici;
}

void baloncuk_sirala(int dizi[], int BOYUT) {
    int i, j;
    int takas_oldu;
    
    for (i = 0; i < BOYUT - 1; i++) {
        takas_oldu = 0;
        for (j = 0; j < BOYUT - i - 1; j++) {
            if (dizi[j] > dizi[j + 1]) {
                takas(&dizi[j], &dizi[j + 1]);
                takas_oldu = 1;
            }
        }
        if (takas_oldu == 0) break;
        
        printf("%d. tur sonucu: ", i + 1);
        dizi_yazdir(dizi, BOYUT);
    }
}

int ikili_arama(int dizi[], int bas_ind, int son_ind, int aranan) {
    while (bas_ind <= son_ind) {
        int orta = bas_ind + (son_ind - bas_ind) / 2;

        if (dizi[orta] == aranan)
            return orta;

        if (dizi[orta] < aranan)
            bas_ind = orta + 1;
        else
            son_ind = orta - 1;
    }
    return -1;
}

int main() {
    int A[] = {60, 61, 55, 53, 8, 5, 19, 57, 52, 67, 74, 1};
    int N = sizeof(A) / sizeof(A[0]);
    int aranan_sayi, sonuc;

    printf("Orijinal Dizi:\n");
    dizi_yazdir(A, N);
    

    baloncuk_sirala(A, N);
    
    
    printf("Siralanmis Sonuc Dizisi:\n");
    dizi_yazdir(A, N);

    printf("\nAranacak sayiyi giriniz: ");
    if (scanf("%d", &aranan_sayi) == 1) {
        sonuc = ikili_arama(A, 0, N - 1, aranan_sayi);

        if (sonuc != -1)
            printf("Sonuc: %d sayisi %d. indiste bulundu.\n", aranan_sayi, sonuc);
        else
            printf("Sonuc: %d sayisi dizide bulunamadi.\n", aranan_sayi);
    }

    return 0;
}
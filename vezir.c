#include <stdio.h>
#include <string.h>

// Şifreleme fonksiyonu
void sifrele(char metin[], int anahtar) {
    for (int i = 0; metin[i] != '\0'; i++) {
        if (metin[i] >= 'A' && metin[i] <= 'Z') {
            metin[i] = 'A' + (metin[i] - 'A' + anahtar) % 26;
        } else if (metin[i] >= 'a' && metin[i] <= 'z') {
            metin[i] = 'a' + (metin[i] - 'a' + anahtar) % 26;
        }
        // Diğer karakterler (boşluk, sayı, özel karakter) değişmez.
    }
}

// Deşifreleme fonksiyonu
void sifrecoz(char metin[], int anahtar) {
    for (int i = 0; metin[i] != '\0'; i++) {
        if (metin[i] >= 'A' && metin[i] <= 'Z') {
            metin[i] = 'A' + (metin[i] - 'A' - anahtar + 26) % 26;
        } else if (metin[i] >= 'a' && metin[i] <= 'z') {
            metin[i] = 'a' + (metin[i] - 'a' - anahtar + 26) % 26;
        }
        // Diğer karakterler değişmez.
    }
}

int main() {
    char metin[100];
    int anahtar, islem;

    printf("Metni girin: ");
    fgets(metin, sizeof(metin), stdin); // Boşluklu metin almak için

    printf("Anahtar (1-25): ");
    scanf("%d", &anahtar);

    printf("İşlem (1: Şifrele, 2: Deşifrele): ");
    scanf("%d", &islem);

    if (islem == 1) {
        sifrele(metin, anahtar);
        printf("Şifreli metin: %s\n", metin);
    } else if (islem == 2) {
        sifrecoz(metin, anahtar);
        printf("Çözülmüş metin: %s\n", metin);
    } else {
        printf("Geçersiz işlem!\n");
    }

    return 0;
}

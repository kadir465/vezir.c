#include <stdio.h>
#include <string.h>

// Şifreleme fonksiyonu
void sifrele(char metin[], int anahtar) {
  for (int i = 0; metin[i] != '\0'; i++) {//girilen metnin sonuna kadar devam eder
    if (metin[i] >= 'A' && metin[i] <= 'Z') {
      metin[i] = 'A' + (metin[i] - 'A' + anahtar) % 26;//anatar kadar eklenerek kayar alfaba dışıa çıkamak için mod 26 aldık
    } else if (metin[i] >= 'a' && metin[i] <= 'z') {
      metin[i] = 'a' + (metin[i] - 'a' + anahtar) % 26;
    }
  }
}

// Deşifreleme fonksiyonu
void desifreleme(char metin[], int anahtar) {
  for (int i = 0; metin[i] != '\0'; i++) {//girilen metnin sonuna kadar tüm karakterleri kontrolü devam eder
    if (metin[i] >= 'A' && metin[i] <= 'Z') {
      metin[i] = 'A' + (metin[i] - 'A' - anahtar + 26) % 26;//anahtar kadar geriye kayar alfaba dışıa çıkamak için mod 26 aldık ve 
    } else if (metin[i] >= 'a' && metin[i] <= 'z') {//26 ekledik çünkü modu çıkardığımı<da negatif bir sonuç olmasın diye
      metin[i] = 'a' + (metin[i] - 'a' - anahtar + 26) % 26;
    }
  }
}

int main() {
  char metin[100];
  int anahtar, islem;

  printf("Metni girin: ");
  fgets(metin, sizeof(metin), stdin); // kullanıcı boşluklu ifadeler de girebilir bundan dolayı fgets kullandık

  printf("Anahtar seçin (1-25): ");
  scanf("%d", &anahtar);

  printf("İşlem (1: Şifrele, 2: Deşifrele): ");
  scanf("%d", &islem);

  if (islem == 1) {
    sifrele(metin, anahtar);
    printf("Şifreli metin: %s\n", metin);
  } else if (islem == 2) {
    desifreleme(metin, anahtar);
    printf("Çözülmüş metin: %s\n", metin);
  } else {
    printf("Geçersiz işlem!\n");
  }

  return 0;
}

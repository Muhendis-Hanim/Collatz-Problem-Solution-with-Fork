#include <stdio.h>

#include <unistd.h>

#include <stdlib.h>

#include <sys/types.h>

#include <sys/wait.h>

int main() {
  int girilen_deger = 0;
  int fork_sayisi, durum_kodu;
  printf("Lutfen sayi giriniz: ");
  scanf("%d", & girilen_deger);
  if (girilen_deger <= 0) {
    printf("Girilen deger 0'dan kucuk ve 0'a esit olamaz.\n");
    return -1;
  }
  fork_sayisi = fork();
  if (fork_sayisi < 0) {
    printf("Cocuk olusturulamadi");
    return -1;
  } else if (fork_sayisi >= 0) {
    if (girilen_deger % 2 == 0) {
      girilen_deger = girilen_deger / 2;
    } else if (girilen_deger % 2 != 0) {
      girilen_deger = (3 * girilen_deger) + 1;
    }
    printf("%d\n", girilen_deger);
  } else {
    printf("fork_sayisi %d\n", fork_sayisi);
    printf("Child'in bitmesi bekleniyor..");
    wait( & durum_kodu);
  }
  return 1;

}
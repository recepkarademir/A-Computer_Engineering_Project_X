// include korumasi
#ifndef NotGiris  // if not define( bu kütüphane hala tanımlanmadıysa)
#define NotGiris // NotGiris kütüphanesini tanımlanır.
// yeni tanımlama yapılırsa bura çalışacak
// main içerisinde mainden önce tanımlanması gerekenler struct veya prototip gibi. buraya yazılmalıdır.

int secimekrani4();// NotGiris.cpp içindeki bir fonksiyonun prototipi tanımlanmış.
void OgrenciDersEkleme();// NotGiris.cpp içindeki bir fonksiyonun prototipi tanımlanmış.
void OgrenciDersNotGiris();// NotGiris.cpp içindeki bir fonksiyonun prototipi tanımlanmış.
void OgrenciDersListeleme();// NotGiris.cpp içindeki bir fonksiyonun prototipi tanımlanmış.
void OgrenciKarneOlustur();// (ders adına göre) NotGiris.cpp içindeki bir fonksiyonun prototipi tanımlanmış. 

#endif // zaten NotGiris kütüphanesini tanımlıysa endif ile işlem sonlandırılacak.

// include korumasi
#ifndef AnaSayfa  // if not define( bu kütüphane hala tanımlanmadıysa)
#define AnaSayfa // AnaSayfa kütüphanesini tanımlanır.
// yeni tanımlama yapılırsa bura çalışacak
// main içerisinde mainden önce tanımlanması gerekenler struct veya prototip gibi. buraya yazılmalıdır.

void Bilgi(); // AnaSayfa.cpp içindeki bir fonksiyonun prototipi tanımlanmış.
void KapanisBilgi();
#endif // zaten AnaSayfa kütüphanesini tanımlıysa endif ile işlem sonlandırılacak.

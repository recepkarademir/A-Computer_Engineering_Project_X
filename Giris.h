// include korumasi
#ifndef Giris  // if not define( bu kütüphane hala tanımlanmadıysa)
#define Giris // Giris kütüphanesini tanımlanır.
// yeni tanımlama yapılırsa bura çalışacak
// main içerisinde mainden önce tanımlanması gerekenler struct veya prototip gibi. buraya yazılmalıdır.

int GirisFonk(); // Giris.cpp içindeki bir fonksiyonun prototipi tanımlanmış.

#endif // zaten Giris kütüphanesini tanımlıysa endif ile işlem sonlandırılacak.

/* Programın kütüphaneleri include etme esnasında, sonsuz bir döngüye düşmemesi için aşağıdakiler yazılır.

#ifndef
#define

...

#endif

*/

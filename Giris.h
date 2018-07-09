// include korumasi
#ifndef Giris  // if not define( bu kütüphane hala tanýmlanmadýysa)
#define Giris // Giris kütüphanesini tanýmlanýr.
// yeni tanýmlama yapýlýrsa bura çalýþacak
// main içerisinde mainden önce tanýmlanmasý gerekenler struct veya prototip gibi. buraya yazýlmalýdýr.

int GirisFonk(); // Giris.cpp içindeki bir fonksiyonun prototipi tanýmlanmýþ.

#endif // zaten Giris kütüphanesini tanýmlýysa endif ile iþlem sonlandýrýlacak.

/* Programýn kütüphaneleri include etme esnasýnda, sonsuz bir döngüye düþmemesi için aþaðýdakiler yazýlýr.

#ifndef
#define

...

#endif

*/

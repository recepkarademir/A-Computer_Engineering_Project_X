#include <iostream>	 // cout, cin, cerr kullanabimek için.
#include "windows.h" // sleep() fonksiyonu için.
#include <conio.h>	// getc() için.
// Hazýrladýðým header dosyalarýnýn programa eklenilmesi.
#include "AnaSayfa.h" // Program açýlýþýndaki bilgi ekraný.
#include "Giris.h"  // Giris header dosyasý ekleniyor.
#include "Ders.h"  // Ders header dosyasý ekleniyor.
#include "NotGiris.h" // NotGiris header dosyasý ekleniyor.
#include "Ogrenci.h" // Ogrenci header dosyasý ekleniyor.
#include "OgretimElemani.h" // OgretimElemani header dosyasý ekleniyor.

using namespace std;

int main(int argc, char** argv)
{
	Bilgi(); // Program açýlýþýndaki bilgi ekranýný çalýþtýran fonksiyon.
	
	if(/*GirisFonk()==*/1) // Program giriþ paneline(giris.cpp) gidiyor ve giriþ baþarýlýysa 1 deðeriyle iþlemlere devam ediyor.
	{
		char secim=0;
		char devam; // alt modülerle iþlem yapýldýktan sonra ana modül seçimine devam edilsin mi kontrolü
		
		while(secim!=5) // Kullanýcý modül seçmeye devam etmek istemezse kapat deðiþkenine 5  deðerini atmýþ olmalýdýr.
		{
			system("cls");
			system("color 8A");// Ýlk rakam(veya harf) olan 8 arkaplan rengini, ikinci rakam(veya harf) A ise yazi rengini belirler.
			 
			cout<<"\n\n\n\n\n\n";
			for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t  ";}cout<<"\xb0";}
			cout<<endl;
			cout<<"\t\t\t\t\t  \xb0    \x99\xA7renci \x98\x9fleri Otomasyonu   \xb0";
			cout<<"\n\t\t\t\t\t  ";
			for(int k=0;k<34;++k){cout<<"\xb0";};
			cout<<endl;
			cout<<"\t\t\t\t\t  \xb0                                \xb0"<<endl;
			cout<<"\t\t\t\t\t  \xb1    KOD   MOD\x9AL ADI             \xb1"<<endl; // Kullanýcý buradaki modül kodlarýndan birini seçer.
			cout<<"\t\t\t\t\t  \xb1                                \xb1"<<endl;
			cout<<"\t\t\t\t\t  \xb2    1....\x99\xA6RENC\x98 MOD\x9AL\x9A         \xb2"<<endl;
			cout<<"\t\t\t\t\t  \xb2    2....\x99\xA6RET\x98M ELEMANI MOD\x9AL\x9A \xb2"<<endl;
			cout<<"\t\t\t\t\t  \xdb    3....DERS MOD\x9AL\x9A            \xdb"<<endl;
			cout<<"\t\t\t\t\t  \xdb    4....NOT G\x98R\x98\x9e MOD\x9AL\x9A       \xdb"<<endl;
			cout<<"\t\t\t\t\t  \xdb                                \xdb"<<endl;
			cout<<"\t\t\t\t\t  ";
			for(int k=0;k<34;++k){cout<<"\xdb";};cout<<endl;
			cout<<"\t\t\t\t\t Programdan \x87\x8Dk\x8D\x9f i\x87in 5 kodunu girin.\n";
			cout<<"\t\t\t\t      Program T\x81rk\x87""e veri giri\x9fini de destekler.\n";
			cout<<"\t\t\t\t\t   Mod\x81l se\x87iminizin kodunu girin: ";
			
			secim=getch();
			
			switch(secim) // Seçilen modül koduna göre programýn akýþý switch-case kontrol mekanizmasýyla belirlenir.
			{
				case '1': // 1 nolu öðrenci modülü seçilirse. secim==1 ise.
					CASE1:devam=0;
					switch(int pos1=secimekrani()) // Ogrenci Modülünün Paneli
					{
						case '1':
							OgrenciKayit();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE1;}
							
						case '2':
							OgrenciNoileArama();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE1;}
							
						case '3':
							OgrenciAdiylaArama();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE1;}
							
						case '4':
							OgrenciBolumeGoreListeleme();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE1;}
							
						case '5':
							OgrenciSinifaGoreListeleme();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE1;}
							
						case '6':
							OgrenciBilgiDuzenle();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE1;}
							
						case '8':// Herhangi bir ekranda ana menüye dönmek için 8 kodu girilmesi yeterli.
							system("cls");
							cout<<"\n\n\n\n\n\n";
							system("color F2");// Ýlk rakam arkaplani ikinci rakam ise yazi rengini belirler.
							cout<<"\t\t\t\t\t     Ana Men\x81ye Y\x94nlendiriliyorsunuz...  ";
							Sleep(1100);
							break;	// Ana modüllerin seçildiði panele while döngüsünün baþýn
							
						default:// 1,2,3,4,5,6 dýþýnda seçim deðeri girilirse. Yanlýþ modül kodu tuþlanýrsa.
							system("cls"); // Konsoldaki eski görüntüyü temizler.
							cout<<"\n\n\n\n\n\n";
							system("color F4");// Ýlk rakam arkaplani ikinci rakam ise yazi rengini belirler.
							cout<<"\t\t\t\t\t     Yanl\x8D\x9f Bir Se\x87im Yapt\x8Dn\x8Dz !  \n"; // Alt modül seçiminde hata yapýlýrsa.
							cout<<"\t\t\t\t\t     Ana Men\x81ye Y\x94nlendiriliyorsunuz...  ";
							Sleep(1300);
							break;
					}
					break;
				
				case '2': // 2 nolu öðretim elemaný modülü seçilirse. secim==2 ise.
					CASE2:devam=0;
					switch(int pos2=secimekrani2())// Ogretim Elemaný Modülünün Paneli
					{
						case '1':
							OgretimElemaniKayit();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE2;}
							
						case '2':
							OgretimElemaniArama();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE2;}
							
						case '3':
							OgrElBilgiDuzenle();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE2;}
							
						case '4':
							OgretimElemaniListeleme();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE2;}
							
						case '8':// Herhangi bir ekranda ana menüye dönmek için 8 kodu girilmesi yeterli.
							system("cls");
							cout<<"\n\n\n\n\n\n";
							system("color F2");// Ýlk rakam arkaplani ikinci rakam ise yazi rengini belirler.
							cout<<"\t\t\t\t\t     Ana Men\x81ye Y\x94nlendiriliyorsunuz...  ";
							Sleep(1100);
							break;// Ana modüllerin seçildiði panele while döngüsünün baþýn
							
						default:// 1,2,3,4 dýþýnda seçim deðeri girilirse.
							system("cls");
							cout<<"\n\n\n\n\n\n";
							system("color F4");// Ýlk rakam arkaplani ikinci rakam ise yazi rengini belirler.
							cout<<"\t\t\t\t\t     Yanl\x8D\x9f Bir Se\x87im Yapt\x8Dn\x8Dz !  \n"; // Alt modül seçiminde hata yapýlýrsa.
							cout<<"\t\t\t\t\t     Ana Men\x81ye Y\x94nlendiriliyorsunuz...  ";
							Sleep(1300);
							break;
					}
					break;
					
				case '3': // 3 nolu ders modülü seçilirse. secim==3 ise.
					CASE3:devam=0;
					switch(int pos3=secimekrani3()) // Ders Modülünün Paneli
					{
						case '1':
							DersEkleme();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE3;}
							
						case '2':
							DersBilgileriGuncelleme();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE3;}
							
						case '3':
							DersListeleme();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE3;}
							
						case '4':
							DersArama();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE3;}
							
						case '8':// Herhangi bir ekranda ana menüye dönmek için 8 kodu girilmesi yeterli.
							system("cls");
							cout<<"\n\n\n\n\n\n";
							system("color F2");// Ýlk rakam arkaplani ikinci rakam ise yazi rengini belirler.
							cout<<"\t\t\t\t\t     Ana Men\x81ye Y\x94nlendiriliyorsunuz...  ";
							Sleep(1100);
							break;// Ana modüllerin seçildiði panele while döngüsünün baþýn
							
						default:// 1,2,3,4 dýþýnda seçim deðeri girilirse.
							system("cls");
							cout<<"\n\n\n\n\n\n";
							system("color F4");// Ýlk rakam arkaplani ikinci rakam ise yazi rengini belirler.
							cout<<"\t\t\t\t\t     Yanl\x8D\x9f Bir Se\x87im Yapt\x8Dn\x8Dz !  \n"; // Alt modül seçiminde hata yapýlýrsa.
							cout<<"\t\t\t\t\t     Ana Men\x81ye Y\x94nlendiriliyorsunuz...  ";
							Sleep(1300);
							break;
					}
					break;
					
				case '4': // 4 nolu not giriþi modülü seçilirse. secim==4 ise 
					CASE4:devam=0;
					switch(int pos4=secimekrani4()) // // Not Giris Modülünün Paneli
					{
						case '1':
							OgrenciDersEkleme();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE4;}
							
						case '2':
							OgrenciDersNotGiris();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE4;}
							
						case '3':
							OgrenciDersListeleme();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE4;}
							
						case '4':
							OgrenciKarneOlustur();
							cout<<"\nDevam etmek i\x87in bo\x9fluk tu\x9funa bas";
							devam=getch();
							if(devam==' '){goto CASE4;}
							
						case '8': // Herhangi bir ekranda ana menüye dönmek için 8 kodu girilmesi yeterli.
							system("cls");
							cout<<"\n\n\n\n\n\n";
							system("color F2");// Ýlk rakam arkaplani ikinci rakam ise yazi rengini belirler.
							cout<<"\t\t\t\t\t     Ana Men\x81ye Y\x94nlendiriliyorsunuz...  ";
							Sleep(1100);
							break; // Ana modüllerin seçildiði panele while döngüsünün baþýna gidiþ baþlýyor.
							
						default:// 1,2,3,4,8 dýþýnda seçim deðeri girilirse.
							system("cls");
							cout<<"\n\n\n\n\n\n";
							system("color F4");// Ýlk rakam arkaplani ikinci rakam ise yazi rengini belirler.
							cout<<"\t\t\t\t\t     Yanl\x8D\x9f Bir Se\x87im Yapt\x8Dn\x8Dz !  \n"; // Alt modül seçiminde hata yapýlýrsa.
							cout<<"\t\t\t\t\t     Ana Men\x81ye Y\x94nlendiriliyorsunuz...  ";
							Sleep(1300);
							break;
					}
					break;

				case '5': // 4 nolu not giriþi modülü seçilirse. secim==4 ise
				// Modül seçiminden yani üstteki while dan çýkmak için.
				goto KAPAT;

				default: // 1,2,3,4 dýþýnda seçim deðeri girilirse.
					system("cls");
					cout<<"\n\n\n\n\n\n";
					system("color F4");// Ýlk rakam arkaplani ikinci rakam ise yazi rengini belirler.
					cout<<"\t\t\t\t\t     Yanl\x8D\x9f Bir Se\x87im Yapt\x8Dn\x8Dz !";
					Sleep(1000);
					break;
			}
		}
		KAPAT: // Bu etiket yanlýþ modül kodu girilince veya kullanýcýnýn programý kapatma isteði üzerine çalýþýr.
		KapanisBilgi(); // kapanýþ ekraný bilgisi yazdýrýlýcak. Ardýndan alttaki son return 0 a gidecek.
	}
	else // Program giriþ panelinde 3 kez hatalý þifre girildiðinde buraya geliyor ve kapanýyor.
	{
		return 0;
	}
	return 0; // Kullanýcý çýkýþ için kapat ý 5 yaparsa veya kritik bir hata ile karþýlaþýlýrsa program buraya gelecektir. 
}

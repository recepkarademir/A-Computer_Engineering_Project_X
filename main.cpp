#include <iostream>	 // cout, cin, cerr kullanabimek i�in.
#include "windows.h" // sleep() fonksiyonu i�in.
#include <conio.h>	// getc() i�in.
// Haz�rlad���m header dosyalar�n�n programa eklenilmesi.
#include "AnaSayfa.h" // Program a��l���ndaki bilgi ekran�.
#include "Giris.h"  // Giris header dosyas� ekleniyor.
#include "Ders.h"  // Ders header dosyas� ekleniyor.
#include "NotGiris.h" // NotGiris header dosyas� ekleniyor.
#include "Ogrenci.h" // Ogrenci header dosyas� ekleniyor.
#include "OgretimElemani.h" // OgretimElemani header dosyas� ekleniyor.

using namespace std;

int main(int argc, char** argv)
{
	Bilgi(); // Program a��l���ndaki bilgi ekran�n� �al��t�ran fonksiyon.
	
	if(/*GirisFonk()==*/1) // Program giri� paneline(giris.cpp) gidiyor ve giri� ba�ar�l�ysa 1 de�eriyle i�lemlere devam ediyor.
	{
		char secim=0;
		char devam; // alt mod�lerle i�lem yap�ld�ktan sonra ana mod�l se�imine devam edilsin mi kontrol�
		
		while(secim!=5) // Kullan�c� mod�l se�meye devam etmek istemezse kapat de�i�kenine 5  de�erini atm�� olmal�d�r.
		{
			system("cls");
			system("color 8A");// �lk rakam(veya harf) olan 8 arkaplan rengini, ikinci rakam(veya harf) A ise yazi rengini belirler.
			 
			cout<<"\n\n\n\n\n\n";
			for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t  ";}cout<<"\xb0";}
			cout<<endl;
			cout<<"\t\t\t\t\t  \xb0    \x99\xA7renci \x98\x9fleri Otomasyonu   \xb0";
			cout<<"\n\t\t\t\t\t  ";
			for(int k=0;k<34;++k){cout<<"\xb0";};
			cout<<endl;
			cout<<"\t\t\t\t\t  \xb0                                \xb0"<<endl;
			cout<<"\t\t\t\t\t  \xb1    KOD   MOD\x9AL ADI             \xb1"<<endl; // Kullan�c� buradaki mod�l kodlar�ndan birini se�er.
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
			
			switch(secim) // Se�ilen mod�l koduna g�re program�n ak��� switch-case kontrol mekanizmas�yla belirlenir.
			{
				case '1': // 1 nolu ��renci mod�l� se�ilirse. secim==1 ise.
					CASE1:devam=0;
					switch(int pos1=secimekrani()) // Ogrenci Mod�l�n�n Paneli
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
							
						case '8':// Herhangi bir ekranda ana men�ye d�nmek i�in 8 kodu girilmesi yeterli.
							system("cls");
							cout<<"\n\n\n\n\n\n";
							system("color F2");// �lk rakam arkaplani ikinci rakam ise yazi rengini belirler.
							cout<<"\t\t\t\t\t     Ana Men\x81ye Y\x94nlendiriliyorsunuz...  ";
							Sleep(1100);
							break;	// Ana mod�llerin se�ildi�i panele while d�ng�s�n�n ba��n
							
						default:// 1,2,3,4,5,6 d���nda se�im de�eri girilirse. Yanl�� mod�l kodu tu�lan�rsa.
							system("cls"); // Konsoldaki eski g�r�nt�y� temizler.
							cout<<"\n\n\n\n\n\n";
							system("color F4");// �lk rakam arkaplani ikinci rakam ise yazi rengini belirler.
							cout<<"\t\t\t\t\t     Yanl\x8D\x9f Bir Se\x87im Yapt\x8Dn\x8Dz !  \n"; // Alt mod�l se�iminde hata yap�l�rsa.
							cout<<"\t\t\t\t\t     Ana Men\x81ye Y\x94nlendiriliyorsunuz...  ";
							Sleep(1300);
							break;
					}
					break;
				
				case '2': // 2 nolu ��retim eleman� mod�l� se�ilirse. secim==2 ise.
					CASE2:devam=0;
					switch(int pos2=secimekrani2())// Ogretim Eleman� Mod�l�n�n Paneli
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
							
						case '8':// Herhangi bir ekranda ana men�ye d�nmek i�in 8 kodu girilmesi yeterli.
							system("cls");
							cout<<"\n\n\n\n\n\n";
							system("color F2");// �lk rakam arkaplani ikinci rakam ise yazi rengini belirler.
							cout<<"\t\t\t\t\t     Ana Men\x81ye Y\x94nlendiriliyorsunuz...  ";
							Sleep(1100);
							break;// Ana mod�llerin se�ildi�i panele while d�ng�s�n�n ba��n
							
						default:// 1,2,3,4 d���nda se�im de�eri girilirse.
							system("cls");
							cout<<"\n\n\n\n\n\n";
							system("color F4");// �lk rakam arkaplani ikinci rakam ise yazi rengini belirler.
							cout<<"\t\t\t\t\t     Yanl\x8D\x9f Bir Se\x87im Yapt\x8Dn\x8Dz !  \n"; // Alt mod�l se�iminde hata yap�l�rsa.
							cout<<"\t\t\t\t\t     Ana Men\x81ye Y\x94nlendiriliyorsunuz...  ";
							Sleep(1300);
							break;
					}
					break;
					
				case '3': // 3 nolu ders mod�l� se�ilirse. secim==3 ise.
					CASE3:devam=0;
					switch(int pos3=secimekrani3()) // Ders Mod�l�n�n Paneli
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
							
						case '8':// Herhangi bir ekranda ana men�ye d�nmek i�in 8 kodu girilmesi yeterli.
							system("cls");
							cout<<"\n\n\n\n\n\n";
							system("color F2");// �lk rakam arkaplani ikinci rakam ise yazi rengini belirler.
							cout<<"\t\t\t\t\t     Ana Men\x81ye Y\x94nlendiriliyorsunuz...  ";
							Sleep(1100);
							break;// Ana mod�llerin se�ildi�i panele while d�ng�s�n�n ba��n
							
						default:// 1,2,3,4 d���nda se�im de�eri girilirse.
							system("cls");
							cout<<"\n\n\n\n\n\n";
							system("color F4");// �lk rakam arkaplani ikinci rakam ise yazi rengini belirler.
							cout<<"\t\t\t\t\t     Yanl\x8D\x9f Bir Se\x87im Yapt\x8Dn\x8Dz !  \n"; // Alt mod�l se�iminde hata yap�l�rsa.
							cout<<"\t\t\t\t\t     Ana Men\x81ye Y\x94nlendiriliyorsunuz...  ";
							Sleep(1300);
							break;
					}
					break;
					
				case '4': // 4 nolu not giri�i mod�l� se�ilirse. secim==4 ise 
					CASE4:devam=0;
					switch(int pos4=secimekrani4()) // // Not Giris Mod�l�n�n Paneli
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
							
						case '8': // Herhangi bir ekranda ana men�ye d�nmek i�in 8 kodu girilmesi yeterli.
							system("cls");
							cout<<"\n\n\n\n\n\n";
							system("color F2");// �lk rakam arkaplani ikinci rakam ise yazi rengini belirler.
							cout<<"\t\t\t\t\t     Ana Men\x81ye Y\x94nlendiriliyorsunuz...  ";
							Sleep(1100);
							break; // Ana mod�llerin se�ildi�i panele while d�ng�s�n�n ba��na gidi� ba�l�yor.
							
						default:// 1,2,3,4,8 d���nda se�im de�eri girilirse.
							system("cls");
							cout<<"\n\n\n\n\n\n";
							system("color F4");// �lk rakam arkaplani ikinci rakam ise yazi rengini belirler.
							cout<<"\t\t\t\t\t     Yanl\x8D\x9f Bir Se\x87im Yapt\x8Dn\x8Dz !  \n"; // Alt mod�l se�iminde hata yap�l�rsa.
							cout<<"\t\t\t\t\t     Ana Men\x81ye Y\x94nlendiriliyorsunuz...  ";
							Sleep(1300);
							break;
					}
					break;

				case '5': // 4 nolu not giri�i mod�l� se�ilirse. secim==4 ise
				// Mod�l se�iminden yani �stteki while dan ��kmak i�in.
				goto KAPAT;

				default: // 1,2,3,4 d���nda se�im de�eri girilirse.
					system("cls");
					cout<<"\n\n\n\n\n\n";
					system("color F4");// �lk rakam arkaplani ikinci rakam ise yazi rengini belirler.
					cout<<"\t\t\t\t\t     Yanl\x8D\x9f Bir Se\x87im Yapt\x8Dn\x8Dz !";
					Sleep(1000);
					break;
			}
		}
		KAPAT: // Bu etiket yanl�� mod�l kodu girilince veya kullan�c�n�n program� kapatma iste�i �zerine �al���r.
		KapanisBilgi(); // kapan�� ekran� bilgisi yazd�r�l�cak. Ard�ndan alttaki son return 0 a gidecek.
	}
	else // Program giri� panelinde 3 kez hatal� �ifre girildi�inde buraya geliyor ve kapan�yor.
	{
		return 0;
	}
	return 0; // Kullan�c� ��k�� i�in kapat � 5 yaparsa veya kritik bir hata ile kar��la��l�rsa program buraya gelecektir. 
}

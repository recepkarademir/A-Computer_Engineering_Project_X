#include <iostream>
#include <conio.h>   // getc() için.
#include "windows.h" // sleep fonksiyonu için.
#include "Giris.h" // prototiplerin kütüphenesi
using namespace std;

int GirisFonk() // Herhangi bir parametre almayan int deðer döndüren fonksiyon.
{
	string sifre;
	double Sonuc=1, Hak=3; // Þifre doðru girildiðinde Sonuc deðiþkeni 0 oluyor. Þifre 3 kez hatalý girilme (Hak)kýna sahiptir.
	system("cls");
	
	while(Hak>0) // Þifre doðru girilene veya Hak 0 olana kadar döngü çalýþýr. 
	{
		cout<<"\n\n\n\n\t\t\t\t\t        \xdb\xdb\xdb\xdb\xdb\xdb\xBB  \xdb\xdb\xdb\xdb\xdb\xdb\xBB  \xdb\xdb\xBB \xdb\xdb\xdb\xdb\xdb\xBB"<<endl; 
		cout<<"\t\t\t\t\t        \xC8\xCD\xCD\xCD\xCD\xdb\xdb\xBB\xdb\xdb\xC9\xCD\xdb\xdb\xdb\xdb\xBB\xdb\xdb\xdb\xBA\xdb\xdb\xC9\xCD\xCD\xdb\xdb\xBB"<<endl;
		cout<<"\t\t\t\t\t        \xdb\xdb\xdb\xdb\xdb \xC9\xBC\xdb\xdb\xBA\xdb\xdb\xC9\xdb\xdb\xBA\xC8\xdb\xdb\xBA\xC8\xdb\xdb\xdb\xdb\xdb\xC9\xBC"<<endl;
		cout<<"\t\t\t\t\t        \xdb\xdb\xC9\xCD\xCD\xCD\xBC \xdb\xdb\xdb\xdb\xC9\xBC\xdb\xdb\xBA \xdb\xdb\xBA\xdb\xdb\xC9\xCD\xCD\xdb\xdb\xBB"<<endl;
		cout<<"\t\t\t\t\t        \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xBB\xC8\xdb\xdb\xdb\xdb\xdb\xdb\xC9\xBC \xdb\xdb\xBA\xC8\xdb\xdb\xdb\xdb\xdb\xC9\xBC"<<endl;
		cout<<"\t\t\t\t\t        \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC \xC8\xCD\xCD\xCD\xCD\xCD\xBC  \xC8\xCD\xBC \xC8\xCD\xCD\xCD\xCD\xBC "<<endl;

		system("color F1");// Ýlk rakam arkaplani ikinci rakam ise yazi rengini belirler.
		cout<<"\n\n\n";
		for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t     ";}cout<<"\xdb";}cout<<endl;
		
		cout<<"\t\t\t\t\t     \xdb    Otomasyon Giri\x9f Paneli      \xdb\n"; // \x9f küçük þ harfi için.
		for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t     ";}cout<<"\xdb";}
		cout<<endl;
		
		cout<<"\t\t\t\t\t     \xC9"; // xC9 , \xCD , \xBB , \xBA , \xC8 ve \xBC paneldeki köþelere koyulan özel karakterler.
		for(int i=0;i<32;++i){cout<<"\xCD";};
		cout<<"\xBB\n";
		cout<<"\t\t\t\t\t     \xBA     Kalan \x9fifre hakk\x8dn\x8dz :"<<Hak-1<<"    \xBA\n"; // Kullanýcýya kalan þifre hakký bildiriliyor.
		cout<<"\t\t\t\t\t     \xC8";
		for(int   i=0;i<32;++i){cout<<"\xCD";};
		cout<<"\xBC\n";
	
		cout<<"\t\t\t\t\t         \x9Eifrenizi Girin :";
		
	    cin>>sifre;// Kullanýcýnýn klavyeye girdiði deðer, kontrol için Sifre deðiþkenine atanýyor.
	    int s=0,wtf,g=3;
	    // Kullanýcýdan alýnan þifre, gerçek þifreyle kýyaslanýyor.
		for(unsigned int i=0,j=1;i<sifre.size();i++){char x=sifre.at(i);wtf=int(x);s=s+(j*j*j)*wtf;j++;}if(s==25940){g=6;Sonuc=0;}
		// Kullanýcý þifreyi doðru girdiyse Sonuc deðiþkeni 0 olur. Þifre admin ise öðretim elemaný moduna geçilir.	
		
		if (Sonuc==0) // Kullanýcý þifreyi doðru girdiyse Sonuc=0 olur ve bu if koþulu saðlanýr.
		{	
			system("cls"); // Konsol ekranýný temizleme fonksiyonu.
			
			system("color FA");// Ýlk rakam arkaplani ikinci rakam ise yazi rengini belirler.
			cout<<"\n\n\n\n\n\n\n\n\n\n";
	
			for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t   ";}cout<<"\xdb";}
			cout<<endl;
			cout<<"\t\t\t\t\t   \xdb                                \xdb\n";
			cout<<"\t\t\t\t\t   \xdb\t      \x9Eifreniz Do\xA7ru\t    \xdb\n"; //\x9E  büyük Þ harfi için.
			cout<<"\t\t\t\t\t   \xdb                                \xdb\n";
			for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t   ";}cout<<"\xdb";}
			cout<<endl;
			cout<<"\t\t\t\t\t   Y\x94nlendiriliyorsunuz "; // \x94  küçük ö harfi için.
			for(int j=0;j<13;++j)
			{
				Sleep(120);cout<<"\xAF";  // \xAF   »   sembolü.
			}
			
		
			Sleep(1400); // Sleep ile program beklemeye alýnýyor.
			system("cls"); // Konsol ekraný temizleme fonksiyonu.
			return 1; // main fonksiyonuna 1 deðeri döndürülüyor; Öðretim elemaný modu aktif olur.
			break; // while dan þifre kontrolünden ayrýlýyor.
		    // Þifre kullanýcýdan doðru olarak alýnmýþtýr. main fonksiyonuna 1 deðeri döndürülüyor.
			
		}
		else // Kullanýcýnýn þifreyi hatalý girdiði durumlarda bu blok çalýþýr.
		{
			Hak--;
			system("cls"); // Konsol ekraný temizleme fonksiyonu.
			system("color F4");// Ýlk rakam arkaplani ikinci rakam ise yazi rengini belirler.
			
			cout<<"\n\n\n\n\n\n\n\n\n\n";
			for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t   ";}cout<<"\xdb";}
			cout<<endl;
			cout<<"\t\t\t\t\t   \xdb                                \xdb\n";
			cout<<"\t\t\t\t\t   \xdb ";
			cout<<"\a  \x9Eifrenizi Yanl\x8d\x9f Girdiniz    \xdb\n";  // \x8d   küçük ý harfi için.
			cout<<"\t\t\t\t\t   \xdb                                \xdb\n";
			for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t   ";}cout<<"\xdb";}
			cout<<endl;
			cout<<"\t\t\t\t\t   Y\x94nlendiriliyorsunuz ";
			for(int j=0;j<13;++j)
			{
				Sleep(130);cout<<"\xAF";
			}
			
			Sleep(1000); // Sleep(1300); // Sleep ile program beklemeye alýnýyor.
			system("cls");
			continue; // Hak  sayýsý 0 dan büyükse þifre kontrolü için döngü baþýna gidiyor.
			
		}
		
	}
	if(Hak<=0) // Hak  sayýsý 0 dan küçük veya sýfýra eþise, sistem kapatýlýyor. if yazamasak ta program  hak <0 olunca buraya gelecek. 
	{
		system("cls");
		system("color F4");// Ýlk rakam arkaplani ikinci rakam ise yazi rengini belirler.
		cout<<"\n\n\n\n\n\n\n\n\n\n";
		
		for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t   ";}cout<<"\xdb";}
		cout<<endl;
		cout<<"\t\t\t\t\t   \xdb                                \xdb\n";
		cout<<"\t\t\t\t\t   \xdb ";
		cerr<<"\a    Eri\x9fim Engellendi !!!      \xdb\n"; // \x9f  küçük þ harfi için.
		cout<<"\t\t\t\t\t   \xdb                                \xdb\n";
		for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t   ";}cout<<"\xdb";}
		cout<<endl;
		cerr<<"\t\t\t\t\t    Sistem Kapat\x8dl\x8dyor ";  // \x8d   küçük ý harfi için.
		for(int j=0;j<8;++j)
		{
			Sleep(120);cout<<"\xE8";  //  \xE8   x iþareti.
		}
		Sleep(1300);
		return 0;
	}
}

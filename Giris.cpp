#include <iostream>
#include <conio.h>   // getc() i�in.
#include "windows.h" // sleep fonksiyonu i�in.
#include "Giris.h" // prototiplerin k�t�phenesi
using namespace std;

int GirisFonk() // Herhangi bir parametre almayan int de�er d�nd�ren fonksiyon.
{
	string sifre;
	double Sonuc=1, Hak=3; // �ifre do�ru girildi�inde Sonuc de�i�keni 0 oluyor. �ifre 3 kez hatal� girilme (Hak)k�na sahiptir.
	system("cls");
	
	while(Hak>0) // �ifre do�ru girilene veya Hak 0 olana kadar d�ng� �al���r. 
	{
		cout<<"\n\n\n\n\t\t\t\t\t        \xdb\xdb\xdb\xdb\xdb\xdb\xBB  \xdb\xdb\xdb\xdb\xdb\xdb\xBB  \xdb\xdb\xBB \xdb\xdb\xdb\xdb\xdb\xBB"<<endl; 
		cout<<"\t\t\t\t\t        \xC8\xCD\xCD\xCD\xCD\xdb\xdb\xBB\xdb\xdb\xC9\xCD\xdb\xdb\xdb\xdb\xBB\xdb\xdb\xdb\xBA\xdb\xdb\xC9\xCD\xCD\xdb\xdb\xBB"<<endl;
		cout<<"\t\t\t\t\t        \xdb\xdb\xdb\xdb\xdb \xC9\xBC\xdb\xdb\xBA\xdb\xdb\xC9\xdb\xdb\xBA\xC8\xdb\xdb\xBA\xC8\xdb\xdb\xdb\xdb\xdb\xC9\xBC"<<endl;
		cout<<"\t\t\t\t\t        \xdb\xdb\xC9\xCD\xCD\xCD\xBC \xdb\xdb\xdb\xdb\xC9\xBC\xdb\xdb\xBA \xdb\xdb\xBA\xdb\xdb\xC9\xCD\xCD\xdb\xdb\xBB"<<endl;
		cout<<"\t\t\t\t\t        \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xBB\xC8\xdb\xdb\xdb\xdb\xdb\xdb\xC9\xBC \xdb\xdb\xBA\xC8\xdb\xdb\xdb\xdb\xdb\xC9\xBC"<<endl;
		cout<<"\t\t\t\t\t        \xC8\xCD\xCD\xCD\xCD\xCD\xCD\xBC \xC8\xCD\xCD\xCD\xCD\xCD\xBC  \xC8\xCD\xBC \xC8\xCD\xCD\xCD\xCD\xBC "<<endl;

		system("color F1");// �lk rakam arkaplani ikinci rakam ise yazi rengini belirler.
		cout<<"\n\n\n";
		for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t     ";}cout<<"\xdb";}cout<<endl;
		
		cout<<"\t\t\t\t\t     \xdb    Otomasyon Giri\x9f Paneli      \xdb\n"; // \x9f k���k � harfi i�in.
		for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t     ";}cout<<"\xdb";}
		cout<<endl;
		
		cout<<"\t\t\t\t\t     \xC9"; // xC9 , \xCD , \xBB , \xBA , \xC8 ve \xBC paneldeki k��elere koyulan �zel karakterler.
		for(int i=0;i<32;++i){cout<<"\xCD";};
		cout<<"\xBB\n";
		cout<<"\t\t\t\t\t     \xBA     Kalan \x9fifre hakk\x8dn\x8dz :"<<Hak-1<<"    \xBA\n"; // Kullan�c�ya kalan �ifre hakk� bildiriliyor.
		cout<<"\t\t\t\t\t     \xC8";
		for(int   i=0;i<32;++i){cout<<"\xCD";};
		cout<<"\xBC\n";
	
		cout<<"\t\t\t\t\t         \x9Eifrenizi Girin :";
		
	    cin>>sifre;// Kullan�c�n�n klavyeye girdi�i de�er, kontrol i�in Sifre de�i�kenine atan�yor.
	    int s=0,wtf,g=3;
	    // Kullan�c�dan al�nan �ifre, ger�ek �ifreyle k�yaslan�yor.
		for(unsigned int i=0,j=1;i<sifre.size();i++){char x=sifre.at(i);wtf=int(x);s=s+(j*j*j)*wtf;j++;}if(s==25940){g=6;Sonuc=0;}
		// Kullan�c� �ifreyi do�ru girdiyse Sonuc de�i�keni 0 olur. �ifre admin ise ��retim eleman� moduna ge�ilir.	
		
		if (Sonuc==0) // Kullan�c� �ifreyi do�ru girdiyse Sonuc=0 olur ve bu if ko�ulu sa�lan�r.
		{	
			system("cls"); // Konsol ekran�n� temizleme fonksiyonu.
			
			system("color FA");// �lk rakam arkaplani ikinci rakam ise yazi rengini belirler.
			cout<<"\n\n\n\n\n\n\n\n\n\n";
	
			for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t   ";}cout<<"\xdb";}
			cout<<endl;
			cout<<"\t\t\t\t\t   \xdb                                \xdb\n";
			cout<<"\t\t\t\t\t   \xdb\t      \x9Eifreniz Do\xA7ru\t    \xdb\n"; //\x9E  b�y�k � harfi i�in.
			cout<<"\t\t\t\t\t   \xdb                                \xdb\n";
			for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t   ";}cout<<"\xdb";}
			cout<<endl;
			cout<<"\t\t\t\t\t   Y\x94nlendiriliyorsunuz "; // \x94  k���k � harfi i�in.
			for(int j=0;j<13;++j)
			{
				Sleep(120);cout<<"\xAF";  // \xAF   �   sembol�.
			}
			
		
			Sleep(1400); // Sleep ile program beklemeye al�n�yor.
			system("cls"); // Konsol ekran� temizleme fonksiyonu.
			return 1; // main fonksiyonuna 1 de�eri d�nd�r�l�yor; ��retim eleman� modu aktif olur.
			break; // while dan �ifre kontrol�nden ayr�l�yor.
		    // �ifre kullan�c�dan do�ru olarak al�nm��t�r. main fonksiyonuna 1 de�eri d�nd�r�l�yor.
			
		}
		else // Kullan�c�n�n �ifreyi hatal� girdi�i durumlarda bu blok �al���r.
		{
			Hak--;
			system("cls"); // Konsol ekran� temizleme fonksiyonu.
			system("color F4");// �lk rakam arkaplani ikinci rakam ise yazi rengini belirler.
			
			cout<<"\n\n\n\n\n\n\n\n\n\n";
			for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t   ";}cout<<"\xdb";}
			cout<<endl;
			cout<<"\t\t\t\t\t   \xdb                                \xdb\n";
			cout<<"\t\t\t\t\t   \xdb ";
			cout<<"\a  \x9Eifrenizi Yanl\x8d\x9f Girdiniz    \xdb\n";  // \x8d   k���k � harfi i�in.
			cout<<"\t\t\t\t\t   \xdb                                \xdb\n";
			for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t   ";}cout<<"\xdb";}
			cout<<endl;
			cout<<"\t\t\t\t\t   Y\x94nlendiriliyorsunuz ";
			for(int j=0;j<13;++j)
			{
				Sleep(130);cout<<"\xAF";
			}
			
			Sleep(1000); // Sleep(1300); // Sleep ile program beklemeye al�n�yor.
			system("cls");
			continue; // Hak  say�s� 0 dan b�y�kse �ifre kontrol� i�in d�ng� ba��na gidiyor.
			
		}
		
	}
	if(Hak<=0) // Hak  say�s� 0 dan k���k veya s�f�ra e�ise, sistem kapat�l�yor. if yazamasak ta program  hak <0 olunca buraya gelecek. 
	{
		system("cls");
		system("color F4");// �lk rakam arkaplani ikinci rakam ise yazi rengini belirler.
		cout<<"\n\n\n\n\n\n\n\n\n\n";
		
		for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t   ";}cout<<"\xdb";}
		cout<<endl;
		cout<<"\t\t\t\t\t   \xdb                                \xdb\n";
		cout<<"\t\t\t\t\t   \xdb ";
		cerr<<"\a    Eri\x9fim Engellendi !!!      \xdb\n"; // \x9f  k���k � harfi i�in.
		cout<<"\t\t\t\t\t   \xdb                                \xdb\n";
		for(int i=0;i<34;++i){if(i==0){cout<<"\t\t\t\t\t   ";}cout<<"\xdb";}
		cout<<endl;
		cerr<<"\t\t\t\t\t    Sistem Kapat\x8dl\x8dyor ";  // \x8d   k���k � harfi i�in.
		for(int j=0;j<8;++j)
		{
			Sleep(120);cout<<"\xE8";  //  \xE8   x i�areti.
		}
		Sleep(1300);
		return 0;
	}
}

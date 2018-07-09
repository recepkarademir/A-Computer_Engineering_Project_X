#include <iostream>
#include "Ogrenci.h"
#include "windows.h" // SLEEP()���N
#include <conio.h>  // getc() i�in.
using namespace std;

int secimekrani()//Alt Mod�llerini Se�mek i�in kullan�lan fonksiyon.
{ 
	char altsecim=0;
	system("cls");
	system("color F1");
	cout<<"\n\n\n";
	cout<<"\n\t\t\t\t      ";for(int i=0;i<44;++i){cout<<"\xb0";};cout<<endl;
	cout<<"\t\t\t\t      \xb0           \x99\xA7renci Alt Mod\x81lleri          \xb0";
	cout<<"\n\t\t\t\t      ";for(int i=0;i<44;++i){cout<<"\xb0";};cout<<endl;
	cout<<endl;
	cout<<"\t\t\t\t       ";for(int i=0;i<42;++i){cout<<"\xdb";};cout<<endl;
	cout<<"\t\t\t\t       \xdb                                        \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb   KOD   ALT MOD\x9AL ADI                  \xdb"<<endl; // Kullan�c� buradaki alt mod�l kodlar�ndan birini se�er.
	cout<<"\t\t\t\t       \xdb                                        \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    1....\x99\xA7renci kay\x8Dt                  \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb";for(int i=0;i<40;++i){cout<<"\xcd";};cout<<"\xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    \x99\xA6RENC\x98 ARAMA                       \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    2....\x99\xA7renci numaras\x8Dna g\x94re ara    \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    3....\x99\xA7renci ad\x8Dna g\x94re ara         \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb";for(int i=0;i<40;++i){cout<<"\xcd";};cout<<"\xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    \x99\xA6RENC\x98 L\x98STELEME                   \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    4....B\x94l\x81me g\x94re listeleme          \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    5....S\x8dn\x8d""fa g\x94re listeleme          \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb";for(int i=0;i<40;++i){cout<<"\xcd";};cout<<"\xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    6....\x99\xA7renci bilgileri d\x81zeltme     \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb                                        \xdb"<<endl;
	cout<<"\t\t\t\t       ";for(int i=0;i<42;++i){cout<<"\xdb";};cout<<endl;
	cout<<"\t\t\t\t           Ana men\x81ye gitmek i\x87in 8 kodunu girin. "<<endl;
	cout<<"\t\t\t\t             Mod\x81l se\x87iminizin kodunu girin: ";
	
	altsecim=getch();

	return altsecim;
}
void OgrenciKayit() // ��rencinin kay�t edildi�i fonksiyon.
{
	system("cls");
	char adsoyad[20],bolum[25]; // kay�t i�in de�i�ken tan�mlamalar�.
	cout<<"\n\n";
	for(int h=0;h<25;++h)
	{
		cout<<"====";
	}
	cout<<"\n\n\n\t\t\tAd Soyad (kelime aralar\x8Dna bo\x9fluk koymay\x8Dn) : ";
	cin>>adsoyad;
	cout<<"\n\n\n\t\t\t\x99\xA7rencinin B�l�m�n� Girin (kelime aralar\x8Dna bo\x9fluk koymay\x8Dn): ";
	cin>>bolum;
	int sinif,no;
	cout<<"\n\n\n\t\t\t\x99\xA7renci Numaras\x8Dn\x8D Girin (10 haneli): ";
	cin>>no;
	cout<<"\n\n\n\t\t\t\x99\xA7renci S\x8Dn\x8D""f�n� Girin : ";
	cin>>sinif;
	
	FILE *write; // write pointere tan�mland�.
	
	
	write=fopen("ogrenci.txt","a"); // a dosyaya �nceki kay�tlar� silmeden kay�t eklemek i�in.
	
	if( write==NULL ) //
	{
		cerr<<"ogrenci.txt acilamadi"; // dosya olu�turulamad�ysa.
		exit(1);
	}
	
	
	fprintf(write, "%10d %20s %25s %3d\n",no,adsoyad,bolum,sinif); // ogrenci.txt ye veriler yaz�l�yor.
	
	
	fclose(write); // dosyalama kapat�l�yor.
	for(int h=0;h<25;++h)
	{
		cout<<"====";
	}
	cout<<"\n\n\n\t\t\tBilgiler kaydedildi."<<endl;
}

void OgrenciNoileArama() // ��rencinin txt de numaras� ile arand��� fonksiyon.
{	
	system("cls");
	FILE *read;
	char adsoyad[20],bolum[25];
	int sinif,no,ArananNo; // verilerin okundu�unda kontrol edilebilmesi i�in.
	
	if( (read=fopen("ogrenci.txt","r"))==NULL )
	{
		cout<<" Dosya okuma ba\x9f""ar�s�z.";
		exit(1);
	}
	cout<<"Aranan ��rencinin numaras�n� girin : ";
	cin>>ArananNo;
	cout<<"\n\n";
	int bulundu=0;// aranan ��renci bulunup bulunmad��� kontrol i�in.Bulunursa 1 olur.
	while(!feof(read)) // ogrenci.txt i�erisinde aran�yor.
	{
		fscanf(read,"%10d %20s %25s %3d", &no,adsoyad,bolum,&sinif); // txt deki de�erler okunuyor.
		if(no==ArananNo) // aranan no ile txt deki no ayn�ysa pointer�n bulundu�u sat�rdan okunan de�i�kenler yazd�r�l�yor.
		{
			bulundu=1; // aranan ��renci varsa
			printf("%10d %20s %25s %3d",no,adsoyad,bolum,sinif); // bulunduysa veriler yazd�r�l�yor.
			break;
		}
		
		
	}
	fclose(read);// dosya kapatma.
	cout<<"\n\n";
	if(bulundu==0)
	{
		cout<<"Aranan \x99\xA7renci Yok."<<endl;
	}
}
	
void OgrenciAdiylaArama() // ogrenci.txt i�erisinde ��rencinin ad�yla arand��� fonksiyon.
{
	system("cls");
	string AdSoyad;
	cout<<"\n\nAranan ��rencinin ad�n� soyad�n� eksiksiz bo\x9fluk koymadan girin : ";
	cin>>AdSoyad;
	FILE *read;
	char adsoyad[20],bolum[25];
	int sinif;
	int no;
	cout<<"\n\n";
	if( (read=fopen("ogrenci.txt","r"))==NULL )
	{
		cout<<" Dosya okuma ba\x9f""ar�s�z.";
		exit(1);
	}
	
	int bulundu=0;// aranan ��renci bulunup bulunmad��� kontrol i�in.Bulunursa 1 olur.
	while(!feof(read)) //ogrenci.txt i�erisinde sat�r sat�r ��rencinin ad� aran�yor.
	{
		fscanf(read,"%10d %20s %25s %3d", &no,adsoyad,bolum,&sinif); // txt deki sat�r�n verileri kontrol i�in okunuyor.
		if(adsoyad==AdSoyad) // adsoyad kontrol ediliyor.
		{
			bulundu=1; // aranan ��renci varsa
			if(!!feof(read)) // Son buldu�u ki�iyi iki defa yazmamas� i�in.
			{
				break;
			}
			printf("%10d %20s %25s %3d",no,adsoyad,bolum,sinif); // bulunduysa veriler yazd�r�l�yor.
			cout<<endl;
		}
		
	}
	fclose(read);
	cout<<"\n\n";
	if(bulundu==0)
	{
		cout<<"Aranan \x99\xA7renci Yok."<<endl;
	}	
}

void OgrenciBolumeGoreListeleme() // ogrenci.txt i�erisindeki veri okunup ekrana bolumun ad�na g�re alfabetik olarak s�ralan�yor.
{	
	system("cls");
	FILE *read;
	char adsoyad[20],bolum[25];
	char      alfabe[31]={'a','b','c','�','d','e','f','g','�','h','�','i','j','k','l','m','n','o','�','p','r','s','�','t','u','�','v','w','x','y','z'};
	char buyukalfabe[31]={'A','B','C','�','D','E','F','G','�','H','I','�','J','K','L','M','N','O','�','P','R','S','�','T','U','�','V','W','X','Y','Z'};
	int sinif,no;
	
	if( (read=fopen("ogrenci.txt","r"))==NULL )
	{
		cout<<" Dosya okuma ba\x9f""ar�s�z.";
		exit(1);
	}
	cout<<"\n\n\t\tB�l�me G�re Alfabetik S�ralama Yap�ld�\n";
	for(int l=0;l<25;++l)
	{
		cout<<"====";
	}
	cout<<endl;
	
	
	
		read=fopen("ogrenci.txt","r");
		int p=0;
		while(!feof(read))// b�t�n dok�man incelenip harf s�ras� gelen listeleniyor.
		{
			while(p<32)
			{
				fscanf(read,"%10d %20s %25s %3d", &no,adsoyad,bolum,&sinif);
				
				if(bolum[0]==alfabe[p] or bolum[0]==buyukalfabe[p])
				{
					printf("%10d %20s %25s %3d",no,adsoyad,bolum,sinif);
					cout<<endl;
				}
				p++;
			}
			p=0;
		}
	
	
	fclose(read);
	for(int l=0;l<25;++l)
	{
		cout<<"====";
	}
}
	
void OgrenciSinifaGoreListeleme() // ogrenci.txt i�erisindeki veriler ekrana, ��rencinin s�n�f�na g�re numerik s�rayla bas�l�r.
{
	system("cls");
	
	FILE *read;
	char adsoyad[20],bolum[25];
	int sinif;
	int no;
	
	if( (read=fopen("ogrenci.txt","r"))==NULL )
	{
		cout<<" Dosya okuma ba\x9f""ar�s�z.";
		exit(1);
	}
	cout<<"S�n�fa G�re Numerik S�ralama Yap�l�yor\n";
	int siralamadegeri=1;
	for(int l=0;l<25;++l)
	{
		cout<<"====";
	}
	cout<<endl;
	while(siralamadegeri<10) // 10 y�ldan fazla �nversitede kalan ��renci yoktur.   ;-)
	{
		read=fopen("ogrenci.txt","r");
		while(!feof(read))
		{
			fscanf(read,"%10d %20s %25s %3d", &no,adsoyad,bolum,&sinif);
			if(!!feof(read)) // Son buldu�u ki�iyi iki defa yazmamas� i�in.
			{
				break;
			}
			
			if(int(sinif)==siralamadegeri) // BURADA ASCII DE�ER� YARDIMIYLA B�L�M�N �LK HARF�YLE SIRALAMA YAPILDI.
			{
				printf("%10d %20s %25s %3d",no,adsoyad,bolum,sinif);
				cout<<endl;
			}
		
		}
		fclose(read);
		siralamadegeri++; // B�R SONRAK� SAYIYA G�RE SIRALAMA YAPMASI ���N.
	}
	fclose(read);
	for(int l=0;l<25;++l)
	{
		cout<<"====";
	}
		
}

void OgrenciBilgiDuzenle() // ��rencinin varl���n�n kontrol edilip ��renci varsa bilgilerinin d�zenleyen fonk.
{
	system("cls");
	char adsoyad[20],bolum[25];
	int secim=0,DuzenlenecekOgrNo,bulundu=0,sinif,no; // txt deki verileri okumak i�in.
	
	cout<<"Bilgileri d�zenlenecek ��rencinin numaras�n� girin : ";
	cin>>DuzenlenecekOgrNo;
	
	
	FILE *update; // write pointere tan�mland�.
	
	
	update=fopen("ogrenci.txt","r+"); // r+ dosyaya �nceki kay�tlar� silmeden kay�t eklemek ve okumak i�in.
	
	if( update==NULL ) //
	{
		cerr<<"ogrenci.txt acilamadi"; // dosya olu�turulamad�ysa.
		exit(1);
	}
	
	
	while(!feof(update)) // girilen ��renci nosuna kay�tl� ��renci varsa d�zenleme yap�labilir. 
	{
		fscanf(update,"%10d %20s %25s %3d",&no,adsoyad,bolum,&sinif); // veriler txt den okunuyor.
		
		if(no==DuzenlenecekOgrNo) // txt deki no girilen ��renci numaras�yla ayn�ysa ��renciyi d�zenle.
		{
			cout<<"\x99\xA7renci ad soyad d�zenlemek i�in 1 e basin\n";
			cout<<"\x99\xA7renci b�l�m d�zenlemek i�in    2 e basin\n";
			cout<<"\x99\xA7renci s�n�f d�zenlemek i�in    3 e basin\n";
			//Ogrenci no duzenlenemez.
			cin>>secim;
			system("cls");
			cout<<"Ogrenci Bilgisinin Eski Hali:\n";
			printf("%10d %20s %25s %3d",no,adsoyad,bolum,sinif);cout<<"\n";
			if (secim==1)
			{
				cout<<"Ad Soyad (kelime aralar�na bo\x9fluk koymay�n) : ";
				cin>>adsoyad;
			}
			else if(secim==2)
			{
				cout<<"\x99\xA7rencinin Bolumunu Girin (kelime aralarina bo\x9fluk koymayin): ";
				cin>>bolum;
			}
			else if(secim==3)
			{
				cout<<"\x99\xA7renci Sinifini Girin : ";
				cin>>sinif;
			}
			else
			{
				cout<<"Hatal� tu\x9flama yaptiniz.";
			}
			
			cout<<"\x99\xA7renci Bilgisinin Yeni Hali:\n";
			printf("%10d %20s %25s %3d",no,adsoyad,bolum,sinif);cout<<"\n";
			fseek(update,sizeof(DuzenlenecekOgrNo),SEEK_CUR);
			fseek(update,-65,SEEK_CUR);// Bir �nceki sat�rda de�i�ikli�e gitmek i�in pointer txt i�erisindeki konumu kayd�r�l�yor.
			fprintf(update, "%10d %20s %25s %3d\n",no,adsoyad,bolum,sinif); // ogrenci.txt ye veriler yaz�l�yor.
			bulundu=1; // aranan ��renci numaras� varsa
			
			cout<<"Duzenleme ba\x9f""arili"<<endl;
			break;
		}
		
	}
	fclose(update); // �st�n� a��k b�rakmamak laz�m :D
	
	if(bulundu==0)// veri bulunamad�ysa.
	{
		cout<<"Bu no lu ogrenci kayitta Yok."<<endl;
		Sleep(1500);
	}
	
}

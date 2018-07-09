#include <iostream>
#include "Ogrenci.h"
#include "windows.h" // SLEEP()ÝÇÝN
#include <conio.h>  // getc() için.
using namespace std;

int secimekrani()//Alt Modüllerini Seçmek için kullanýlan fonksiyon.
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
	cout<<"\t\t\t\t       \xdb   KOD   ALT MOD\x9AL ADI                  \xdb"<<endl; // Kullanýcý buradaki alt modül kodlarýndan birini seçer.
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
void OgrenciKayit() // Öðrencinin kayýt edildiði fonksiyon.
{
	system("cls");
	char adsoyad[20],bolum[25]; // kayýt için deðiþken tanýmlamalarý.
	cout<<"\n\n";
	for(int h=0;h<25;++h)
	{
		cout<<"====";
	}
	cout<<"\n\n\n\t\t\tAd Soyad (kelime aralar\x8Dna bo\x9fluk koymay\x8Dn) : ";
	cin>>adsoyad;
	cout<<"\n\n\n\t\t\t\x99\xA7rencinin Bölümünü Girin (kelime aralar\x8Dna bo\x9fluk koymay\x8Dn): ";
	cin>>bolum;
	int sinif,no;
	cout<<"\n\n\n\t\t\t\x99\xA7renci Numaras\x8Dn\x8D Girin (10 haneli): ";
	cin>>no;
	cout<<"\n\n\n\t\t\t\x99\xA7renci S\x8Dn\x8D""fýný Girin : ";
	cin>>sinif;
	
	FILE *write; // write pointere tanýmlandý.
	
	
	write=fopen("ogrenci.txt","a"); // a dosyaya önceki kayýtlarý silmeden kayýt eklemek için.
	
	if( write==NULL ) //
	{
		cerr<<"ogrenci.txt acilamadi"; // dosya oluþturulamadýysa.
		exit(1);
	}
	
	
	fprintf(write, "%10d %20s %25s %3d\n",no,adsoyad,bolum,sinif); // ogrenci.txt ye veriler yazýlýyor.
	
	
	fclose(write); // dosyalama kapatýlýyor.
	for(int h=0;h<25;++h)
	{
		cout<<"====";
	}
	cout<<"\n\n\n\t\t\tBilgiler kaydedildi."<<endl;
}

void OgrenciNoileArama() // Öðrencinin txt de numarasý ile arandýðý fonksiyon.
{	
	system("cls");
	FILE *read;
	char adsoyad[20],bolum[25];
	int sinif,no,ArananNo; // verilerin okunduðunda kontrol edilebilmesi için.
	
	if( (read=fopen("ogrenci.txt","r"))==NULL )
	{
		cout<<" Dosya okuma ba\x9f""arýsýz.";
		exit(1);
	}
	cout<<"Aranan öðrencinin numarasýný girin : ";
	cin>>ArananNo;
	cout<<"\n\n";
	int bulundu=0;// aranan öðrenci bulunup bulunmadýðý kontrol için.Bulunursa 1 olur.
	while(!feof(read)) // ogrenci.txt içerisinde aranýyor.
	{
		fscanf(read,"%10d %20s %25s %3d", &no,adsoyad,bolum,&sinif); // txt deki deðerler okunuyor.
		if(no==ArananNo) // aranan no ile txt deki no aynýysa pointerýn bulunduðu satýrdan okunan deðiþkenler yazdýrýlýyor.
		{
			bulundu=1; // aranan öðrenci varsa
			printf("%10d %20s %25s %3d",no,adsoyad,bolum,sinif); // bulunduysa veriler yazdýrýlýyor.
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
	
void OgrenciAdiylaArama() // ogrenci.txt içerisinde öðrencinin adýyla arandýðý fonksiyon.
{
	system("cls");
	string AdSoyad;
	cout<<"\n\nAranan öðrencinin adýný soyadýný eksiksiz bo\x9fluk koymadan girin : ";
	cin>>AdSoyad;
	FILE *read;
	char adsoyad[20],bolum[25];
	int sinif;
	int no;
	cout<<"\n\n";
	if( (read=fopen("ogrenci.txt","r"))==NULL )
	{
		cout<<" Dosya okuma ba\x9f""arýsýz.";
		exit(1);
	}
	
	int bulundu=0;// aranan öðrenci bulunup bulunmadýðý kontrol için.Bulunursa 1 olur.
	while(!feof(read)) //ogrenci.txt içerisinde satýr satýr öðrencinin adý aranýyor.
	{
		fscanf(read,"%10d %20s %25s %3d", &no,adsoyad,bolum,&sinif); // txt deki satýrýn verileri kontrol için okunuyor.
		if(adsoyad==AdSoyad) // adsoyad kontrol ediliyor.
		{
			bulundu=1; // aranan öðrenci varsa
			if(!!feof(read)) // Son bulduðu kiþiyi iki defa yazmamasý için.
			{
				break;
			}
			printf("%10d %20s %25s %3d",no,adsoyad,bolum,sinif); // bulunduysa veriler yazdýrýlýyor.
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

void OgrenciBolumeGoreListeleme() // ogrenci.txt içerisindeki veri okunup ekrana bolumun adýna göre alfabetik olarak sýralanýyor.
{	
	system("cls");
	FILE *read;
	char adsoyad[20],bolum[25];
	char      alfabe[31]={'a','b','c','ç','d','e','f','g','ð','h','ý','i','j','k','l','m','n','o','ö','p','r','s','þ','t','u','ü','v','w','x','y','z'};
	char buyukalfabe[31]={'A','B','C','Ç','D','E','F','G','Ð','H','I','Ý','J','K','L','M','N','O','Ö','P','R','S','Þ','T','U','Ü','V','W','X','Y','Z'};
	int sinif,no;
	
	if( (read=fopen("ogrenci.txt","r"))==NULL )
	{
		cout<<" Dosya okuma ba\x9f""arýsýz.";
		exit(1);
	}
	cout<<"\n\n\t\tBölüme Göre Alfabetik Sýralama Yapýldý\n";
	for(int l=0;l<25;++l)
	{
		cout<<"====";
	}
	cout<<endl;
	
	
	
		read=fopen("ogrenci.txt","r");
		int p=0;
		while(!feof(read))// bütün doküman incelenip harf sýrasý gelen listeleniyor.
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
	
void OgrenciSinifaGoreListeleme() // ogrenci.txt içerisindeki veriler ekrana, öðrencinin sýnýfýna göre numerik sýrayla basýlýr.
{
	system("cls");
	
	FILE *read;
	char adsoyad[20],bolum[25];
	int sinif;
	int no;
	
	if( (read=fopen("ogrenci.txt","r"))==NULL )
	{
		cout<<" Dosya okuma ba\x9f""arýsýz.";
		exit(1);
	}
	cout<<"Sýnýfa Göre Numerik Sýralama Yapýlýyor\n";
	int siralamadegeri=1;
	for(int l=0;l<25;++l)
	{
		cout<<"====";
	}
	cout<<endl;
	while(siralamadegeri<10) // 10 yýldan fazla ünversitede kalan öðrenci yoktur.   ;-)
	{
		read=fopen("ogrenci.txt","r");
		while(!feof(read))
		{
			fscanf(read,"%10d %20s %25s %3d", &no,adsoyad,bolum,&sinif);
			if(!!feof(read)) // Son bulduðu kiþiyi iki defa yazmamasý için.
			{
				break;
			}
			
			if(int(sinif)==siralamadegeri) // BURADA ASCII DEÐERÝ YARDIMIYLA BÖLÜMÜN ÝLK HARFÝYLE SIRALAMA YAPILDI.
			{
				printf("%10d %20s %25s %3d",no,adsoyad,bolum,sinif);
				cout<<endl;
			}
		
		}
		fclose(read);
		siralamadegeri++; // BÝR SONRAKÝ SAYIYA GÖRE SIRALAMA YAPMASI ÝÇÝN.
	}
	fclose(read);
	for(int l=0;l<25;++l)
	{
		cout<<"====";
	}
		
}

void OgrenciBilgiDuzenle() // öðrencinin varlýðýnýn kontrol edilip öðrenci varsa bilgilerinin düzenleyen fonk.
{
	system("cls");
	char adsoyad[20],bolum[25];
	int secim=0,DuzenlenecekOgrNo,bulundu=0,sinif,no; // txt deki verileri okumak için.
	
	cout<<"Bilgileri düzenlenecek öðrencinin numarasýný girin : ";
	cin>>DuzenlenecekOgrNo;
	
	
	FILE *update; // write pointere tanýmlandý.
	
	
	update=fopen("ogrenci.txt","r+"); // r+ dosyaya önceki kayýtlarý silmeden kayýt eklemek ve okumak için.
	
	if( update==NULL ) //
	{
		cerr<<"ogrenci.txt acilamadi"; // dosya oluþturulamadýysa.
		exit(1);
	}
	
	
	while(!feof(update)) // girilen öðrenci nosuna kayýtlý öðrenci varsa düzenleme yapýlabilir. 
	{
		fscanf(update,"%10d %20s %25s %3d",&no,adsoyad,bolum,&sinif); // veriler txt den okunuyor.
		
		if(no==DuzenlenecekOgrNo) // txt deki no girilen öðrenci numarasýyla aynýysa öðrenciyi düzenle.
		{
			cout<<"\x99\xA7renci ad soyad düzenlemek için 1 e basin\n";
			cout<<"\x99\xA7renci bölüm düzenlemek için    2 e basin\n";
			cout<<"\x99\xA7renci sýnýf düzenlemek için    3 e basin\n";
			//Ogrenci no duzenlenemez.
			cin>>secim;
			system("cls");
			cout<<"Ogrenci Bilgisinin Eski Hali:\n";
			printf("%10d %20s %25s %3d",no,adsoyad,bolum,sinif);cout<<"\n";
			if (secim==1)
			{
				cout<<"Ad Soyad (kelime aralarýna bo\x9fluk koymayýn) : ";
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
				cout<<"Hatalý tu\x9flama yaptiniz.";
			}
			
			cout<<"\x99\xA7renci Bilgisinin Yeni Hali:\n";
			printf("%10d %20s %25s %3d",no,adsoyad,bolum,sinif);cout<<"\n";
			fseek(update,sizeof(DuzenlenecekOgrNo),SEEK_CUR);
			fseek(update,-65,SEEK_CUR);// Bir Önceki satýrda deðiþikliðe gitmek için pointer txt içerisindeki konumu kaydýrýlýyor.
			fprintf(update, "%10d %20s %25s %3d\n",no,adsoyad,bolum,sinif); // ogrenci.txt ye veriler yazýlýyor.
			bulundu=1; // aranan öðrenci numarasý varsa
			
			cout<<"Duzenleme ba\x9f""arili"<<endl;
			break;
		}
		
	}
	fclose(update); // üstünü açýk býrakmamak lazým :D
	
	if(bulundu==0)// veri bulunamadýysa.
	{
		cout<<"Bu no lu ogrenci kayitta Yok."<<endl;
		Sleep(1500);
	}
	
}

#include <iostream>
#include <conio.h>  // getc() i�in.
#include "NotGiris.h"	// Prototiplerin tan�mlanmas�.
#include <fstream> // dosyalama i�lemleri i�in gerekli
using namespace std;

int secimekrani4() // NotGiris Alt Mod�llerini Se�mek i�in kullan�lan fonksiyon.
{
	char altsecim=0;
	system("cls");
	system("color F1");
	
	cout<<"\n\n\n";
	cout<<"\n\t\t\t\t      ";for(int i=0;i<47;++i){cout<<"\xb0";};cout<<endl;
	cout<<"\t\t\t\t      \xb0           Not Giri\x9f Alt  Mod\x81lleri          \xb0";
	cout<<"\n\t\t\t\t      ";for(int i=0;i<47;++i){cout<<"\xb0";};cout<<endl;
	cout<<endl;
	cout<<"\t\t\t\t       ";for(int i=0;i<45;++i){cout<<"\xdb";};cout<<endl;
	cout<<"\t\t\t\t       \xdb                                           \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb                                           \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    KOD   ALT MOD\x9AL ADI                    \xdb"<<endl;// Kullan�c� buradaki alt mod�l kodlar�ndan birini se�er.
	cout<<"\t\t\t\t       \xdb                                           \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    1....\x99\xA7renciye ders ekleme             \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    2....\x99\xA7rencinin ald\x8d\xA7\x8d derse not giri\x9f \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    3....\x99\xA7renci ders listeleme            \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    4....\x99\xA7renci karnesi olu\x9fturma         \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb                                           \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb                                           \xdb"<<endl;
	cout<<"\t\t\t\t       ";for(int i=0;i<45;++i){cout<<"\xdb";};cout<<endl;
	cout<<"\t\t\t\t\t   Ana men\x81ye gitmek i\x87in 8 kodunu girin. "<<endl;
	cout<<"\t\t\t\t\t     Mod\x81l se\x87iminizin kodunu girin: ";
	
	altsecim=getch();
	return altsecim;
}

void OgrenciDersEkleme() // ��renciye ders ekleme i�lemini yapan fonksiyon.
{
	system("cls");
	int ogrno,  derskod,  dnot=101,  dno,  bulundu=0,  sinif,  no; // ��renci dnotu 101 ise notu daha girilmemi�tir. Not kontrol� i�in.
	char dersad[20];
	char adsoyad[20],bolum[25];// bu ve �stteki de�i�kenler txt de�erlerini kontrol i�in.
	
	
	cout<<"\n(10 haneli orn:2015141003)\nDers eklemek istediginiz ��renci numaras�n� girin : ";
	cin>>ogrno;
	cout<<"Eklenecek ders numaras�n� Girin : ";
	cin>>derskod;


	FILE *ogrkontrol; // ogrkontrol pointere tan�mland�.
	ogrkontrol=fopen("ogrenci.txt","r");// r sadece okuma yapmak i�in
	if( ogrkontrol==NULL )
	{
		cerr<<"ogrenci.txt acilamadi"; // dosya olu�turulamad�ysa.
		exit(1);
	}




	FILE *write; // veri yazmak i�in pointer
	write=fopen("notgiris.txt","a+"); // a+ dosyaya �nceki kay�tlar� silmeden kay�t eklemek i�in.
	if( write==NULL )
	{
		cerr<<"notgiris.txt acilamadi"; // dosya olu�turulamad�ysa.
		exit(1);
	}
	
	
	
	FILE *kontrol; // ders var m� kontrol� i�in tan�mland�.
	kontrol=fopen("ders.txt","r"); // r sadece okuma yapmak i�in
	if( kontrol==NULL ) 
	{
		cerr<<"ders.txt acilamadi"; // dosya olu�turulamad�ysa.
		exit(1);
	}
	
	


	while(!feof(kontrol)) // ders halihaz�rda ��renci taraf�ndan al�n�yorsa bulundu 1 olur
	{
		fscanf(kontrol,"%4d %20s",&dno,dersad);
		
		if(dno==derskod)
		{
			fclose(kontrol);
			bulundu=1;
			break;
		}
	}
	
	
	
	if(bulundu==1)
	{
		while(!feof(ogrkontrol)) // ��renci kayd� ogrenci.txt de varsa  bulundu 2 olur.
		{
			fscanf(ogrkontrol,"%10d %20s %25s %3d",&no,adsoyad,bolum,&sinif); // veriler kontrol i�in al�n�yor.
			if(no==ogrno)
			{
				bulundu++;
				break;// kontrol� devam ettirmeye gerek yok.��renci bulundu.
			}
		}
	
	}
	
	if(bulundu==2)
	{
		fprintf(write,"%10d %4d %3d\n",ogrno,derskod,dnot); // notgiris.txt ye veriler formatl� olarak yaz�l�yor.
		
	}
		fclose(write); // dosya buffer �i�memesi i�in kapat�l�yor
		fclose(ogrkontrol);// dosya buffer �i�memesi i�in kapat�l�yor
		fclose(kontrol);// dosya buffer �i�memesi i�in kapat�l�yor
	if(bulundu==2) // ekleme yap�ld�ysa 2 olur.
	{
		cout<<"Bilgiler kaydedildi."<<endl;
	}
	else// bulundu 2 den farkl�ysa ekeleme yap�lamaz.
	{
		cout<<"Bilgiler kaydedilemedi(��renci veya ders kay�tl� de�il.)"<<endl;
	}
}

void OgrenciDersNotGiris() // ��renciye ders notunun girildi�i fonksiyon
{
	system("cls");
	int ogrno,no,derskod,dnot=101,bulundu=0,dersk,dersnot; // ��renci dnotu 101 ise notu daha girilmemi�tir. Not kontrol� i�in.
	cout<<"\n(10 haneli orn:2015141003)\nNot girmek istedi�iniz ��renci numaras�n� girin : ";
	cin>>ogrno;
	cout<<"\nNot girilecek dersin kodunu girin : ";
	cin>>derskod;
	

	FILE *update;

	update=fopen("notgiris.txt","r+"); // r+ dosyaya �nceki kay�tlar� silmeden kay�t eklemek okumak i�in.
	
	if( update==NULL ) //
	{
		cerr<<"notgiris.txt acilamadi"; // dosya olu�turulamad�ysa.
		exit(1);
	}
			
	while(!feof(update)) // dersin notunun oldu�u sat�ra gidiliyor.
	{
		fscanf(update,"%10d %4d %3d",&no,&dersk,&dnot); // veriler okunuyor.
		
		if(ogrno==no and derskod==dersk)
		{
			cout<<"\nDersin notunu girin : ";
			cin>>dersnot; // ogrenci ve ald��� dersler do�ruland� ve ders notu isteniyor.
			
			//cout<<endl<<ftell(update)<<endl;   buras� kod geli�tirme a�amas�nda kullan�ld�.
			fseek(update,-19,SEEK_CUR); // txt de notun yaz�laca�� sat�r konumuna gidiliyor.
			fprintf(update, "%10d %4d %3d\n",no,dersk,dersnot); 
			//cout<<endl<<ftell(update)<<endl;	buras� kod geli�tirme a�amas�nda kullan�ld�.
		
			bulundu=2; // not giri�i ba�ar�l�ysa.
			break;
			
		}
	}
	fclose(update);// dosya buffer �i�memesi i�in kapat�l�yor
	
	
	if(bulundu==2)
	{
		cout<<"\nBilgiler kaydedildi."<<endl;
	}
	else
	{
		cout<<"\nBilgiler kaydedilemedi(��renci veya ders kay�tl� de�il.)"<<endl;
	}
}

void OgrenciDersListeleme() // ��renci numaras�na g�re 
{
	system("cls");
	int ogrno,derskod,dnot=101,bulundu=0,no,dersk; // ��renci dnotu 101 ise notu daha girilmemi�tir. Not kontrol� i�in.
	cout<<"\n(10 haneli orn:2015141003)\nListelemek istedi�iniz ��renci numaras�n� girin : ";
	cin>>ogrno;
	
	


	FILE *read;
	FILE *kontrol; // kontrol pointere tan�mland�.
	
	kontrol=fopen("notgiris.txt","r"); // a dosyaya �nceki kay�tlar� silmeden kay�t eklemek i�in.
	
	
	if( kontrol==NULL ) 
	{
		cerr<<"notgiris.txt acilamadi"; // dosya olu�turulamad�ysa.
		exit(1);
	}
	cout<<"=========================================================="<<endl;



	while(!feof(kontrol)) // ��encinin ald��� dersler  s�rayla listeleniyor.
	{
		fscanf(kontrol,"%10d %4d %3d",&no,&dersk,&dnot);
		
		if(ogrno==no)
		{
			read=fopen("notgiris.txt","a"); // a dosyaya �nceki kay�tlar� silmeden kay�t eklemek i�in.
	
			if(read==NULL)
			{
				cerr<<"notgiris.txt acilamadi"; // dosya olu�turulamad�ysa.
				exit(1);
			}
			if(!!feof(kontrol)) // Son buldu�unu iki defa yazmamas� i�in.
			{
				break; // whiledan ayr�l.
			}
			printf("Ogrenci No : %10d   Ald�g� Ders Kodu : %4d \n",no,dersk); //  veriler ekrana yaz�l�yor.
			bulundu=2;
			fclose(read);
		}
	}
	fclose(kontrol);
	
	if(bulundu==2)
	{
		cout<<"\nBilgiler listelendi."<<endl;
	}
	else
	{
		cout<<"\nBilgiler kaydedilemedi(��renci veya ders kay�tl� de�il.)"<<endl;
	}
	cout<<"=========================================================="<<endl;
}

void OgrenciKarneOlustur() // ��rencinin ald��� derslerin yan�ndaki notlarla beraber hepsi listeleniyor.
{
	system("cls");
	int ogrno,derskod,dnot=101,bulundu=0,no,dersk; // ��renci dnotu 101 ise notu daha girilmemi�tir. Not kontrol� i�in.
	cout<<"\n(10 haneli orn:2015141003)\nKarnesini istediginiz ��rencinin numaras�n� girin : ";
	cin>>ogrno;
	

	FILE *read;// kontrol pointere tan�mland�.
	FILE *kontrol; // kontrol pointere tan�mland�.
	
	kontrol=fopen("notgiris.txt","r");
	
	
	if( kontrol==NULL ) 
	{
		cerr<<"notgiris.txt acilamadi"; // dosya olu�turulamad�ysa.
		exit(1);
	}
	



	while(!feof(kontrol)) // ��encinin karne bilgileri s�rayla listeleniyor.
	{
		fscanf(kontrol,"%10d %4d %3d",&no,&dersk,&dnot); // txt den veriler okunoyoy.
		
		if(ogrno==no)
		{
			
			read=fopen("notgiris.txt","a"); // a dosyaya �nceki kay�tlar� silmeden kay�t eklemek i�in.
	
			if( read==NULL ) //
			{
				cerr<<"notgiris.txt acilamadi"; // dosya olu�turulamad�ysa.
				exit(1);
			}
			if(!!feof(kontrol)) // Son buldu�unu iki defa yazmamas� i�in.
			{
				break;
			}
			if(dnot==101) // DERS NOTU 101 �SE DERS�N NOTU G�R�LMEM��T�R.
			{
				cout<<"\n==========================================================================="<<endl;
				printf("��renci No : %10d   Ald��� Ders Kodu : %4d  Ders Notu : Not girilmemi�\n",no,dersk,dnot);
			}
			else// DERS NOTU 101 DE��LSE DERS�N NOTU G�R�LM��T�R.
			{
				cout<<"\n==========================================================================="<<endl;
				printf("��renci No : %10d   Ald��� Ders Kodu : %4d  Ders Notu : %3d\n",no,dersk,dnot); // notgiris.txt ye veriler yaz�l�yor.
				bulundu=2;
				fclose(read);
			}
			
		}
	}
	fclose(kontrol);
	cout<<"\n==========================================================================="<<endl;
	if(bulundu==2)
	{
		cout<<"\nKarne Bilgileri Listelendi."<<endl;
	}
	else
	{
		cout<<"\nBilgiler Listelenemedi(��renci veya ders kay�tl� de�il.)"<<endl;
	}
}

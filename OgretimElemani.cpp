#include <iostream>
#include "OgretimElemani.h"
#include <conio.h> // getc() i�in.
using namespace std;

int secimekrani2() // ��retim Eleman� Alt Mod�llerini Se�mek i�in kullan�lan fonksiyon.
{
	char altsecim=0;
	system("cls");
	system("color F1");
	
	cout<<"\n\n\n";
	cout<<"\n\t\t\t\t      ";for(int i=0;i<52;++i){cout<<"\xb0";};cout<<endl;
	cout<<"\t\t\t\t      \xb0          \x99\xA7retim Eleman\x8d Alt Mod\x81lleri           \xb0";
	cout<<"\n\t\t\t\t      ";for(int i=0;i<52;++i){cout<<"\xb0";};cout<<endl;
	cout<<endl;
	cout<<"\t\t\t\t       ";for(int i=0;i<50;++i){cout<<"\xdb";};cout<<endl;
	cout<<"\t\t\t\t       \xdb                                                \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb                                                \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    KOD   ALT MOD\x9AL ADI                         \xdb"<<endl;// Kullan�c� buradaki alt mod�l kodlar�ndan birini se�er.
	cout<<"\t\t\t\t       \xdb                                                \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    1....\x99\xA7retim eleman\x8d kay\x8dt                  \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    2....\x99\xA7retim eleman\x8d arama (sicil noyla)    \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    3....\x99\xA7retim eleman\x8d bilgileri d\x81zeltme     \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb    4....\x99\xA7retim eleman\x8d listeleme (b\x94l\x81m)      \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb                                                \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb                                                \xdb"<<endl;
	cout<<"\t\t\t\t       ";for(int i=0;i<50;++i){cout<<"\xdb";};cout<<endl;
	cout<<"\t\t\t\t\t      Ana men\x81ye gitmek i\x87in 8 kodunu girin. "<<endl;
	cout<<"\t\t\t\t\t        Mod\x81l se\x87iminizin kodunu girin: ";
	
	altsecim=getch();
	return altsecim;
}

void OgretimElemaniKayit() // ��r. Eleman� yeni kay�t yapan fonksiyon.
{
	system("cls");
	char adsoyad[20],bolum[25];
	cout<<"\n\n\n";
	cout<<"��retim eleman� Ad Soyad (kelime aralar�na bo�luk koymay�n) : ";
	cin>>adsoyad;
	cout<<"��retim eleman�n�n B�l�m�n� Girin (kelime aralar�na bo�luk koymay�n): ";
	cin>>bolum;
	int no;
	cout<<"��retim eleman� Sicil Numaras�n� Girin (9haneli): ";
	cin>>no;

	
	FILE *write; // write pointere tan�mland�.
	
	
	write=fopen("ogreleman.txt","a"); // a dosyaya �nceki kay�tlar� silmeden kay�t eklemek i�in.
	
	if( write==NULL ) //
	{
		cerr<<"ogreleman.txt a��lamadi"; // dosya olu�turulamad�ysa.
		exit(1);
	}
	
	
	fprintf(write, "\n%9d %20s %25s",no,adsoyad,bolum); // ogreleman.txt ye veriler yaz�l�yor.
	
	
	fclose(write);
	cout<<"Bilgiler Ba�ar�yla kaydedildi."<<endl;
}

void OgretimElemaniArama() // ��r. Eleman� sicil numaras�na g�re arama yapan fonk.
{
	system("cls");
	FILE *read;
	char adsoyad[20],bolum[25];
	int no,sicilara;
	cout<<"\n\n==============================================================================\n";
	if( (read=fopen("ogreleman.txt","r"))==NULL )
	{
		cout<<" Dosya okuma ba�ar�s�z.";
		exit(1);
	}
	cout<<"Aranan ogretim eleman� sicil numarasini girin (9haneli): ";
	cin>>sicilara;
	
	int bulundu=0;// aranan sicil nolu ��r.eleman� bulunup bulunmad��� kontrol i�in. Bulunursa 1 olur.
	while(!feof(read)) // txt i�erisinde sat�r sat�r sicil numaras� kontrol eidlecek.
	{
		fscanf(read,"%9d %20s %25s", &no,adsoyad,bolum); // txt deki veriler kontrol i�in al�n�yor.
		if(no==sicilara)
		{
			bulundu=1; // aranan sicil no varsa
			printf("%9d %20s %25s",no,adsoyad,bolum); // sicil nolu ��r elem. kay�tl�ysa.
			break;
		}
		
		
	}
	fclose(read);
	
	if(bulundu==0)
	{
		cout<<"Aranan ��retim eleman� Yok."<<endl;
	}
	cout<<"\n\n==============================================================================\n";
}

void OgrElBilgiDuzenle() // ��r. Eleman� bilgilerini d�zenleyen program.
{
	system("cls");
	char adsoyad[20],bolum[25];
	int secim=0,ogrelemansicilno,bulundu=0,no;
	
	cout<<"Bilgileri d�zenlenecek ��retim eleman� sicil numaras�n� girin (9haneli): ";
	cin>>ogrelemansicilno;
	
	
	FILE *update; // write pointere tan�mland�.
	
	
	update=fopen("ogreleman.txt","r+"); // r+ dosyaya �nceki kay�tlar� silmeden kay�t eklemek ve okumak i�in.
	
	if( update==NULL ) //
	{
		cerr<<"ogreleman.txt acilamadi"; // dosya olu�turulamad�ysa.
		exit(1);
	}
	
	
	while(!feof(update))
	{
		fscanf(update,"%10d %20s %25s",&no,adsoyad,bolum); // txt den veriler okunuyor.
		
		if(no==ogrelemansicilno) // sicil noya sahip biri varsa d�zenleme  yap�labilir.
		{
			cout<<"\n��retim eleman� ad soyad d�zenlemek i�in 1 e bas�n\n";
			cout<<"��retim eleman� b�l�m d�zenlemek i�in    2 e bas�n\n";
			cout<<"��retim eleman� sicil no d�zenlemek i�in 3 e bas�n\n";
			cin>>secim;
			system("cls");
			cout<<"\n��retim eleman� bilgisinin Eski Hali:\n\n";
			printf("%9d %20s %25s",no,adsoyad,bolum);cout<<"\n";
			if (secim==1)
			{
				cout<<"Ad Soyad (kelime aralar�na bo�luk koymay�n) : ";
				cin>>adsoyad;
			}
			else if(secim==2)
			{
				cout<<"��retim eleman� b�l�m�n� girin (kelime aralar�na bo�luk koymay�n): ";
				cin>>bolum;
			}
			else if(secim==3)
			{
				cout<<"\n��retim eleman� yeni sicil nosunu girin (10haneli): ";
				cin>>no;
			}
			else
			{
				cout<<"Hatal� tu�lama yapt�n�z.";
			}
			// Pointeren bulundu�u yer yard�m�yla veride duzenleme yapabiliriz.
			cout<<"=============================================================================="<<endl;
			cout<<"��retim eleman� bilgisinin Yeni Hali:\n\n";
			printf("%9d %20s %25s",no,adsoyad,bolum);cout<<"\n"; // yeni hal formatl� olarak yazd�r�l�yor.
			cout<<endl;
			if(ftell(update)<=57)// buras� txt deki ilk kay�tta d�zenleme yap�ld���nda sorun olu�mamas� i�in yaz�ld�.
			{
					
					fseek(update,0,SEEK_SET);
					fprintf(update, "%9d %20s %25s\n",no,adsoyad,bolum); // ogrenci.txt ye veriler yaz�l�yor.
					bulundu=1; // aranan ��renci numaras� varsa
					
					break;
			}
			else// txt deki ikinci ve di�er sat�rdaki verilerde g�ncelleme yapmak i�in.
			{
			fseek(update,sizeof(ogrelemansicilno),SEEK_CUR);
			fseek(update,-63,SEEK_CUR);// program bir sonraki eleman bilgisini de�i�tiriyor fakat biz bir �ncekini -65 yazarak de�i�tirebiliyoruz.
			
			fprintf(update, "\n%9d %20s %25s\n",no,adsoyad,bolum); // ogrenci.txt ye veriler yaz�l�yor.
			
			bulundu=1; // aranan ��renci numaras� varsa
			cout<<"D�zenleme ba�ar�l�"<<endl;
			break;
			}
			
			
			
		}
		
		
	}
	fclose(update);
	
	if(bulundu==0)
	{
		cout<<"Bu no lu ��retim eleman� kay�tta Yok."<<endl;
	}
}

void OgretimElemaniListeleme() // ��retim eleman� b�l�m ad�na g�re alfabetik s�ralama.
{
	system("cls");
	FILE *read;
	char adsoyad[20],bolum[25];
	int no;
	
	if( (read=fopen("ogreleman.txt","r"))==NULL )
	{
		cout<<" Dosya okuma basarisiz.";
		exit(1);
	}
	cout<<"B�l�me G�re S�ralama Yapl�yor\n";
	int ASCII=65;// A harfinin Ascii kar��l��� 65 tir 97 ise k���k a harfinin asci kar��l���.
	cout<<"B�l�me g�re alfabetik siralama = \n\n";
	
	
	while(ASCII+32<=123) // K���k a ile B�y�k A n�n ascii de�erlerinden z ve Z ye kadarki harflere g�re s�ralama yap�l�yor.
	{
		read=fopen("ogreleman.txt","r");
		while(!feof(read))
		{
			fscanf(read,"%9d %20s %25s", &no,adsoyad,bolum);
			
			if(int(bolum[0])==ASCII or int(bolum[0])==ASCII+32) // BURADA ASCII DE�ER�YLE, �LK HARF BAZ ALINIP SIRALAMA YAPILDI.
			{
				if(!!feof(read)) // ik defa s�ralama ekrana bas�lmas�n diye.
				{
					break;
				}
				for(int i=0;i<34;++i){cout<<"==";}
				cout<<endl;
				printf("%9d %20s %25s",no,adsoyad,bolum); // s�ralananlar ekrana bas�l�yor.
				cout<<endl;
				for(int i=0;i<34;++i){cout<<"==";}
				cout<<endl;
				
			}
		
		}
		fclose(read);
		ASCII++; // B�R SONRAK� HARFE G�RE SIRALAMA YAPMASI ���N. �NCE A LARI SONRA B LER� EN SON Z LEYLE BA�LAYAN B�L�MLER� YAZDIRACAK.
	}
	fclose(read);
	
}

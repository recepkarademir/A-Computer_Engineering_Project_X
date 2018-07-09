#include <iostream>
#include "OgretimElemani.h"
#include <conio.h> // getc() için.
using namespace std;

int secimekrani2() // Öðretim Elemaný Alt Modüllerini Seçmek için kullanýlan fonksiyon.
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
	cout<<"\t\t\t\t       \xdb    KOD   ALT MOD\x9AL ADI                         \xdb"<<endl;// Kullanýcý buradaki alt modül kodlarýndan birini seçer.
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

void OgretimElemaniKayit() // Öðr. Elemaný yeni kayýt yapan fonksiyon.
{
	system("cls");
	char adsoyad[20],bolum[25];
	cout<<"\n\n\n";
	cout<<"Öðretim elemaný Ad Soyad (kelime aralarýna boþluk koymayýn) : ";
	cin>>adsoyad;
	cout<<"Öðretim elemanýnýn Bölümünü Girin (kelime aralarýna boþluk koymayýn): ";
	cin>>bolum;
	int no;
	cout<<"Öðretim elemaný Sicil Numarasýný Girin (9haneli): ";
	cin>>no;

	
	FILE *write; // write pointere tanýmlandý.
	
	
	write=fopen("ogreleman.txt","a"); // a dosyaya önceki kayýtlarý silmeden kayýt eklemek için.
	
	if( write==NULL ) //
	{
		cerr<<"ogreleman.txt açýlamadi"; // dosya oluþturulamadýysa.
		exit(1);
	}
	
	
	fprintf(write, "\n%9d %20s %25s",no,adsoyad,bolum); // ogreleman.txt ye veriler yazýlýyor.
	
	
	fclose(write);
	cout<<"Bilgiler Baþarýyla kaydedildi."<<endl;
}

void OgretimElemaniArama() // Öðr. Elemaný sicil numarasýna göre arama yapan fonk.
{
	system("cls");
	FILE *read;
	char adsoyad[20],bolum[25];
	int no,sicilara;
	cout<<"\n\n==============================================================================\n";
	if( (read=fopen("ogreleman.txt","r"))==NULL )
	{
		cout<<" Dosya okuma baþarýsýz.";
		exit(1);
	}
	cout<<"Aranan ogretim elemaný sicil numarasini girin (9haneli): ";
	cin>>sicilara;
	
	int bulundu=0;// aranan sicil nolu öðr.elemaný bulunup bulunmadýðý kontrol için. Bulunursa 1 olur.
	while(!feof(read)) // txt içerisinde satýr satýr sicil numarasý kontrol eidlecek.
	{
		fscanf(read,"%9d %20s %25s", &no,adsoyad,bolum); // txt deki veriler kontrol için alýnýyor.
		if(no==sicilara)
		{
			bulundu=1; // aranan sicil no varsa
			printf("%9d %20s %25s",no,adsoyad,bolum); // sicil nolu öðr elem. kayýtlýysa.
			break;
		}
		
		
	}
	fclose(read);
	
	if(bulundu==0)
	{
		cout<<"Aranan Öðretim elemaný Yok."<<endl;
	}
	cout<<"\n\n==============================================================================\n";
}

void OgrElBilgiDuzenle() // Öðr. Elemaný bilgilerini düzenleyen program.
{
	system("cls");
	char adsoyad[20],bolum[25];
	int secim=0,ogrelemansicilno,bulundu=0,no;
	
	cout<<"Bilgileri düzenlenecek Öðretim elemaný sicil numarasýný girin (9haneli): ";
	cin>>ogrelemansicilno;
	
	
	FILE *update; // write pointere tanýmlandý.
	
	
	update=fopen("ogreleman.txt","r+"); // r+ dosyaya önceki kayýtlarý silmeden kayýt eklemek ve okumak için.
	
	if( update==NULL ) //
	{
		cerr<<"ogreleman.txt acilamadi"; // dosya oluþturulamadýysa.
		exit(1);
	}
	
	
	while(!feof(update))
	{
		fscanf(update,"%10d %20s %25s",&no,adsoyad,bolum); // txt den veriler okunuyor.
		
		if(no==ogrelemansicilno) // sicil noya sahip biri varsa düzenleme  yapýlabilir.
		{
			cout<<"\nÖðretim elemaný ad soyad düzenlemek için 1 e basýn\n";
			cout<<"Öðretim elemaný bölüm düzenlemek için    2 e basýn\n";
			cout<<"Öðretim elemaný sicil no düzenlemek için 3 e basýn\n";
			cin>>secim;
			system("cls");
			cout<<"\nÖðretim elemaný bilgisinin Eski Hali:\n\n";
			printf("%9d %20s %25s",no,adsoyad,bolum);cout<<"\n";
			if (secim==1)
			{
				cout<<"Ad Soyad (kelime aralarýna boþluk koymayýn) : ";
				cin>>adsoyad;
			}
			else if(secim==2)
			{
				cout<<"Öðretim elemaný bölümünü girin (kelime aralarýna boþluk koymayýn): ";
				cin>>bolum;
			}
			else if(secim==3)
			{
				cout<<"\nÖðretim elemaný yeni sicil nosunu girin (10haneli): ";
				cin>>no;
			}
			else
			{
				cout<<"Hatalý tuþlama yaptýnýz.";
			}
			// Pointeren bulunduðu yer yardýmýyla veride duzenleme yapabiliriz.
			cout<<"=============================================================================="<<endl;
			cout<<"Öðretim elemaný bilgisinin Yeni Hali:\n\n";
			printf("%9d %20s %25s",no,adsoyad,bolum);cout<<"\n"; // yeni hal formatlý olarak yazdýrýlýyor.
			cout<<endl;
			if(ftell(update)<=57)// burasý txt deki ilk kayýtta düzenleme yapýldýðýnda sorun oluþmamasý için yazýldý.
			{
					
					fseek(update,0,SEEK_SET);
					fprintf(update, "%9d %20s %25s\n",no,adsoyad,bolum); // ogrenci.txt ye veriler yazýlýyor.
					bulundu=1; // aranan öðrenci numarasý varsa
					
					break;
			}
			else// txt deki ikinci ve diðer satýrdaki verilerde güncelleme yapmak için.
			{
			fseek(update,sizeof(ogrelemansicilno),SEEK_CUR);
			fseek(update,-63,SEEK_CUR);// program bir sonraki eleman bilgisini deðiþtiriyor fakat biz bir öncekini -65 yazarak deðiþtirebiliyoruz.
			
			fprintf(update, "\n%9d %20s %25s\n",no,adsoyad,bolum); // ogrenci.txt ye veriler yazýlýyor.
			
			bulundu=1; // aranan öðrenci numarasý varsa
			cout<<"Düzenleme baþarýlý"<<endl;
			break;
			}
			
			
			
		}
		
		
	}
	fclose(update);
	
	if(bulundu==0)
	{
		cout<<"Bu no lu öðretim elemaný kayýtta Yok."<<endl;
	}
}

void OgretimElemaniListeleme() // Öðretim elemaný bölüm adýna göre alfabetik sýralama.
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
	cout<<"Bölüme Göre Sýralama Yaplýyor\n";
	int ASCII=65;// A harfinin Ascii karþýlýðý 65 tir 97 ise küçük a harfinin asci karþýlýðý.
	cout<<"Bölüme göre alfabetik siralama = \n\n";
	
	
	while(ASCII+32<=123) // Küçük a ile Büyük A nýn ascii deðerlerinden z ve Z ye kadarki harflere göre sýralama yapýlýyor.
	{
		read=fopen("ogreleman.txt","r");
		while(!feof(read))
		{
			fscanf(read,"%9d %20s %25s", &no,adsoyad,bolum);
			
			if(int(bolum[0])==ASCII or int(bolum[0])==ASCII+32) // BURADA ASCII DEÐERÝYLE, ÝLK HARF BAZ ALINIP SIRALAMA YAPILDI.
			{
				if(!!feof(read)) // ik defa sýralama ekrana basýlmasýn diye.
				{
					break;
				}
				for(int i=0;i<34;++i){cout<<"==";}
				cout<<endl;
				printf("%9d %20s %25s",no,adsoyad,bolum); // sýralananlar ekrana basýlýyor.
				cout<<endl;
				for(int i=0;i<34;++i){cout<<"==";}
				cout<<endl;
				
			}
		
		}
		fclose(read);
		ASCII++; // BÝR SONRAKÝ HARFE GÖRE SIRALAMA YAPMASI ÝÇÝN. ÖNCE A LARI SONRA B LERÝ EN SON Z LEYLE BAÞLAYAN BÖLÜMLERÝ YAZDIRACAK.
	}
	fclose(read);
	
}

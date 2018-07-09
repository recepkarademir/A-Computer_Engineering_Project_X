#include <iostream>
#include <conio.h>  // getc() için.
#include "NotGiris.h"	// Prototiplerin tanýmlanmasý.
#include <fstream> // dosyalama iþlemleri için gerekli
using namespace std;

int secimekrani4() // NotGiris Alt Modüllerini Seçmek için kullanýlan fonksiyon.
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
	cout<<"\t\t\t\t       \xdb    KOD   ALT MOD\x9AL ADI                    \xdb"<<endl;// Kullanýcý buradaki alt modül kodlarýndan birini seçer.
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

void OgrenciDersEkleme() // Öðrenciye ders ekleme iþlemini yapan fonksiyon.
{
	system("cls");
	int ogrno,  derskod,  dnot=101,  dno,  bulundu=0,  sinif,  no; // öðrenci dnotu 101 ise notu daha girilmemiþtir. Not kontrolü için.
	char dersad[20];
	char adsoyad[20],bolum[25];// bu ve üstteki deðiþkenler txt deðerlerini kontrol için.
	
	
	cout<<"\n(10 haneli orn:2015141003)\nDers eklemek istediginiz öðrenci numarasýný girin : ";
	cin>>ogrno;
	cout<<"Eklenecek ders numarasýný Girin : ";
	cin>>derskod;


	FILE *ogrkontrol; // ogrkontrol pointere tanýmlandý.
	ogrkontrol=fopen("ogrenci.txt","r");// r sadece okuma yapmak için
	if( ogrkontrol==NULL )
	{
		cerr<<"ogrenci.txt acilamadi"; // dosya oluþturulamadýysa.
		exit(1);
	}




	FILE *write; // veri yazmak için pointer
	write=fopen("notgiris.txt","a+"); // a+ dosyaya önceki kayýtlarý silmeden kayýt eklemek için.
	if( write==NULL )
	{
		cerr<<"notgiris.txt acilamadi"; // dosya oluþturulamadýysa.
		exit(1);
	}
	
	
	
	FILE *kontrol; // ders var mý kontrolü için tanýmlandý.
	kontrol=fopen("ders.txt","r"); // r sadece okuma yapmak için
	if( kontrol==NULL ) 
	{
		cerr<<"ders.txt acilamadi"; // dosya oluþturulamadýysa.
		exit(1);
	}
	
	


	while(!feof(kontrol)) // ders halihazýrda öðrenci tarafýndan alýnýyorsa bulundu 1 olur
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
		while(!feof(ogrkontrol)) // Öðrenci kaydý ogrenci.txt de varsa  bulundu 2 olur.
		{
			fscanf(ogrkontrol,"%10d %20s %25s %3d",&no,adsoyad,bolum,&sinif); // veriler kontrol için alýnýyor.
			if(no==ogrno)
			{
				bulundu++;
				break;// kontrolü devam ettirmeye gerek yok.öðrenci bulundu.
			}
		}
	
	}
	
	if(bulundu==2)
	{
		fprintf(write,"%10d %4d %3d\n",ogrno,derskod,dnot); // notgiris.txt ye veriler formatlý olarak yazýlýyor.
		
	}
		fclose(write); // dosya buffer þiþmemesi için kapatýlýyor
		fclose(ogrkontrol);// dosya buffer þiþmemesi için kapatýlýyor
		fclose(kontrol);// dosya buffer þiþmemesi için kapatýlýyor
	if(bulundu==2) // ekleme yapýldýysa 2 olur.
	{
		cout<<"Bilgiler kaydedildi."<<endl;
	}
	else// bulundu 2 den farklýysa ekeleme yapýlamaz.
	{
		cout<<"Bilgiler kaydedilemedi(Öðrenci veya ders kayýtlý deðil.)"<<endl;
	}
}

void OgrenciDersNotGiris() // Öðrenciye ders notunun girildiði fonksiyon
{
	system("cls");
	int ogrno,no,derskod,dnot=101,bulundu=0,dersk,dersnot; // öðrenci dnotu 101 ise notu daha girilmemiþtir. Not kontrolü için.
	cout<<"\n(10 haneli orn:2015141003)\nNot girmek istediðiniz öðrenci numarasýný girin : ";
	cin>>ogrno;
	cout<<"\nNot girilecek dersin kodunu girin : ";
	cin>>derskod;
	

	FILE *update;

	update=fopen("notgiris.txt","r+"); // r+ dosyaya önceki kayýtlarý silmeden kayýt eklemek okumak için.
	
	if( update==NULL ) //
	{
		cerr<<"notgiris.txt acilamadi"; // dosya oluþturulamadýysa.
		exit(1);
	}
			
	while(!feof(update)) // dersin notunun olduðu satýra gidiliyor.
	{
		fscanf(update,"%10d %4d %3d",&no,&dersk,&dnot); // veriler okunuyor.
		
		if(ogrno==no and derskod==dersk)
		{
			cout<<"\nDersin notunu girin : ";
			cin>>dersnot; // ogrenci ve aldýðý dersler doðrulandý ve ders notu isteniyor.
			
			//cout<<endl<<ftell(update)<<endl;   burasý kod geliþtirme aþamasýnda kullanýldý.
			fseek(update,-19,SEEK_CUR); // txt de notun yazýlacaðý satýr konumuna gidiliyor.
			fprintf(update, "%10d %4d %3d\n",no,dersk,dersnot); 
			//cout<<endl<<ftell(update)<<endl;	burasý kod geliþtirme aþamasýnda kullanýldý.
		
			bulundu=2; // not giriþi baþarýlýysa.
			break;
			
		}
	}
	fclose(update);// dosya buffer þiþmemesi için kapatýlýyor
	
	
	if(bulundu==2)
	{
		cout<<"\nBilgiler kaydedildi."<<endl;
	}
	else
	{
		cout<<"\nBilgiler kaydedilemedi(Öðrenci veya ders kayýtlý deðil.)"<<endl;
	}
}

void OgrenciDersListeleme() // Öðrenci numarasýna göre 
{
	system("cls");
	int ogrno,derskod,dnot=101,bulundu=0,no,dersk; // öðrenci dnotu 101 ise notu daha girilmemiþtir. Not kontrolü için.
	cout<<"\n(10 haneli orn:2015141003)\nListelemek istediðiniz öðrenci numarasýný girin : ";
	cin>>ogrno;
	
	


	FILE *read;
	FILE *kontrol; // kontrol pointere tanýmlandý.
	
	kontrol=fopen("notgiris.txt","r"); // a dosyaya önceki kayýtlarý silmeden kayýt eklemek için.
	
	
	if( kontrol==NULL ) 
	{
		cerr<<"notgiris.txt acilamadi"; // dosya oluþturulamadýysa.
		exit(1);
	}
	cout<<"=========================================================="<<endl;



	while(!feof(kontrol)) // öðencinin aldýðý dersler  sýrayla listeleniyor.
	{
		fscanf(kontrol,"%10d %4d %3d",&no,&dersk,&dnot);
		
		if(ogrno==no)
		{
			read=fopen("notgiris.txt","a"); // a dosyaya önceki kayýtlarý silmeden kayýt eklemek için.
	
			if(read==NULL)
			{
				cerr<<"notgiris.txt acilamadi"; // dosya oluþturulamadýysa.
				exit(1);
			}
			if(!!feof(kontrol)) // Son bulduðunu iki defa yazmamasý için.
			{
				break; // whiledan ayrýl.
			}
			printf("Ogrenci No : %10d   Aldýgý Ders Kodu : %4d \n",no,dersk); //  veriler ekrana yazýlýyor.
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
		cout<<"\nBilgiler kaydedilemedi(Öðrenci veya ders kayýtlý deðil.)"<<endl;
	}
	cout<<"=========================================================="<<endl;
}

void OgrenciKarneOlustur() // Öðrencinin aldýðý derslerin yanýndaki notlarla beraber hepsi listeleniyor.
{
	system("cls");
	int ogrno,derskod,dnot=101,bulundu=0,no,dersk; // öðrenci dnotu 101 ise notu daha girilmemiþtir. Not kontrolü için.
	cout<<"\n(10 haneli orn:2015141003)\nKarnesini istediginiz öðrencinin numarasýný girin : ";
	cin>>ogrno;
	

	FILE *read;// kontrol pointere tanýmlandý.
	FILE *kontrol; // kontrol pointere tanýmlandý.
	
	kontrol=fopen("notgiris.txt","r");
	
	
	if( kontrol==NULL ) 
	{
		cerr<<"notgiris.txt acilamadi"; // dosya oluþturulamadýysa.
		exit(1);
	}
	



	while(!feof(kontrol)) // öðencinin karne bilgileri sýrayla listeleniyor.
	{
		fscanf(kontrol,"%10d %4d %3d",&no,&dersk,&dnot); // txt den veriler okunoyoy.
		
		if(ogrno==no)
		{
			
			read=fopen("notgiris.txt","a"); // a dosyaya önceki kayýtlarý silmeden kayýt eklemek için.
	
			if( read==NULL ) //
			{
				cerr<<"notgiris.txt acilamadi"; // dosya oluþturulamadýysa.
				exit(1);
			}
			if(!!feof(kontrol)) // Son bulduðunu iki defa yazmamasý için.
			{
				break;
			}
			if(dnot==101) // DERS NOTU 101 ÝSE DERSÝN NOTU GÝRÝLMEMÝÞTÝR.
			{
				cout<<"\n==========================================================================="<<endl;
				printf("Öðrenci No : %10d   Aldýðý Ders Kodu : %4d  Ders Notu : Not girilmemiþ\n",no,dersk,dnot);
			}
			else// DERS NOTU 101 DEÐÝLSE DERSÝN NOTU GÝRÝLMÝÞTÝR.
			{
				cout<<"\n==========================================================================="<<endl;
				printf("Öðrenci No : %10d   Aldýðý Ders Kodu : %4d  Ders Notu : %3d\n",no,dersk,dnot); // notgiris.txt ye veriler yazýlýyor.
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
		cout<<"\nBilgiler Listelenemedi(Öðrenci veya ders kayýtlý deðil.)"<<endl;
	}
}

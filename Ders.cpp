#include <iostream>   // cin cout cerr k�t�phanesi
#include "Ders.h"	// Prototiplerin tan�mland��� header �a�r�l�yor.
#include <fstream> // dosyalama i�lemleri i�in gerekli
#include <conio.h>  // getc() i�in.
using namespace std;

int secimekrani3() // Ders Alt Mod�llerini Se�mek i�in kullan�lan bir fonksiyon.
{
	char altsecim=0; //  alt mod�llerin �zelliklerini se�mek i�in kullan�lacak karar de�i�keni.
	system("cls"); // konsolu temizle.
	system("color F1"); // arkaplan,yaz� rengi ayar�
	
	
	
	cout<<"\n\n\n";
	cout<<"\n\t\t\t\t      ";for(int i=0;i<42;++i){cout<<"\xb0";};cout<<endl;
	cout<<"\t\t\t\t      \xb0           Ders Alt Mod\x81lleri           \xb0";
	cout<<"\n\t\t\t\t      ";for(int i=0;i<42;++i){cout<<"\xb0";};cout<<endl;
	cout<<endl;
	cout<<"\t\t\t\t       ";for(int i=0;i<40;++i){cout<<"\xdb";};cout<<endl;
	cout<<"\t\t\t\t       \xdb                                      \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb   KOD   ALT MOD\x9AL ADI                \xdb"<<endl; // Kullan�c� buradaki alt mod�l kodlar�ndan birini se�er.
	cout<<"\t\t\t\t       \xdb                                      \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb   1....Ders ekleme                   \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb   2....Ders bilgileri g\x81ncelleme     \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb   3....Ders listeleme                \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb   4....Ders arama (ders ad\x8Dna g\x94re)  \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb                                      \xdb"<<endl;
	cout<<"\t\t\t\t       ";for(int i=0;i<40;++i){cout<<"\xdb";};cout<<endl;
	cout<<"\t\t\t\t      Ana men\x81ye gitmek i\x87in 8 kodunu girin. "<<endl;
	cout<<"\t\t\t\t        Mod\x81l se\x87iminizin kodunu girin: ";
	altsecim=getch();
	return altsecim; // alt mod�l i�lem se�imi geri d�nd�r�l�yor.
}

void DersEkleme() // Ders.txt ye yeni ders kayd� fonksiyonu. 
{
	system("cls");
	char dersad[20]; // eklenecek dersin ad de�i�keni.
	cout<<"Ders Ad�  (kelime aralar�na bo�luk koymay�n) : ";
	cin>>dersad;
	int no; // Dersin  kodu
	cout<<"Ders Numaras�n� Girin (4 haneli): ";
	cin>>no;
	
	FILE *write; // write pointere tan�mland�.
	
	
	write=fopen("ders.txt","a"); // a dosyaya �nceki kay�tlar� silmeden kay�t eklemek i�in.
	// pointere txt dok�man adresi y�kleniyor.
	if( write==NULL ) //
	{
		cerr<<"ders.txt acilamadi"; // dosya olu�turulamad�ysa.
		exit(1);
	}
	
	
	fprintf(write, "%4d %20s\n",no,dersad); // ders.txt ye veriler yaz�l�yor.
	
	
	fclose(write); // dosyaya yazmayla i�imiz bitti.
	
	cout<<"Bilgiler kaydedildi."<<endl;
}

void DersBilgileriGuncelleme() //kay�tl� dersin ad�n�n de�i�tirilebildi�i fonk.
{
	system("cls");
	int secim=0,DuzenlenecekDersNo,bulundu=0,no; // kay�tl� dersteki verileri okuyup bunlara at�yoruz
	char dersad[20];
	
	cout<<"Bilgileri d�zenlenecek dersin kodunu girin (4 haneli): ";
	cin>>DuzenlenecekDersNo;
	
	system("cls");
	FILE *update; // update pointere tan�mland�.
	
	
	update=fopen("ders.txt","r+"); // r+ hem okuma hem de dok�mana zara vermeden �zerine bilgi yazmak i�in.
	
	if( update==NULL ) // txt yoksa.
	{
		cerr<<"ders.txt acilamadi"; // dosya olu�turulamad�ysa.
		exit(1);
	}
	
	while(!feof(update)) // dosyan�n son sat�r�na gelindiyse.
	{	
		fscanf(update,"%4d %20s\n",&no,dersad); // ders.txt sat�rlar�ndaki bilgiler al�n�yor.
		
		if(no==DuzenlenecekDersNo) // al�nan bilgi de�i�tirilecek bilgiyle ayn�ysa ders vard�r ve de�i�tirilebilir.
		{
			cout<<"Ders ad�n� d�zenleyebilirsiniz.\n";
			
			cout<<"\nDers Bilgisinin Eski Hali:\n";
			printf("%4d %20s",no,dersad);cout<<"\n\n"; // ekrana dersin eski bilgileri yaz�l�yor.
			
			cout<<"Yeni ders ismi (kelime aralar�na bo�luk koymay�n) : ";
			cin>>dersad;
			
			cout<<"\n=================================================="<<endl;
			cout<<"\nDers Bilgisinin Yeni Hali:\n";
			printf("%4d %20s",no,dersad);cout<<"\n"; //olu�acak yeni durum ekrana yazd�r�l�yor.
			
			fseek(update,sizeof(DuzenlenecekDersNo),SEEK_CUR); // txt i�erisindeki veri yaz�lacak dosya i�aretcisi konumu belirleniyor.
			fseek(update,-29,SEEK_CUR); //Bir �nceki sat�r�n konumuna gitmek i�in.
			fprintf(update, "%4d %20s\n",no,dersad); // ders.txt ye veriler yaz�l�yor.
			
			bulundu=1; // aranan ders numaras� varsa
			cout<<"\n\nD�zenleme basar�l�..."<<endl;
			break;
		}
		
		
	}
	fclose(update); // dosyalama kapat�l�yor.
	
	if(bulundu==0) // 0 ise kontrol sonucu ders kayd� bulunamam��t�r.
	{
		cout<<"Bu kodda ders kayd� yok."<<endl;
	}
}

void DersListeleme() // Derslerin listelenece�i fonk.
{
	system("cls");
	FILE *read; // dosyalama a��l�yor.
	char dersad[20];
	int no;	
	
	if( (read=fopen("ders.txt","r"))==NULL )
	{
		cout<<" Dosya okuma ba�ar�s�z.";
		exit(1);
	}
	cout<<"\nDers Ad�na G�re Alfabetik listeleme yap�ld�\n";
	
	int ASCII=65; // A harfinin Ascii kar��l��� 65 tir 97 ise k���k a harfinin asci kar��l���.
	cout<<"\nKod              Ders Ad�    \n";
	for(int i=0;i<20;++i){cout<<"==";} // Panelin k��elerindeki dolgulu �izgilerin sembol�.
	cout<<endl;
	
	while(ASCII+32<123) // ders ad�n�n ilk harfinin ascii de�eri alfabetik olarak s�ralan�yor.
	{
		read=fopen("ders.txt","r");
		while(!feof(read)) // b�t�n dok�man incelenip harf s�ras� gelen listeleniyor.
		{
			fscanf(read,"%4d %20s",&no,dersad); // veriler txt den okunuyor.
			
			if(int(dersad[0])==ASCII or int(dersad[0])==ASCII+32) // BURADA ASCII DE�ER� YARDIMIYLA B�L�M�N �LK HARF�YLE SIRALAMA YAPILDI.
			{
				printf("%4d %20s",no,dersad);
				cout<<endl;
					break;
			}
		
		}
		// ASCII++ oldu�unda bir sonraki harfe g�re s�ralama yap�yor.
		ASCII++; // B�R SONRAK� HARFE G�RE SIRALAMA YAPMASI ���N. �NCE A LARI SONRA B LER� EN SON Z LEYLE BA�LAYAN B�L�MLER� YAZDIRACAK.
	}
	
	fclose(read);// dosya kapat�ld�.
	for(int i=0;i<20;++i){cout<<"==";} // Panelin k��elerindeki  �izgilerin sembol�.
	cout<<endl;
}

void DersArama() // ders ad�na g�re arama yapan fonksiyon.
{
	string arananders; // aranacak ders ad�.
	system("cls");
	
	cout<<"\n\n\n\t\tAranan dersin ad�n� girin (eksiksiz ve bo�luk koymadan): ";
	cin>>arananders;
	
	FILE *read;
	char dersad[20];
	int no;
	cout<<endl;
	
	if( (read=fopen("ders.txt","r"))==NULL )
	{
		cout<<" Dosya okuma ba�arisiz.";
		exit(1);
	}
	
	int bulundu=0;// aranan dersi bulunup bulunmad��� kontrol i�in.Bulunursa 1 olur.
	
	while(!feof(read))// txt tamamen ders ad� var m� diye aranacak.
	{
		fscanf(read,"%4d %20s",&no,dersad); // txt verileri kontrol i�in okunuyor.
		if(dersad==arananders) // e�er e�itlik olursa txt nin bu sat�r�ndaki veriler yazd�r�l�r.
		{
			bulundu=1; // aranan ders varsa 1 olur.
			if(!!feof(read)) // Son buldu�u dersi iki defa yazmamas� i�in.
			{
				break;
			}
			printf("%4d %20s",no,dersad);
			cout<<endl;
		}
	}
	fclose(read);
	
	if(bulundu==0)
	{
		cout<<"Aranan Ders Yok."<<endl;
	}
}

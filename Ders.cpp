#include <iostream>   // cin cout cerr kütüphanesi
#include "Ders.h"	// Prototiplerin tanýmlandýðý header çaðrýlýyor.
#include <fstream> // dosyalama iþlemleri için gerekli
#include <conio.h>  // getc() için.
using namespace std;

int secimekrani3() // Ders Alt Modüllerini Seçmek için kullanýlan bir fonksiyon.
{
	char altsecim=0; //  alt modüllerin özelliklerini seçmek için kullanýlacak karar deðiþkeni.
	system("cls"); // konsolu temizle.
	system("color F1"); // arkaplan,yazý rengi ayarý
	
	
	
	cout<<"\n\n\n";
	cout<<"\n\t\t\t\t      ";for(int i=0;i<42;++i){cout<<"\xb0";};cout<<endl;
	cout<<"\t\t\t\t      \xb0           Ders Alt Mod\x81lleri           \xb0";
	cout<<"\n\t\t\t\t      ";for(int i=0;i<42;++i){cout<<"\xb0";};cout<<endl;
	cout<<endl;
	cout<<"\t\t\t\t       ";for(int i=0;i<40;++i){cout<<"\xdb";};cout<<endl;
	cout<<"\t\t\t\t       \xdb                                      \xdb"<<endl;
	cout<<"\t\t\t\t       \xdb   KOD   ALT MOD\x9AL ADI                \xdb"<<endl; // Kullanýcý buradaki alt modül kodlarýndan birini seçer.
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
	return altsecim; // alt modül iþlem seçimi geri döndürülüyor.
}

void DersEkleme() // Ders.txt ye yeni ders kaydý fonksiyonu. 
{
	system("cls");
	char dersad[20]; // eklenecek dersin ad deðiþkeni.
	cout<<"Ders Adý  (kelime aralarýna boþluk koymayýn) : ";
	cin>>dersad;
	int no; // Dersin  kodu
	cout<<"Ders Numarasýný Girin (4 haneli): ";
	cin>>no;
	
	FILE *write; // write pointere tanýmlandý.
	
	
	write=fopen("ders.txt","a"); // a dosyaya önceki kayýtlarý silmeden kayýt eklemek için.
	// pointere txt doküman adresi yükleniyor.
	if( write==NULL ) //
	{
		cerr<<"ders.txt acilamadi"; // dosya oluþturulamadýysa.
		exit(1);
	}
	
	
	fprintf(write, "%4d %20s\n",no,dersad); // ders.txt ye veriler yazýlýyor.
	
	
	fclose(write); // dosyaya yazmayla iþimiz bitti.
	
	cout<<"Bilgiler kaydedildi."<<endl;
}

void DersBilgileriGuncelleme() //kayýtlý dersin adýnýn deðiþtirilebildiði fonk.
{
	system("cls");
	int secim=0,DuzenlenecekDersNo,bulundu=0,no; // kayýtlý dersteki verileri okuyup bunlara atýyoruz
	char dersad[20];
	
	cout<<"Bilgileri düzenlenecek dersin kodunu girin (4 haneli): ";
	cin>>DuzenlenecekDersNo;
	
	system("cls");
	FILE *update; // update pointere tanýmlandý.
	
	
	update=fopen("ders.txt","r+"); // r+ hem okuma hem de dokümana zara vermeden üzerine bilgi yazmak için.
	
	if( update==NULL ) // txt yoksa.
	{
		cerr<<"ders.txt acilamadi"; // dosya oluþturulamadýysa.
		exit(1);
	}
	
	while(!feof(update)) // dosyanýn son satýrýna gelindiyse.
	{	
		fscanf(update,"%4d %20s\n",&no,dersad); // ders.txt satýrlarýndaki bilgiler alýnýyor.
		
		if(no==DuzenlenecekDersNo) // alýnan bilgi deðiþtirilecek bilgiyle aynýysa ders vardýr ve deðiþtirilebilir.
		{
			cout<<"Ders adýný düzenleyebilirsiniz.\n";
			
			cout<<"\nDers Bilgisinin Eski Hali:\n";
			printf("%4d %20s",no,dersad);cout<<"\n\n"; // ekrana dersin eski bilgileri yazýlýyor.
			
			cout<<"Yeni ders ismi (kelime aralarýna boþluk koymayýn) : ";
			cin>>dersad;
			
			cout<<"\n=================================================="<<endl;
			cout<<"\nDers Bilgisinin Yeni Hali:\n";
			printf("%4d %20s",no,dersad);cout<<"\n"; //oluþacak yeni durum ekrana yazdýrýlýyor.
			
			fseek(update,sizeof(DuzenlenecekDersNo),SEEK_CUR); // txt içerisindeki veri yazýlacak dosya iþaretcisi konumu belirleniyor.
			fseek(update,-29,SEEK_CUR); //Bir önceki satýrýn konumuna gitmek için.
			fprintf(update, "%4d %20s\n",no,dersad); // ders.txt ye veriler yazýlýyor.
			
			bulundu=1; // aranan ders numarasý varsa
			cout<<"\n\nDüzenleme basarýlý..."<<endl;
			break;
		}
		
		
	}
	fclose(update); // dosyalama kapatýlýyor.
	
	if(bulundu==0) // 0 ise kontrol sonucu ders kaydý bulunamamýþtýr.
	{
		cout<<"Bu kodda ders kaydý yok."<<endl;
	}
}

void DersListeleme() // Derslerin listeleneceði fonk.
{
	system("cls");
	FILE *read; // dosyalama açýlýyor.
	char dersad[20];
	int no;	
	
	if( (read=fopen("ders.txt","r"))==NULL )
	{
		cout<<" Dosya okuma baþarýsýz.";
		exit(1);
	}
	cout<<"\nDers Adýna Göre Alfabetik listeleme yapýldý\n";
	
	int ASCII=65; // A harfinin Ascii karþýlýðý 65 tir 97 ise küçük a harfinin asci karþýlýðý.
	cout<<"\nKod              Ders Adý    \n";
	for(int i=0;i<20;++i){cout<<"==";} // Panelin köþelerindeki dolgulu çizgilerin sembolü.
	cout<<endl;
	
	while(ASCII+32<123) // ders adýnýn ilk harfinin ascii deðeri alfabetik olarak sýralanýyor.
	{
		read=fopen("ders.txt","r");
		while(!feof(read)) // bütün doküman incelenip harf sýrasý gelen listeleniyor.
		{
			fscanf(read,"%4d %20s",&no,dersad); // veriler txt den okunuyor.
			
			if(int(dersad[0])==ASCII or int(dersad[0])==ASCII+32) // BURADA ASCII DEÐERÝ YARDIMIYLA BÖLÜMÜN ÝLK HARFÝYLE SIRALAMA YAPILDI.
			{
				printf("%4d %20s",no,dersad);
				cout<<endl;
					break;
			}
		
		}
		// ASCII++ olduðunda bir sonraki harfe göre sýralama yapýyor.
		ASCII++; // BÝR SONRAKÝ HARFE GÖRE SIRALAMA YAPMASI ÝÇÝN. ÖNCE A LARI SONRA B LERÝ EN SON Z LEYLE BAÞLAYAN BÖLÜMLERÝ YAZDIRACAK.
	}
	
	fclose(read);// dosya kapatýldý.
	for(int i=0;i<20;++i){cout<<"==";} // Panelin köþelerindeki  çizgilerin sembolü.
	cout<<endl;
}

void DersArama() // ders adýna göre arama yapan fonksiyon.
{
	string arananders; // aranacak ders adý.
	system("cls");
	
	cout<<"\n\n\n\t\tAranan dersin adýný girin (eksiksiz ve boþluk koymadan): ";
	cin>>arananders;
	
	FILE *read;
	char dersad[20];
	int no;
	cout<<endl;
	
	if( (read=fopen("ders.txt","r"))==NULL )
	{
		cout<<" Dosya okuma baþarisiz.";
		exit(1);
	}
	
	int bulundu=0;// aranan dersi bulunup bulunmadýðý kontrol için.Bulunursa 1 olur.
	
	while(!feof(read))// txt tamamen ders adý var mý diye aranacak.
	{
		fscanf(read,"%4d %20s",&no,dersad); // txt verileri kontrol için okunuyor.
		if(dersad==arananders) // eðer eþitlik olursa txt nin bu satýrýndaki veriler yazdýrýlýr.
		{
			bulundu=1; // aranan ders varsa 1 olur.
			if(!!feof(read)) // Son bulduðu dersi iki defa yazmamasý için.
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

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
struct musteri{
	string ad, soyad, telefon;
	int menuno;
};
void sipariscikar()
{
	musteri m;
	string tel;
	int b = 0;
	fstream siparis;
	siparis.open("siparis.txt", ios::app | ios::in | ios::out);
	cout << "Cikarilacak siparisin telefon numarasini giriniz : ";
	cin >> tel;
	while (siparis >> m.ad >> m.soyad >> m.telefon >> m.menuno)
	{
		if (tel == m.telefon)
		{
			b++;
			cout << "Siparis Bulundu " << endl;
			cout << "Ad : " << m.ad << endl << "Soyad : " << m.soyad << endl << "Telefon : " << m.telefon << endl << "Menu No : " << m.menuno << endl;
			break;
		}
		else
			continue;
	}
	siparis.close();
	if (b == 0)
		cout << "Siparis bulunamadi " << endl;
	else
	{
		fstream siparis;
		fstream sipariscikarr;
		siparis.open("siparis.txt", ios::app | ios::in | ios::out);
		sipariscikarr.open("siparisyeni.txt", ios::app | ios::in | ios::out);
		while (siparis >> m.ad >> m.soyad >> m.telefon >> m.menuno)
		{
			if (m.telefon != tel)
			{
				sipariscikarr << m.ad << setw(15) << m.soyad << setw(15) << m.telefon << setw(15) << m.menuno << endl;
			}
			else
				continue;
		}
		siparis.close();
		sipariscikarr.close();
		remove("siparis.txt");
		rename("siparisyeni.txt", "siparis.txt");
		cout << "Siparis cikartildi " << endl;
	}

}
void siparisal()
{
	fstream menu;
	fstream siparis;
	string oku;
	int menuu;
	menu.open("menu.txt", ios::app | ios::in | ios::out);
	musteri m;
	cout << "Musteri Ad : "; cin >> m.ad;
	cout << "Musteri Soyad : "; cin >> m.soyad;
	cout << "Musteri Telefon : "; cin >> m.telefon;
	cout << "*********** MENULER ************" << endl;
	while (!menu.eof())
	{
		getline(menu, oku);
		cout << oku << endl;
	}
	menu.close();
	siparis.open("siparis.txt", ios::app | ios::in | ios::out);

	cout << "Hangi menuyu almak istersiniz : "; cin >> menuu;
	switch (menuu)
	{
	case 1: m.menuno = 1;
		siparis << m.ad << setw(15) << m.soyad << setw(15) << m.telefon << setw(15) << m.menuno << endl;
		cout << "Odemeniz gereken ucret : " << 20 << endl;
		break;
	case 2:m.menuno = 2;
		siparis << m.ad << setw(15) << m.soyad << setw(15) << m.telefon << setw(15) << m.menuno << endl;
		cout << "Odemeniz gereken ucret : " << 10 << endl;
		break;
	case 3:m.menuno = 3;
		siparis << m.ad << setw(15) << m.soyad << setw(15) << m.telefon << setw(15) << m.menuno << endl;
		cout << "Odemeniz gereken ucret : " << 15 << endl;
		break;
	case 4:m.menuno = 4;
		siparis << m.ad << setw(15) << m.soyad << setw(15) << m.telefon << setw(15) << m.menuno << endl;
		cout << "Odemeniz gereken ucret : " << 30 << endl;
		break;
	case 5:m.menuno = 5;
		siparis << m.ad << setw(15) << m.soyad << setw(15) << m.telefon << setw(15) << m.menuno << endl;
		cout << "Odemeniz gereken ucret : " << 12 << endl;
		break;

	default:cout << "Yanlis deger girdiniz ... " << endl;
	}
	siparis.close();
}
void siparisgoruntule()
{
	musteri m;
	string oku;
	fstream siparis;
	siparis.open("siparis.txt", ios::app | ios::in | ios::out);
	cout << "********************** SIPARISLER ********************" << endl;
	cout << "AD ------ SOYAD ----- TELEFON ------ MENU NO" << endl;
	while (!siparis.eof())
	{
		getline(siparis, oku);
		cout << oku << endl;
	}
	siparis.close();
}
void siparissorgu()
{
	int b = 0;
	musteri m;
	string tel;
	fstream siparis;
	siparis.open("siparis.txt", ios::app | ios::in | ios::out);
	cout << "Siparis veren kisinin telefon numarsini giriniz : "; cin >> tel;
	while (siparis >> m.ad >> m.soyad >> m.telefon >> m.menuno)
	{
		if (tel == m.telefon)
		{
			cout << "Siparis bulundu " << endl;
			b++;
			cout << "Ad : " << m.ad << endl << "Soyad : " << m.soyad << endl << "Telefon : " << m.telefon << endl << "Menu No : " << m.menuno << endl;
			break;
		}
	}
	if (b == 0)
		cout << "Siparis Bulunamadi " << endl;
	siparis.close();
}
void main()
{
	system("color e1");
	char cevap;
	int islem;
	do{
		cout << "                               *************** FASTFOOD OTOMASYONU *************** " << endl;
		cout << "1-Siparis Alma \n2-Siparisleri Goruntule \n3-Siparis Sorgulama \n4-Siparis Cikarma " << endl;
		cout << "*************************************************************************************" << endl;
		cout << "Islem numarasi giriniz :  "; cin >> islem;
		switch (islem)
		{
		case 1:siparisal();
			break;
		case 2:siparisgoruntule();
			break;
		case 3: siparissorgu();
			break;
		case 4: sipariscikar();
			break;
		default:cout << "Yanlis deger girdiniz .." << endl;
			break;
		}
		cout << "Tekrar islem yapmak istermisiniz ";
		cin >> cevap;
		system("cls");
	} while (cevap == 'e');
}
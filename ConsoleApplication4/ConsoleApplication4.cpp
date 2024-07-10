#include <iostream>
#include <vector>
using namespace std;

//class penerbit
class penerbit;
//class buku
class buku;
//class pengarang
//berisikan variabel nama dengan akses modifier public
class pengarang
{				
public:
	//membuat member dari class pengarang dengan variabel string dan vector
	string nama;
	vector<penerbit*> daftar_penerbit;
	vector<buku*> daftar_buku;
	//membuat konstructor dan destructor dari class pengarang
	pengarang(string pNama) :nama(pNama)
	{
		
	}

	~pengarang()
	{
		
	}
	//tambahkan beberapa methode untuk digunakan di class pengarang2
	void tambahpenerbit(penerbit*);
	void cetakpenerbit();
	void tambahbuku(buku*);
	void cetakbuku();
};

//class penerbit
class penerbit
{
	//membuat member dari class penerbit dengan variabel string dan vector
public:
	string nama;
	vector<pengarang*> daftar_pengarang;
	//membuat konstructor dan destructor dari class penerbit
	penerbit(string pNama) :nama(pNama)
	{
		
	}

	~penerbit()
	{
		
	}
	//tambahkan beberapa methode untuk digunakan di class pengarang
	void tambahpengarang(pengarang*);
	void cetakpengarang();
};

//class uku
class buku
{
	//membuat member dari class buku dengan variabel string dan vector
public:
	string judul;
	vector<pengarang*> daftar_pengarang;
	//membuat konstructor dan destructor dari class buku
	buku(string pJudul) :judul(pJudul)
	{
		
	}

	~buku()
	{
		
	}
	//tambahkan beberapa methode untuk digunakan di class pengarang
	void tambahpengarang(pengarang*);
	void cetakpengarang();
};

void pengarang::tambahpenerbit(penerbit* pPenerbit)
{
	daftar_penerbit.push_back(pPenerbit);
}

void pengarang::cetakpenerbit()
{
	cout << "Daftar penerbit yang diikuti pengarang \"" << this->nama << "\":\n";
	for (auto& a : daftar_penerbit)
	{
		cout << a->nama << "\n";
	}
	cout << endl;
}


void pengarang::tambahbuku(buku* pJudul)
{
	daftar_buku.push_back(pJudul);
}

void pengarang::cetakbuku()
{
	cout << "Daftar buku yang dikarang \"" << this->nama << "\":\n";
	for (auto& a : daftar_buku)
	{
		cout << a->judul << "\n";
	}
	cout << endl;
}

void penerbit::tambahpengarang(pengarang* pPengarang)
{
	daftar_pengarang.push_back(pPengarang);
	pPengarang->tambahpenerbit(this);
}

void penerbit::cetakpengarang()
{
	cout << "Daftar Pengarang pada penerbit  \"" << this->nama << "\":\n";
	for (auto& a : daftar_pengarang)
	{
		cout << a->nama << "\n";
	}
	cout << endl;
}

void buku::tambahpengarang(pengarang* pPengarang)
{
	daftar_pengarang.push_back(pPengarang);
	pPengarang->tambahbuku(this);
}

void buku::cetakpengarang()
{
	cout << "Daftar pengarang yang mengarang buku\"" << this->judul << "\":\n";
	for (auto& a : daftar_pengarang)
	{
		cout << a->nama << "\n";
	}
	cout << endl;
}


//membuat int main
int main()
{
	penerbit* varPenerbit1 = new penerbit("Gama Press");
	penerbit* varPenerbit2 = new penerbit("Intan Pariwara");

	pengarang* varPengarang1 = new pengarang("Joko");
	pengarang* varPengarang2 = new pengarang("Lia");
	pengarang* varPengarang3 = new pengarang("Giga");
	pengarang* varPengarang4 = new pengarang("Asroni");

	buku* varBuku1 = new buku("Fisika");
	buku* varBuku2 = new buku("Algoritma");
	buku* varBuku3 = new buku("Basisdata");
	buku* varBuku4 = new buku("Dasar Pemograman");
	buku* varBuku5 = new buku("Matematika");
	buku* varBuku6 = new buku("Multimedia 1");


	varPenerbit1->tambahpengarang(varPengarang1);
	varPenerbit1->tambahpengarang(varPengarang2);
	varPenerbit1->tambahpengarang(varPengarang3);
	varPenerbit2->tambahpengarang(varPengarang3);
	varPenerbit2->tambahpengarang(varPengarang4);

	varPengarang3->tambahpenerbit(varPenerbit1);
	varPengarang3->tambahpenerbit(varPenerbit2);

	varPengarang1->tambahbuku(varBuku1);
	varPengarang1->tambahbuku(varBuku2);
	varPengarang2->tambahbuku(varBuku3);
	varPengarang3->tambahbuku(varBuku5);
	varPengarang3->tambahbuku(varBuku6);
	varPengarang4->tambahbuku(varBuku4);

	varPenerbit1->cetakpengarang();
	varPenerbit2->cetakpengarang();
	varPengarang3->cetakpenerbit();
	varPengarang1->cetakbuku();
	varPengarang2->cetakbuku();
	varPengarang3->cetakbuku();
	varPengarang4->cetakbuku();


	return 0;

}



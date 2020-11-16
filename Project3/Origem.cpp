#include <iostream>
#include <vector>
#include <map>
#include <locale>
#include <fstream>
#include <string>
#include <ostream>
#include <locale.h>
#include <cstdlib>

using namespace std;
 

class No
{
private:
	No *esq, *dir;
	string time , nome, pos, status, sg;


public: 

	No(string time, string nome, string pos, string status, string sg)
	{
		esq = NULL;
		dir = NULL;
		this->time = time;
		this->nome = nome;
		this->pos = pos;
		this->status = status;
		this->sg = sg;

	}

	string getTime() {
		return time;
	}
	string getNome() 
	{
		return nome;

	}
	string getPos()
	{
		return pos;
	}
	string getStatus()
	{
		return status;
	}
	string getSg() {
		return sg;
	}
	No* getEsq()
	{
		return esq;
	}
	No* getDir()
	{
		return dir;
	}
	void setEsq(No* no) 
	{
		esq = no;
	}
	void setDir(No* no)
	{
		dir = no;
	}
};

class Arvore
{
private:
	No* raiz;
	string time, nome, pos, status, sg, name;
	
public:
	
	Arvore()//string time, string nome, string pos, string status, string sg
	{
		raiz = NULL;
		
	}

	void setName(string name) {
		this->name = name;

	}

	string getName() {
		return this->name;
	}

	void inserir(string time, string nome, string pos, string status, string sg)
	{
		if (raiz == NULL) {
			raiz = new No(time, nome, pos, status, sg);
		}
		else {
			inserirAux(raiz, time, nome, pos, status, sg);
		}
	}

	void inserirAux(No *no, string time, string nome, string pos, string status, string sg)
	{
		if (nome < no->getNome())
		{
			if (no->getEsq() == NULL) 
			{
				No* novo_no = new No(time, nome, pos, status, sg);
				no->setEsq(novo_no);
			}
			else
			{
				inserirAux(no->getEsq(), time, nome, pos, status, sg);
			}
		}
		else if  (nome > no->getNome())
		{
			if (no->getDir() == NULL)
			{
				No* novo_no = new No(time, nome, pos, status, sg);
				no->setDir(novo_no);
			}
			else
			{
				inserirAux(no->getDir(), time, nome, pos, status, sg);
			}
			
		}
		
	}

	No* getRaiz() 
	{
		return raiz;
	}

	void emOrdem(No* no)
	{
		if (no != NULL) 
		{
			emOrdem(no->getEsq());
			cout << " " << no->getNome() << " " << no->getTime() << " " << no->getPos() << " " <<  no->getSg() << " " << no->getStatus() << " \n ";
			emOrdem(no->getDir());
			
		}
	}
	
};

class Time {
	map<string, Arvore*> arvores;


	public: void createTime(string time2, string nome, string pos, string status, string sg) {
		
		Arvore* arvore = new Arvore();
		arvore->setName(time2);
		arvore->inserir(time2, nome, pos, status, sg);
 		this->arvores[time2] = arvore;

	}
	
	public: Arvore* getTime(string name) {
		return this->arvores[name];
	}

	public: void Nomes() {

		ifstream Nomes;
		int a = 0;

		Nomes.open("Nomes.csv");

		while (Nomes.good()) {

			string nome;
			string sigla;

			getline(Nomes, nome, ';');
			getline(Nomes, sigla, '\n');

			if (sigla == "BOT" || sigla == "CAM" || sigla == "CAP" || sigla == "CHA" || sigla == "COR" || sigla == "CRU" || sigla == "FLA" || sigla == "FLU" || sigla == "FOR" || sigla == "INT" || sigla == "PAL" || sigla == "SAO") {

				cout << "\t" << nome << "\t\t\t\t\t\t\t" << sigla << "\n";

			}
			else {
				cout << "\t" << nome << "\t\t\t\t\t\t\t\t" << sigla << "\n";


			}
		}

	}

	public: bool verifica(string nome) {

		if (this->arvores[nome]) {
			return true;
		} else {
			return false;
		}
	}
};


int main()
{
	string aux = "asd";
	string nom;
	int a = 0;
	setlocale(LC_ALL, "Portuguese");
	ifstream Times;

	Times.open("Times.csv");

	Time* times_bra = new Time();


	while (Times.good()) 
	{

		string time;
		string nome;
		string pos;
		string status;
		string sg;

		getline(Times, time, ';');
		getline(Times, nome, ';');
		getline(Times, pos, ';');
		getline(Times, status, ';');
		getline(Times, sg, '\n');

		if (time != aux) {

			times_bra->createTime(time, nome, pos, status, sg);
			aux = time;

		}
		else if (time == aux) {

			Arvore* sa = times_bra->getTime(time);
			sa->inserir(time, nome, pos, status, sg);

		}

	}


	while (a == 0) 
	{
		cout << "\t\t\t\t" << "ARVORE BINARIA TIMES SERIE A" << "\n";

		cout << "Para visualizar a arvore binaria de algum time, digite a sigla do time conforme esboçado" << "\n\n";

		times_bra->Nomes();
		cout << "Para SAIR escreva 'sair'" << "\n\n";
		cin >> nom;
		if (times_bra->verifica(nom) == true) {
			
			system("cls");
			cout << " ";
			Arvore* obj_time = times_bra->getTime(nom);
			cout << "\n\n";
			obj_time->emOrdem(obj_time->getRaiz());
			system("\n pause");
			system("cls");

		} else if (nom == "sair"){

			a = 1;
		} else {

			cout << "VOCÊ ESCREVEU UMA OPÇÃO INVÁLIDA!!\n";
			system("pause");
			system("cls");
		}

	}

	return 0;
}


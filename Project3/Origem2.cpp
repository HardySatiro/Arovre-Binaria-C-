#include <iostream>
#include <vector>
#include <map>
#include <locale>
#include <iostream>
#include <fstream>
#include <string>
#include <ostream>

using namespace std;


class Jogador {
	map<string, Jogador*> jogadores;

public:

	string name;
	string altura;
	string posicao;


public: void setname(string name) {
	this->name = name;
}

public: string getname() {
	return this->name;
}

public: void setaltura(string altura) {
	this->altura = altura;
}

public: string getaltura() {
	return this->altura;
}

public: void setposicao(string posicao) {
	this->posicao = posicao;
}

public: string getposicao() {
	return this->posicao;
}

public: void creat(string name, string altura, string posicao) {

	Jogador* jogador = new Jogador();
	jogador->setname(name);
	jogador->setaltura(altura);
	jogador->setposicao(posicao);
	this->jogadores[name] = jogador;
}

public: Jogador* getplayername(string name) {
	return this->jogadores[name];
}

};


class No
{
private:
	No *esq, *dir;
	string time , nome, pos, status, sg;
	int dp, dd, rb, gc, cv, ca, gs, fs;

public: 

	No(string time, string nome, string pos, string status, string sg)//, int dp, int dd, int rb, int gc, int cv, int ca, int gs, int fs
	{
		esq = NULL;
		dir = NULL;
		this->time = time;
		this->nome = nome;
		this->pos = pos;
		this->status = status;
		this->sg = sg;

	}

	string gettime() {
		return time;
	}
	string getnome() 
	{
		return nome;

	}
	string getpos()
	{
		return pos;
	}
	string getstatus()
	{
		return status;
	}
	string getsg() {
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
	string time, nome, pos, status, sg;
	
public:
	
	Arvore()//string time, string nome, string pos, string status, string sg
	{
		raiz = NULL;
		/*this->time = time;
		this->nome = nome;
		this->pos = pos;
		this->status = status;
		this->sg = sg;*/

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
		if (nome < no->getnome())
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
		else if  (nome > no->getnome())
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
			cout << no->getnome() << " ";
			emOrdem(no->getDir());
			
		}
	}
	
};

/*void carrer() {

	ifstream Cor, Vas, For, Ava, Sao, Pal, Bah, San, Fla, Goi, Cru, Bot, Gre, Csa, Cap, Int, Cha, Cam, Flu, Cea;

	Cor.open("FLA.csv");
	Arvore* Core = new Arvore("COR", "SAO", "MEIA", "ASD", "ASDAS");

	string time;
	string nome;
	string pos;
	string status;
	string sg;

	while (Cor.good()) {

		getline(Cor, time, ';');
		getline(Cor, nome, ';');
		getline(Cor, pos, ';');
		getline(Cor, status, ';');
		getline(Cor, sg, '\n');
		Core->inserir(time, nome, pos, status, sg);

		
	}
	Core->emOrdem(Core->getRaiz());
}

*/

int main() {
	

	Jogador* a = new Jogador();

	a->creat("hardy", "185", "meia");
	a->creat("joao", "185", "meia");
	a->creat("juca", "185", "meia");

	Arvore* Asa = new Arvore();

	Jogador* hehe = a->getplayername("hardy");
	string name = hehe->getname();
	string altura = hehe->getaltura();
	string posicao = hehe->getposicao();
	string time = "aaa";
	string pos = "sadas";

	Asa->inserir(name, altura, posicao, time, pos);

	cout << "PERCORRENDO EM ORDEM \n";

	return 0;

}


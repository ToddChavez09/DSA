#include <iostream>
using namespace std;

template<typename T>
struct Noh
{
	T elem;
	Noh<T> *prox;
};

template<typename T>
struct Fila{

	Noh<T> *inicio, *fim;
};

template<typename T>
void inicializar(Fila<T> &F)
{
	F.inicio = nullptr;
	F.fim = nullptr;
}
template<typename T>
bool vazia(Fila<T> &F){
	return (F.inicio == nullptr);
}
template<typename T>
bool enfilar(Fila<T> &F, T e)
{
	Noh<T> *n = new Noh<T>;
	if (n == nullptr) return false;
	n->elem = e;
	n->prox = nullptr;

	if(vazia(F)){
		F.inicio = n;
		F.fim = n;
	}else{
		F.fim->prox = n;
		F.fim = n;
	}

	return true;
}
template<typename T>
T desenfilar(Fila<T> &F)
{
	Noh<T> *n = F.fim;
	delete F.fim;
	F.fim = n->prox;
	return n->elem;

}
template<typename T>
void printar(Fila<T> F)
{
	Noh<T> *aux = F.inicio;
	while (aux != nullptr){
		cout << aux->elem << " ";
		aux = aux->prox;
	}
}

int main(int argc, char const *argv[])
{
	Fila<int> F;
	inicializar(F);
	enfilar(F, 10);
	enfilar(F, 20);
	enfilar(F, 30);
	enfilar(F, 40);
	printar(F);
	return 0;
}